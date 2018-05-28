#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "Pelicula.h"
#include "Archivo.h"

#define MENU_MAIN_TITULO "TP3 MARIANO PONTI"
#define MENU_MAIN_CANT 6
#define MENU_MAIN_DETALLE1  "1. Agregar pelicula"
#define MENU_MAIN_DETALLE2  "2. Borrar pelicula"
#define MENU_MAIN_DETALLE3  "3. Modificar pelicula"
#define MENU_MAIN_DETALLE4  "4. Generar pagina web"
#define MENU_MAIN_DETALLE5  "5. Listado Peliculas"
#define MENU_MAIN_DETALLE0  "0. Salir"

int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/MENU_MAIN_CANT,
                            /*codigos*/{1,2,3,4,5,0},
                            /*descripciones*/{MENU_MAIN_DETALLE1,MENU_MAIN_DETALLE2,MENU_MAIN_DETALLE3,MENU_MAIN_DETALLE4,MENU_MAIN_DETALLE5,MENU_MAIN_DETALLE0},
                            /*titulo del menu*/{MENU_MAIN_TITULO}};
    int opcion;
    char salirDelPrograma = 'N';

    //ARRAYS DE ESTRUCTURAS
    eMovie listadoPeliculas[PELICULA_CANT_MAX] = {};
    eHtml paginaWeb;

    //INCIALIZAR
    eMovie_init(listadoPeliculas, PELICULA_CANT_MAX);
    eHtml_init(&paginaWeb);

    //CARGAR DATOS POR HARDCODE PARA DEBUG
    eMovie_initHardcode(listadoPeliculas);

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                eMovie_alta(listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 2:
                eMovie_baja(listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 3:
                eMovie_modificacion(listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 4:
                eHtml_generarWeb(&paginaWeb, listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 5:
                eMovie_mostrarListado(listadoPeliculas, PELICULA_CANT_MAX);pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
