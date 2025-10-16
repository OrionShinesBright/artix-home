#!/bin/bash

[ -f ~/.xprofile ] && source /home/orion/.xprofile
xdg-user-dirs-update &
picom -b

WALLPAPER="/home/orion/pics/walls/$(ls ~/pics/walls | shuf | head -1)"
xwallpaper --zoom "$WALLPAPER"
wal -o /home/orion/src/SCRIPTS/wal_reload -i "$WALLPAPER"
export WALLPAPER="$WALLPAPER"

exec dwm
