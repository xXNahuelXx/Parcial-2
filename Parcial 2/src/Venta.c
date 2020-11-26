/*
 * Venta.c
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Venta.h"
#include "Validate.h"

Venta* Venta_new()
{
	return (Venta*)malloc(sizeof(Venta));
}

Venta* Venta_newParametros(char* idVentaStr,char* idClienteStr,char*cantAfichesStr,char* nombreArchivoStr,char* zonaStr,char* estadoStr)
{
	Venta* pVenta=Venta_new();
	if(pVenta!=NULL && idVentaStr!=NULL && idClienteStr!=NULL && cantAfichesStr!=NULL && nombreArchivoStr!=NULL && zonaStr!=NULL && estadoStr!=NULL)
	{
		Venta_setIdVentaChar(pVenta,idVentaStr);
		Venta_setIdClienteChar(pVenta,idClienteStr);
		Venta_setCantAfichesChar(pVenta,cantAfichesStr);
		Venta_setNombreArchivo(pVenta,nombreArchivoStr);
		Venta_setZonaChar(pVenta,zonaStr);
		Venta_setEstadoChar(pVenta,estadoStr);
	}
	return pVenta;
}

int Venta_setIdVentaChar(Venta* pVenta,char* idVenta)
{
	int retorno=-1;
	if(pVenta!=NULL && idVenta!=NULL && ValidNumber(idVenta,IDVENTA_LEN)==1)
	{
		pVenta->idVenta=atoi(idVenta);
		retorno=0;
	}
	return retorno;
}

int Venta_setIdVentaInt(Venta* pVenta,int idVenta)
{
	int retorno=-1;
	if(pVenta!=NULL && idVenta>0)
	{
		pVenta->idVenta=idVenta;
		retorno=0;
	}
	return retorno;
}

int Venta_getVentaId(Venta* pVenta,int* idVenta)
{
	int retorno=-1;
	if(pVenta!=NULL && idVenta!=NULL)
	{
		*idVenta=pVenta->idVenta;
		retorno=0;
	}
	return retorno;
}

int Venta_setIdClienteChar(Venta* pVenta,char* idCliente)
{
	int retorno=-1;
	if(pVenta!=NULL && idCliente!=NULL && ValidNumber(idCliente,IDCLIENTE_LEN)==1)
	{
		pVenta->idCliente=atoi(idCliente);
		retorno=0;
	}
	return retorno;
}


int Venta_setIdClienteInt(Venta* pVenta,int idCliente)
{
	int retorno=-1;
	if(pVenta!=NULL && idCliente>0)
	{
		pVenta->idCliente=idCliente;
		retorno=0;
	}
	return retorno;
}

int Venta_getIdCliente(Venta* pVenta,int* idCliente)
{
	int retorno=-1;
	if(pVenta!=NULL && idCliente!=NULL)
	{
		*idCliente=pVenta->idCliente;
		retorno=0;
	}
	return retorno;
}

int Venta_setCantAfichesChar(Venta* pVenta,char* cantAfiches)
{
	int retorno=-1;
	if(pVenta!=NULL && cantAfiches!=NULL && ValidNumber(cantAfiches,CANTAFICHES_LEN)==1)
	{
		pVenta->cantAfiches=atoi(cantAfiches);
		retorno=0;
	}
	return retorno;
}

int Venta_setCantAfichesInt(Venta* pVenta,int cantAfiches)
{
	int retorno=-1;
	if(pVenta!=NULL && cantAfiches>0)
	{
		pVenta->cantAfiches=cantAfiches;
		retorno=0;
	}
	return retorno;
}

int Venta_getCantAfiches(Venta* pVenta,int* cantAfiches)
{
	int retorno=-1;
	if(pVenta!=NULL && cantAfiches!=NULL)
	{
		*cantAfiches=pVenta->cantAfiches;
		retorno=0;
	}
	return retorno;
}

int Venta_setNombreArchivo(Venta* pVenta,char* nombreArchivo)
{
	int retorno=-1;
	if(pVenta!=NULL && nombreArchivo!=NULL)
	{
		strncpy(pVenta->nombreArchivo,nombreArchivo,NOMBREARCH_LEN);
		retorno=0;
	}
	return retorno;
}

int Venta_getNombreArchivo(Venta* pVenta,char* nombreArchivo)
{
	int retorno=-1;
	if(pVenta!=NULL && nombreArchivo!=NULL)
	{
		strncpy(nombreArchivo,pVenta->nombreArchivo,NOMBREARCH_LEN);
		retorno=0;
	}
	return retorno;
}

int Venta_setZonaChar(Venta* pVenta,char* zona)
{
	int retorno=-1;
	if(pVenta!=NULL && zona!=NULL && ValidNumber(zona,ZONA_LEN)==1)
	{
		pVenta->zona=atoi(zona);
		retorno=0;
	}
	return retorno;
}

int Venta_setZonaInt(Venta* pVenta,int zona)
{
	int retorno=-1;
	if(pVenta!=NULL && (zona==1 || zona==2 || zona==3))
	{
		pVenta->zona=zona;
		retorno=0;
	}
	return retorno;
}

int Venta_getZona(Venta* pVenta,int* zona)
{
	int retorno=-1;
	if(pVenta!=NULL && zona!=NULL)
	{
		*zona=pVenta->zona;
		retorno=0;
	}
	return retorno;
}

int Venta_setEstadoChar(Venta* pVenta,char* estado)
{
	int retorno=-1;
	if(pVenta!=NULL && estado!=NULL && ValidNumber(estado,ESTADO_LEN)==1)
	{
		pVenta->estado=atoi(estado);
		retorno=0;
	}
	return retorno;
}

int Venta_setEstadoInt(Venta* pVenta,int estado)
{
	int retorno=-1;
	if(pVenta!=NULL && (estado==0 || estado==1))
	{
		pVenta->estado=estado;
		retorno=0;
	}
	return retorno;
}

int Venta_getEstado(Venta* pVenta,int* estado)
{
	int retorno=-1;
	if(pVenta!=NULL && estado>0)
	{
		*estado=pVenta->estado;
		retorno=0;
	}
	return retorno;
}

void Venta_CabeceraListar(void)
{
	printf("%10s %12s %14s %16s %15s %31s","ID_VENTA","ID_CLIENTE","CANT_AFICHES","ZONA","ESTADO","NOMBRE_ARCHIVO\n");
	printf("______________________________________________________________________________________________________\n");
}

int Venta_Listar(void* pElement)
{
	int retorno=-1;
	Venta bufferElement;
	char bufferEstado[ESTADO_LEN];
	char bufferZona[ZONA_LEN];
	if(pElement!=NULL)
	{
		Venta_getVentaId((Venta*)pElement,&bufferElement.idVenta);
		Venta_getIdCliente((Venta*)pElement,&bufferElement.idCliente);
		Venta_getNombreArchivo((Venta*)pElement,bufferElement.nombreArchivo);
		Venta_getCantAfiches((Venta*)pElement,&bufferElement.cantAfiches);
		Venta_getZona((Venta*)pElement,&bufferElement.zona);
		Venta_getEstado((Venta*)pElement,&bufferElement.estado);
		if(bufferElement.estado==1)
		{
			sprintf(bufferEstado,"A COBRAR");
		}
		else
		{
			sprintf(bufferEstado,"COBRADO");
		}
		if(bufferElement.zona==1)
		{
			sprintf(bufferZona,"ZONA SUR");
		}
		else if(bufferElement.zona==2)
		{
			sprintf(bufferZona,"ZONA OESTE");
		}
		else
		{
			sprintf(bufferZona,"CABA");
		}
		printf("%10d %12d %14d  %15s %15s %30s\n",bufferElement.idVenta,bufferElement.idCliente,bufferElement.cantAfiches,bufferZona,bufferEstado,bufferElement.nombreArchivo);
		retorno=0;
	}
	return retorno;
}

void Venta_delete(Venta* pElement)
{
	if(pElement!=NULL)
	{
		free(pElement);
	}
}
