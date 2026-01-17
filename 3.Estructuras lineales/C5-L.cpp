// Listas_02.cpp 
//
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T> class Nodo {
private:
    T dato;
    Nodo* next;
public:
    Nodo() { next = NULL; }; //constructor por defecto, crea nodo vacio
    Nodo(T a) { dato = a; next = NULL; }; //constructor con dato, next a NULL
    void set_dato(T a) { dato = a; }; //setea el dato
    void set_next(Nodo* n) { next = n; };//setea el puntero next
    T get_dato() { return dato; }; //retorna el dato
    Nodo* get_next() { return next; }; //retorna el puntero next
    bool es_vacio() { return next == NULL; } //retorna true si el nodo es vacio
};

template <class T> class Lista {
private: Nodo<T>* czo; //puntero al nodo cabeza, de tipo Nodo<T>
     
public:
    Lista() { czo = new Nodo<T>(); }; //constructor por defecto, crea lista vacia
    Lista(Nodo<T>* n) { czo = n; };
    //~Lista(void);
    void add(T d); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
                        //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void copy(Lista<T>* l1);
   
};
template <class T>
void Lista<T>::add(T d) 
{ 
    Nodo<T>* nuevo = new Nodo<T>(d); 
    nuevo->set_next(czo); //el next del nuevo nodo apunta al nodo que apuntaba czo
    czo = nuevo; //czo apunta al nuevo nodo, y sigue siendo la cabeza de la lista
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
        return NULL;
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
        return p; //este return vuelve a la llamada anterior, this->resto()->toPrint(p)
    }
    else {
        //std::ostringstream stm;
        ostringstream stm; //es como un buffer de salida
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        //cout<<endl<<" stm.str()= "<<stm.str()<<endl;
        return stm.str(); //retorna el string contenido en el buffer, al final de todo 
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

int main()
{
    Lista<string>* l = new Lista<string>();
    Lista<int>* r = new Lista<int>();
    Lista<string>* l2 = new Lista<string>();
    
    
    l->add("cuatro");
    l->add("tres");
    l->add("dos");
    l->add("uno");
    cout << "Lista l: " << endl;
    cout << l->toPrint("") << endl;
    cout << "Tamanio de l: " << l->size() << endl;
    l->borrar();
    cout << "Lista l luego de borrar la cabeza: " << endl;
    cout << l->toPrint("") << endl;
    l->borrar_last();
    cout << "Lista l luego de borrar el ultimo: " << endl;
    cout << l->toPrint("") << endl;
    l2->add("seis");
    l2->add("cinco");   
    cout << "Lista l2: " << endl;
    cout << l2->toPrint("") << endl;
    l->concat(l2);
    cout << "Lista l luego de concatenar l2: " << endl; 
    cout << l->toPrint("") << endl;
    
    cout << "Tomo los 3 primeros nodos de l: " << endl;
    l->tomar(3);
    cout << l->toPrint("") << endl;

    

    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;

}

/*
void addOrdenado(T d)// suma nodos ordenados de menor a mayor
bool esta(T d); //retorna true cuando d est� en la lista
void borrarDato(T d)// borra el nodo que contiene a d
*/
 
// -- Realización de los métodos --

//-- size -> cantidad de nodos en la lista
template <class T> 
int Lista<T>::size()
{
    if(this->esvacia()){
        return 0;
    }
    else{
        return 1 + this->resto()->size();
    }
}

//-- borrar -> borra el nodo cabeza
template <class T>
void Lista<T>::borrar(void)
{
    if(!this->esvacia()){
        Nodo<T>* aux = new Nodo<T>();
        aux = czo; //guardo el nodo cabeza en aux
        czo = czo->get_next(); //czo apunta al siguiente nodo
        delete aux; //libero la memoria del nodo cabeza

    }
}

//-- borrar_last -> borra el ultimo nodo de la lista
template <class T> void Lista<T>::borrar_last(){
    if(!this->esvacia()){
        if(this->resto()->esvacia()){
            //si el resto es vacia, significa que czo es el ultimo nodo
            this->borrar(); //borro el nodo cabeza (ultimo nodo)
        }
        else{
            this->resto()->borrar_last(); //sigo buscando en el resto
        }
    }
}

//-- concat -> le transfiere los datos de l1 a this
template <class T>
void Lista<T>::concat(Lista<T>* l1){
    if(!(l1->esvacia())){
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}


//-- tomar -> deja "vivos" los n primeros nodos y borra el resto
template <class T>
void Lista<T>::tomar(int n){
    if(this->size()>n){
        this->borrar_last();
        this->tomar(n);
    }
}



