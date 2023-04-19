#include <iostream>
using namespace std;

int main(){
  int N,x,counter=0;
  cin >> N; //ler o valor de N do utilizador
  for (int i=0;i<N;i++){
    cin >> x;
    if (x==42){
      counter++;
    }
  }
  cout << counter << endl;
}
