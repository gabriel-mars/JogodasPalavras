#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <locale.h>

int casa3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false;

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
    setlocale(LC_ALL, "");

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/casa.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone2.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.36, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.16, ALTURA * 0.506, 0, "BALA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.36, ALTURA * 0.506, 0, "CELA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.56, ALTURA * 0.506, 0, "CASA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.76, ALTURA * 0.506, 0, "CERA");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.52 && evento.mouse.x < LARGURA * 0.52 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "BALA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "CELA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "CASA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "CERA");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                    }

                    if(let1){
                        al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                        al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");//Escrevendo a opção no Menu;
                        al_flip_display();
                    }

                    if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                        evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                            al_destroy_display(janela);
                            letras3(FPS, ALTURA, LARGURA,pers_sel);
                    }
                }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte, pergunta, icone);

    return 0;
}

int rato3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "RATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "PATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "GATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "SAPO");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.12 && evento.mouse.x < LARGURA * 0.12 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "RATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "PATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "GATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "SAPO");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }


                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }



                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int dado3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_SAMPLE * parabens = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    double tempo_ini = 0,
           tempo_fin = 0;
    bool let1 = false;
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
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "DEDO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "CABO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "DADO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "RABO");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.52 && evento.mouse.x < LARGURA * 0.52 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "DEDO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "CABO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "DADO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "RABO");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

               if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                    al_destroy_display(janela);
                    letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int barco3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    pergunta = al_load_bitmap("Arte/barco.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "BARCO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "BERÇO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "CERCO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "PERTO");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.12 && evento.mouse.x < LARGURA * 0.12 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "BARCO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "BERÇO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "CERCO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "PERTO");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int sapato3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    pergunta = al_load_bitmap("Arte/sapato.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.13, ALTURA * 0.506, 0, "SENSATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.33, ALTURA * 0.506, 0, "PRATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.53, ALTURA * 0.506, 0, "BARATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.73, ALTURA * 0.506, 0, "SAPATO");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.72 && evento.mouse.x < LARGURA * 0.72 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.13, ALTURA * 0.506, 0, "SENSATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.33, ALTURA * 0.506, 0, "PRATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.53, ALTURA * 0.506, 0, "BARATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.73, ALTURA * 0.506, 0, "SAPATO");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int escada3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    pergunta = al_load_bitmap("Arte/escada.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.13, ALTURA * 0.506, 0, "SALADA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.33, ALTURA * 0.506, 0, "ESCADA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.53, ALTURA * 0.506, 0, "ESCALA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.73, ALTURA * 0.506, 0, "CEVADA");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.32 && evento.mouse.x < LARGURA * 0.32 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.13, ALTURA * 0.506, 0, "SALADA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.33, ALTURA * 0.506, 0, "ESCADA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.53, ALTURA * 0.506, 0, "ESCALA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.73, ALTURA * 0.506, 0, "CEVADA");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }


                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int livro3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    pergunta = al_load_bitmap("Arte/livro.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "LIVRO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "TOURO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "JURO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "CARRO");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.12 && evento.mouse.x < LARGURA * 0.12 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa3, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "LIVRO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "TOURO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "JURO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "CARRO");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int abelha3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    pergunta = al_load_bitmap("Arte/abelha.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "AREIA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "ABELHA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "ORELHA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "CADEIA");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.32 && evento.mouse.x < LARGURA * 0.32 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "AREIA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "ABELHA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "ORELHA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "CADEIA");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }


                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int galo3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    pergunta = al_load_bitmap("Arte/galo.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "GATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "GELO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "PATO");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "GALO");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.72 && evento.mouse.x < LARGURA * 0.72 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "GATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "GELO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "PATO");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "GALO");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }


                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }



                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}

int janela3(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;

    //Declaração de variáveis
    bool narrador = false;
    bool aberto =  true;
    bool let1 =  false;

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
    pergunta = al_load_bitmap("Arte/janela.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    avancar = al_load_bitmap("Arte/barrinha.png");
    icone = al_load_bitmap("Arte/icone.png");
    caixa1 = al_load_bitmap("Arte/barra.png");
    caixa3= al_load_bitmap("Arte/barra_sel.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/Arial.ttf", 25, 0);
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
    al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.52, ALTURA * 0.5,0);
    al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.06, 0, "CLIQUE NO MEU NOME:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "TABELA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "CANELA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "JANELA");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "PANELA");//Escrevendo a opção no Menu;
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
                if(evento.mouse.x > LARGURA * 0.52 && evento.mouse.x < LARGURA * 0.52 + al_get_bitmap_width(caixa1) &&
                    evento.mouse.y > ALTURA * 0.5 && evento.mouse.y < ALTURA * 0.5 + al_get_bitmap_height(caixa1)){
                        al_draw_bitmap(caixa1, LARGURA * 0.12, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.32, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa3, LARGURA * 0.52, ALTURA * 0.5,0);
                        al_draw_bitmap(caixa1, LARGURA * 0.72, ALTURA * 0.5,0);

                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.15, ALTURA * 0.506, 0, "TABELA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.35, ALTURA * 0.506, 0, "CANELA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.55, ALTURA * 0.506, 0, "JANELA");//Escrevendo a opção no Menu;
                        al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.75, ALTURA * 0.506, 0, "PANELA");//Escrevendo a opção no Menu;

                        al_flip_display();
                        let1 = true;
                }


                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte2, al_map_rgb(255, 255, 255), LARGURA * 0.809, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras3(FPS, ALTURA, LARGURA,pers_sel);
                }
            }

            tempo_fin = al_get_time() - tempo_ini;

            if(tempo_fin < 1.0 / FPS){
                al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
            }
        }
    }

    destruir_palavras3(janela, fila_eventos, fonte,  pergunta, icone);

    return 0;
}
