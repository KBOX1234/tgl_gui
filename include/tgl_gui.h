#ifndef TGL_GUI_H


#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>

typedef struct window{
    int size_x;
    int size_y;

    char* char_buffer;
    char* color_buffer;

    char* title;

    int cursor_x;
    int cursor_y;

    int x;
    int y;
} window;

extern window* windows;
extern window* current_window;
extern int window_inc;

window* create_window(const char* name, int size_x, int size_y);

void render_window(window* win, int x, int y);

void draw_char_win(char c, int x, int y, char color, window* win);

void printf_win(window* win, char color, const char *format, ...);

void set_cursor_pos_win(window* win, int x, int y);

void clear_win(window* win);

#ifdef __cplusplus
}
#endif

#endif
