#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long auxiliar(vector<vector<long long>> piramide,int len){
    //percorrer a piramide de baixo para cima
    if (len == 1){ // se a piramide for apenas um bloco
        if(piramide[0][0] == 0) return 0;
        return 1;
    }
    else if(piramide[0][0] == 0) return 0; // se a peça no topo da piramide está estragda, não há nenhum caminho possível para lá
    else{
        for(int i=len-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                if(piramide[i][j] == -1){
                    if(i == len-1){
                        piramide[i][j] = 1;
                    }
                    else{
                        piramide[i][j] = piramide[i+1][j] + piramide[i+1][j+1];
                    }
                }
            }
            if (i == 0) piramide[i][0] = piramide[i+1][0] + piramide[i+1][1];
        }
        return piramide[0][0];
    }
}




int main(){
    int ncamadas,npedrasmas;
    cin >> ncamadas;
    cin >> npedrasmas;

    //piramide representado por uma matriz quadrada de vetores incialmente inicializada toda a -1's
    vector <vector<long long>> piramide(ncamadas,vector<long long>(ncamadas,-1)); 
    int camada,posicao;
    for(int i=0;i<npedrasmas;i++){
        cin >> camada >> posicao;
        piramide[ncamadas - camada][posicao-1] = 0; // fica indisponível
    }
    cout << auxiliar(piramide,ncamadas) << endl;
}