#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string> // Añadido para manejar el nombre del empleado

using namespace std;

// =========================================================
// CLASE TIEMPO (Necesaria para representar horas)
// =========================================================
class Tiempo {
public:
    Tiempo(int = 0, int = 0, int = 0); 
    ~Tiempo(); 
    
    void estableceHora(int, int, int); 
    void estableceHora1(int);   
    void estableceMinuto(int);  
    void estableceSegundo(int); 

    int obtieneHora1();    
    int obtieneMinuto();   
    int obtieneSegundo();  

    void imprimeUniversal();    
    void imprimeEstandar();    

private:
    int hora;     // 0 - 23
    int minuto;   // 0 - 59
    int segundo;  // 0 - 59
};

// --- Implementación de Tiempo ---
Tiempo::Tiempo(int hr, int min, int seg) { estableceHora(hr, min, seg); }
Tiempo::~Tiempo() { }

void Tiempo::estableceHora(int h, int m, int s) { 
    estableceHora1(h); estableceMinuto(m); estableceSegundo(s); 
}
void Tiempo::estableceHora1(int h) { hora = (h >= 0 && h < 24) ? h : 0; }
void Tiempo::estableceMinuto(int m) { minuto = (m >= 0 && m < 60) ? m : 0; }
void Tiempo::estableceSegundo(int s) { segundo = (s >= 0 && s < 60) ? s : 0; }
int Tiempo::obtieneHora1() { return hora; }
int Tiempo::obtieneMinuto() { return minuto; }
int Tiempo::obtieneSegundo() { return segundo; }

void Tiempo::imprimeEstandar() {
    cout << ((hora == 0 || hora == 12) ? 12 : hora % 12)
         << ":" << setfill('0') << setw(2) << minuto
         << ":" << setw(2) << segundo << (hora < 12 ? " AM" : " PM");
}

// =========================================================
// TU NUEVA CLASE: Semana_Laboral
/*
Esta clase debe contener:
- Atributos para el nombre del empleado y su documento de identidad.
- Un arreglo bidimensional de objetos Tiempo para almacenar las horas de ingreso y salida de cada día
    de la semana laboral (5 días, 2 eventos por día).
- Métodos para:
    - Establecer las horas de ingreso y salida para cada día.
    - Calcular el total de horas trabajadas en la semana.
    
*/
// =========================================================
class Semana_Laboral {
private:
    string nombreEmpleado;
    long int documento;
    // Arreglo de 5 días (filas) x 2 eventos [Ingreso, Salida] (columnas)
    Tiempo horario[5][2]; 

public:
    // TODO: Implementar constructor
    Semana_Laboral(string nombre, long int doc){
        //lo que hago en el constructor es recibir el nombre y el documento del empleado, y asignarlos a los atributos de la clase
        nombreEmpleado = nombre;
        documento = doc;
    }

    // TODO: Método para setear la hora de ingreso y de salida para cada día
    //tomo como día 0=Lunes, 1=Martes, 2=Miércoles, 3=Jueves, 4=Viernes
    //tomo como tipo 0=Ingreso, 1=Salida
    void setHorario(int dia, int tipo, int hora, int minuto);

    //obtener el número total de horas y minutos trabajados en la semana
    void calcularHorasTrabajadas();
};

void Semana_Laboral::setHorario(int dia, int tipo, int hora, int minuto){
    //establezco día y horario en el arreglo, lo hago con el método de la clase Tiempo, ya que el arreglo es de tipo Tiempo y uso sus métodos
    horario[dia][tipo].estableceHora(hora, minuto, 0); //segundos en 0
}

void Semana_Laboral::calcularHorasTrabajadas(){
    int minutosTotales = 0;
    for(int i=0; i<5; i++){ //recorro los 5 días
        int minutosIngreso = horario[i][0].obtieneHora1() * 60 + horario[i][0].obtieneMinuto();
        int minutosSalida = horario[i][1].obtieneHora1() * 60 + horario[i][1].obtieneMinuto();

        minutosTotales += (minutosSalida - minutosIngreso);
    }

    int horasTrabajadas = minutosTotales / 60;
    int minutosRestantes = minutosTotales % 60;

    cout << "Empleado: " << nombreEmpleado << " (Documento: " << documento << ")" << endl;
    cout << "Total horas trabajadas en la semana: " << horasTrabajadas << " horas y " << minutosRestantes << " minutos." << endl;
}
// =========================================================
// MAIN LIMPIO
// =========================================================
int main(int argc, char *argv[]) {
    
    // Aquí puedes crear tu objeto Semana_Laboral y probar los métodos
    Semana_Laboral empleado1("Ariel Verdu", 16655890);
    empleado1.setHorario(0, 0, 9, 0); // Lunes Ingreso 9:00
    empleado1.setHorario(0, 1, 17, 0); // Lunes Salida 17:00
    empleado1.setHorario(1, 0, 9, 15); // Martes Ingreso 9:15
    empleado1.setHorario(1, 1, 17, 0); // Martes Salida 17:00

    empleado1.calcularHorasTrabajadas();

    cout << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}