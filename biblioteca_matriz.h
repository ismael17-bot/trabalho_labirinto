#define ERRO_COORDENADA_INVALIDA -1

typedef struct{
	int **dados;
	int linhas, colunas;
} MatrizDinamica;


// int preenche_matriz( MatrizDinamica m);
int get_matriz( MatrizDinamica p, int lin, int col, int *valor);
void inicializa_matriz_caminho( MatrizDinamica *p, int l, int c );
void inicializa_matriz_status( MatrizDinamica *p, int l, int c );
void mostra_matriz( MatrizDinamica m );
void desaloca_matriz( MatrizDinamica *p );
int modifica_matriz( MatrizDinamica *p, int lin, int col, int valor);
int compara_matrizes( MatrizDinamica a, MatrizDinamica b );
