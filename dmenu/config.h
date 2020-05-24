/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 0;                    /* -c option; centers dmenu on screen			 */
static int min_width = 500;                 /* minimum width when centered					 */
static unsigned int lineheight = 0;         /* -h option; minimum height of a menu line    	 */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Hermit:size=9"
};

static const char col_gray1[] = "#181818"; // Dark gary
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#F0F0F0"; // White gray

static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
				/*     fg         bg       */
	[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel] = { col_gray1, col_gray4},
	[SchemeOut] = { col_gray4, col_gray1 },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
