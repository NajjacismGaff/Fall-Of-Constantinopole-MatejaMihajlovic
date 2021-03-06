#include<iostream>
#include<cstdlib>
#include<ctime>
#include<allegro5/allegro.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_primitives.h>

using namespace std;

int main()
{

    //ovako nesto
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_BITMAP* carigrad = NULL;
    ALLEGRO_BITMAP* CRX = NULL;
    ALLEGRO_BITMAP* uvod = NULL;
    ALLEGRO_BITMAP* turki = NULL;
    ALLEGRO_BITMAP* boom = NULL;

    //napadi/prestupi

    ALLEGRO_BITMAP* otatt = NULL;
    ALLEGRO_BITMAP* byatt = NULL;

    //zvuci
    ALLEGRO_SAMPLE* muzika = NULL;
    ALLEGRO_SAMPLE_INSTANCE* muzika_sample = NULL;

    ALLEGRO_SAMPLE* Bblizu = NULL;
    ALLEGRO_SAMPLE* Bdaleko = NULL;
 


    //slike
    ALLEGRO_BITMAP* carigrad1 = NULL;
    ALLEGRO_BITMAP* ottoman1 = NULL;
    ALLEGRO_BITMAP* carigrad2 = NULL;
    ALLEGRO_BITMAP* ottoman2 = NULL;
    ALLEGRO_BITMAP* carigrad3 = NULL;
    ALLEGRO_BITMAP* ottoman3 = NULL;
    ALLEGRO_BITMAP* ottoman4 = NULL;

    ALLEGRO_BITMAP* carigrad4 = NULL;
    ALLEGRO_BITMAP* ottoman5 = NULL;

    //health

    int c1 = 17, c2 = 32, c3 = 24, c4 = 20;
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;

    int o1 = 23, o2 = 32, o3 = 30, o4 = 20, o5 = 17;
    int ox1 = 0, ox2 = 0, ox3 = 0, ox4 = 0, ox5 = 0;

    int sek = 0;

    int prc = 0;//prc tho

    //deadline

    int deadline = 0;

    al_init();
    display = al_create_display(1000, 700);
    queue = al_create_event_queue();
    timer = al_create_timer(1.0 / 1.0);


    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();


    al_install_audio();
    al_init_acodec_addon();

    al_reserve_samples(99);


    al_install_keyboard();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    
    al_init_image_addon();


    uvod = al_load_bitmap("Uvod.jpg");
    assert(uvod != NULL);

    CRX = al_load_bitmap("VCX.png");
    assert(CRX != NULL);

    turki = al_load_bitmap("download.png");
    assert(turki != NULL);


    carigrad = al_load_bitmap("KaoCarigrad.jpg");
    assert(carigrad != NULL);



    otatt = al_load_bitmap("OtAtt.png");
    assert(otatt != NULL);

    byatt = al_load_bitmap("ByAtt.png");
    assert(byatt != NULL);


    boom = al_load_bitmap("boom.png");
    assert(boom != NULL);


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
     Bblizu = al_load_sample("Blizu_1.ogg");
     Bdaleko = al_load_sample("BDaleko_2.ogg");

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
        
                al_clear_to_color(al_map_rgba_f(1, 1, 1, 1));
                al_draw_bitmap(carigrad,0, 0,0);

                sek = sek + 1;

               if (c1 <= 0) {
                    x1 = 1;
                    al_draw_bitmap(CRX, 120, 300, 0);
               }

                if (c2 <= 0) {
                    x2 = 1;
                    al_draw_bitmap(CRX, 270, 120, 0);
                    
                }

                if (c3 <= 0) {
                    x3 = 1;
                    al_draw_bitmap(CRX, 90, 500, 0);
                    
                }

                if (c4 <= 0) {
                    x4 = 1;
                    al_draw_bitmap(CRX, 600, 220, 0);
                    
               }
                if ((x1+x2+x3+x4) == 4) {
                    al_draw_bitmap(turki,0,0,0);

                    for (int i = 0; i <= 9999999999999999;i++)printf("turki win!!!");
                   
                }

                if (deadline > 2200)
                {
                    x1 = 0;
                    x2 = 0;
                    x3 = 0;
                    x4 = 0;

                    c1 = 17;
                    c2 = 32;
                    c3 = 24;
                    c4 = 20;

                    ox1 = 0;
                    ox2 = 0;
                    ox3 = 0;
                    ox4 = 0;
                    ox5 = 0;

                    o1 = 23; 
                    o2 = 32;
                    o3 = 30;
                    o4 = 20;
                    o5 = 17;
                    deadline = 0;

                }



                if (o1 <= 0)ox1 = 1;
                if (o2 <= 0)ox2 = 1;
                if (o3 <= 0)ox3 = 1;
                if (o4 <= 0)ox4 = 1;
                if (o5 <= 0)ox5 = 1;
                if ((o1+o2+o3+o4+o5)==5)al_destroy_display(display);

                prc += 2;
                if (prc >= 30)prc = 0;

                srand((int)time(0));
                int i = 0,prk;
                while (i++ < 10) {
                    
                    int attackBroj;
                    attackBroj = (rand() % 99) + 1;
                    cout << attackBroj << " ";
                    prk = attackBroj;
                }
                
                printf("\t%d\t%d-%d-%d-%d\t+%d\tdeadline = %d", prk,c1,c2,c3,c4,sek,deadline);
                printf("\n");

                if (o1>=1)al_draw_bitmap(ottoman1, 6, 300, 0);
                if (c1 >= 1)al_draw_bitmap(carigrad1, 120, 300, 0);

                if (o2 >= 1)al_draw_bitmap(ottoman2, 160, 40, 0);
                if (c2 >= 1)al_draw_bitmap(carigrad2, 270, 120, 0);

                if (o3 >= 1)al_draw_bitmap(ottoman3, -15, 500, 0);
                if (c3 >= 1)al_draw_bitmap(carigrad3, 90, 500, 0);

                if (o4 >= 1)al_draw_bitmap(ottoman4, 90, 160, 0);
                

                if (o5 >= 1)al_draw_bitmap(ottoman5, 600, 100, 0);
                if (c4 >= 1)al_draw_bitmap(carigrad4, 600, 220, 0);

                if (sek > 60)sek = 0;

                if (sek > 30)
                {
                    al_draw_bitmap(byatt, 750, 600, 0);

                    if(prk%11==0&&o1>=1)
                    {
                        o1 = o1 - 2;
                        al_draw_bitmap(boom, 6, 300, 0);

                    }
                    if (prk % 21==0&&o2>=1)
                    {
                        o2 = o2 - 2;
                        al_draw_bitmap(boom, 160, 40, 0);
                    }
                    if (prk % 27==0&&o3>=1)
                    {
                        o3 = o3 - 2;
                        al_draw_bitmap(boom, -15, 500, 0);
                    }
                    if (prk % 19==0&&o4>=1)
                    {
                        o4 = o4 - 2;
                        al_draw_bitmap(boom, 90, 160, 0);
                    }
                    if (prk % 32==0&&o5!=1)
                    {
                        o5 = o5 - 2;
                        al_draw_bitmap(boom, 600, 100, 0);
                    }


                }



                if(sek<=30)al_draw_bitmap(otatt, 750, 600, 0);if (event.type == ALLEGRO_EVENT_KEY_UP)
                {

                    

                    if(prk % 11==0&&c1>=1)
                    {
                        printf("fddfsdfsdfsdfsdfsdfsdfsdfdfs");
                        al_play_sample(Bblizu, 1.0, 0, 1,ALLEGRO_PLAYMODE_ONCE, NULL);
                        c1 = c1 - 2;
                        al_draw_bitmap(boom, 120, 300, 0);
                    }
                    if (prk % 21==0&&c2>=1)
                    {
                        printf("fddfsdfsdfsdfsdfsdfsdfsdfdfs");
                        al_play_sample(Bdaleko, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        c2 = c2 - 2;
                        al_draw_bitmap(boom, 270, 120, 0);
                    }
                    if (prk % 27 == 0&&c3>=1)
                    {
                        printf("fddfsdfsdfsdfsdfsdfsdfsdfdfs");
                        al_play_sample(Bblizu, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        c3 = c3 - 2;
                        al_draw_bitmap(boom, 90, 500, 0);
                    }
                    if (prk % 19 == 0&&c4>=1)
                    {
                        printf("fddfsdfsdfsdfsdfsdfsdfsdfdfs");
                        al_play_sample(Bdaleko, 1.0, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        c4 = c4 - 2;
                        al_draw_bitmap(boom, 600, 220, 0);
                    }
                }
                

                //if (xx == 4)al_destroy_display(display);

                al_flip_display();
        

        if (x > width) x = al_get_bitmap_width(carigrad);
        //deadline++;

    }

    //al_destroy_display(display);
    al_uninstall_keyboard();
    al_destroy_timer(timer);
    al_destroy_bitmap(carigrad);
    al_uninstall_audio();
    al_destroy_sample(muzika);


    return 0;
}
//Rad Mateje Mihajlovicha 1-4 Gimnazija Chuprija 2022 6/18,7/18 i neki dani pre toga najjache :))))))))))))))