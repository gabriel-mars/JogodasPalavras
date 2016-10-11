#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

int casa(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false;
    bool let2 = false;
    bool let3 = false;
    bool let4 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/casa.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone2.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    voz = al_load_sample("Arte/rato.ogg");
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.71, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                    }

                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                    }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                    al_flip_display();
                    let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                    al_flip_display();
                    let4 = true;
                }

            if(let1 && let2 && let3 && let4){
                al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");//Escrevendo a opção no Menu;
                al_flip_display();
            }
            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "BALA");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "SALA");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "CASA");//Escrevendo as dicas;
                  al_flip_display();
            }

            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras(FPS, ALTURA, LARGURA,pers_sel);
            }
        }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
    }
  }

    destruir_palavras(janela, fila_eventos, fonte, pergunta, voz, icone);

    return 0;
}

int rato(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;
    bool let2=  false;
    bool let3 =  false;
    bool let4=  false;
    double tempo_ini = 0,
           tempo_fin = 0;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/rato.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    voz = al_load_sample("Arte/rato.ogg");
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.71, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

            if(let1 && let2 && let3 && let4){
                al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                al_flip_display();
            }

            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){

                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "RATO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "PATO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "GATO");//Escrevendo as dicas;
                  al_flip_display();

                  }

            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras(FPS, ALTURA, LARGURA,pers_sel);
            }
        }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
    }
}
    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int dado(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_SAMPLE * voz = NULL;
    ALLEGRO_SAMPLE * parabens = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false;
    bool let2 = false;
    bool let3 = false;
    bool let4 = false;
    bool sel1 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/dado.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.71, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(let1 && let2 && let3 && let4){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }
                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){

                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "PATO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "DADO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "SAPO");//Escrevendo as dicas;
                  al_flip_display();

                  }

               if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
      }
     }

    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int barco(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false, let2 = false, let3 = false, let4 = false, let5 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/barco.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3 = al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    voz = al_load_sample("Arte/rato.ogg");
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.71, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let5 = true;
                }

            if(let1 && let2 && let3 && let4 && let5){
                al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                al_flip_display();
            }

            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras(FPS, ALTURA, LARGURA,pers_sel);
            }
            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){

                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "DARDO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "BARCO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "PASTO");//Escrevendo as dicas;
                  al_flip_display();

                  }
        }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
    }
   }
    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int sapato(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false, let2 = false, let3 = false, let4 = false, let5 = false, let6 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/sapato.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    voz = al_load_sample("Arte/rato.ogg");
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.71, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        //al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "Clique nas letras do meu nome");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let5 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let6 = true;
                }

                if(let1 && let2 && let3 && let4 && let5 && let6){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

               if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras(FPS, ALTURA, LARGURA,pers_sel);
                }
                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){

                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "SAPATO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "RENATO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "ESCAPO");//Escrevendo as dicas;
                  al_flip_display();

                  }
            }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
    }
   }
    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int escada(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false, let2 = false, let3 = false, let4 = false, let5 = false, let6 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/escada.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    voz = al_load_sample("Arte/rato.ogg");
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.119,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "E");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.71, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        //al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "Clique nas letras do meu nome");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let5 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "S");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "C");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let6 = true;
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                        al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                        al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "SACADA");//Escrevendo as dicas;
                        al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "SALADA");//Escrevendo as dicas;
                        al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "ESCADA");//Escrevendo as dicas;
                        al_flip_display();
                }

                if(let1 && let2 && let3 && let4 && let5 && let6){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

               if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
    }
   }
    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int livro(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false, let2 = false, let3 = false, let4 = false, let5 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/livro.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3 = al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    voz = al_load_sample("Arte/rato.ogg");
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.119,0);// 0.2
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "V");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.71, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "V");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "V");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "V");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "V");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "Q");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "T");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "V");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let5 = true;
                }

            if(let1 && let2 && let3 && let4 && let5){
                al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                al_flip_display();
            }

            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras(FPS, ALTURA, LARGURA, pers_sel);
            }
            if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){

                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "LIVRO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "CADERNO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "BICHO");//Escrevendo as dicas;
                  al_flip_display();

                  }
        }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
    }
   }
    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int abelha(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false, let2 = false, let3 = false, let4 = false, let5 = false, let6 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/abelha.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "H");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "H");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "H");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "H");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "H");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "H");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let5 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "B");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "R");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "H");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let6 = true;
                }

                if(let1 && let2 && let3 && let4 && let5 && let6){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

               if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras(FPS, ALTURA, LARGURA,pers_sel);
                }
                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                        al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                        al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "ORELHA");//Escrevendo as dicas;
                        al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "ABELHA");//Escrevendo as dicas;
                        al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "GROSELHA");//Escrevendo as dicas;
                        al_flip_display();
                  }
            }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
    }
   }
    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int galo(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_SAMPLE * voz = NULL;
    ALLEGRO_SAMPLE * parabens = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false;
    bool let2 = false;
    bool let3 = false;
    bool let4 = false;
    bool sel1 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/galo.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.5 && evento.mouse.x < LARGURA * 0.5 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "U");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "D");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "P");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "O");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "X");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(let1 && let2 && let3 && let4){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

               if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras(FPS, ALTURA, LARGURA,pers_sel);
                }
                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){

                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "GALO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "PATO");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "RATO");//Escrevendo as dicas;
                  al_flip_display();

                  }
            }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
      }
     }

    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}

int janela1(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_SAMPLE * voz = NULL;
    ALLEGRO_SAMPLE * parabens = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false;
    bool let2 = false;
    bool let3 = false;
    bool let4 = false;
    bool let5 = false;
    bool let6 = false;
    bool sel1 = false;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(4); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/janela.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/caixa1.png");
    caixa2 = al_load_bitmap("Arte/caixa2.png");
    caixa3= al_load_bitmap("Arte/caixa3.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(pergunta, LARGURA * 0.4, ALTURA * 0.2,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
    al_draw_bitmap(caixa1, LARGURA * 0.8, ALTURA * 0.7,0);
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NAS LETRAS DO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "J");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "N");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "I");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while (aberto){ //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_F1:
                        al_destroy_display(janela);
                        main();
                    break;
                }
            }

            if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Batalhar
                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "J");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "N");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "J");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "N");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let2 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "J");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "N");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let3 = true;
                }

                if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "J");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "N");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let4 = true;
                }

                if(evento.mouse.x > LARGURA * 0.3 && evento.mouse.x < LARGURA * 0.3 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "J");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "N");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let5 = true;
                }

                if(evento.mouse.x > LARGURA * 0.7 && evento.mouse.x < LARGURA * 0.7 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.7, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.3, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.4, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.5, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.6, ALTURA * 0.7,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.7, ALTURA * 0.7,0);
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.501, 0, "J");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.501, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.501, 0, "F");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.501, 0, "G");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.501, 0, "N");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.31, ALTURA * 0.701, 0, "L");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.41, ALTURA * 0.701, 0, "Y");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.51, ALTURA * 0.701, 0, "I");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.701, 0, "E");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.71, ALTURA * 0.701, 0, "A");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.81, ALTURA * 0.701, 0, "?");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let6 = true;
                }

                if(let1 && let2 && let3 && let4 && let5 && let6){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

               if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras(FPS, ALTURA, LARGURA,pers_sel);
                }
                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(caixa1) &&
                evento.mouse.y > ALTURA * 0.7 && evento.mouse.y < ALTURA * 0.7 + al_get_bitmap_height(caixa1)){

                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.5,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.6,0);
                  al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.7,0);
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA* 0.53, 0, "TABELA");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.63, 0, "PANELA");//Escrevendo as dicas;
                  al_draw_textf(fonte, al_map_rgb(255,255,255),LARGURA * 0.81, ALTURA * 0.73, 0, "JANELA");//Escrevendo as dicas;
                  al_flip_display();

                  }
            }

        tempo_fin = al_get_time() - tempo_ini;

        if(tempo_fin < 1.0 / FPS){
            al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
        }
      }
     }

    destruir_palavras(janela, fila_eventos, fonte,  pergunta, voz, icone);

    return 0;
}
