/* See LICENSE file for copyright and license details. */
//#define ACTUALFULLSCREEN /* Uncomment if the actualfullscreen patch is added */
//#define AWESOMEBAR /* Uncommnet if the awesomebar patch is used */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 14;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=12" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=12";
static const unsigned int gappx     = 1;        /* gap pixel between windows */

#include "colors-wal-dwm.h"

/* status bar */
static const Block blocks[] = {
	/* fg     		command		interval	signal */
	{ status_fg, "bar_battery", 60, 0},
	{ status_fg, "printf '%(%d-%m-%Y)T'",	60, 0},
	{ status_fg, "printf '%(%H:%M %p)T'",	60, 0},
	{ status_fg, "bar_audio_change", 0, 4},
	{ status_fg, "bar_mic_change", 0, 5}
};

/* inverse the order of the blocks, comment to disable */
#define INVERSED	1
/* delimeter between blocks commands. NULL character ('\0') means no delimeter. */
static char delimiter[] = " | ";
/* max number of character that one block command can output */
#define CMDLENGTH	50


/* tagging */
static const char *tags[] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
static const char *tagsalt[] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
static const int momentaryalttags = 1; /* 1 means alttags will show only when key is held down*/

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "floating-st-scratch", "menu-st",   "MENU",  0,   1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 2;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 60;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_border, "-sf", norm_bg, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *upbrightness[]   = { "xbacklight", "-inc", "5", NULL };
static const char *downbrightness[] = { "xbacklight", "-dec", "5", NULL };
static const char *incvol[] = {"audio_inc", NULL};
static const char *decvol[] = {"audio_dec", NULL};
static const char *mutevol[] = {"audio_toggle", NULL};
static const char *mutemic[] = {"mic_toggle", NULL};
static const char *yazi[] = {"st", "-e", "dwm_yazi", NULL};
static const char *MENU[] = {"MENU", NULL};

#include "exitdwm.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */

	/*
	 * SPAWNING
	 */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,	             		XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,						XK_e,	   spawn,		   {.v = yazi } },
	{ MODKEY,						XK_a,	   spawn,		   {.v = MENU } },
	/*
	 * DESPAWNING
	 */
	{ MODKEY,             			XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,      exitdwm,        {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} }, 
	/*
	 * TOGGLES
	 */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	/*
	 * LAYOUTS
	 */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	/*
	 * NAVIGATION
	 */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_r,      togglepreviewallwin,  {0} },
	/*
	 * TAGS
	 */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	/*
	 * BUILT-IN KEYS
	 */
	{ 0,            XF86XK_MonBrightnessUp,    spawn,          {.v = upbrightness } },
	{ 0,            XF86XK_MonBrightnessDown,  spawn,          {.v = downbrightness } },
	{ 0,			XF86XK_AudioLowerVolume,   spawn,		   {.v = decvol} },	
	{ 0,			XF86XK_AudioRaiseVolume,   spawn,		   {.v = incvol} },
	{ 0,			XF86XK_AudioMute,		   spawn,		   {.v = mutevol} },
	{ 0,			XF86XK_AudioMicMute,	   spawn,		   {.v = mutemic} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },

	{ ClkStatusText,        0,              Button1,        sendstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,              Button2,        sendstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,              Button3,        sendstatusbar,   {.i = 3 } },
	{ ClkStatusText,        0,              Button4,        sendstatusbar,   {.i = 4 } },
	{ ClkStatusText,        0,              Button5,        sendstatusbar,   {.i = 5 } },
	{ ClkStatusText,        ShiftMask,      Button1,        sendstatusbar,   {.i = 6 } },

	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

