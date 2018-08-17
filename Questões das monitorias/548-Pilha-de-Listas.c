#include <string>
//n�o utilizar biblioteca pronta para lista, j� aprenderam, implementem
#include <list>
#include <cstdio>
#include <iostream>

using namespace std;

bool empty();
void push(list <int> values);
list<int> pop();

//crio um n� com uma lista de valores e um ponteiro pro pr�ximo como "atributos"
struct node{
	list <int> values;
	node *next;
};

//vai ser o topo da minha pilha de n�s
node *top;

int main(){
	string s;
	int k;
	//enquanto existir string, ele l� e armazena em s
	while(cin >> s){
		list<int> values;
		if(s == "PUSH"){
			//enquanto existir inteiros, ele coloca o inteiro em k, 
			//e joga no final da lista 
			while(scanf("%d",&k)==1){
				values.push_back(k);
			}
			//vai colocar um novo n� na pilha, com a lista de valores
			push(values);
		}
		else if(s == "POP"){
			//cout, imprime comando na tela em c++, endl pula uma linha 
			if(empty()) cout << "EMPTY STACK" << endl;
			else{
				//minha fun��o pop retorna uma lista
				list<int> que = pop();
				while(!que.empty()){
					int c = que.front();//pega o primeiro inteiro da lista
					que.pop_front();//retira o inteiro da lista
					cout << c;
					if(que.size() > 0) cout << " ";
				}
				cout << endl;
			}
		}
	}
	
	return 0;
}
void push(list <int> values){
	node *n = new node;//crio um novo n�
	
	//coloco a lista de valores que quero adicionar na lista que o n� possui
	n->values = values;
	
	n->next = top;//o pr�ximo dele vai ser o "antigo" topo
	top = n;//o novo n� se torna o topo
}

//no remover da pilha sai o �ltimo a entrar, ou seja o topo(LIFO)
list<int> pop(){
	list<int> ret = top->values; //pego a lista de ints do topo
	node *n = top; //igualo um n� ao topo, para delet�-lo
	top = n->next; //o topo vira o n� anterior ao top (o next do topo)
	delete(n); //deleto o antigo topo
	return ret; //retorno a lista
}
bool empty(){
	if(top == NULL) return true;
	return false;
}