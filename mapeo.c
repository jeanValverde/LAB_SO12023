#define MAX_MAP 300

struct Mapeo {
  char llave[100];
  struct Permiso permisos[MAX_PERMISOS];
  int count_permisos;
};

struct Mapeo resultados_mapeo[MAX_MAP]; //soporte para 100 grupos unicos
int num_mapeos = 0; //cantidad mapeada 

void print_mapeo(struct Mapeo mapeo){
  printf("\n------------------------------------------\n");   
  printf("Llave: %s\n",mapeo.llave);
  printf("Cantidad de permisos: %d\n",mapeo.count_permisos);
  for (int i = 0; i < mapeo.count_permisos; i++) {
    print_permiso(mapeo.permisos[i]); 
  }
  printf("\n------------------------------------------\n");   
}

void print_mapeos(){
  printf("\nCantidad de mapeos: %d\n", num_mapeos);
  for (int i = 0; i < num_mapeos ; i++) {
    if(resultados_mapeo[i].llave != NULL){
      print_mapeo(resultados_mapeo[i]);
    }
  }
}

/**
 * verifica que exista una y solo una llave
 * -1: podemos ingresarla nueva
 * <> -1: existe retorna el indice
*/
int search(char llave[100]){  
  int indiceMapeo = -1; 
  for (int i = 0; i < num_mapeos ; i++) { 
    int equals = strcmp(resultados_mapeo[i].llave, llave);
    if(equals == 0){  
      indiceMapeo = i;
    }
  }  
  return indiceMapeo;
}


/**
 * agrega un nuevo mapeo
*/
void push_mapeo(char llave[100], struct Permiso permiso){

  int existe = search(llave); 
  //printf(" resutado de la busqueda: %s %d \n", permiso.grupo,  existe);
  
  if(existe == -1){  
    struct Mapeo mapeo;  
    strcpy(mapeo.llave,llave); 
    mapeo.permisos[mapeo.count_permisos] = permiso;
    mapeo.count_permisos = mapeo.count_permisos + 1; 
    resultados_mapeo[num_mapeos] = mapeo; 
    num_mapeos++; 
  }else{
    //agrega solo el nuevo vehiculo  
    int next = resultados_mapeo[existe].count_permisos;
    resultados_mapeo[existe].permisos[next] = permiso;
    resultados_mapeo[existe].count_permisos = next+1;
  }
  
  
}


/*
*funcion para indicar el tipo de mapeo a utilizar
*/
void filter_by_grupo(struct Permiso permiso){    
  push_mapeo(permiso.grupo, permiso); 
}


/**
 * Aplicar el mapeo segun la regla o funcion indicada 
*/
void map(void (*filter)(struct Permiso)) { 
  for (int i = 0; i < get_cantidad_permisos() ; i++) {   
    //struct Permiso permiso = get_permiso(i); 
    filter(permisos[i]); 
  }
}

