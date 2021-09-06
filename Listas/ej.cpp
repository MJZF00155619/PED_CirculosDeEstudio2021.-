#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
};
Nodo *initNode;

void insertarAlPrincipio(int n){
    Nodo *nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->sig = initNode;
    initNode = nuevo;
}

void insertarAlFinal(int n){
    Nodo *nuevo = new Nodo;
    nuevo->dato=n;
    nuevo->sig = NULL;

    if(initNode==NULL){
        initNode=nuevo;
    }else{
        Nodo *p = initNode;
        Nodo *q = NULL;
        while(p!=NULL){
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void mostrarLista(){
    Nodo *s = initNode;

    while(s!=NULL){
        cout<<s->dato<<endl;
        s = s->sig;
    }
}

int main(){
    
    insertarAlPrincipio(1);
    insertarAlPrincipio(2);
    insertarAlPrincipio(3);
    insertarAlFinal(4);
    insertarAlPrincipio(5);

    mostrarLista();

    return 0;
}