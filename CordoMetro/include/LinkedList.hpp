#pragma once
#include <cstddef>   // Para std::size_t
#include <cassert>   // Para assert

template <typename T>
class LinkedList{
private:
    struct Node{
        T value;
        Node* next;

        Node(T val, Node* nxt = nullptr) : value(val), next(nxt){}

    };

    Node* m_head;   //apunta a la cabeza de la lista
    Node* m_tail;   //apunta al final de la lista 
    std::size_t m_size;     //contador de elementos para que size() sea o(1)

public:
    LinkedList() : m_head(nullptr), m_tail(nullptr), m_size(0){}

    class Iterator {
    private:
        Node* current; // El nodo real en el que está parado el iterador
    public:
        Iterator(Node* node) : current(node) {}

        // Operador * (para obtener el valor: *it)
        T& operator*() { return current->value; }

        // Operador ++ (para avanzar al siguiente: ++it)
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        // Operador != (para comparar en el bucle: it != end())
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // La línea de metro es una secuencia ordenada de estaciones. Se agregan al final al construir
    // la red, y se recorren para calcular rutas.
    void        pushBack(T value);       // O(1) con tail pointer
    void        pushFront(T value);      // O(1)
    void        popFront();              // O(1)
    T&          front();                 // referencia al primero
    const T&    front() const;
    std::size_t size()  const noexcept;
    bool        isEmpty() const noexcept;
    Iterator    begin();
    Iterator    end();

};

template<typename T>
void LinkedList<T>::pushBack(T value){
    Node* nuevo = new Node(value);

    if(m_head==nullptr){
        m_head = nuevo;
        m_tail = nuevo;
    }
    else{
        m_tail->next = nuevo;
        m_tail = nuevo;
    }

    m_size++;

}

template<typename T>
void LinkedList<T>::pushFront(T value){
    Node* nuevo = new Node(value);

    if(m_tail == nullptr){
        m_head = nuevo;
        m_tail = nuevo;
    }
    else{
        nuevo->next = m_head;
        m_head = nuevo;
    }

    m_size++;
}

template<typename T>
void LinkedList<T>::popFront(){
    assert(!isEmpty());

    Node* temp = m_head;
    m_head = m_head->next;

    if(m_head == nullptr){
        m_tail = nullptr;
    }
    delete temp;
}

template <typename T>
T& LinkedList<T>::front() {
    assert(!isEmpty());
    return m_head->value;
}

template <typename T>
const T& LinkedList<T>::front() const{
    assert(!isEmpty());
    return m_head->value;
}

template <typename T>
std::size_t LinkedList<T>::size()  const noexcept{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty()const noexcept{
    return m_head == nullptr;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
    return Iterator(m_head); // Arranca en el primero
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() {
    return Iterator(nullptr); // El fin es el pasado el último (nullptr)
}