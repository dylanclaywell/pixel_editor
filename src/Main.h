#ifndef _MAIN_H_
#define _MAIN_H_

#include <allegro5/allegro.h>

#include "Cursor.h"
#include "Canvas.h"

class Main {
    private:
        ALLEGRO_DISPLAY *display;
        ALLEGRO_TIMER *timer;
        ALLEGRO_EVENT_QUEUE *event_queue;

        Cursor cursor;
        Canvas canvas;

        bool redraw;
        bool quit;
        const float FPS = 60.0;
        bool pressedKeys[ALLEGRO_KEY_MAX] = {false};

    public:
        Main();
        ~Main();

        bool initialize(int, int);
        void run();
        void update(ALLEGRO_EVENT);
        void handleKeyDown(ALLEGRO_EVENT);
        void handleKeyUp(ALLEGRO_EVENT);
        void draw();
};

#endif
