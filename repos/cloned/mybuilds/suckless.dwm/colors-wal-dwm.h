static char norm_fg[] = "#caa9c1";
static char norm_bg[] = "#010101";
static char norm_border[] = "#8d7687";

static char sel_fg[] = "#caa9c1";
static char sel_bg[] = "#974D50";
static char sel_border[] = "#caa9c1";

static char status_fg[] = "#caa9c1";
static char status_bg[] = "#CC6C2A";
static char status_border[] = "#CC6C2A";

static char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [SchemeStatus] =  { status_fg,      status_bg,    status_border },
};
