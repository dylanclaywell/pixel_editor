#include <allegro5/allegro.h>

#include "Canvas.h"

Canvas::Canvas() {
}

Canvas::~Canvas() {
    al_destroy_bitmap(canvas);
}

void Canvas::initialize(int w, int h, ALLEGRO_DISPLAY *d) {
    width = w;
    height = h;
    display = d;
    x = 0;
    y = 0;
    zoom = 3;

    canvas = al_create_bitmap(w, h);
    
    al_set_target_bitmap(canvas);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_set_target_bitmap(al_get_backbuffer(display));
}

void Canvas::draw() {
    al_draw_scaled_bitmap(
        canvas,
        x,
        y,
        width,
        height,
        x,
        y,
        width * zoom,
        height * zoom,
        0
    );
}

int Canvas::getWidth() {
    return width;
}

int Canvas::getHeight() {
    return height;
}

ALLEGRO_BITMAP *Canvas::getSurface() {
    return canvas;
}
