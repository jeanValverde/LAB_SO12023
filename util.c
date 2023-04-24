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