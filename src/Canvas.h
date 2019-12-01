#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <allegro5/allegro.h>

class Canvas {
    private:
        int width, height, zoom, x, y;
        ALLEGRO_BITMAP *canvas;
        ALLEGRO_DISPLAY *display;

    public:
        Canvas();
        ~Canvas();

        void initialize(int, int, ALLEGRO_DISPLAY *);
        void draw();

        // Accessors
        int getWidth();
        int getHeight();
        ALLEGRO_BITMAP *getSurface();
};

#endif
