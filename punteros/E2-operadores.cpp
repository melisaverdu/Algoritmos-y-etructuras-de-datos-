#include <iostream>
#include <string>
using namespace std;

struct Autor {
    string nombre;
    int anio_nacimiento;
};

struct Libro {
    string titulo;
    Autor* autor; // Puntero a otra estructura
    float precio;
};

void imprimir_ficha(Libro* l) {
    // TODO: Imprimir "Libro: [titulo], Autor: [nombre], Nacido en: [anio]"
    // Pista: l es puntero (usa ->), pero l->autor también es puntero.
    cout << "Libro: " << l->titulo << ", Autor: " << l->autor->nombre << ", Nacido en: " << l->autor->anio_nacimiento << endl;
}

int main() {
    // 1. Reserva memoria para un Libro
    Libro* miLibro = new Libro; //defino un puntero a Libro y le asigno memoria dinámica, ahi voy a guardar los datos del libro: titulo, autor y precio

    // 2. Reserva memoria para el Autor dentro de ese libro
    miLibro->autor = new Autor; //dentro del libro, el autor es un puntero, por lo que le asigno memoria dinámica para guardar los datos del autor: nombre y año de nacimiento

    // 3. Cargar datos (puedes inventarlos)
    miLibro->titulo = "Cien Años de Soledad";
    miLibro->autor->nombre = "Gabriel García Márquez";
    miLibro->autor->anio_nacimiento = 1927;
    miLibro->precio = 29.99;


    imprimir_ficha(miLibro);

    // 4. TODO: Liberar memoria en el orden correcto
    // Pista: ¿Qué pasa si borras miLibro antes de borrar miLibro->autor?
    
    return 0;
}