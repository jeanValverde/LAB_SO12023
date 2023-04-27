#define MAX_PERMISOS 20000

struct Permiso {
  char grupo[100]; 
  int tasacion;
  int numero_puertas;
  int valor_pagado; 
};

struct Permiso permisos[MAX_PERMISOS];
int num_permisos = 0;

void add_permiso(struct Permiso permiso) {
  permisos[num_permisos] = permiso;
  num_permisos++;
}

struct Permiso get_permiso(int num_permiso){
    return permisos[num_permiso];
}


int get_cantidad_permisos(){
    return num_permisos;
}

/**
 * @return void 
 * @def imprimir por pantalla un vehiculo
 * @param Permiso permiso
*/
void print_permiso(struct Permiso permiso){
  printf("\n");
  printf("Grupo: %s\n",permiso.grupo);
  printf("Tasacion: %d\n",permiso.tasacion);
  printf("Valor Pagado: %d\n",permiso.valor_pagado);
  printf("Numero de Puertas: %d\n",permiso.numero_puertas);
  printf("\n");
}

/**
 * @return void 
 * @def imprimir por pantalla un permisos
 * @param 
*/
void print_permisos() {
  int count = 0;
  for (int i = 0; i < num_permisos; i++) {
    print_permiso(permisos[i]);
    count++;
  }
  printf("\nprint %d filas. \n", count );
}


