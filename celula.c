
#include "biblioteca_celula.h"
#include <stdio.h>

void celula(Celula *c,int l,int col, int d){
	c->linha = l;
	c->coluna = col;
	c->dist = d;
}

int compara_celula(Celula a,Celula b){
	return (a.linha==b.linha && b.coluna==a.coluna);
}

void mostrar_celula(Celula c){
	printf("\n");
	printf("dist: %d || linha: %d || coluna: %d\n", c.dist, c.linha, c.coluna);
	printf("\n");
}