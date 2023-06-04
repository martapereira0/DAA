#include <iostream>
#include <list>
#include <vector>

#define MAX 27 

using namespace std;

int n;              // Numero de nos do grafo
bool adj[MAX][MAX]; // Matriz de adjacencias, indica se existe ligação entre um nó x e um nó y
bool visited[MAX];  // Que nos ja foram visitados?
list <char> ordem;

void dfs(int v) {
    visited[v] = true;
    for (int i=0; i<MAX; i++){
        if (adj[v][i] && !visited[i]){
            dfs(i);
        }
    }  
    ordem.push_front(v + 'A');  
    //char car = v + 'A';
    //cout << "dfs(" << car << ")" << endl;
}

int main() {
  int n_words;
  string word,f_word,s_word;

  cin >> n_words;
  cin >> f_word;
  for (int i=0; i<n_words; i++) {
    cin >> s_word;
    int len_f = f_word.size();
    int len_s = s_word.size();
    for(int j=0;j<len_f && j<len_s;j++){
        int letter_f = f_word[j] - 'A'; // para indices
        int letter_s = s_word[j] - 'A';
        if(letter_f != letter_s){
            adj[letter_f][letter_s] = true;
            break; // a primeira letra de cada palavra é diferente logo já sabemos a "ordem" das mesmas
        }
    }
    f_word = s_word;
  }

  for(int i=0;i<MAX;i++) visited[i]=false; //marcar todos os nós como **não visitados**
  
  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
        if(!visited[i] && adj[i][j]){
            dfs(i);
        }
    }
  }
  for(auto i : ordem){
    cout << i;
  }
  
  cout << endl;
  
  return 0;
}



