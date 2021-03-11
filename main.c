#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca_fila.h"
#include "biblioteca_matriz.h"
#include "biblioteca_celula.h"

void valida_adjacente (int l, int c,int dist, MatrizDinamica *caminho, MatrizDinamica *status,FilaGenerica *fila,Celula inicio);
void mostra(void *a);
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
	inicializa_fila(&fila,30,sizeof(Celula));

	//inicialmente deiarei a inicializaçao da celula padrao
	Celula inicio;
	Celula final;
	Celula C;

	cria_celula(&inicio,0,0,0);
	cria_celula(&final,4,4,0);

	printf ("\nDados da celula inicio");
	mostrar_celula(inicio);
	printf ("Dados da celula final");
	mostrar_celula(final);

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
		if (comparaCelula(C,final))
		{
			achou=1;
		}else{
			l=C.linha;
			c=C.coluna;
			dist=C.dist;
			valida_adjacente(l,c+1,dist+1,&caminho,&status,&fila,inicio);
			valida_adjacente(l,c-1,dist+1,&caminho,&status,&fila,inicio);
			valida_adjacente(l-1,c,dist+1,&caminho,&status,&fila,inicio);
			valida_adjacente(l+1,c,dist+1,&caminho,&status,&fila,inicio);
		}
	}
	if (achou)
	{
		printf(" A distancia e %d\n\n",C.dist);
	}else{
		printf("nao deu ");
	}
	mostra_matriz(caminho);

	//inicializa status
	mostra_matriz(status);
	//desaloca as matrizes 
	desaloca_matriz(&caminho);
	desaloca_matriz(&status);
	desaloca_fila(&fila);
	
    return 0;
}
void mostra(void *a){
	Celula *b=a;
	mostrar_celula(*b);
}

void valida_adjacente (int l, int c,int dist, MatrizDinamica *caminho, MatrizDinamica *status,FilaGenerica *fila,Celula inicio){
	int auxi, valor, auxi2 ; 
	get_matriz(caminho,l,c,&auxi);
	valor=get_matriz(status,l,c,&auxi2);
	if (valor==1 && !auxi==0 && auxi2==0 && (l!=inicio.linha || c!=inicio.coluna)){
		auxi=1;
		modifica_matriz(status,l,c,auxi);

		Celula C;
		cria_celula(&C,l,c,dist);
		inserir(fila,&C);

	}
}


