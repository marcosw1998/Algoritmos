#include<stdio.h>
#include<stdlib.h>

typedef struct No
{
    int value;
    int visit;
    struct NO *precursor;
    struct No *next;
}no;



int tam=0,tam2=0; // var global para saber quantos onibus sobraram no vagão


no *aloca(no *vertice,int i)
{
    vertice= (no*) malloc(sizeof(no));
    vertice->next= NULL;
    vertice->precursor= NULL;
    vertice->visit =0;
    vertice->value= i;
    return vertice;
}

void E1D(no *d,int a) // vertice, quem vai ser o novo
{
    no *novo;
    novo = aloca(novo,a);
    no *per;
    per = d;

    if(per -> next == NULL)
    {
        per -> next = novo;

        if (novo->precursor == NULL)
        {
            novo -> precursor = d;
        }
    }
    else
    {
        while(per->next !=NULL)
        {
            per = per->next;
        }
        per -> next = novo;

        if (novo->precursor == NULL)
        {
            novo -> precursor = d;
        }
    }
}

void pri(no *d)
{

        while(d->next !=NULL)
        {
            printf("%d ",d->value);
            d = d->next;
        }
        printf("\n");
}

int main()
{
    int i=0,j=0;
    int tam,c,v,a; // tamanho do grafo, qtd de casos, vertices e arestas
    no *vet;

    scanf("%d %d",&tam,&c);
    vet = (int*) malloc(tam * sizeof(no));
        // aqui tenho de inicializar a lista de adjacência novamente

        for(i=0;i < tam;i++)
        {
            vet[i] = aloca(vet,i); // alocando o vetor de adjacências, cada um aponta para a head de um vertice
        }

        for(i=0;i<c;i++)
        {
            scanf("%d %d",&v,&a);

            vet[v] = E1D (vet[v],a);
            vet[a]=  E1D (vet[a],v);
        }

        for(i=0; i<tam ;i++)
        {
            pri(vet[i]);
        }

    return 0;
}
