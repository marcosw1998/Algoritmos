//Inserção em AVL

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int valor;
    int balance;
    struct arvore *dir;
    struct arvore *esq;
}arv;
typedef struct ret
{
    int change;
    struct arvore *ptr;
}ret;

arv **root_gbl;
int contu=0,contpri=0;

arv *aloca(arv *no,int x)
{
    no = (arv*) malloc(sizeof(arv));
    no->balance= 0;
    no->dir = NULL;
    no->esq = NULL;
    no->valor = x;
    return no;
}
arv* rotesq(arv *root)
{
    contu++;
    arv *r;
    arv *rl;
    r = root->dir;
    rl = r->esq;
    r->esq = root;
    root->dir = rl;
    if (r->balance > 0)
    {
        root->balance = root->balance -1 - r->balance;
    }
    else
        root->balance = root->balance-1;
    if(root->balance<0)
    {
        r->balance = r->balance -1 + root->balance;
    }
    else
        r->balance = r->balance -1;
    return r;
}
arv* rotdir(arv *root)
{
    contu++;
    arv *r;
    arv *rr;
    r = root->esq;
    rr = r->dir;
    r->dir = root;
    root->esq = rr;
    if (r->balance < 0)
    {
        root->balance = root->balance+1-r->balance;
    }
    else
        root-> balance = root->balance + 1;
        if(root->balance>0)
        {
            r->balance = r->balance +1 + root->balance;
        }
            else
                r->balance = r->balance +1;
    return r;
}
ret *insere(arv *root,int x) // provavel erro na rotação
{
    ret *fim;
    fim = NULL;
    arv *no;
    int ch; //Caso a altura tenha sido alterada

    if(root == NULL)
    {
        fim = (ret*) malloc (sizeof(ret));
        no = aloca(no,x);

        fim->change = 1;
        fim->ptr = no;

        return fim;
    }
        else if(x < root->valor )
        {
            fim = insere(root->esq,x);
            root->esq = fim->ptr; // pode ser que seja "root->left"
            ch = fim->change;
            root->balance= root->balance - ch;
        }
        else if(x >= root->valor)
        {
            fim = insere(root->dir,x);
            root->dir = fim->ptr;
            ch = fim->change;
            root->balance= root->balance + ch;
        }

    if(ch == 0)     
    {
        fim->ptr= root;
        fim->change = 0;
       
        return fim;
    }
        else if(root->balance == 0)
        {
            fim->change = 0;
            fim->ptr = root;
         
            return fim;
        }

        else if((root->balance == 1 || root->balance == -1))
        {
            fim->ptr = root;
            fim->change = 1;
    
           return fim;
        }
        else if(root->balance == -2)
        {
            printf("Antes de ajustar balanceamento...\n");
            contpri=0;
            pri(*root_gbl); //root
            printf("\n");
            if(root->esq->balance == 1)
            {
         
                root->esq = rotesq(root->esq);
            }
            fim->ptr =  rotdir(root);
            fim->change = 0;
   
            return fim;
        }
        else if(root->balance == 2)
        {
            printf("Antes de ajustar balanceamento...\n");
            contpri=0;
            pri(*root_gbl);//root
            printf("\n");
            if(root->dir->balance == -1)
            {
                root->dir = rotdir(root->dir);
            }
            fim->change = 0;
            fim->ptr = rotesq(root);
            return fim;
        }
}
void pri(arv *root)
{

    if( root != NULL)
    {
        if(contpri==0)
        {
            printf("  ");
        }
	    contpri++;
        printf(" ( %d ",root->valor);
        if(root->esq == NULL) printf(" () ");  //parantêses pois se for nulo substituem o elemento
		//se o nó à esquerda não for nulo, imprimirei a partir dele
		else pri(root->esq);
		if(root->dir == NULL)
            printf(" () ");  //parantêses pois se for nulo substituem o elemento
            else pri(root->dir);//se o nó à direita não for nulo, imprimirei a partir dele
		printf(") ");
    }
}

int main()
{
    int x;
    arv *root;
    ret *result;
    result= NULL;
    root = NULL;
    root_gbl= &root;

    while(scanf("%d",&x) ==1)
    {
        if (root == NULL) // caso o elemento = raíz, a raiz apota pra ela msm
        {
            printf("\n----\n");
            printf("Adicionando %d\nContinuou AVL...\n",x);
            root = aloca(root,x);
            root_gbl = root;
            contpri=0;
            pri(root);
            printf("\n----\n");
        }
            else
            {
                printf("Adicionando %d\n",x);
                result = insere(root,x);
                root= result->ptr;
                root_gbl= &root;
                
                if(contu==0)
                {
                    printf("Continuou AVL...\n");
                    contpri=0;
                    pri(root);
                    printf("\n----\n");    
                }
                else
                {
                    printf("Depois de ajustar balanceamento...\n");
                    contpri=0;
                    pri(root);
                    printf("\n----\n");
                    contu = 0;
                }
            }
    }
    return 0;
}
