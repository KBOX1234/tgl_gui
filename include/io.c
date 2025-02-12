void draw_char_win(char c, int x, int y, char color, struct window* win) {
    if (x >= 0 && x < win->size_x && y >= 0 && y < win->size_y) {
        size_t index = (y * win->size_x) + x;
        win->char_buffer[index] = c;
        win->color_buffer[index] = color;
    }
}

void printf_win(struct window* win, char color, const char *format, ...) {
    va_list args;
    va_start(args, format);

    size_t size = vsnprintf(NULL, 0, format, args) + 1;
    va_end(args);
    char* buffer = malloc(size);
    if (!buffer) return;

    va_start(args, format);
    vsnprintf(buffer, size, format, args);
    va_end(args);

    for (int inc = 0; inc < size; inc++) {
        if (buffer[inc] == '\n') {
            win->cursor_y++;
            win->cursor_x = 0;
            buffer[inc] = ' ';
        } else if (win->cursor_x >= win->size_x) {
            win->cursor_x = 0;
            win->cursor_y++;
        }

        if (win->cursor_y >= win->size_y) {

            size_t total_size = win->size_x * win->size_y;
            memmove(win->char_buffer, win->char_buffer + win->size_x, total_size - win->size_x);
            memmove(win->color_buffer, win->color_buffer + win->size_x, total_size - win->size_x);


            memset(win->char_buffer + total_size - win->size_x, ' ', win->size_x);
            memset(win->color_buffer + total_size - win->size_x, 0xf0, win->size_x);

            win->cursor_y = win->size_y - 1;
        }

        draw_char_win(buffer[inc], win->cursor_x, win->cursor_y, color, win);
        if(buffer[inc] == '\0'){
            draw_char_win(' ', win->cursor_x, win->cursor_y, color, win);
        }
        win->cursor_x++;
    }

    free(buffer);
}
