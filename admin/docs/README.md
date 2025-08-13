## 🧑‍💻 Menú de la Aplicación del ADMIN

Al ejecutar `seguimiento-de-materias.exe`, primero se lee el archivo `admin/config/menu-principal.txt` para luego poder mostrar el siguiente menú:

```
     == ADMINISTRAR MATERIAS ==
     1 - Editar Materias
     2 - Crear Materia
     3 - Eliminar Materia
     ----------------------------------------
     0 - Salir
```

---

### Declaraciones de structs:

```c
typedef void (*ptr_funcion_void_t)(void);

typedef struct
{
     char *text; // Texto de la opcion
     ptr_funcion_void_t funcion; // Puntero a funcion
} opcion_accion_t;

// La fucion que muestra las materias utilza la funcion de agregar o eliminar materia, segun corresponda, y ambas tienen la misma firma
typedef void (*ptr_funcion_editar_eliminar_materia_t)(char *title, materia_archivo_t *materia, int *materiasLength, materia_archivo_t **materiasArray);

typedef struct
{
     int length;             // Cantidad de opciones
     opcion_accion_t *array; // Array de opciones con acciones
} opciones_acciones_t;

typedef struct
{
     int id;                 // ID único de la materia
     int nombreLength;       // Largo del nombre
     char *nombre;           // Nombre de la materia
     int correlativasLength; // Cantidad de correlativas
     int *correlativas;      // IDs de materias correlativas
} materia_archivo_t;
```

## 📘 Opciones del menú:

- Abrir el archivo `cli/config/menu-principal.txt` para lectura y verificar que exista.
- Leer primero la cantidad de opciones (el primer dato int) para reservar memoria para el `opcionesArray` (sizeof(opcion_accion_t) \* opcionesLength).
- Iterar en el archivo para ir guardando los datos del `funcionId` y `textLength`.
- Reservar memoria dentro del `opcionesArray[i].text` (sizeof(char) \* textLength + 1); el +1 es para poder agragarle el `'\0'`.
- Leer y almacenar el text con `fgets(opcionesArray[i].text, textLength + 1, fp)`.
- Usar el funcionId para poder almacenar la funcion en el objeto `opcionesArray[i].funcion = funcionesArray[funcionIndex]`.
- Por ultimo, almacenar los datos en un objeto `opciones_acciones_t` para su comodo uso `{ opcionesLength, opcionesArray, };`

### 1. Editar Materias

- ### Muestra todas las materias registradas.

  - Lee `../bin/materias-length.dat` el cual contiene un entero (`int`).
  - Reservar memoria para `materiasArray` (materiasLength \* sizeof(materia_t)).
  - Lee `../bin/materias.dat` cuya estructura es `materia_archivo_t`.
  - Guardar los datos de `materias.dat` en `materiasArray`.
  - Ordenar las materias de la A-Z.
  - Iterar en `materiasArray` para mostrar el listado de materias junto con su index + 1, de forma tal que `index + 1` - `NombreDeMateria`.

  ```
  == EDITAR MATERIAS ==
  0 - Volver
  ---------------------------------------------------
  1 - algebra-1
  2 - fisica-1
  3 - introduccion a la ingenieria
  4 - matematica-1
  ...
  ```

- ### Permite seleccionar una materia y ver mas de su informacion.

  - Se accede a los datos de la materia seleccionada haciendo `materiasArray[numeroIngresado - 1]`, dado a que numeroIngresado es el `index + 1`.
  - Los datos se envian a otra funcion que permite editarla.

    ```
    == MATERIA fisica-1 ==
    id: 4
    1 - nombre: fisica-1
    2 - correlativas: matematica-1, algebra-1
    ---------------------------------------------------
    3 - Confirmar
    0 - Cancelar
    ```

  - Confirmar es usado luego de haber editado la materia, guardando los nuevos datos en materias.dat

- ### Permite editar el nombre y correlatividades de la materia seleccionada.

  - Al querer modificar el nombre lo que se escriba se pasa a toLowerCase (todo minuscula).
  - Se compara si es que existe alguna otra materia con el mismo nombre. En caso de que asi sea se devuelve el error "El nombre de la materia ingresado ya existe, por favor elige otro".
  - Si se quiere editar las correlatividades, primero se generan 2 arrays a base de materiasArray:
    - Con la informacion de materiasArray[i].correlativas (array de materiasId int) generamos el "correlativasArray" (se agarra un id de materia del materiasArray[i].correlativas[j], se busca por id en materiasArray para completar la informacion); y es ordenado de la A-Z.
    - noCorrelativasArray es una copia de materiasArray a la cual se le eliminan las materias presentes en materiasArray[i].correlativas; y es ordenado de la A-Z.
  - Con los arrays (correlativasArray y noCorrelativasArray) se genera un menu interactivo para poder quitar y añadir materias (dependiendo si se encuentra o no actualmente en el materia.correlativas).

    ```
     == SELECCIONAR CORRELATIVAS ==
     0 - Cancelar
     ---------------------------------------------------
     1 - algebra-1 [ Quitar ] X
     2 - matematica-1 [ Quitar ] X
     ---------------------------------------------------
     3 - fisica-1 [ Agregar ]
     4 - matematica-2 [ Agregar ]
     ...
    ```

  - Volver a la Card de la Materia.

### 2. Crear Materia

- ### Permite crear una nueva materia.

  - Se reserva espacio para una variable del tipo `materia_archivo_t`.
  - Se checkea cual es el ultimo id disponible en contador-id.dat

    ```
     == CREAR MATERIA  ==
     id: 5
     1 - nombre: --
     2 - correlativas: --
     ---------------------------------------------------------------
     3 - Confirmar
     0 - Cancelar
    ```

  - Confirmar es usado luego de haber editado la materia, guardando los nuevos datos en materias.dat

- ### Permite crear el nombre y agregar correlatividades.

  - Al querer modificar el nombre lo que se escriba se pasa a toLowerCase (todo minuscula).
  - Se compara si es que existe alguna otra materia con el mismo nombre. En caso de que asi sea se devuelve el error "El nombre de la materia ingresado ya existe, por favor elige otro".
  - Si se quiere editar las correlatividades, primero se generan 2 arrays a base de materiasArray:
    - Con la informacion de materiasArray[i].correlativas (array de materiasId int) generamos el "correlativasArray" (se agarra un id de materia del materiasArray[i].correlativas[j], se busca por id en materiasArray para completar la informacion); y es ordenado de la A-Z.
    - noCorrelativasArray es una copia de materiasArray a la cual se le eliminan las materias presentes en materiasArray[i].correlativas; y es ordenado de la A-Z.
  - Con los arrays (correlativasArray y noCorrelativasArray) se genera un menu interactivo para poder quitar y añadir materias (dependiendo si se encuentra o no actualmente en el materia.correlativas).

    ```
     == SELECCIONAR CORRELATIVAS ==
     0 - Cancelar
     ---------------------------------------------------
     1 - algebra-1 [ Quitar ] X
     2 - matematica-1 [ Quitar ] X
     ---------------------------------------------------
     3 - fisica-1 [ Agregar ]
     4 - matematica-2 [ Agregar ]
     ...
    ```

  - Volver a la Card de la Materia.

### 3. Eliminar Materia

- ### Muestra todas las materias registradas.

  - Lee `../bin/materias-length.dat` el cual contiene un entero (`int`).
  - Reservar memoria para `materiasArray` (materiasLength \* sizeof(materia_t)).
  - Lee `../bin/materias.dat` cuya estructura es `materia_archivo_t`.
  - Guardar los datos de `materias.dat` en `materiasArray`.
  - Ordenar las materias de la A-Z.
  - Iterar en `materiasArray` para mostrar el listado de materias junto con su index + 1, de forma tal que `index + 1` - `NombreDeMateria`.

  ```
  == ELIMINAR MATERIA ==
  0 - Volver
  ---------------------------------------------------
  1 - algebra-1
  2 - fisica-1
  3 - introduccion a la ingenieria
  4 - matematica-1
  ...
  ```

- ### Permite seleccionar una materia a eliminar.

  - Se accede a los datos de la materia seleccionada haciendo `materiasArray[numeroIngresado - 1]`, dado a que numeroIngresado es el `index + 1`.
  - Los datos se envian a otra funcion que permite eliminarla.
  - Dicha funcion primero tiene un mensaje de confirmacion "Seguro que quiere eliminar ${Materia}? (S/N)" de presionar "N" se regresa al listado de materias, si se presiona "S" se continua con la eliminacion.
  - Eliminar la materiaId de aquellas materias que la tienen de correlativa: { ..., correlativas: [ _materiaId_, otraMateriaId, ... ] }
  - Eliminar materia del materiasArray.
  - Guardar el array editado en materias.dat y a materias-length.dat restarle 1 (-1).
  - Una vez actualizado el materias.dat se vuelve al listado de materias para eliminar (notece que ya no esta presente la materia eliminada).

### 0. Salir

- Cierra la aplicación.
  - Mostrar confirmacion de salida "Esta seguro que desea salir? (S/N)"
  - Si introduce "N" devolver al menú principal.
  - Si introduce "S" cerrar app.
