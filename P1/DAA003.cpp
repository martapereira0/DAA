#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>
using namespace std;

int geracao(string m){ //determinar a que geração a matricula pertence
  if (isalpha(m[0])){
    if (isdigit(m[6])) { // 1ªgeração
      return 1;
    }
    else{ //4ªgeração
      return 4;
    }
  }
  else{
    if (isalpha(m[6])){
      return 2; //2ªgeração
    }
    else{
      return 3;
    }
  }
  return 0;
}
//calcular a quantidade de matriculas anteriores a uma geração
int quantmatriculasantes(int g){ 
  int q = 23 * 23 * 10 * 10 * 10 * 10;
  if (g==1){ 
    return 0; //geraçao 1 nao tem matriculas antes
  }
  else if (g==2){
    return q; // geracao 2 tem as matriculas da geracao 1
  }
  else if (g==3){
    return 2*q; //geracao 3 tem as matriculas da gercao 1 e 2
  }
  else{
    return 3*q; //geracao 4 tem as matriculas da geracao 1 2 e 3
  }
}

//calcular a quantidade de matriculas desde o inicio da geração até à matricula atual
int quantmatriculasdentro(string matricula){
  int num = 0; //numero da matricula
  int base = 1;
  for(int i=7;i>=0;i--){
    if (isdigit(matricula[i])){
      int numero = matricula[i] - '0'; // a função stoi converte uma string num int
      num += numero * base;
      base *= 10;
    }
  }
  for(int i=7;i>=0;i--){
    if (isalpha(matricula[i])){
      int letra = matricula[i] - 'A';
      if (matricula[i]>'K'){
        letra--; //retirar o valor do 'K'
      }
      if (matricula[i]>'W'){
        letra--; //retirar o valor do 'W'
      }
      if (matricula[i]>'Y'){
        letra--; //retirar o valor do 'Y'
      }
      num += letra * base;
      base *= 23;
    }
  }
  return num;
}


int main(){
  int T;
  string mat1,mat2;
  int g1,g2;
  cin >> T;
  for(int i=0;i<T;i++){
    cin >> mat1 >> mat2;
    g1=geracao(mat1); // descobrir a qual geração a 1ª matricula pertence
    g2=geracao(mat2); //descobrir a qual geração a 2ª matricula pertence
    int dif = abs((quantmatriculasantes(g1) + quantmatriculasdentro(mat1)) - (quantmatriculasantes(g2)+ quantmatriculasdentro(mat2)));
    cout << dif << endl;
  }
}
