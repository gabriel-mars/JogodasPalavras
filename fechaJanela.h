#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

int fechaJanela(int janela){
    if(al_show_native_message_box(janela, "Jogo das Palvras", "Sair", "Deseja realmente sair?", NULL, ALLEGRO_MESSAGEBOX_YES_NO)){
       exit(0);
    }

    return 0;
}
