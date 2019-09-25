/*TRABALHO ARVORE BINÁRIA
ESTRUTURA DE DADOS 2
ALUNOS: BRUNO RODRIGUES GUIMARÃES, EDUARDO ENRIQUE
*/

#include <stdio.h>
#include <stdlib.h>
#include "Arvore_Binaria.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    No* arvore = NULL;
    No* no;
    Aluno aluno,pesquisa;
    int esc,cont = 0;
    for(;;)
    {
        printf("\n1-Inserir aluno");
        printf("\n2-Mostrar alunos");
        printf("\n3-Menor matricula");
        printf("\n4-Maior matricula");
        printf("\n5-Pesquisar aluno");
        printf("\n6-Nó raiz");
        printf("\n7-Mostrar folhas");
        printf("\n8-Remover aluno");
        printf("\n9-Carregar alunos");

        printf("\nopção: ");
        scanf(" %d",&esc);
        switch(esc)
        {
        case 1:
            printf("\nMatricula: ");
            scanf(" %d",&aluno.matricula);
            printf("Nome: ");
            scanf(" %[^\n]s",&aluno.nome);
            printf("Sobrenome: ");
            scanf(" %[^\n]s",&aluno.sobrenome);
            inserir_aluno(&arvore,&aluno);
            break;
        case 2:
            mostrar_matriculas(arvore);
            break;
        case 3:
            no = *menor_matricula(&arvore);
            printf("\nMatricula: %d",no->aluno->matricula);
            printf("\nNome: %s",no->aluno->nome);
            printf("\nSobrenome: %s",no->aluno->sobrenome);
            break;
        case 4:
            no = *maior_matricula(&arvore);
            printf("\nMatricula: %d",no->aluno->matricula);
            printf("\nNome: %s",no->aluno->nome);
            printf("\nSobrenome: %s",no->aluno->sobrenome);
            break;
        case 5:
            printf("Nome: ");
            scanf(" %[^\n]s",&aluno.nome);
            pesquisar_aluno(arvore,&aluno);
            break;
        case 6:
            no_raiz(arvore);
            break;
        case 7:
            mostrar_folhas(&arvore);
            break;
        case 8:
            printf("Matricula: ");
            scanf(" %d",&aluno.matricula);
            remover_no(&arvore,aluno.matricula);
            break;
        case 9:
            carregar_alunos(&arvore);
            printf("\n\n<alunos na lista>");
            break;
        }
        getch();
        system("cls");
    }
}
