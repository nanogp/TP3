#pragma once
#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "Pelicula.h"

//constantes
#define ARCHIVO_LECTURA "r"
#define ARCHIVO_LECTURA_BINARIO "rb"
#define ARCHIVO_ESCRITURA "w"
#define ARCHIVO_ESCRITURA_BINARIO "wb"

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

#endif // ARCHIVO_H_INCLUDED
