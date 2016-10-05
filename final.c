//Inclus�o de bibliotecas padr�o
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <locale.h>


int fim(int FPS, int ALTURA, int LARGURA, int pers_sel){
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_BITMAP * play = NULL;
    ALLEGRO_BITMAP * play_sel= NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * obrigado = NULL;
    ALLEGRO_FONT * fonte = NULL;

    bool aberto = true;
    bool sel1 = false;
    double tempo_ini = 0,
           tempo_fin = 0;

    //Inicializa��o das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instala��o do audio
    al_init_font_addon(); //Instala��o das fontes
    al_init_ttf_addon();
    setlocale(LC_ALL, ""); // Configurando caracteres especiais e acentua��o


    //Cria��o do display e seus elementos gr�ficos
    janela = al_create_display(LARGURA, ALTURA);
    fila_eventos = al_create_event_queue(); //Cria��o da fila de eventos
    play = al_load_bitmap("Arte/barrinha.png");
    play_sel = al_load_bitmap("Arte/barrinha_sel.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    icone = al_load_bitmap("Arte/icone.png");
    obrigado = al_load_bitmap("Arte/Obrigado.png");

     //Adi��o do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    //Primeiro desenho da p�gina
    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(play, LARGURA * 0.6, ALTURA * 0.76, 0);
    al_draw_bitmap(obrigado, LARGURA * 0.28, ALTURA * 0.1, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.61, ALTURA * 0.78, 0, "SAIR");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.3, ALTURA * 0.4, 0, "AGRADECEMOS POR JOGAR O NOSSO JOGO!");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.3, ALTURA * 0.5, 0, "ESPERAMOS QUE TENHAM GOSTADO.");

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
                if(evento.mouse.y > ALTURA* 0.76 && evento.mouse.y < ALTURA * 0.76 + al_get_bitmap_height(play)){
                    if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(play)){
                        sel1 = true;
                    }else{
                        sel1 = false;
                    }
                }else{
                    sel1 = false;
                }

                if(sel1){
                    al_draw_bitmap(play_sel, LARGURA * 0.6, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.78, 0, "SAIR");//Escrevendo a op��o no Menu;
                }else{
                    al_draw_bitmap(play, LARGURA * 0.6, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.78, 0, "SAIR");//Escrevendo a op��o no Menu;
                }
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA * 0.6 && evento.mouse.x <= LARGURA * 0.6 + al_get_bitmap_width(play) &&
                    evento.mouse.y >= ALTURA * 0.76 && evento.mouse.y <= ALTURA * 0.76 + al_get_bitmap_height(play)){
                    exit(0);
                }
            }
        }
        al_flip_display();
    }

    tempo_fin = al_get_time() - tempo_ini;

    if(tempo_fin < 1.0 / FPS){
        al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
    }

    destruir_fim(janela, fila_eventos, play, play_sel, fundo, fonte, icone, obrigado);

    return 0;
}
