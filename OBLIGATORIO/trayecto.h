#ifndef TRAYECTO_H_INCLUDED
#define TRAYECTO_H_INCLUDED
#include "ciudades.h"

typedef int Trayecto [N][N];

//PRIMITIVAS
void CrearT (Trayecto &t);
//Crea un Trayecto vacio.
boolean PertVertice(Trayecto t, int clave );
//Determina si en el Trayecto existe el vertice especificado.
boolean PerteneceArista (Trayecto t, int clave, int clave2);
//Determina si en el Trayecto existe la arista especificada.
void InsertarArista (Trayecto &t, int clave, int clave2);
//Inserta la nueva arista al Trayecto. Precondicion: la arista no pertenece al Trayecto.
int GradoVertice (Trayecto t, int clave);
//Devuelve el grado del vertice especificado. Precondicion: el vertice pertenece al Trayecto.

//FUNCIONES

void RegistrarTramo (Trayecto &t, int n, int m);
//PRECONDICION: EL ARRELGO DE CIUDADES DEBE ESTAR LLENO
boolean ExisteCamino (Trayecto t, int u, int v);

//AUXUILARES
void DFS (Trayecto t, int actual, int v, boolean visitado [N]);
//PRECONDICION: EL ARRELGO DE CIUDADES DEBE ESTAR LLENO

#endif // TRAYECTO_H_INCLUDED