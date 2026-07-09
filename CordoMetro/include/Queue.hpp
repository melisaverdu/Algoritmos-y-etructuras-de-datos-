#pragma once
#include <cstddef>   // Para std::size_t
#include <cassert>   // Para assert

template <typename T>
class Queue{
private:
    //Estructura para los eslabones o nodos de la pila
    struct Node{
        T value;
        Node* next;

        Node(T val, Node* nxt = nullptr) : value(val), next(nxt){}

    };

    Node* first;             //puntero al nodo superior (el primero que entró)
    Node* last;              //puntero al nodo inferior (el ultimo que entró)
    std::size_t m_size;     //contador de elementos para que size() sea o(1)

public:
    Queue() : first(nullptr), last(nullptr), m_size(0){}

    void        enqueue(T value);  // agrega al final O(1)
    void        dequeue();         // elimina del frente O(1)
    T&          front();
    const T&    front() const;
    std::size_t size()  const noexcept;
    bool        isEmpty() const noexcept;


};

template <typename T>
void Queue<T>::enqueue(T value){
    //creo un nuevo nodo que sirve tanto para el if como para el else
    Node* nuevo = new Node(value);

    if(first==nullptr){
        first = nuevo;
        last = nuevo;
    }
    else{
        last->next = nuevo;
        last = nuevo;
        
    }

    m_size++;
}

template <typename T>
void Queue<T>::dequeue(){
    assert(!isEmpty());

    Node* temp = first;
    first = temp->next;

    /* hago esta verificación porque si estamos en un ultimo nodo 
    donde first y las apuntan a lo mismo, entonces cuando elimine temp
    last se queda apuntando a la nada, es como un puntero fantasma, entonces 
    ahi tengo que hacer también que last también sea nullptr*/

    if(first == nullptr){
        last = nullptr;
    }

    delete temp;
    m_size--;
}

template <typename T>
T& Queue<T>::front(){
    assert(!isEmpty());
    return first->value;
}

template <typename T>
const T& Queue<T>::front()const{
    assert(!isEmpty());
    return first->value;
}

template <typename T>
std::size_t Queue<T>::size()  const noexcept{
    return m_size;
}

template <typename T>
bool Queue<T>::isEmpty() const noexcept{
    return first == nullptr; // O m_size == 0, la que más te guste
}



