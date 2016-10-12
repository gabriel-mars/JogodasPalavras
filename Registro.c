#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void){
    //Declaração dos campos do registro
    struct cadastrar{
        char nome [30];
        char escola [30];
        char jogaria;
        int idade;
    };

    struct cadastrar aluno;
    int cont = 1;
    FILE *fp;
    setlocale(LC_ALL, "");
    do{
        printf("\n---------- Cadastro de Jogadores -----------\n\n");
        //Repetição para cadastro de alunos
        printf("Informe o nome: ");
        scanf ( "%[^\n]", &aluno.nome);
        fflush(stdin);
        //gets(aluno.nome);

        printf("Informe a escola: ");
        scanf ( "%[^\n]", &aluno.escola);
        fflush(stdin);
        //gets(aluno.escola);

        printf("Informe a idade: ");
        scanf("%i", &aluno.idade);
        fflush(stdin);

        printf("Jogaria em sua escola?");
        printf("\nS - Sim / N - Não ");
        scanf("%c", &aluno.jogaria);
        fflush(stdin);

        //Grava a struct em um arquivo
        fp = fopen("alunos.txt", "a");

        fprintf(fp, "%s %s %i %c %i\n\n", aluno.nome, aluno.escola, aluno.idade, aluno.jogaria, cont);

        fclose(fp);

        cont ++;
        system("cls");
    }while(cont > 0);

    return 0;
}
