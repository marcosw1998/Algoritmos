#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int cont;
    struct NO *next;
    struct NO *ant;
}no;
no *aloca(no *lista)
{
    int i;
    lista= (no*) malloc( sizeof(no));
    lista->next= NULL;
    lista->ant= NULL;
		return lista;
}
void busca(no *head,no *hd2,int *contador)
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
void concat(no *head,no *hd2,int num)
{
    no *aux,*ant,*aux2;
    aux = head;
    no *auxhd,*anthd;
    auxhd= hd2;
    anthd= hd2;
    while( aux->next != NULL && aux->cont != num)
    {
        ant = aux;
        aux = aux-> next;
    }
        if (aux->next == NULL && aux->cont != num)
        {
            printf("Valor nao encontrado");
        }
            else
            {
                printf("Valor encontrado! %d\n",num);
                    if (aux->next == NULL) //caso o ultimo elemento seja o escolhido
                    {
                        aux->next = anthd->next;
                    }
                        else
                        {
                            while( auxhd->next != NULL) //auxhd está no fim da 2a lista
                            {
                                auxhd = auxhd-> next;
                            }
                                aux2 = aux->next;
                                auxhd->next = aux2;
                                aux->next = anthd->next;
                        }
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
        novo->ant = aux;
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
    printf("\n");
      //  printf("\n"); printar ao contrário
   // while (aux->ant != NULL)
    //{
      //  printf("%d ",aux->cont);
        //aux = aux->ant;
    //}
}
void rem(no *head, int num) // funfando
{
    no *aux,*ant,*auxhd,*aux2;
    aux = head;

    while( aux->next != NULL && aux->cont != num)
    {
        ant = aux;
        aux = aux-> next;
    }
        if (aux->next == NULL && aux->cont != num)
        {
            printf("Valor nao encontrado");
        }
            else
            {
                //printf("aux = %d ant = %d\n",aux->cont,ant->cont);
                printf("Valor encontrado! %d\n",num);
                if (aux->next == NULL) //caso o ultimo elemento seja o escolhido
                {
                    free(aux);
                    ant->next = NULL;
                }
                    else
                    {
                        aux -> next -> ant = ant;
                        ant->next = aux->next;
                        free(aux);
                    }
           }
}
int main()
{
    int m,n,o;
    no *head,*hd2;
    head = aloca(head);
    hd2= aloca(hd2);

    printf("Quero uma lista de m elementos\n");
    scanf("%d",&m);
    iaux(head,m);
    pri(head);
    printf("Agora quero fazer outra lista, com n elementos\n");
    scanf("%d",&n);
    iaux(hd2,n);
    pri(hd2);
    printf("E concatenar as duas apos o numero\n");
    scanf("%d",&o);
    concat(head,hd2,o);
    printf("Final\n");
    pri(head);

    return 0;
}
/*
     printf("\nQuero remover m\n");
    scanf("%d",&m);
    rem(head,m);


    printf("Quero uma nova lista de m elementos\n");
    scanf("%d",&m);
    iaux(hd2,m);
    pri(hd2);


    (m>n) // nao poderia ser subconjunto
    {
        printf("0");
        exit (0);
    }

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
    */

