#include <stdlib.h>
#include "lineas.h"


int main(){
    //declarar variables
    int opcion;
    LineasABB ABB;
    Trayecto T;
    ParadasL P;
    Ciudades C;
    string codigo;
    //Inicializar estructuras
    CrearT(T);
    CrearP(P);
    Make(ABB);
    CrearC(C);
    //StrCrear(codigo);

    //menu
    while(opcion != 9){
        printf("\n\t\t\tEMPRESA DE TRANSPORTE INTERDEPARTAMENTAL\n\n");
        printf("MENU\n");
        printf("1-REGISTRAR CIUDAD\n");
        printf("2-VER CIUDADES DISPONIBLES\n");
        printf("3-REGISTRAR NUEVO TRAMO ENTRE 2 CIUDADES\n");
        printf("4-VERIFICAR EXISTENCIA DE RECORRDIDO ENTRE 2 CIUDADES\n");
        printf("5-REGISTRAR LINEA\n");
        printf("6-VER LINEAS DISPONIBLES\n");
        printf("7-AGREGAR PARADA A RECORRIDO DE LINEA\n");
        printf("8-VER DATOS DEL RECORRIDO DE UNA LINEA\n");
        printf("9-EXIT\n");
        printf("SELECCIONE UNA OPCION:");
        fflush(stdin);
        scanf("%d", &opcion);
        switch (opcion){

        case 1: string nombre;
                if(C.tope != N){
                    printf("\nIngrese el nombre de la ciudad (La primer letra debe ser con mayuscula):");

                    scanDinamico(nombre);
                    if(nombre[0]>=65 && nombre[0]<=90){
                        if(!ExisteCiudad(C, nombre)){
                            CargarCiudad(C, nombre);
                            printf("\nCiudad registrada correctamente\n");
                        }
                        else
                            printf("\nERROR: Ya existe una ciudad registrada con ese nombre\n");
                    }else
                        printf("\nERROR: La primer letra debe ser con Mayuscula.\n");
                }
                else
                    printf("\nFue alcanzado el limite de ciudades en el sistema\n");
            break;
        case 2: printf("\nLas ciudades disponibles son:\n");
                ListarCiudades(C);
            break;
        case 3: int prim, seg;
                if(C.tope == N){
                    printf("\nLas ciudades disponibles son:\n");
                    ListarCiudades(C);
                    printf("\nElija a travez de sus respectivos numeros, las dos ciudades para el nuevo tramo:");
                    printf("\nNumero de la primera:");
                    scanf("%d", &prim);
                    printf("\nNumero de la segunda:");
                    scanf("%d", &seg);
                    if(prim<=C.tope && seg<=C.tope)
                        RegistrarTramo(T, prim, seg);
                    else
                        printf("Uno de los numeros de ciudades esta fuera del rango permitido de ciudades.");
                }
                else
                    printf("\nTodavia no estan cargadas todas las ciudades\n");
            break;
        case 4:
            if(C.tope == N){
                    int prim, seg;
                    printf("\nLas ciudades disponibles son:\n");
                    ListarCiudades(C);
                    printf("\nElija a travez de sus respectivos numeros, las dos ciudades para verificar si existe un camino entre ellas:");
                    printf("\nNumero de la primera:");
                    scanf("%d", &prim);
                    printf("\nNumero de la segunda:");
                    scanf("%d", &seg);
                    if(prim<=C.tope && seg<=C.tope){
                        if(ExisteCamino(T,prim, seg))
                            printf("\nExiste un camino posible entre las dos ciudades\n");
                        else
                            printf("\nNo hay ningun camino que una las dos ciudades\n");
                    }else
                        printf("\nUno de los numeros de ciudades esta fuera del rango permitido de ciudades.\n");
                }
                else
                    printf("\nTodavia no estan cargadas todas las ciudades\n");
            break;
        case 5:
                printf("\nIngrese el codigo alfanumerico para la nueva linea:");
                scanDinamico(codigo);
                RegistrarLinea(ABB, codigo);
            break;
        case 6: printf("\nLas lineas disponibles:\n");
                ListarLineas(ABB);
            break;
        case 7:
                int numero;
                if(C.tope == N){
                    printf("\nIngrese el codigo alfanumerico de la linea:");
                    scanDinamico(codigo);
                    printf("\nIngrese el numero de la ciudad para la nueva parada:");
                    scanf("%d", &numero);
                    Ciudad aux= C.info[numero-1];
                    RegistrarParada(ABB, T, codigo, aux);
                }
                else
                    printf("\nTodavia no estan cargadas todas las ciudades\n");
            break;
        case 8:
                printf("\nIngrese el codigo alfanumerico de la linea:");
                scanDinamico(codigo);
                if(Member(ABB,codigo))
                        ListarRecorrido(ABB, codigo);
                else
                    printf("\nNo existe una linea con ese codigo\n");
            break;
        case 9:
            break;

        default:
                printf("\nERROR: opcion no reconocida\n");
        }
        system("pause");
        system("cls");
      }
}
