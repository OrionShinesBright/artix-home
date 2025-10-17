################
# ZSH Settings #
################

# History
HISTFILE=~/.cache/zsh_history
HISTSIZE=2000
SAVEHIST=2000

# Options
setopt autocd
unsetopt beep

# Keybinds
bindkey -e

# Completions
zstyle :compinstall filename '/home/orion/.zshrc'
autoload -Uz compinit
compinit

################
# Env Settings #
################

# Exports
export EDITOR="$HOME/.config/nvim/nvim-linux-x86_64/bin/nvim"
export PATH="$PATH:/home/orion/sys/scripts"

###########
# Aliases #
###########

# Dotfiles
alias dots='/usr/bin/git --git-dir="$HOME/sys/palantir/bare-repo/.git-bare" --work-tree="$HOME"'

# Programs
alias nvim="NVIM_APPNAME=nvim $HOME/.config/nvim/nvim-linux-x86_64/bin/nvim"
alias e='yazi'

# Editing files
alias z="${EDITOR} ~/.zshrc"

# Navigation
export REPOSDIR="/home/orion/repos"
export DWMDIR="$REPOSDIR/cloned/suckless.dwm"
alias ndwm="cd $DWMDIR"
export DMENUDIR="$$REPOSDIR/cloned/suckless.dmenu"
alias ndmenu="cd $DMENUDIR"
export STDIR="$REPOSDIR/cloned/suckless.st"
alias nst="cd $STDIR"
export SCRIPTSDIR="/home/orion/sys/scripts"
alias nscr="cd $SCRIPTSDIR"
export STUDYDIR="/home/orion/study/sem3"
alias nstudy="cd $STUDYDIR"
export XDG_CONFIG_DIR="/home/orion/.config"
alias nconf="cd $XDG_CONFIG_DIR"

# Coreutils (Not specifically GNU ones)
alias ls="ls --color=auto -1 --group-directories-first --si --classify"
alias grep="grep --color=auto"
alias less="less -R"
alias df='df -h /'
alias fstab="sed 's/#.*//' /etc/fstab | column --table --table-columns SOURCE,TARGET,TYPE"

# Useful
alias b='cat /sys/class/power_supply/BAT0/capacity'

##############
# Aesthetics #
##############

# Pywal
(cat ~/.cache/wal/sequences &)
source ~/.cache/wal/colors-tty.sh

# Info Fetching
macchina --show kernel,distribution,packages,uptime,memory,battery -t Beryllium

PS1='%F{blue}%~%F{yellow} >%F{white} '
