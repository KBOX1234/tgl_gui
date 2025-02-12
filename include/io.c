void draw_char_win(char c, int x, int y, char color, struct window* win){
    if(x < win->size_x && x > 0){
        if(y < win->size_y && y > 0){
            win->char_buffer[win->size_x*y+x] = c;
            win->color_buffer[win->size_y*y+x] = color;
        }
    }
}

void printf_win(struct window* win, char color, const char *format, ...){
    va_list args;
    va_start(args, format);

    size_t size = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);
    char* buffer = malloc(size);

    va_start(args, format);
    vsnprintf(buffer, size, format, args);
    va_end(args);

    int inc = 0;

    while(inc < size){

        if(buffer[inc] == '\n'){
            win->cursor_y++;
            win->cursor_x = 0;
            buffer[inc] = ' ';
        }
        else if(win->cursor_x >= win->size_x){
            win->cursor_x = 1;
            win->cursor_y++;
        }

        else if(win->cursor_y >= win->size_y){
            size_t total_size = win->size_x * win->size_y;
            char* new_char_buffer = malloc(total_size);
            char* new_color_buffer = malloc(total_size);

            memcpy(new_char_buffer, &win->char_buffer[win->size_x], total_size - win->size_x);
            memset(&new_char_buffer[total_size - win->size_x], ' ', win->size_x);

            memcpy(new_color_buffer, &win->color_buffer[win->size_x], total_size - win->size_x);
            memset(&new_color_buffer[total_size - win->size_x], 0xf0, win->size_x);

            free(win->char_buffer);
            free(win->color_buffer);
            win->char_buffer = new_char_buffer;
            win->color_buffer = new_color_buffer;

            win->cursor_y--;
        }
        if(buffer[inc] != '\0'){
            draw_char_win(buffer[inc], win->cursor_x, win->cursor_y, color, win);
        }
        else{
            draw_char_win(' ', win->cursor_x, win->cursor_y, color, win);
        }
        win->cursor_x++;
        inc++;
    }

    free(buffer);
    
}