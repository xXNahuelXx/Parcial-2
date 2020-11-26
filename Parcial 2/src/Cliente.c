/*
 * Cliente.c
 *
 *  Created on: 21 nov. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Cliente.h"
#include "Validate.h"
#include "Gets.h"

Cliente* Cliente_new()
{
	return (Cliente*)malloc(sizeof(Cliente));
}

Cliente* Cliente_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* cuitStr)
{
	Cliente* pCliente=Cliente_new();
	if(pCliente!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && cuitStr!=NULL)
	{
		Cliente_setIdChar(pCliente,idStr);
		Cliente_setNombre(pCliente,nombreStr);
		Cliente_setApellido(pCliente,apellidoStr);
		Cliente_setCuit(pCliente,cuitStr);
	}
	return pCliente;
}

int Cliente_setIdChar(Cliente* pCliente,char* id)
{
	int retorno=-1;
	if(pCliente!=NULL && id!=NULL && ValidNumber(id,ID_LEN)==1)
	{
		pCliente->idCliente=atoi(id);
		retorno=0;
	}
	return retorno;
}

int Cliente_setIdInt(Cliente* pCliente,int id)
{
	int retorno=-1;
	if(pCliente!=NULL && id>0)
	{
		pCliente->idCliente=id;
		retorno=0;
	}
	return retorno;
}

int Cliente_getId(Cliente* pCliente,int* id)
{
	int retorno=-1;
	if(pCliente!=NULL && id!=NULL)
	{
		*id=pCliente->idCliente;
		retorno=0;
	}
	return retorno;
}

int Cliente_setNombre(Cliente* pCliente,char* nombre)
{
	int retorno=-1;
	if(pCliente!=NULL && nombre!=NULL && ValidString(nombre,NOMBRE_LEN)==1)
	{
		strncpy(pCliente->nombre,nombre,NOMBRE_LEN);
		retorno=0;
	}
	return retorno;
}

int Cliente_getNombre(Cliente* pCliente,char* nombre)
{
	int retorno=-1;
	if(pCliente!=NULL && nombre!=NULL)
	{
		strncpy(nombre,pCliente->nombre,NOMBRE_LEN);
		retorno=0;
	}
	return retorno;
}

int Cliente_setApellido(Cliente* pCliente,char* apellido)
{
	int retorno=-1;
	if(pCliente!=NULL && apellido!=NULL && ValidString(apellido,APELLIDO_LEN)==1)
	{
		strncpy(pCliente->apellido,apellido,APELLIDO_LEN);
		retorno=0;
	}
	return retorno;
}

int Cliente_getApellido(Cliente* pCliente,char* apellido)
{
	int retorno=-1;
	if(pCliente!=NULL && apellido!=NULL)
	{
		strncpy(apellido,pCliente->apellido,APELLIDO_LEN);
		retorno=0;
	}
	return retorno;
}

int Cliente_setCuit(Cliente* pCliente,char* cuit)
{
	int retorno=-1;
	if(pCliente!=NULL && cuit!=NULL && ValidCuit(cuit,CUIT_LEN)==1)
	{
		strncpy(pCliente->cuit,cuit,CUIT_LEN);
		retorno=0;
	}
	return retorno;
}

int Cliente_getCuit(Cliente* pCliente,char* cuit)
{
	int retorno=-1;
	if(pCliente!=NULL && cuit!=NULL)
	{
		strncpy(cuit,pCliente->cuit,CUIT_LEN);
		retorno=0;
	}
	return retorno;
}

int Cliente_setCantVentasACobrar(Cliente* pCliente,int cantVentasACobrar)
{
	int retorno=-1;
	if(pCliente!=NULL && cantVentasACobrar>=0)
	{
		pCliente->cantVentasACobrar=cantVentasACobrar;
		retorno=0;
	}
	return retorno;
}

int Cliente_getCantVentasACobrar(Cliente* pCliente,int* cantVentasACobrar)
{
	int retorno=-1;
	if(pCliente!=NULL && cantVentasACobrar!=NULL)
	{
		*cantVentasACobrar=pCliente->cantVentasACobrar;
		retorno=0;
	}
	return retorno;
}

int Cliente_setCantVentasCobradas(Cliente* pCliente,int cantVentasCobradas)
{
	int retorno=-1;
	if(pCliente!=NULL && cantVentasCobradas>=0)
	{
		pCliente->cantVentasCobradas=cantVentasCobradas;
		retorno=0;
	}
	return retorno;
}

int Cliente_getCantVentasCobradas(Cliente* pCliente,int* cantVentasCobradas)
{
	int retorno=-1;
	if(pCliente!=NULL && cantVentasCobradas!=NULL)
	{
		*cantVentasCobradas=pCliente->cantVentasCobradas;
		retorno=0;
	}
	return retorno;
}

void Cliente_CabeceraListar(void)
{
	printf("%5s %20s %20s %20s","ID_CLIENTE","NOMBRE","APELLIDO","CUIT\n");
	printf("________________________________________________________________________\n");
}

int Cliente_Listar(void* pElement)
{
	int retorno=-1;
	Cliente bufferElement;
	if(pElement!=NULL)
	{
		Cliente_getId((Cliente*)pElement,&bufferElement.idCliente);
		Cliente_getNombre((Cliente*)pElement,bufferElement.nombre);
		Cliente_getApellido((Cliente*)pElement,bufferElement.apellido);
		Cliente_getCuit((Cliente*)pElement,bufferElement.cuit);
		printf("%10d %20s %20s %19s\n",bufferElement.idCliente,bufferElement.nombre,bufferElement.apellido,bufferElement.cuit);
		retorno=0;
	}
	return retorno;
}

void Cliente_delete(Cliente* pElement)
{
	if(pElement!=NULL)
	{
		free(pElement);
	}
}
