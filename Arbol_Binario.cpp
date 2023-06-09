#include <iostream>

using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int valor) {
        this->valor = valor;
        izquierdo = NULL;
        derecho = NULL;
    }
};

Nodo* insertarNodo( Nodo* nodo , int numero )
{
    
    if( nodo == NULL )
    {
        Nodo* nodo = new Nodo(numero);
        return nodo;
    }

    if( numero < nodo->valor )
    {
        nodo->izquierdo = insertarNodo( nodo->izquierdo , numero );
    }

    if( numero > nodo->valor )
    {
        nodo->derecho = insertarNodo( nodo->derecho , numero );
    }

    return nodo;

}
void imprimirArbol(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    
    imprimirArbol(nodo->izquierdo);
    cout << nodo->valor << " ";
    imprimirArbol(nodo->derecho);
}
void imprimirArbolDes(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }
    imprimirArbolDes(nodo->derecho);
    cout << nodo->valor << " ";
    imprimirArbolDes(nodo->izquierdo);
}

int main()
{

    Nodo* raiz = NULL;
    
    while( true )
    {
        
		int numero;

        cout<<"Ingresa el numero: ";
        
        cin>>numero;

        if( numero == -1 ) break;

        raiz = insertarNodo(raiz , numero);

    }
    cout<<"\n Forma Ascendente:\n";
    imprimirArbol(raiz);
    cout<<"\n Forma Descendente:\n";
	imprimirArbolDes(raiz);

}
