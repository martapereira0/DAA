// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao limpa no final a memoria criada - a cada "new" deve corresponder um "delete")

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos
  vector<vector<int>> matriz;  //matriz com todas as distancias

  Graph(int n) { // Constructor: chamado quando um objeto Graph for criado
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
    matriz.resize(n+1,vector<int>(n+1)); 
  }

  ~Graph() { // Destructor: chamado quando um objeto Graph for destruido
    delete[] nodes;
  }

  void addLink(int a, int b) {
    nodes[a].adj.push_back(b);
    nodes[b].adj.push_back(a);
  }
  
  void bfs(int v) {
    list<int> q;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    
    q.push_back(v); // adicionar v ao final da lista
    nodes[v].visited = true;
    nodes[v].distance = 0;

    while (q.size() > 0) {
      int u = q.front(); q.pop_front(); // retirar primeiro elemento da lista
      // cout << u << " [dist=" << nodes[u].distance << "]" << endl;
      for (auto w : nodes[u].adj)
        if (!nodes[w].visited) {
          q.push_back(w);
          nodes[w].visited  = true;
          matriz[v][w] = matriz[v][u] + 1;
        }
    }
  }

  int excentricidade(int v){
    int exce=0;
    for(int i=1;i<=n;i++){
      if(matriz[i][v] > exce) exce = matriz[i][v];
    }
    return exce;
  } 
};

int main() {
  int n, e, a, b,d=0,r=5000;
  list <int> centrais;
  list <int> perifericos;
  cin >> n;
  Graph g(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b;
    g.addLink(a, b);
  }

  // Pesquisa em largura 
  for(int i=1;i<=n;i++) g.bfs(i);
  //g.imprimirMatriz();
  for(int i=1;i<=n;i++){
    int exc = g.excentricidade(i);
    if(exc > d) d = exc;
    if(exc < r) r = exc;
  }
  for(int i=1;i<=n;i++){
    int exc = g.excentricidade(i);
    if(exc == d) centrais.push_back(i);
    if(exc == r) perifericos.push_back(i);
  }

  cout << d << endl << r << endl;
  int in=0,j=0;

  for(auto i : perifericos){
    if(j==0){
      cout << i;
      j++;
    }
    else cout << " " << i;
    
  }
  cout << endl;

  for(auto i : centrais){
    if(in==0){
      cout << i; in++;
    }
    else cout << " " << i;
  }
  cout << endl;
  
  return 0;
}
