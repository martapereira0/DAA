#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct {
  char letra;
  int freq;
  int firstappear;
} DNA;

struct compareDNA {
  bool operator()(const DNA & p1, const DNA & p2) {
    if (p1.freq > p2.freq) return true;
    if (p1.freq < p2.freq) return false;
    if (p1.firstappear < p2.firstappear) return true;
    if (p1.firstappear > p2.firstappear) return false;


    return false;
  }
};

int main(){
    string dna;

    cin >> dna;

    DNA array[26]; 
    
    for (int i=0;i<26;i++){ 
        array[i].letra='A' + i; 
        array[i].freq=0;
    }

    int len = dna.size(); 
    
    for (int i=0; i<len; i++){
      int pos = dna[i] - 'A';
      if (array[pos].freq == 0){
        array[pos].firstappear = i; //guardar a posição em que cada letra ocorre pela 1ª vez
      }
      array[pos].freq++; // aumentar frequencias
    }

    sort(array, array + 26, compareDNA()); 

    for (int i=0; i<26; i++){
        if (array[i].freq != 0){
          cout << array[i].letra << " " << array[i].freq << endl;
        }
    }
    return 0;
}