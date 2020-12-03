/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 5;		/* snap pixel */
static const unsigned int gappx     = 8;        /* gap pixel between windows */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Hermit:size=9" };
static const char dmenufont[]       = "Hermit:size=9";
static const char col_gray1[]       = "#181818"; // Dark gary
static const char col_gray2[]       = "#00ffff"; // aqua (cyan)
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#F0F0F0"; // White gray
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*                        fg         bg         border   */
	[SchemeNorm] 		= { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  		= { col_gray1, col_gray4, col_gray2 },
	[SchemeStatus]  	= { col_gray3, col_gray1,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  	= { col_gray1, col_gray4,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  	= { col_gray3, col_gray1,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  	= { col_gray3, col_gray1,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  	= { col_gray3, col_gray1,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           		tags mask  iscentered   isfloating  isterminal  noswallow  monitor */
	{ "Gimp",    NULL,     NULL,           		0,        1,           1,          0,          0,         -1 },
	{ "Firefox", NULL,     NULL,           		1 << 8,   0,		   0,          0,         -1,         -1 },
	{ "discord", NULL,	   NULL,		   		2,	      0,		   0,          0,          1,         -1 },
	{ "st",      NULL,     NULL,           		0,        0,		   0,          1,         -1,         -1 },
	{ NULL,	 	 NULL,	   "pulsemixer",   		0,	      1,		   1,          0,          1,         -1 },
	{ NULL,      NULL,     "Event Tester", 		0,        0,		   1,          0,          1,         -1 },
	{ NULL,      NULL,     "Payload Injector",  0,        0,		   0,          0,          1,         -1 }
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
// #define MODKEY Mod1Mask // Using ALT as MODKEY
#define MODKEY Mod4Mask // Using SUPER as MODKEY
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,    	        KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_gray4, "-sf", col_gray1, NULL };
static const char term[]  = "st";
static const char *termcmd[]  = { term, NULL };

/* Personal variable*/
static const char *firefox[]  	  = { "firefox", NULL };
static const char *discord[]	  = { "discord", NULL };
static const char *ncmpcpp[]	  = { term, "-e", "ncmpcpp", NULL };
static const char *pulsemixer[]	  = { term, "-e", "pulsemixer", NULL };
static const char *switchkbmap[]  = { "switch_kb", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	//{ MODKEY,                       XK_b,      togglebar,      {0} },
	/* Begin personal bindings */
	{ MODKEY,                       XK_a,      spawn,          {.v = switchkbmap } },
	{ MODKEY,                       XK_b,      spawn,          {.v = firefox } },
	{ MODKEY,                       XK_w,      spawn,          {.v = discord } },
	{ MODKEY,                       XK_n,      spawn,          {.v = ncmpcpp } },
	{ MODKEY,                       XK_p,      spawn,          {.v = pulsemixer } },
	/* End personal bindings */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,		                XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

