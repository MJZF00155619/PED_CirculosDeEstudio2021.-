#include <iostream>
using namespace std;

struct Numeros
{
    int coef;
    int exp;
};typedef struct Numeros numeros;

struct Nodo
{
  numeros dato;  
  Nodo *siguiente; 
};
Nodo *initNode;

numeros agregar(){
    numeros n;
    cout<<"agregue el coeficiente"<<endl;
    cin>>n.coef;
    cout<<"Agregue el exponente"<<endl;
    cin>>n.exp;

    return n;
}

void insertarLista(numeros n){
    Nodo *nuevo = new Nodo();
    nuevo->dato=n;
    nuevo->siguiente = initNode;
    initNode = nuevo; 
}

void mostrarNumeros(numeros n){
    cout<<"Coeficiente: "<<n.coef<<endl;
    cout<<"Exponente: "<<n.exp<<endl;
}

void mostrarLista(Nodo *initNode){
    Nodo *s = initNode;
    while(s!= NULL){
        mostrarNumeros(s->dato);
        s = s->siguiente;
    }
}


int main(){

    initNode == NULL;
    numeros dato, dato2, dato3;

    while(true){
        dato = agregar();
        insertarLista(dato);
    }

    mostrarLista(initNode);

    return 0;
}