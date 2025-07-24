# 👤 CLI - Seguimiento Personal del Alumno

Este subproyecto forma parte del sistema **Seguimiento de Materias**. Su propósito es brindar una herramienta al alumno para organizar y planificar la cursada de sus materias de forma personalizada.

---

## 📌 ¿Qué hace este módulo?

`seguimiento-de-materias.exe` es una aplicación de línea de comandos que permite al alumno:

-    Visualizar todas las materias disponibles.
-    Asignar un **estado personal** a cada materia.
-    Aplicar filtros para facilitar la organización y busqueda de las materias.

> ⚠️ Este módulo **no modifica las materias**, solamente las **lee**.

---

## 🔗 Dependencia de Datos

Este módulo **lee las materias** desde:

```
seguimiento-de-materias/
└── bin/
    ├── materias-length.dat # Cantidad de materias
    └── materias.dat # Datos binarios de materias
```

-    `materias-length.dat`: contiene un entero (`int`) que representa la cantidad total de materias.
-    ` materias.dat`: archivo binario que almacena la lista de materias. Cada materia tiene la siguiente estructura:

     ```c
     typedef struct {
     int id; // ID único de la materia
     int nombreLength; // Largo del nombre
     char nombre[nombreLength]; // Nombre de la materia
     int correlativasLength; // Cantidad de correlativas
     int correlativas[correlativasLength]; // IDs de materias correlativas
     } MateriaArchivo;
     ```

Estos archivos son generados por el subproyecto `admin/`. Si no existen, la aplicación no podrá mostrar materias.

---

## 📁 Estructura de Carpetas

```
bin/ # Datos principales de lectura (materias.dat y materias-length.dat)

cli/
├── bin/ # Cache de estado por materia (${materiaId}.dat es un int)
├── docs/ # Documentación técnica
├── headers/ # Archivos .h (declaraciones de funciones)
├── res/ # Recursos (logo app)
├── src/ # Código fuente en C
└── seguimiento-de-materias.exe # Ejecutable generado (interfaz alumno)
```

---

## 📚 Estados de materia

Cada materia puede tener un estado asignado por el alumno. Estos estados son:

| Estado                 | Valor |
| ---------------------- | ----- |
| No cursada             | 1     |
| En curso               | 2     |
| Siguiente cuatrimestre | 3     |
| Final pendiente        | 4     |
| Aprobada               | 5     |

---

## 💾 Archivos de estado

Los estados asignados se guardan de forma local en archivos `${materiaId}.dat` (materiaId es un `int`) ubicados en `cli/bin/`:

```
cli/
└── bin/
    ├── ${materiaId}.dat # Estado de la materia con ID entero (int)
    ├── 1.dat # Estado de la materia con ID 1
    ├── 2.dat # Estado de la materia con ID 2
   ...
```

Cada archivo `${materiaId}.dat` contiene un entero (`int`) entre 1 y 5 que representa el estado de la materia correspondiente.

> ⚠️ Estos archivos son independientes de los datos globales de materias (ubicados en `seguimiento-de-materias/bin/`) y solo afectan la vista del alumno.

---

## 🚀 ¿Cómo se ejecuta?

Este proyecto está pensado para ser compilado y ejecutado con **Visual Studio** usando tareas (Tasks).

### ▶️ Pasos

1. Abrí Visual Studio.
2. Abrí el subproyecto `cli/`.
3. Ejecutá la task configurada para compilar y correr `seguimiento-de-materias.exe`.

> El ejecutable generado estará en `seguimiento-de-materias/cli/seguimiento-de-materias.exe`.

---

## 🧑‍💻 Menú de la Aplicación de CLI

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

### 📘 Opciones del menú:

#### 1. Ver listado de materias

-    Muestra todas las materias registradas.
-    Permite seleccionar una, ver mas de su informacion y editar su estado personal.

#### 2. Filtrar materias Cursables

-    Permite filtrar solo aquellas materias que sean Cursables. Se consideran "cursables" aquellas materias No Cursadas cuyas correlatividades ya están finalizadas o aprobadas, es decir, todas sus correlativas tienen estado 4 (Final Pendiente) o 5 (Aprobada).
-    Permite seleccionar una, ver mas de su informacion y editar su estado personal.

#### 3 a 6. Filtros por estado

-    Permiten filtrar solo aquellas materias que coincidan con un estado específico.
-    Permite seleccionar una, ver mas de su informacion y editar su estado personal.

#### 0. Salir

-    Cierra la aplicación.

---

Para detalles tecnicos, ver:

-    [`docs/README`](docs/README)
