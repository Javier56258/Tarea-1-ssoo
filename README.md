# Tarea-1-ssoo
Esta tarea consiste en generar una carrera de autos por consola de Linux utilizando programación multihebras. Cada auto compite en una hebra distinta.

## Instrucciones para compilar y ejecutar el programa:
### Antes de compilar el programa debes cumplir ciertos requisitos:
- Debes tener instalado el sistema operativo Linux
- Contar con el compilador g++ y la herramienta make.
- Descargar los archivos aquí presentes Tarea1SO.cpp y Makefile.
### Compilar:
- Abre una terminal y navega al directorio donde se encuentran los archivos del programa desccargados.
- Ejecuta el comando *make* ```make ``` para compilar el programa. Con eso se genera un nuevo archivo Tarea1SO.o
  que puede ser borrado con ```make clean ```. *Dato:* El Makefile debe estar escrito de esa manera para funcionar bien y su codigo está hecho para compilar en especifico el archivo llamado *Tarea1SO.cpp* por lo que se debe tener cuidado si se duplica algun archivo o si se decidió compilar de otra manera que implicara cambiar el nombre de un archivo.
### Ejecutar:
- Con las instrucciones anteriores cumplidas ya se puede ejecutar la carrera. Esto se hace especificando 2 argumentos que son la cantidad de metros y cantidad de autos respectivamente
- Ejemplo: ```./Tarea1SO 100 5 ```
- Lo anterior ejecutará la carrera mostrando cuantos metros son y cuantos autos compiten antes de iniciar la carrera. En la carrera se muestra cuantos metros lleva cada auto y se va avizando el lugar en el que llegan al terminar la carrera. Al finalizar todos la carrera el programa muestra un "podio" con el orden en que llegaron los autos y sus respectivos lugares en la carrera.
- En caso de tener instalado htop puedes ejecutarlo en terminal en segundo plano a la ejecución de la carrera. Esto muestra como van los autos de una manera más dinámica.
- En caso de seguir el paso anterior presionas *F3* para activar la barra de busqueda y puedes buscar el ejecutable por *Tarea1SO*
- Posterior a terminar la carrera, para salir de htop puedes presionar *q* o *F10*
