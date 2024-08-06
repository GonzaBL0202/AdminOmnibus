#ifndef CIUDADES_H_INCLUDED
#define CIUDADES_H_INCLUDED

#include "StringDinamico.h"

const int N = 5;

typedef struct {
	int numero;
	string nombre;
}Ciudad;

typedef struct {
		Ciudad info [N];
		int tope;
} Ciudades;


void CrearC (Ciudades &s);
//Crear la ciudades vacia
void InsFront (Ciudades &s, Ciudad c);
//Inserta un elemento al inicio
boolean EsVacia (Ciudades s);
//Determina si la ciudades es vacia
Ciudad Primero (Ciudades S);
//Devuelve el primer elemento
void Resto (Ciudades &s);
//modifica la ciudades retirando el primer elemento
int Largo (Ciudades S);
//Devuelve el largo de la ciudades
Ciudad K_esimo (Ciudades s, int k);
//Devuelve el elemento indicado

//AUXILIARES
void MostrarCiudad (Ciudad C);
boolean ExisteCiudad (Ciudades C, string nom);

//SELECTORAS

int DarNumeroC(Ciudad c);
void DarNombre (Ciudad C, string &s);

//FUNCIONES
void CargarCiudad (Ciudades &C, string nom);
void ListarCiudades (Ciudades c);

#endif // CIUDADES_H_INCLUDED
