#include "paradas.h"

void CrearP (ParadasL &p){
    p.prim=NULL;
    p.ult=NULL;
}

void InsFront (ParadasL &p, Parada par){
    if (p.prim == NULL){
        Nodo * nuevo = new Nodo;
        nuevo->info=par;
        nuevo->sig=NULL;
        nuevo->ant=NULL;
        p.prim = nuevo;
        p.ult = nuevo;
    }
    else{
        Nodo * nuevo = new Nodo;
        nuevo->info = par;
        nuevo->ant=NULL;
        nuevo->sig= p.prim;
        p.prim=nuevo;
    }

}

void InsBack (ParadasL &p, Parada Par){
     if (p.prim== NULL){
        Nodo * nuevo = new Nodo;
        nuevo->info=Par;
        nuevo->sig=NULL;
        nuevo->ant=NULL;
        p.prim = nuevo;
        p.ult = nuevo;
    }
    else{
        Nodo * nuevo = new Nodo;
        nuevo->info = Par;
        nuevo->ant=p.ult;
        nuevo->sig= NULL;
        p.ult=nuevo;
    }
}

boolean EsVacia (ParadasL p){
    if (p.prim==NULL && p.ult==NULL)
        return TRUE;
    else
        return FALSE;
}

Parada Primero (ParadasL p){
    return p.prim->info;
}

void Resto (ParadasL &p){
    p.prim=p.prim->sig;
    p.prim->ant->sig=NULL;
    p.prim->ant=NULL;
}

int Largo (ParadasL p){
    int cant=0;
        while(p.prim != NULL){
             p.prim=p.prim->sig;
             cant++;
        }
    return cant;
}

Parada K_esimo (ParadasL p, int k){
    int largo = Largo(p);
    int diptancia= largo - k;
    if(diptancia < largo/2 ) {
        while(diptancia > 0)
            p.prim=p.prim->sig;
        return p.prim->info;
    }
    else{
        while(diptancia > 0)
            p.ult=p.ult->ant;
        return p.ult->info;
    }
}

//AUXILIARES

void CopiarLista(ParadasL &P, ParadasL aux){
    while (aux.prim!=NULL){
        InsBack(P, aux.prim->info);
        aux.prim=aux.prim->sig;
    }

}


Parada DarUltima (ParadasL P){
    return (P.ult->info);
};

void MostrarParada (Parada p){
    printf("\nLa parada %d es en la ciudad: %d- ", p.num, p.info.numero);
    print(p.info.nombre);
    printf("\n");
}

void ListarParadas (ParadasL p){
    while(p.prim != NULL){
        MostrarParada(p.prim->info);
        p.prim=p.prim->sig;
    }
}
