/*TRABALHO ARVORE BINÁRIA
ESTRUTURA DE DADOS 2
ALUNOS: BRUNO RODRIGUES GUIMARÃES, EDUARDO ENRIQUE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arvore_Binaria.h"

void carregar_alunos(No** arvore)
{
    Aluno raiz = {875,"BRUNO"," RODRIGUES GUIMARÃES"};
    Aluno alunos[] =
    {
        {798,"ALEXSANDRA","NASCIMENTO CARNEIRO"},
        {409,"DOUGLAS","SCHMITZ DUPSKI"},
        {919,"EDUARDO","HENRIQUE DE OLIVEIRA"},
        {726,"FABIANO","DA SILVA OLIVEIRA"},
        {940,"GABRIEL","VINICIUS DE OLIVEIRA"},
        {530,"HEBER","WURMSTICH NARDES"},
        {264,"ISABELA","SILVEIRA ROCHA"},
        {255,"LUIS","HENRIQUE SCRIGNOLLI FROIO"},
        {845,"MARCIO","APARECIDO DA SILVA"},
        {405,"MARLON","RODRIGUES"},
        {861,"MATHEUS","CARMO DE MATOS PINHO"},
        {226,"MATHEUS","RODRIGUES DE SOUZA"},
        {458,"MICHAEL","DOUGLAS COSTA DA SILVA"},
        {067,"SILVIO","JULIANO REGIO LEITE"},
        {379,"THAIS","MEIRA PEREIRA"},
        {991,"THIEGO","RAMOS MOURA"},
        {986,"UANDERSON","COELHO RODRIGUES"},
    };

    int cont = sizeof(alunos)/sizeof(Aluno);

    for (int i = 0; i < cont; i++)
    {
        int r = rand() % cont;

        Aluno temp = alunos[i];
        alunos[i] = alunos[r];
        alunos[r] = temp;
    }

    inserir_aluno(arvore,&raiz);
    for(int i = 0; i < cont; i++)
    {
        inserir_aluno(arvore,&alunos[i]);
    }
}
