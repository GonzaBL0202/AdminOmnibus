#include "lineas.h"

//PRIMITIVAS
void Make(LineasABB &ABB){
    ABB=NULL;
}

boolean Member(LineasABB ABB, string clave){
    if(ABB == NULL)
        return FALSE;
    else{
        string aux;
        DarCodigo(ABB->info, aux);
        if(streq(aux, clave))
            return TRUE;
        else
            if(CodigoMayor(clave,aux))
                return Member(ABB->hder, clave);
            else
                return Member(ABB->hizq, clave);
        }
}

void Insert(LineasABB &ABB, string elem){

    if(ABB == NULL){
        nodo * nuevo = new nodo;
        ABB=nuevo;
        StrCrear(ABB->info.codigo);
        strcopDinamico(ABB->info.codigo, elem);
        ABB->info.paradas=0;
        ABB->info.Recorrido.prim=NULL;
        ABB->info.Recorrido.ult=NULL;
        ABB->hder=NULL;
        ABB->hizq=NULL;
    }
    else{
            string aux;
            StrCrear(aux);
            DarCodigo(ABB->info, aux);
            if(CodigoMayor(elem,aux))
                return Insert(ABB->hder, elem);
            else
                return Insert(ABB->hizq, elem);
        }
}


Linea Find(LineasABB ABB, string clave){
    string aux;
    DarCodigo(ABB->info, aux);
    if(streq(aux, clave))
        return ABB->info;
    else{
            if(CodigoMayor(clave,aux))
                return Find(ABB->hder, clave);
            else
                return Find(ABB->hizq, clave);
        }
}
void Modify(LineasABB &ABB, string codigo, Linea L ){
    string aux;
    DarCodigo(ABB->info, aux);
    if(streq(aux, codigo)){
        ABB->info.paradas=L.paradas;
        strcopDinamico(ABB->info.codigo, L.codigo);
        CopiarLista(ABB->info.Recorrido, L.Recorrido);
    }
    else{
            if(CodigoMayor(codigo,aux))
                return Modify(ABB->hder,codigo, L);
            else
                return Modify(ABB->hizq, codigo, L);
        }
}
void Delete(LineasABB &ABB, string clave){

}

//SELECTORAS
void DarCodigo (Linea L, string &s){
    StrCrear(s);
    strcopDinamico(s,L.codigo);
}

int DarParadas(Linea l){
    return (l.paradas);
}

//AUXILIARES

void MostrarLinea (Linea L){
    printf("\nCodigo:");
    print(L.codigo);
    printf("\n");
    printf("\nCantidad de paradas:%d\n", DarParadas(L));
}

//FUNCIONES

void RegistrarLinea (LineasABB &ABB, string codigo){
    if(!Member(ABB, codigo)){
        Insert(ABB, codigo);
        printf("\nSe registro correctamente la nueva linea\n");
    }

    else
        printf("\nERROR: Ya existe una linea con ese codigo alfanumerico\n");
}

void ListarLineas (LineasABB ABB){
    if (ABB != NULL){
        ListarLineas (ABB -> hizq);
        MostrarLinea(ABB->info);
        ListarLineas (ABB -> hder);
    }
}

void InsertarParada (Linea &L, Trayecto t, string codigo, Ciudad c){
       if(L.paradas==0){
            Parada nueva;
            nueva.info.nombre = c.nombre;
            nueva.info.numero = c.numero;
            nueva.num=1;
            InsBack(L.Recorrido,nueva);
            L.paradas++;
            printf("\nNueva parada registrada correctamente\n");
        }else{
            Parada par= DarUltima(L.Recorrido);
            if(PerteneceArista(t,par.info.numero, c.numero)){
                Parada nueva;
                nueva.info.nombre = c.nombre;
                nueva.info.numero = c.numero;
                nueva.num= par.num+1;

                InsBack(L.Recorrido,nueva);
                L.paradas++;
                printf("\nNueva parada registrada correctamente\n");
            }
            else
                printf("\nNo existe un tramo entre la ultima parada y la nueva\n");

}}


void RegistrarParada (LineasABB &ABB, Trayecto t, string codigo, Ciudad c){
    if(Member(ABB, codigo)){
        Linea L= Find(ABB, codigo);
        InsertarParada(L, t,codigo, c);
        Modify(ABB, codigo, L);
    }
    else
        printf("\nNo existe una linea con ese codigo\n");
}


void ListarRecorrido (LineasABB ABB, string codigo){
    Linea L=Find(ABB, codigo);
    if(L.paradas!=0)
        ListarParadas(L.Recorrido);
    else
        printf("\nLa linea aun no tiene paradas registradas\n");
}
