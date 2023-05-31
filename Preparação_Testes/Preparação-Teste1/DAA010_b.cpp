#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int bsearch(int low,int high,int value,int somas[]){
    while(low < high){
        int middle = low + (high-low)/2;
        if(somas[middle] == value) return middle;
        else if(somas[middle] > value) high = middle; // o hugo tinha razão
        else low = middle + 1;
    }
    return low;
}


int procurar(int somas[],int N,int valor){
    int aux = bsearch(0,N,valor,somas);
    if(somas[aux] == valor) cout << valor << endl;
    else{
        //caso o valor a procurar seja menor que o 1º elemento das somas ou maior que o último elemento das somas
        if((aux == 0 && valor < somas[0]) || (aux == N && valor > somas[N])){
            cout << somas[aux] << endl;
            return 0;
        }
        //caso o valor a procurar esteja entre algum dos valores do array das somas
        else{
            int auxx = aux - 1;
            int dif1 = 0,dif2 = 0;
            dif1 = valor - somas[auxx];
            dif2 = somas[aux] - valor;
            if(dif1 == dif2) cout << somas[auxx] << " " << somas[aux] << endl;
            else if(dif1 < dif2) cout << somas[auxx] << endl;
            else cout << somas[aux] << endl;
        }
    }
    return 0;
}


int main(){
    int N,Q,valor;

    cin >> N;

    int arr[N];

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int somas[N*(N-1)/2],index=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            somas[index] = arr[i] + arr[j];
            index++;
        }
    }

    sort(somas,somas+N*(N-1)/2);

    cin >> Q;
    for(int j=0;j<Q;j++){
        cin >> valor;
        procurar(somas,(N*(N-1)/2)-1,valor);
    }

    return 0;
}