#include "Archivo.h"
#include <stdio.h>
#include <string.h>

void eHtml_init(eHtml* plantillaWeb)
{
    char lineasInicio[13][100] = {{"<!DOCTYPE html>\n"},
                                  {"<html lang='en'>\n"},
                                  {"<head>\n"},
                                  {"    <meta charset='utf-8'>\n"},
                                  {"    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"},
                                  {"    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"},
                                  {"    <title>Lista peliculas</title>\n"},
                                  {"    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"},
                                  {"    <link href='css/custom.css' rel='stylesheet'>\n"},
                                  {"</head>\n"},
                                  {"<body>\n"},
                                  {"    <div class='container'>\n"},
                                  {"        <div class='row'>\n"}};

    char lineasFin[8][100] = {{"        </div>\n"},
                              {"    </div>\n"},
                              {"    <script src='js/jquery-1.11.3.min.js'></script>\n"},
                              {"    <script src='js/bootstrap.min.js'></script>\n"},
                              {"    <script src='js/ie10-viewport-bug-workaround.js'></script>\n"},
                              {"    <script src='js/holder.min.js'></script>\n"},
                              {"</body>\n"},
                              {"</html>\n"}};

    plantillaWeb->cantLineasIni = 13;
    plantillaWeb->cantLineasFin = 8;
    plantillaWeb->cantLineasPelicula = 14;

    //procedo a armar el inicio y fin de pagina para tenerlos listos
    //luego solo concateno las peliculas en medio

    //armo el inicio de pagina
    for (int i=0; i<plantillaWeb->cantLineasIni; i++)
    {
        strcat((char*)&plantillaWeb->inicioDePagina, (char*)(lineasInicio+i));
    }

    //armo el fin de pagina
    for (int i=0; i<plantillaWeb->cantLineasFin; i++)
    {
        strcat((char*)&plantillaWeb->finDePagina, (char*)(lineasFin+i));
    }

    printf("%s%s",plantillaWeb->inicioDePagina,plantillaWeb->finDePagina);
    pausa();
}
