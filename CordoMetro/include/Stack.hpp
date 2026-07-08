#pragma once
#include <cstddef>   // Para std::size_t
#include <cassert>   // Para assert


/*
El runner puede deshacer su ultimo viaje (volver a la estación de origen).
La estructura LIFO captura exactamente este comportamiento.
*/
template <typename T>
class Stack{
private:
    //Estructura para los eslabones o nodos de la pila
    struct Node{
        T value;
        Node* next;

        Node(T val, Node* nxt = nullptr) : value(val), next(nxt){}

    };

    Node* m_top             //puntero al nodo superior (el ultimo que entró)
    std::size_t m_size;     //contador de elementos para que size() sea o(1)

public:
    //constructor 
    Stack() : m_top(nullptr), m_size(0) {}

    // Destructor (¡fundamental para no dejar pérdidas de memoria!)
    ~Stack();

    // Interfaz mínima requerida por el CordoMetro
    void push(T value);
    void pop();
    T& top();
    const T& top() const;
    std::size_t size() const noexcept;
    bool isEmpty() const noexcept;
};

template <typename T>
void Stack<T>::push(T value){
    Node* nuevo = new Node(value, m_top); // reservo memoria para el nuevo nodo y engancho el puntero del top para que apunte a este nuevo y no a nullptr
    m_top = nuevo;
    m_size++;
}

template <typename T>
void Stack<T>::pop(){
    assert(!isEmpty()); // Si está vacía, el programa frena acá

    Node* temp = m_top; // guardo el de arriba de todo
    m_top = m_top->next; //l e asigno al tope el de abajo
    delete temp; // borramos de la memoria el viejo tope
    m_size--; //restamos uno al tamaña
    
}

template <typename T>
T& Stack<T>::top(){
    assert(!isEmpty());
    return m_top->value;
}

template <typename T>
const T& Stack<T>::top() const{
    assert(!isEmpty());
    return m_top->value;
}

template <typename T>
std::size_t Stack<T>::size() const noexcept{
    return m_size; //retorna el contador de elementos 
}

template <typename T>
bool Stack<T>:: isEmpty() const noexcept{
    return m_top==nullptr;
}

