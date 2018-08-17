
#include <stdio.h>
#include <stdlib.h>

int sizeg;

void pri(int *vet,int size)
{
    int i;
    for(i=size-4;i<=size;i++)
    {
        printf("%d\n",vet[i]);
    }
    printf("\n");
}


void permuta(int *vet, int l,int m)
{
   	int aux;
    aux = vet[l];
    vet[l] = vet[m];
    vet[m] = aux;
}


int particao(int *vet, int l, int r)
{
    int p;
    p = (l+r)/2;	// escolha do pivÔ, o elemento do meio, usar a função random % range
    permuta(vet,l,p);
    int i,j;
    i=l;
    j=r;
    while(i<j)
    {
        while(i<=r && vet[i] <= vet[l]) //percorrendo do inicio até achar um valor maoior que v[0]
        {
            i++;
        }
        while(vet[l] < vet[j]) // percorrendo do final até encontrar um valor menor que o inicial
        {
            j--;
        }
        if(i<j)
        {
            permuta(vet,i,j);
        }
    }
    permuta(vet,l,j);
    return j;
}

void quicksort(int *v,int l,int r)
{
    int p;
    if (r<=l)
    {
        return;
    }
    //else
    p = particao(v,l,r);
    quicksort(v,l,p-1);
    quicksort(v,p+1,r);
}


int main()
{
    int x,y,n,i,j=0,*vet;

    //printf("Tamanho do vetor e valor:\n");
    scanf(" %d %d",&n,&y);

    vet= (int*) malloc ((n) * sizeof(int));

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
      sizeg= j;
      quicksort(vet,0,j); // onde 0 e j são as posições iniciais e finais do vetor
      pri(vet,j);

    return 0;
}