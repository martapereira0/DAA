// Codigo inicial para o problema [DAA 022] Arvores Red-Black
// Pedro Ribeiro (DCC/FCUP)

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

// Estrutura para representar um no da arvore
typedef struct node {
  bool isBlack; // No preto?
  bool isNull;  // No nulo?
  int value;    // Valor
  struct node *left, *right; // Filhos
} *Node;

// Criar um no a partir de um numero
Node mkNode(int v) {
  Node aux = (Node)malloc(sizeof(struct node));
  aux->isNull  = (v==0);
  aux->isBlack = (v>=0);
  aux->value   = abs(v);
  return aux;
}

// Ler input em preorder
Node readPreOrder() {
  int v;
  cin >> v;
  Node aux = mkNode(v);
  if (v!=0) {
    aux->left  = readPreOrder();
    aux->right = readPreOrder();
  }
  return aux;
}

// Menor valor da arvore
int minimum(Node t) {
  if (t->isNull) return INT_MAX;
  int minLeft  = minimum(t->left);
  int minRight = minimum(t->right);
  return min(t->value, min(minLeft, minRight));
}

// Maior valor da arvore
int maximum(Node t) {
  if (t->isNull) return INT_MIN;
  int maxLeft  = maximum(t->left);
  int maxRight = maximum(t->right);
  return max(t->value, max(maxLeft, maxRight));
}

// Quantidade de nos (internos)
int size(Node t) {
  if (t->isNull) return 0;
  return 1 + size(t->left) + size(t->right);
}

// ---------------------------------------------------

// verificar se a raíz da árvore é preta
bool rootproperty(Node t){ 
  if (!t->isBlack) return false;
  return true;
}

// men -> identifica que estamos a avaliar a sub-arvore da esquerda
// mai -> identifica que estamos a avaliar a sub-arvore da direita
// verifica se respeita a BSTree property
bool isBSTree(Node t,int min, int max){
  if (t->isNull) return true;
  if (t->value > max || t->value < min) return false;
  return isBSTree(t->left,min,t->value-1) && isBSTree(t->right,t->value+1,max);
}

// verifica se respeita a Red property
bool redproperty(Node t){ 
  if (t->isNull) return true; // é uma folha logo tem de ser preta
  if ((!t->isBlack && !t->left->isNull && !t->left->isBlack) || (!t->isBlack && !t->right->isNull && !t->right->isBlack)) return false; 
  return redproperty(t->left) && redproperty(t->right); 
}

// verificar se todos os elementos do vetor são iguais, se sim então a árvore respeita à black property

bool allEqual(vector<int> const &v) {
    return adjacent_find(v.begin(), v.end(), std::not_equal_to<int>()) == v.end();
}


// guardar a quantidade de nós pretos de cada caminho num vector (pois não precisamos de definir o tamanho dele uma vez que não sabemos o tamanho do mesmo)
bool count_black_pieces(Node t,int c, vector<int>& vetor){
  if (t->isNull){
    vetor.push_back(c); // é uma folha logo tem de ser preta
    return true;
  }
  if (t->isBlack){
    c++; 
    //cout << "no preto: " << t->value << endl;
  }

  count_black_pieces(t->left,c,vetor);
  count_black_pieces(t->right,c,vetor); 

  if (allEqual(vetor)) return true;
  return false;
}


int main() {
  int i, n;

  cin >> n;
  for (i=0; i<n; i++) {
    Node root = readPreOrder();
    vector<int> vetor;
    if (count_black_pieces(root,0,vetor) && isBSTree(root,INT_MIN,INT_MAX) && rootproperty(root) && redproperty(root)) cout << "SIM" << endl ;
    else cout << "NAO" << endl ;
    //cout << "---------------------------" << endl;
  }
  return 0;
}
