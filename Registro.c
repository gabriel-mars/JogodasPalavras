#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void){
    //Declara��o dos campos do registro
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
        //Repeti��o para cadastro de alunos
        printf("Informe o nome: ");
        __fpurge(stdin);
        scanf ( "%[^\n]", &aluno.nome);
        //gets(aluno.nome);

        printf("Informe a escola: ");
        __fpurge(stdin);
        scanf ( "%[^\n]", &aluno.escola);
        //gets(aluno.escola);

        printf("Informe a idade: ");
        __fpurge(stdin);
        scanf("%i", &aluno.idade);

        printf("Jogaria em sua escola?");
        printf("\nS - Sim / N - N�o ");
        __fpurge(stdin);
        scanf("%c", &aluno.jogaria);

        //Grava a struct em um arquivo
        fp = fopen("alunos.txt", "a");

        fprintf(fp, "%s %s %i %c\n\n", aluno.nome, aluno.escola, aluno.idade, aluno.jogaria);

        fclose(fp);

        cont ++;
        system("clear");
    }while(cont > 0);

    return 0;
}
