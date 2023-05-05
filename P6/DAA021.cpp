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

        else if(str == "MIN"){
            auto it = s.begin(); // it é como se fosse a posiçao
            cout << *it << endl; // *it é o iterador, acede ao conteúdo
            s.erase(it); // eliminar o conteudo daquela posição
            
        }
        else{
            auto it = s.end(); // apontar para a posiço exatamente a seguir à ultima
            it--; // aceder à penultima posição
            cout << *it << endl;
            s.erase(it);

        }
    }
    return 0;
}
