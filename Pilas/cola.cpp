#include<iostream>
using namespace std;

struct nodo{
    int nro;
    struct nodo *sig;
};

struct cola{
    nodo *delante;
    nodo *atras;
};

void encolar(struct cola &q, int valor){
    struct nodo *aux = new (struct nodo);

    aux->nro = valor;
    aux->sig = NULL;

    if(q.delante == NULL){
        q.delante = aux;
    }else{
        (q.atras)->sig = aux;
    }
    q.atras = aux;
}

int desencolar(struct cola &q){
    int num;
    struct nodo *aux;

    aux = q.delante;
    num = aux->nro;
    q.delante=(q.delante)->sig;
    delete(aux);
    return num;
};

void mostrar(struct cola q){
    struct nodo *aux;
    aux = q.delante;
    while(aux!=NULL){
        cout<<"->"<<aux->nro;
        aux=aux->sig;
    }

    cout<<endl;
}

int main(){
    struct cola q;

    q.delante = NULL;
    q.atras = NULL;

    encolar(q, 1);
    encolar(q, 2);
    encolar(q, 3);

    mostrar(q);

    cout<<"Elemento sacado: "<<desencolar(q)<<endl;
    mostrar(q);

    return 0;
}