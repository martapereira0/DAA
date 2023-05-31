#include <iostream>
#include <algorithm>
using namespace std;

bool avaliar(int value,int arr[], int N,int k){
    int c = 0; // contar o nº de partções necessárias 
    int soma = 0; //somar nºs para definir cada partição
    
    for(int i=0;i<N;i++){
        soma = soma + arr[i];
        if(arr[i] > value) return false; // é impossível fazer uma partição com um número apenas que é maior que o value
        if (soma > value){
            c++; // quer dizer que é uma partição
            soma = arr[i]; //resetar a soma para a nova partição
        }
        //cout << "soma: " << soma << " c: " << c << endl;
    }
    c++;
    if (c <= k) return true; // se é possível dividir o segmento em c partições sendo c < k, então também é possível dividir em k
    return false;
}


int bsearch(int low,int high,int arr[], int N,int k){
    while (low < high){
        int middle = low + (high - low) / 2;
        if (avaliar(middle,arr,N,k)==true) { // se para aquele valor é possível fazer as k partições, então para os valores superiores a ele também é, logo intyeressa-nos avaliar para os números inferiores
            high = middle;
        }
        else low = middle + 1;
    }
    if (!avaliar(low,arr,N,k)) return -1;
    else return low;
}

int main(){
    int N,nparticoes,sum=0,k;
    cin >> N;
    int arr[N];
    for(int i = 0;i < N; i++){
        cin >> arr[i];
        sum = sum + arr[i];
    }
    cin >> nparticoes;
    for(int i=0;i<nparticoes;i++){
        cin >> k;
        cout << bsearch(1,sum,arr,N,k) << endl;
    }
    return 0;
}