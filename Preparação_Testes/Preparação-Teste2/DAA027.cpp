#include <iostream>
#include <cstring>

#define MAX 500      // Maximo numero de nos


using namespace std;

int nodes,edges;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias
bool visited[MAX];  // Que nos ja foram visitados?
int collored[MAX]; // array que vai conter em cada posição x a cor do nó x

bool dfs(int v,int colour) {
    visited[v] = true;
    collored[v] = colour;
    for(int i=1;i<=nodes;i++){
        if(adj[v][i]){ // sṍ vamos verificar cores em ligações que existem
            if(visited[i]){
                if (collored[i] == collored[v]) return false; // se a cor do filho for igual à do pai
            }    
            else{
                return true && dfs(i,!colour);
            }
        }    
    }
    return true;
}

int main() {
  int N, a, b;

  cin >> N;
  for (int i=0; i<N; i++) {
    memset(visited,0,sizeof(visited)); // inicializar o vetor visited a false sempre que há um novo caso para avaliar
    memset(adj,0,sizeof(adj)); // inicializar o vetor adj a false sempre que há um novo caso para avaliar
    memset(collored,0,sizeof(collored)); // inicializar o vetor filled a false sempre que há um novo caso para avaliar 
    cin >> nodes;
    cin >> edges;
    for(int j=0;j<edges;j++){
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }
    if(dfs(1,1)){
        cout << "sim" << endl;
    }
    else{
        cout << "nao" << endl;
    }
  }
  return 0;
}
