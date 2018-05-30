#pragma once
#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "Pelicula.h"

/**************************** LIMITES ************************************************************/

/**************************** CONSTANTES *********************************************************/
#define ARCHIVO_HTML_RUTA "index.html"
#define ARCHIVO_BINARIO_RUTA "Listado_Peliculas.dat"
#define ARCHIVO_HTML_LECTURA "r"
#define ARCHIVO_BINARIO_LECTURA "rb"
#define ARCHIVO_HTML_ESCRITURA "w"
#define ARCHIVO_BINARIO_ESCRITURA "wb"
#define ARCHIVO_NRO_LINEAS_INI 13
#define ARCHIVO_NRO_LINEAS_FIN 8
#define ARCHIVO_NRO_LINEAS_PELICULA 14

/**************************** TITULOS ************************************************************/
#define ARCHIVO_GENERAR_WEB_TITULO "GENERAR PAGINA WEB"

/**************************** MENSAJES ERROR *****************************************************/

/**************************** MENSAJES INFO ******************************************************/
#define ARCHIVO_MSJ_HTML_OK "\n\nSe gener¢ la p gina web en el archivo: "

/**************************** MENSAJES INPUT *****************************************************/

/**************************** LISTADOS ***********************************************************/

/**************************** ORDENAMIENTO *******************************************************/

/**************************** MENUS **************************************************************/

/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    int cantLineasIni;//13
    int cantLineasPelicula;//14
    int cantLineasFin;//8
    char codigoFuente[1000*PELICULA_CANT_MAX];
    char inicioDePagina[500];
    char finDePagina[300];
}eArchivoHtml;

/**************************** INICIALIZACIONES ***************************************************/
void eArchivoBinario_initHardcode(eMovie* listadoPeliculas);
//-----------------------------------------------------------------------------------------------//
void eArchivoHtml_init(eArchivoHtml* plantillaWeb);
//-----------------------------------------------------------------------------------------------//
int eArchivoHtml_generarCodigoHtmlPelicula(char* htmlPelicula, eMovie* pelicula);
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION ARCHIVO HTML ***********************************************/
int eArchivoHtml_escribirArchivoHtml(char* codigoFuente);
//-----------------------------------------------------------------------------------------------//
int eArchivoHtml_generarWeb(eArchivoHtml* paginaWeb, eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION ARCHIVO BINARIO ********************************************/
int eArchivoBinario_leer(char* rutaArchivo, eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
int eArchivoBinario_escribir(char* rutaArchivo, eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
#endif // ARCHIVO_H_INCLUDED
