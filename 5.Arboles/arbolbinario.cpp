
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class nodo {
public:
    T info;
    nodo* der, * izq;
};

template <class T> class arbol {
private:
    nodo<T>* raiz, * q;
    void ArbolBusq(T x, nodo<T>*& nuevo); //esta realmente es la funcion que crea el arbol
    void rid(nodo<T>* aux);
    void ird(nodo<T>* aux);
    void idr(nodo<T>* aux);
    void show(nodo<T>* aux, int n);

public:
    arbol() { raiz = NULL; }; // Constructor
    ~arbol() {}; 
    void CreaArbolBus(T x); 
    //recorridos
    void RID() { rid(raiz); }
    void IRD() { ird(raiz); }
    void IDR() { idr(raiz); }

    void VerArbol() { show(raiz, 0); }

};


template <class T> void arbol<T>::CreaArbolBus(T x)
{
    ArbolBusq(x, raiz);
}
template <class T> void arbol<T>::ArbolBusq(T x, nodo<T>*& nuevo) //con & no estamos pasando una copia, estamos pasando el puntero original
{
    if (nuevo == NULL) { //la primera vez nuevo ES la raiz (por &)
        nuevo = new nodo<T>; //estoy modificando directamente la raiz que esta afuera
        nuevo->info = x; 
        nuevo->der = nuevo->izq = NULL;
    }
    //del segundo dato en adelante va a entrar aca
    //con nuevo->info me devuelve el valor de la raiz (a donde esta apuntando)
    if (x > nuevo->info) ArbolBusq(x, nuevo->der); //nuevo es el puntero derecho del nodo anterior
    if (x < nuevo->info) ArbolBusq(x, nuevo->izq); //nuevo es el puntero izquierdo del nodo anterior
}
template <class T> void arbol<T>::ird(nodo<T>* aux)
{
    if (aux != NULL) {
        ird(aux->izq);
        cout << "\n" << aux->info;
        ird(aux->der);
    }
}
template <class T> void arbol<T>::rid(nodo<T>* aux)
{
    if (aux != NULL) {
        cout << "\n" << aux->info;
        rid(aux->izq);
        rid(aux->der);
    }
}
template <class T> void arbol<T>::idr(nodo<T>* aux)
{
    if (aux != NULL) {
        idr(aux->izq);
        idr(aux->der);
        cout << "\n" << aux->info;
    }
}
template <class T> void arbol<T>::show(nodo<T>* aux, int n)
{
    int i;
    if (aux != NULL) {                      //OjO este es un recorrido dri
        show(aux->der, n + 1);
        for (i = 1; i <= n; i++) cout << "     ";
        cout << aux->info << "\n";
        show(aux->izq, n + 1);
    }
}
//-------------------------------------------------------
int main(int argc, char* argv[])
{
    int i,x;
    arbol<int> A;
    int vec[10] = { 50,12,18,240,222,45,410,325,38,95 };
    //int vec[10]={50,120,180,240,252,450,460,475,488,595};
    for (i = 0; i < 10; i++) {
        A.CreaArbolBus(vec[i]);
        //T.VerArbol();
        //system("PAUSE");
    }

    A.VerArbol();
    
    cout << "\n IRD--------------------------------";
    A.IRD();
    cout << "\n RID--------------------------------";
    A.RID();
    cout<<"\n IDR--------------------------------";
    A.IDR();
   
   /*
    cout << "\n Mostrar Hojas ----------";
    A.MostrarHojas();

    cout << "\n El menor del arbol= " << A.Menor();

    if (A.Esta(95))cout << "\n\n El dato 95 esta";
    else cout << "\n\n El dato 95 NO esta";

    
       for(i=0;i<5;i++){
         cout<<"\n -------------------------------- Ing dato a borrar= "; cin>>x;
         A.Borrar(x);
         A.VerArbol();

       }
    */
    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Realizar los siguientes metodos de la clase arbol
void MostrarHojas() //muestra todas las hojas del arbol
bool Esta(x) //retorna true si x esta en el arbol
T Menor() // retorna el menor valor del arbol
T Mayor() // retorna el mayor valor del arbol
void Borrar(x) // elimina el nodo que contiene el dato x

*/

