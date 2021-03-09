#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_fila.h"
#include "biblioteca_matriz.h"
#include "biblioteca_celula.h"

int main(int argc, char const *argv[])
{
    int l,c;
    printf("Digite a quantidade de linhas:\n");
    scanf("%d",&l);
    printf("Digite a quantidade de colunas:\n");
    scanf("%d",&c);

    MatrizDinamica caminho;
    MatrizDinamica status;
	FilaGenerica fila;

	//inicializaçao das matrizes 
	inicializa_matriz_caminho(&caminho,l,c);
	inicializa_matriz_status(&status,l,c);
	
	//inicializaçao da fila
	inicializa_fila(&fila,30,4);

	//inicialmente deiarei a inicializaçao da celula padrao
	Celula inicio;
	Celula final;
	Celula C;

	celula(&inicio,0,0,0);
	celula(&final,4,4,0);

	printf ("\nDados da celula inicio");
	mostrar_celula(inicio);
	printf ("Dados da celula final");
	mostrar_celula(final);

	modifica_matriz(&status,inicio.linha,inicio.coluna,5);
	modifica_matriz(&status,final.linha,final.coluna,5);

	//preenche a matriz caminho randomicamente 
	for (int i = 0; i < l; ++i){
	    for (int j = 0; j < c; ++j){
			int a = 1;
			if((rand() % 100) < 30){
				a=0;
			}
			modifica_matriz(&caminho,i,j,a);
		}
	}
	printf("linhas:%d +++ colunas:%d\n\n\n",l,c );

	//mostra o labirinto 
	mostra_matriz(caminho);

	//inicializa status
	mostra_matriz(status);
	
	inserir(&fila,&inicio);
	int achou = 0;
	int dist = 0;

	while (!fila_vazia(fila) && !achou){
		remover(&fila,&C);
		if (C.linha==final.linha && C.coluna==final.coluna)
		{
			achou=1;
		}else{

		}
		
	}

	//desaloca as matrizes 
	desaloca_matriz(&caminho);
	desaloca_matriz(&status);
	desaloca_fila(&fila);

    return 0;
}

void valida_adjacente (int l, int c,int dist, MatrizDinamica *caminho, MatrizDinamica *status){
	int auxi;
	get_matriz(caminho,)
}


