#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void debugar(int arr[],int N){
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


void avaliar(int quantia,int moedas_disp[],int N){
    // array coins diz a quantidade de moedas utilizadas
    // array use diz a 1ªmoeda a usar para obter o mínimo de moedas para fazer a quantia i

    int coins[quantia+1],use[quantia+1],aux=0;
    coins[0] = 0; //não há nenhuma moeda que satisfaça o valor de 0
    use[0] = -1;
    
    for(int i=1;i<=quantia;i++){ //percorrer todos os i's até a quantidade que pretendemos
        int min = 1000; // nº grande para que consiga comparar e obter sempre a menor quantidade de moedas possíveis para fazer cada quantia
        for(int j=0;moedas_disp[j]<=i && j<N;j++){ //percorrer o array das moedas disponiveis até à moeda inferior ou igual a i e só pode percorrer o tamanho do array de moedas disponíveis
            if(moedas_disp[j] == i){ // quando existe aquela moeda nas moedas disponíveis
                coins[i] = 1;
                use[i] = moedas_disp[j];
            }
            else{
                aux = i - moedas_disp[j];
                int candidato = coins[aux] + 1; // quantidade de moedas necessárias para fazer aux + 1 que é a moeda que estamos a usar no momento
                if (candidato < min){ // entra aqui se o valor candidato for inferior ao valor atual do coins[i]
                    min = candidato; 
                    coins[i] = candidato;
                    use[i] = moedas_disp[j];
                }
            }
        }

    }
    /*cout << "coins: ";
    debugar(coins,quantia+1);
    cout << "use: ";
    debugar(use,quantia+1);*/


    cout << quantia << ": [" << coins[quantia] << "]";
    int i = quantia;
    while(coins[i] >= 1){
        cout << " " << use[i];
        i = i - use[i];
    }
    cout << endl;
}




int main(){
    int N,M,quantia;
    cin >> N;
    int moedas_disp[N];
    for(int i=0;i<N;i++){
        cin >> moedas_disp[i];
    }
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> quantia;
        avaliar(quantia,moedas_disp,N);
    }
    return 0;
}