## 🧑‍💻 Menú de la Aplicación del CLI

Al ejecutar `seguimiento-de-materias.exe`, se muestra el siguiente menú:

```
     == SEGUIMIENTO DE MATERIAS ==
     1 - Ver listado de materias
     2 - Filtrar materias Cursables
     3 - Filtrar materias En Curso
     4 - Filtrar materias Siguiente Cuatrimestre
     5 - Filtrar materias con Final Pendiente
     6 - Filtrar materias Aprobadas
     ----------------------------------------
     0 - Salir
```

---

### Declaraciones de structs:

```c
     // Como se encuentra en materias.dat
     typedef struct {
          int id;
          int nombreLength;
          char nombre;
          int correlativasLength;
          int *correlativas; // Contiene materias ID
     } materia_archivo_t;

     // AL guardar la informacion de materias.dat en el materiasArray, tambien se le agrega la nueva prop "estado" cuyo valor se obtiene desde ${materiaId}.dat
     typedef struct {
          int id;
          int nombreLength;
          char nombre;
          int correlativasLength;
          int *correlativas; // Contiene materias ID
          int estado; // Entre 1 y 5
     } materia_con_estado_t;
```

## 📘 Opciones del menú:

### 1. Ver listado de materias

-    ### Muestra todas las materias registradas.

     -    Lee `../bin/materias-length.dat` el cual contiene un entero (`int`).
     -    Reservar memoria para `materiasArray` (materiasLength \* sizeof(materia_con_estado_t)).
     -    Lee `../bin/materias.dat` cuya estructura es `materia_archivo_t`.
     -    Guardar los datos de `materias.dat` en `materiasArray`.
     -    Ordenar las materias de la A-Z.
     -    Iterar en `materiasArray` para mostrar el listado de materias junto con su index + 1, de forma tal que `index + 1` - `NombreDeMateria`.

     ```
     == LISTADO DE MATERIAS ==
     0 - Volver
     ---------------------------------------------------
     1 - Algebra-1
     2 - Fisica-1
     3 - Introduccion a la Ingenieria
     4 - Matematica-1
     ...
     ```

-    ### Permite seleccionar una materia y ver mas de su informacion.

     -    Se accede a los datos de la materia seleccionada haciendo `materiasArray[numeroIngresado - 1]`, dado a que numeroIngresado es el `index + 1`.
     -    Los datos se envian a otra funcion que obtiene el estado de la materia ingresando a `bin/${materiaId}.dat`.
     -    Guardar dicho estado en `materiasArray[index].estado`.
     -    Mostrar en pantalla todos los datos.


         ```
         == MATERIA Fisica-1 ==
         id: 4
         nombre: Fisica-1
         correlativas: Matematica-1, Algebra-1
         estado: no cursada
         ---------------------------------------------------
         1 - Editar estado
         0 - Volver
         ```

-    ### Permite editar el estado personal de la materia seleccionada.
     -    Se muestra en pantalla las opciones pre-establecidas de cada uno de los 5 estados.
     -    Si el estado seleccionado es 5 (Aprobado), primero checkear que sus correlatividades hayan sido Aprobadas (con `bin/${materiaId}.dat` = 5). De no haber sido aprobada se devuelve el `Error` "La materia requiere que la correlativa ${nombre} haya sido aprobada". Devolver a la seleccion de estado.
     -    Al seleccionar uno se acutualiza el archivo `bin/${materiaId}.dat` con el nuevo valor (`int`) seleccionado.
     -    Volver a la Card de la Materia.
     ```
     == NUEVO ESTADO DE Fisica-1 ==
     1 - no cursada
     2 - en curso
     3 - siguiente cuatrimestre
     4 - final pendiente
     5 - aprobada
     ---------------------------------------------------
     0 - Cancelar
     ```

### 2. Filtrar materias Cursables

-    Permite filtrar solo aquellas materias que sean Cursables. Se consideran "cursables" aquellas materias No Cursadas cuyas correlatividades ya están finalizadas o aprobadas, es decir, todas sus correlativas tienen estado 4 (Final Pendiente) o 5 (Aprobada).

     -    Lee `../bin/materias-length.dat` el cual contiene un entero (`int`).
     -    Reservar memoria para `materiasArray` (materiasLength \* sizeof(materia_con_estado_t)).
     -    Lee `../bin/materias.dat` cuya estructura es `materia_archivo_t`.
     -    Guardar los datos de `materias.dat` en `materiasArray`.
     -    Iterar en `materiasArray` y obtener el estado de la materia ingresando a `bin/${materiaId}.dat`.
     -    Guardar el estado de cada materia en su respectivo objeto `materiasArray[index].estado`.
     -    Filtrar materias que tienen estado **1 (No cursada)**.
     -    Iterar en las materias filtradas y re-iterar en su Array de correlativas `materiasArray[index].correlativas` que contiene `[..., materiaId]`.
     -    Verificar el estado de todas sus correlatividades accediendo a `bin/${materiaId}.dat`.
     -    Contar únicamente aquellas materias cuyas correlatividades contienen todas el estado 4 (Final Pendiente) o 5 (Aprobada) y guardar el int contado en `materiasCursablesLength`.
     -    Reservar memoria para `materiasCursablesArray` (materiasCursablesLength \* sizeof(materia_con_estado_t))
     -    Guardar en `materiasCursables` únicamente aquellas materias cuyas correlatividades contienen todas el estado 4 (Final Pendiente) o 5 (Aprobada).
     -    Ordenar las materias de la A-Z.
     -    Iterar en `materiasArray` para mostrar el listado de materias junto con su index + 1, de forma tal que `index + 1` - `NombreDeMateria`.

     ```
     == MATERIAS CURSABLES ==
     0 - Volver
     ---------------------------------------------------
     1 - Algebra-2
     2 - Fisica-1
     3 - Matematica-2
     ...
     ```

-    ### Permite seleccionar una materia y ver mas de su informacion.

     -    Se accede a los datos de la materia seleccionada haciendo `materiasArray[numeroIngresado - 1]`, dado a que numeroIngresado es el `index + 1`.
     -    Los datos se envian a otra funcion que obtiene el estado de la materia ingresando a `bin/${materiaId}.dat`.
     -    Guardar dicho estado en `materiasArray[index].estado`.
     -    Mostrar en pantalla todos los datos.


         ```
         == MATERIA Fisica-1 ==
         id: 4
         nombre: Fisica-1
         correlativas: Matematica-1, Algebra-1
         estado: no cursada
         ---------------------------------------------------
         1 - Editar estado
         0 - Volver
         ```

-    ### Permite editar el estado personal de la materia seleccionada.
     -    Se muestra en pantalla las opciones pre-establecidas de cada uno de los 5 estados.
     -    Si el estado seleccionado es 5 (Aprobado), primero checkear que sus correlatividades hayan sido Aprobadas (con `bin/${materiaId}.dat` = 5). De no haber sido aprobada se devuelve el `Error` "La materia requiere que la correlativa ${nombre} haya sido aprobada". Devolver a la seleccion de estado.
     -    Al seleccionar uno se acutualiza el archivo `bin/${materiaId}.dat` con el nuevo valor (`int`) seleccionado.
     -    Volver a la Card de la Materia.
     ```
     == NUEVO ESTADO DE Fisica-1 ==
     1 - no cursada
     2 - en curso
     3 - siguiente cuatrimestre
     4 - final pendiente
     5 - aprobada
     ---------------------------------------------------
     0 - Cancelar
     ```

### 3 a 6. Filtros por estado

-    Permiten filtrar solo aquellas materias que coincidan con un estado específico.

     -    Lee `../bin/materias-length.dat` el cual contiene un entero (`int`).
     -    Reservar memoria para `materiasArray` (materiasLength \* sizeof(materia_con_estado_t)).
     -    Lee `../bin/materias.dat` cuya estructura es `materia_archivo_t`.
     -    Guardar los datos de `materias.dat` en `materiasArray`.
     -    Iterar en `materiasArray` y obtener el estado de la materia ingresando a `bin/${materiaId}.dat`.
     -    Guardar el estado de cada materia en su respectivo objeto `materiasArray[index].estado`.
     -    Filtrar materias que tienen estado seleccionado.
     -    Ordenar las materias de la A-Z.
     -    Iterar en `materiasArray` para mostrar el listado de materias junto con su index + 1, de forma tal que `index + 1` - `NombreDeMateria`.

     ```
     == MATERIAS {NombreDelFiltro} ==
     0 - Volver
     ---------------------------------------------------
     1 - Algebra-2
     2 - Fisica-1
     3 - Matematica-2
     ...
     ```

-    ### Permite seleccionar una materia y ver mas de su informacion.

     -    Se accede a los datos de la materia seleccionada haciendo `materiasArray[numeroIngresado - 1]`, dado a que numeroIngresado es el `index + 1`.
     -    Los datos se envian a otra funcion que obtiene el estado de la materia ingresando a `bin/${materiaId}.dat`.
     -    Guardar dicho estado en `materiasArray[index].estado`.
     -    Mostrar en pantalla todos los datos.


         ```
         == MATERIA Fisica-1 ==
         id: 4
         nombre: Fisica-1
         correlativas: Matematica-1, Algebra-1
         estado: no cursada
         ---------------------------------------------------
         1 - Editar estado
         0 - Volver
         ```

-    ### Permite editar el estado personal de la materia seleccionada.
     -    Se muestra en pantalla las opciones pre-establecidas de cada uno de los 5 estados.
     -    Si el estado seleccionado es 5 (Aprobado), primero checkear que sus correlatividades hayan sido Aprobadas (con `bin/${materiaId}.dat` = 5). De no haber sido aprobada se devuelve el `Error` "La materia requiere que la correlativa ${nombre} haya sido aprobada". Devolver a la seleccion de estado.
     -    Al seleccionar uno se acutualiza el archivo `bin/${materiaId}.dat` con el nuevo valor (`int`) seleccionado.
     -    Volver a la Card de la Materia.
     ```
     == NUEVO ESTADO DE Fisica-1 ==
     1 - no cursada
     2 - en curso
     3 - siguiente cuatrimestre
     4 - final pendiente
     5 - aprobada
     ---------------------------------------------------
     0 - Cancelar
     ```

### 0. Salir

-    Cierra la aplicación.
     -    Mostrar confirmacion de salida "Esta seguro que desea salir? (S/N)"
     -    Si introduce "N" devolver al menú principal.
     -    Si introduce "S" cerrar app.
