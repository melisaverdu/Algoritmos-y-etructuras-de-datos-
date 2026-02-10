#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctype.h>
#include <string>

using namespace std;

template <class T> class Nodo {
private:
    T dato;
    Nodo* next;
public:
    Nodo() { next = NULL; };
    Nodo(T a) { dato = a; next = NULL; };
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

template <class T> class Lista {
private:
    Nodo<T>* czo;
    void addO(T d, Nodo<T>* ant);
    void borrarD(T d, Nodo<T>* ant);
public:
    Lista() { czo = new Nodo<T>(); };
    Lista(Nodo<T>* n) { czo = n; };
    ~Lista(void);
    void add(T d); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
                        //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    void impre(void);
    T suma(T i);
    int size();
    bool esta(T d);// detecta si d esta en la lista
    void borrarDato(T d) { borrarD(d, NULL); }//borra el nodo que contiene d
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d) { addO(d, NULL); }; //sumar nodos a la lista Ordenados de menor a MAYOR

};
template <class T>
Lista<T>::~Lista(void) {
    // Mientras haya nodos con datos en la lista...
    while (!esvacia()) {
        borrar(); // El método borrar() ya elimina la cabeza y mueve el puntero
    }
    // Al final del bucle, solo queda el nodo centinela creado en el constructor.
    // También debemos liberarlo.
    delete czo;
    std::cout << "\n>> Destructor llamado: Memoria de la lista liberada correctamente." << std::endl;
}
template <class T>
void Lista<T>::add(T d) //100
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
}
template <class T>
bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();
}
template <class T>
T Lista<T>::cabeza(void)
{
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return T();
    }
    return czo->get_dato();
}

template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}

template <class T>
string Lista<T>::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        //std::ostringstream stm;
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str();
    }
}

template <class T>
T Lista<T>::suma(T i)
{    //cout<<" i al entrar= "<<i<<endl;
    if (this->esvacia()) {
        return i;
    }
    else {

        //cout<<"this->cabeza()= "<<this->cabeza()<<endl;   
        return this->resto()->suma(i + this->cabeza());
    }
}

template <class T> int Lista<T>::size()
{
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}

template <class T> void Lista<T>::borrar(void)
{ //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

template <class T> void Lista<T>::borrar_last()
{ // borra el ultimo nodo
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else this->resto()->borrar_last();
    }
}

template <class T> void Lista<T>::concat(Lista<T>* l1)
{// le transfiere los datos de l1 a this
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

template <class T> Lista<T>* Lista<T>::copy(void)
{
    Lista<T>* aux = new Lista();
    aux->concat(this);
    return aux;
}

template <class T> void Lista<T>::tomar(int n)
{ //deja "vivos" los n primeros nodos y borra el resto
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}

template <class T> void Lista<T>::impre(void)
{
    Nodo<T>* aux;
    aux = czo;
    while (aux->get_next() != NULL) {
        cout << aux->get_dato() << endl;
        aux = aux->get_next();
    }
}

template <class T>
void Lista<T>::addO(T d, Nodo<T>* ant)
{
    if (this->esvacia()) {//el primero
        this->add(d);
    }
    else {
        if (d < czo->get_dato()) {
            if (ant == NULL) {//al principio
                this->add(d);
            }
            else {//entre medio
                Nodo<T>* nuevo = new Nodo<T>(d);
                nuevo->set_next(ant->get_next());
                ant->set_next(nuevo);
            }
        }
        else {
            if ((czo->get_next())->get_next() == NULL) {//al final
                Nodo<T>* nuevo = new Nodo<T>(d);
                nuevo->set_next(czo->get_next());
                czo->set_next(nuevo);

            }
            else this->resto()->addO(d, czo);

        }
    }
}

template <class T> bool Lista<T>::esta(T d)
{// busca d en la lista
    if (this->esvacia()) return false;
    if (this->cabeza() == d) return true;
    
    return this->resto()->esta(d);    
}

template <class T>
void Lista<T>::borrarD(T d, Nodo<T>* ant)
{
    if (!this->esvacia()) {
        if (d == this->cabeza()) {
            if (ant == NULL) {//al principio
                this->borrar();
            }
            else {//entre medio
                ant->set_next(czo->get_next());
                delete czo;
            }
        }
        else  this->resto()->borrarD(d, czo);

    }
}

template <class T> class Pila:public Lista<T>{
      public:
             Pila(){Lista<T>();}; //cuando se corre el constructor de Pila, se corre el de Lista
             void apilar(T d){this->add(d);};
             T tope(void){return this->cabeza();};
             void desapilar(void){this->borrar();};
             bool pilavacia(){return this->esvacia();};
             string procesarCadena(Lista<char>* l1);
             bool esPalindromo(Lista<char>* l1);
             void editor(Lista<T>* l1);
};                  
/*
PILAS (Pensar en LIFO: El último que entra sale primero)
Ejercicio A: El "Retroceso" de caracteres. Escribe una función que reciba una cadena (ejemplo: abc#de##f) y use una Pila para procesarla.

Si el carácter es una letra, se apila.

Si es un #, funciona como la tecla "Backspace" (borra la última letra ingresada).

Al final, muestra cómo quedó la cadena.

Ejemplo: abc#de##f debería quedar como abf.

Ejercicio B: Invertir un número. Recibe un número entero (ejemplo: 1234) y, usando una Pila de números, devuélvelo invertido (4321).

Pista: Usa el operador % 10 para sacar el último dígito y apilarlo.
*/
template <class T>
string Pila<T>::procesarCadena(Lista<char>* l1){
    Pila<char> pila;
    while(!l1->esvacia()){
        char m = l1->cabeza();
        if(m != '#'){
            cout << "Apilando: " << m << endl;
            pila.apilar(m);
            
        }else{
            
            cout << "Encontre # lo ignoro " << pila.tope() << endl;
        }
        l1->borrar();
    }
    string resultado = "";
    while(!pila.pilavacia()){
        
        resultado = pila.tope() + resultado;
        pila.desapilar();
    }
    cout << "Cadena procesada: " << resultado << endl;
    return resultado;
    
}
/*
El Ejercicio: Verificador de Palíndromos con Pilas
Consigna: Escribe una función que reciba una Lista<char> (tu lista de caracteres) y determine si el contenido es un palíndromo utilizando una Pila.

Lógica sugerida:

Recorre la lista original y ve apilando cada carácter en una Pila<char>.

Al terminar, la Pila tendrá los mismos caracteres pero en orden inverso (LIFO).

Vuelve a recorrer la lista desde el principio y, al mismo tiempo, ve sacando elementos de la Pila (tope y luego desapilar).

Compara el elemento de la lista con el de la pila. Si en algún momento son distintos, no es palíndromo.

Si vacías la pila y todos coincidieron, ¡es un palíndromo!
*/
template <class T>
bool Pila<T>::esPalindromo(Lista<char>* listaOriginal){
    Pila<char> pilaAux;
    //hago una copia de la lista en una pila aux para no modificar la original
    Lista<char>* cpr = listaOriginal->copy();
       
    // Apilo todos los caracteres en la pila
    while(!cpr->esvacia()){
        char letra = cpr->cabeza();
        pilaAux.apilar(letra); //apilo la letra
        cpr->borrar(); //paso al siguiente
    }

    // Hago una copia de la lista para no modificar la original
    cpr = listaOriginal->copy();

    while(!cpr->esvacia() && !pilaAux.esvacia()){ //mientras ambas no esten vacias
        if(cpr->cabeza() == pilaAux.tope()){
            pilaAux.desapilar();
            cpr->borrar();
        }
        else{
            return false;
        }
    }
    return true;    
}


int main()
{
    /*Pila<char> pila;
    Lista<char>* listaentrada = new Lista<char>();
    string cadena = "abc#de##f";
    
    for(int i = cadena.length() - 1; i >= 0; i--){
        listaentrada->add(cadena[i]);
    }
    cout << "Cadena original: " << cadena << endl;
    pila.procesarCadena(listaentrada);
    return 0;*/
    
    Pila<char> pila;
    Lista<char>* palindromo = new Lista<char>();
    string cadena = "valentino";
     for(int i = cadena.length() - 1; i >= 0; i--){
        palindromo->add(cadena[i]);
    }
    cout << "Cadena original: " << cadena << endl;
    if(pila.esPalindromo(palindromo)){
        cout<<"La palabra: "<< cadena << " es palindromo";
    }
    else{
        cout<<"La palabra: "<< cadena << " no es palindromo";
    }
}

