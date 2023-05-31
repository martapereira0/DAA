// Exemplo de pesquisa em profundidade (DFS) num grafo nao dirigido

#include <iostream>
#include <cstring>

#define MAX 105      // Maximo numero de nos

using namespace std;

int rows,cols,max_local,max_global;              // Numero de nos do grafo
char adj[MAX][MAX]; 
bool visited[MAX][MAX];  // Que nos ja foram visitados?

void dfs(int line,int col) {
    //garantir que estamos dentro dos limites da matriz
    if (line < 0 || line >= rows || col < 0 || col >= cols) return;
    // se não for '#' ou se já tiver sido contabilizado
    if (adj[line][col] != '#' || visited[line][col]) return;
    max_local++;
    visited[line][col] = true;
    dfs(line+1,col);
    dfs(line+1,col+1);
    dfs(line,col+1);
    dfs(line-1,col+1);
    dfs(line-1,col);
    dfs(line-1,col-1);
    dfs(line,col-1);
    dfs(line+1,col-1);
}

int main() {
    int N;

    cin >> N;
    for(int k=0;k<N;k++){
        memset(visited,false,sizeof(visited)); // inicializar o vetor visited a false sempre que há um novo caso para avaliar
        max_local=0,max_global=0;
        cin >> rows >> cols;
        string linha;
        for(int p=0;p<rows;p++){
            cin >> adj[p];
        }  
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if (adj[i][j] == '#' && !visited[i][j]){
                    dfs(i,j);
                    if (max_local > max_global){
                        max_global = max_local;
                    }
                    max_local=0;
                }    
            }
        }
        cout << max_global << endl;
    }
    return 0;
}