void dfs(){
    //1.creamos el vector/ arreglo de visitados y lo ponemos en false
    bool visitados[V]; /* si es una estructura como un vector
    la declaro como std::vector<bool>visitados(V, false), con esto
    me ahorro el for de inicializacion
    */
   for(int i=0; i<v; i++){
    visitados[i]= false;
   }

   //recorro todo y me importan los que no estan visitados para llamar
   //la recursion
   for(int i=0; i<V;i++){
        if(!visitados[i]){
            //aca llamo a la recursión, normalmente con un if 
            if(dfsrec(son 3 datos uno va a ser i) == true (ej)){
                return algo lo que pida el ejercicio
            }
        }
   }

   //este dfs es bool no void
}

bool dfsrec(u es donde empiezo){
    
}