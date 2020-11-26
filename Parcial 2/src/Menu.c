/*
 * Menu.c
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */
#include "Menu.h"
#include "Gets.h"

int Menu(void)
{
	int opcion;
	GetOption("MENU\n\n"
					"1).Agregar cliente.\n"
					"2).Vender afiches.\n"
					"3).Modificar venta.\n"
					"4).Cobrar venta.\n"
					"5).Generar informe de cobro.\n"
					"6).Generar informe de deudas.\n"
					"7).Generar estadisticas.\n"
					"8).Salir.\nIngrese una opcion: ", "Ingrese un dato valido!\n",&opcion,2,1,8);
	return opcion;
}

