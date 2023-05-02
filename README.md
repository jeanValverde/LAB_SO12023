# Sistemas Operativos 1/2023 Laboratorio 1


En este laboratorio, se pide que implemente una soluci´on capaz de leer un gran conjunto de datos,
espec´ıficamente una base de datos chilena perteneciente a la municipalidad de Calbuco donde se almacena
un registro de los permisos de circulaci´on correspondientes al a˜no 2022. El objetivo es simular MapReduce
creado por Google. En esta primera parte, solo se requiere que sea capaz de procesar los datos, realizando
operaciones sencillas para obtener m´etricas que puedan aportar informaci´on ´util.

Se solicitan tres programas. Uno para coordinar y distribuir los datos de entrada a la etapa de mapeo,
adem´as de recibirle a la etapa de reduce las respectivas salidas. El segundo c´odigo, se encargar´a de representar
la etapa de mapeo, la cual calcular´a las propiedades descritas previamente. Finalmente el tercer c´odigo
representa la tercera etapa, correspondiente a Reduce.

## DataSet


Grupo de Vehículo, Placa, Digito, Código SII, Año del Vehículo, Tasación Fiscal, Tipo de Pago, Valor Neto, Valor IPC, Valor Multa, Valor Total Pagado, Forma de Pago, Fecha de Pago, Año Permiso, Tipo Vehículo, Marca, Modelo, Color, Transmisión, Tipo Combustible, Equipamiento y Número Puertas

[Permiso de Circulación Año 2022](https://datos.gob.cl/dataset/permiso-de-circulacion-ano-2022)
 
## Entregables

* Makefile: Archivo para make que compila el programa. De no incluirlo, el trabajo ser´a evaluado con
la calificaci´on m´ınima.

* coordinador.c: archivo con el c´odigo del proceso padre. Puede inclu´ır otros archivos fuente. Recuerde
que todas las funciones deben estar comentadas, explicadas de forma entendible especificando sus
entradas, funcionamiento y salida. Si una funci´on no est´a explicada se bajar´a puntaje.

* mapeo.c: archivo con el c´odigo para el c´alculo de propiedades. Puede inclu´ır otros archivos fuente.
Recuerde que todas las funciones deben estar comentadas, explicadas de forma entendible especificando
sus entradas, funcionamiento y salida. Si una funci´on no est´a explicada se bajar´a puntaje.

* reduce.c: archivo con el c´odigo para el c´alculo de propiedades. Puede inclu´ır otros archivos fuente.
Recuerde que todas las funciones deben estar comentadas, explicadas de forma entendible especificando
sus entradas, funcionamiento y salida. Si una funci´on no est´a explicada se bajar´a puntaje.

* Trabajos con c´odigos que hayan sido copiados de un trabajo de otro grupo ser´an calificados con la nota
m´ınima.

 
## Run for MakeFile

```
  make
```

```
  ./programa -i [ubicacion CSV] -c [LINEAS] [ -d  opcional] 
```


## License

[MIT](https://choosealicense.com/licenses/mit/)
