#include <stdlib.h>
#include <string.h>

#include "terminal_gl.h"
#include "impl/backend_linux.c"

#include "tgl_gui.h"

int main(){

    init_window("tgl gui example");

    struct window* test = create_window("status", 30, 10);
    struct window* test2 = create_window("inct log", 20, 10);

    printf_win(test, 0xe0, "hello there\n");
    printf_win(test, 0xf0, "number: %d\n", 9);
    int xi = 3;
    unsigned long inct = 0;

    while (1){
        fill_screen(' ', 0xf0);
        scan_input();
        printf_win(test2, 0xe0, "inct: %d\n", inct);

        render_window(test, 3, 3);
        render_window(test2, xi, 30);

        update();
        scan_input();

        if(is_key_pressed('t') == 1) printf_win(test, 0x30, "key 't' pressed\n");
        if(is_key_pressed('l') == 1) printf_win(test, 0x10, "key 'l' pressed\n");
        inct++;
    }
    

    return 0;
}