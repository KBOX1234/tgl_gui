#include "../include/tgl_gui.h"

#include <terminal_gl.h>
#include <stdlib.h>
#include <string.h>


window** windows = NULL;
window* current_window = NULL;
int window_inc = 0;


void render_window(window* win, int x, int y){
    if(win == NULL) return;
    int pointer_x = x;
    int pointer_y = y;

    int index_inc = 0;

    //draw content
    while(pointer_y < y + win->size_y){
        while(pointer_x < x + win->size_x){
            draw_char(win->char_buffer[index_inc], pointer_x, pointer_y, win->color_buffer[index_inc]);
            pointer_x++;
            index_inc++;
        }
        pointer_y++;
        pointer_x = x;
    }

    pointer_y = y;
    //draws sides
    while(pointer_y < y + win->size_y){
        draw_char('|', x, pointer_y, 0xf0);
        
        draw_char('|', x + win->size_x, pointer_y, 0xf0);
        pointer_y++;
    }

    for (int px = x; px < x + win->size_x; px++) {
        draw_char('=', px, y, 0xf0);
        draw_char('=', px, y + win->size_y - 1, 0xf0);
    }

    for (int py = y; py < y + win->size_y; py++) {
        draw_char('|', x, py, 0xf0);
        draw_char('|', x + win->size_x - 1, py, 0xf0);
    }

    draw_text(win->title, x + 3, y, 0x20);
    

}

window* new_window(const char* name, int size_x, int size_y){
    window* win_return = malloc(sizeof(window));

    win_return->size_x = size_x;
    win_return->size_y = size_y;

    char* new_name = malloc(strlen(name) + 1);
    strcpy(new_name, name);
    win_return->title = new_name;

    win_return->char_buffer = (char*)malloc(size_x*size_y);
    win_return->color_buffer = (char*)malloc(size_x*size_y);
    memset(win_return->char_buffer, ' ', size_x*size_y);
    memset(win_return->color_buffer, 0xf0, size_x*size_y);

    win_return->cursor_x = 2;
    win_return->cursor_y = 2;

    return win_return;
}

window* create_window(const char* name, int size_x, int size_y){
    window_inc++;
    window** new_list = malloc(sizeof(window*) * window_inc);

    memcpy(new_list, windows, sizeof(window*)*(window_inc-1));

    free(windows);
    windows = new_list;

    windows[window_inc] = new_window(name, size_x, size_y);
    windows[window_inc]->x = 5;
    windows[window_inc]->y = 5;

    return windows[window_inc];
}

void clear_win(window* win){
    int size_x = win->size_x;
    int size_y = win->size_y;

    win->cursor_x = 0;
    win->cursor_y = 0;
    memset(win->char_buffer, ' ', size_x*size_y);
    memset(win->color_buffer, 0xf0, size_x*size_y);
}

void set_cursor_pos_win(window* win, int x, int y){
    win->cursor_x = x;
    win->cursor_y = y;
}

void destroy_window(window *w){
    free(w->char_buffer);
    free(w->title);
    free(w->color_buffer);
    free(w);
}
