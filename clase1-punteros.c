#include <cstdlib>
#include <iostream>

using namespace std;



int main(int argc, char *argv[])
{   int x,y;
    /*-defino punteros a enteros
    contienen direcciones de enteros
    */
    int *px,*py;

    //-------------------------------------------------------------------
    x=55; y=-22;
    cout<<"\n x="<<x;
    cout<<"\n y="<<y;
    cout<<"\n tamaño entero= "<<sizeof(int);

    // con & obtengo la dirección de una variable
    px=&x; py=&y;
    cout<<"\n px="<<px; // dirección de x (un número hexadecimal)
    cout<<"\n py="<<py; // dirección de y (un número hexadecimal)
    cout<<"\n *px="<<*px; // valor de x (55)
    cout<<"\n *py="<<*py;  // valor de y (-22) es un puntero apuntando a lo que hay en esa dirección

    *px=7; //cambio el valor de x a 7
    cout<<"\n *px="<<*px<<"  x="<<x;  //imprime 7 

    py=px; // ahora py apunta a donde apunta px (a x)
    cout<<"\n *py="<<*py<<"  y="<<y; //imprime 7
    
    cout<<endl<<"----------------------";
    cout<<"\n x="<<x<<"  y="<<y;
    swap(x,y);
    cout<<"\n x="<<x<<"  y="<<y;
     cout<<endl<<"----------------------";


    //--------------------------------------------------------------------
    //definición: el nombre de un arreglo es un puntero constante al primer elemento del arreglo
    int v[5]={23,1,-8,14,7}; 

     px=&v[0]; //le doy la direccion del primer elemento del arreglo
     py=v; //el nombre del arreglo es la direccion del primer elemento
     // por definición, lo anterior es lo mismo 

     cout<<"\n *px="<<*px<<"  *py="<<*py; //ambos apuntan al primer elemento del arreglo que es 23, imprime eso
     cout<<"\n  px="<<px<<"  py="<<py; //ambos tienen la direccion del primer elemento del arreglo 
     
     for(int i=0;i<5;i++){
         cout<<endl<<px[i]<<"  "<<*(px+i) // ambas formas son equivalentes
         //*() el "*" es el contenido al que apunta lo que está entre paréntesis
             <<"  "<<*(v+i)<<"  "<<*py++; // ambas formas son equivalentes
         //el py++ avanza al siguiente elemento del arreglo y el "*" obtiene su valor
     }

     //-----------------------------------------------------------------------

     cout<<endl<<"px= "<<px;
     cout<<endl<<"v= "<<v;
     cout<<endl<<"py= "<<py;
     
     
         
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}


void swap(int a, int b)
{ int c;
  cout<<"\n a="<<a<<"  b="<<b;
  c=a; a=b; b=c;
  cout<<"\n a="<<a<<"  b="<<b;   
     
}
void swap(int *a, int *b)
{ int c;
  cout<<"\n a="<<*a<<"  b="<<*b;
  c=*a; *a=*b; *b=c;
  cout<<"\n a="<<*a<<"  b="<<*b;   
     
}

void swap(int &a, int &b)
{int c;
  cout<<"\n a="<<a<<"  b="<<b;
  c=a; a=b; b=c;
  cout<<"\n a="<<a<<"  b="<<b;   
}

  

