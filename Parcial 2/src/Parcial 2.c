/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "Menu.h"
#include "Controller.h"
#include "Parser.h"
#include "Informes.h"
#include "Gets.h"

int main(void)
{
	setbuf(stdout,NULL);
	int option;
	int optionSubmenu;
	char bufferChar;
	char salir;
	int idCliente;
	int idVenta;
	int cant;
	Cliente* pCliente;
	Venta* pVenta;
	Cliente bufferCliente;
	Venta bufferVenta;
	LinkedList* listaDeClientes=ll_newLinkedList();
	LinkedList* listaDeVentas=ll_newLinkedList();
	void* pElement;

	if(controller_CargarArchivoDeTexto("clientes.txt", listaDeClientes,parser_ClienteDeTexto)==0
		&& controller_CargarArchivoDeTexto("ventas.txt",listaDeVentas,parser_VentaDeTexto)==0)
	{
		idCliente=controller_InitId(listaDeClientes,1);
		idVenta=controller_InitId(listaDeVentas,2);
		do{
			option=Menu();
			switch(option)
			{
				case 1:
					pElement=ClienteyVenta_addCliente(listaDeClientes,&idCliente);
					if(pElement!=NULL)
					{
						if(ll_add(listaDeClientes,pElement)==0)
						{
							controller_GuardarArchivoClientes("clientes.txt",listaDeClientes);
							printf("Cambios guardados correctamente!\n");
						}
						else
						{
							printf("Algo salio mal, no se guardaron cambios!\n");
						}
					}
					break;
				case 2:
					pElement=ClienteyVenta_addVenta(listaDeClientes,listaDeVentas,&idVenta);
					if(pElement!=NULL)
					{
						if(ll_add(listaDeVentas,pElement)==0)
						{
							controller_GuardarArchivoVentas("ventas.txt",listaDeVentas);
							printf("Cambios guardados correctamente!\n");
							Venta_CabeceraListar();
							Venta_Listar(pElement);
						}
						else
						{
							printf("Algo salio mal, no se guardaron cambios!\n");
						}
					}
					break;
				case 3:
					if(ClienteyVenta_ModificarVenta(listaDeClientes, listaDeVentas,ClienteyVenta_ModificarCamposVenta)==0)
					{
						controller_GuardarArchivoVentas("ventas.txt",listaDeVentas);
						printf("Cambios guardados correctamente!\n");
					}
					else
					{
						printf("Algo salio mal, no se guardaron cambios!\n");
					}
					break;
				case 4:
					if(ClienteyVenta_ModificarVenta(listaDeClientes, listaDeVentas,ClienteyVenta_ModificarEstadoVenta)==0)
					{
						controller_GuardarArchivoVentas("ventas.txt",listaDeVentas);
						printf("Cambios guardados correctamente!\n");
					}
					else
					{
						printf("Algo salio mal, no se guardaron cambios!\n");
					}
					break;
				case 5:
					if(Informe_GenerarInfoDeCobros(listaDeClientes, listaDeVentas,ClienteyVenta_VentasCobradas,COBRADO)
							&& Informes_GuardarCobradas("cobradas.txt",listaDeClientes)==0)
					{
						printf("Cambios guardados correctamente!\n");
					}
					else
					{
						printf("Algo salio mal, no se guardaron cambios!\n");
					}
					break;
				case 6:
					if(Informe_GenerarInfoDeCobros(listaDeClientes, listaDeVentas,ClienteyVenta_VentasACobrar,A_COBRAR)
							&& Informes_GuardarACobrar("aCobrar.txt",listaDeClientes)==0)
					{
						printf("Cambios guardados correctamente!\n");
					}
					else
					{
						printf("Algo salio mal, no se guardaron cambios!\n");
					}
					break;
				case 7:
					do
					{
						GetOption("1).Cliente al que se le vendió mas afiches\n"
								"2).Cliente al que se le vendió menos afiches\n"
								"3).Venta con mas afiches vendidos (indicar id de venta y cuit de cliente)\n"
								"4).Volver al menu principal\n"
								"Ingrese una opcion: ", "Ingrese un dato valido!\n",&optionSubmenu,2,1,4);
						switch(optionSubmenu)
						{
							case 1:
								pCliente=Informes_contDeAfiches(listaDeVentas, listaDeClientes,&cant,1);
								if(pCliente!=NULL)
								{
									Cliente_getId(pCliente,&bufferCliente.idCliente);
									Cliente_getNombre(pCliente,bufferCliente.nombre);
									printf("El cliente con mas afiches es: %5d %10s\nCon un total de: %d afiches\n",bufferCliente.idCliente,bufferCliente.nombre,cant);
								}
								break;
							case 2:
								pCliente=Informes_contDeAfiches(listaDeVentas, listaDeClientes,&cant,0);
								if(pCliente!=NULL)
								{
									Cliente_getId(pCliente,&bufferCliente.idCliente);
									Cliente_getNombre(pCliente,bufferCliente.nombre);
									printf("El cliente con menos afiches es: Id Cliente: %5d\nNombre Cliente: %10s\nCon un total de: %d afiches\n",bufferCliente.idCliente,bufferCliente.nombre,cant);
								}
								break;
							case 3:
								pVenta=Informes_VentasConMasAfichesVendidos(listaDeVentas, &cant,1);
								if(pVenta!=NULL)
								{
									Venta_getVentaId(pVenta,&bufferVenta.idVenta);
									Venta_getIdCliente(pVenta,&bufferVenta.idCliente);
									pCliente=ClienteyVenta_BuscarPorIdCliente(listaDeClientes,bufferVenta.idCliente);
									if(pCliente!=NULL)
									{
										Cliente_getCuit(pCliente,bufferCliente.cuit);
										printf("La venta con mas afiches es: Id Venta: %5d\nCuit cliente: %10s\n",bufferVenta.idVenta,bufferCliente.cuit);
									}
								}
								break;
							case 4:
								if(GetChar("Seguro desea salir? (s/n): ","Ingrese un dato valido!\n",&bufferChar,2)==0)
								{
									salir=tolower(bufferChar);
									if(salir=='s')
									{
										option=4;
									}
									else if(salir=='n')
									{
										option=0;
									}
								}
								break;
						}
					}while(optionSubmenu!=4);
					break;
				case 8:
					if(GetChar("Seguro desea salir? (s/n): ","Ingrese un dato valido!\n",&bufferChar,2)==0)
					{
						salir=tolower(bufferChar);
						if(salir=='s')
						{
							printf("\n>>> SALIDA CON EXITO <<<\n\n\n");
							option=10;
						}
						else if(salir=='n')
						{
							option=0;
						}
					}
					break;
			}
			system("pause");
			system("cls");
		}while(option != 8);
	}
	else
	{
		printf("No trajo el archivo!");
	}
	return EXIT_SUCCESS;
}
