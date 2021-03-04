#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_fila.h"
#include "biblioteca_matriz.h"



int main(int argc, char const *argv[])
{
    MatrizDinamica m1;
    inicializa_matriz(&m1,10,10);
    // preenche_matriz (m1);
    mostra_matriz(m1);



    
    return 0;
}

