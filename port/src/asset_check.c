/*
 * Runtime asset identity check.
 *
 * The pins cover the locally supported XANBUD set. They contain hashes only;
 * retail data stays outside the repository and is opened from --data.
 */
#include "asset_check.h"
#include "retail_asset_manifest.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    uint32_t h[8];
    uint64_t bits;
    uint8_t block[64];
    size_t used;
} sha256_ctx;

static const uint32_t sha_k[64] = {
    0x428a2f98u,0x71374491u,0xb5c0fbcfu,0xe9b5dba5u,0x3956c25bu,0x59f111f1u,0x923f82a4u,0xab1c5ed5u,
    0xd807aa98u,0x12835b01u,0x243185beu,0x550c7dc3u,0x72be5d74u,0x80deb1feu,0x9bdc06a7u,0xc19bf174u,
    0xe49b69c1u,0xefbe4786u,0x0fc19dc6u,0x240ca1ccu,0x2de92c6fu,0x4a7484aau,0x5cb0a9dcu,0x76f988dau,
    0x983e5152u,0xa831c66du,0xb00327c8u,0xbf597fc7u,0xc6e00bf3u,0xd5a79147u,0x06ca6351u,0x14292967u,
    0x27b70a85u,0x2e1b2138u,0x4d2c6dfcu,0x53380d13u,0x650a7354u,0x766a0abbu,0x81c2c92eu,0x92722c85u,
    0xa2bfe8a1u,0xa81a664bu,0xc24b8b70u,0xc76c51a3u,0xd192e819u,0xd6990624u,0xf40e3585u,0x106aa070u,
    0x19a4c116u,0x1e376c08u,0x2748774cu,0x34b0bcb5u,0x391c0cb3u,0x4ed8aa4au,0x5b9cca4fu,0x682e6ff3u,
    0x748f82eeu,0x78a5636fu,0x84c87814u,0x8cc70208u,0x90befffau,0xa4506cebu,0xbef9a3f7u,0xc67178f2u
};

static uint32_t rotr32(uint32_t x, unsigned n) { return (x >> n) | (x << (32u - n)); }

static void sha256_transform(sha256_ctx *c, const uint8_t b[64]) {
    uint32_t w[64], a, d, e, f, g, h, bb, cc;
    unsigned i;
    for (i = 0; i < 16; ++i)
        w[i] = ((uint32_t)b[i*4] << 24) | ((uint32_t)b[i*4+1] << 16) |
               ((uint32_t)b[i*4+2] << 8) | (uint32_t)b[i*4+3];
    for (; i < 64; ++i) {
        uint32_t x = w[i-15], y = w[i-2];
        uint32_t s0 = rotr32(x,7) ^ rotr32(x,18) ^ (x >> 3);
        uint32_t s1 = rotr32(y,17) ^ rotr32(y,19) ^ (y >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;
    }
    a=c->h[0]; bb=c->h[1]; cc=c->h[2]; d=c->h[3];
    e=c->h[4]; f=c->h[5]; g=c->h[6]; h=c->h[7];
    for (i = 0; i < 64; ++i) {
        uint32_t s1 = rotr32(e,6) ^ rotr32(e,11) ^ rotr32(e,25);
        uint32_t ch = (e & f) ^ (~e & g);
        uint32_t t1 = h + s1 + ch + sha_k[i] + w[i];
        uint32_t s0 = rotr32(a,2) ^ rotr32(a,13) ^ rotr32(a,22);
        uint32_t maj = (a & bb) ^ (a & cc) ^ (bb & cc);
        uint32_t t2 = s0 + maj;
        h=g; g=f; f=e; e=d+t1; d=cc; cc=bb; bb=a; a=t1+t2;
    }
    c->h[0]+=a; c->h[1]+=bb; c->h[2]+=cc; c->h[3]+=d;
    c->h[4]+=e; c->h[5]+=f; c->h[6]+=g; c->h[7]+=h;
}

static void sha256_init(sha256_ctx *c) {
    static const uint32_t init[8] = {
        0x6a09e667u,0xbb67ae85u,0x3c6ef372u,0xa54ff53au,
        0x510e527fu,0x9b05688cu,0x1f83d9abu,0x5be0cd19u
    };
    memcpy(c->h, init, sizeof(init)); c->bits=0; c->used=0;
}

static void sha256_update(sha256_ctx *c, const uint8_t *p, size_t n) {
    c->bits += (uint64_t)n * 8u;
    while (n) {
        size_t take = 64 - c->used;
        if (take > n) take = n;
        memcpy(c->block + c->used, p, take);
        c->used += take; p += take; n -= take;
        if (c->used == 64) { sha256_transform(c, c->block); c->used=0; }
    }
}

static void sha256_final(sha256_ctx *c, uint8_t out[32]) {
    uint64_t bits = c->bits;
    unsigned i;
    c->block[c->used++] = 0x80;
    if (c->used > 56) {
        memset(c->block + c->used, 0, 64 - c->used);
        sha256_transform(c, c->block); c->used=0;
    }
    memset(c->block + c->used, 0, 56 - c->used);
    for (i=0;i<8;++i) c->block[63-i]=(uint8_t)(bits>>(i*8));
    sha256_transform(c, c->block);
    for (i=0;i<8;++i) {
        out[i*4]=(uint8_t)(c->h[i]>>24); out[i*4+1]=(uint8_t)(c->h[i]>>16);
        out[i*4+2]=(uint8_t)(c->h[i]>>8); out[i*4+3]=(uint8_t)c->h[i];
    }
}

bool xanth_sha256_file(const char *path, char hex[65]) {
    FILE *f = fopen(path, "rb");
    sha256_ctx c;
    uint8_t buf[16384], digest[32];
    size_t n;
    unsigned i;
    static const char digits[] = "0123456789abcdef";
    if (!f) return false;
    sha256_init(&c);
    while ((n=fread(buf,1,sizeof(buf),f)) != 0) sha256_update(&c,buf,n);
    if (ferror(f)) { fclose(f); return false; }
    fclose(f); sha256_final(&c,digest);
    for (i=0;i<32;++i) { hex[i*2]=digits[digest[i]>>4]; hex[i*2+1]=digits[digest[i]&15]; }
    hex[64]='\0';
    return true;
}

static int verify_one(const char *path, const char *want, const char *name,
                      char *error, size_t error_size) {
    char got[65];
    if (!xanth_sha256_file(path, got)) {
        snprintf(error,error_size,"missing or unreadable %s (%s)",name,path);
        return 0;
    }
    if (strcmp(got,want) != 0) {
        snprintf(error,error_size,"SHA-256 mismatch for %s; expected XANBUD asset set",name);
        return 0;
    }
    return 1;
}

bool xanth_check_assets(const char *exe_path, const char *data_dir,
                        char *error, size_t error_size) {
    char path[1024];
    size_t i;
    static const char exe_sha[] = "3982b5f5c055a4fd84b0a4fe3b911b7393af687b623d0d00f846c5da46d26671";
    if (!exe_path || !data_dir || !error || error_size == 0) return false;
    error[0]='\0';
    if (!verify_one(exe_path,exe_sha,"XANTH.EXE",error,error_size)) goto fail;
    for (i=0;i<XANTH_ASSET_PIN_COUNT;++i) {
        int n=snprintf(path,sizeof(path),"%s/%s",data_dir,xanth_asset_pins[i].name);
        if (n<0 || (size_t)n>=sizeof(path)) {
            snprintf(error,error_size,"game data path is too long"); goto fail;
        }
        if (!verify_one(path,xanth_asset_pins[i].sha256,xanth_asset_pins[i].name,error,error_size)) goto fail;
    }
    return true;
fail:
    snprintf(path,sizeof(path),"%s",error);
    snprintf(error,error_size,"%s\nSupply the matching XANBUD game files with --data <directory>. The files stay on your machine and are not included with the port.",path);
    return false;
}
