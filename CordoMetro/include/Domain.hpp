#pragma once

#include <string>

struct Estacion
{
    std::string nombre;
    int tiempoSig;
    int pasajerosEsp;
};

struct Pasajero
{
    std::string nombre;
    std::string destino;
    int prioridad;
};

struct Viaje
{
    std::string origen;
    std::string destino;
    int duracionMin;
    std::string fecha;
};