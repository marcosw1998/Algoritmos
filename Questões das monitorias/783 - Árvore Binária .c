#include <stdio.h>
#include <stdlib.h>
 
typedef struct binary_tree_node{
	int key;
	struct binary_tree_node *left;
	struct binary_tree_node *right;
}BSTNode;
 
 
void insert(BSTNode *root, int key);
void printTree(BSTNode *node);
 
BSTNode *root; //raiz da árvore
 
int main(void) {
	int n;
	//lê um novo inteiro até eof
	while(scanf("%d", &n) == 1){
		insert(root, n); //chama o método para inserir na árvore
		printf("\n----\n");
		printf("Adicionando %d\n", n);
		printf("  ");
		printTree(root); //imprime toda a árvore
	}
	printf("\n----");
	return 0;
}
 
//nodeR recebe a root
void insert(BSTNode *nodeR, int key){
	BSTNode *currentN = nodeR;
	//se a raiz for nula, insere o elemento na raiz
	if(nodeR == NULL){ 
		nodeR = malloc(sizeof(BSTNode));
		nodeR->left = NULL;
		nodeR->right = NULL;
		nodeR->key = key;
		root = nodeR;
	}
	//se a raiz não for nula
	else{
		//preciso de um apontador para o anterior, para fazê-lo apontar para o novo elemento
		BSTNode *previous;
		//entro no while até o currentN ficar null, ou seja na folha onde preciso inserir o inteiro
		while(currentN != NULL){
			/*currentN nesse momento nunca é null, ou seja previous nunca ficará null e terá o nó
			anterior aonde irei inserir*/
			previous = currentN;
			if(key >= currentN->key)currentN = currentN->right;  //vê se dá pra inserir na direita
			else currentN = currentN->left;  //ou tenta inserir na esquerda
		}
		//ao sair do while cheguei na folha(nula) onde preciso inserir o inteiro
		currentN = malloc(sizeof(BSTNode));
		currentN->left = NULL;
		currentN->right = NULL;
		currentN->key = key;
		//mando o anterior ao novo nó apontar para ele, se key maior, sua direita, se menor a sua esquerda
		if(key >= previous->key)previous->right = currentN;
		else previous->left = currentN;
	}
}
void printTree(BSTNode *node){
	//impressão em pré-ordem
	if(node != NULL){
		//imprimo o nó "central/raiz"
		printf(" ( %d ", node->key);
		if(node->left == NULL)printf(" () ");  //parantêses pois se for nulo substituem o elemento
		//se o nó à esquerda não for nulo, imprimirei a partir dele
		else printTree(node->left);
		if(node->right == NULL)printf(" () ");  //parantêses pois se for nulo substituem o elemento
		//se o nó à direita não for nulo, imprimirei a partir dele
		else printTree(node->right);
		printf(") ");
	}
}