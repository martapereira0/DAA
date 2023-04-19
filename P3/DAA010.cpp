#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int procurar(int high,int low, int value,int somas[],int N){
    while(low < high){ // percorrer o array enquanto low != high ou então até encontrar exatamente o valor a procurar
        int middle = low + (high - low) / 2;
        if (value > somas[middle]) low = middle + 1;
        else if(value < somas[middle]) high = middle;
        else{ //significa que o valor a procurar está no array das somas
            cout << value << endl;
            return 0;
        }
    }
    // se chegar aqui é pq o valor a procurar não existe no array
    if(low == 0 || (low == N-1 && somas[low] < value)){  // precisamos de fazer somas[low] < value caso estejamos com um caso em que o valor se encontra entre o ultimo valor e o penultimo
        // significa que ou o valor a procurar é inferior ao 1º elemento do array ou que é superior ao ultimo elemento do array
        cout << somas[low] << endl; 
        return 0;
    }
    else{
        int dif1=0,dif2=0;
        dif1 = somas[low] - value;
        dif2 = value - somas[low-1];
        if(dif1 == dif2){
            cout << somas[low-1] << " " << somas[low] << endl;
        }
        else if(dif1 > dif2){
            cout << somas[low-1] << endl;
        }
        else{
            cout << somas[low] << endl;
        }
    }
    return 0;
}

int main(){
    int N,M,p;
    cin >> N;
    int arr[N]; 
    for (int i=0;i<N;i++) cin >> arr[i];

    int aux[N*(N-1)/2],index=0; // index para definir o indice do array auxiliar para armazenar as somas 
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            aux[index]=arr[i]+arr[j];
            index++;
        }
    }
    sort(aux,aux+(N*(N-1)/2)); //ordenar array das somas

    //para aplicar pesquisa binária ao array das somas
    int high=(N*(N-1)/2)-1,low=0; // indíces 


    cin >> M;
    for (int i=0;i<M;i++){
        cin >> p; // ler o valor a procurar no array das somas
        procurar(high,low,p,aux,N*(N-1)/2);    
    }
    return 0;
}