## 🧑‍💻 Menú de la Aplicación del ADMIN

Al ejecutar `seguimiento-de-materias.exe`, primero se lee el archivo `admin/config/menu-principal.txt` para luego poder mostrar el siguiente menú:

```
     == ADMINISTRAR MATERIAS ==
     1 - Editar Materias
     2 - Agregar Materia
     3 - Eliminar Materias
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
     } materia_t;

     // Al leer los bin la informacion se maneja de esta forma para mayor comodidad
     typedef struct {
          int length; // Cantidad de materias
          materia_t *array; // Array de materias
     } materias_t;
```

## 📘 Opciones del menú:

- Abrir el archivo `cli/config/menu-principal.txt` para lectura y verificar que exista.
- Leer primero la cantidad de opciones (el primer dato int) para reservar memoria para el `opcionesArray` (sizeof(opcion_accion_t) \* opcionesLength).
- Iterar en el archivo para ir guardando los datos del `funcionId` y `textLength`.
- Reservar memoria dentro del `opcionesArray[i].text` (sizeof(char) \* textLength + 1); el +1 es para poder agragarle el `'\0'`.
- Leer y almacenar el text con `fgets(opcionesArray[i].text, textLength + 1, fp)`.
- Usar el funcionId para poder almacenar la funcion en el objeto `opcionesArray[i].funcion = funcionesArray[funcionIndex]`.
- Por ultimo, almacenar los datos en un objeto `opciones_acciones_t` para su comodo uso `{ opcionesLength, opcionesArray, };`

// Agregar informacion importante sobre el procesamiento de informacion

### 0. Salir

- Cierra la aplicación.
  - Mostrar confirmacion de salida "Esta seguro que desea salir? (S/N)"
  - Si introduce "N" devolver al menú principal.
  - Si introduce "S" cerrar app.
