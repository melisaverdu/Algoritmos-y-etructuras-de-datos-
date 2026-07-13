#ifndef CORDOMETRO_HPP
#define CORDOMETRO_HPP

#include <string>
#include <memory> // Obligatorio para std::unique_ptr

namespace CordoMetro {

    // 1. Estructura de Dominio: Estacion
    struct Estacion { 
        std::string nombre;       // Ej: "Plaza Vélez Sársfield"
        int         tiempoSig;    // Minutos hasta la siguiente estación
        int         pasajerosEsp; // Pasajeros esperando en el andén
    };

    // 2. Estructura del Nodo de la Lista (Basado en el diseño del TP)
    template <typename T>
    struct Node {
        T m_value;
        std::unique_ptr<Node<T>> m_spNext; // El puntero inteligente al siguiente

        // Constructor simple para inicializar el nodo
        Node(const T& value) : m_value(value), m_spNext(nullptr) {}
    };

    // =========================================================================
    // 3. FIRMAS DE LAS FUNCIONES RECURSIVAS (Sección 2 del Enunciado)
    // =========================================================================

    // 2.1 Búsqueda con cortocircuito (DFS)
    // Al escribir inline, c++ permite escribir el cuerpo aca mismo sin romper nada 
inline const Node<Estacion>* findEstacion(const Node<Estacion>* node, const std::string& nombre){
        /*
            Buscar una estación por su nombre a lo largo del tren de nodos de la lista enlazada
        */
        if(node == nullptr){
            return nullptr;
        }
        if(node->m_value.nombre == nombre){
            return node;
        }
        if(node->m_value.nombre != nombre){
            return findEstacion(node->m_spNext.get(), nombre);
        }
    }

    // 2.2 Acumulación condicionada (Activación diferida)
inline int contarEstaciones(const Node<Estacion>* node, const std::string& origen, const std::string& destino, bool contando = false) {
    // Caso Base 1: Llegamos al final del subte y no hay más nada
        if (node == nullptr) {
            return 0;
        }

    // ¿Esta estación actual es el destino?
        if (node->m_value.nombre == destino) {
        // Si ya veníamos contando, o si justo el origen era igual al destino, esta estación cuenta como la última (+1) y frena la recursividad.
            if (contando || node->m_value.nombre == origen) {
                return 1; 
            }
            return 0; // Si llegamos al destino pero nunca pasamos por el origen, no cuenta.
        }

        // ¿Esta estación actual es el origen?
        if (node->m_value.nombre == origen) {
            // Encontramos el origen: esta estación cuenta (+1) y activamos "true" para las que siguen
            return 1 + contarEstaciones(node->m_spNext.get(), origen, destino, true);
        }

        // Si no es ni el origen ni el destino, es una estación intermedia. 
        // Su valor depende de si el interruptor "contando" ya estaba encendido:
        if (contando) {
            return 1 + contarEstaciones(node->m_spNext.get(), origen, destino, true);
        } else {
            // Si "contando" es false, ignoramos esta estación (0) y seguimos buscando el origen
            return contarEstaciones(node->m_spNext.get(), origen, destino, false);
        }
}

    // 2.3 Acumulación condicionada (Suma paramétrica de tiempos)
inline int calcularTiempoRuta(const Node<Estacion>* node, const std::string& origen, const std::string& destino, bool contando = false){
        //si llegamos al final y no hay mas nada
        if(node == nullptr){
            return 0;
        }
        //si encuentro el destino 
        if(node->m_value.nombre == destino){
            return 0;
        }
        //si encuentro el origen
        if(node->m_value.nombre == origen){
            return node->m_value.tiempoSig + calcularTiempoRuta(node->m_spNext.get(), origen, destino, true); //lo pongo en true para que empiece a contar ya que pase por el origen
        }
        //si esstoy en una estación intermedia o previa al origen
        if(contando){
            return node->m_value.tiempoSig + calcularTiempoRuta(node->m_spNext.get(), origen, destino, true);
        }else{
            return calcularTiempoRuta(node->m_spNext.get(), origen, destino, false); //porque todavía no pase por el origen lo pongo en false
        }

    }

} // namespace CordoMetro

#endif // CORDOMETRO_HPP