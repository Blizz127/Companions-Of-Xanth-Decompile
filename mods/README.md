# Local asset replacements

This directory is for user-created, local replacements. No mod assets are
included or loaded by default. Pass `--mods mods` or set `mods=mods` in an
explicit port config to enable lookup.

Each replacement file must be named as the lowercase SHA-256 digest of the
original retail asset, with no extension. The port hashes the original file
from the user-supplied game directory and opens the matching file here when it
exists. The replacement must use the same file format the game expects.

Replacement assets are ignored by Git so they are not accidentally committed
or distributed with the port. Keep your own backups of any local mods.
