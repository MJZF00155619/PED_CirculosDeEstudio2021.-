#include <iostream>
using namespace std;

int potencia(int x, int n){
 int p;
 if(n == 0){
  p = 1;
 }else{
  p = x * potencia(x, n-1);
 }
 return p;
}

int main() {
 cout << "El resultado es "<<potencia(2, 3)<<endl;
 return 0;
}