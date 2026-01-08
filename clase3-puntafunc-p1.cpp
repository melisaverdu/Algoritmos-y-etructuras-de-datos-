#include <cstdlib>
#include <iostream>
using namespace std;

//podemos tener punteros a funciones 
void f1(int);
void f2(int);

int main(int argc, char *argv[])
{
    //de esta manera se define un puntero a función que recibe un entero y no devuelve nada
    void (*pf)(int); // 1. el tipo que devuelve la función (void)
                     // 2. el nombre del puntero a función (pf)
                     // 3. los parámetros que recibe la función (int)

    pf=&f2; //asigno al puntero la dirección de la función f2
    pf(5);  //llamo a la función a través del puntero
            // es equivalente a f2(5);
    cout<<endl;
    f2(5); 
    cout<<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;


    
}

void f1(int n){
    int i;
    for(i=0;i<n;i++)
        cout<< "\n Soy la UNO (1);"
}
void f2(int n){
    int i;
    for(i=0;i<n;i++)
        cout<< "\n Soy la DOS (2);"
}