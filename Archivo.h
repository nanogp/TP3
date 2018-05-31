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

/**************************** INICIALIZACIONES ***************************************************/
/** \brief inicializo el archivo con datos en caso de que no exista
 *
 * \param listadoPeliculas eMovie* el listado de peliculas
 * \return void
 *
 */
void eArchivoBinario_initHardcode(eMovie* listadoPeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief preparo los bloques de codigo de inicio y fin para generar la pagina web
 *
 * \param codigoHtml char** puntero al que voy asignar memoria para guardar el codigo html de la web
 * \return int devuelve 0 si no hubo error y -1 si no pudo conseguir memoria
 *
 */
int eArchivoHtml_init(char** codigoHtml);
//-----------------------------------------------------------------------------------------------//
/** \brief genera el bloque de codigo con los datos de una pelicula
 *
 * \param htmlPelicula char* variable donde quiero guardar el codigo html generado
 * \param pelicula eMovie* datos de la pelicula
 * \return int devuelve cero si no hubo ningun error
 *
 */
int eArchivoHtml_generarCodigoHtmlPelicula(char* htmlPelicula, eMovie* pelicula);
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION ARCHIVO HTML ***********************************************/
/** \brief escribe un archivo html en disco con el codigo recibido por parametro
 *
 * \param codigoHtml char* el codigo fuente a escribir en el archivo
 * \return int devuelve cero si no hubo ningun error
 *
 */
int eArchivoHtml_escribirArchivoHtml(char* codigoHtml);
//-----------------------------------------------------------------------------------------------//
/** \brief genera un archivo html en disco con el listado de peliculas recibido
 *
 * \param listadoPeliculas eMovie* el listado de peliculas a utilizar
 * \param limitePeliculas int cantidad maxima de elementos en el listado
 * \return int devuelve cero si no hubo ningun error
 *
 */
int eArchivoHtml_generarWeb(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION ARCHIVO BINARIO ********************************************/
/** \brief lee un archivo binario con un listado de peliculas y lo carga en memoria
 *
 * \param rutaArchivo char* ruta al archivo binario
 * \param listadoPeliculas eMovie* un array para guardar el listado que contiene el archivo
 * \param limitePeliculas int cantidad maxima de elementos en el listado
 * \return int devuelve cero si no hubo ningun error
 *
 */
int eArchivoBinario_leer(char* rutaArchivo, eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief escribe un archivo binario con el listado de peliculas en memoria
 *
 * \param rutaArchivo char* ruta al archivo binario
 * \param listadoPeliculas eMovie* el listado de peliculas a guardar en el archivo
 * \param limitePeliculas int cantidad maxima de elementos en el listado
 * \return int devuelve cero si no hubo ningun error
 *
 */
int eArchivoBinario_escribir(char* rutaArchivo, eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
#endif // ARCHIVO_H_INCLUDED
