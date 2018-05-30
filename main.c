/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"
#include "Pelicula.h"
#include "Archivo.h"

/**************************** INCLUSION DE LIBRERIAS ESTANDAR ************************************/
#include <stdio.h>
#include <stdlib.h>

/**************************** MENUS **************************************************************/
#define MENU_MAIN_TITULO "TP3 MARIANO PONTI"
#define MENU_MAIN_CANT 5
#define MENU_MAIN_DETALLE1  "1. Agregar pelicula"
#define MENU_MAIN_DETALLE2  "2. Borrar pelicula"
#define MENU_MAIN_DETALLE3  "3. Modificar pelicula"
#define MENU_MAIN_DETALLE4  "4. Generar pagina web"
#define MENU_MAIN_DETALLE0  "0. Salir"

int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/MENU_MAIN_CANT,
                            /*codigos*/{1,2,3,4,0},
                            /*descripciones*/{MENU_MAIN_DETALLE1,MENU_MAIN_DETALLE2,MENU_MAIN_DETALLE3,MENU_MAIN_DETALLE4,MENU_MAIN_DETALLE0},
                            /*titulo del menu*/{MENU_MAIN_TITULO}};
    int opcion;
    char salirDelPrograma = 'N';


    /************************ ARRAYS DE ESTRUCTURAS **********************************************/
    eMovie listadoPeliculas[PELICULA_CANT_MAX] = {};
    eArchivoHtml paginaWeb;

    /************************ INICIALIZACION *****************************************************/
    eMovie_init(listadoPeliculas, PELICULA_CANT_MAX);
    eArchivoBinario_leer(ARCHIVO_BINARIO_RUTA, listadoPeliculas, PELICULA_CANT_MAX);

    /************************ GENERAR DATOS POR HARDCODE PARA DEBUG ******************************/
    /************************ (SOLO SI EL ARCHIVO BINARIO NO EXISTE) *****************************/
    eArchivoBinario_initHardcode(listadoPeliculas);

    do
    {
        /******************** MENU PRINCIPAL *****************************************************/
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                /************ ALTA ***************************************************************/
                eMovie_alta(listadoPeliculas, PELICULA_CANT_MAX);
                eArchivoBinario_escribir(ARCHIVO_BINARIO_RUTA, listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 2:
                /************ BAJA ***************************************************************/
                eMovie_baja(listadoPeliculas, PELICULA_CANT_MAX);
                eArchivoBinario_escribir(ARCHIVO_BINARIO_RUTA, listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 3:
                /************ MODIFICACION *******************************************************/
                eMovie_modificacion(listadoPeliculas, PELICULA_CANT_MAX);
                eArchivoBinario_escribir(ARCHIVO_BINARIO_RUTA, listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 4:
                /************ LISTADO WEB ********************************************************/
                eArchivoHtml_generarWeb(&paginaWeb, listadoPeliculas, PELICULA_CANT_MAX);
                break;
            case 0:
                /************ SALIR DEL PROGRAMA *************************************************/
                salirDelPrograma = pedirConfirmacion(MSJ_SALIR_DEL_PROGRAMA);
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
