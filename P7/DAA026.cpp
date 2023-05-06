#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

// variáveis globais 

#define MAX 110
#define CARD '#'

int rows,cols;
int max_local,max_global;
char m[MAX][MAX];
bool visited[MAX][MAX];



void dfs(int y,int x){
    // verificar se a célula está numa posição válida da matriz
    if(y<0 || y >= rows || x<0 || x >= cols) return;
    // se aquela célula já tiver sida visitada ou então se não for "#", nãos nos interessa analisá-la
    if(visited[y][x] || m[y][x] != CARD) return;
    visited[y][x] = true;
    max_local++;
    dfs(y+1,x);
    dfs(y-1,x);
    dfs(y,x+1);
    dfs(y,x-1);
    dfs(y-1,x-1);
    dfs(y+1,x-1);
    dfs(y-1,x+1);
    dfs(y+1,x+1);
}


int main(){
    int quantidade;
    cin >> quantidade;
    for(int i=0 ; i<quantidade; i++){
        memset(visited,false,sizeof(visited)); // inicializar o vetor visited a false sempre que há um novo caso para avaliar
        bool visited[MAX][MAX];
        max_global=0,max_local=0;
        cin >> rows >> cols;
        for(int j=0; j<rows; j++){
            cin >> m[j];
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(m[i][j] == CARD && !visited[i][j]){
                    dfs(i,j);
                    if(max_local > max_global){
                        max_global = max_local;
                    }
                    max_local=0;

                }
            }
        }
        cout << max_global << endl;
    }
}