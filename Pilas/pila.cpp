#include<iostream>
using namespace std;

class Pila{
    private:
        class Nodo{
            public:
                int info;
                Nodo *sig;
        };

        Nodo *raiz;
    public:
        Pila();
        void push(int x);
        void push();
        int pop();
        void imprimir();
        int top();
};

Pila::Pila(){
    raiz = NULL;
}

void Pila::push(int x){
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    if(raiz==NULL){
        raiz = nuevo;
        nuevo->sig = NULL;
    }else{
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

//Ejemplo de sobrecarga de metodo
void Pila::push(){
    Nodo *nuevo;
    nuevo = new Nodo();
    if(raiz==NULL){
        raiz = nuevo;
        nuevo->sig = NULL;
    }else{
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

int Pila::pop(){
    if(raiz!=NULL){
        int informacion = raiz->info;
        Nodo *borrar = raiz;
        raiz = raiz->sig; 
        delete borrar;
        return informacion;
    }else{
        return -1;
    }
}

int Pila::top(){
    if(raiz!=NULL){
        int informacion = raiz->info;
        return informacion;
    }else{
        return -1;
    }
}

void Pila::imprimir(){
    Nodo *reco=raiz;
    while(reco!=NULL){
        cout<<reco->info<<"->";
        reco = reco->sig;
    }
    cout<<endl;
}

int main(){
    Pila *pila1;
    pila1 = new Pila();

    pila1->push(1);
    pila1->push(2);
    pila1->push(3);
    pila1->push(4);
    pila1->push();

    pila1->imprimir();

    cout<<"Dato top: "<<pila1->top()<<endl;

    cout<<"Dato extraido: "<<pila1->pop()<<endl;
    cout<<"Dato extraido: "<<pila1->pop()<<endl;

    pila1->imprimir();

    return 0;
}