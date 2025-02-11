#include <stdlib.h>
#include <string.h>

#include "terminal_gl.h"
#include "impl/backend_linux.c"

#include "debug_tgl.h"

int main(){

    init_window("tgl gui example");

    while (1){
        fill_screen(' ', 0xf0);



        update();
    }
    

    return 0;
}