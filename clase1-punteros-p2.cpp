#include <cstdlib>
#include <iostream>

using namespace std;


void swap(int, int);
void swap(int *a, int *b);
void swap(int &a, int &b);
void impre(int *. int);

int main(){

    //prueba de swap con punteros y referencias
    int x,y;
    x=55; y=-22;


    cout<<endl<<"----------------------";
    cout<<"\n x="<<x<<"  y="<<y;
    //swap(x,y); 
    swap(&x,&y); //llamo a la función que usa punteros -> con & le mando la dirección de x e y
                //ahora el cambio si se ve en el main, porque trabajo con direcciones de memoria

    swap(x,y); //llamo a la función que usa referencias -> con & le mando la dirección de x e y
                //ahora el cambio si se ve en el main, porque trabajo con referencias
    cout<<"\n x="<<x<<"  y="<<y;
    cout<<endl<<"----------------------";

    //prueba de la función impre
    int V[5]={23,1,-8,14,7};
    impre(V, 5); //el nombre del arreglo es un puntero al primer elemento, entonces le paso V como puntero

}

void impre(int *px, int N){
    for(int i=0;i<N;i++){
        cout<<px[i]<<endl;
    }
}

/* otra forma de definir la función es como void impre(int px[], int N)
   la forma "correcta" de usar es si yo voy a recibir la dirección de un arreglo
   lo exprese de esta forma, para que el que lea el código entienda mejor que es un arreglo.
   
   En cambio si leo int *px, entiendo que es un puntero a un entero, que puede o no apuntar a un arreglo.
*/

void swap(int a, int b)
{   int c;
    cout<<"\n a="<<a<<"  b="<<b;
    c=a; a=b; b=c;
    cout<<"\n a="<<a<<"  b="<<b;   
    // los cambios no afectan a x e y, todo se hace dentro de esta función 
}
void swap(int *a, int *b)
{   int c;
    cout<<"\n a="<<*a<<"  b="<<*b;
    c=*a; *a=*b; *b=c; //hago el intercambio con los punteros que apuntan a lso valores originales
    // los cambios afectan a x e y, porque estoy trabajando con sus direcciones
    cout<<"\n a="<<*a<<"  b="<<*b;   
    
}

//esta funcion usa referencias, que son alias de las variables originales
//cuando la llamo como swap(x,y), a es un alias de x y b es un alias de y
//
void swap(int &a, int &b)
{int c;
  cout<<"\n a="<<a<<"  b="<<b;
  c=a; a=b; b=c; //aca el compilador se encarga solo de hacer el pasaje por referencia 
  cout<<"\n a="<<a<<"  b="<<b;   
}

