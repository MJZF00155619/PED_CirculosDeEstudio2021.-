#include<iostream>
using namespace std;

struct Persona{
    int id;
    string nombre;
    int edad;
};

struct nodo{
    Persona dato;
    nodo* siguiente;
    nodo* atras;
} *primero, *ultimo;

int idP;

void insertarNodo(){
    nodo* nuevo = new nodo();
    Persona persona;
    idP++;
    persona.id = idP;
    cout<<"Inserte el nombre de la persona"<<endl;
    getline(cin, persona.nombre);
    cout<<"Ingrese la edad de la persona"<<endl;
    cin>>persona.edad;
    cin.ignore();
    cout<<"El id de la persona es: "<<persona.id<<endl;

    nuevo->dato = persona;
    
    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente= primero;
        primero->atras = ultimo;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->atras = ultimo;
        nuevo->siguiente = primero;
        ultimo = nuevo;
        primero->atras = ultimo;
    }
}

void modificarNodo(){
    nodo* actual = new nodo();
    actual = primero;
    bool encontrado = false;
    int nodoBuscado = 0;
    cout<<"Ingrese el id de la persona a buscar para poder modificiar ";
    cin>> nodoBuscado;
    cin.ignore();

    if(primero!=NULL){
        do{
            if(actual->dato.id==nodoBuscado){
                cout<<"Persona con: "<<nodoBuscado<<"ha sido encontrada"<<endl;

                cout<<"Ingrese el nuevo nombre: "<<endl;
                getline(cin, actual->dato.nombre);
                cout<<"Ingrese la nueva edad para esta persona: "<<endl;
                cin>>actual->dato.edad;
                cin.ignore();
                cout<<"Nodo modificado"<<endl;

                encontrado=true;
            }
            actual = actual->siguiente;
        }while(actual!=primero && encontrado!=true);

        if(!encontrado){
            cout<<"Nodo no encontrado"<<endl;
        }

    }else{
        cout<<"la lista esta vacia"<<endl;
    }
}

void mostrarPrimeroAlUltimo(){
    nodo* actual = new nodo();
    actual = primero;
    if(primero!=NULL){
        do{
            cout<<"ID: "<<actual->dato.id<<endl;
            cout<<"Nombre: "<<actual->dato.nombre<<endl;
            cout<<"Edad: "<<actual->dato.edad<<endl;

        actual =  actual->siguiente;
        cout<<endl;
        }while(actual!=primero);
    }else{
        cout<<"La lista se encuentra vacia"<<endl;
    }
}

void mostrarUltimoAlPrimero(){
    nodo* actual = new nodo();
    actual = ultimo;
    if(primero!=NULL){
        do{
            cout<<"ID: "<<actual->dato.id<<endl;
            cout<<"Nombre: "<<actual->dato.nombre<<endl;
            cout<<"Edad: "<<actual->dato.edad<<endl;

        actual =  actual->atras;
        cout<<endl;
        }while(actual!=ultimo);
    }else{
        cout<<"La lista se encuentra vacia"<<endl;
    }
}

int main(){
    insertarNodo();
    insertarNodo();
    insertarNodo();
    modificarNodo();
    mostrarPrimeroAlUltimo();
    mostrarUltimoAlPrimero();
    return 0;
}