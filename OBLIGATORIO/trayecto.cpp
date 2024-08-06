#include "trayecto.h"

//PRIMITIVAS
void CrearT (Trayecto &t){
    for(int i=0; i<N; i++){
       for(int j=0;j<N;j++)
            t[i][j]=0;
    }

}

boolean PertVertice(Trayecto t, int clave ){
    return boolean (clave < N);
}

boolean PerteneceArista (Trayecto t, int clave, int clave2){
    if (t[clave-1][clave2-1]==1)
        return TRUE;
    else
        return FALSE;
}


void InsertarArista (Trayecto &t, int clave, int clave2){
   t[clave][clave2]=1;
}

int GradoVertice (Trayecto t, int clave){
int cant=0;
    for(int i=0;i<N;i++){
        if(t[clave][i]==1)
            cant++;
    }
    if(t[clave][clave]==1)
        cant++;
return cant;
}

//FUNCIONES

void RegistrarTramo (Trayecto &t, int n, int m){
    if(t[n-1][m-1]!=1){
         t[n-1][m-1]= 1;
         t[m-1][n-1]= 1;
         printf("\nSe registro correctamente el tramo\n");
    }
    else
        printf("\nERROR: Ya existe este tramo\n");
}

boolean ExisteCamino (Trayecto t, int u, int v) {

     if(t[u-1][v-1]==1)
        return TRUE;
     else{
         boolean visitado [N];
         for (int i = 0; i < N; i++)
            visitado [i] = FALSE;
         DFS (t, u-1, v-1, visitado);
          return visitado[v-1];
}

}

//AUXILIARES
void DFS (Trayecto t, int actual, int v, boolean visitado [N]){
 visitado [actual] = TRUE;
 int j = 0;
 while (j < N && !visitado [v]){
    if (t [actual][j] == 1){
        if (!visitado [j])
            DFS (t, j, v, visitado);
    }
 j++;
 }
}

