/*
 * Cliente&Venta.c
 *
 *  Created on: 22 nov. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Gets.h"
#include "Cliente&Venta.h"

Cliente* ClienteyVenta_addCliente(LinkedList* lista,int* id)
{
	Cliente bufferCliente;
	Cliente* pCliente;

	pCliente=Cliente_new();
	if(pCliente!=NULL)
	{
		if(GetString("Ingrese nombre del cliente: ","Ingrese un dato valido!\n",bufferCliente.nombre,NOMBRE_LEN,2)==0
				&& GetString("Ingrese apellido del cliente: ","Ingrese un dato valido!\n",bufferCliente.apellido,APELLIDO_LEN,2)==0
				&& GetCuit("Ingrese numero de cuit con el siguiente formato xx-xxxxxxxx-x: ","Ingrese un dato valido! Recuerde: xx-xxxxxxxx-x",bufferCliente.cuit,2)==0)
		{
			if(ClienteyVenta_CheckCuit(lista,bufferCliente.cuit)==0)
			{
				Cliente_setIdInt(pCliente,*id);
				Cliente_setNombre(pCliente,bufferCliente.nombre);
				Cliente_setApellido(pCliente,bufferCliente.apellido);
				Cliente_setCuit(pCliente,bufferCliente.cuit);
				printf("#Su id es: %d\n",*id);
				(*id)++;
			}
			else
			{
				printf("ERROR! Cuit existente en la lista\n");
				Cliente_delete(pCliente);
				pCliente=NULL;
			}
		}
		else
		{
			Cliente_delete(pCliente);
			pCliente=NULL;
		}
	}
	return pCliente;
}

Venta* ClienteyVenta_addVenta(LinkedList* listC,LinkedList* listV,int* id)
{
	Cliente bufferCliente;
	Venta bufferVenta;
	Venta* pVenta;

	pVenta=Venta_new();
	if(pVenta!=NULL)
	{
		if(ll_map(listC,Cliente_Listar)==0
				&& GetInt("Ingrese el id del cliente: ","Ingrese un dato valido!\n",&bufferCliente.idCliente,2)==0
				&& ClienteyVenta_BuscarPorIdCliente(listC,bufferCliente.idCliente)!=NULL
				&& GetInt("Ingrese la cantidad de afiches: ","Ingrese un dato valido!\n",&bufferVenta.cantAfiches,2)==0
				&& GetString("Ingrese el nombre del archivo: ","Ingrese un dato valido!\n",bufferVenta.nombreArchivo,NOMBREARCH_LEN,2)==0
				&& GetOption("1).Zona Sur\n2).Zona Oeste\n3).CABA\nIngrese la zona: ", "Ingrese un dato valido!\n",&bufferVenta.zona,2,1,3)==0)
		{
			Venta_setIdVentaInt(pVenta,*id);
			Venta_setIdClienteInt(pVenta,bufferCliente.idCliente);
			Venta_setCantAfichesInt(pVenta,bufferVenta.cantAfiches);
			Venta_setNombreArchivo(pVenta,bufferVenta.nombreArchivo);
			Venta_setZonaInt(pVenta,bufferVenta.zona);
			Venta_setEstadoInt(pVenta,A_COBRAR);
			printf("#El id de venta es: %d\n",*id);
			(*id)++;
		}
		else
		{
			Venta_delete(pVenta);
			pVenta=NULL;
		}
	}
	return pVenta;
}

Cliente* ClienteyVenta_BuscarPorIdCliente(LinkedList* lista,int id)
{
	Cliente* retorno=NULL;
	int i;
	Cliente* pCliente;
	Cliente bufferCliente;
	if(lista!=NULL)
	{
		for(i=0;i<ll_len(lista);i++)
		{
			pCliente=(Cliente*)ll_get(lista,i);;
			Cliente_getId(pCliente,&bufferCliente.idCliente);
			if(id==bufferCliente.idCliente)
			{
				retorno=pCliente;
				break;
			}
		}
	}
	return retorno;
}

Venta* ClienteyVenta_BuscarPorIdVenta(LinkedList* lista,int id)
{
	Venta* retorno=NULL;
	int i;
	Venta* pVenta;
	int bufferIdVenta;
	if(lista!=NULL)
	{
		for(i=0;i<ll_len(lista);i++)
		{
			pVenta=(Venta*)ll_get(lista,i);;
			Venta_getVentaId(pVenta,&bufferIdVenta);
			if(id==bufferIdVenta)
			{
				retorno=pVenta;
				break;
			}
		}
	}
	return retorno;
}

int ClienteyVenta_CheckCuit(LinkedList* lista,char* cuit)
{
	int i;
	int retorno=0;
	Cliente* pCliente;
	Cliente bufferCliente;
	if(lista!=NULL)
	{
		for(i=0;i<ll_len(lista);i++)
		{
			pCliente=(Cliente*)ll_get(lista,i);
			if(pCliente!=NULL && strncmp(cuit,bufferCliente.cuit,CUIT_LEN)==0)
			{
				retorno=-1;
				break;
			}
		}
	}
	return retorno;
}

int ClienteyVenta_ModificarVenta(LinkedList* listaC,LinkedList* listaV,int (*pFunc)(Venta*))
{
	LinkedList* listaNueva=ll_newLinkedList();
	Venta* pVenta;
	Cliente* pCliente;
	int bufferIdVenta;
	int bufferIdCliente;
	int retorno=-1;
	if(listaC!=NULL && listaV!=NULL && listaNueva!=NULL)
	{
		listaNueva=ll_clone(listaV);
		if(listaNueva!=NULL)
		{
			ll_filter(listaNueva,ClienteyVenta_VentasACobrar);
			ll_map(listaNueva,Venta_Listar);
			if(GetInt("Ingrese el id de la venta: ","Ingrese un dato valido!\n",&bufferIdVenta,2)==0)
			{
				pVenta=ClienteyVenta_BuscarPorIdVenta(listaNueva,bufferIdVenta);
				if(pVenta!=NULL)
				{
					Venta_getIdCliente(pVenta,&bufferIdCliente);
					pCliente=ClienteyVenta_BuscarPorIdCliente(listaC,bufferIdCliente);
					if(pCliente!=NULL)
					{
						Cliente_Listar(pCliente);
						if(pFunc(pVenta)==0)
						{
							retorno=0;
						}
					}
				}
			}
			ll_deleteLinkedList(listaNueva);
		}
	}
	return retorno;
}

int ClienteyVenta_VentasACobrar(void* pElement)
{
	Venta* pVenta;
	int retorno=0;
	int bufferEstado;
	if(pElement!=NULL)
	{
		pVenta=(Venta*)pElement;
		Venta_getEstado(pVenta,&bufferEstado);
		if(bufferEstado==A_COBRAR)
		{
			retorno=1;
		}
	}
	return retorno;
}

int ClienteyVenta_VentasCobradas(void* pElement)
{
	Venta* pVenta;
	int retorno=0;
	int bufferEstado;
	if(pElement!=NULL)
	{
		pVenta=(Venta*)pElement;
		Venta_getEstado(pVenta,&bufferEstado);
		if(bufferEstado==COBRADO)
		{
			retorno=1;
		}
	}
	return retorno;
}

int ClienteyVenta_ModificarCamposVenta(Venta* pVenta)
{
	int opcion;
	int salir;
	char bufferChar;
	Venta bufferVenta;
	int retorno;
	int flagMod=0;
	do
	{
		Venta_getVentaId(pVenta,&bufferVenta.idVenta);
		Venta_getIdCliente(pVenta,&bufferVenta.idCliente);
		Venta_getNombreArchivo(pVenta,bufferVenta.nombreArchivo);
		Venta_getCantAfiches(pVenta,&bufferVenta.cantAfiches);
		Venta_getZona(pVenta,&bufferVenta.zona);
		Venta_getEstado(pVenta,&bufferVenta.estado);
		printf("*******************************************************\n");
		printf("Id Venta: %d\nId Cliente: %d\nCantidad de afiches: %d\nZona: %d\nEstado: %d\nNombre del archivo: %s\n",bufferVenta.idVenta,bufferVenta.idCliente,
				bufferVenta.cantAfiches,
				bufferVenta.zona,
				bufferVenta.estado,
				bufferVenta.nombreArchivo);
		printf("*******************************************************\n\n");
		GetOption("MODIFICAR VENTA\n\n1).Modificar nombre del archivo.\n2)Modificar cantidad de afiches.\n3).Modificar zona.\n4).Salir.\nQue desea modificar: ","Ingrese un dato valido!\n",&opcion,2,1,4);
		switch(opcion)
		{
			case 1:
				if(GetString("Ingrese nuevo nombre al archivo: ","Ingrese un dato valido!\n",bufferVenta.nombreArchivo,NOMBREARCH_LEN,2)==0)
				{
					Venta_setNombreArchivo(pVenta,bufferVenta.nombreArchivo);
					flagMod=1;
				}
				break;
			case 2:
				if(GetInt("Ingrese la nueva cantidad de afiches: ","Ingrese un dato valido!92n",&bufferVenta.cantAfiches,2)==0)
				{
					Venta_setCantAfichesInt(pVenta,bufferVenta.cantAfiches);
					flagMod=1;
				}
				break;
			case 3:
				if(GetOption("1).Zona Sur\n2).Zona Oeste\n3).CABA\nIngrese la nueva zona: ", "Ingrese un dato valido!\n",&bufferVenta.zona,2,1,3)==0)
				{
					Venta_setZonaInt(pVenta,bufferVenta.zona);
					flagMod=1;
				}
				break;
			case 4:
				if(GetChar("Seguro desea salir? (s/n): ","Ingrese un dato valido!\n",&bufferChar,2)==0)
				{
					if(flagMod==1)
					{
						retorno=1;
					}else if(flagMod==0)
					{
						retorno=0;
					}
					else
					{
						retorno=-1;
					}
					salir=tolower(bufferChar);
					if(salir=='s')
					{
						printf("\n>>> SALIDA CON EXITO <<<\n\n\n");
						opcion=4;
					}
					else if(salir=='n')
					{
						opcion=0;
					}
				}
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 4);
	return retorno;
}

int ClienteyVenta_ModificarEstadoVenta(Venta* pVenta)
{
	char bufferChar;
	char decision;
	int retorno=-1;
	if(pVenta!=NULL)
	{
		GetChar("Desea cambiar el estado? (s/n): ","Ingrese un dato valido!\n",&bufferChar,2);
		decision=tolower(bufferChar);
		if(decision=='s')
		{
			Venta_setEstadoInt(pVenta,COBRADO);
			retorno=0;
		}
	}
	return retorno;
}

int ClienteyVenta_CompararAfichesCargados(void* pElement, void* arg)
{
	Venta* pVenta = (Venta*)pElement;
	int* idCliente=(int*)arg;
	int bufferId;
	int estado;
	int cant=0;

	Venta_getIdCliente(pVenta,&bufferId);
	Venta_getEstado(pVenta,&estado);
	if((*idCliente)==bufferId && estado==COBRADO)
	{
		Venta_getCantAfiches(pVenta,&cant);
	}
	return cant;
}
