#pragma once
#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Pelicula.h"

//LIMITES

//CONSTANTES
#define ARCHIVO_LECTURA "r"
#define ARCHIVO_LECTURA_BINARIO "rb"
#define ARCHIVO_ESCRITURA "w"
#define ARCHIVO_ESCRITURA_BINARIO "wb"
#define ARCHIVO_RUTA_BINARIO "Listado Peliculas.dat"
#define ARCHIVO_RUTA_HTML "index.html"
#define ARCHIVO_NRO_LINEAS_INI 13
#define ARCHIVO_NRO_LINEAS_FIN 8
#define ARCHIVO_NRO_LINEAS_PELICULA 14

//TITULOS
#define ARCHIVO_GENERAR_WEB_TITULO "GENERAR PAGINA WEB"

//MENSAJES ERROR

//MENSAJES INFO
#define ARCHIVO_MSJ_HTML_OK "\n\nSe gener¢ el archivo html para la pagina web\n"

//MENSAJES INPUT

//LISTADOS

//ORDEN

//MENUS

typedef struct
{
    int cantLineasIni;//13
    int cantLineasPelicula;//14
    int cantLineasFin;//8
    char codigoFuente[1000*PELICULA_CANT_MAX];
    char inicioDePagina[500];
    char finDePagina[300];
}eHtml;

void eHtml_init(eHtml* plantillaWeb);
int eHtml_generarCodigoHtmlPelicula(char* htmlPelicula, eMovie* pelicula);
int eHtml_generarWeb(eHtml* paginaWeb, eMovie* listadoPeliculas, int limitePeliculas);
int eArchivo_leer(char* rutaArchivo, eMovie* listadoPeliculas, int limitePeliculas);
int eArchivo_escribir(char* rutaArchivo, eMovie* listadoPeliculas, int limitePeliculas);
#endif // ARCHIVO_H_INCLUDED
