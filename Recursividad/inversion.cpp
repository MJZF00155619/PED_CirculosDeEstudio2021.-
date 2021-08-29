#include<iostream>
using namespace std;

void invertir(int n){
    cout<<n%10;
    if (n>10)
        invertir(n/10);
}
int main(){
    int n;
    
    cout<<" Ingrese un numero: ";
    cin>>n;
        
    invertir(n);
    cout<<endl<<endl;
    return 0;
}