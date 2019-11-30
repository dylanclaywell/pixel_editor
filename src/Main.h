#ifndef _MAIN_H_
#define _MAIN_H_

#include <allegro5/allegro.h>

class Main {
    private:
        ALLEGRO_DISPLAY *display;
        ALLEGRO_TIMER *timer;
        ALLEGRO_EVENT_QUEUE *event_queue;

        bool redraw;
        bool quit;
        const float FPS = 60.0;

    public:
        Main();
        ~Main();

        bool initialize(int, int);
        void run();
        void update();
        void draw();
};

#endif
