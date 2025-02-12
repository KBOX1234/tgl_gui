#include <stdlib.h>
#include <string.h>

#define IMG_LOADING

#include "terminal_gl.h"
#include "impl/backend_linux.c"

#include "tgl_gui.h"

int main(){

    init_window("tgl gui example");

    struct window* test = create_window("status", 30, 10);
    struct window* test2 = create_window("inct log", 20, 10);

    struct text_image guy = load_buffer("test.x");

    printf_win(test, 0xe0, "hello there\n");
    printf_win(test, 0x04, "number: %d\n", 9);
    int xi = 30;
    int yi = 9;
    unsigned long inct = 0;

    while (1){
        fill_screen(' ', 0xf0);
        scan_input();
        printf_win(test2, 0xe0, "inct: %d\n", inct);

        render_window(test, 3, 3);

        render_text_image(guy, xi, yi, 0);

        render_window(test2, 3, 30);

        update();
        scan_input();

        if(is_key_pressed('w') == 0){
            printf_win(test, 0xa0, "W key pressed\n");
            yi++;
        }

        if(is_key_pressed('a') == 0){
            printf_win(test, 0xa0, "A key pressed\n");
            xi++;
        }

        if(is_key_pressed('s') == 0){
            printf_win(test, 0xa0, "S key pressed\n");
            yi--;
        }

        if(is_key_pressed('d') == 0){
            printf_win(test, 0xa0, "D key pressed\n");
            xi--;
        }
        inct++;
    }
    

    return 0;
}
