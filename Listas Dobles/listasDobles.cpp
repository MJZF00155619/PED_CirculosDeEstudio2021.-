#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *ant;
    Nodo *sig;
};
Nodo* head;

void insertar(int n){
    Nodo *nuevo = new Nodo;
    nuevo->dato = n;
    if(head==NULL){
        nuevo->ant=NULL;
        nuevo->sig=NULL;
        head = nuevo;
    }else{
        nuevo->ant=NULL;
        nuevo->sig=head;
        head->ant=nuevo;
        head=nuevo;
    }
}

void insertarAlFinal(int n){
    Nodo *nuevo = new Nodo;
    nuevo->dato = n;
    nuevo->sig = NULL;
    if(head==NULL){
        nuevo->ant=NULL;
        nuevo->sig=NULL;
        head = nuevo;
    }else{
        Nodo *aux = head;
        while(aux->sig!= NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        nuevo->ant=aux;
    }
}

void mostrar(){
    Nodo *aux=head;
    while(aux!=NULL){
        cout<<aux->dato<<"->";
        aux=aux->sig;
    }
    cout<<endl;
}

void mostrarInvertido(){
    Nodo* aux = head;
    while(aux->sig!=NULL){
        aux=aux->sig;
    }

    while(aux!=NULL){
        cout<<"->"<<aux->dato;
        aux=aux->ant;
    }
    cout<<endl;
}

void eliminar(){
    int num;
    cout<<"Numero a eliminar: ";
    cin>>num;

    Nodo *p = head, *q=NULL;

    while(p !=NULL && p->dato!=num){
        q = p;
        p = p->sig;
    }

    if(p==NULL){
        cout<<"Numero no existe"<<endl;
    }

    if(q==NULL){
        head = p->sig;
        head->ant = NULL;
    }else{
        q->sig = p->sig;
        if(p->sig!=NULL){
            (q->sig)->ant=q;
        }
    }
    delete(p); 
}


int main(){

    insertar(5);
    insertar(6);
    insertar(7);
    insertarAlFinal(8);

    mostrar();
    mostrarInvertido();

    eliminar();

    mostrar();
    mostrarInvertido();

    return 0;
}