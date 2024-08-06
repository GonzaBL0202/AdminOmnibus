#include "ciudades.h"

//PRIMITIVAS
void CrearC (Ciudades &c){
    c.tope=0;
}

void InsFront (Ciudades &c, Ciudad C){
    c.tope++;
    for(int i=1;i<c.tope;i++)
        c.info[i]=c.info[i-1];
    c.info[0]=C;
}

boolean EsVacia (Ciudades c){
    return boolean (c.tope == 0);
}

Ciudad Primero (Ciudades c){
    return c.info[0];
}
void Resto (Ciudades &c){
    for(int i=0;i<c.tope;i++)
        c.info[i]=c.info[i+1];
    c.tope--;
}
int Largo (Ciudades c){
    return c.tope;
}
Ciudad K_esimo (Ciudades c, int x){
    return c.info[x];
}

//AUXILIARES
void MostrarCiudad (Ciudad C){
    printf("%d-", C.numero );
    print(C.nombre);
    printf("\n");
}

boolean ExisteCiudad (Ciudades C, string nom){
    boolean existe=FALSE;
    int i=0;
    while(i<C.tope && !existe){
        if(streq(C.info[i].nombre,nom))
            existe = TRUE;
        else
            i++;
    }
    return existe;
}

//SELECTORAS
int DarNumeroC(Ciudad c){
    return(c.numero);
}

void DarNombre (Ciudad C, string &s){
    StrCrear(s);
    strconDinamico(s,C.nombre);
}

//FUNCIONES

void CargarCiudad (Ciudades &C, string nom){
    if(C.tope<N){
        if(!ExisteCiudad(C,nom)){
            C.info[C.tope].nombre=nom;
            C.info[C.tope].numero=C.tope+1;
            C.tope++;
            }
        else
            printf("\nERORR: Ya existe una ciudad registrada con ese nombrea\n");
    }else
        printf("\nERROR: El cupo de ciudades ya esta completo\n");

}

void ListarCiudades (Ciudades c){
    for(int i=0;i<c.tope;i++){
        MostrarCiudad(c.info[i]);
    }
}
