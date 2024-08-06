#ifndef PARADAS_H_INCLUDED
#define PARADAS_H_INCLUDED

#include "ciudades.h"

typedef struct {
	int num;
	Ciudad info;
}Parada;

typedef struct nodoPar{
	Parada info;
	nodoPar * ant;
	nodoPar * sig;
}Nodo;

typedef struct {
	Nodo * prim;
	Nodo * ult;
} ParadasL;

void CrearP (ParadasL &s);
//Crear la ParadasL vacia
void InsFront (ParadasL &s);
//Inserta un elemento al inicio
void InsBack (ParadasL &s, Parada Par);
boolean EsVacia (ParadasL s);
//Determina si la ParadasL es vacia
Parada Primero (ParadasL S);
//Devuelve el primer elemento
void Resto (ParadasL &s);
//modifica la ParadasL retirando el primer elemento
int Largo (ParadasL S);
//Devuelve el largo de la ParadasL
Parada K_esimo (ParadasL s, int k);
//Devuelve el elemento indicado

//AUXILIARES

void CopiarLista(ParadasL &P, ParadasL aux);

Parada DarUltima (ParadasL P);

void MostrarParada (Parada p);

void ListarParadas (ParadasL p);


#endif // PARADAS_H_INCLUDED