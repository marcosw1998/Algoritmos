#include <string>
//não utilizar biblioteca pronta para lista, já aprenderam, implementem
#include <list>
#include <cstdio>
#include <iostream>

using namespace std;

bool empty();
void push(list <int> values);
list<int> pop();

//crio um nó com uma lista de valores e um ponteiro pro próximo como "atributos"
struct node{
	list <int> values;
	node *next;
};

//vai ser o topo da minha pilha de nós
node *top;

int main(){
	string s;
	int k;
	//enquanto existir string, ele lê e armazena em s
	while(cin >> s){
		list<int> values;
		if(s == "PUSH"){
			//enquanto existir inteiros, ele coloca o inteiro em k, 
			//e joga no final da lista 
			while(scanf("%d",&k)==1){
				values.push_back(k);
			}
			//vai colocar um novo nó na pilha, com a lista de valores
			push(values);
		}
		else if(s == "POP"){
			//cout, imprime comando na tela em c++, endl pula uma linha 
			if(empty()) cout << "EMPTY STACK" << endl;
			else{
				//minha função pop retorna uma lista
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
	node *n = new node;//crio um novo nó
	
	//coloco a lista de valores que quero adicionar na lista que o nó possui
	n->values = values;
	
	n->next = top;//o próximo dele vai ser o "antigo" topo
	top = n;//o novo nó se torna o topo
}

//no remover da pilha sai o último a entrar, ou seja o topo(LIFO)
list<int> pop(){
	list<int> ret = top->values; //pego a lista de ints do topo
	node *n = top; //igualo um nó ao topo, para deletá-lo
	top = n->next; //o topo vira o nó anterior ao top (o next do topo)
	delete(n); //deleto o antigo topo
	return ret; //retorno a lista
}
bool empty(){
	if(top == NULL) return true;
	return false;
}