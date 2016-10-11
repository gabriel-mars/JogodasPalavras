//Inclusão de bibliotecas padrão
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>

int personagens(int FPS, int ALTURA, int LARGURA){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_BITMAP * pers1 = NULL;
    ALLEGRO_BITMAP * pers2 = NULL;
    ALLEGRO_BITMAP * pers3 = NULL;
    ALLEGRO_BITMAP * pers4 = NULL;
    ALLEGRO_BITMAP * play = NULL;
    ALLEGRO_BITMAP * play_sel= NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_AUDIO_STREAM * voz1 = NULL;
    ALLEGRO_AUDIO_STREAM * voz2 = NULL;
    ALLEGRO_AUDIO_STREAM * voz3 = NULL;

    //Declaração de variáveis
    bool aberto = true;
    bool sel1 = false;
    double tempo_ini = 0,
           tempo_fin = 0;
    int * pers_selPtr;
    int pers_sel;
    int opcao = 0;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    //Criação do display e seus elementos gráficos
    janela = al_create_display(LARGURA, ALTURA);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos
    pers1 = al_load_bitmap("Arte/Pai.png");
    pers2 = al_load_bitmap("Arte/Pers2.png");
    pers3 = al_load_bitmap("Arte/Pers3.png");
    pers4 = al_load_bitmap("Arte/Pers4.png");
    play = al_load_bitmap("Arte/barrinha.png");
    play_sel = al_load_bitmap("Arte/barrinha_sel.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    icone = al_load_bitmap("Arte/icone.png");
    voz1 = al_load_sample("Narrador/voltar_menu.ogg");
    voz2 = al_load_sample("Narrador/avancar.ogg");
    voz3 = al_load_sample("Narrador/personagem.ogg");

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_draw_bitmap(fundo, 0, 0, 0);

    //Primeiro desenho da página
    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(play, LARGURA * 0.05, ALTURA * 0.76, 0);
    al_draw_bitmap(pers1, LARGURA * 0.05, ALTURA * 0.36, 0);
    al_draw_bitmap(pers2, LARGURA * 0.30, ALTURA * 0.36, 0);
    al_draw_bitmap(pers3, LARGURA * 0.55, ALTURA * 0.36, 0);
    al_draw_bitmap(pers4, LARGURA * 0.80, ALTURA * 0.36, 0);

    //Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.08, ALTURA * 0.775, 0, "MENU");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.345, ALTURA * 0.2, 0, "ESCOLHA SEU PERSONAGEM:");
    al_play_sample(voz3,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_flip_display();

    al_set_window_title(janela, "Jogo das Palavras");

    while(aberto){  //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        verifica = 1;

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;

            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.y > ALTURA* 0.76 && evento.mouse.y < ALTURA * 0.76 + al_get_bitmap_height(play)){
                    if(evento.mouse.x > LARGURA * 0.05 && evento.mouse.x < LARGURA * 0.05 + al_get_bitmap_width(play)){
                        sel1 = true;
                    }else{
                        sel1 = false;
                    }

                }else{
                    sel1 = false;
                    opcao = 0;
                }

                if(sel1){
                    al_draw_bitmap(play_sel, LARGURA * 0.05, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.08, ALTURA * 0.775, 0, "MENU");

                    if(opcao != 1){
                        al_play_sample(voz1,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        opcao = 1;
                    }
                }
                else{
                    al_draw_bitmap(play, LARGURA * 0.05, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.08, ALTURA * 0.775, 0, "MENU");

                }
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                //Alterando as páginas com clique
                if(evento.mouse.x >= LARGURA * 0.05 && evento.mouse.x <= LARGURA * 0.05 + al_get_bitmap_width(play) &&
                    evento.mouse.y >= ALTURA * 0.76 && evento.mouse.y <= ALTURA * 0.76 + al_get_bitmap_height(play)){
                    destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                    main();
                }if(evento.mouse.x >= LARGURA * 0.05 && evento.mouse.x <= LARGURA * 0.05 + al_get_bitmap_width(pers1) &&
                    evento.mouse.y >= ALTURA * 0.36 && evento.mouse.y <= ALTURA * 0.36 + al_get_bitmap_height(pers1)){
                    destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                    pers_sel  = pers1;
                    teste(FPS, ALTURA, LARGURA, pers_sel);
                }
                if(evento.mouse.x >= LARGURA * 0.3 && evento.mouse.x <= LARGURA * 0.3 + al_get_bitmap_width(pers1) &&
                    evento.mouse.y >= ALTURA * 0.36 && evento.mouse.y <= ALTURA * 0.36 + al_get_bitmap_height(pers1)){
                    destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                    pers_sel  = pers2;
                    teste(FPS, ALTURA, LARGURA, pers_sel);
                }
                if(evento.mouse.x >= LARGURA * 0.55 && evento.mouse.x <= LARGURA * 0.55 + al_get_bitmap_width(pers1) &&
                    evento.mouse.y >= ALTURA * 0.36 && evento.mouse.y <= ALTURA * 0.36 + al_get_bitmap_height(pers1)){
                    destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                    pers_sel  = pers3;
                    teste(FPS, ALTURA, LARGURA, pers_sel);
                }
                if(evento.mouse.x >= LARGURA * 0.80 && evento.mouse.x <= LARGURA * 0.80 + al_get_bitmap_width(pers1) &&
                    evento.mouse.y >= ALTURA * 0.36 && evento.mouse.y <= ALTURA * 0.36 + al_get_bitmap_height(pers1)){
                    destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                    pers_sel  = pers4;
                    teste(FPS, ALTURA, LARGURA, pers_sel);
                }
            }
        }

        al_flip_display();
    }

    tempo_fin = al_get_time() - tempo_ini;

    if(tempo_fin < 1.0 / FPS){
        al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
    }

    int destruir_personagens(janela, fila_eventos, pers1, pers2, pers3, play, play_sel, fundo, fonte, icone, voz1, voz2);

    return 0;
}
