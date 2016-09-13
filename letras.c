#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

int letras(int FPS, int ALTURA, int LARGURA){
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * play = NULL;
    ALLEGRO_BITMAP * play_sel= NULL;
    ALLEGRO_FONT * fonte = NULL;

    bool aberto = true;
    bool sel1 = false,
        sel2 = false,
        sel3 = false,
        sel4 = false,
        sel5 = false,
        sel6 = false,
        sel7 = false,
        sel8 = false,
        sel9 = false,
        sel10 = false;
    double tempo_ini = 0,
           tempo_fin = 0;

    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    janela = al_create_display(LARGURA, ALTURA);
    fila_eventos = al_create_event_queue();
    fundo = al_load_bitmap("Arte/quadro.png");
    icone = al_load_bitmap("Arte/icone.png");
    play = al_load_bitmap("Arte/caixa1.png");
    play_sel = al_load_bitmap("Arte/caixa2.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(play, LARGURA * 0.20, ALTURA * 0.36, 0);
    al_draw_bitmap(play, LARGURA * 0.35, ALTURA * 0.36, 0);
    al_draw_bitmap(play, LARGURA * 0.50, ALTURA * 0.36, 0);
    al_draw_bitmap(play, LARGURA * 0.65, ALTURA * 0.36, 0);
    al_draw_bitmap(play, LARGURA * 0.80, ALTURA * 0.36, 0);
    al_draw_bitmap(play, LARGURA * 0.20, ALTURA * 0.56, 0);
    al_draw_bitmap(play, LARGURA * 0.35, ALTURA * 0.56, 0);
    al_draw_bitmap(play, LARGURA * 0.50, ALTURA * 0.56, 0);
    al_draw_bitmap(play, LARGURA * 0.65, ALTURA * 0.56, 0);
    al_draw_bitmap(play, LARGURA * 0.80, ALTURA * 0.56, 0);

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while(aberto){
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;

            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){

            }else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){

            }
        }

        al_flip_display();
    }

    tempo_fin = al_get_time() - tempo_ini;

    if(tempo_fin < 1.0 / FPS){
        al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
    }

    destruir_letras(janela, fila_eventos, fundo, icone, play, play_sel, fonte);

    return 0;
}
