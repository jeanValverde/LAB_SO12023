# Especifica el compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall

# Lista de archivos objeto
OBJS = src/coordinador.c 

# Nombre del ejecutable
TARGET = programa

# Regla para crear el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para crear cada archivo objeto
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Regla para limpiar los archivos generados por el compilador
clean:
	rm -f $(TARGET)

run:
	./$(TARGET)  -i /archivo -c lineas


.PHONY: clean run
