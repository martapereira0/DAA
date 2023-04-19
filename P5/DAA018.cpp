#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void avaliar(int quantia,int moedas_disp[],int n_moedas){
    // array coins diz a quantidade de moedas utilizadas
    // array use diz a 1ªmoeda a usar para obter o mínimo de moedas para fazer a quantia i
    int coins[quantia+1],use[quantia+1],res = 0;
    coins[0] = 0;
    use[0] = -1;
    for(int i = 1; i <= quantia; i++){ //percorrer todos os i's até a quantidade que pretendemos
        int k = 0; // percorrer array das moedas disponíveis
        int min = 10000; // nº grande para que consiga comparar e obter sempre a menor quantidade de moedas possíveis para fazer cada quantia
        while (moedas_disp[k] <= i && k < n_moedas){
            if (moedas_disp[k] == i){ // quando existe aquela moeda nas moedas disponíveis
                coins[i] = 1;
                use[i] = moedas_disp[k];
            }
            else{
                res = i - moedas_disp[k];
                int candidato = coins[res] + 1; // quantidade de moedas necessárias para fazer aux + 1 que é a moeda que estamos a usar no momento
                if (candidato < min) { // entra aqui se o valor candidato for inferior ao valor atual do coins[i]
                    min = candidato;
                    coins[i] = min;
                    use[i] = moedas_disp[k];
                }
            }
            k++;
        }
    }

    cout << quantia << ": [" << coins[quantia] << "]";
    int i = quantia;
    while (coins[i] >= 1){
        cout << " " << use[i];
        i = i - use[i];
    }
    cout << endl;
}


int main(){
    int n_moedas,n_perguntas,quantia;

    cin >> n_moedas;

    int moedas_disp[n_moedas]; // array com moedas disponíveis

    for(int i = 0; i < n_moedas; i++){
        cin >> moedas_disp[i];
    }
    cin >> n_perguntas;
    for(int i = 0; i < n_perguntas; i++){
        cin >> quantia;
        avaliar(quantia,moedas_disp,n_moedas);
    }
    return 0;
}