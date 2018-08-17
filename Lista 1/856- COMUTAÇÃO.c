#include<stdio.h>
#include<stdlib.h>

typedef struct No
{
    int cont;
    struct No *next;
}no;

int tam=0,tam2=0; // var global para saber quantos onibus sobraram no vagão

no *aloca(no *lista)
{
    lista= (no*) malloc(sizeof(no));
    lista->next= NULL;
    return lista;
}
void E1D(no *hd2,int x)
{
    if(tam2==0)
    {
        tam2++;
        no *aux2;
        aux2 = hd2;
        aux2->cont= x;
        aux2->next= NULL;
    }else
    {
        tam2++;
        no *aux2,*novo;
        aux2 = hd2;
        while(aux2->next != NULL)
        {
            aux2= aux2->next;
        }
        novo = aloca(novo);
        novo->cont= x;
        aux2->next = novo;
    }
}
no *S1D(no *hd2)
{
        if(tam2==0)
        {
            printf("Lista vazia\n");
        }else
        {
            no *aux2,*ant,*head;
            aux2 = hd2;
            head = hd2;
            if(tam2==1)
            {
                printf("%d\n",aux2->cont);
                free(aux2);
                aux2 = aloca(aux2);
                tam2--;
                return aux2;
            }else
                {
                    while(aux2->next != NULL)
                    {
                        ant = aux2;
                        aux2= aux2->next;
                    }
                        printf("%d\n",aux2->cont);
                        free(aux2);
                        ant->next = NULL;
                        tam2--;
                        return head;
            }
        }
}
no *E1E(no *hd2,int x)
{
    if(tam2==0)
    {
        tam2++;
        no *aux2;
        aux2 = hd2;
        aux2->cont= x;
        aux2->next= NULL;
        //printf("aux2 cont= %d",aux2->cont);
        return aux2;
    }
    else
    {
        tam2++;
        no *aux2,*novo;
        novo = aloca(novo);
        aux2 = hd2;
        novo->cont= x;
        novo->next = aux2;
       // printf("NOVO= %d, aux2= %d",novo->cont,aux2->cont);
        return novo;
    }
}
no *S1E(no *hd2)
{
        if(tam2==0)
        {
            printf("Lista vazia\n");
            return hd2;
        }
        else // talvez precise do caso onde só tenho 1 elemento
            {
                no *aux2,*ant;
                ant= hd2;
                printf("%d\n",ant->cont);
                if(tam2==1)
                {
                    free(ant);
                    ant = aloca(ant);
                    tam2--;
                    return ant;
                }else
                    {
                        aux2= ant->next;
                        free(ant);
                        tam2--;
                        return aux2;
                    }
            }
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
    int i=0,j=0,x,ch=0;
    char v[8];
    no *head,*hd2;
    head = aloca(head);
    hd2 = aloca(hd2);

    while(ch!=1)
    {
        scanf(" %s",&v);

        if(strcmp(v,"FIM") == 0)
        {
            printf("%d\n%d\n",tam,tam2);
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
                    else if(strcmp(v,"E1D") == 0)
                    {
                        E1D(hd2,i);
                        i++;
                    }
                        else if(strcmp(v,"S1D") == 0)
                        {
                           hd2= S1D(hd2);
                        }
                            else if(strcmp(v,"E1E") == 0)
                            {
                                hd2 = E1E(hd2,i);
                                i++;
                            }
                                    else if(strcmp(v,"S1E") == 0)
                                    {
                                        hd2= S1E(hd2);
                                    }
                                        else if(strcmp(v,"PRI") == 0)
                                        {
                                            printf("E0\n");
                                            pri(head);
                                            printf("E1\n");
                                            pri(hd2);
                                        }
    }

    return 0;
}
