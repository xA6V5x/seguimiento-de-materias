# 📚 Seguimiento de Materias

Proyecto en lenguaje C que permite la **gestión y el seguimiento de materias** en una carrera universitaria. El sistema se divide en dos aplicaciones principales:

- `admin-materias.exe`: administración de las materias y sus correlatividades.
- `seguimiento-de-materias.exe`: permite al alumno marcar el estado de las materias para organizar su cursada.

## 🧩 Estructura del Proyecto

```
seguimiento-de-materias/
├── admin/ # Subproyecto para administración de materias
├── cli/ # Subproyecto dirigido al alumno
├── bin/ # Carpeta compartida de datos (materias.dat y materias-length.dat)
└── README.md # Este archivo
```

### 📂 `bin/` (compartida)

Contiene los datos principales que ambas aplicaciones utilizan:

- `materias-length.dat`: cantidad de materias almacenadas.
  - int cantidadDeMaterias
- ` materias.dat`: información binaria de las materias.
  - int id
  - int nombreLength
  - char nombre
  - int correlativasLength
  - int \*correlativas (contiene el ID de materias)

## 🚀 Ejecución

El proyecto está pensado para ejecutarse desde **Visual Studio**, utilizando sus tareas (`Tasks`) para compilar y ejecutar:

1. Abrir Visual Studio.
2. Abrir el subproyecto deseado (`admin/` o `cli/`).
3. Ejecutar la task correspondiente para compilar y correr.

## 🔧 Flujo de Uso

### 1. Administrar materias

1. Ejecutar `admin-materias.exe` desde `seguimiento-de-materias/admin/admin-materias.exe`.
2. El menú permite:
   ```
   == ADMINISTRAR MATERIAS ==
   1 - Editar Materias
   2 - Crear Materia
   3 - Eliminar Materias
   --------------------------
   0 - Salir
   ```
3. Agregar materias nuevas, editar o eliminar las existentes. Cada materia puede tener correlatividades (otras materias como requisitos).
4. La información se guarda automáticamente en `seguimiento-de-materias/bin`.

### 2. Seguimiento personal del alumno

1. Ejecutar `seguimiento-de-materias.exe` desde `seguimiento-de-materias/cli/seguimiento-de-materias.exe`.
2. Menú principal:
   ```
   == SEGUIMIENTO DE MATERIAS ==
   1 - Ver listado de materias
   2 - Filtrar materias Cursables
   3 - Filtrar materias En Curso
   4 - Filtrar materias Siguiente Cuatri
   5 - Filtrar materias con Final Pendiente
   6 - Filtrar materias Aprobadas
   ----------------------------------------
   0 - Salir
   ```
3. Se pueden asignar estados personalizados a las materias:
   - 1: No cursada
   - 2: En curso
   - 3: Siguiente cuatrimestre
   - 4: Final pendiente
   - 5: Aprobada
4. La app guarda estos estados en archivos individuales por materia en `cli/bin/` utilzados posteriormente para los filtros.

## 🧱 Lenguaje y dependencias

- Lenguaje: **C estándar**
- No se utilizan librerías externas.

---

Para más detalles, ver:

- [`admin/README`](admin/README)
- [`cli/README`](cli/README)
