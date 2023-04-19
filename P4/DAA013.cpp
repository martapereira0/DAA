#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortFunc(vector<int>& a,vector<int>& b){
    if (a[0]<b[0]) return true;
    if (a[0] == b[0]){
        if(a[2]<b[2]) return true; //intervalos que comecem ao mesmo tempo são ordenados de froma crescente de acordo com a duraçaõ
    }
    return false;
}

/*void debugar(vector<vector<int>>  vec, int N){
    for(int i=0;i<N;i++){
        cout << vec[i][0] << " " << vec[i][1] << " " << vec[i][2] << endl;
    }
}*/

int main(){
    int M,N,in,f,barra=0;
    cin >> M;
    cin >> N;

    // vector<vector<int>>  vec -> para utilizar o push_back(adicionar um elmento ao vetor) não posso declarar o tamanho do vetor principal
    // se quiser declarar o tamanho do vetor principal tenho de fazer vec[i]=valor para adicionar o valor ao vetor
    
    vector<vector<int>>  vec(N); //vetor de tuplos em que cada tuplo tem o inicio o fim e a distancia do seu intervalo
    for(int i=0;i<N;i++){
        cin >> in >> f;
        vector<int> tuplo {in,f,f-in};
        vec[i]=tuplo;
    }
    sort(vec.begin(),vec.end(),sortFunc); 
    // c -> contador ; aux -> guardar o valor do fim do intervalo que contiver a maior distancia ; i -> indice para percorrer o vetor principal "vec" 
    int maiordist = 0,c=0,aux,i=0;
    while(barra < M){
        if(vec[i][0] <= barra){ // só entra aqui caso o incio do intervalo for inferior ou igual ao valor da barra atual
            if (vec[i][2] >= maiordist || vec[i][1] > aux){ //caso a distancia do atual seja superior à maior distancia até ao momento ou se o final do intervalo for superior ao final do intervalo que tem maior distância
                if (i == N-1){ // caso estejamos a anlisar o ultimo intervalo e se tenha de colocar a barra no final do mesmo, sem isto não teriamos como colocar a barra lá
                    barra = vec[i][1];
                    c++;
                }
                maiordist = vec[i][2];
                aux = vec[i][1];
                i++;
            }
            else if(i == N - 1){ // se avaliar esta condição é pq vec[i][2] < maiordist
                //se entrar aqui é pq o ultimo elemento não tem o maior intervalo
                barra = vec[i][1];
                c++;
            }
            else{
                i++;
            }
        }
        else{
            barra = aux;
            c++;
            maiordist = 0;
            //o valor do i não altera pois temos de avaliar esse mesmo intervalo para fazer o proximo segmento
        }
    }
    cout << c << endl;
    return 0;
}