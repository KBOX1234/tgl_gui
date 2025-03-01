void render_window(struct window* win, int x, int y){
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

    pointer_x = x;
    pointer_y = y;
    while(pointer_y <= y + win->size_y){
        while(pointer_x <= x + win->size_x){
            draw_char('=', pointer_x, pointer_y, 0xf0);
            pointer_x++;
        }
        pointer_y = pointer_y + win->size_y;
        pointer_x = x;
    }

    draw_text(win->title, x + 3, y, 0x20);
    

}

struct window* new_window(const char* name, int size_x, int size_y){
    struct window* win_return = (struct window*)malloc(sizeof(struct window));

    win_return->size_x = size_x;
    win_return->size_y = size_y;

    char* new_name = (char*)malloc(strlen(name) + 1);
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

struct window* create_window(const char* name, int size_x, int size_y){
    window_inc++;
    struct window* new_list = (struct window*)malloc(sizeof(struct window) * window_inc);

    memcpy(new_list, windows, sizeof(struct window)*(window_inc-1));

    //free(windows);
    windows = new_list;

    windows[window_inc] = *new_window(name, size_x, size_y);
    windows[window_inc].x = 5;
    windows[window_inc].y = 5;

    return &windows[window_inc];
}

void clear_win(struct window* win){
    int size_x = win->size_x;
    int size_y = win->size_y;

    win->cursor_x = 0;
    win->cursor_y = 0;
    memset(win->char_buffer, ' ', size_x*size_y);
    memset(win->color_buffer, 0xf0, size_x*size_y);
}

void set_cursor_pos_win(struct window* win, int x, int y){
    win->cursor_x = x;
    win->cursor_y = y;
}
