    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct NO
    {
        char city[11];
        int val;
        int peso;
        struct NO *next;
    }no;

    typedef struct heap
    {
        int val;
        int peso;
    }heap;

    heap h[15000]; //ta faltando zero aqui...
    int pos[15000];
    int sizeno=0;

    void heapify(int i)
    {
        int m,l,r;
        heap aux;
        m= i;
        int aux1;
        l= 2*m+1;
        r= (2*m)+2;
        if(( l < sizeno) && (h[l].peso < h[m].peso)) // se o filho a esquerda é menor que o pai troca
        {
            m = l;
        }

        if((r<sizeno) && (h[r].peso < h[m].peso)) // se o filho a direita é menor que o pai atual troca, que pode ter sido alterado na cond anterior
        {
            m = r;
        }

        if(m != i) // sinal que teve de trocar
        {
            aux = h[i];
            h[i] = h[m];
            h[m] = aux;

            aux1 = pos[h[i].val];
            pos[h[i].val] = pos[h[m].val];
            pos[h[m].val] = aux1;
            heapify(m);
        }
    }
    heap removeheap()
    {
        int aux1;
        heap r;
        aux1 = pos[h[0].val];
        r = h[0];
        h[0] = h[sizeno-1];
        h[sizeno-1] = r;

        pos[h[0].val] = pos[h[sizeno-1].val];
        pos[h[sizeno -1].val] = aux1;

            sizeno --;
            heapify(0);
            return r;
    }

    void bubbleup()
    {
        int i;
        heap aux;
        int aux1;
        i= sizeno-1;

        while(i>0 && h[i].peso <= h[(i-1)/2].peso)
        {

            aux1 = pos[h[i].val];
            pos[h[i].val] = pos[h[(i-1)/2].val];
            pos[h[(i-1)/2].val] = aux1;

            aux= h[i];
            h[i]= h[(i-1)/2];
            h[(i-1)/2] = aux;
            i= (i-1)/2;
        }
    }

    void heapinsert (int val,int peso)
    {
        h[sizeno].val = val;
        h[sizeno].peso = peso;
        pos[h[sizeno].val] = (sizeno);
        sizeno++;
        bubbleup();
    }

    void heap_update(int valora,int peso)
    {
        int i=0,key=0;

    if(h[pos[valora]].val == valora)
    {
        h[pos[valora]].val = valora;
        h[pos[valora]].peso = peso;
        bubbleup();
    }
        else
        {
            heapinsert(valora,peso);
        }

    }

    void dijkstra(no *p, int c1,int c2,int n)
    {
        int *d;
        int i;
        no *e;
        heap aux;
        d= (int*) malloc(n * sizeof(int));
        for(i=0;i<n;i++)
        {
            d[i] = 2147483647;
        }
        d[c1]=0;
        heapinsert(c1,0);
        for (i = 0; i < n; i++)
        {
            aux = removeheap();
            e = p[aux.val].next;
            while(e != NULL)
            {
                if(d[aux.val] + e->peso < d[e->val])
                {
                    d[e->val] = d[aux.val] + e->peso;
                    heap_update(e->val,d[e->val]);
                }
                e= e->next;
            }
        }
            printf("%d\n",d[c2]);
            free(d);
    }

    void insert(no *hd,int v,int p)
    {
        no *aux,*novo;
        aux = hd;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
            novo = (no*) malloc(sizeof(no));
            novo->val=v;
            novo->peso=p;
            novo->next = NULL;
            aux->next = novo;
    }

    int main()
    {
        no *p;
        int s,n,o,v,viz,peso;
        int rep,i,j,k,l,m,c1=-1,c2=-1,key=-1;
        char nome[11],cidade1[11],cidade2[11];

        scanf(" %d",&s);

        for(i=0;i<s;i++)
        {
            scanf("%d",&n);
            p= (no*) malloc ( n * sizeof(no));
            for(j=0;j<n;j++)
            {
                p[j].next = NULL;
                scanf("%s",p[j].city);
                scanf("%d",&v);
                for(k=0;k<v;k++)
                {
                    scanf("%d %d",&viz,&peso);
                    insert(&p[j],viz-1,peso); // até aqui tÔ apenas preenchendo a lista de adjacências de cada cidade, tá imprimi as listas e tão certas
                }
            }
            scanf("%d",&rep); //aqui vai ser a qtd de trajetos que ele vai tentar fazer
            for(l=0;l<rep;l++)
            {
                scanf(" %s", cidade1);
                scanf(" %s",cidade2);
                for(m=0;m<n;m++)
                {
                    if( strcmp(cidade1,p[m].city) == 0)
                        c1=m;
                    if(strcmp(cidade2,p[m].city)==0)
                        c2=m;
                    if(c1!=-1 && c2 != -1)
                    {
                        m=n;
                        key=1;
                    }
                }
                if (key==-1)
                {
                  //printf("Uma das cidades nao existe\n");
                  if(c1!=-1 || c2!=-1)
                        printf("-1\n");
                  else
                        dijkstra(p,0,0,n);
                        //printf("0\n");
                }
                else
                    dijkstra(p,c1,c2,n); // mando pra função o indice das duas cidades, para procurar no vetor distância

                c1=c2=key=-1;
                sizeno=0;
            }
            free(p);
        }
        //system("pause");
        return 0;
    }
/*
2
4
gdansk
2
2 1
3 3
bydgoszcz
3
1 1
3 1
4 4
torun
3
1 3
2 1
4 1
warszawa
2
2 4
3 1
2
gdansk warszawa
bydgoszcz buique

4
gdansk
2
2 1
3 3
bydgoszcz
3
1 1
3 1
4 4
torun
3
1 3
2 1
4 1
warszawa
2
2 4
3 1
2
bgdansk warszawa
bydgoszcz buique
*/
