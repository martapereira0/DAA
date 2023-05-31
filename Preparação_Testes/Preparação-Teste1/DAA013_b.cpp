#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
void debugar(vector<vector<int>> vec,int N){
    for(int i=0;i<N;i++){
        cout << vec[i][0] << " " << vec[i][1] << " " << vec[i][2] << endl;
    }
}*/

bool sortFunc(vector<int>&a,vector<int>&b){
    if(a[0]<b[0]) return true;
    else if(a[0]>b[0]) return false;
    else{
        if(a[2]<b[2]) return true;
        else return false;
    }
}



int main(){
    int M,N,in,fin,barra=0,contador=0,aux,mdist=0;

    cin >> M;

    cin >> N;

    vector<vector<int>> arr (N,vector<int>(3,0));

    for(int i=0;i<N;i++){
        cin >> in >> fin;
        vector<int> aux{in,fin,fin-in};
        arr[i]=aux;
    }
    //cout << "--------------------------------------------" << endl;
    sort(arr.begin(),arr.end(),sortFunc);
    //debugar(arr,N);

    int i=0; //indice para percorrer vetor arr
    while(barra < M){
        if (arr[i][0] <= barra && i < N){
            if (arr[i][1] > barra){
                if(arr[i][2] >= mdist || arr[i][1] > aux){
                    if(i == N - 1){
                        barra = arr[i][1];
                        contador++;
                    }
                    aux = arr[i][1];
                    mdist = arr[i][2];
                }
                else if(i == N - 1){
                    barra = aux;
                    contador++;
                }
                i++;
            }
            else{
                i++;
            }
        }
        else{
            barra = aux;
            contador ++;
            mdist = 0;
            i--;
        }
        //cout << "barra: " << barra << endl;
        
    }
    

    cout << contador << endl;
    return 0;
}