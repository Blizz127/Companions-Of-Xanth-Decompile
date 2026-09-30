"""Release gate for the explicit packaged executable, using a private X server.

Ordinary keys release the retail intro gates. The executable's existing
read-only input trace must report field-idle, event8 and an empty keyboard
queue before each physical click; this test installs no observer and writes
no guest state. Visible RGB crops remain pinned to prior retail-VM evidence.
No retail screenshots are committed.
"""
import ctypes as C
import ctypes.util
import hashlib
import json
import os
import re
from pathlib import Path
import select
import shutil
import struct
import subprocess
import tempfile
import time
import unittest

# SHA-256 static RGB areas from verified VM context_fresh/g_take evidence.
# Corrected IF changes rain timing and full-frame hashes; these static pins
# exclude the proven animated window and object-caption areas.
ROOM = (51,4,315,124)
# Proven rain rectangle is (51,4)-(136,75); selected/hovered object captions
# render near the picture bottom. Exact prior-frame static areas keep the
# monitor, desk, keyboard and envelope, and exclude both dynamic UI regions.
STATIC_ROOM = ((137,4,315,76),(51,76,315,112))
SLOT = (92,152,116,172)
VERB_PANEL = (2,4,49,74)
VERBS = "fed1fbf00bd57525709c3159fd6c9c5a9f14589891e00a284846eda1231e0605"
EMPTY_SLOT = "1acfe672346c37560dc577a19602daa7d1240cbb96d49c495044ec00841979f1"
BEDROOM = "1a76e1a1d2c5ebfc9ca502c9dc97afda85df27db11bc5ee9c95b063400a8d361"
TAKEN_ROOM = "28f3205495f7dc5f52a16b830b4b0a6b3f82331dc657835e88afe44098354aa1"
ENVELOPE = "4f13771698ec068921990afaa6c0ef23bbeab0418df86e607c52d7564e745a51"


def crop_hash(rgb, rect):
    x0,y0,x1,y1=rect
    return hashlib.sha256(b"".join(rgb[(y*320+x0)*3:(y*320+x1)*3]
                                  for y in range(y0,y1))).hexdigest()


def room_hash(rgb):
    return hashlib.sha256(b"".join(rgb[(y*320+x0)*3:(y*320+x1)*3]
        for x0,y0,x1,y1 in STATIC_ROOM for y in range(y0,y1))).hexdigest()


def bmp_rgb(path):
    data=path.read_bytes()
    offset=struct.unpack_from("<I",data,10)[0]
    width,height=struct.unpack_from("<ii",data,18)
    if (width,height)!= (320,200) or struct.unpack_from("<H",data,28)[0]!=24:
        raise AssertionError("final screenshot must be the actual 320x200 guest BMP")
    stride=(width*3+3)&~3
    return b"".join(data[offset+(199-y)*stride+x*3:offset+(199-y)*stride+x*3+3][::-1]
                    for y in range(200) for x in range(320))


class XImage(C.Structure):
    _fields_=[("width",C.c_int),("height",C.c_int),("xoffset",C.c_int),
              ("format",C.c_int),("data",C.c_void_p),("byte_order",C.c_int),
              ("bitmap_unit",C.c_int),("bitmap_bit_order",C.c_int),
              ("bitmap_pad",C.c_int),("depth",C.c_int),("bytes_per_line",C.c_int),
              ("bits_per_pixel",C.c_int),("red_mask",C.c_ulong),
              ("green_mask",C.c_ulong),("blue_mask",C.c_ulong)]


class PrivateX:
    def __init__(self,directory):
        x11=ctypes.util.find_library("X11")
        xtst=ctypes.util.find_library("Xtst")
        if not shutil.which("Xvfb") or not x11 or not xtst:
            raise AssertionError("release gate requires Xvfb, libX11 and libXtst")
        self.x=C.CDLL(x11); self.t=C.CDLL(xtst)
        # A window may disappear between process.poll and XGetImage at exit.
        # Retain the callback so Xlib reports failure instead of killing Python.
        self.error_handler=C.CFUNCTYPE(C.c_int,C.c_void_p,C.c_void_p)(lambda display,event:0)
        self.x.XSetErrorHandler.argtypes=[type(self.error_handler)]
        self.x.XSetErrorHandler(self.error_handler)
        signatures={
            "XOpenDisplay":([C.c_char_p],C.c_void_p),
            "XDefaultRootWindow":([C.c_void_p],C.c_ulong),
            "XQueryTree":([C.c_void_p,C.c_ulong,C.POINTER(C.c_ulong),C.POINTER(C.c_ulong),C.POINTER(C.POINTER(C.c_ulong)),C.POINTER(C.c_uint)],C.c_int),
            "XFetchName":([C.c_void_p,C.c_ulong,C.POINTER(C.c_void_p)],C.c_int),
            "XFree":([C.c_void_p],C.c_int),
            "XSetInputFocus":([C.c_void_p,C.c_ulong,C.c_int,C.c_ulong],C.c_int),
            "XFlush":([C.c_void_p],C.c_int),
            "XKeysymToKeycode":([C.c_void_p,C.c_ulong],C.c_uint),
            "XGetImage":([C.c_void_p,C.c_ulong,C.c_int,C.c_int,C.c_uint,C.c_uint,C.c_ulong,C.c_int],C.POINTER(XImage)),
            "XDestroyImage":([C.POINTER(XImage)],C.c_int),
            "XCloseDisplay":([C.c_void_p],C.c_int),
        }
        for name,(args,result) in signatures.items():
            fn=getattr(self.x,name);fn.argtypes=args;fn.restype=result
        for name,args in [("XTestFakeKeyEvent",[C.c_void_p,C.c_uint,C.c_int,C.c_ulong]),
                          ("XTestFakeButtonEvent",[C.c_void_p,C.c_uint,C.c_int,C.c_ulong]),
                          ("XTestFakeMotionEvent",[C.c_void_p,C.c_int,C.c_int,C.c_int,C.c_ulong])]:
            fn=getattr(self.t,name);fn.argtypes=args;fn.restype=C.c_int
        read_fd,write_fd=os.pipe()
        self.log=open(directory/"xvfb.log","wb")
        env={k:v for k,v in os.environ.items() if k not in
             ("DISPLAY","WAYLAND_DISPLAY","XAUTHORITY","SDL_VIDEODRIVER")}
        self.server=subprocess.Popen(["Xvfb","-displayfd",str(write_fd),"-screen","0","640x480x24","-nolisten","tcp","-ac"],
                                     pass_fds=(write_fd,),stdout=self.log,stderr=self.log,env=env)
        os.close(write_fd)
        try:
            display_number=b""
            deadline=time.monotonic()+5
            while b"\n" not in display_number:
                remaining=deadline-time.monotonic()
                if remaining<=0 or not select.select([read_fd],[],[],remaining)[0]:
                    raise AssertionError("private Xvfb did not publish a display within 5s")
                chunk=os.read(read_fd,32)
                if not chunk:raise AssertionError("private Xvfb closed displayfd before its newline")
                display_number+=chunk
            self.display=":"+display_number.decode().strip()
        except Exception:
            self.server.terminate()
            try:self.server.wait(timeout=2)
            except subprocess.TimeoutExpired:self.server.kill();self.server.wait()
            self.log.close()
            raise
        finally:
            os.close(read_fd)
        self.authority=directory/"private-xauthority"
        self.authority.touch()
        previous_authority=os.environ.get("XAUTHORITY")
        os.environ["XAUTHORITY"]=str(self.authority)
        try:
            self.connection=None
            deadline=time.monotonic()+2
            while not self.connection and time.monotonic()<deadline:
                self.connection=self.x.XOpenDisplay(self.display.encode())
                if not self.connection:time.sleep(.05)
        finally:
            if previous_authority is None:os.environ.pop("XAUTHORITY",None)
            else:os.environ["XAUTHORITY"]=previous_authority
        if not self.connection:
            self.server.terminate();self.server.wait(timeout=2);self.log.close()
            raise AssertionError("cannot open private Xvfb display")
        self.root=self.x.XDefaultRootWindow(self.connection)

    def window(self):
        root=C.c_ulong(); parent=C.c_ulong();children=C.POINTER(C.c_ulong)();count=C.c_uint()
        self.x.XQueryTree(self.connection,self.root,C.byref(root),C.byref(parent),C.byref(children),C.byref(count))
        found=[]
        try:
            for index in range(count.value):
                name=C.c_void_p()
                if self.x.XFetchName(self.connection,children[index],C.byref(name)) and name.value:
                    title=C.string_at(name).decode(errors="replace");self.x.XFree(name)
                    if title=="Companions of Xanth":found.append(children[index])
        finally:
            if children:self.x.XFree(children)
        if len(found)>1:raise AssertionError("private display has multiple game windows")
        return found[0] if found else None

    def rgb(self,window):
        image=self.x.XGetImage(self.connection,window,0,0,320,200,C.c_ulong(-1).value,2)
        if not image:raise AssertionError("cannot capture game window")
        try:
            img=image.contents
            if img.bits_per_pixel!=32 or img.byte_order!=0 or (img.red_mask,img.green_mask,img.blue_mask)!=(0xff0000,0xff00,0xff):
                raise AssertionError("private Xvfb RGB format unsupported")
            raw=C.string_at(img.data,img.bytes_per_line*200)
            return b"".join(raw[y*img.bytes_per_line+x*4:y*img.bytes_per_line+x*4+3][::-1]
                            for y in range(200) for x in range(320))
        finally:self.x.XDestroyImage(image)

    def key(self,window,symbol):
        self.x.XSetInputFocus(self.connection,window,1,0)
        code=self.x.XKeysymToKeycode(self.connection,symbol)
        if not code or not self.t.XTestFakeKeyEvent(self.connection,code,1,0):
            raise AssertionError("XTest rejected ordinary key")
        self.t.XTestFakeKeyEvent(self.connection,code,0,0)
        self.x.XFlush(self.connection)

    def space(self,window):self.key(window,0x20)
    def escape(self,window):self.key(window,0xff1b)

    def move(self,window,x,y):
        # The private game is centered at (160,140), with square-pixel320x200.
        # Query its translated origin rather than assuming a desktop placement.
        translate=self.x.XTranslateCoordinates
        translate.argtypes=[C.c_void_p,C.c_ulong,C.c_ulong,C.c_int,C.c_int,C.POINTER(C.c_int),C.POINTER(C.c_int),C.POINTER(C.c_ulong)]
        translate.restype=C.c_int
        rx=C.c_int();ry=C.c_int();child=C.c_ulong()
        if not translate(self.connection,window,self.root,x,y,C.byref(rx),C.byref(ry),C.byref(child)):
            raise AssertionError("cannot translate game pointer coordinates")
        self.x.XSetInputFocus(self.connection,window,1,0)
        self.t.XTestFakeMotionEvent(self.connection,0,rx.value,ry.value,0)
        self.x.XFlush(self.connection)

    def click(self,window,x,y):
        self.move(window,x,y)
        if not self.t.XTestFakeButtonEvent(self.connection,1,1,0):
            raise AssertionError("XTest rejected game-window button press")
        self.x.XFlush(self.connection)
        # Verify the X server sees this exact window position and held button.
        query=self.x.XQueryPointer
        query.argtypes=[C.c_void_p,C.c_ulong,C.POINTER(C.c_ulong),C.POINTER(C.c_ulong),
                        C.POINTER(C.c_int),C.POINTER(C.c_int),C.POINTER(C.c_int),
                        C.POINTER(C.c_int),C.POINTER(C.c_uint)]
        query.restype=C.c_int
        root=C.c_ulong();child=C.c_ulong();rx=C.c_int();ry=C.c_int()
        wx=C.c_int();wy=C.c_int();mask=C.c_uint()
        if not query(self.connection,window,C.byref(root),C.byref(child),C.byref(rx),
                     C.byref(ry),C.byref(wx),C.byref(wy),C.byref(mask)) or \
                (wx.value,wy.value)!=(x,y) or not(mask.value & 0x100):
            raise AssertionError("XTest click did not reach the exact game-window point")
        time.sleep(.2)
        if not self.t.XTestFakeButtonEvent(self.connection,1,0,0):
            raise AssertionError("XTest rejected game-window button release")
        self.x.XFlush(self.connection)

    def close(self):
        if getattr(self,"connection",None):self.x.XCloseDisplay(self.connection)
        self.server.terminate()
        try:self.server.wait(timeout=2)
        except subprocess.TimeoutExpired:self.server.kill();self.server.wait()
        self.log.close()


class RealtimeInputGate(unittest.TestCase):
    def run_game(self,inputs):
        self.assertIn("XANTH_PORT_BIN",os.environ,"set explicit packaged XANTH_PORT_BIN")
        self.assertIn("XANTH_DATA",os.environ,"set owner XANTH_DATA")
        binary=Path(os.environ["XANTH_PORT_BIN"]).resolve()
        data=Path(os.environ["XANTH_DATA"]).resolve()
        self.assertTrue(binary.is_file(),f"explicit packaged binary missing: {binary}")
        self.assertTrue((data/"XANTH.EXE").is_file(),"owned retail XANTH_DATA required")
        self.assertEqual(hashlib.sha256((data/"XANTH.EXE").read_bytes()).hexdigest(),
            "3982b5f5c055a4fd84b0a4fe3b911b7393af687b623d0d00f846c5da46d26671",
            "retail oracle requires the pinned owner executable")
        with tempfile.TemporaryDirectory(prefix="xanth-realtime-") as tmp:
            directory=Path(tmp);display=PrivateX(directory);game=None
            try:
                env={k:v for k,v in os.environ.items() if k not in
                     ("DISPLAY","WAYLAND_DISPLAY","XAUTHORITY","SDL_VIDEODRIVER","SDL_VIDEO_DRIVER")}
                env.update(DISPLAY=display.display,XAUTHORITY=str(display.authority),
                           SDL_VIDEODRIVER="x11",SDL_AUDIODRIVER="dummy",
                           XDG_CONFIG_HOME=str(directory/"config"),XDG_DATA_HOME=str(directory/"data"),
                           XDG_STATE_HOME=str(directory/"state"),XDG_CACHE_HOME=str(directory/"cache"),
                           XANTH_TRACE_INPUT="1")
                shot=directory/"final.bmp";log=open(directory/"game.log","wb")
                started=time.monotonic()
                game=subprocess.Popen([str(binary),"--data",str(data),"--saves",str(directory/"saves"),
                    "--scale","1","--pixel-perfect","--no-controller","--frames",str(3200 if inputs else 350),
                    "--shot",str(shot)],env=env,cwd=directory,stdout=log,stderr=log)
                hashes=set();bedroom=False;taken=False;window=None;clicks=0;spaces=0
                field_visible_since=None;neutral_toggle=False
                # Proven production intro recipe. The diagnostic heartbeat is
                # only every70frames; send each key at the first observed frame
                # at/after its target, then stop once the guest reports idle.
                key_frames=[300,900,1500,1800,2100,2400,2700]
                key_index=0;key_posts=[];field_handshakes=[];first_click_frame=None;quit_sent=False
                state_pattern=re.compile(r"\[input\] guest field=(\S+) frame=(\d+) polls=(\d+) caller=([0-9A-Fa-f]+) event=([0-9A-Fa-f]+) keys=(\d+)")
                while game.poll() is None and time.monotonic()-started<55:
                    elapsed=time.monotonic()-started
                    current_log=(directory/"game.log").read_text(errors="replace")
                    states=state_pattern.findall(current_log)
                    latest=states[-1] if states else None
                    # This validates the provider's declared FIELD result; it
                    # does not sample DS or duplicate the guest-state observer.
                    ready=bool(latest and latest[0]=="field-idle" and
                        latest[3].upper()=="095901A0" and int(latest[4],16)==8 and
                        int(latest[5])==0)
                    frame=int(latest[1]) if latest else 0
                    window=window or display.window()
                    if window:
                        try:
                            if inputs:
                                neutral_toggle=not neutral_toggle
                                display.move(window,305 if neutral_toggle else 304,196)
                                time.sleep(.02)
                            rgb=display.rgb(window)
                        except AssertionError:
                            try:game.wait(timeout=.2)
                            except subprocess.TimeoutExpired:raise
                            break
                        hashes.add(hashlib.sha256(rgb).hexdigest())
                        if (room_hash(rgb)==BEDROOM and crop_hash(rgb,VERB_PANEL)==VERBS
                            and crop_hash(rgb,SLOT)==EMPTY_SLOT):
                            bedroom=True
                            if field_visible_since is None:field_visible_since=elapsed
                        if inputs and ready and bedroom and clicks==0:
                            field_handshakes.append(latest)
                            display.click(window,105,103);clicks=1;first_click_frame=frame
                        elif inputs and ready and clicks==1 and frame>first_click_frame:
                            # Wait for another real returned idle event after
                            # object selection, not a fixed delay or stale state.
                            field_handshakes.append(latest)
                            display.click(window,14,7);clicks=2
                        if room_hash(rgb)==TAKEN_ROOM and crop_hash(rgb,SLOT)==ENVELOPE:
                            taken=True
                            if inputs and ready and clicks==2 and not quit_sent:
                                # The existing host Escape path exits normally
                                # and writes --shot after the verified guest turn.
                                display.escape(window);quit_sent=True
                        if inputs and not ready and not clicks and key_index<len(key_frames) and frame>=key_frames[key_index]:
                            display.space(window);spaces+=1
                            key_posts.append((key_frames[key_index],frame))
                            key_index+=1
                    time.sleep(.07)
                if game.poll() is None:
                    game.terminate();game.wait(timeout=2)
                    self.fail("packaged run exceeded 55s; no final-frame baseline accepted")
                log.close();output=(directory/"game.log").read_text(errors="replace")
                self.assertEqual(game.returncode,0,output[-2500:])
                self.assertTrue(shot.is_file(),"--shot did not produce final guest screenshot")
                final=bmp_rgb(shot)
                posts=re.findall(r"\[input\] post mouse state=(\d+) frame=(\d+) logical=(\d+),(\d+) field=(\S+)",output)
                acknowledgments=re.findall(r"\[input\] mouse state=(\d+) observed frame=(\d+) guest=(\d+),(\d+) field=(\S+) polls=(\d+)",output)
                report={"binary_sha256":hashlib.sha256(binary.read_bytes()).hexdigest(),
                    "input":inputs,"duration":round(time.monotonic()-started,2),
                    "spaces":spaces,"clicks":clicks,"visible_states":len(hashes),
                    "bedroom_visible_at":field_visible_since,
                    "intro_key_frames":key_posts,"field_handshakes":field_handshakes,"quit_after_oracle":quit_sent,
                    "source_input_posts":posts,"source_input_acknowledgments":acknowledgments,
                    "bedroom_oracle":bedroom,"envelope_oracle":taken,
                    "final_rgb_sha256":hashlib.sha256(final).hexdigest(),
                    "final_room_sha256":room_hash(final),"full_room_sha256":crop_hash(final,ROOM),"final_slot_sha256":crop_hash(final,SLOT)}
                artifact_root=os.environ.get("XANTH_REALTIME_ARTIFACTS")
                if artifact_root:
                    artifacts=Path(artifact_root)/("input" if inputs else "no-input")
                    artifacts.mkdir(parents=True,exist_ok=True)
                    shutil.copyfile(shot,artifacts/"final.bmp")
                    (artifacts/"game.log").write_text(output)
                    (artifacts/"report.json").write_text(json.dumps(report,indent=2))
                print(json.dumps(report),flush=True)
                return report
            finally:
                if game and game.poll() is None:
                    game.kill();game.wait()
                artifact_root=os.environ.get("XANTH_REALTIME_ARTIFACTS")
                if artifact_root:
                    artifacts=Path(artifact_root)/("input" if inputs else "no-input")
                    artifacts.mkdir(parents=True,exist_ok=True)
                    for filename in ("final.bmp","game.log"):
                        if (directory/filename).is_file():
                            shutil.copyfile(directory/filename,artifacts/filename)
                display.close()

    def test_no_input_renders_startup(self):
        report=self.run_game(False)
        self.assertNotEqual(report["final_rgb_sha256"],hashlib.sha256(bytes(320*200*3)).hexdigest(),
                            "no-input startup remains entirely black")

    def test_keyboard_progression_and_envelope_click(self):
        report=self.run_game(True)
        self.assertTrue(report["bedroom_oracle"],"ordinary spaces did not reach the verified retail bedroom")
        self.assertEqual(len(report["field_handshakes"]),2,
                         "actual source field-idle/empty-keyboard handshake unavailable before both clicks")
        expected_states=["1","0","1","0"]
        expected_points=[("105","103"),("105","103"),("14","7"),("14","7")]
        for records in (report["source_input_posts"],report["source_input_acknowledgments"]):
            self.assertEqual([record[0] for record in records],expected_states)
            self.assertEqual([tuple(record[2:4]) for record in records],expected_points)
            self.assertTrue(all(record[4] in ("field-idle","busy-event") for record in records),
                            "a gesture reached a modal/guard/unknown guest state")
        self.assertTrue(report["envelope_oracle"],"real game-window clicks did not take the envelope")
        self.assertEqual(report["final_slot_sha256"],ENVELOPE,"final --shot lacks the verified envelope")


if __name__=="__main__":unittest.main()
