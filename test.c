#include <stdlib.h>
#include <string.h>

#include "terminal_gl.h"
#include "impl/backend_linux.c"

#include "tgl_gui.h"

int main(){

    init_window("tgl gui example");

    struct window* test = new_window("test window", 20, 20);
    struct window* test2 = new_window("test2 window", 20, 20);

    printf_win(test, 0x40, "hello there kenobi___\n");
    printf_win(test, 0xf0, "number: %d\n", 9);
    printf_win(test, 0xf0, "this text will print to the next line becaus it is too long for the window to handle\n");
    //printf_win(test, 0xf0, "number: %d\n", 200);
    unsigned long inct = 0;

    while (1){
        fill_screen(' ', 0xf0);
        scan_input();
        printf_win(test2, 0xf0, "inct: %d\n", inct);


        render_window(test, 3, 3);
        render_window(test2, 3, 23);
        update();
        inct++;
    }
    

    return 0;
}