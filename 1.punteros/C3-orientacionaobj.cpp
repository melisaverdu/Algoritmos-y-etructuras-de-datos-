// DEITEL pag 439 en adelante
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Esto es la posibilidad de definir una variable estructurada, que coniene varios tipos de datos
struct FECHA {
   int dia;
   int mes;
   int anio;
};

struct PERSOMA{
   long int DNI;
   FECHA nac;
}

/*Hasta el momento hemos visto lo anterioir, con el mismo concepto podemos definir clases.
-Una clase es una estructura de datos que contiene atributos (datos) y m�todos (funciones) que operan sobre esos datos.
-Los atributos y métodos de una clase se denominan miembros de la clase. Estos miembros pueden ser de dos tipos: públicos y privados.
-Los miembros públicos son accesibles desde fuera de la clase, mientras que los miembros privados solo son accesibles desde dentro de la clase.
A los métodos públicos son la interfaz de la clase, ya que permiten a los usuarios interactuar con los objetos de la clase.

-La definición de una clase comienza con la palabra clave class seguida del nombre de la clase y el cuerpo de la clase encerrado entre llaves.

*/

class Tiempo {

public:
//las funciones son las que me van a permitair ingresar y cambiar las variables privadas

/*-Cuando yo creo un objeto de la clase Tiempo, se llama al constructor para inicializar los atributos del objeto. 
Es el que me permite poner unvalor por defecto a las variables privadas de la calse.


*/
   Tiempo( int = 0, int = 0, int = 0); // constructor predeterminado
   ~Tiempo(); // destructor predeterminado
   // funciones establecer = set
   void estableceHora( int, int, int ); // establece hora, minuto, segundo
   void estableceHora1( int );   // establece hora
   void estableceMinuto( int );  // establece minuto
   void estableceSegundo( int ); // establece segundo

   // funciones obtener = get
   int obtieneHora1();        // obtiene hora
   int obtieneMinuto();       // obtiene minuto
   int obtieneSegundo();      // obtiene segundo

   void imprimeUniversal();         // imprime la hora en formato universal
   void imprimeEstandar();          // imprime la hora en formato est�ndar
   
   void incrementaSegundos(const int);
   void incrementaMinutos(const int );
   void incrementaHoras(const int);

private:
//variables que voy a poder cambiar con los metodos publicos

   int hora;     // 0 - 23 (formato de reloj de 24 horas)
   int minuto;   // 0 - 59
   int segundo;  // 0 - 59

}; // fin de la clase Tiempo

// funci�n constructor para inicializar datos privados;
// llama a la funci�n miembro estableceHora para asignar los valores;
// los valores predeterminados son 0 (vea la definic�n de la clase)

//Lo que se escribe despues de  "::" es como indicar que la funcion pertenece a la clase Tiempo

Tiempo::Tiempo( int hr, int min, int seg ) 
{ 
   //Cada vez que creo un objeto de la clase Tiempo se ejecuta el constructor, éste método con als variables que le paso por defecto o por parametro
   //desde el main
   cout<<"\n soy el constructor\n";
   estableceHora( hr, min, seg ); //esto va a controlar que los valores sean correctos

} // fin del constructor Tiempo

Tiempo::~Tiempo()
{ cout<<"\n soy el destructor ------------";
}

// establece los valores de hora, minuto y segundo
void Tiempo::estableceHora( int h, int m, int s ) 
{ 
   estableceHora1( h );
   estableceMinuto( m );
   estableceSegundo( s );

} // fin de la funci�n estableceHora

// establece el valor de hora
void Tiempo::estableceHora1( int h ) 
{
   //es como si usara un if pero en una sola linea
   //lo que se pone despues de ":" es lo que se asigna a la variable hora, si no se ciumple la condicion
   hora = ( h >= 0 && h < 24 ) ? h : 0; //puedo acceder a los atributos privados desde los metodos publicos

} // fin de la funci�n estableceHora1

// establece el valor de minuto
void Tiempo::estableceMinuto( int m )
{ 
   minuto = ( m >= 0 && m < 60 ) ? m : 0; 

} // fin de la funci�n estableceMinuto

// establece el valor de segundo
void Tiempo::estableceSegundo( int s )
{ 
   segundo = ( s >= 0 && s < 60 ) ? s : 0; 

} // fin de la funci�n estableceSegundo

// devuelve el valor de hora
int Tiempo::obtieneHora1() 
{ 
   return hora;   

} // fin de la funci�n obtieneHora1

// devuelve el valor de minuto 
int Tiempo::obtieneMinuto() 
{
   return minuto; 

} // fin de la funci�n obtieneMinuto

// devuelve el valor de segundo 
int Tiempo::obtieneSegundo() 
{ 
   return segundo;
   
} // fin de la funci�n obtieneSegundo

// imprime Tiempo en formato universal
void Tiempo::imprimeUniversal()
{
   cout << setfill( '0' ) << setw( 2 ) << hora << ":"
        << setw( 2 ) << minuto << ":"
        << setw( 2 ) << segundo;

} // fin de la funci�n imprimeUniversal

// print Time in standard format
// imprime Tiempo en formato est�ndar
void Tiempo::imprimeEstandar()
{
   cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 )
        << ":" << setfill( '0' ) << setw( 2 ) << minuto
        << ":" << setw( 2 ) << segundo 
        << ( hora < 12 ? " AM" : " PM" );

} // fin de la funcion imprimeEstandar
void Tiempo::incrementaSegundos(const int cuenta )
{
   cout << "Incrementa segundo " << cuenta
        << " veces:\nHora inicio: ";
   imprimeEstandar();

   for ( int i = 0; i < cuenta; i++ ) {
      estableceSegundo( ( obtieneSegundo() + 1 ) % 60 );  

      if ( obtieneSegundo() == 0 )
         incrementaMinutos(1);

      cout << "\nsegundo + 1: ";
      imprimeEstandar();

   } // fin de for

   cout << endl;

} // fin de la funci�n incrementaSegundos

void Tiempo::incrementaMinutos(const int cuenta )
{
   cout << "Incrementa minuto " << cuenta
        << " veces:\nHora inicio: ";
   imprimeEstandar();

   for ( int i = 0; i < cuenta; i++ ) {
      estableceMinuto( ( obtieneMinuto() + 1 ) % 60 );  

      if ( obtieneMinuto() == 0 )
         incrementaHoras(1);

      cout << "\nminuto + 1: ";
      imprimeEstandar();

   } // fin de for

   cout << endl;

} // fin de la funci�n incrementaMinutos

void Tiempo::incrementaHoras(const int cuenta )
{
   cout << "Incrementa hora " << cuenta
        << " veces:\nHora inicio: ";
   imprimeEstandar();

   for ( int i = 0; i < cuenta; i++ ) {
      estableceHora1( ( obtieneHora1() + 1 ) % 24 );

      cout << "\nhora + 1: ";
      imprimeEstandar();

   } // fin de for

   cout << endl;

} // fin de la funci�n incrementaHoras

int main(int argc, char *argv[])
{  
    {Tiempo t(14,40,0),x,y(10);              // crea el objeto de Tiempo
      t.imprimeEstandar(); cout<<endl;
      x.imprimeEstandar(); cout<<endl;
      y.imprimeEstandar(); cout<<endl;
    
      //creo un objeto dinamicamente, un puntero de tipo Tiempo y utilizo el operador ->
      Tiempo *p= new Tiempo(11,11,11);
      p->imprimeEstandar();cout<<endl;
      
   // establece la hora mediante funciones establece (set) individuales
   t.estableceHora1( 17 );     // establece hora en un valor v�lido
   t.estableceMinuto( 34 );   // establece minuto en un valor v�lido
   t.estableceSegundo( 25 );   // establece segundo en un valor v�lido

   // funciones obtener (get) para obtener hora, minuto y segundo
   cout << "Resultado de establecer todos los valores validos:\n" 
        << "  Hora: " << t.obtieneHora1() // aca por ejemplo no podría hacer t.hora porque hora es privado
        << "  Minuto: " << t.obtieneMinuto()
        << "  Segundo: " << t.obtieneSegundo();

   // establece hora mediante el uso de funciones individuales
   t.estableceHora1( 234 );     // establece hora no v�lida en 0
   t.estableceMinuto( 43 );    // establece minuto en un valor v�lido
   t.estableceSegundo( 6373 ); // establece segundo no v�lido en 0

   // despliega hora, minuto y segundo despu�s de establecer 
   // los valores no v�lidos de hora y segundo
   cout << "\n\nResultado del intento de establecer los valores no validos de minuto"
        << " y segundo:\n  Hora: " << t.obtieneHora1()
        << "  Minuto: " << t.obtieneMinuto()
        << "  Segundo: " << t.obtieneSegundo() << "\n\n";

   t.estableceHora( 11, 58, 0 );    // establece hora
   t.incrementaSegundos( 150 );  // incrementa los minutos de t en 3
   t.imprimeEstandar(); cout<<endl;



    cout<<endl<<endl;

  } //con esta llave se destruyen los objetos de tipo Tiempo creados en el main
    cout<<endl<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Hacer una clase Semana_Laboral
que almacene:
el Nombre de un empleado
su documento
en un arreglo de 5 x 2 de tipo Tiempo la hora de ingreso y de salida de cada d�a
La clase debe tener m�todos para
setear la hora de ingreso y de salida para cada d�a
obtener el n�mero total de horas y minutos trabajados en la semana
todo otro m�todo que considere
*/



