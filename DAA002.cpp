#include <iostream>
using namespace std;

int main(){
  int T,r,n,p;
  cin >> T;
  for(int i=0;i<T;i++){
    cin >> p >> n;
    int soma=0;
    while (soma!=n){
      p++;
      r=p;
      soma=0;
      while (r>0){
        soma+=r%10;
        r/=10;
      }
    }
    cout << p << endl;
  }
}
