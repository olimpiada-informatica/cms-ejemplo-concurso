# Ejemplo de concurso para probar CMS

Este repositorio contiene un ejemplo de concurso en formato `italy_yaml`
soportado por [CMS](https://github.com/cms-dev/cms).

Contiene algunos problemas aparecidos en ediciones pasadas de la [OIE](https://olimpiada-informatica.org/)
creados por [Félix Moreno Peñarrubia](https://github.com/FelixMorenoPenarrubia).

El concurso tiene una fecha de inicio y fin no válida (definida en [contest.yaml](contest.yaml))
que es posible que quieras modificar antes de importar el concurso en
una instalación de CMS. La importación se hace utilizando la utilidad de CMS `cmsImportContest`:

```
# Desde el directorio que contiene el fichero contest.yaml
$ cmsImportContest -L italy_yaml -i .
```

Antes de importarlo, **se deben compilar** los validadores de algunas de las tareas.
En concreto, dentro de cada tarea, todos aquellos `check/checker.cpp` o `check/manager.cpp`,
de forma que el fichero generado sea `check/checker` y `check/manager` respectivamente.
Esos ficheros compilados no aparecen en el repositorio pues el binario depende
de la plataforma donde se haya desplegado CMS.

El cometido del repositorio no es tanto ejemplificar un buen diseño de problemas y
generadores sino el "formato italiano" que soporta CMS. Es posible
que los autores de problemas quieran, durante el diseño, utilizar
una estructura de directorios distinta con *scripts* adicionales
para ayudar a compilar y probar soluciones, etc.
