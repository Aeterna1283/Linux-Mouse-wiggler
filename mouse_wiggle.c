#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>



int main()
{
    //1 create a "fake" mouse device
    struct libevdev *dev = libevdev_new();
    struct libevdev_uinput *uidev = NULL;

    libevdev_set_name(dev, "USB Fake Mouse");

    //what is the device capable of
     libevdev_enable_event_type(dev, EV_REL);
     libevdev_enable_event_code(dev, EV_REL, REL_X, NULL);
     libevdev_enable_event_code(dev, EV_REL, REL_Y, NULL);
     libevdev_enable_event_type(dev, EV_KEY);
     libevdev_enable_event_code(dev, EV_KEY, BTN_LEFT, NULL);
     libevdev_enable_event_type(dev, EV_SYN);
     libevdev_enable_event_code(dev, EV_SYN, SYN_REPORT, NULL);

    int code = libevdev_uinput_create_from_device(dev, LIBEVDEV_UINPUT_OPEN_MANAGED, &uidev);

    if(code != 0)
    {
        perror("failure.\n");
        return -1;
    }

    //2 definte what the mouse is capable of

    srand(time(NULL));
    //activate fake mouse events
    while(1)
    {
        //printf("While loop running?\n");
        
        int amplitude = rand() % 41 - 20; //NUMBERS BETWEEN - 20 AND 20

        int direction = rand() % 2 == 0 ? REL_X : REL_Y;

        printf("While loop running? amp=%d,  dir=%d\n", amplitude, direction);

        libevdev_uinput_write_event(uidev, EV_REL, direction, amplitude);
        libevdev_uinput_write_event(uidev, EV_SYN, SYN_REPORT, 0);

        usleep(50000);
    }
}

