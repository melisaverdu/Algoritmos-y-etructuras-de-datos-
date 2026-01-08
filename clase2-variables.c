#include <cstdlib>
#include <iostream>
using namespace std;


/*Tengo que tener en cuenta que si yo no llamo a la función, as variables locales de la misma, 
no existen en memoria.
Cuando la llamo, se crean en memoria y cuando termina en "return co", se destruyen.

*/
int *copiax2(int x[], int N){ //devuelve la dirección del arreglo copiado (el que está multiplicado por dos)
    int co[4];


    for(int i=0; i<N; i++){
        co[i] = x[i] * 2;
    }    
    return co; // retorno un (puntero constante a la primera dirección de arreglo)
    //pero el mismo se destruye al salir de la función, entonces las siguientes líneas son las formas de solucionarlo.
    
    //----------------------------------Solución 1:----------------------------------
    static int co[4]; //la variable estática vive mientras dure el programa
    for(int i=0; i<N; i++){
        co[i] = x[i] * 2;
    }
    return co;

    //-------------------------------Solución 2:----------------------------------
    int *co=(int *) malloc (sizeof(int)*N); //reservo memoria en el heap, la cantidad de memoria que necesito, es la que 
                                            //coloco dentro del argumento de malloc
    //Uso cast para convertur la dirección devuelta por malloc a un puntero de tipo int, la cual  es recibida por un puntero de tipo int.

    for(int i=0; i<N; i++){
        co[i] = x[i] * 2;   
    }
    return co;

    //-------------------------------Solución 3:----------------------------------
    int *co = new int[N]; //reservo memoria en el heap, la cantidad de memoria que necesito, es la que 
                          //coloco dentro del argumento de new. Funciona igual que malloc, pero es más seguro.
    for(int i=0; i<N; i++){
        co[i] = x[i] * 2;
    }
    return co;

}

void prindat(void){
    static int x = 0; //la variable estática vive mientras dure el programa
    cout << x << endl;
    x++;

    //Si la variable no está definida como static me va a imprimir siempre 0
}

int main(){
    int v[4] = {1, 2, 3, 4};
    int *px;
    px = copiax2(v, 4);

    for(int i=0; i<4; i++){
        cout << px[i] << " ";
    }
    cout << endl;

    //Si usé malloc, o new debo liberar la memoria reservada con delete o free
    delete [] px; //si usé new
    //free(px); //si usé malloc

    //-------------------------Prueba prindat-------------------------
    prindat(); //0 La primera vez que se llama, x vale 0
    //Las siguientes veces que se llama, x mantiene su valor anterior
    prindat(); //1  
    prindat(); //2 

    return 0;
}