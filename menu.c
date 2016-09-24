//Inclusão de bibliotecas padrão
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_ttf.h>

//Inclusão de módulos externos
#include "destruir.h"
#include "fechaJanela.h"
#include "Teste2Tela.c"
#include "sobre.c"
#include "instrucoes.c"
#include "personagem.c"
#include "letras.c"
#include "letras2.c"
#include "palavras.c"
#include "palavras2.c"
#include "final.c"

//Definição de constantes
const int ALTURA = 700;
const int LARGURA = 1366;
const int FPS = 60;

int main(void){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_BITMAP * abc = NULL;
    ALLEGRO_BITMAP * crianca = NULL;
    ALLEGRO_BITMAP * play = NULL;
    ALLEGRO_BITMAP * prof = NULL;
    ALLEGRO_BITMAP * play_sel= NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_AUDIO_STREAM * musica = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_AUDIO_STREAM * voz1 = NULL;
    ALLEGRO_AUDIO_STREAM * voz2 = NULL;
    ALLEGRO_AUDIO_STREAM * voz3 = NULL;
    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_FONT * fonte2 = NULL;


    //Declaração de variáveis
    bool aberto = true;
    bool desligar = false;
    bool sel1 = false, sel2 = false, sel3 = false, sel4 = false;
    double tempo_ini = 0,
           tempo_fin = 0;

    //Inicialização das bibliotecas
    al_init();
    al_install_mouse();
    al_init_image_addon();
    al_install_audio(); //Instalação do audio
    al_init_acodec_addon(); //Inicio do audio
    al_reserve_samples(2); //Reserva de canal para audio
    al_install_keyboard();
    al_init_font_addon(); //Instalação das fontes
    al_init_ttf_addon();

    //Criação do display e seus elementos gráficos
    janela = al_create_display(LARGURA, ALTURA);
    fila_eventos = al_create_event_queue(); //Criação da fila de eventos
    abc = al_load_bitmap("Arte/abc.png");
    crianca = al_load_bitmap("Arte/crianca.png");
    play = al_load_bitmap("Arte/barrinha.png");
    play_sel = al_load_bitmap("Arte/barrinha_sel.png");
    prof = al_load_bitmap("Arte/professor.png");
    fundo = al_load_bitmap("Arte/Plano-de-fundo.png");
    icone = al_load_bitmap("Arte/icone.png");
    fonte = al_load_ttf_font("Arte/Arial.ttf", 30, 0);
    fonte2 = al_load_ttf_font("Arte/rayando.ttf", 80, 0);
    musica = al_load_audio_stream("Arte/playback.ogg",4,1024);
    voz = al_load_sample("Narrador/jogar.ogg");
    voz1 = al_load_sample("Narrador/Instrucoes.ogg");
    voz2 = al_load_sample("Narrador/sobre.ogg");
    voz3 = al_load_sample("Narrador/sair.ogg");


    //Adição do eventos na fila
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    //Ativar a música
    al_set_audio_stream_playmode(musica, ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());

    //Primeiro desenho da página
    al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.56, 0);
    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.66, 0);
    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.76, 0);
    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.86, 0);
    al_draw_bitmap(prof, LARGURA * 0.7, ALTURA * 0.45, 0);
    al_draw_bitmap(abc, LARGURA * 0.45, ALTURA * 0.45, 0);
    al_draw_bitmap(crianca, LARGURA * 0.25, ALTURA * 0.45, 0);

    //Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.05, ALTURA * 0.58, 0, "Jogar");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.05, ALTURA * 0.68, 0, "Ajuda");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.05, ALTURA * 0.78, 0, "Sobre");
    al_draw_textf(fonte, al_map_rgb(255, 255,255), LARGURA * 0.05, ALTURA * 0.88, 0, "Sair");
    al_draw_textf(fonte2, al_map_rgb(255, 255,255), LARGURA * 0.3, ALTURA * 0.2, 0, "Jogo Das Palavras");

    al_flip_display();

    //Título da Janela
    al_set_window_title(janela, "Jogo das Palavras");

    while(aberto){  //Repetição para o display permanecer aberto
        tempo_ini = al_get_time();

        if(!desligar){
            al_set_audio_stream_playing(musica, true); //Tocas música durante a execução
        }else{
            al_set_audio_stream_playing(musica, false); //Parar a música
        }

        while(!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;

            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                fechaJanela(janela);
            }else if(evento.type == ALLEGRO_EVENT_KEY_UP){ //Trocas de página de acordo com a tecla pressionada
                switch(evento.keyboard.keycode){
                    case ALLEGRO_KEY_M:
                        desligar = true;
                    break;
                    case ALLEGRO_KEY_N:
                        desligar = false;
                    break;
                    case ALLEGRO_KEY_3:
                        sobre(FPS, ALTURA, LARGURA);
                    break;
                    case ALLEGRO_KEY_4:
                        instrucoes(FPS, ALTURA, LARGURA);
                    break;
                    case ALLEGRO_KEY_ESCAPE:
                        fechaJanela(janela);
                    break;
                }
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x > LARGURA * 0.04 && evento.mouse.x < LARGURA * 0.04 + al_get_bitmap_width(play)){
                    if(evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play)){
                        sel1 = true;

                    }else{
                        sel1 = false;
                    }

                    if(evento.mouse.y > ALTURA * 0.66 && evento.mouse.y < ALTURA * 0.66 + al_get_bitmap_height(play)){
                        sel2 = true;
                    }else{
                        sel2 = false;
                    }

                    if(evento.mouse.y > ALTURA * 0.76 && evento.mouse.y < ALTURA * 0.76 + al_get_bitmap_height(play)){
                        sel3 = true;
                    }else{
                        sel3 = false;
                    }

                    if(evento.mouse.y > ALTURA * 0.86 && evento.mouse.y < ALTURA * 0.86 + al_get_bitmap_height(play)){
                        sel4 = true;
                    }else{
                        sel4 = false;
                    }
                }else{
                    sel1 = false;
                    sel2 = false;
                    sel3 = false;
                    sel4 = false;
                }
                if(sel1){
                    al_draw_bitmap(play_sel, LARGURA * 0.04, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.58, 0, "Jogar");//Escrevendo a opção no Menu;
                    al_play_sample(voz,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                }
                else{
                    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.56, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.58, 0, "Jogar");//Escrevendo a opção no Menu;
                }
                if(sel2){
                    al_draw_bitmap(play_sel, LARGURA * 0.04, ALTURA * 0.66, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.68, 0, "Ajuda");//Escrevendo a opção no Menu;
                    al_play_sample(voz1,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

                }else{
                    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.66, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.68, 0, "Ajuda");//Escrevendo a opção no Menu;
                }

                if(sel3){
                    al_draw_bitmap(play_sel, LARGURA * 0.04, ALTURA * 0.76, 0);
                   al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.78, 0, "Sobre");//Escrevendo a opção no Menu;
                    al_play_sample(voz2,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

                }else{
                    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.76, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.78, 0, "Sobre");//Escrevendo a opção no Menu;
                }

                if(sel4){
                    al_draw_bitmap(play_sel, LARGURA * 0.04, ALTURA * 0.86, 0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.88, 0, "Sair");//Escrevendo a opção no Menu;
                    al_play_sample(voz3,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
                }else{
                    al_draw_bitmap(play, LARGURA * 0.04, ALTURA * 0.86,0);//desenhar(play);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.05, ALTURA * 0.88, 0, "Sair");//Escrevendo a opção no Menu;
                }
            }else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){ //Janelas com o clique
                //Jogar
                if(evento.mouse.x > LARGURA * 0.04 && evento.mouse.x < LARGURA * 0.04 + al_get_bitmap_width(play) &&
                    evento.mouse.y > ALTURA * 0.56 && evento.mouse.y < ALTURA * 0.56 + al_get_bitmap_height(play)){
                    al_destroy_display(janela);
                    personagens(FPS, ALTURA, LARGURA);
                }

                //Sobre
                if(evento.mouse.x > LARGURA * 0.04 && evento.mouse.x < LARGURA * 0.04 + al_get_bitmap_width(play) &&
                    evento.mouse.y > ALTURA * 0.76 && evento.mouse.y < ALTURA * 0.76 + al_get_bitmap_height(play)){
                    al_destroy_display(janela);
                    sobre(FPS, ALTURA, LARGURA);
                }
                //Instruções
                if(evento.mouse.x > LARGURA * 0.04 && evento.mouse.x < LARGURA * 0.04 + al_get_bitmap_width(play) &&
                    evento.mouse.y > ALTURA * 0.66 && evento.mouse.y < ALTURA * 0.66 + al_get_bitmap_height(play)){
                    al_destroy_display(janela);
                    instrucoes(FPS, ALTURA, LARGURA);
                }

                //Sair
                if(evento.mouse.x > LARGURA * 0.04 && evento.mouse.x < LARGURA * 0.04 + al_get_bitmap_width(play) &&
                    evento.mouse.y > ALTURA * 0.86 && evento.mouse.y < ALTURA * 0.86 + al_get_bitmap_height(play)){
                    fechaJanela(janela);
                }
            }
        }
        al_flip_display();
    }

    tempo_fin = al_get_time() - tempo_ini;

    if(tempo_fin < 1.0 / FPS){
        al_rest((1.0 / FPS) - (al_get_time()- tempo_ini));
    }

    destruir(play, play_sel, fundo, janela, icone, musica, fila_eventos, fonte);

    return 0;
}
