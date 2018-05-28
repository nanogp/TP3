#include "Archivo.h"
#include <stdio.h>
#include <string.h>

void eHtml_init(eHtml* paginaWeb)
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

    paginaWeb->cantLineasIni = ARCHIVO_NRO_LINEAS_INI;
    paginaWeb->cantLineasFin = ARCHIVO_NRO_LINEAS_FIN;
    paginaWeb->cantLineasPelicula = ARCHIVO_NRO_LINEAS_PELICULA;

    //procedo a armar el inicio y fin de pagina para tenerlos listos
    //luego solo concateno las peliculas en medio

    //armo el inicio de pagina
    for (int i=0; i<paginaWeb->cantLineasIni; i++)
    {
        strcat((char*)&paginaWeb->inicioDePagina, (char*)(lineasInicio+i));
    }

    //armo el fin de pagina
    for (int i=0; i<paginaWeb->cantLineasFin; i++)
    {
        strcat((char*)&paginaWeb->finDePagina, (char*)(lineasFin+i));
    }

    printf("%s%s",paginaWeb->inicioDePagina,paginaWeb->finDePagina);
    pausa();
}

int eHtml_generarCodigoHtmlPelicula(char* htmlPelicula, eMovie* pelicula)
{
    int retorno = -1;

    if(pelicula != NULL)
    {
        retorno = 0;

        //concateno lineas
        strcat(htmlPelicula, "\n            <article class='col-md-4 article-intro'>");
        strcat(htmlPelicula, "\n                <a href='#'>");
        strcat(htmlPelicula, "\n                    <img class='img-responsive img-rounded' src='"); strcat(htmlPelicula, pelicula->linkImagen); strcat(htmlPelicula, "' alt=''>");
        strcat(htmlPelicula, "\n                </a>");
        strcat(htmlPelicula, "\n                <h3>");
        strcat(htmlPelicula, "\n                    <a href='#'>"); strcat(htmlPelicula, pelicula->titulo); strcat(htmlPelicula, "</a>");
        strcat(htmlPelicula, "\n                </h3>");
        strcat(htmlPelicula, "\n				<ul>");
        strcat(htmlPelicula, "\n					<li>Género:"); strcat(htmlPelicula, pelicula->genero); strcat(htmlPelicula, "</li>");
        strcat(htmlPelicula, "\n					<li>Puntaje:"); strcat(htmlPelicula, (char*)pelicula->puntaje); strcat(htmlPelicula, "</li>");
        strcat(htmlPelicula, "\n					<li>Duración:"); strcat(htmlPelicula, (char*)pelicula->duracion); strcat(htmlPelicula, "</li>");
        strcat(htmlPelicula, "\n				</ul>");
        strcat(htmlPelicula, "\n                <p>"); strcat(htmlPelicula, pelicula->descripcion); strcat(htmlPelicula, "</p>");
        strcat(htmlPelicula, "\n            </article>");

    }

    return retorno;
}

int eHtml_generarWeb(eHtml* paginaWeb, eMovie* listadoPeliculas, int limitePeliculas)
{
    int retorno = -1;
    int i;

    if(paginaWeb != NULL && listadoPeliculas != NULL && limitePeliculas > 0)
    {
        retorno = 0;
        limpiarPantallaYMostrarTitulo(ARCHIVO_GENERAR_WEB_TITULO);

        if(eMovie_informarListadoVacio(listadoPeliculas, limitePeliculas) == 0)
        {
            //voy a armar el codigo fuente de la pagina
            strcat(paginaWeb->codigoFuente, paginaWeb->inicioDePagina);

            for(i=0 ; i<limitePeliculas ; i++)
            {
                if((listadoPeliculas+i)->estado == OCUPADO)
                {
                    eHtml_generarCodigoHtmlPelicula((char*)&(paginaWeb->codigoFuente), (listadoPeliculas+i));
                }
            }

            strcat(paginaWeb->codigoFuente, paginaWeb->finDePagina);
        }
    }

    printf("%s",paginaWeb->codigoFuente);
    pausa();
    return retorno;
}
