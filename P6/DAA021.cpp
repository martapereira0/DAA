#include <iostream>
#include <set>
using namespace std;




int main(){
    int A,R;
    string str;
    cin >> A >> R;
    int total = A + R,energia;
    multiset<int> s;
    for(int i=0; i<total; i++){
        cin >> str;
        if (str == "BAK"){
            cin >> energia;
            s.insert(energia);
        }
        // se nao quiser usar o auto tenho de fazer multiset:: qql coisa

        else if(str == "MIN"){
            auto it = s.begin(); // it é como se fosse a posiçao
            cout << *it << endl; // *it é o iterador, acede ao conteúdo
            s.erase(it); // eliminar o conteudo daquela posição
            // se fizesse s.erase(*it) iria remover todos os "nos" com aquele valor e nós não queremos isso
            
            
            // s.rend() aponta para a ultima posição num multiset inverso ou seja para a posição anterior à primeira e como estamos em reverse temos de fazer it--
            //auto it = s.rend(); // aceder ao primeiro elemento do multiset inverso que equivale ao ultimo elemento do multiset inicial
            //it--;
            //cout << *it << endl;
            //s.erase(it); não é possível apagar elementos numa estrutura reverse, logo nao é possivel fazer erase o mesmo para rbegin() que aponta para o primeiro elemento do multiset inverso ou seja para o ultimo do multiset original
        
        }
        else{
            auto it = s.end(); // apontar para a posiço exatamente a seguir à ultima
            it--; // aceder à penultima posição
            cout << *it << endl;
            s.erase(it);

        }
        //cout << "conteudo: ";
        //for(auto i : s){
            //cout << i << " ";
        //}
        //cout << endl;
        
    }
    return 0;
}