#include <iostream>
#include <string>

//Recursión a la cola
/*
En la que la última instrucción que ejecuta una función es la llamada recursiva, a si misma.
En muchos lenguajes este tipo de recursión puede ser optimizada por el compilador para evitar el crecimiento de la pila de llamadas,
mediante el TCO (Tail Call Optimization), que convierte la llamada recursiva en una simple instrucción de salto.

*/
using namespace std;

int factorial(int n)
{	if (n==0 )	return 1;
    else{
		return n * factorial(n-1);
	}
}

int factorialTail(int n, int acumula)
{	if (n==0 )	return acumula;
    else{
		
		return factorialTail(n-1,n*acumula); //solo tiene que retornar la llamada recursiva, no queda ninguna operacion pendiente
	}
}
int main()
{	int f=4;
	cout<<"factorial de "<<f<<"! "<<factorial(f)<<endl;
	cout<<"factorialTail de "<<f<<"! "<<factorialTail(f,1)<<endl;
	return 0;
}