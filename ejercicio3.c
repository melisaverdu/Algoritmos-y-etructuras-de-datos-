/* Consigna: Crea una función llamada es_centenario que reciba un puntero a persona (de tu código anterior).

La función debe devolver true si la persona nació en 1926 o antes (asumiendo que estamos en 2026).

En el main, llama a esta función pasándole la dirección de p1 (que es una variable normal) y luego pasándole el puntero pp1 (que es dinámico).

Pista de sintaxis:

Para p1 (variable): es_centenario(&p1);

Para pp1 (puntero): es_centenario(pp1);

¿Cómo escribirías esa función es_centenario accediendo al campo anio dentro de la estructura anidada nac? Te leo para darte el aprobado final.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_PS 4

typedef struct {
       int dia;
       int mes;
       int anio;
} FECHA;

typedef struct {
       char nombre[20];
       FECHA nac;
       long int dni;
} persona;

void printfecha(FECHA *f){
     printf("dia:%d - mes:%d - anio:%d\n",f->dia,f->mes,f->anio);
}

//espera una dirección de memoria de tipo persona
void printpersona(persona *p){
    printf("nombre %s,dni %ld,nac:",p->nombre,p->dni);
    printfecha(&(p->nac)); //le paso la dirección de memoria del campo nac de p, porque printfecha espera una dirección de memoria de tipo fecha
}

void cargar_ps(persona *ps){
     int i;
     for(i=0;i<N_PS;i++){
        strcpy((ps+i)->nombre,"Luisa Castro");
        (ps+i)->dni=10998760+i;
        (ps+i)->nac.dia=10+i;
        (ps+i)->nac.mes=2;
        (ps+i)->nac.anio=1980;
     }
}

void print_ps(persona *ps){
     int i;
     for(i=0;i<N_PS;i++){
         printpersona(ps+i);
     }
}

int main(int argc, char *argv[])
{
     FECHA f1, f2;
     persona p1;
     persona *pp1;
	        
     pp1=(persona *)malloc(sizeof(persona)); //reserva en bytes el tamaño de "persona" y lo castea a un puntero de tipo persona
     //pp1 va a ser un puntero que va a apuntar a un lugar de la memoria, donde voy a poder guardar información del tipo persona
     // lo mismo es poner new persona

     //---------------------------------------------------------------------------------------------------------------------------------------------------------
     //le quiero cargar a f1 datos, lo hago con el operador punto porque f1 es una variable de tipo fecha
     f1.dia=12;
     f1.mes=3;
     f1.anio=1999;

     //le quiero cargar datos a p1, lo hago con el operador punto porque p1 es una variable de tipo persona
     //como esta definido como una tira de caracteres, uso la función strcpy para copiar la cadena "Juan Lopez" en el campo nombre de p1
     strcpy(p1.nombre,"Juan Lopez");

     //le quiero cargar datos a p1, tengo 3 variables dentro de p1, una es nombre (que ya la cargue), otra es dni y la otra es nac que es de tipo fecha
     //p1.nac es una variable de tipo fecha, entonces para cargar los datos de dia, mes y anio uso el operador punto dos veces
     p1.dni=12445099;
     p1.nac.dia=1;
     p1.nac.mes=12;
     p1.nac.anio=1999;
     //---------------------------------------------------------------------------------------------------------------------------------------------------------
     
     //le quiero cargar datos a pp1, como pp1 es un puntero uso el operador flecha ->
     //Por ejemplo quiero ir de los distintos bytes reservados en memoria para pp1 al campo nombre, entonces uso pp1->nombre


     strcpy(pp1->nombre,"Luisa Castro");
     pp1->dni=10998760;
     pp1->nac.dia=10; //pp1 es un puntero que le apunta al campo nacimiento, que es de tipo fecha, entonces uso el operador 
                      //flecha dos veces para llegar al campo dia, y luego el operador punto para asignarle el valor 10, ya que dia es una variable de tipo entero, no un puntero 
     pp1->nac.mes=2;
     pp1->nac.anio=1980;
     printpersona(&p1); //le paso la dirección de memoria de p1 con el operador &, porque eso es lo que espera la funcion
     printpersona(pp1); //pp1 ya es un puntero, por lo tanto no necesito usar el operador &
     free(pp1);
//   system("PAUSE");

     persona *ps;
						  
     ps=(persona *)malloc(sizeof(persona)*N_PS);
     cargar_ps(ps);
     print_ps(ps);
     free(ps);
//   system("PAUSE");

     return 0;
}
