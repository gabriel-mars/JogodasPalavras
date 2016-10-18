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

int destruir_fases(int janela, int fundo, int fila_eventos, int play, int play_sel, int icone, int voz1, int voz2, int voz3, int fonte){
    al_destroy_display(janela);
	al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
	al_destroy_bitmap(fundo);
	al_destroy_bitmap(icone);
	al_destroy_font(fonte);
    al_destroy_sample(voz1);
    al_destroy_sample(voz2);
    al_destroy_sample(voz3);
    
    return 0;
}

int destruir_sobre(int janela, int fundo, int fila_eventos, int play, int play_sel, int fonte, int icone, int fonte2, int voz, int voz1, int voz2){
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
	al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
	al_destroy_bitmap(fundo);
    al_destroy_font(fonte);
    al_destroy_font(fonte2);
    al_destroy_bitmap(icone);
	al_destroy_sample(voz);
    al_destroy_sample(voz1);
    al_destroy_sample(voz2);

    return 0;
}

int destruir_palavras(int janela, int fila_eventos, int fonte, int pergunta, int icone, int fonte2, int fundo, int avancar, int caixa1, int caixa3){
    al_destroy_display(janela);
	al_destroy_bitmap(fundo);
	al_destroy_bitmap(avancar);
	al_destroy_bitmap(caixa1);
	al_destroy_bitmap(caixa3);
	al_destroy_bitmap(icone);
	al_destroy_bitmap(pergunta);
    al_destroy_event_queue(fila_eventos);
    al_destroy_font(fonte);
    al_destroy_font(fonte2);

    return 0;
}

int destruir_palavras2(int janela, int fila_eventos, int fonte, int pergunta, int icone, int fonte2, int fundo, int avancar, int caixa1, int caixa3, int erro1, int erro2, int selecao, int fonte3){
    al_destroy_display(janela);
	al_destroy_bitmap(fundo);
	al_destroy_bitmap(avancar);
	al_destroy_bitmap(caixa1);
	al_destroy_bitmap(caixa3);
	al_destroy_bitmap(icone);
	al_destroy_bitmap(pergunta);
	al_destroy_bitmap(erro1);
	al_destroy_bitmap(erro2);
	al_destroy_bitmap(selecao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_font(fonte);
    al_destroy_font(fonte2);
    al_destroy_font(fonte3);

    return 0;
}

int destruir_palavras3(int janela, int fundo, int avancar, int caixa1, int caixa3, int icone, int pergunta, int fila_eventos, int fonte, int fonte2){
    al_destroy_display(janela);
    al_destroy_bitmap(fundo);
    al_destroy_bitmap(avancar);
    al_destroy_bitmap(caixa1);
    al_destroy_bitmap(caixa3);
    al_destroy_bitmap(icone);
    al_destroy_bitmap(pergunta);
    al_destroy_event_queue(fila_eventos);
    al_destroy_font(fonte);
    al_destroy_font(fonte2);

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

int destruir_instrucoes(int janela, int fundo, int fila_eventos, int play, int play_sel, int fonte, int icone, int voz, int voz1, int voz2){
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
	al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
	al_destroy_bitmap(fundo);    
    al_destroy_font(fonte);
    al_destroy_bitmap(icone);
    al_destroy_sample(voz);
    al_destroy_sample(voz1);
    al_destroy_sample(voz2);

    return 0;
}

int destruir_personagens(int janela, int fila_eventos, int play, int play_sel, int fundo, int fonte, int icone){
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(play);
    al_destroy_bitmap(play_sel);
    al_destroy_bitmap(fundo);
	al_destroy_font(fonte);
    al_destroy_bitmap(icone);
    
    return 0;
}
