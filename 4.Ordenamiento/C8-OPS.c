// Metodo de Ordenamiento por Seleccion Directa
// Wirth pag. 68
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#define MAX 5000

void impre(int *v);

int main(int argc, char *argv[]){
  int i,j,pos,men,m=0,c=0;
  int a[MAX];//={50,40,30,20,10}; //
  
  for(i=0;i<MAX;i++){ //genera un arreglo aleatorio de MAX elementos 
       a[i]=int(rand());
  }
 
  impre(a);
 cout<<"\n---------------------------------"<<endl;

 //Los siguientes dos ciclos for signofican el grado de complejidad O(n**2)
 for(i=0;i<MAX;i++){ //Me sirve para recorrer todo el arreglo la primera vez, luego la segunda sin el primero, etc.
   men=a[i]; // 42 | 20 |
   pos=i; // 0 | 1 |
   m++;
   for(j=i+1;j<MAX;j++){ 
     c++;
     if(a[j]<men){ //20<42 si | 17<20 si |
       men=a[j]; //men=20 | men=17 |
       m++;
       pos=j; //pos=1 | pos=2 |
     }
   }
   a[pos]=a[i]; // a[1]=a[0] - 20=42 | a[2]=a[1] - 17=20 |
   m++ ;
   a[i]=men; // a[0]=20 | a[1]=17 |
   m++ ; 
 }
  impre(a);
// ---------       Mmin= 3(n-1)
// C= 1/2(n**2-n)  Mmed= ??
// --------------  Mmax= (n**2/4)+3(n-1)
 
  printf("\n cantidad de comparaciones= %d  movimientos= %d",c,m);
  printf("\n\n");
  system("PAUSE");	
  return 0;
}
void impre(int *v)
{ int i;
  printf("\n");
  for(i=0;i<MAX;i++)
     printf("\n %3d   %3d",i,v[i]);
}