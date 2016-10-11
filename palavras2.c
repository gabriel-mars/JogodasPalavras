#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

int casa2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/casa.png");
    erro1 = al_load_bitmap("Arte/abelha.png");
    erro2 = al_load_bitmap("Arte/barco.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "CASA");//Escrevendo a opção no Menu;

    al_draw_bitmap(pergunta, LARGURA * 0.24, ALTURA * 0.36, 0);
    al_draw_bitmap(erro1, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.24 && evento.mouse.x < LARGURA * 0.24 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.237, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.24, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int rato2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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
    erro1 = al_load_bitmap("Arte/sapato.png");
    erro2 = al_load_bitmap("Arte/livro.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_register_event_source(fila_eventos, al_get_mouse_event_source());

    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_set_display_icon(janela, icone);

    al_flip_display();

    al_draw_bitmap(fundo,0,0,0);
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6,0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "RATO");//Escrevendo a opção no Menu;

    al_draw_bitmap(pergunta, LARGURA * 0.29, ALTURA * 0.347, 0);
    al_draw_bitmap(erro1, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.29 && evento.mouse.x < LARGURA * 0.29 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.347 && evento.mouse.y < ALTURA * 0.347 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.287, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.29, ALTURA * 0.347, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int dado2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
	ALLEGRO_DISPLAY * janela = NULL;
	ALLEGRO_BITMAP * fundo = NULL;
	ALLEGRO_BITMAP * avancar = NULL;
	ALLEGRO_BITMAP * caixa1 = NULL;
	ALLEGRO_BITMAP * caixa2 = NULL;
	ALLEGRO_BITMAP * caixa3 = NULL;
	ALLEGRO_BITMAP * icone = NULL;
	ALLEGRO_BITMAP * pergunta = NULL;
	ALLEGRO_BITMAP * erro1 = NULL;
	ALLEGRO_BITMAP * erro2 = NULL;
	ALLEGRO_BITMAP * selecao = NULL;
	ALLEGRO_AUDIO_STREAM * voz = NULL;
	ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
	ALLEGRO_FONT * fonte = NULL;

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

	janela =  al_create_display(LARGURA, ALTURA);
	pergunta = al_load_bitmap("Arte/dado.png");
	erro1 = al_load_bitmap("Arte/escada.png");
	erro2 = al_load_bitmap("Arte/livro.png");
	selecao = al_load_bitmap("Arte/selecao.png");
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
	al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

	al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
	al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "DADO");//Escrevendo a opção no Menu;

	al_draw_bitmap(erro1, LARGURA * 0.24, ALTURA * 0.36, 0);
	al_draw_bitmap(pergunta, LARGURA * 0.469, ALTURA * 0.4, 0);
	al_draw_bitmap(erro2, LARGURA * 0.65, ALTURA * 0.36, 0);

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
				if(evento.mouse.x > LARGURA * 0.469 && evento.mouse.x < LARGURA * 0.469 + al_get_bitmap_width(pergunta) &&
					evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
						al_draw_bitmap(selecao, LARGURA * 0.435, ALTURA * 0.351, 0);
						al_draw_bitmap(pergunta, LARGURA * 0.469, ALTURA * 0.4, 0);

						al_flip_display();
						let1 = true;
				}

				if(let1){
					al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
					al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
					al_flip_display();
				}

				if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
					evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
						al_destroy_display(janela);
						letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int barco2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/barco.png");
    erro1 = al_load_bitmap("Arte/galo.png");
    erro2 = al_load_bitmap("Arte/dado.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "BARCO");//Escrevendo a opção no Menu;

    al_draw_bitmap(erro1, LARGURA * 0.24, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.647, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int sapato2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/sapato.png");
    erro1 = al_load_bitmap("Arte/casa.png");
    erro2 = al_load_bitmap("Arte/dado.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "SAPATO");//Escrevendo a opção no Menu;

    al_draw_bitmap(pergunta, LARGURA * 0.24, ALTURA * 0.36, 0);
    al_draw_bitmap(erro1, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.69, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.24 && evento.mouse.x < LARGURA * 0.24 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.237, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.24, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int escada2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/escada.png");
    erro1 = al_load_bitmap("Arte/livro.png");
    erro2 = al_load_bitmap("Arte/janela.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "ESCADA");//Escrevendo a opção no Menu;

    al_draw_bitmap(erro1, LARGURA * 0.24, ALTURA * 0.36, 0);
    al_draw_bitmap(pergunta, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.47 && evento.mouse.x < LARGURA * 0.47 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.457, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.47, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int livro2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/livro.png");
    erro1 = al_load_bitmap("Arte/abelha.png");
    erro2 = al_load_bitmap("Arte/barco.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "LIVRO");//Escrevendo a opção no Menu;

    al_draw_bitmap(erro1, LARGURA * 0.24, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.42, ALTURA * 0.36, 0);
    al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.647, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int abelha2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/abelha.png");
    erro1 = al_load_bitmap("Arte/janela.png");
    erro2 = al_load_bitmap("Arte/galo.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "ABELHA");//Escrevendo a opção no Menu;

    al_draw_bitmap(erro2, LARGURA * 0.28, ALTURA * 0.36, 0);
    al_draw_bitmap(erro1, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.64, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA,pers_sel);
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

int galo2(int FPS,int ALTURA,int LARGURA,int pers_sel){
    //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/galo.png");
    erro1 = al_load_bitmap("Arte/abelha.png");
    erro2 = al_load_bitmap("Arte/barco.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "GALO");//Escrevendo a opção no Menu;

    al_draw_bitmap(pergunta, LARGURA * 0.24, ALTURA * 0.36, 0);
    al_draw_bitmap(erro1, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.24 && evento.mouse.x < LARGURA * 0.24 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.237, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.24, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA, pers_sel);
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

int janela2(int FPS,int ALTURA,int LARGURA,int pers_sel){
        //Inicialização das variáveis com Allegro
    ALLEGRO_DISPLAY * janela = NULL;
    ALLEGRO_BITMAP * fundo = NULL;
    ALLEGRO_BITMAP * avancar = NULL;
    ALLEGRO_BITMAP * caixa1 = NULL;
    ALLEGRO_BITMAP * caixa2 = NULL;
    ALLEGRO_BITMAP * caixa3 = NULL;
    ALLEGRO_BITMAP * icone = NULL;
    ALLEGRO_BITMAP * pergunta = NULL;
    ALLEGRO_BITMAP * erro1 = NULL;
    ALLEGRO_BITMAP * erro2 = NULL;
    ALLEGRO_BITMAP * selecao = NULL;
    ALLEGRO_AUDIO_STREAM * voz = NULL;
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_FONT * fonte = NULL;

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

    janela =  al_create_display(LARGURA, ALTURA);
    pergunta = al_load_bitmap("Arte/janela.png");
    erro1 = al_load_bitmap("Arte/casa.png");
    erro2 = al_load_bitmap("Arte/dado.png");
    selecao = al_load_bitmap("Arte/selecao.png");
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
    al_draw_bitmap(pers_sel, LARGURA * 0.08, ALTURA * 0.6, 0);

    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.37, ALTURA * 0.15, 0, "SELECIONE MINHA IMAGEM:");//Escrevendo a opção no Menu;
    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.47, ALTURA * 0.2, 0, "JANELA");//Escrevendo a opção no Menu;

    al_draw_bitmap(erro1, LARGURA * 0.24, ALTURA * 0.36, 0);
    al_draw_bitmap(erro2, LARGURA * 0.47, ALTURA * 0.36, 0);
    al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

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
                if(evento.mouse.x > LARGURA * 0.65 && evento.mouse.x < LARGURA * 0.65 + al_get_bitmap_width(pergunta) &&
                    evento.mouse.y > ALTURA * 0.36 && evento.mouse.y < ALTURA * 0.36 + al_get_bitmap_height(pergunta)){
                        al_draw_bitmap(selecao, LARGURA * 0.647, ALTURA * 0.351, 0);
                        al_draw_bitmap(pergunta, LARGURA * 0.65, ALTURA * 0.36, 0);

                        al_flip_display();
                        let1 = true;
                }

                if(let1){
                    al_draw_bitmap(avancar, LARGURA * 0.8, ALTURA * 0.8,0);
                    al_draw_textf(fonte, al_map_rgb(255, 255, 255), LARGURA * 0.806, ALTURA * 0.82, 0, "CONTINUAR");
                    al_flip_display();
                }

                if(evento.mouse.x > LARGURA * 0.8 && evento.mouse.x < LARGURA * 0.8 + al_get_bitmap_width(avancar) &&
                    evento.mouse.y > ALTURA * 0.8 && evento.mouse.y < ALTURA * 0.8 + al_get_bitmap_height(avancar)){
                        al_destroy_display(janela);
                        letras2(FPS, ALTURA, LARGURA, pers_sel);
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
