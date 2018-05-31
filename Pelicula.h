#pragma once
#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

/**************************** INCLUSION DE LIBRERIAS PERSONALES **********************************/
#include "General.h"
#include "Menu.h"

/**************************** LIMITES ************************************************************/
#define PELICULA_CANT_MAX 6
#define PELICULA_LARGO_TITULO 20
#define PELICULA_LARGO_GENERO 20
#define PELICULA_LARGO_DESCRIPCION 300
#define PELICULA_LARGO_LINK 500
#define PELICULA_PUNTAJE_MIN 1
#define PELICULA_PUNTAJE_MAX 100
#define PELICULA_DURACION_MIN 1
#define PELICULA_DURACION_MAX 300
#define PELICULA_ID_MIN 1
#define PELICULA_ID_MAX 1000000
#define PELICULA_LARGO_RESERVAS 10

/**************************** TITULOS ************************************************************/
#define PELICULA_ALTA_TITULO "ALTA DE PELICULA"
#define PELICULA_BAJA_TITULO "BAJA DE PELICULA"
#define PELICULA_MODIFICACION_TITULO "MODIFICACION DE PELICULA"
#define PELICULA_LISTADO_TITULO "LISTADO DE PELICULAS"

/**************************** MENSAJES ERROR *****************************************************/
#define PELICULA_MSJ_ID_NO_EXISTE "\nEl ID de Pelicula ingresado no existe"
#define PELICULA_MSJ_LISTA_VACIA "\n\nLa lista de Peliculas esta vacia o todos los registros se dieron de baja"
#define PELICULA_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Pelicula"
#define PELICULA_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: "
#define PELICULA_MSJ_REINGRESE_TITULO "\nTitulo no valido. Reingrese por favor hasta 20 caracteres: "
#define PELICULA_MSJ_REINGRESE_GENERO "\nGenero no valido. Reingrese por favor hasta 20 caracteres: "
#define PELICULA_MSJ_REINGRESE_DESCRIPCION "\nDescripcion no valida. Reingrese por favor hasta 500 caracteres: "
#define PELICULA_MSJ_REINGRESE_DURACION "\nDuracion no valida. Reingrese por favor un numero entre 1 y 300: "
#define PELICULA_MSJ_REINGRESE_PUNTAJE "\nPuntaje no valido. Reingrese por favor un numero entre 1 y 100: "
#define PELICULA_MSJ_REINGRESE_LINK "\nLink a imagen no valido. Reingrese por favor hasta 500 caracteres: "

/**************************** MENSAJES INFO ******************************************************/
#define PELICULA_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicha Pelicula?"
#define PELICULA_MSJ_ALTA_OK "\nLa Pelicula se dio de alta"
#define PELICULA_MSJ_BAJA_OK "\nLa Pelicula se dio de baja"
#define PELICULA_MSJ_MODIFICACION_SIN_CAMBIOS "\nNo hubo cambio alguno"
#define PELICULA_MSJ_MODIFICACION_OK "\nLa Pelicula se modifico"
#define PELICULA_MSJ_REGISTRO_ACTUAL "\n\nREGISTRO DE PELICULA ACTUAL:\n컴컴컴컴컴컴컴컴컴컴컴컴컴컴"
#define PELICULA_MSJ_REGISTRO_MODIFICADO "\n\nREGISTRO MODIFICADO:\n컴컴컴컴컴컴컴컴컴컴"

/**************************** MENSAJES INPUT *****************************************************/
#define PELICULA_MSJ_INGRESE_ID "\n\nIngrese el ID de Pelicula: "
#define PELICULA_MSJ_INGRESE_TITULO "\nIngrese Titulo Pelicula: "
#define PELICULA_MSJ_INGRESE_GENERO "\nIngrese Genero: "
#define PELICULA_MSJ_INGRESE_DESCRIPCION "\nIngrese Descripcion: "
#define PELICULA_MSJ_INGRESE_DURACION "\nIngrese Duracion en minutos: "
#define PELICULA_MSJ_INGRESE_PUNTAJE "\nIngrese Puntaje entre 1 y 100: "
#define PELICULA_MSJ_INGRESE_LINK "\nIngrese Link a imagen: "

/**************************** LISTADOS ***********************************************************/
#define PELICULA_MOSTRAR_UNO_CABECERA "\nID \t- TITULO \t\t- GENERO \t\t- PUNTAJE - DURACION"
#define PELICULA_MOSTRAR_UNO_MASCARA "\n%d \t- %-20s \t- %-20s \t- %-7d - %d min"
#define PELICULA_MOSTRAR_UNO_COMPLETO_MASCARA "\n- ID:%d \n- TITULO: %-20s \n- GENERO: %-20s \n- PUNTAJE: %d \n- DURACION: %d min \n- DESCRIPCION: %s \n- LINK A IMAGEN: %s\n"

/**************************** ORDENAMIENTO *******************************************************/
#define PELICULA_ORDEN_TITULO "titulo"
#define PELICULA_ORDEN_TITULO_DESC "tituloDescendente"
#define PELICULA_ORDEN_ID "id"
#define PELICULA_ORDEN_ID_DESC "idDescendente"

/**************************** MENUS **************************************************************/
#define PELICULA_MENU_MODIFICAR_UNO_TITULO "Que desea modificar?"
#define PELICULA_MENU_MODIFICAR_UNO_CANT 8
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE1 "1. Titulo"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE2 "2. Genero"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE3 "3. Duracion"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE4 "4. Descripcion"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE5 "5. Puntaje"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE6 "6. Link a imagen"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE9 "9. Finalizar modificacion"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE0 "0. Cancelar"


/**************************** ESTRUCTURAS ********************************************************/
typedef struct{
   char titulo[PELICULA_LARGO_TITULO];
   char genero[PELICULA_LARGO_GENERO];
   int duracion;
   char descripcion[PELICULA_LARGO_DESCRIPCION];
   int puntaje;
   char linkImagen[PELICULA_LARGO_LINK];
   //-------------------------
   int idPelicula;
   int estado;
}eMovie;


/**************************** INICIALIZACIONES ***************************************************/
/** \brief inicializa el listado de peliculas con datos de prueba
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \return void
 *
 */
void eMovie_initHardcode(eMovie* listadoPeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief inicializa el array de peliculas en cero
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int devuelve cero si no hubo ningun error
 *
 */
int eMovie_init(eMovie* listadoPeliculas, int limitePeliculas);


/**************************** BUSQUEDA ***********************************************************/
/** \brief busca en el listado un registro con estado libre y devuelve su posicion
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int devuelve numero de posicion en el array
 *
 */
int eMovie_buscarLugarLibre(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief calcula el siguiente Id disponible para una pelicula
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int el numero de Id calculado
 *
 */
int eMovie_siguienteId(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief verifica si no hay registros ocupados en el listado de peliculas
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int devuelve 1 si esta vacío, 0 si esta ocupado y -1 si hubo error
 *
 */
int eMovie_estaVacio(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief informa en pantalla si el listado de peliculas esta vacio
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int devuelve cero si no hubo ningun error
 *
 */
int eMovie_informarListadoVacio(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief busca un Id en el listado y devuelve su posicion
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \param idPelicula int el Id a buscar
 * \return int la posicion en el array, -1 si no se encuentra, -2 si hubo error
 *
 */
int eMovie_buscarPorId(eMovie* listadoPeliculas, int limitePeliculas, int idPelicula);
//-----------------------------------------------------------------------------------------------//
/** \brief pide al usuario ingresar un Id y busca su posicion en el listado de peliculas
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int la posicion en el array, -1 si no se encuentra, -2 si hubo error
 *
 */
int eMovie_pedirIdYBuscar(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief obtiene la cantidad de peliculas dadas de alta en el listado de peliculas
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int devuelve la cantidad de elementos o -1 si hubo error
 *
 */
int eMovie_obtenerCantidadElementos(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
/** \brief
 *
 * \return int
 *
 */
int eMovie_pedirId();
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \return int
 *
 */
int eMovie_pedirDuracion();
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \return int
 *
 */
int eMovie_pedirPuntaje();
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param retorno char*
 * \return void
 *
 */
void eMovie_pedirTitulo(char* retorno);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param retorno char*
 * \return void
 *
 */
void eMovie_pedirGenero(char* retorno);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param retorno char*
 * \return void
 *
 */
void eMovie_pedirDescripcion(char* retorno);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param retorno char*
 * \return void
 *
 */
void eMovie_pedirLinkImagen(char* retorno);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return eMovie
 *
 */
eMovie eMovie_pedirIngreso(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//


/**************************** LISTADO DE DATOS ***************************************************/
/** \brief
 *
 * \param pelicula eMovie*
 * \return int
 *
 */
int eMovie_mostrarUno(eMovie* pelicula);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param pelicula eMovie*
 * \return int
 *
 */
int eMovie_mostrarUnoCompleto(eMovie* pelicula);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int
 *
 */
int eMovie_mostrarListado(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//


/**************************** GESTION DE DATOS ***************************************************/
/** \brief
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int
 *
 */
int eMovie_alta(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int
 *
 */
int eMovie_modificacion(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//
/** \brief
 *
 * \param listadoPeliculas eMovie* la variable donde se guarda el listado
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \return int
 *
 */
int eMovie_baja(eMovie* listadoPeliculas, int limitePeliculas);
//-----------------------------------------------------------------------------------------------//


/**************************** ORDENAMIENTO *******************************************************/
/** \brief
 *
 * \param listado eMovie*
 * \param limitePeliculas int la cantidad maxima de elementos del listado
 * \param orden char*
 * \return int
 *
 */
int eMovie_ordenar(eMovie* listado, int limitePeliculas, char* orden);
//-----------------------------------------------------------------------------------------------//
#endif // PELICULA_H_INCLUDED
