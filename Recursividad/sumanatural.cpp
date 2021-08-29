#include <iostream>
using namespace std;

int sumanaturales(int n){
 int suma;
 if(n == 0){
  suma = 0;
 }else{
  suma = n + sumanaturales(n-1);
 }
 return suma;
}

int main() {
 int n;
 cout << "Introduce n: ";
 cin >> n;
 cout << "Suma = " << sumanaturales(n)<<endl;
 return 0;
}