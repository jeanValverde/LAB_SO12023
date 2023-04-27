int sumary_by_tasacion(struct Permiso permiso, int resultado){
  return permiso.tasacion + resultado;
}

int sumary_by_valor_pagado(struct Permiso permiso, int resultado){
  return permiso.valor_pagado + resultado;
}

int sumary_by_dos_puertas(struct Permiso permiso, int resultado){
  if(permiso.numero_puertas == 2){
    resultado++;
  }
  return resultado;
}

int sumary_by_cuatro_puertas(struct Permiso permiso, int resultado){
  if(permiso.numero_puertas == 4){
    resultado++;
  }
  return resultado;
}

int reduce(int (*accion)(struct Permiso, int resultado), char llave[]) { 
  int resultado = 0; 
  int equals = search(llave); 
  if(equals >= 0){    
    struct Mapeo mapeo = get_mapeo(equals);  
    for (int i = 0; i < mapeo.count_permisos ; i++) {   
      resultado = accion(mapeo.permisos[i], resultado);  
    }
  }
  return resultado;
}
 