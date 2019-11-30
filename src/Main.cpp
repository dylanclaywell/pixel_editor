#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

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

    if (!al_init_primitives_addon()) {
        cout << "Error, could not initialize Allegro 5 primitives addon\n";
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
   
    cursor.initialize(32);
 
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
                update(event);
                redraw = true;
                break;
            case ALLEGRO_EVENT_KEY_DOWN:
                handleKeyDown(event);
                break;
            case ALLEGRO_EVENT_KEY_UP:
                handleKeyUp(event);
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

void Main::update(ALLEGRO_EVENT event) {
    if (pressedKeys[ALLEGRO_KEY_UP]) {
        cursor.moveUp();
    } else if (pressedKeys[ALLEGRO_KEY_DOWN]) {
        cursor.moveDown();
    }

    if (pressedKeys[ALLEGRO_KEY_LEFT]) {
        cursor.moveLeft();
    } else if (pressedKeys[ALLEGRO_KEY_RIGHT]) {
        cursor.moveRight();
    }
}

void Main::handleKeyDown(ALLEGRO_EVENT event) {
    cout << event.keyboard.keycode << endl;

    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            pressedKeys[ALLEGRO_KEY_UP] = true;
            break;
        case ALLEGRO_KEY_DOWN:
            pressedKeys[ALLEGRO_KEY_DOWN] = true;
            break;
        case ALLEGRO_KEY_LEFT:
            pressedKeys[ALLEGRO_KEY_LEFT] = true;
            break;
        case ALLEGRO_KEY_RIGHT:
            pressedKeys[ALLEGRO_KEY_RIGHT] = true;
            break;
    }
}

void Main::handleKeyUp(ALLEGRO_EVENT event) {
    cout << event.keyboard.keycode << endl;

    switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_UP:
            pressedKeys[ALLEGRO_KEY_UP] = false;
            break;
        case ALLEGRO_KEY_DOWN:
            pressedKeys[ALLEGRO_KEY_DOWN] = false;
            break;
        case ALLEGRO_KEY_LEFT:
            pressedKeys[ALLEGRO_KEY_LEFT] = false;
            break;
        case ALLEGRO_KEY_RIGHT:
            pressedKeys[ALLEGRO_KEY_RIGHT] = false;
            break;
    }
}

void Main::draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    cursor.draw();

    al_flip_display();
}
