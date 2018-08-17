#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int cont;
    struct NO *next;
}no;

int busca(no *head,no *hd2,int *contador)
{
    no *aux;
    aux = head;
    no *aux2;
    aux2 = hd2;

    while( aux->next != NULL && aux2->cont != aux->cont)
    {
        aux = aux-> next;
    }

    if (aux->next == NULL && aux2->cont != aux->cont)
    {
        printf("0");
        exit (0);
    }
        else if((aux2->cont == aux->cont) || (aux->next == NULL && aux2->cont == aux->cont))
        {
            *contador+=1;
            aux2 = aux2->next;
        }
}

void insere(no *hd,int x)
{
    no *aux,*novo;
    aux = hd;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }
        novo = (no*)malloc(sizeof(no));
        novo->cont= x;
        novo->next = NULL;
        aux->next = novo;
}

void iaux (no *hd,int num)
{
    int i,x;
    for(i=0;i<num;i++)
    {
        scanf("%d",&x);
        insere(hd,x);
    }
}


void pri (no *head)
{
    no *aux;
    aux = head;
    while (aux->next != NULL)
    {
        aux = aux->next;
        printf("%d ",aux->cont);
    }
}

void rem(no *head,int num)
{
    no *aux,*ant,*aux2;
    aux = head;

    while( aux->next != NULL && aux->cont != num)
    {
        ant = aux;
        aux = aux-> next;
    }
        if (aux->next == NULL)
        {
            printf("Valor nao encontrado");
        }
        else
        {
            printf("Valor encontrado! %d\n",num);
            aux2 = aux->next;
            free(aux);
            ant -> next = aux2;
        }
}

int main()
{
    int i,m,n,x;
    int contador=0;
    no *head;
    head = (no*) malloc(sizeof(no));
    head->next= NULL;
    scanf("%d",&n);
    iaux(head,n);
    scanf("%d",&m);
    no *hd2;
    hd2 = (no*) malloc(sizeof(no));
    hd2->next= NULL;
    if (m>n) // nao poderia ser subconjunto
    {
      printf("0");
        exit (0);
    }

    iaux(hd2,m);

    for(i=0;i<m;i++)
    {
        hd2= hd2->next;
        busca(head,hd2,&contador);
        if (contador == m)
        {
            printf("1");
            exit (0);
        }
    }


    busca(head,head2,m);
        pri(head);
        printf("\nQuero remover o elemento: ");
        scanf("%d",&m);
        rem(head,m);
        pri(head);

    return 0;
}
