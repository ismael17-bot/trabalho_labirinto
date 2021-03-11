
typedef struct{
	int dist;
	int linha, coluna;
} Celula;

void cria_celula(Celula *c,int l,int col, int d);

int comparaCelula(Celula a,Celula b);

void mostrar_celula(Celula c);