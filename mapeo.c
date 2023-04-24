#include "mapeo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Vehiculo resultados[10000];

bool filter_by_grupo(Vehiculo vehiculo, char *llave){  
  if(trim(vehiculo.grupo) == llave){ 
    return true; 
  }
  return false;
}

void map(bool (*filter)(Vehiculo,char *), int count, Vehiculo vehiculo[],char *llave) {
  int nuevo = 0;
  for (int i = 0; i < count ; i++) {
    if(filter(vehiculo[i],llave)){
      resultados[nuevo] = vehiculo[i];
      nuevo++;
    }
  }
}

