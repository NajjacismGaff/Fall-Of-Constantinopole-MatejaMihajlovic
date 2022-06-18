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
    ALLEGRO_BITMAP* uvod = NULL;

    ALLEGRO_SAMPLE* muzika = NULL;
    ALLEGRO_SAMPLE_INSTANCE* muzika_sample = NULL;

    ALLEGRO_BITMAP* carigrad1 = NULL;
    ALLEGRO_BITMAP* ottoman1 = NULL;
    ALLEGRO_BITMAP* carigrad2 = NULL;
    ALLEGRO_BITMAP* ottoman2 = NULL;
    ALLEGRO_BITMAP* carigrad3 = NULL;
    ALLEGRO_BITMAP* ottoman3 = NULL;
    ALLEGRO_BITMAP* ottoman4 = NULL;

    ALLEGRO_BITMAP* carigrad4 = NULL;
    ALLEGRO_BITMAP* ottoman5 = NULL;



    al_init();
    display = al_create_display(1000, 700);
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 60);


    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();


    al_install_audio();
    al_init_acodec_addon();

    al_reserve_samples(1);


    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    al_init_image_addon();


    uvod = al_load_bitmap("Uvod.jpg");
    assert(uvod != NULL);


    carigrad = al_load_bitmap("KaoCarigrad.jpg");
    assert(carigrad != NULL);



    carigrad1 = al_load_bitmap("CARIGRAD1.png");
    assert(carigrad1 != NULL);
    carigrad2 = al_load_bitmap("CARIGRAD1.png");
    assert(carigrad2 != NULL);
    carigrad3 = al_load_bitmap("CARIGRAD1.png");
    assert(carigrad3 != NULL);
    carigrad4 = al_load_bitmap("CARIGRAD1.png");
    assert(carigrad4 != NULL);

    ottoman1 = al_load_bitmap("OTTOMAN1.png");
    assert(ottoman1 != NULL);
    ottoman2 = al_load_bitmap("OTTOMAN1.png");
    assert(ottoman2 != NULL);
    ottoman3 = al_load_bitmap("OTTOMAN1.png");
    assert(ottoman3 != NULL);
    ottoman4 = al_load_bitmap("OTTOMAN1.png");
    assert(ottoman4 != NULL);
    ottoman5 = al_load_bitmap("OTTOMAN1.png");
    assert(ottoman5 != NULL);



    int width = al_get_display_width(display);

    al_start_timer(timer);

    bool running = true;

    float x = 0;

     muzika = al_load_sample("CeddinDeden.ogg");
     al_play_sample(muzika, 1.0, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

     while (running) {
         al_flip_display();

         al_draw_bitmap(uvod, 0, 0, 0);

         ALLEGRO_EVENT event;
         al_wait_for_event(queue, &event);

     
         if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
             goto kraj_uvoda;
        // else
             //goto prt;

     }

     kraj_uvoda:

    while (running) {
        al_flip_display();

        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);
        //if (event.type == ALLEGRO_EVENT_KEY_UP || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            //running = false;

        if (event.type == ALLEGRO_EVENT_TIMER){
                
                al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
                al_draw_bitmap(carigrad,0, 0,0);

                printf("aaaaa/t");

                al_draw_bitmap(ottoman1, 6, 300, 0);
                al_draw_bitmap(carigrad1, 120, 300, 0);

                al_draw_bitmap(ottoman2, 160, 40, 0);
                al_draw_bitmap(carigrad2, 270, 120, 0);

                al_draw_bitmap(ottoman3, -15, 500, 0);
                al_draw_bitmap(carigrad3, 90, 500, 0);

                al_draw_bitmap(ottoman4, 90, 160, 0);
                


                al_draw_bitmap(ottoman5, 600, 100, 0);
                al_draw_bitmap(carigrad4, 600, 220, 0);


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