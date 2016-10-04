#include <stdio.h>

int destruir(int play, int play_sel, int fundo, int janela,int icone, int musica, int fila_eventos, int fonte){
    al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
    al_destroy_bitmap(fundo);
    al_destroy_bitmap(icone);
    al_destroy_display(janela);
    al_destroy_audio_stream(musica);
    al_destroy_event_queue(fila_eventos);
    al_destroy_font(fonte);

    return 0;
}

int destruir_fases(int janelaFases, int fundo, int fila_eventos, int play, int play_sel){
    al_destroy_display(janelaFases);
    al_destroy_bitmap(fundo);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);

    return 0;
}

int destruir_sobre(int janelaFases, int fundo, int fila_eventos, int play, int play_sel, int fonte, int icone){
    al_destroy_display(janelaFases);
    al_destroy_bitmap(fundo);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
    al_destroy_font(fonte);
    al_destroy_bitmap(icone);

    return 0;
}

int destruir_palavras(int janela, int fila_eventos, int fonte, int pergunta, int voz, int icone){
    al_destroy_audio_stream(voz);
    al_destroy_bitmap(pergunta);
    al_destroy_event_queue(fila_eventos);
    al_destroy_font(fonte);
    al_destroy_display(janela);
    al_destroy_bitmap(icone);

    return 0;
}

int destruir_letras(int janela, int fila_eventos, int fundo, int icone, int play, int play_sel, int fonte, int play1, int play2){
    al_destroy_display(janela);
    al_destroy_bitmap(fundo);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(play);
    al_destroy_bitmap(play1);
    al_destroy_bitmap(play2);
    al_destroy_bitmap(play_sel);
    al_destroy_bitmap(icone);
    al_destroy_font(fonte);

    return 0;
}

int destruir_fim(int janela, int fila_eventos, int play, int play_sel, int fundo, int fonte, int icone, int obrigado){
    al_destroy_display(janela);
    al_destroy_bitmap(fundo);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
    al_destroy_bitmap(icone);
    al_destroy_bitmap(obrigado);
    al_destroy_font(fonte);

    return 0;
}

int destruir_pagina(int janela, int play, int play_sel, int fundo, int icone, int fila_eventos, int fonte){
    al_destroy_display(janela);
    al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
    al_destroy_bitmap(fundo);
    al_destroy_bitmap(icone);
    al_destroy_event_queue(fila_eventos);
    al_destroy_font(fonte);
    return 0;
}
