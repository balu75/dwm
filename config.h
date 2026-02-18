/* This File has to be maintained by hand */

#include <X11/XF86keysym.h>

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 10;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "Roboto Mono Nerd Font:size=10:weight:bold" };
static const char dmenufont[]       = "Roboto Mono Nerd Font:size=11";

//catppuccin - Mocha
static const char col_rosewater[] = "#f5e0dc";
static const char col_flamingo[]  = "#f2cdcd";
static const char col_pink[]      = "#f5c2e7";
static const char col_mauve[]     = "#cba6f7";
static const char col_red[]       = "#f38ba8";
static const char col_maroon[]    = "#eba0ac";
static const char col_peach[]     = "#fab387";
static const char col_yellow[]    = "#f9e2af";
static const char col_green[]     = "#a6e3a1";
static const char col_teal[]      = "#94e2d5";
static const char col_sky[]       = "#89dceb";
static const char col_sapphire[]  = "#74c7ec";
static const char col_blue[]      = "#89b4fa";
static const char col_lavender[]  = "#b4befe";
static const char col_text[]      = "#cdd6f4";
static const char col_subtext1[]  = "#bac2de";
static const char col_subtext0[]  = "#a6adc8";
static const char col_overlay2[]  = "#9399b2";
static const char col_overlay1[]  = "#7f849c";
static const char col_overlay0[]  = "#6c7086";
static const char col_surface2[]  = "#585b70";
static const char col_surface1[]  = "#45475a";
static const char col_surface0[]  = "#313244";
static const char col_base[]      = "#1e1e2e";
static const char col_mantle[]    = "#181825";
static const char col_crust[]     = "#11111b";

static const char *colors[][3]    = {
  /*             fg             bg                  border   */
  [SchemeNorm] = { col_text,    col_base,           col_overlay2 },
  [SchemeSel]  = { col_text,    col_surface0,       col_lavender },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", ""};

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class            instance    title       tags mask     isfloating   monitor */
  0
};

/* layout(s) */
static const float mfact     = 0.75; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "[]=",      tile },    /* first entry is default */
  { "><>",      NULL },    /* no layout function means floating behavior */
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_sapphire, "-nf", col_pink, "-sb", col_text, "-sf", col_blue, NULL };
static const char *roficmd[] = {"rofi", "-show", "combi", "-modes", "combi", "-combi-modes", "drun,run", NULL};
static const char *termcmd[]  = { "kitty", NULL };
static const char *dvolupcmd[] = { "/home/thomas/bin/volumeup", NULL };
static const char *dvoldowncmd[] = { "/home/thomas/bin/volumedown", NULL };
static const char *dvolmutecmd[] = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *dvolmicmutecmd[] = { "amixer", "-q", "set", "Mic", "toggle", NULL };
static const char *dbrightdowncmd[] = { "xbacklight", "-dec", "20", NULL };
static const char *dbrightupcmd[] = { "xbacklight", "-inc", "20", NULL };
static const char *clipmenucmd[] = { "clipmenu", NULL };
static const char *configcmd[] = { "/home/thomas/dev/config/target/config", NULL };
static const char *progscmd[] = { "/home/thomas/dot-files/menu/power", NULL };
static const char *normal[] = { "selscreen", "normal", NULL };
static const char *ldesk[] = { "selscreen", "ldesk", NULL };
static const char *desk[] = { "selscreen", "desk", NULL };
static const char *suspendcmd[] = { "systemctl", "suspend", NULL };
static const char *poweroffcmd[] = { "systemctl", "hibernate", NULL };
static const char *browsercmd[] = { "firefox", NULL };
static const char *browserinccmd[] = { "firefox", "--private-window", NULL };
static const char *displayoffcmd[] = { "sh", "-c","sleep 3 && xset dpms force off", NULL };
static const char *us[] = { "/home/thomas/bin/us", NULL };
static const char *de[] = { "/home/thomas/bin/de", NULL };
static const char *bluetoothcmd[] = { "kitty", "bluetui", NULL };
static const char *btopcmd[] = { "kitty", "btop", NULL };
static const char *yazicmd[] = { "kitty", "yazi", NULL };
static const char *dwmconfigcmd[] = { "kitty", "-d", "/home/thomas/suckless/dwm/", "nvim", "config.h", NULL };
static const char *wlancmd[] = { "kitty", "connect_wlan", NULL};

static Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,                       XK_b,      spawn,          {.v = browsercmd } },
  { MODKEY|ShiftMask,             XK_b,      spawn,          {.v = browserinccmd } },
  { MODKEY|ControlMask,           XK_b,      spawn,          {.v = bluetoothcmd } },
  { MODKEY,                       XK_p,      spawn,          {.v = roficmd } },
  { MODKEY,                       XK_y,      spawn,          {.v = yazicmd } },
  { MODKEY|ShiftMask,             XK_t,      spawn,          {.v = btopcmd } },
  { MODKEY,                       XK_c,      spawn,          {.v = dwmconfigcmd } },

  { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },

  { MODKEY,                       XK_F1,     spawn,          {.v = progscmd } },
  { MODKEY,                       XK_F2,     spawn,          {.v = clipmenucmd } },
  { MODKEY,                       XK_F3,     spawn,          {.v = wlancmd } },
  { MODKEY,                       XK_F8,     togglebar,      {0} },
  { MODKEY,                       XK_F9,     spawn,          {.v = de } },
  { MODKEY|ShiftMask,             XK_F9,     spawn,          {.v = us } },
  { MODKEY,                       XK_F10,    spawn,          {.v = poweroffcmd } },
  { MODKEY,                       XK_F11,    spawn,          {.v = suspendcmd } },
  { MODKEY|ShiftMask,             XK_F11,    spawn,          {.v = displayoffcmd } },
  { MODKEY,                       XK_F12,    spawn,          {.v = normal } },
  { MODKEY|ShiftMask,             XK_F12,    spawn,          {.v = desk } },
  { MODKEY|ControlMask,           XK_F12,    spawn,          {.v = ldesk } },
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
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
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
  { 0,                            XF86XK_AudioRaiseVolume,   spawn,          {.v = dvolupcmd } },
  { 0,                            XF86XK_AudioLowerVolume,   spawn,          {.v = dvoldowncmd } },
  { 0,                            XF86XK_AudioMute,          spawn,          {.v = dvolmutecmd } },
  { 0,                            XF86XK_AudioMicMute,       spawn,          {.v = dvolmicmutecmd } },
  { 0,                            XF86XK_MonBrightnessUp,    spawn,          {.v = dbrightupcmd } },
  { 0,                            XF86XK_MonBrightnessDown,  spawn,          {.v = dbrightdowncmd } },
  { 0,                            XF86XK_Launch1,            spawn,          {.v = configcmd } },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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


