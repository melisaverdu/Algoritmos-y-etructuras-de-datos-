//  Pila con Arreglo.cpp  
//

#include <cstdlib>
#include <iostream>
#include <sstream>

#define MAX 100
using namespace std;


/*
    Pila implementada con arreglo
    No dinamica, no utiliza punteros, no se crean nodos
*/
template <class T> class Pila {
private:
    T d[MAX];
    int p;
public:
    Pila() { p = -1; };
    void apilar(T x) { d[++p] = x; };
    T tope(void) { return d[p]; };
    void desapilar(void) { p--; };
    bool pilavacia() { return p == -1; };
};



int main()
{
    /*
    Pila<string>* p = new Pila<string>();
    p->apilar("10");  p->apilar("11");
    p->apilar("12");  p->apilar("13");
    if (!p->pilavacia()) cout << p->tope() << endl;
    if (!p->pilavacia())p->desapilar();
    if (!p->pilavacia())cout << p->tope() << endl;
    if (!p->pilavacia())p->desapilar();
    if (!p->pilavacia())cout << p->tope() << endl;
    */


    string cadena;
    Pila<char>* p = new Pila<char>();
    cout << endl << "Ingrese cadena= "; cin >> cadena;
    int error = false;
    for (int i = 0; (i < cadena.length()) && (!error); i++) { //cadena.length() devuelve la longitud de la cadena
                                                             
        if (cadena.at(i) == '{') p->apilar('{'); //cadena.at(i) devuelve el caracter en la posicion i
        if (cadena.at(i) == '[') p->apilar('[');
        if (cadena.at(i) == '(') p->apilar('(');

        if (cadena.at(i) == '}') { 
            if (p->pilavacia()) error = true; //p->pilavacia() devuelve true si la pila esta vacia, entonces si tengo } y la pila esta vacia, es error
            else
                if (p->tope() != '{') error = true; //si el tope no es {, es error, el tope es el ultimo elemento ingresado y debe ser {
                else p->desapilar(); //si no hay error, desapilo el tope que es {, e como decir, listo, se cerro bien, lo tacho de mi lista.
        }
        if (cadena.at(i) == ']') {
            if (p->pilavacia()) error = true;
            else
                if (p->tope() != '[') error = true;
                else p->desapilar();
        }
        if (cadena.at(i) == ')') {
            if (p->pilavacia()) error = true;
            else
                if (p->tope() != '(') error = true;
                else p->desapilar();
        }
    }//fin for i
    if ((!error) && p->pilavacia())cout << endl << "TOdo OK";
    else cout << endl << "ERROR";
    


    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
