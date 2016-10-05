//Inclusão de bibliotecas padrão
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <locale.h>

int instrucoes(int FPS, int ALTURA, int LARGURA){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_BITMAP * play = NULL;
    ALLEGRO_BITMAP * play_sel= NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_AUDIO_STREAM * voz1 = NULL;
    ALLEGRO_AUDIO_STREAM * voz2 = NULL;


    //Declaração de variáveis
    bool aberto = true;
    bool sel1 = false,
         sel2 = false;
    double tempo_ini = 0,
           tempo_fin = 0;
    int opcao = 0;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();
    setlocale(LC_ALL, "Portuguese"); // Configurando caracteres especiais e acentuação


    //Criação do display e seus elementos gráficos
    janela = al_create_display(LARGURA, ALTURA);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos
    play = al_load_bitmap("Arte/barrinha.png");
    play_sel = al_load_bitmap("Arte/barrinha_sel.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    icone = al_load_bitmap("Arte/icone.png");
    voz = al_load_sample("Narrador/inst_tela.ogg");
    voz1 = al_load_sample("Narrador/voltar_menu.ogg");
    voz2 = al_load_sample("Narrador/sair.ogg");


    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_draw_bitmap(fundo, 0, 0, 0);

    //Primeiro desenho da página
    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(play, LARGURA * 0.2, ALTURA * 0.76, 0);
    al_draw_bitmap(play, LARGURA * 0.6, ALTURA * 0.76, 0);

    //Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.21, ALTURA * 0.77, 0, "MENU");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.61, ALTURA * 0.77, 0, "SAIR");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.1, ALTURA * 0.1, 0, "NO MODO 'LETRAS':");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.1, ALTURA * 0.15, 0, "CLIQUE NAS LETRAS QUE FORMAM O NOME DA IMAGEM.");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.1, ALTURA * 0.20, 0, "SE PRECISAR DE AJUDA CLIQUE NO BOTÃO '?'.");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.1, ALTURA * 0.3, 0, "NO MODO 'IMAGEM':");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.1, ALTURA * 0.35, 0, "ESCOLHA A IMAGEM DE ACORDO COM A PALAVRA.");

    al_flip_display();
    al_play_sample(voz,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

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
                    if(evento.mouse.x > LARGURA * 0.2 && evento.mouse.x < LARGURA * 0.2 + al_get_bitmap_width(play)){
                        sel1 = true;
                    }else{
                        sel1 = false;
                    }
                    if(evento.mouse.x > LARGURA * 0.6 && evento.mouse.x < LARGURA * 0.6 + al_get_bitmap_width(play)){
                        sel2 = true;
                    }else{
                        sel2 = false;
                    }
                }else{
                    sel1 = false;
                    sel2 = false;
                    opcao = 0;
                }

                if(sel1){
                    al_draw_bitmap(play_sel, LARGURA * 0.2, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.21, ALTURA * 0.77, 0, "MENU");//Escrevendo a opção no Menu;

                    if(opcao != 1){
                        al_play_sample(voz1,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        opcao = 1;
                    }
                }else{
                    al_draw_bitmap(play, LARGURA * 0.2, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.21, ALTURA * 0.77, 0, "MENU");//Escrevendo a opção no Menu;

                }
                if(sel2){
                    al_draw_bitmap(play_sel, LARGURA * 0.6, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.77, 0, "SAIR");//Escrevendo a opção no Menu;

                    if(opcao != 2){
                        al_play_sample(voz2,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                        opcao = 2;
                    }
                }else{
                    al_draw_bitmap(play, LARGURA * 0.6, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.61, ALTURA * 0.77, 0, "SAIR");//Escrevendo a opção no Menu;
                }
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                //Alterando as páginas com clique
                if(evento.mouse.x >= LARGURA * 0.6 && evento.mouse.x <= LARGURA * 0.6 + al_get_bitmap_width(play) &&
                    evento.mouse.y >= ALTURA * 0.76 && evento.mouse.y <= ALTURA * 0.76 + al_get_bitmap_height(play)){
                    fechaJanela(janela);
                }
                if(evento.mouse.x >= LARGURA * 0.2 && evento.mouse.x <= LARGURA * 0.2 + al_get_bitmap_width(play) &&
                    evento.mouse.y >= ALTURA * 0.76 && evento.mouse.y <= ALTURA * 0.76 + al_get_bitmap_height(play)){
                    al_destroy_display(janela);
                    main();
                }
            }
        }
        al_flip_display();
    }

    tempo_fin = al_get_time() - tempo_ini;

    if(tempo_fin < 1.0 / FPS){
        al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
    }

    destruir_sobre(janela, fundo, fila_eventos, play, play_sel, fonte, icone);

    return 0;
}
