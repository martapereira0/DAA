#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortFunc(const vector<float>& v1,const vector<float>& v2){
    if (v1[0] == v2[0]) return v1[1] < v2[1]; // se ambos os vetores tiverem o mesmo valor de racio o primeiro é o que tem menor indice
    return v1[0] > v2[0];
}

int main() {
    int N;
    float dur,multa,racio,nencomenda=1;
    vector<vector<float>> vec; // vetor que vai conter vetores 
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> dur >> multa;
        racio = multa/dur;
        vector<float> vec_aux {racio,nencomenda}; // cada sub-vetor do vetor principal tem 2 elementos, o valor do racio e o nº da encomenda
        vec.push_back(vec_aux);
        nencomenda++;
    }
    // a função sort tem como ultimo parametro opcional uma condicao que é a forma como queremos ordenar, por default ordena por forma crescente
    sort(vec.begin(),vec.end(),sortFunc); // ordenar o vetor de acordo com a nossa função sortFunc
    for(int i=0;i<N;i++){
        if (i<N-1) cout << vec[i][1] << " ";
        else cout << vec[i][1];
    }
    cout << endl;
}