/**
 * ============================================================================
 * Modelos de 1er parcial Valenzuela 2026: PRACTICA FINAL UNO - #FINALMATCH
 * FCEFyN - UNC
 * ============================================================================
 * Estructuras de Datos implementadas a mano con punteros y nodos internos.
 */

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ============================================================================
// PUNTO 1: QUEUE - FUSIÓN DE CANALES DE MONITOREO (Vale 33.33 puntos)
// ============================================================================
/*
  CONTEXTO[cite: 13]:
  En la terapia intensiva, cada paciente genera una cola de eventos[cite: 14]. 
  La primera mitad corresponde a mediciones biomédicas y la segunda mitad 
  a confirmaciones de laboratorio[cite: 14].
  Se necesita intercalar ambas mitades manteniendo el orden relativo[cite: 15].

  RESTRICCIONES[cite: 21]:
  - Se garantiza que la cantidad de elementos es par[cite: 22].
  - NO usar loops sobre punteros internos (¡Prohibido recorrer con ->next!)[cite: 23].
  - Solo usar operaciones públicas del ADT: enqueue, dequeue, front, isEmpty, size[cite: 24].
  - Se permite usar colas (queues) auxiliares.

  EJEMPLO[cite: 27]:
  Original:  [10, 20, 30, 100, 200, 300] 
  Resultado: [10, 100, 20, 200, 30, 300] 
*/

template <typename TData>
class Queue {
private:
    struct Node {
        TData data;
        Node* next;
        explicit Node(const TData& d) : data(d), next(nullptr) {}
    };
    Node* m_front;
    Node* m_back;
    std::size_t m_size;

public:
    Queue() : m_front(nullptr), m_back(nullptr), m_size(0) {}
    ~Queue() { while (!isEmpty()) dequeue(); }

    void enqueue(const TData& value) {
        Node* n = new Node(value);
        if (m_back) m_back->next = n;
        else m_front = n;
        m_back = n;
        ++m_size;
    }

    void dequeue() {
        if (isEmpty()) throw std::underflow_error("Queue vacia");
        Node* tmp = m_front;
        m_front = m_front->next;
        if (!m_front) m_back = nullptr;
        delete tmp;
        --m_size;
    }

    const TData& front() const {
        if (isEmpty()) throw std::underflow_error("Queue vacia");
        return m_front->data;
    }

    bool isEmpty() const { return m_front == nullptr; }
    std::size_t size() const { return m_size; }

    // ------------------------------------------------------------------------
    // IMPLEMENTAR PUNTO 1 [cite: 35, 136]
    // ------------------------------------------------------------------------
    void fusionarCanales() {
        // --- TU TAREA ---
        // Tu código acá...
        Queue<TData> mitad1; // va a contener la primera mitad de los elementos 
        Queue<TData> mitad2; // va a contener la segundo mitad de los elementos

        std::size_t mitad = size() / 2;

        for(std::size_t i = 0; i<mitad; i++){
            mitad1.enqueue(front()); //encolo el elemento del frente en mi cola nueva y asi hasta conteenr toda la primera mitad
            dequeue(); //desencolo para no repetir
        }
        
        for(std::size_t i = 0; i<mitad; i++){
            mitad2.enqueue(front()); //encolo el elemento del frente en mi cola nueva y asi hasta conteenr toda la primera mitad
            dequeue(); //desencolo para no repetir
        }

        while(mitad1.size() != 0){
            enqueue(mitad1.front());
            mitad1.dequeue();
            enqueue(mitad2.front());
            mitad2.dequeue();
        }
    }
};


// ============================================================================
// PUNTO 2: STACK - REORDENAMIENTO DE PROTOCOLOS CLÍNICOS (Vale 33.33 puntos)
// ============================================================================
/*
  CONTEXTO[cite: 224]:
  El stack de un dron médico contiene en el tope intervenciones inmediatas[cite: 226], 
  y debajo las de seguimiento[cite: 226]. Se necesita intercambiar ambas mitades 
  del stack manteniendo el orden interno de cada una[cite: 227].

  RESTRICCIONES[cite: 233]:
  - Se garantiza que la cantidad de elementos es par[cite: 234].
  - Solo usar operaciones públicas del ADT: push, pop, top, isEmpty, size[cite: 235].
  - Se permite usar stacks auxiliares[cite: 236].

  EJEMPLO[cite: 238]:
  Original:  tope -> [1, 2, 3, 4, 5, 6] [cite: 239]
  Resultado: tope -> [4, 5, 6, 1, 2, 3] [cite: 240]
*/

template <typename TData>
class Stack {
private:
    struct Node {
        TData data;
        Node* next;
        explicit Node(const TData& d) : data(d), next(nullptr) {}
    };
    Node* m_top;
    std::size_t m_size;

public:
    Stack() : m_top(nullptr), m_size(0) {}
    ~Stack() { while (!isEmpty()) pop(); }

    void push(const TData& value) {
        Node* n = new Node(value);
        n->next = m_top;
        m_top = n;
        ++m_size;
    }

    void pop() {
        if (isEmpty()) throw std::underflow_error("Stack vacio");
        Node* tmp = m_top;
        m_top = m_top->next;
        delete tmp;
        --m_size;
    }

    const TData& top() const {
        if (isEmpty()) throw std::underflow_error("Stack vacio");
        return m_top->data;
    }

    bool isEmpty() const { return m_top == nullptr; }
    std::size_t size() const { return m_size; }

    // ------------------------------------------------------------------------
    // IMPLEMENTAR PUNTO 2 [cite: 243, 334]
    // ------------------------------------------------------------------------
    void intercambiarMitades() {
        // --- TU TAREA ---
        // Tu código acá...
        Stack<TData> mitad1; // la primera mitad 
        Stack<TData> mitad2; // segunda mitad 

        std::size_t mitad = size()/2;

        for(std::size_t i = 0; i < mitad; i++){
            mitad1.push(top());  //pongo la primera mitad 
            pop(); // voy sacando de la original
        }

        for(std::size_t i = 0; i<mitad; i++){
            mitad2.push(top()); //pongo la segunda mitad
            pop(); //voy sacando de la original
        }

        while(!mitad1.isEmpty()){
            push(mitad1.top()); //pongo la primera mitad en la original
            mitad1.pop(); //voy eliminando de la primera mitad
        }

        while(!mitad2.isEmpty()){
            push(mitad2.top());
            mitad2.pop();
        }


    }
};


// ============================================================================
// PUNTO 3: DLL - REUBICAR BLOQUE INICIAL ESTABLE (Vale 33.33 puntos)
// ============================================================================
/*
  CONTEXTO[cite: 404]:
  La lista doblemente enlazada comienza con un bloque de observaciones repetidas[cite: 406].
  Se debe mover ese bloque maximal completo al final de la lista[cite: 410], 
  manteniendo su orden relativo interno[cite: 410].

  RESTRICCIONES[cite: 421]:
  - NO usar estructuras auxiliares (¡Prohibido crear otras listas!)[cite: 422].
  - NO crear ni destruir nodos (¡No usar 'new' ni 'delete'!)[cite: 423].
  - Solo re-enlazar punteros 'prev' y 'next' a mano[cite: 424].
  - Mantener correctos m_head, m_tail y m_size[cite: 425].

  EJEMPLO[cite: 411]:
  Original:  [120, 120, 120, 90, 91, 92] [cite: 412]
  Resultado: [90, 91, 92, 120, 120, 120] [cite: 412]
*/

template <typename TData>
class DLL {
private:
    struct Node {
        TData data;
        Node* next;
        Node* prev;
        explicit Node(const TData& d) : data(d), next(nullptr), prev(nullptr) {}
    };
    Node* m_head;
    Node* m_tail;
    std::size_t m_size;

public:
    DLL() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    ~DLL() { while (m_head) { Node* tmp = m_head; m_head = m_head->next; delete tmp; } }

    void pushBack(const TData& value) {
        Node* n = new Node(value);
        if (!m_tail) { m_head = m_tail = n; }
        else { n->prev = m_tail; m_tail->next = n; m_tail = n; }
        ++m_size;
    }

    void print() const {
        Node* cur = m_head;
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }

    std::size_t size() const { return m_size; }

    // ------------------------------------------------------------------------
    // IMPLEMENTAR PUNTO 3 [cite: 426, 552]
    // ------------------------------------------------------------------------
    void moverBloqueInicialAlFinal() {
        // --- TU TAREA ---
        // Tu código acá...

        if (m_head == m_tail || m_head == nullptr){
            return;
        }

        Node* aux = m_head; //nodo auxiliar que apunta a la cabeza para empezar a recorrer
        TData datita = m_head->data; //contiene el valor repetido del bloque

        // Buscamos avanzar aux hasta el final del bloque repetido
        while (aux->next != nullptr && aux->next->data == datita) {
            aux = aux->next;
        }

    // Si resulta que aux llegó hasta m_tail, significa que toda la lista es igual.
    // En ese caso, terminamos acá y no tocamos ningún puntero.
        if (aux == m_tail) {
            return;
        }
        //cuando no entro mas al while, significa que el ultimo que guardo el aux, es el ultimo elemento del bloque repetido
        
        m_tail->next = m_head; // hago que el que sigue de m_tail ya no apunte a nullptr sino que se conecte con la head
        m_head->prev = m_tail;
        // Hasta acá conectamos los extremos de la lista, falta cortarla al medio.

        // Acomodamos head
        m_head = aux->next; // aux apunta al ultimo del bloque repetido
        m_head->prev = nullptr;

        // Acomodamos tail
        m_tail = aux; // el ultimo es m_tail que en este momento es aux
        m_tail->next = nullptr;
    }
};

// ============================================================================
// MAIN DE PRUEBAS
// ============================================================================
int main() {
    cout << "Plantilla lista para iniciar las pruebas." << endl;
    return 0;
}