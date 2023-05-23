// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao limpa no final a memoria criada - a cada "new" deve corresponder um "delete")

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

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
  Node *nodes;    // Array para conter os nos, é do tipo Node ou seja tem uma lista de adj, um valor booleano e a distancia daquele nó ao nó origem da pesquisa
  vector<vector<int>> matrix;  // Matriz das distãncias de cada nó do grafo

  Graph(int n) { // Constructor: chamado quando um objeto Graph for criado
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
    matrix.resize(n + 1, vector<int>(n + 1));
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
    
    q.push_back(v); 
    nodes[v].visited = true;
    matrix[v][v]= 0;

    while (q.size() > 0) {
      int u = q.front(); 
      q.pop_front(); 
      for (auto w : nodes[u].adj)
        if (!nodes[w].visited) {
          q.push_back(w);
          nodes[w].visited  = true;
          matrix[v][w] = matrix[v][u] + 1; 	  
        }
    }
  }
  int excentricidade(int no){ // determinar a excentricidade de cada nó
    int maximum=0;
    for(int i=1;i<=n;i++){
      if(matrix[i][no] > maximum){
        maximum = matrix[i][no];
      }
    }
    return maximum;
  }
};

int main() {
  int n, e, a, b, d, r;
  
  cin >> n;
  list<int> central;
  list<int> periferico;

  Graph g(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b;
    g.addLink(a, b);
  }

  // Pesquisa em largura a partir do no 1
  for(int i=1;i<=n;i++){
    g.bfs(i); // fazer o bfs em todos os nós do grafo
  }
  for(int i=1;i<=n;i++){
    if (g.excentricidade(i) > d) d = g.excentricidade(i);
    if (g.excentricidade(i) < r) r = g.excentricidade(i);
  }
  for(int i=1;i<=n;i++){
    if (g.excentricidade(i) == d) periferico.push_back(i);
    if (g.excentricidade(i) == r) central.push_back(i);
  }
  
  cout << d << endl << r << endl;
  int ol = 0;
  for (int i : central) {
      if (ol == 0)
          cout << i;
      else
          cout << " " << i;
      ol = 1;
  }
  cout << endl;
  ol = 0;
  for (int i : periferico) {
      if (ol == 0)
          cout << i;
      else
          cout << " " << i;
      ol = 1;
  }
  cout << endl;
  return 0;
}
