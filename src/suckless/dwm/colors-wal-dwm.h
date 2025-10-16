static char norm_fg[] = "#c8cb9a";
static char norm_bg[] = "#11130f";
static char norm_border[] = "#8c8e6b";

static char sel_fg[] = "#c8cb9a";
static char sel_bg[] = "#897642";
static char sel_border[] = "#c8cb9a";

static char status_fg[] = "#c8cb9a";
static char status_bg[] = "#5C6B4B";
static char status_border[] = "#5C6B4B";

static char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeStatus] =  { status_fg,      status_bg,    status_border },
};
