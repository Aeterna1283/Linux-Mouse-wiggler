# Linux-Mouse-wiggler
Creates a fake registered device recognized by the linux kernel, that wiggles the users mouse



Requires installing libevdev with this command: sudo apt install libevdev-dev

once done, the program can be compiled with gcc -Wall -o maus mouse_wiggle.c $( pkg-config --cflags --libs libevdev) 
(the executable can be called whatever you wish)

and requires sudo privileges to run with sudo ./ex_name 

if the session type is Wayland it probably will not work so trying switching to X11 for the full effects of the mouse jiggle. Performance varies on virtual machines. 

By using sudo evtest, the fake mouse will be seen with other devices recognized by the linux kernel.
