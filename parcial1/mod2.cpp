/**
 * ============================================================================
 * SIMULACIÓN PARCIAL 1 (VARIANTE STACK/QUEUE) - EN BLANCO PARA PRACTICAR
 * FCEFyN - UNC
 * ============================================================================
 * Instrucciones: Completá el código de las funciones y del main según lo 
 * solicitado en los enunciados. Al final, respondé las preguntas teóricas.
 */

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

// ============================================================================
// PUNTO 1: SISTEMA DE REWIND, REDO Y MOSTRAR (Vale 30 puntos)
// ============================================================================
/*
  ENUNCIADO[cite: 207, 209]:
  Tienes un sistema que registra una secuencia de acciones realizadas por un usuario 
  (por ejemplo, en un juego o en un editor) mediante strings[cite: 207].
  Utiliza dos pilas de strings (stack<string>): una para almacenar la secuencia de 
  acciones realizadas (accionesRealizadas) y otra para las acciones deshechas (accionesDeshechas)[cite: 209].
  
  Tus tareas:
  1. Implementar la función 'rewind' (idealmente recursiva) que simule la acción de 
     deshacer las últimas 'n' acciones, pasándolas de 'realizadas' a 'deshechas'[cite: 211, 212].
  2. Implementar la función 'redo' que simule la acción de rehacer la última acción deshecha[cite: 213].
  3. Implementar la función 'mostrar' que imprima las operaciones de la pila una bajo la otra, 
     desapilando y luego volviéndola a su estado original usando una estructura auxiliar[cite: 221, 222].

    MÉTODOS DISPONIBLES EN std::stack<T>:
push(T& val): Añade un nuevo elemento a la cima de la pila.
pop(): Elimina el elemento de la cima de la pila. No devuelve el valor eliminado.
top(): Accede al elemento de la cima de la pila sin eliminarlo.
empty(): Retorna true si la pila está vacía, false en caso contrario.
size(): Retorna el número de elementos en la pila.
*/

// REWIND: Deshace 'n' operaciones [cite: 211]
void rewind(int n, stack<string>& realizadas, stack<string>& deshechas) {
    // --- TU TAREA ---
    // Tu código acá...
    if(realizadas.size() == 0){
        return;
    }
    if(n != 0){
        deshechas.push(realizadas.top());
        realizadas.pop();
        rewind(n-1, realizadas, deshechas);
    }
}

// REDO: Rehace la última operación deshecha [cite: 213]
void redo(stack<string>& realizadas, stack<string>& deshechas) {
    // --- TU TAREA ---
    // Tu código acá...
    if(deshechas.size() == 0){
        return;
    }else{
        realizadas.push(deshechas.top());
        deshechas.pop();
        return;
    }
}

// MOSTRAR: Imprime la pila sin destruirla usando una pila auxiliar [cite: 221, 222]
void mostrar(stack<string>& s) {
    // --- TU TAREA ---
    // Tu código acá...
    if(s.empty()){
        return;
    }
    stack<string> temp; // creo una pila auxiliar
    while(!s.empty()){
        temp.push(s.top()); //coloco en la pila auxiliar el primer elemento de la pila s
        s.pop(); // elimino el elemento en s para que cuando pase de nuevo a s no haya duplicados
    }
    // ya pasé todos los elementos a temp, ahora los vuelvo a pasar a s mientras los voy imprimiento en el orden original
    while(!temp.empty()){
        s.push(temp.top()); //lo agrefo a s
        cout << s.top() << endl; //lo muestro 
        temp.pop();
    }
}




// ============================================================================
// PUNTO 2: VERIFICACIÓN DE PALÍNDROMO (Vale 30 puntos)
// ============================================================================
/*
  ENUNCIADO[cite: 375]:
  Implementa una función 'esPalindromo' que determine si una cadena de texto es 
  un palíndromo utilizando una cola (std::queue) y una pila (std::stack)[cite: 375, 391].
  Debe ignorar espacios y diferencias entre mayúsculas y minúsculas[cite: 392].
  Retorna true si la cadena es un palíndromo, false en caso contrario[cite: 393].
*/
bool esPalindromo(const string& texto) {
    // --- TU TAREA ---
    // Pistas: Usá loops para cargar la pila y cola ignorando espacios con isalpha(),
    // pasá a minúsculas con tolower() y luego compará elemento por elemento.
    
    // Tu código acá...
    stack<char> pila;
    queue<char> cola;

    // El bucle para recorrer e ir cargando
    for (int i = 0; i < texto.size(); i++) {
        char letraActual = texto[i];  //voy pasando a letraActual cada una de las letras del string 

        if(isalpha(letraActual)){ //aca se verfica que sea una letra mayuscula o minuscula, todo lo que no sea una letra retorna false
            char minuscula = tolower(letraActual); //paso todas a minúsculas

            cola.push(minuscula); // pongo en la cola la letra
            pila.push(minuscula); //pongo en la pila la letra
        }

    }
    while(!cola.empty()){
        if(cola.front() == pila.top()){
            cola.pop(); //elimino el primero de la cola
            pila.pop(); //elimino el ultimo de la pila
        }else{
            return false;
        }        
    }
    return true;
}




// ============================================================================
// FUNCIÓN MAIN COMPLETA (A implementar según el flujo del examen)
// ============================================================================
/*
  El programa debe realizar las siguientes acciones en la función main()[cite: 215]:
  - Crear dos pilas de string: accionesRealizadas y accionesDeshechas[cite: 216].
  - Solicitar al usuario que ingrese la cantidad de acciones que va a realizar (na)[cite: 217].
  - Pedir el ingreso de los nombres de las 'na' acciones y guardarlas[cite: 218].
  - Solicitar la cantidad de acciones a deshacer (nd) y aplicar 'rewind'[cite: 219].
  - Solicitar la cantidad de acciones a rehacer (nr) y aplicar 'redo' esa cantidad de veces[cite: 220].
  - Mostrar las operaciones finales llamando a la función 'mostrar'[cite: 221].
*/
int main() {
    // --- TU TAREA ---
    // Tu código acá...

    return 0;
}




/* ============================================================================
 * SECCIÓN TEÓRICA: PREGUNTAS DE OPCIÓN MÚLTIPLE
 * ============================================================================
 * Intentá responderlas mentalmente o anotando la respuesta abajo.
 
 PREGUNTA 3[cite: 443]:
 En una aplicación de IoT, un microcontrolador mantiene una pila para registrar los últimos 250 eventos críticos[cite: 446].
 Si se ejecutan 185 operaciones push y luego 100 pop, ¿cuántos eventos quedarán en la pila? [cite: 447]
 
 RESPUESTA: 85


 PREGUNTA 4[cite: 449]:
 ¿Cuál estructura sería más adecuada para almacenar los paquetes en un robot repartidor 
 que sigue una ruta definida, y debe entregarlos en el orden en que fueron cargados? [cite: 452]
 
 a. Queue [cite: 453]
 b. List [cite: 454]
 c. Stack [cite: 455]
 d. Reverse List [cite: 456]
 
 RESPUESTA: a


 PREGUNTA 5[cite: 460]:
 El sistema de telemetría de CONAE-Marte guarda paquetes de datos entrantes en una lista simplemente enlazada, 
 donde cada nodo contiene la marca de tiempo y el siguiente nodo[cite: 464].
 Si se desea insertar un nuevo paquete justo después del segundo nodo, y se dispone del puntero a ese nodo, 
 ¿qué acciones son necesarias? [cite: 465]
 
 a. Cambiar el puntero del nodo anterior al nuevo nodo [cite: 466, 467]
 b. Recorrer la lista completa desde el principio [cite: 468]
 c. No es posible insertar sin conocer el tamaño total de la lista [cite: 469, 470]
 d. Cambiar el puntero del segundo nodo para que apunte al nuevo nodo, y que el nuevo nodo apunte al siguiente [cite: 471]
 
 RESPUESTA: d
*/