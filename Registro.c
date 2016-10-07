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
    setlocale(LC_ALL, "portuguese");
    do{
        printf("\n---------- Cadastro de Jogadores -----------\n\n");
        //Repetição para cadastro de alunos
        printf("Informe o nome: ");
        scanf ( "%[^\n]", &aluno.nome);
        __fpurge(stdin);
        //gets(aluno.nome);

        printf("Informe a escola: ");
        scanf ( "%[^\n]", &aluno.escola);
        __fpurge(stdin);
        //gets(aluno.escola);

        printf("Informe a idade: ");
        scanf("%i", &aluno.idade);
        __fpurge(stdin);

        printf("Jogaria em sua escola?");
        printf("\nS - Sim / N - Não ");
        scanf("%c", &aluno.jogaria);
        __fpurge(stdin);

        //Grava a struct em um arquivo
        fp = fopen("alunos.txt", "a");

        fprintf(fp, "%s %s %i %c\n\n", aluno.nome, aluno.escola, aluno.idade, aluno.jogaria);

        fclose(fp);

        cont ++;
        system("clear");
    }while(cont > 0);

    return 0;
}
