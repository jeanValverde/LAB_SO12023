char* trim(char* str) {
  char* end;
  
  // Elimina los espacios en blanco al inicio de la cadena
  while (isspace(*str)) {
    str++;
  }
  
  // Si la cadena está vacía, devuelve la cadena
  if (*str == '\0') {
    return str;
  }
  
  // Elimina los espacios en blanco al final de la cadena
  end = str + strlen(str) - 1;
  while (end > str && isspace(*end)) {
    end--;
  }
  
  // Agrega el carácter nulo al final de la cadena
  *(end + 1) = '\0';
  
  return str;
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
 * @def imprime por pantalla un mensaje
 * @param char mensaje 
*/
void escribir(char mensaje[]){
  printf("%s\n    ", mensaje);
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