/*TRABALHO ARVORE BIN�RIA
ESTRUTURA DE DADOS 2
ALUNOS: BRUNO RODRIGUES GUIMAR�ES, EDUARDO ENRIQUE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arvore_Binaria.h"


void inserir_aluno(No** arvore,Aluno* aluno)
{
    if(*arvore == NULL)
    {
        *arvore = (No*)malloc(sizeof(No));
        (*arvore)->aluno = (Aluno*)malloc(sizeof(Aluno));
        (*arvore)->direita = NULL;
        (*arvore)->esquerda = NULL;
        (*(*arvore)->aluno) = *aluno;
    }
    if((*arvore)->aluno->matricula > aluno->matricula)
        inserir_aluno(&(*arvore)->esquerda,aluno);
    else if((*arvore)->aluno->matricula < aluno->matricula)
        inserir_aluno(&(*arvore)->direita,aluno);
}

void mostrar_matriculas(No* arvore)
{
    if(arvore != NULL)
    {
        mostrar_matriculas(arvore->esquerda);
        printf("\nMatricula: %d",arvore->aluno->matricula);
        printf("\nNome: %s \n",arvore->aluno->nome);
        printf("Sobrenome: %s \n\n",arvore->aluno->sobrenome);
        mostrar_matriculas(arvore->direita);
    }

}
No** menor_matricula(No** arvore)
{
    if((*arvore)->esquerda != NULL)
    {
        menor_matricula(&(*arvore)->esquerda); //CAMINHA AT� O N� MAIS ESQUERDO DA ARVORE
    }
    else
    {
        return arvore; //RETORNA O MENOR N�
    }
}

No** maior_matricula(No** arvore)
{
    if((*arvore)->direita != NULL)
    {
        maior_matricula(&(*arvore)->direita); //CAMINHA AT� O N� MAIS DIREITO DA ARVORE
    }
    else
    {
        return arvore;  //RETORNA O MAIOR N�
    }
}

//PERCORRE A ARVORE, SE ACHAR UM ALUNO COM O NOME SOLICIDADO, O IMPRIME;
void pesquisar_aluno(No *arvore, Aluno* aluno)
{
    if(arvore != NULL)
    {
        if(strcmp(arvore->aluno->nome,aluno->nome) == 0)  //COMPARA O NOME SOLICITADO COM A DA ARVORE
        {
            printf("\nMatricula: %d",arvore->aluno->matricula);
            printf("\nNome: %s",arvore->aluno->nome);
            printf("\nSobrenome: %s",arvore->aluno->sobrenome);
            printf("\n-Est� matriculado-\n");
        }
        pesquisar_aluno(arvore->direita,aluno);
        pesquisar_aluno(arvore->esquerda,aluno);
    }
}

//PERCORRE A ARVORE COMPARANDO A MATRICULA COM OS DEMAIS N�S;
No** pesquisar_matricula(No **arvore, int matricula)
{
    if(*arvore == NULL)
        return NULL;
    if(matricula == (*arvore)->aluno->matricula)
    {
        return arvore;
    }
    else if(matricula > (*arvore)->aluno->matricula)
        pesquisar_matricula(&(*arvore)->direita,matricula);
    else if(matricula < (*arvore)->aluno->matricula)
        pesquisar_matricula(&(*arvore)->esquerda,matricula);
}


void no_raiz(No* arvore)
{
    if(arvore != NULL)
    {
        printf("<N� raiz>\n");
        printf("\nMatricula: %d",arvore->aluno->matricula);
        printf("\nNome: %s",arvore->aluno->nome);
        printf("\nSobrenome: %s",arvore->aluno->sobrenome);
    }
    else
        printf("\n\nArvore vazia");
}

//PERCORRE TODA A ARVORE E IMPRIME AS FOLHAS
void mostrar_folhas(No** arvore)
{
    if(*arvore != NULL)
    {
        mostrar_folhas(&(*arvore)->esquerda);
        if((*arvore)->direita == NULL && (*arvore)->esquerda == NULL) // SE O N� N�O TIVER FILHOS, O IMPRIME
        {
            printf("\nMatricula: %d",(*arvore)->aluno->matricula);
            printf("\nNome: %s \n\n",(*arvore)->aluno->nome);
        }
        mostrar_folhas(&(*arvore)->direita);
    }
}

//REMOVE O N� SOLI
void remover_no(No** arvore, int matricula)
{
    No* aux,*aux2;
    No** remover = pesquisar_matricula(arvore,matricula);  //PESQUIA O N� A SER REMOVIDO PELA MATRICULA
    if(*remover != NULL)
    {
        if((*remover)->direita != NULL) //SE A SUBARVORE DA DIREITA N�O ESTIVER VAZIA
        {
            aux = *maior_matricula(remover); //RETORNA O MAIOR N� DA SUBARVORE A DIREITA
            *((*remover)->aluno) = *(aux->aluno); //SUBSTITUI OS VALORES DO N� PELO MAIOR N� DA SUBARVORE
            if(aux->esquerda != NULL) //SE O MAIOR N� TIVER FILHOS A ESQUERDA, ELE FAZ A SUBSTITUI��O DO N� PELO FILHO MAIS PROXIMO;
            {
                aux2 = aux->esquerda;
                aux->aluno = aux->esquerda->aluno;
                aux->esquerda = aux2->esquerda;
                aux->direita = aux2->direita;
                free(aux2);
            }
            else
                free(aux); //REMOVE O MAIOR N�
        }
        else if((*remover)->esquerda != NULL)  //SE A SUBARVORE DA ESQUERDA N�O ESTIVER VAZIA
        {
            aux = *menor_matricula(remover); //RETORNA O MENOR N� DA SUBARVORE A ESQUERDA
            *((*remover)->aluno) = *(aux->aluno); //SUBSTITUI OS VALORES DO N� PELO MENOR N� DA SUBARVORE
            if(aux->direita != NULL) //SE O MENOR N� TIVER FILHOS A DIREITA, ELE FAZ A SUBSTITUI��O DO N� PELO FILHO MAIS PROXIMO;
            {
                aux2 = aux->direita;
                aux->aluno = aux2->aluno;
                aux->direita = aux2->direita;
                aux->direita = aux2->esquerda;
                free(aux2);
            }
            else
                free(aux); //REMOVE O MENOR N�
        }
        else
        {
            free(*remover); //SE O N� A SER REMOVIDO N�O TIVER FILHOS, SIMPLESMENTE O APAGA E O ATRIBUI NULL;
            *remover = NULL;
        }
        printf("\nN� removido");
    }
    else
        printf("\nN� n�o esta na arvore");
}
