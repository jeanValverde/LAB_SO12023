#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "util.c"
#include "mapeo.c"


Vehiculo vehiculos[10000]; //vehiculos y la cantidad maxima 
int RECUENTO = 0; //recuento real de lineas en la lectura del csv


/**
 * @return void 
 * @def imprime por pantalla un mensaje
 * @param char mensaje 
*/
void escribir(char mensaje[]){
  printf("%c\n    ", mensaje);
}

/**
 * @return FILE
 * @def Lee un archivo con una ruta absoluta  
 * @param char path (ruta absoluta)    
*/
FILE *read_csv(char *path_csv)
{
  FILE *fp = fopen(path_csv, "r");
  return fp;
}

/**
 * @return void
 * @def Imprime por pantalla un mensaje y sale de la aplicacion 
 * @param char mensaje
*/
void end(char mensaje[]){
  printf(mensaje);
  exit(1);
}

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


/**
 * @return void 
 * @def recorrer por pantalla un vehiculo
 * @param vehiculo 
*/
void print_vehiculos(Vehiculo vehiculo[]){
  int count = 0;
  for (int i = 0; i < RECUENTO; i++) {
    if(vehiculo[i].grupo != NULL){
      print_vehiculo(vehiculo[i]);
      count++;
    } 
  }
  printf("\nprint %d filas.\n", count );
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
  //Vehiculo vehiculos[max_lines]; 
  vehiculos[max_lines];
  int count_row = 0;

  // Leer línea por línea del archivo CSV
  while (fgets(row, max_lines, csv) != NULL){

    // Dividir la línea en campos separados por ";"
    char *row_read = strtok(row, ";");
    int columna = 0; 
    Vehiculo vehiculo = new_vehiculo();
  
    while (row_read != NULL) {
      
      if(columna == 0){ 
        vehiculo.grupo = row_read;
      }

      if(columna == 5){
        int value = atoi(row_read);
        vehiculo.tasacion = value;
      }

      if(columna == 10){
        int value = atoi(row_read);
        vehiculo.valor_pagado = value;
      }

      if(columna == 22){
        int value = atoi(row_read);
        vehiculo.numero_puertas = value;
      }

      row_read = strtok(NULL, ";");
      columna++;
    }

    vehiculos[count_row] = vehiculo;
    count_row++;
  }

  RECUENTO = count_row;
  printf("\nSe leyeron %d filas en el csv.\n", count_row );
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

  map(filter_by_grupo,RECUENTO,vehiculos,"Vehiculo Liviano");

  print_vehiculos(resultados);



  return 0;
}

