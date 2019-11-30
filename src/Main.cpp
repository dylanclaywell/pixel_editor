#include <iostream>
#include <allegro5/allegro.h>

#include "Main.h"

using namespace std;

Main::Main() {
}

Main::~Main() {
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
}

bool Main::initialize(int width, int height) {
    if (!al_init()) {
        cout << "Error, could not initialize Allegro 5\n";
        return false;
    }

    timer = al_create_timer(1.0 / FPS);

    if (!timer) {
        cout << "Error, could not create timer.\n";
        return false;
    }

    display = al_create_display(640, 480);

    if (!display) {
        cout << "Error, could not create display\n";
        return false;
    }

    event_queue = al_create_event_queue();

    if (!event_queue) {
        cout << "Error, could not create event queue\n";
        return false;
    }

    al_install_keyboard();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    redraw = true;
    quit = false;
    
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    al_start_timer(timer);

    return true;
}

void Main::run() {
    while (!quit) {
        ALLEGRO_EVENT event;
        
        al_wait_for_event(event_queue, &event);

        switch(event.type) {
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                quit = true;
                break;
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            draw();
            redraw = false;
        }
    }
}

void Main::update() {
}

void Main::draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));



    al_flip_display();
}
