//Inclusão de bibliotecas padrão
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>

int teste(int FPS,int ALTURA,int LARGURA, int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_BITMAP * play = NULL;
    ALLEGRO_BITMAP * play_sel= NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_AUDIO_STREAM * voz1 = NULL;
    ALLEGRO_AUDIO_STREAM * voz2 = NULL;
    ALLEGRO_AUDIO_STREAM * voz3 = NULL;


    //Declaração de variáveis
    bool aberto = true;
    bool sel1 = false,
         sel2 = false,
         sel3 = false;
    double tempo_ini = 0,
           tempo_fin = 0;
    int opcao = 0;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    //Criação do display e seus elementos gráficos
    janela = al_create_display(LARGURA, ALTURA);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos
    play = al_load_bitmap("Arte/barrinha.png");
    play_sel = al_load_bitmap("Arte/barrinha_sel.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    icone = al_load_bitmap("Arte/icone2.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    voz1 = al_load_sample("Narrador/letras.ogg");
    voz2 = al_load_sample("Narrador/imagens.ogg");
    voz3 = al_load_sample("Narrador/palavras.ogg");

    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    //Primeiro desenho da página
    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);
    al_draw_bitmap(play, LARGURA * 0.42, ALTURA * 0.25, 0);
    al_draw_bitmap(play, LARGURA * 0.42, ALTURA * 0.5, 0);
    al_draw_bitmap(play, LARGURA * 0.42, ALTURA * 0.75, 0);

    //Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.25, ALTURA * 0.15, 0, "COMBINE  AS  LETRAS  DE  ACORDO  COM  A  FIGURA.");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.443, ALTURA * 0.265, 0, "LETRAS");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.25, ALTURA * 0.4, 0, "SELECIONE  A  IMAGEM  DE  ACORDO  COM  A  PALAVRA.");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.435, ALTURA * 0.515, 0, "IMAGENS");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.25, ALTURA * 0.65, 0, "SELECIONE  A  PALAVRA  DE  ACORDO  COM  A  FIGURA.");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.43, ALTURA * 0.765, 0, "PALAVRAS");

    al_flip_display();

    //Título da Janela
    al_set_window_title(janela, "Jogo das Palavras");

    while(aberto){  //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;

            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){ //Trocas de página de acordo com a tecla pressionada
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_3:
                        main();
                    break;
                    case ALLEGRO_KEY_4:
                        personagens(FPS, ALTURA, LARGURA);
                    break;
                    case ALLEGRO_KEY_5:
                        personagens(FPS, ALTURA, LARGURA);
                    break;
                    case ALLEGRO_KEY_ESCAPE:
                        fechaJanela(janela);
                    break;
                }
                //Movimento do Mouse Para Narração
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x > LARGURA * 0.42 && evento.mouse.x < LARGURA * 0.42 + al_get_bitmap_width(play)){
                    if(evento.mouse.y > ALTURA * 0.25 && evento.mouse.y < ALTURA * 0.25 + al_get_bitmap_height(play)){
                        sel1 = true;
                    }else{
                        sel1 = false;
                    }
                    if(evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(play)){
                        sel2 = true;
                    }else{
                        sel2 = false;
                    }

                    if(evento.mouse.y > ALTURA * 0.75 && evento.mouse.y < ALTURA * 0.75 + al_get_bitmap_height(play)){
                        sel3 = true;
                    }else{
                        sel3 = false;
                    }
                }else{
                    sel1 = false;
                    sel2 = false;
                    sel3 = false;
                    opcao = 0;
                }

                if(sel1){
                    al_draw_bitmap(play_sel, LARGURA * 0.42, ALTURA * 0.25, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.443, ALTURA * 0.265, 0, "LETRAS");//Escrevendo a opção no Menu;

                 /*   if(opcao != 1){
                        opcao = 1;
                    }*/
                    opcao = 1;
                }else{
                    al_draw_bitmap(play, LARGURA * 0.42, ALTURA * 0.25, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.443, ALTURA * 0.265, 0, "LETRAS");//Escrevendo a opção no Menu;
                }

                if(sel2){
                    al_draw_bitmap(play_sel, LARGURA * 0.42, ALTURA * 0.5, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.435, ALTURA * 0.515, 0, "IMAGENS");//Escrevendo a opção no Menu;

                    /*if(opcao != 2){
                        al_play_sample(voz2,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        opcao = 2;
                    }*/
                    opcao = 2;
                }else{
                    al_draw_bitmap(play, LARGURA * 0.42, ALTURA * 0.5, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.435, ALTURA * 0.515, 0, "IMAGENS");//Escrevendo a opção no Menu;
                }

                if(sel3){
                    al_draw_bitmap(play_sel, LARGURA * 0.42, ALTURA * 0.75, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.43, ALTURA * 0.765, 0, "PALAVRAS");//Escrevendo a opção no Menu;

                    /*if(opcao != 2){
                        al_play_sample(voz3,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        opcao = 2;
                    }*/
                    opcao = 3;
                }else{
                    al_draw_bitmap(play, LARGURA * 0.42, ALTURA * 0.75, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.43, ALTURA * 0.765, 0, "PALAVRAS");//Escrevendo a opção no Menu;
                }if (opcao == 1){

                    al_play_sample(voz1,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                     }else if(opcao == 2){

                        al_play_sample(voz2,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                    }else if(opcao == 3){

                        al_play_sample(voz3,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

                    }

                }else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    //Alterando as páginas com clique
                    if(evento.mouse.x >= LARGURA * 0.42 && evento.mouse.x <= LARGURA * 0.42 + al_get_bitmap_width(play) &&
                        evento.mouse.y >= ALTURA * 0.25 && evento.mouse.y <= ALTURA * 0.25 + al_get_bitmap_height(play)){
                        al_destroy_sample(voz1);
                        al_destroy_sample(voz2);
                        al_destroy_sample(voz3);
                        destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                        letras(FPS, ALTURA, LARGURA, pers_sel);
                    }
                    if(evento.mouse.x >= LARGURA * 0.42 && evento.mouse.x <= LARGURA * 0.42 + al_get_bitmap_width(play) &&
                        evento.mouse.y >= ALTURA * 0.5 && evento.mouse.y <= ALTURA * 0.5 + al_get_bitmap_height(play)){
                        al_destroy_sample(voz1);
                        al_destroy_sample(voz2);
                        al_destroy_sample(voz3);
                        destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                        letras2(FPS, ALTURA, LARGURA, pers_sel);
                    }
                    if(evento.mouse.x >= LARGURA * 0.42 && evento.mouse.x <= LARGURA * 0.42 + al_get_bitmap_width(play) &&
                        evento.mouse.y >= ALTURA * 0.75 && evento.mouse.y <= ALTURA * 0.75 + al_get_bitmap_height(play)){
                        al_destroy_sample(voz1);
                        al_destroy_sample(voz2);
                        al_destroy_sample(voz3);
                        destruir_pagina(janela, play, play_sel, fundo, icone, fila_eventos, fonte);
                        letras3(FPS, ALTURA, LARGURA, pers_sel);
                    }
                }
            }
        al_flip_display();
        }
    //Calculo Para Controlar FPS

    tempo_fin = al_get_time() - tempo_ini;

    if(tempo_fin < 1.0 / FPS){
        al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
    }

    destruir_fases(janela, fundo, fila_eventos, play, play_sel);

    return 0;
}
