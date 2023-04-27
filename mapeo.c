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

Mapeo resultados_mapeo[100]; //soporte para 100 grupos unicos
int unicos = 0; //cantidad mapeada 

/**
 * verifica que exista una y solo una llave
 * -1: podemos ingresarla nueva
 * <> -1: existe retorna el indice
*/
int search(char *llave){
  for (int i = 0; i < unicos ; i++) {
    if(resultados_mapeo[i].llave != NULL){
      //revisar 
      if(resultados_mapeo[i].llave == llave){
        //printf("ENCONTRADO %S ==  %S \n", resultados_mapeo[i].llave, llave );
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
  mapeo.vehiculos[0] = new_vehiculo();
  return mapeo;
}

void print_mapeo(Mapeo mapeo){
  printf("\n");
  printf(mapeo.llave);
  printf("Llave: %s\n",mapeo.llave);
  printf("Cantidad de vehiculos: %d\n",mapeo.count_vehiculos);
  printf("\n");
}

void print_mapeos(){
  printf("\nCantidad de mapeos: %d\n", unicos);
  for (int i = 0; i < unicos ; i++) {
    if(resultados_mapeo[i].llave != NULL){
      print_mapeo(resultados_mapeo[i]);
    }
  }
}

/**
 * agrega un nuevo mapeo
*/
void push_mapeo(char *llave, Vehiculo vehiculo){
  printf(llave);

  int existe = search(llave);
  
  if(existe == -1){  
    Mapeo mapeo = new_mapeo(llave); 
    print_mapeo(mapeo); 
    mapeo.vehiculos[mapeo.count_vehiculos] = vehiculo;
    mapeo.count_vehiculos = mapeo.count_vehiculos + 1;
    resultados_mapeo[unicos] = mapeo;
    unicos++; 
  }else{
    //agrega solo el nuevo vehiculo 
    int next = resultados_mapeo[existe].count_vehiculos;
    resultados_mapeo[existe].vehiculos[next] = vehiculo;
    resultados_mapeo[existe].count_vehiculos = next+1;
  }
  
}

/*
*funcion para indicar el tipo de mapeo a utilizar
*/
void filter_by_grupo(Vehiculo vehiculo){  
  //char *posible_llave = trim(vehiculo.grupo); 
  //printf("%s    \n",vehiculo.grupo);
  //push_mapeo(vehiculo.grupo,vehiculo); 
}


/**
 * Aplicar el mapeo segun la regla o funcion indicada 
*/
void map(void (*filter)(Vehiculo), int count, Vehiculo vehiculos[]) {
  int nuevo = 0;
  for (int i = 0; i < count ; i++) {
    //filter(vehiculos[i]); 
    printf("%d  %s\n",i,vehiculos[i].grupo);
  }
}

