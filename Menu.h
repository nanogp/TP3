#pragma once
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/**************************** LIMITES ************************************************************/
#define MENU_LARGO_DESCRIPCION 100
#define MENU_LARGO_TITULO 100
#define MENU_CANT_MAX 20


/**************************** ESTRUCTURAS ********************************************************/
typedef struct
{
    int limiteOpciones;
    int codigos[MENU_CANT_MAX];
    char descripciones[MENU_CANT_MAX][MENU_LARGO_DESCRIPCION];
    char titulo[MENU_LARGO_TITULO];
} eMenu;


/**************************** LISTADO DE DATOS ***************************************************/
/** \brief muestra en pantalla un tipo de dato menu
 *
 * \param menu  eMenu*: el menu a mostrar
 * \return void
 *
 */
void mostrarMenu(eMenu* menu);
//-----------------------------------------------------------------------------------------------//


/**************************** ENTRADA DE DATOS ***************************************************/
/** \brief pide al usuario que elija una opcion de menu recibido como parametro
 *
 * \param menu  eMenu*: el menu de opciones a mostrar al usuario para pedir y validar la opcion seleccionada
 * \return int: el numero de opcion validada
 *
 */
int pedirOpcion(eMenu* menu);
//-----------------------------------------------------------------------------------------------//

#endif // MENU_H_INCLUDED
