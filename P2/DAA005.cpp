#include <iostream>
#include <array>
using namespace std;

int main(){
    int N,F,i,f;
    cin >> N;
    array<int,200000> array,narray;
    for (int j=0;j<N;j++){
        cin >> array[j];
        if (j==0) narray[j]=array[j];
        else narray[j] = narray[j-1] + array[j];

    }
    cin >> F;
    for (int j=0;j<F;j++){
        cin >> i >> f;
        int sum = (i==1 && f==N) ? narray[f-1] : narray[f-1]-narray[i-2];
        cout << sum << '\n';
    }
    return 0;
}