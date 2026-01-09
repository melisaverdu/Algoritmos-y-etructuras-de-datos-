#include <iostream>

using namespace std;

// Función que duplica el tamaño de un arreglo dinámico
int* expandir_arreglo(int* arreglo_original, int tam_actual, int &nuevo_tam) {
    nuevo_tam = tam_actual * 2;
    
    // 1. Reservar memoria en el HEAP para el nuevo tamaño
    int* nuevo_arreglo = new int[nuevo_tam]; // TODO: Usa 'new' para crear un arreglo de tamaño 'nuevo_tam'

    // 2. Copiar los datos del viejo al nuevo usando un bucle
    for (int i = 0; i < tam_actual; i++) {
        // TODO: Copia arreglo_original[i] en nuevo_arreglo[i]
        nuevo_arreglo[i]= arreglo_original[i];
    }

    // 3. Inicializar el resto del nuevo arreglo con ceros
    for (int i = tam_actual; i < nuevo_tam; i++) {
        // TODO: Pon un 0 en las posiciones nuevas
        nuevo_arreglo[i]=0;
    }

    // 4. LIBERAR la memoria del arreglo original para evitar fugas (Memory Leak)
    // TODO: Usa 'delete []' sobre arreglo_original
    delete [] arreglo_original;
    // 5. Retornar el nuevo puntero
    return nuevo_arreglo;
}

int main() {
    int tam = 4;
    int n_tam = 0;
    
    // Creamos el arreglo inicial en el Heap
    int* v = new int[tam]{10, 20, 30, 40};

    cout << "Arreglo original: ";
    for(int i=0; i<tam; i++) cout << v[i] << " ";
    cout << endl;

    // Llamamos a la función
    v = expandir_arreglo(v, tam, n_tam);

    cout << "Arreglo expandido: ";
    for(int i=0; i<n_tam; i++) cout << v[i] << " ";
    cout << endl;

    // Limpieza final
    delete[] v;

    return 0;
}
