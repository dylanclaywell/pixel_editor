#include <iostream>
#include <allegro5/allegro.h>

using namespace std;

const float FPS = 60.0;

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

    bool redraw = true;
    bool quit = false;

    if (!al_init()) {
        cout << "Error, could not initialize Allegro 5.\n";
        return 1;
    }

    timer = al_create_timer(1.0 / FPS);

    if (!timer) {
        cout << "Error, could not create timer.\n";
        return 1;
    }

    display = al_create_display(640, 480);

    if (!display) {
        cout << "Error, could not create display\n";
        return 1;
    }

    event_queue = al_create_event_queue();

    if (!event_queue) {
        cout << "Error, could not create event queue\n";
        return 1;
    }

    al_install_keyboard();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    al_start_timer(timer);

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
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_flip_display();
            redraw = false;
        }
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

    return 0;
}
