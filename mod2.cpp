#include <iostream>
#include <initializer_list>

struct Nodo {
    int valor;
    Nodo* next;

    explicit Nodo(int v) : valor(v), next(nullptr) {}
};

// Helpers
Nodo* buildList(std::initializer_list<int> vals) {
    Nodo* head = nullptr;
    Nodo* tail = nullptr;

    for (int v : vals) {
        Nodo* n = new Nodo(v);

        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    return head;
}

void printList(Nodo* head) {
    while (head) {
        std::cout << head->valor;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << "\n";
}

void freeList(Nodo* head) {
    while (head) {
        Nodo* t = head;
        head = head->next;
        delete t;
    }
}

/*
============================================================
PREGUNTA 1 — STACK (25 pts)
============================================================

Implementar:

void pushBottom(Nodo*& top, int value);

Agrega un elemento al fondo de la pila.

Ejemplo:
TOP -> 3 -> 2 -> 1

pushBottom(top, 0);

TOP -> 3 -> 2 -> 1 -> 0

Restricciones:
- Debe ser recursiva
- NO loops
*/


// DESARROLLE AQUI
void pushBottom(Nodo*& top, int value){
    if(top == nullptr){
        top = new Nodo(value);
    } else {
        pushBottom(top->next, value);
    }
}


/*
============================================================
PREGUNTA 2 — QUEUE (25 pts)
============================================================

Implementar:

void dequeueAll(Node*& front, Node*& rear, int value);

Elimina TODOS los nodos de la cola cuyo valor == value.

Restricciones:
- Puede ser iterativa o recursiva
- Debe mantener front/rear consistentes
- Debe liberar memoria
*/

- forma iterativa
void dequeueAll(Nodo*& front, Nodo*& rear, int value){
    while(front != nullptr && front->valor == value){
        Nodo* temp = front;
        front = front->next;
        delete temp;
    }

    if(front == nullptr){
        rear = nullptr;
        return;
    }

    
    Nodo* current = front;
    while(current->next != nullptr){
        if(current->next->valor == value){
            Nodo* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    rear = current; // actualizar rear al último nodo
}



// DESARROLLE AQUI
void dequeueAll(Nodo*& front, Nodo*& rear, int value){
    if(front == nullptr){
        rear = nullptr;
        return;
    }
    if(front->valor == value){
        Nodo* temp = front;
        front = front->next;
        delete temp;
        dequeueAll(front, rear, value);
    } else {
        dequeueAll(front->next, rear, value);
    }

    if(front == nullptr){
        rear = nullptr;
    }
    else if(front->next == nullptr){
        rear = front;
    }
    
}

/*
============================================================
PREGUNTA 3 — BIG O (15 pts)
============================================================

Analizar complejidad de:

for(int i = 0; i < n; i++){
    for(int j = 1; j < n; j *= 2){
        cout << i+j;
    }
}

Escribir respuesta en comentario.
*/
 

// RESPUESTA AQUI -> O(n log n)



/*
============================================================
PREGUNTA 4 — DEBUGGING (20 pts)
============================================================

¿Qué problema tiene este código?

void pop(Nodo*& top){
    delete top;
    top = top->next;
}

Explicar en comentario y corregir.
*/


// RESPUESTA / CORRECCION AQUI
// El problema es que se está accediendo a memoria liberada después de eliminar el nodo top. 
//Esto puede causar un comportamiento indefinido. Para corregirlo, primero se debe guardar el siguiente 
//nodo antes de eliminar el nodo actual.

void pop(Nodo*& top){
    Nodo* temp = top;
    top = top->next;
    delete temp;
}

/*
============================================================
PREGUNTA 5 — CONCEPTUAL (15 pts)
============================================================

Nombrar 2 diferencias entre Stack y Queue.

Escribir en comentarios.
*/


// RESPUESTA AQUI
/*

1. Stack es una estructura de datos LIFO (Last In, First Out), lo que significa que el último elemento agregado es el primero en ser eliminado.
2. Queue es una estructura de datos FIFO (First In, First Out), lo que significa que el primer elemento agregado es el primero en ser eliminado.


*/



int main() {
    return 0;
}