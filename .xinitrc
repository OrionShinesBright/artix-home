#!/bin/bash

[ -f ~/.xprofile ] && source /home/orion/.xprofile
xdg-user-dirs-update &
picom -b

WALLPAPER="/home/orion/media/pics/wals/$(ls ~/media/pics/wals | shuf | head -1)"
xwallpaper --zoom "$WALLPAPER"
wal -o /home/orion/sys/scripts/wal_reload -i "$WALLPAPER"
export WALLPAPER="$WALLPAPER"

exec dwm
