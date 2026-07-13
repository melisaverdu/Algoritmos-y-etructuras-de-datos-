/**
 * ============================================================================
 * SIMULACIÓN PARCIAL 1 - ALGORITMOS Y ESTRUCTURAS DE DATOS
 * FCEFyN - UNC
 * ============================================================================
 * Instrucciones: Resolvé los problemas de programación completando el código
 * donde corresponda y pensá las respuestas de opción múltiple al final.
 */

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// PUNTO 1: POLIMORFISMO Y CLASES DERIVADAS (Vale 30 puntos)
// ============================================================================
/*
  ENUNCIADO:
  En un sistema de monitoreo de pacientes en un sanatorio, los sensores envían 
  datos de diferentes tipos: temperatura, presión y pulso. Se requiere un sistema 
  que almacene distintos tipos de sensores como objetos polimórficos.
  
  Implementá una jerarquía de clases donde 'Sensor' es una clase base con una 
  función virtual pura 'leer()'. Derivá al menos dos clases ('SensorTemperatura' 
  y 'SensorPresion') que sobreescriban este método retornando "Presion" para el 
  caso del SensorPresion y "Temperatura" para el SensorTemperatura.
*/

class Sensor {
public:
    // NOTA: 'leer' debe retornar una referencia constante a string y ser virtual pura.
    virtual const string& leer() const = 0;
    
    // Destructor virtual por defecto (buena práctica obligatoria en polimorfismo)
    virtual ~Sensor() = default;
};

// --- TU TAREA (PUNTO 1) ---
// Implementá acá abajo las clases 'SensorPresion' y 'SensorTemperatura'
// Recordá almacenar el string correspondiente y usar 'override'.

// class SensorPresion ...
// class SensorTemperatura ...

// 1. Clase SensorPresion que hereda de Sensor
class SensorPresion : public Sensor {
private:
    string dato; // Variable para guardar el texto

public:
    // Constructor: apenas nace el objeto, le cargamos "Presion"
    SensorPresion() : dato("Presion") {}

    // Sobreescribimos el método obligatorio de la clase base
    const string& leer() const override {
        return dato;
    }
};

// 2. Clase SensorTemperatura que hereda de Sensor
class SensorTemperatura : public Sensor {
private:
    string dato; // Variable para guardar el texto

public:
    // Constructor: apenas nace el objeto, le cargamos "Temperatura"
    SensorTemperatura() : dato("Temperatura") {}

    // Sobreescribimos el método obligatorio de la clase base
    const string& leer() const override {
        return dato;
    }
};


// ============================================================================
// PUNTO 2: IMPLEMENTACIÓN DE COLA (FIFO) (Vale 30 puntos)
// ============================================================================
/*
  ENUNCIADO:
  Dada la siguiente implementación base para una Cola, implementá la función 
  'encolar' para agregar un elemento en base al patrón de acceso FIFO (First In, First Out).
*/

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int a) : dato(a), siguiente(nullptr) {}
};

class Cola {
private:
    Nodo* inicio;
    Nodo* final;

public:
    Cola() : inicio(nullptr), final(nullptr) {}
    
    ~Cola() {
        Nodo* temp = inicio;
        while (temp != nullptr) {
            Nodo* aux = temp;
            temp = temp->siguiente;
            delete aux;
        }
    }

    void imprimir() {
        Nodo* temp = inicio;
        cout << "Cola -> ";
        while (temp != nullptr) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        cout << "FINAL\n";
    }

    // --- TU TAREA (PUNTO 2) ---
    // Implementá el método encolar respetando el comportamiento FIFO
    void encolar(int valor) {
        // Tu código acá...
        Nodo* temp = new Nodo(valor);
        if(inicio ==  nullptr){
            inicio = temp;
            final = temp;
        }else{
            final->siguiente = temp;
            final = temp;
        }
    }
};




// ============================================================================
// FUNCIÓN MAIN (Para probar tus soluciones en VS Code)
// ============================================================================
int main() {
    cout << "--- probando punto 1 (polimorfismo) ---\n";
    /* Descomentá esto cuando implementes las clases del Punto 1:
    Sensor* s1 = new SensorPresion();
    Sensor* s2 = new SensorTemperatura();
    cout << "Sensor 1 dice: " << s1->leer() << endl; // Debería decir Presion
    cout << "Sensor 2 dice: " << s2->leer() << endl; // Debería decir Temperatura
    delete s1;
    delete s2;
    */

    cout << "\n--- probando punto 2 (cola fifo) ---\n";
    Cola miCola;
    miCola.encolar(12);
    miCola.encolar(99);
    miCola.imprimir(); // Debería mostrar: Cola -> 12 -> 99 -> FINAL

    return 0;
}




/* ============================================================================
 * SECCIÓN TEÓRICA: PREGUNTAS DE OPCIÓN MÚLTIPLE
 * ============================================================================
 * Escribí al lado o abajo de cada pregunta cuál considerás que es la opción correcta.
 
 PREGUNTA 3:
 ¿Cuál de las siguientes situaciones es un ejemplo natural donde una Pila (Stack) 
 sería la estructura de datos más adecuada? [cite: 158]
 
 a. Administrar tareas en un sistema operativo, donde las tareas se procesan en el orden en que llegan. [cite: 159]
 b. Imprimir documentos en una impresora compartida. [cite: 160]
 c. Implementar la función "deshacer" (undo) en un editor de texto o una aplicación de diseño. [cite: 161]
 d. Procesar clientes en una fila de supermercado. [cite: 162]
 
 RESPUESTA: c


 PREGUNTA 4:
 Durante una tormenta solar, la nave CONAE-Marte pierde contacto temporal con Tierra. [cite: 166]
 Cuando la conexión se restablece, los comandos recibidos se almacenan en una cola para su ejecución en orden. [cite: 167]
 Se reciben los siguientes comandos, en este orden:
   1. "Reiniciar antena" [cite: 169]
   2. "Verificar señal" [cite: 170]
   3. "Reestablecer frecuencia" [cite: 171]
 ¿Qué comando se ejecuta primero si se respeta el comportamiento de la estructura usada? [cite: 172]
 
 a. "Verificar señal" [cite: 173]
 b. "Reestablecer frecuencia" [cite: 174]
 c. "Reiniciar antena" [cite: 175]
 d. No se puede saber, depende de la prioridad de cada comando [cite: 176]
 
 RESPUESTA: 1


 PREGUNTA 5:
 ¿Cuál estructura sería más adecuada para almacenar los paquetes en un robot repartidor 
 que sigue una ruta definida, y debe entregarlos en el orden en que fueron cargados? [cite: 184]
 
 a. Stack [cite: 185]
 b. Queue [cite: 186]
 c. Reverse List [cite: 187]
 d. List [cite: 188]
 
 RESPUESTA: Queue
*/