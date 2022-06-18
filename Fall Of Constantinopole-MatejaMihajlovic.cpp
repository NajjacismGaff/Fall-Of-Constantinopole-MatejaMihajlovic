#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_primitives.h>

int main()
{

    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_BITMAP* carigrad = NULL;
    ALLEGRO_SAMPLE* muzika = NULL;
    ALLEGRO_SAMPLE_INSTANCE* muzika_sample = NULL;


    al_init();
    display = al_create_display(1000, 700);
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60);


    al_install_audio();
    al_init_acodec_addon();

    al_reserve_samples(1);


    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    al_init_image_addon();


    carigrad = al_load_bitmap("KaoCarigrad.jpg");
    assert(carigrad != NULL);

    int width = al_get_display_width(display);


    al_start_timer(timer);

    bool running = true;

    float x = 0;

     muzika = al_load_sample("CeddinDeden.ogg");
     al_play_sample(muzika, 1.0, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

    while (running) {
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            running = false;

        if (event.type == ALLEGRO_EVENT_TIMER){
                
                al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
                al_draw_bitmap(carigrad,0, 0,0);
                al_flip_display();
        }

        if (x > width) x = al_get_bitmap_width(carigrad);

    }



    al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_timer(timer);
    al_destroy_bitmap(carigrad);
    al_uninstall_audio();
    al_destroy_sample(muzika);


    return 0;
}