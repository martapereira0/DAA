// Exemplo de aplicacao do algoritmo de Dijkstra
// (assumindo um grafo pesado e dirigido, sem pesos negativos)

#include <iostream>
#include <climits> // nº infinitamente grande para inicilizar as distancias a infinito
#include <list>
#include <set>
#include <map>

using namespace std;

// Classe que representa um no
class Node {
public:
  list<pair<int, float>> adj;  // Lista de adjacencias
  bool visited;              // No ja foi visitado?
  float distance;              // Distancia ao no origem da pesquisa
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) { // Constructor: chamado quando um objeto Graph for criado
    this->n = n;
    nodes = new Node[n+1];  // +1 se os nos comecam em 1 ao inves de 0
  }
  
  ~Graph() { // Destructor: chamado quando um objeto Graph for destruido
    delete[] nodes;
  }
  
  void addLink(int a, int b, float c) { // adicionar um par do tipo {nó,custo}
    //grafo bidirecional, logo:
    nodes[a].adj.push_back({b,c});
    nodes[b].adj.push_back({a,c}); 
  }

  // Algoritmo de Dijkstra
  float dijkstra(int s,int k) {
    
    //Inicializar nos como nao visitados e com distancia infinita
    for (int i=1; i<=n; i++) {
      nodes[i].distance = INT_MAX;
      nodes[i].visited  = false;
    }
    
    // Inicializar "fila" com no origem
    nodes[s].distance = 0;
    set<pair<int, int>> q; // By "default" um par e comparado pelo primeiro elemento 
    q.insert({0, s});      // Criar um par (dist=0, no=s)

    // Ciclo principal do Dijkstra
    while (!q.empty()) {
      
      // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
      int u = q.begin()->second; // -.begin(): aceder ao 1º par do set; > second para aceder ao 2º valor do par
      q.erase(q.begin()); // erase(): remover o 1ºpar do set
      nodes[u].visited = true; //marcar que aquele no foi visitado

      // Relaxar arestas do no retirado
      for (auto edge : nodes[u].adj) { //percorrer os nos adjacentes ao nó u
        int v = edge.first;
        float cost = edge.second;
        if (!nodes[v].visited && nodes[u].distance + cost < nodes[v].distance) {
          q.erase({nodes[v].distance, v});  // Apagar do set
          nodes[v].distance = nodes[u].distance + cost;
          q.insert({nodes[v].distance, v}); // Inserir com nova (e menor) distancia
        }
      }
    }
    return nodes[k].distance;
  }
};

int main() {
  int n, e,indice=1;
  string origem, destino, a, b;
  float dist;
  
  cin >> n >> e;
  Graph g(n);
  cin >> origem >> destino;
  map<string, int> locais; // dicionario
  for (int i=0; i<e; i++) {
    cin >> a >> b >> dist;
    // se aquele local ainda não tiver sido adicionado ao dicionário
    if(locais.find(a) == locais.end()){ 
      locais.insert({a,indice++});
    }
    if(locais.find(b) == locais.end()){
      locais.insert({b,indice++});
    }
    // locais[a] -> aceder ao indíce associado àquele local
    g.addLink(locais[a],locais[b],dist); // adicionar ao grafo o valor a que se refere aquela localidade e a distancia
  }

  // Execucao exemplo a partir do no origem
  float distancia = g.dijkstra(locais[origem],locais[destino]);
  cout << distancia << endl;

  return 0;
}

