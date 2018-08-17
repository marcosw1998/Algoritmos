#include<stdio.h>
#include<stdlib.h>

typedef struct No
{
    int cont;
    struct No *next;
}no;

int tam=0; // var global para saber quantos onibus sobraram no vagão

no *aloca(no *lista)
{
    lista= (no*) malloc(sizeof(no));
    lista->next= NULL;
    return lista;
}
void push(no *head,int x)
{
    no *aux,*novo;
    aux = head;

    if(tam==0)
    {
        tam++;
        aux->cont = x;
    }else
    {
        tam++;
        while(aux->next != NULL)
        {
            aux= aux->next;
        }
        novo = aloca(novo);
        novo->cont= x;
        aux->next = novo;
    }
}
void pop(no *head)
{
    if(tam==0)
    {
        printf("Pilha vazia\n");

    }else
        {
            no *aux,*ant;
            aux = head;
            while(aux->next != NULL)
            {
                ant = aux;
                aux= aux->next;
            }
                printf("%d\n",aux->cont);
                if(tam==1)
                {
                    aux = aloca(aux);
                    tam--;
                }
                else
                {
                    free(aux);
                    ant->next = NULL;
                    tam--;
                }
        }
}
void pri(no *head)
{
    no *aux;
    aux = head;
    printf("Na pilha contem os seguintes onibus\n");
        while(aux->next != NULL)
        {
            printf("%d ",aux->cont);
            aux = aux->next;
        }
            printf("%d ",aux->cont);
}
int main()
{
    int i=0,x,ch=0;
    char v[8];
    no *head;
    head = aloca(head);

    while(ch!=1)
    {
        scanf(" %s",&v);

        if(strcmp(v,"FIM") == 0)
        {
            printf("%d\n%",tam);
            ch=1;
        }
            else if(strcmp(v,"E0") == 0)
            {
                push(head,i);
                i++;
            }
                else if(strcmp(v,"S0") == 0)
                {
                    pop(head);
                }
    }

    return 0;
}
