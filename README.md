# TGL UI 
Tgl ui is a project aimed to add usefull debuging and graphics interfaces to [terminal gl](https://github.com/KBOX1234/terminal_gl).

## Why does this exist
People (not many people) probubly wonder why this exists. The reason it exists is becaus everyone uses the terminal for quick debugging. But becaus terminal gl runs in the terminal, that is not an option. The main priority of tgl ui is to bring that functionality back along with adding cool Uis in later on.

## How to get started
(Assuming you have experiance with terminal gl), let us start with creating a window:
```c
struct window* my_debug_window = create_window("my_debug window", 30, 10);
```
now you have a simple debug window, but how do you use it?
First, you need to print text to it and then render it:
```c
printf_win(my_debug_window, 0xe0, "this can work just like printf, here is a number: %d\n", 100);
render_window(my_debug_window, 3, 3);
```
Just remember to include the library before you include the terminal gl backend as well as to update the screen with the update command.
Once you have done that, you should be good to go :))
