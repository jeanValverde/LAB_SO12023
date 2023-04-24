#include "mapeo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  char *llave;
  Vehiculo vehiculos[10000];
  int count_vehiculos;
} Mapeo;

Mapeo resultados[100]; //soporte para 100 grupos unicos
int unicos = 0; //cantidad mapeada 

/**
 * verifica que exista una y solo una llave
 * -1: podemos ingresarla nueva
 * <> -1: existe retorna el indice
*/
int search(char *llave){
  if(unicos == 0){
    return -1;
  }

  for (int i = 0; i < unicos ; i++) {
    if(resultados[i].llave != NULL){
      //revisar 
      if(resultados[i].llave == llave){
        return unicos;
      }
    }
  }

  return -1;
}

/**
 * mapeo vacio
*/
Mapeo new_mapeo(char *llave){
  Mapeo mapeo;
  mapeo.llave = llave;
  mapeo.count_vehiculos = 0; 
}

/**
 * agrega un nuevo mapeo
*/
void push_mapeo(char *llave, Vehiculo vehiculo){
  int existe = search(llave);

  if(existe == -1){
    Mapeo mapeo = new_mapeo(llave); 
    mapeo.vehiculos[mapeo.count_vehiculos] = vehiculo;
    mapeo.count_vehiculos = mapeo.count_vehiculos + 1;
    resultados[unicos] = mapeo;
  }else{
    //agrega solo el nuevo vehiculo 
    int next = resultados[existe].count_vehiculos;
    resultados[existe].vehiculos[next] = vehiculo;
    resultados[existe].count_vehiculos = next+1;
  }

}

/*
*
*/
void filter_by_grupo(Vehiculo vehiculo){  
  push_mapeo("Carga",vehiculo);
  push_mapeo("Transporte Publico",vehiculo);
  push_mapeo("Vehiculo Liviano",vehiculo);
}


/**
 * Crear cada resultado si no existe 
*/
void map(void (*filter)(Vehiculo), int count, Vehiculo vehiculos[]) {
  int nuevo = 0;
  for (int i = 0; i < count ; i++) {
    filter(vehiculos[i]);
  }
}

