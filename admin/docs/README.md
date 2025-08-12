## 🧑‍💻 Menú de la Aplicación del ADMIN

Al ejecutar `seguimiento-de-materias.exe`, primero se lee el archivo `admin/config/menu-principal.txt` para luego poder mostrar el siguiente menú:

```
     == ADMINISTRAR MATERIAS ==
     1 - Editar Materias
     2 - Crear Materia
     3 - Eliminar Materias
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
  1 - Algebra-1
  2 - Fisica-1
  3 - Introduccion a la Ingenieria
  4 - Matematica-1
  ...
  ```

- ### Permite seleccionar una materia y ver mas de su informacion.

  - Se accede a los datos de la materia seleccionada haciendo `materiasArray[numeroIngresado - 1]`, dado a que numeroIngresado es el `index + 1`.
  - Los datos se envian a otra funcion que obtiene el estado de la materia ingresando a `bin/${materiaId}.dat`.
  - Guardar dicho estado en `materiasArray[index].estado`.
  - Mostrar en pantalla todos los datos.

    ```
    == MATERIA Fisica-1 ==
    id: 4
    1 - nombre: Fisica-1
    2 - correlativas: Matematica-1, Algebra-1
    ---------------------------------------------------
    3 - Confirmar
    0 - Cancelar
    ```

- ### Permite editar el estado personal de la materia seleccionada.
  - Se muestra en pantalla las opciones pre-establecidas de cada uno de los 5 estados.
  - Si el estado seleccionado es 5 (Aprobado), primero checkear que sus correlatividades hayan sido Aprobadas (con `bin/${materiaId}.dat` = 5). De no haber sido aprobada se devuelve el `Error` "La materia requiere que la correlativa ${nombre} haya sido aprobada". Devolver a la seleccion de estado.
  - Al seleccionar uno se acutualiza el archivo `bin/${materiaId}.dat` con el nuevo valor (`int`) seleccionado.
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
  - Volver a la Card de la Materia.

### 0. Salir

- Cierra la aplicación.
  - Mostrar confirmacion de salida "Esta seguro que desea salir? (S/N)"
  - Si introduce "N" devolver al menú principal.
  - Si introduce "S" cerrar app.
