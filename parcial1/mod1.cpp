#include <iostream>
#include <initializer_list>

struct Nodo {
    int valor;
    Nodo* next;

    explicit Nodo(int v) : valor(v), next(nullptr) {}
};

// Helpers para tests (NO modificar)
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

        if (head->next) {
            std::cout << " -> ";
        }

        head = head->next;
    }

    std::cout << "\n";
}

void freeList(Nodo* head) {
    while (head) {
        Nodo* temp = head;
        head = head->next;
        delete temp;
    }
}

/*
============================================================
PREGUNTA 1 — removeNegatives
============================================================

Implementar:

Nodo* removeNegatives(Nodo* head);

Restricciones:
- Debe ser estrictamente recursiva
- NO usar loops
- Debe modificar la lista original
- Debe liberar nodos eliminados

Ejemplo:
3 -> -1 -> 5 -> -2 -> 7
↓
3 -> 5 -> 7
*/

// DESARROLLE SU FUNCION AQUI
void removeNegative(Nodo*& head){
    if(head == nullptr) return;

    if(head->valor < 0){
        Nodo* temp = head;
        head = head->next;
        delete temp;
        removeNegative(head);
    } else {
        removeNegative(head->next);
    }

}

/*
============================================================
PREGUNTA 2 — Debugging
============================================================

La siguiente función está rota:

int countNodes(Nodo* head){
    if(head == nullptr) return 0;

    delete head;
    return 1 + countNodes(head->next); //quiero acceder a memoria liberada, memory leak
}

Tu tarea:
1. Identificar bug en comentario
2. Corregir la función
3. Justificar corrección

*/

// DESARROLLE SU FUNCION AQUI


/*

int countNodes(Nodo* head){
    if(head == nullptr) return 0;

    return 1 + countNodes(head->next);
}
============================================================
PREGUNTA 3 — esAlternante
============================================================

Una lista es alternante si:

1 -> 3 -> 2 -> 4 -> 1   => true
1 -> 2 -> 3             => false

Implementar:

bool esAlternante(Nodo* head);

Restricciones:
- Debe ser recursiva
- NO loops
*/

// DESARROLLE SU FUNCION AQUI
bool esAlternante(Nodo* head){
    if(head != nullptr && head->next != nullptr && head->next->next != nullptr){
        if((head->valor < head->next->valor)&&(head->next->next->valor < head->next->valor)){
            return esAlternante(head->next);
        } else if((head->valor > head->next->valor)&&(head->next->next->valor > head->next->valor)){
            return esAlternante(head->next);
        } else {
            return false;   
        }
}

/*
============================================================
PREGUNTA 4 — Invariantes
============================================================

Nombrar en comentarios 2 invariantes estructurales válidos
para una cola implementada con:

Node* front;
Node* rear;

invariantes estructurales:
1. Si front es nullptr, entonces rear también debe ser nullptr (cola vacía).
2. El nodo apuntado por rear siempre debe tener su puntero next igual a nullptr (indica el final de la cola).

*/

// ESCRIBA SUS INVARIANTES AQUI



int main() {
    // =========================
    // TEST removeNegatives
    // =========================
    Nodo* l1 = buildList({3, -1, 5, -2, 7});
    l1 = removeNegatives(l1);
    printList(l1);
    freeList(l1);

    // =========================
    // TEST countNodes
    // =========================
    Nodo* l2 = buildList({1, 2, 3, 4});
    std::cout << countNodes(l2) << "\n";
    freeList(l2);

    // =========================
    // TEST esAlternante
    // =========================
    Nodo* l3 = buildList({1, 3, 2, 4, 1});
    std::cout << (esAlternante(l3) ? "true" : "false") << "\n";
    freeList(l3);

    Nodo* l4 = buildList({1, 2, 3});
    std::cout << (esAlternante(l4) ? "true" : "false") << "\n";
    freeList(l4);

    return 0;
};
