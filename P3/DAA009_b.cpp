#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortFunc(vector<int>&a,vector<int>&b){
    // comparar frequencias de cada letra
    // ordenar decrescentemente o vetor de acordo com as frequencias
    if(a[1]>b[1]) return true;
    else if(a[1]<b[1]) return false;
    // se duas letras tiverem a mesma frequencia, aparece 1º a que tem menor indice,i.e, que apareceu em primeiro na string de input
    else{
        if(a[2]<b[2]) return true;
        else return false;
    }
}


int main(){
    string in; 
    vector<vector<int>> vec(26,vector<int>(3,0)); // vetor com sub-vetores em que em cada em cada sub-vetor na 1ª posição está o valor ascii da letra, na 2ª a frequencia, 3ª o índice em que essa letra surgiu pela 1ª vez

    for(int i=0;i<26;i++){
        vec[i][0]='A'+i; 
    }
    cin >> in;
    int len = in.length();
    for(int i=0;i<len;i++){
        int posi = in[i] - 'A'; // letra que estamos a avaliar da string
        if (vec[posi][1] == 0){
            vec[posi][1] = 1; // frequência passa a ser 1
            vec[posi][2] = i; //guardar o indice em que a letra apareceu pela 1ª vez na string adda como input
        }
        else{
            vec[posi][1]++; // aumenta na frequencia
        }

    }
    
    sort(vec.begin(),vec.end(),sortFunc);
    int i = 0; // percorrer vec
    while(vec[i][1]!=0 && i < 25){
        cout << char(vec[i][0]) << " " << vec[i][1] << endl;
        i++;
    }
    if(vec[i][1] != 0){
        cout << char(vec[i][0]) << " " << vec[i][1] << endl;
    }
    return 0;
}