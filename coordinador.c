#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>  
#include <stdbool.h>

#include "util.c"
#include "permiso.c"
#include "mapeo.c"
#include "reduce.c"


/**
 * @return void 
 * @def valida que el numero de lineas no sea 0 - si no es valido sale de la aplicacion 
 * @param char lines (numero de linea para leer en el csv)
*/
void is_valid_lines(char *lines){
  int num = atoi(lines);

  if(num == 0){
    end("Debe ingresar un numero de lineas para leer el csv.   ");
  }

  if(num < 0){
    end("Debe ingresar un numero mayor a 0.");
  }

}

/**
 * @return void 
 * @def valida que el archivo exista - si no esta sale de la aplicacion 
 * @param char path (ubicacion del archivo absoluta)
*/
void is_path_csv(char *path_csv){
  FILE *csv = read_csv(path_csv);
  if(csv == NULL){ 
    end("Debe insertar la unicacion del archivo valida.");
  }
  fclose(csv);
}

/**
 * @return void 
 * @def lee linea por linea el csv y crea vehiculos 
 * @param path, lines  
*/
void get_data_csv(char *path_csv, char *lines){
  FILE *csv = read_csv(path_csv);
  int max_lines = atoi(lines);
  char row[max_lines];
  int count_row = 0;
   
  // Leer línea por línea del archivo CSV
  while (fgets(row, max_lines, csv) != NULL){

    // Dividir la línea en campos separados por ";"
    char *row_read = NULL;
    row_read = strtok(row, ";");
    int columna = 0; 
    struct Permiso permiso;
    
    while (row_read != NULL) {

      if(columna == 0){  
        strcpy(permiso.grupo,row_read);
      } 

      if(columna == 5){
        int value = atoi(row_read);
        permiso.tasacion = value;
      }

      if(columna == 10){
        int value = atoi(row_read);
        permiso.valor_pagado = value;
      }

      if(columna == 22){
        int value = atoi(row_read);
        permiso.numero_puertas = value;
      }
      
      row_read = strtok(NULL, ";");   
      columna++;
    }
   
    add_permiso(permiso);  
  }

  printf("\nSe leyeron %d filas en el csv.\n", get_cantidad_permisos() );
  fclose(csv);
}


int main(int argc, char *argv[])
{

  //input necesarios 
  char *path_csv =  argv[1];
  char *lines = argv[2];

  //validar input 
  is_path_csv(path_csv);
  is_valid_lines(lines);
  
  //leer el archivo 
  get_data_csv(path_csv, lines); 

  //print_permisos();

  //mapea y aplica el filtro relacionado
  map(filter_by_grupo);

  //print_mapeos();

  //aplicar el reduce sobre una accion determinada a los mapeos

  /**
  1. Indicar tasacion total para cada grupo de vehiculo #LLAVE: GRUPO
  2. Indicar el total del valor pagado para cada grupo de vehiculo. #LLAVE: GRUPO
  3. Indicar para cada grupo de vehiculo la cantidad de vehiculos con dos y cuatro puertas. #LLAVE: GRUPO
  */

  for (int i = 0; i < get_num_mapeos() ; i++) {  
    struct Mapeo mapeo = get_mapeo(i);  
    int resultado = reduce(sumary_by_tasacion, mapeo.llave);
    printf("Total de tasaciones para %s: %d\n", mapeo.llave , resultado);
  }


  for (int i = 0; i < get_num_mapeos() ; i++) {  
    struct Mapeo mapeo = get_mapeo(i);  
    int resultado = reduce(sumary_by_valor_pagado, mapeo.llave);
    printf("Total de valor pagado para %s: %d\n", mapeo.llave , resultado);
  }

  
  for (int i = 0; i < get_num_mapeos() ; i++) {  
    struct Mapeo mapeo = get_mapeo(i);  
    int resultado = reduce(sumary_by_dos_puertas, mapeo.llave);
    printf("Total de vehiculos con 2 puertas para %s: %d\n", mapeo.llave , resultado);
  }

  for (int i = 0; i < get_num_mapeos() ; i++) {  
    struct Mapeo mapeo = get_mapeo(i);  
    int resultado = reduce(sumary_by_cuatro_puertas, mapeo.llave);
    printf("Total de vehiculos con 4 puertas para %s: %d\n", mapeo.llave , resultado);
  }
  

  return 0;
}

