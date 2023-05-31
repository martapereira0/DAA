#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool calcular(int arr[],int N,int k,int middle){
    int nparticoes = 0,soma = 0;
    for(int i = 0; i < N ;i++){
        if (arr[i] > middle) return false; // não é possível fazer partições quando um valor é superior ao valor do middle

        if (soma + arr[i] > middle){
            nparticoes++;
            soma = arr[i];
        }
        else{
            soma = soma + arr[i];
        }

    }
    nparticoes++; //adicionar a última partição
    if (nparticoes <= k) return true;
    return false;
}

int bsearch(int low, int high,int arr[],int N,int k){
    while (low < high){
        int middle = low + (high - low) / 2;
        if (calcular(arr,N,k,middle)) high = middle;
        else{
            low = middle + 1;
        }
    }
    return low;
}



int main(){
    int N,M,k,sum=0;
    cin >> N;
    int arr[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
        sum = sum + arr[i];
    }
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> k;
        cout << bsearch(0,sum,arr,N,k) << endl;

    }
    return 0;
}