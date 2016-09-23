#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

int letras(int FPS, int ALTURA, int LARGURA, int pers_sel){
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
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    icone = al_load_bitmap("Arte/icone.png");
    play = al_load_bitmap("Arte/caixa4.png");
    play_sel = al_load_bitmap("Arte/caixa2.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
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

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.21, ALTURA * 0.38, 0, "A");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.36, ALTURA * 0.38, 0, "B");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.38, 0, "C");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.66, ALTURA * 0.38, 0, "L");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.38, 0, "J");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.21, ALTURA * 0.58, 0, "G");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.36, ALTURA * 0.58, 0, "S");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.58, 0, "E");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.66, ALTURA * 0.58, 0, "R");
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.58, 0, "D");

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
                if(evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(play)){
                    if(evento.mouse.x > LARGURA * 0.20 && evento.mouse.x < LARGURA * 0.20 + al_get_bitmap_width(play)){
                        sel1 = true;
                    }else{
                        sel1 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.35 && evento.mouse.x < LARGURA * 0.35 + al_get_bitmap_width(play)){
                        sel2 = true;
                    }else{
                        sel2 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.50 && evento.mouse.x < LARGURA * 0.50 + al_get_bitmap_width(play)){
                        sel3 = true;
                    }else{
                        sel3 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(play)){
                        sel4 = true;
                    }else{
                        sel4 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.80 && evento.mouse.x < LARGURA * 0.80 + al_get_bitmap_width(play)){
                        sel5 = true;
                    }else{
                        sel5 = false;
                    }
                }else if(evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play)){
                    if(evento.mouse.x > LARGURA * 0.20 && evento.mouse.x < LARGURA * 0.20 + al_get_bitmap_width(play)){
                        sel6 = true;
                    }else{
                        sel6 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.35 && evento.mouse.x < LARGURA * 0.35 + al_get_bitmap_width(play)){
                        sel7 = true;
                    }else{
                        sel7 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.50 && evento.mouse.x < LARGURA * 0.50 + al_get_bitmap_width(play)){
                        sel8 = true;
                    }else{
                        sel8 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(play)){
                        sel9 = true;
                    }else{
                        sel9 = false;
                    }

                    if(evento.mouse.x > LARGURA * 0.80 && evento.mouse.x < LARGURA * 0.80 + al_get_bitmap_width(play)){
                        sel10 = true;
                    }else{
                        sel10 = false;
                    }
                }else{
                    sel1 = false;
                    sel2 = false;
                    sel3 = false;
                    sel4 = false;
                    sel5 = false;
                    sel6 = false;
                    sel7 = false;
                    sel8 = false;
                    sel9 = false;
                    sel10 = false;
                }

                if(sel1){
                    al_draw_bitmap(play_sel, LARGURA * 0.20, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.21, ALTURA * 0.38, 0, "A");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.20, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.21, ALTURA * 0.38, 0, "A");
                }
                if(sel2){
                    al_draw_bitmap(play_sel, LARGURA * 0.35, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.36, ALTURA * 0.38, 0, "B");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.35, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.36, ALTURA * 0.38, 0, "B");
                }
                if(sel3){
                    al_draw_bitmap(play_sel, LARGURA * 0.50, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.51, ALTURA * 0.38, 0, "C");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.50, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.38, 0, "C");
                }
                if(sel4){
                    al_draw_bitmap(play_sel, LARGURA * 0.65, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.66, ALTURA * 0.38, 0, "L");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.65, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.66, ALTURA * 0.38, 0, "L");
                }
                if(sel5){
                    al_draw_bitmap(play_sel, LARGURA * 0.80, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.81, ALTURA * 0.38, 0, "J");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.80, ALTURA * 0.36, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.38, 0, "J");
                }
                if(sel6){
                    al_draw_bitmap(play_sel, LARGURA * 0.20, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.21, ALTURA * 0.58, 0, "G");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.20, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.21, ALTURA * 0.58, 0, "G");
                }
                if(sel7){
                    al_draw_bitmap(play_sel, LARGURA * 0.35, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.36, ALTURA * 0.58, 0, "S");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.35, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.36, ALTURA * 0.58, 0, "S");
                }
                if(sel8){
                    al_draw_bitmap(play_sel, LARGURA * 0.50, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.51, ALTURA * 0.58, 0, "E");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.50, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.58, 0, "E");
                }
                if(sel9){
                    al_draw_bitmap(play_sel, LARGURA * 0.65, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.66, ALTURA * 0.58, 0, "R");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.65, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.66, ALTURA * 0.58, 0, "R");
                }
                if(sel10){
                    al_draw_bitmap(play_sel, LARGURA * 0.80, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(0, 0, 0), LARGURA * 0.81, ALTURA * 0.58, 0, "D");
                }else{
                    al_draw_bitmap(play, LARGURA * 0.80, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.58, 0, "D");
                }
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.20 && evento.mouse.x < LARGURA * 0.20 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    abelha(FPS, ALTURA, LARGURA, pers_sel);
                }

                if(evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(play) &&
                 evento.mouse.x > LARGURA * 0.35 && evento.mouse.x < LARGURA * 0.35 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    barco(FPS, ALTURA, LARGURA, pers_sel);
                 }

                if(evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(play) &&
                 evento.mouse.x > LARGURA * 0.50 && evento.mouse.x < LARGURA * 0.50 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    casa(FPS, ALTURA, LARGURA, pers_sel);
                 }

                if(evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    livro(FPS, ALTURA, LARGURA, pers_sel);
                }

                if(evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.80 && evento.mouse.x < LARGURA * 0.80 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    juiz(FPS, ALTURA, LARGURA, pers_sel);
                }

                if(evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    rato(FPS, ALTURA, LARGURA, pers_sel);
                }

                if(evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.80 && evento.mouse.x < LARGURA * 0.80 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    dado(FPS, ALTURA, LARGURA, pers_sel);
                }

                if(evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.35 && evento.mouse.x < LARGURA * 0.35 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    sapato(FPS, ALTURA, LARGURA, pers_sel);
                }

                if(evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.50 && evento.mouse.x < LARGURA * 0.50 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    escada(FPS, ALTURA, LARGURA, pers_sel);
                }

                if(evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play) &&
                evento.mouse.x > LARGURA * 0.20 && evento.mouse.x < LARGURA * 0.20 + al_get_bitmap_width(play)){
                    al_destroy_display(janela);
                    galo(FPS, ALTURA, LARGURA, pers_sel);
                }
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
