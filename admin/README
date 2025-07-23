# 🛠 Admin - Gestión de Materias

Este subproyecto forma parte del sistema **Seguimiento de Materias**. Su propósito es permitir la administración completa de las materias disponibles en la carrera: creación, edición, eliminación y configuración de correlatividades.

---

## 📌 ¿Qué hace este módulo?

`admin-materias.exe` es una aplicación de línea de comandos que permite gestionar las materias que luego el alumno podrá consultar desde su propia interfaz (`cli/seguimiento-de-materias.exe`).

Desde esta herramienta podés:

-    Agregar materias nuevas
-    Editar nombre o correlatividades de materias existentes
-    Eliminar materias
-    Guardar todo en formato binario para que luego lo use la interfaz del alumno

---

## 📁 Estructura de Carpetas

```
bin/ # Binario donde se crean/leen/editan/eliminan las materias (materias.dat y materias-length.dat)

admin/
├── bin/ # Binario contador de id (contador-id.dat es un int)
├── docs/ # Documentación técnica
├── headers/ # Archivos .h (estructuras y funciones)
├── res/ # Recursos (logo app)
├── src/ # Código fuente en C
└── admin-materias.exe # Ejecutable generado (administrador de materias)
```

---

## 📂 Archivos generados

Este módulo escribe los datos en la carpeta principal `seguimiento-de-materias/bin/` para que puedan ser consumidos por el sistema del alumno (`cli/`):

-    `materias-length.dat`: contiene un entero (`int`) que representa la cantidad total de materias creadas.
-    `materias.dat`: archivo binario que almacena la lista de materias. Cada materia tiene la siguiente estructura:

```c
typedef struct {
    int id;                     // ID único de la materia
    int nombreLength;          // Largo del nombre
    char nombre[nombreLength]; // Nombre de la materia
    int correlativasLength;    // Cantidad de correlativas
    int correlativas[correlativasLength]; // IDs de materias correlativas
} Materia;
```

---

## 🚀 ¿Cómo se ejecuta?

Este proyecto está pensado para ser compilado y ejecutado con **Visual Studio** usando tareas (Tasks).

### ▶️ Pasos

1. Abrí Visual Studio.
2. Abrí el subproyecto `admin/`.
3. Ejecutá la task configurada para compilar y correr `admin-materias.exe`.

> El ejecutable generado estará en `seguimiento-de-materias/admin/admin-materias.exe`.

---

## 🧑‍💻 Menú de la Aplicación

Al ejecutar `admin-materias.exe`, se muestra el siguiente menú:

```
== ADMINISTRAR MATERIAS ==
1 - Editar Materias
2 - Agregar Materias
3 - Eliminar Materias
--------------------------
0 - Salir
```

### 📘 Opciones del menú:

#### 1. Editar Materias

-    Permite modificar el nombre de una materia existente.
-    Permite agregar o quitar correlatividades.

#### 2. Agregar Materias

-    Ingresás un nombre y una lista de correlativas (opcional).
-    Se asigna automáticamente un ID a la nueva materia.

#### 3. Eliminar Materias

-    Eliminás la materia seleccionada.
-    También se eliminan todas las referencias a ella como correlativa en otras materias.

#### 0. Salir

-    Cierra la aplicación.

---

## 🔗 Dependencia de Datos

Este módulo **lee, crea, actualiza y elimina las materias** desde:

```
seguimiento-de-materias/bin/
├── materias-length.dat # Cantidad de materias
└── materias.dat # Datos binarios de materias
```

Este módulo trabaja directamente sobre los archivos` materias.dat` y `materias-length.dat` ubicados en `seguimiento-de-materias/bin/`.
Estos archivos son leídos por el subproyecto CLI, que es la herramienta usada por los alumnos.

---

## 📎 Relación con otros módulos

| Módulo | Función                                                          |
| ------ | ---------------------------------------------------------------- |
| `cli/` | Consume los datos creados por este módulo para mostrar al alumno |
| `bin/` | Contiene los archivos de datos generados por este módulo         |
