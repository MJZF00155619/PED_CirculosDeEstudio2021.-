#include<iostream>
using namespace std;

struct nodo{
    int dato;
    nodo* sig;
    nodo* ant;
} *primero, *ultimo;

void insertarNodo(){
    nodo* nuevo = new nodo();
    cout<<"Valor del nodo: ";
    cin>>nuevo->dato;

    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
        primero->sig=primero;
        primero->ant=ultimo;
    }else{
        ultimo->sig = nuevo;
        nuevo->ant=ultimo;
        nuevo->sig = primero;
        ultimo = nuevo;
        primero->ant=ultimo;
    }
}

void buscarNodo(){
    nodo* actual = new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoBuscado;
    cout<<"Ingrese el nodo que quiere: "<<endl;
    cin>>nodoBuscado;

    if(primero!=NULL){
        do{
            if(actual->dato==nodoBuscado){
                cout<<"Nodo encontrado: "<<nodoBuscado;
                encontrado = true;
            }
            actual = actual->sig;
        }while(actual!=primero && encontrado != true);
    }else{
        cout<<"No se encontro el elemento"<<endl;
    }
}

void modificarNodo(){
    nodo* actual = new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoBuscado;
    cout<<"Ingrese el nodo que quiere: "<<endl;
    cin>>nodoBuscado;

    if(primero!=NULL){
        do{
            if(actual->dato==nodoBuscado){
                cout<<"Nodo encontrado: "<<nodoBuscado;

                cout<<"agregue el nuevo dato:" <<endl;
                cin>>actual->dato;

                encontrado = true;
            }
            actual = actual->sig;
        }while(actual!=primero && encontrado != true);
    }else{
        cout<<"No se encontro el elemento"<<endl;
    }
}

void mostrar(){
    nodo* actual = new nodo();
    actual = primero;
    if(primero!=NULL){
        do{
            cout<<actual->dato<<"->";
            actual=actual->sig;
        }while(actual!=primero); 
        cout<<endl;
    }else{
        cout<<"La lista esta vacia"<<endl;
    }
}

void mostrarAlrevez(){
    nodo* actual = new nodo();
    actual = ultimo;
    if(primero!=NULL){
        do{
            cout<<actual->dato<<"->";
            actual=actual->ant;
        }while(actual!=ultimo); 
        cout<<endl;
    }else{
        cout<<"La lista esta vacia"<<endl;
    }
}

void mostrar_primero_ultimo(){
    nodo* actual = new nodo();
    cout<<primero->dato<<"->";
    actual = primero->ant;
    cout<<actual->dato;
    cout<<endl;

    nodo* actual2 = new nodo();
    cout<<ultimo->dato<<"->";
    actual2 = ultimo->sig;
    cout<<actual2->dato;
    cout<<endl;

}

int main(){
    int opcion;

    do{
        cout<<"Ingrese una opcion"<<endl;
        cout<<"1. insertar \n2.buscar\n 3.Modificar\n 4.Mostrar\n 5.Mostrar al revez"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1: insertarNodo();
            break;
        case 2: buscarNodo();
            break;
        case 3: modificarNodo();
            break;
        case 4: mostrar();
            break;
        case 5: mostrarAlrevez();
            break;
        case 6: mostrar_primero_ultimo();
            break;
        default:
            break;
        }

    }while(opcion!=7);

    return 0;
}