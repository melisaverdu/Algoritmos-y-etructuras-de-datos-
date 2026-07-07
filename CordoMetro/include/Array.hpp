#pragma once

#include <cstddef>   // std::size_t
#include <cassert>   // assert
//En un template la implementación va debajo de la clase en el mismo archivo.hpp
template <typename T, std::size_t N>
class Array{

private:
    T datos[N];

public:
    class Iterator {
    private:
        T* m_ptr; // Puntero al elemento actual del arreglo 
    public:
        // Constructor para inicializar el puntero
        Iterator(T* ptr) : m_ptr(ptr) {}

        // Operadores mínimos para que sea un iterador:
        // 1. Desreferencia (para ver o modificar el valor) -> operator*
        // 2. Avance (para los bucles) -> operator++
        // 3. Comparación (para saber si llegamos al final) -> operator!=
    };
    T& operator[](std::size_t i);
    const T& operator[](std::size_t i) const;

    constexpr std::size_t size() const noexcept;

    void fill(const T& value);

    Iterator begin();
    Iterator end();


};

template<typename T, std::size_t N>
constexpr std::size_t Array<T, N>::size() const noexcept
{
    return N;
}

template<typename T, std::size_t N>
T& Array<T, N>::operator[](std::size_t i){
    //assert sirve para verificar que una condición sea verdadera mientras el programa se esta ejecutando 
    assert(i<N); 
    return datos[i];
    
}

template<typename T, std::size_t N>
const T& Array<T, N>::operator[](std::size_t i) const{
    assert(i<N); 
    return datos[i];
}

template<typename T, std::size_t N>
void Array<T, N>::fill(const T& value){
    for(std::size_t i=0; i<N; ++i){
        datos[i] = value;
    }
}

template<typename T, std::size_t N>
typename Array<T, N>::Iterator Array<T, N>::begin() {
    return Iterator(&datos[0]); //llamo al constructor de mi clase interna Iterator, para que el constructor de esa función
                               //inicialice su miembro privado m_ptr que es un puntero al primer elemento del arreglo.
}

template<typename T, std::size_t N>
typename Array<T, N>::Iterator Array<T, N>::end(){
    return Iterator(&datos[N]);
}

template<typename T, std::size_t N>
typename Array<T, N>::Iterator Array<T, N>::end(){
    return Iterator(&datos[N-1]);
}
