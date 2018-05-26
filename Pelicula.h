#pragma once
#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include "General.h"
#include "Menu.h"

//LIMITES
#define PELICULA_CANT_MAX 1000
#define PELICULA_LARGO_TITULO 20
#define PELICULA_LARGO_GENERO 20
#define PELICULA_LARGO_DESCRIPCION 50
#define PELICULA_LARGO_LINK 50
#define PELICULA_PUNTAJE_MIN 1
#define PELICULA_PUNTAJE_MAX 10
#define PELICULA_DURACION_MIN 1
#define PELICULA_DURACION_MAX 300
#define PELICULA_ID_MIN 1
#define PELICULA_ID_MAX 1000000
#define PELICULA_LARGO_RESERVAS 10

//CONSTANTES
#define PELICULA_K_A 1
#define PELICULA_K_B 2
#define PELICULA_K_OTROS 3
#define PELICULA_K_TXT_A "Oro"
#define PELICULA_K_TXT_B "Petroleo"
#define PELICULA_K_TXT_OTROS "Otros"

//TITULOS
#define PELICULA_ALTA_TITULO "ALTA DE PELICULA"
#define PELICULA_BAJA_TITULO "BAJA DE PELICULA"
#define PELICULA_MODIFICACION_TITULO "MODIFICACION DE PELICULA"
#define PELICULA_LISTADO_TITULO "LISTADO DE PELICULAS"

//MENSAJES ERROR
#define PELICULA_MSJ_ID_NO_EXISTE "\nEl ID de Pelicula ingresado no existe"
#define PELICULA_MSJ_LISTA_VACIA "\n\nLa lista de Peliculas esta vacia o todos los registros se dieron de baja"
#define PELICULA_MSJ_NO_MAS_LUGAR "\nNo hay mas lugares disponibles para altas de Pelicula"

//MENSAJES INFO
#define PELICULA_MSJ_CONFIRMAR_BAJA "Confirma que desea dar de baja dicho Pelicula?"
#define PELICULA_MSJ_ALTA_OK "\nEl Pelicula se dio de alta"
#define PELICULA_MSJ_BAJA_OK "\nEl Pelicula se dio de baja"
#define PELICULA_MSJ_MODIFICACION_OK "\nEl Pelicula se modifico"
#define PELICULA_MSJ_REGISTRO_ACTUAL "\n\nPelicula actual: \0"
#define PELICULA_MSJ_REGISTRO_MODIFICADO "\n\nPelicula modificado: \0"

//MENSAJES INPUT
#define PELICULA_MSJ_INGRESE_ID "\n\nIngrese el ID de Pelicula: \0"
#define PELICULA_MSJ_REINGRESE_ID "\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0"
#define PELICULA_MSJ_INGRESE_TITULO "\nIngrese Titulo Pelicula: \0"
#define PELICULA_MSJ_REINGRESE_TITULO "\nTitulo muy largo. Reingrese por favor: \0"
#define PELICULA_MSJ_INGRESE_GENERO "\nIngrese Genero: \0"
#define PELICULA_MSJ_REINGRESE_GENERO "\nGenero muy largo. Reingrese por favor: \0"
#define PELICULA_MSJ_INGRESE_DESCRIPCION "\nIngrese Descripcion: \0"
#define PELICULA_MSJ_REINGRESE_DESCRIPCION "\nDescripcion muy larga. Reingrese por favor: \0"
#define PELICULA_MSJ_INGRESE_DURACION "\nIngrese Duracion: \0"
#define PELICULA_MSJ_REINGRESE_DURACION "\nDuracion no valida. Reingrese por favor: \0"
#define PELICULA_MSJ_INGRESE_PUNTAJE "\nIngrese Puntaje: \0"
#define PELICULA_MSJ_REINGRESE_PUNTAJE "\nPuntaje no valido. Reingrese por favor: \0"
#define PELICULA_MSJ_INGRESE_LINK "\nIngrese Link a imagen: \0"
#define PELICULA_MSJ_REINGRESE_LINK "\nLink a imagen no valido. Reingrese por favor: \0"

//LISTADOS
#define PELICULA_MOSTRAR_UNO_MASCARA DEFINIR_MACRO_STRING(\n%d - %-10s - %-10s - %-10d - %-10d - %-10s)
#define PELICULA_MOSTRAR_UNO_CABECERA "\nID - TITULO - GENERO - PUNTAJE - DURACION - DESCRIPCION"

//ORDEN
#define PELICULA_ORDEN_TITULO "nombreAsc"
#define PELICULA_ORDEN_ID "idAsc"

//MENUS
#define PELICULA_MENU_MODIFICAR_UNO_TITULO "Que desea modificar?"
#define PELICULA_MENU_MODIFICAR_UNO_CANT 6
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE1 "1. Titulo"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE2 "2. Genero"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE3 "3. Duracion"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE4 "4. Descripcion"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE5 "5. Puntaje"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE6 "6. Link a imagen"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE9 "9. Finalizar modificacion"
#define PELICULA_MENU_MODIFICAR_UNO_DETALLE0 "0. Cancelar"

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

//init
void eMovie_initHardcode(eMovie* listadoPeliculas);
int eMovie_init(eMovie* listadoPeliculas, int limitePeliculas);

//busqueda
int eMovie_buscarLugarLibre(eMovie* listadoPeliculas, int limitePeliculas);
int eMovie_siguienteId(eMovie* listadoPeliculas, int limitePeliculas);
int eMovie_estaVacio(eMovie* listadoPeliculas, int limitePeliculas);
int eMovie_informarListadoVacio(eMovie* listadoPeliculas, int limitePeliculas);
int eMovie_buscarPorId(eMovie* listadoPeliculas, int limitePeliculas, int idPelicula);
int eMovie_pedirIdYBuscar(eMovie* listadoPeliculas, int limitePeliculas);

//input
int eMovie_pedirId();
int eMovie_pedirDuracion();
int eMovie_pedirPuntaje();
void eMovie_pedirTitulo(char* retorno);
void eMovie_pedirGenero(char* retorno);
void eMovie_pedirDescripcion(char* retorno);
void eMovie_pedirLinkImagen(char* retorno);
eMovie eMovie_pedirIngreso(eMovie* listadoPeliculas, int limitePeliculas);

//listado
int eMovie_mostrarUno(eMovie* pelicula);
int eMovie_mostrarListado(eMovie* listadoPeliculas, int limitePeliculas);

//gestion
int eMovie_alta(eMovie* listadoPeliculas, int limitePeliculas);
int eMovie_modificacion(eMovie* listadoPeliculas, int limitePeliculas);
int eMovie_baja(eMovie* listadoPeliculas, int limitePeliculas);
int eMovie_ordenar(eMovie* listado, int limitePeliculas, char* orden);

#endif // PELICULA_H_INCLUDED
