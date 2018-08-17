#include <stdio.h>
#include <stdlib.h>

typedef struct cel celula;

struct cel
{
    int conteudo;
    celula *prox;
};

void preenche(cel *p)
{
    int i;
    celula *j;

}

int main()
{
    cel *p;

    p = (celula*) malloc(2 * sizeof(celula));

    return 0;
}
