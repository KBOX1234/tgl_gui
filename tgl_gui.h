#include <stdarg.h>

struct window{
    int size_x;
    int size_y;

    char* char_buffer;
    char* color_buffer;

    char* title;

    int cursor_x;
    int cursor_y;

    int x;
    int y;
};

struct window* windows;
struct window* current_window;
int window_inc = 0;

struct window* create_window(const char* name, int size_x, int size_y);

void render_window(struct window* win, int x, int y);

void draw_char_win(char c, int x, int y, char color, struct window* win);

void printf_win(struct window* win, char color, const char *format, ...);

void set_cursor_pos_win(struct window* win, int x, int y);

void clear_win(struct window* win);

#include "include/window.c"
#include "include/debug_tgl.c"
#include "include/io.c"