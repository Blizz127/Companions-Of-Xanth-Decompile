# Reproduce from the local disc

Run from the repository root. Never overwrite the original image.

```sh
python3 -m unittest discover -s tests -v
python3 tools/register_retail.py XANBUD.iso
7z x -y -oextracted XANBUD.iso XANTH/XANTH.EXE XANTH/XANTH.OVL
cp extracted/XANTH/XANTH.EXE original/XANTH.EXE
cp extracted/XANTH/XANTH.OVL original/XANTH.OVL
python3 tools/identify.py original/XANTH.EXE > evidence/local/mz-new.json
python3 tools/identify.py --kind ovl original/XANTH.OVL > evidence/local/ovl-new.json
cmp evidence/target/mz.json evidence/local/mz-new.json
cmp evidence/target/ovl.json evidence/local/ovl-new.json
python3 tools/verify.py
```

`7z` is required for extraction. The image is ISO 9660 MODE1/2048; do not
substitute a CD-XA decoder. `register_retail.py` refuses a size or SHA-256
mismatch. `verify.py` refuses a missing or mismatched EXE/OVL.

No historical compiler is required for this step. Matching comes after
compiler identification.
