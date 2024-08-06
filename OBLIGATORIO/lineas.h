#ifndef LINEAS_H_INCLUDED
#define LINEAS_H_INCLUDED

#include "paradas.h"
#include "trayecto.h"

typedef struct{
		string codigo;
		int paradas;
		ParadasL Recorrido;
}Linea;

typedef struct NodoB {
	Linea info;
	NodoB * hizq;
	NodoB * hder;
} nodo;

typedef nodo * LineasABB;

void Make(LineasABB &d);
// Crear el LineasABB vacio
boolean Member(LineasABB d, string clave);
//determina si existe un elemento  con cierta clave en el LineasABB
void Insert(LineasABB &d, Linea elem);
// inserta el elemento en el LineasABB. Precondicion No exista elemento con la misma clave.
Linea Find(LineasABB d, string clave);
// Devuelve el elemento del LineasABB con esa clave. Precondicion: el elemento con dicha clave existe
void Modify(LineasABB &d, string codigo, Linea L);
// modificar elemento del LineasABB. Precond: debe existir el elemento
void Delete(LineasABB &d, string clave);
 // eliminar elemento del LineasABB.
//Precond: debe existir el elemento con dicha clave


//SELECTORAS

int DarParadas(Linea l);

void DarCodigo (Linea L, string &s);

//AUXILIARES

 void MostrarLinea (Linea L);


 //FUNCIONES

void RegistrarLinea (LineasABB &ABB, string codigo);
void ListarLineas (LineasABB ABB);
void RegistrarParada (LineasABB &ABB, Trayecto t, string codigo, Ciudad c);
void ListarRecorrido (LineasABB ABB, string codigo);

#endif // LINEAS_H_INCLUDED