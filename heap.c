#include <stdio.h>
#include <stdlib.h>


void heapify(int *vet, int i,int sizegeral)
{
    int m,l,r,aux;
    m= i;
    l= 2*m;
    r= (2*m)+1;
    if((l<sizegeral) && (vet[l]>vet[m])) // se o filho a esquerda é maior que o pai troca
    {
        m = l;
    }

    if((r<sizegeral) && (vet[r]>vet[m])) // se o filho a direita é maior que o pai atual troca, que pode ter sido alterado na cond anterior
    {
        m = r;
    }

    if(m != i) // sinal que teve de trocar
    {
        aux = vet[i];
        vet[i]= vet[m];
        vet[m] = aux;
        heapify(vet,m,sizegeral);
    }
}

void constroiheap(int *vet, int size)
{
    int i;

    for(i=(size/2); i >= 1; i--)   //pode ser que seja (size/2)-2 ou -1
    {
        heapify(vet,i,size);
    }
    vet[size] = 0; // Tá ficando com n a mais
    priheap(vet,size);
    printf("\n");

    return vet;

}

void removeheap(int *vet, int size)
{
    int aux;

        aux = vet[1];
        vet[1] = vet[size];
        vet[size] = aux;
        size --;
        heapify(vet,1,size);
}


void priheap(int *vet,int size)
{
    int i;
    for(i=1;i<=size;i++)
    {
        printf("%d ",vet[i]);
    }
}
int main()
{
    int i,x,n,*vet,tamaux;

    printf("Tamanho do vetor:\n");
    scanf(" %d",&n);
    n++;
    tamaux=n;
    vet= (int*) malloc ((n) * sizeof(int));

    // noesq = 2n
    // no dir= 2n+1
    // pai = n/2
    // folhas estão a partir de n/2

    for(i=1;i<n;i++)
    {
            scanf(" %d",&vet[i]);
    }
      priheap(vet,tamaux);
      constroiheap(vet,n);

      while(n > 1)
      {
        removeheap(vet,n);
        n--;
      }
      priheap(vet,tamaux);



    return 0;
}