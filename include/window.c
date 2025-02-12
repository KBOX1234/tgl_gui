void render_window(struct window* win, int x, int y){
    int pointer_x = x;
    int pointer_y = y;

    int index_inc = 0;

    while(pointer_y < y + win->size_y){
        while(pointer_x < x + win->size_x){
            draw_char(win->char_buffer[index_inc], pointer_x, pointer_y, win->color_buffer[index_inc]);
            pointer_x++;
            index_inc++;
        }
        pointer_y++;
        pointer_x = x;
    }
}

struct window* new_window(char* name, int size_x, int size_y){
    struct window* win_return = (struct window*)malloc(sizeof(struct window));

    win_return->size_x = size_x;
    win_return->size_y = size_y;
    win_return->title = name;

    win_return->char_buffer = (char*)malloc(size_x*size_y);
    win_return->color_buffer = (char*)malloc(size_x*size_y);

    win_return->cursor_x = 2;
    win_return->cursor_y = 2;

    return win_return;
}