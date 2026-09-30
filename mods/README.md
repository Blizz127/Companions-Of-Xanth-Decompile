# Local asset replacements

This directory is for user-created, local replacements. No mod assets are
included or loaded by default. Pass `--mods mods` or set `mods=mods` in an
explicit port config to enable lookup.

Graphics replacements (`.PIC` and `.RGN`) additionally require
`--replacement-graphics`; font replacements (`.FNT`) require
`--replacement-fonts`. These switches are independent, so `--mods mods` alone
preserves the retail pictures, regions, and fonts. A missing replacement falls
back to the original asset.

Each replacement file must be named as the lowercase SHA-256 digest of the
original retail asset, with no extension. The port hashes the original file
from the user-supplied game directory and opens the matching file here when it
exists. The replacement must use the same file format the game expects.

The optional `--enhanced-graphics` switch enables linear display filtering and
CRT scanlines. It does not enable asset replacements. These display effects
leave the game's 320x200 pixels, palette, screenshot output, and hit-testing
coordinates intact; they do not add higher-resolution scene assets. Use
`--linear` or `--crt` to select either effect separately, and `--pixel-perfect`
for square-pixel integer scaling.

Replacement assets are ignored by Git so they are not accidentally committed
or distributed with the port. Keep your own backups of any local mods.
