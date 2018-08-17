#include <stdio.h>
#include <stdlib.h>

void pri(int *vet,int size)
{
    int i;
    for(i=size-4;i<=size;i++)
    {
        printf("%d\n",vet[i]);
    }
    printf("\n");
}


void intercala(int *vet,int *aux, int l,int mid, int r)
{
    int i=l, j=mid, k= 0, x= (r-l)+1;

    while(i < mid && j <= r)
    {

        if ( vet[i] < vet[j])
        {
            aux[k] = vet[i];
            i++;
            k++;
        }
            else
            {
                aux[k] = vet[j];
                j++;
                k++;
            }
    }

    while(i<mid)
    {
        aux[k] = vet[i];
        i++;
        k++;
    }
    while(j <= r)
    {
        aux[k]= vet[j];
        j++;
        k++;
    }

    i=l;
    k=0;

    while(i <= r)
    {
        vet[i]= aux[k];
        i++;
        k++;
    }
}


void mergesort(int *vet,int *aux,int l,int r)
{
    if (l == r)
        return;
    int mid;
    mid = (l+r)/2;
    mergesort(vet,aux,l,mid);
    mergesort(vet,aux,mid+1,r);
    intercala(vet,aux,l,mid+1,r);
}


int main()
{
    int x,y,n,i,j=0,*vet,*aux;

    //printf("Tamanho do vetor e valor:\n");
    scanf(" %d %d",&n,&y);

    vet= (int*) malloc ((n) * sizeof(int));
    aux= (int*) malloc (((n/2)+1) * sizeof(int));

    for(i=0;i<n;i++)
    {
            scanf(" %d",&x);
            if(x % 10 == y)
            {
                vet[j] = x;
                j++;
            }

    }
      while (j < 5)
      {
        vet[j] = -1;
        j++;
      }
      j--;

      mergesort(vet,aux,0,j); // onde 0 e j são as posições iniciais e finais do vetor
      pri(vet,j);

    return 0;
}
