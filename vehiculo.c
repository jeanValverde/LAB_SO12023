//Grupo Vehiculo   #0 
//Tasacion         #5 
//Numero Puertas   #22
//Valor Pagado     #10

typedef struct
{
  char *grupo;
  int tasacion;
  int numero_puertas;
  int valor_pagado;
} Vehiculo;


/**
 * @return Vehiculo vacio 
 * @param none 
 * @def crea un vehciulo vacio 
*/
Vehiculo new_vehiculo(){
  Vehiculo vehiculo;
  vehiculo.grupo = "SIN GRUPO";
  vehiculo.tasacion = 0;
  vehiculo.valor_pagado = 0;
  vehiculo.numero_puertas = 0;
  return vehiculo;
}

/**
 * @return void 
 * @def imprimir por pantalla un vehiculo
 * @param vehiculo 
*/
void print_vehiculo(Vehiculo vehiculo){
  printf("\n");
  printf("Grupo: %s\n",vehiculo.grupo);
  printf("Tasacion: %d\n",vehiculo.tasacion);
  printf("Valor Pagado: %d\n",vehiculo.valor_pagado);
  printf("Numero de Puertas: %d\n",vehiculo.numero_puertas);
  printf("\n");
}