#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_fila.h"
#include "biblioteca_matriz.h"

void preencheLinhaColuna(int *l,int *c);

int main(int argc, char const *argv[])
{
    // MatrizDinamica m1;
    // inicializa_matriz(&m1,7,6);
    // mostra_matriz(m1);

    int l,c;
    printf("Digite a quantidade de linhas:\n");
    sscanf("%d",&l);
    printf("Digite a quantidade de colunas:\n");
    sscanf("%d",&c);

    MatrizDinamica caminho;
    MatrizDinamica visao;

	inicializa_matriz(&caminho,l,c);
	inicializa_matriz(&visao,l,c);
    preencheLinhaColuna(&l,&c);

	srand(time(NULL));
	for (int i = 0; i < l; ++i){
	    for (int j = 0; j < c; ++j){
	        char a[5] = {' ','\0'};
			if((rand() % 100) < 20){
			    strcpy(a,"[ ]");
			}
			modifica_matriz(&caminho,i,j,&a);
		}
	}



    
    return 0;
}


void preencheLinhaColuna(int *l,int *c){
	char auxChar[5];
	int aux;
	do{
		printf("Qual o numero de linhas do mapa:\n");
	    gets(auxChar);
	    aux = validaNumero(auxChar);
	    if(aux){
	        *l = atoi(auxChar);
	    }else
			printf("Digite um valor valido\n");
	} while (!aux);

	do{
		printf("Qual o numero de colunas do mapa:\n");
	    gets(auxChar);
	    aux = validaNumero(auxChar);
	    if(aux){
	        *c = atoi(auxChar);
	    }else
	    	printf("Digite um valor valido\n");
	} while (!aux);
}

