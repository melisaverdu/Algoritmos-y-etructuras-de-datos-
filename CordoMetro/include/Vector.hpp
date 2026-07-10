#pragma once
#include <cstddef>   // Para std::size_t
#include <cassert>   // Para assert

template <typename T>
class Vector {
private:
    T* m_data;
    std::size_t m_size;
    std::size_t m_capacity;

public:
    Vector() : m_size(0), m_capacity(4) {
        m_data = new T[m_capacity]; // Reservamos un bloque de 4 "departamentos" juntos
    }

    /*
        El mapa completo de la red necesita acceso aleatorio: "dame la linea 3"
        sin recorrer todas las anteriores.
    */
    using Iterator = T*; //este es un alias que le dice a c++ que Iterator es un puntero comun 
    void        pushBack(T value);          // expande si necesario (x2)
    void        popBack();
    T&          operator[](std::size_t i);
    const T&    operator[](std::size_t i) const;
    std::size_t size()     const noexcept;
    std::size_t capacity() const noexcept;
    bool        isEmpty()  const noexcept;
    Iterator    begin();
    Iterator    end();

};

template<typename T>
void Vector<T>::pushBack(T value){
//añade un elemento 
    if(m_size == m_capacity){
        resize(m_capacity*2); //es un método privado para duplicar la memoria si se requiere
    }

    m_data[m_size]=value;
    m_size++;

}

template<typename T>
void Vector<T>::popBack(){
//elimina el último elemento del vector 
    //no se pueden borrar elementos si está vacío
    assert(m_size > 0);
    m_size--;
}

template<typename T>
T& Vector<T>::operator[](std::size_t i){
/* Dado el índice i, calcular instantáneamente la dirección exacta de memoria de ese
casillero, meterse adentro y devolver una referencia del objeto que está ahi
En este que no tengo el const, tiene la opción de modificarlo
*/

    assert(i < m_size); //si la posicion que tengo que buscar es menor al m_size, todo ok
    return m_data[i];

}

template<typename T>
const T& Vector<T>::operator[](std::size_t i) const{
    //no me deja modificar nada
    assert(i < m_size); //si la posicion que tengo que buscar es menor al m_size, todo ok
    return m_data[i];

}

template<typename T>
std::size_t Vector<T>::size() const noexcept{
    return m_size;
}

template<typename T>
std::size_t Vector<T>::capacity() const noexcept{
    return m_capacity;
}

template<typename T>
bool Vector<T>::isEmpty() const noexcept{
    return m_size == 0;
}

/*
En las otras clases tuvimos que crear una clase dentro de la clase, como en la LinkedList
porque los nodos estaban sueltos y el operador ++ tenia que saltar siguiendo la flecha .next
Pero en un vector los elementos están pegados uno al lado del otro en la memoria, por lo tanto 
Iterator será un simple puntero T*
*/
template<typename T>
typename Vector<T>::Iterator Vector<T>::begin(){
    return m_data; // Apunta al primer elemento (índice 0)
}

template<typename T>
typename Vector<T>::Iterator Vector<T>::end(){
    return m_data + m_size; // Apunta al casillero "pasado el último"
}