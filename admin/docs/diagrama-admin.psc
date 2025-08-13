SubProceso EditarMateria
    // BLOQUE: Mostrar lista de materias
    // BLOQUE: Seleccionar materia por índice	
	
	// BLOQUE: Reservar espacio para correlativasArray
	// BLOQUE: Iterar en materias.correlativas y buscar la informacion completa de la materia
	// BLOQUE: Guardar la informacion encontrada en el correlativasArray
	
	// BLOQUE: Reservar espacio para noCorrelativasArray
	// BLOQUE: Iterar en materiasArray y hacer una copia total en noCorrelativasArray menos de la materia principal (dado a que no puede ser correlativa de si misma)
	// BLOQUE: Sacar de noCorrelativasArray las materias que se encuentran en materias.correlativas
	
	Definir opcion Como Entero
	
	Repetir
		// Información de la materia seleccionada de ejemplo
		Mostrar "== MATERIA fisica-1 =="
		Mostrar "id: 3"
		Mostrar "1 - nombre: fisica-1"
		// BLOQUE: Iterar en materia.correlativas (array de materiaId) y extraer el nombre de la materia desde el materiasArray
		Mostrar "2 - correlativas: matematica-1; algebra-1"
		Mostrar "3 - Confirmar"
		Mostrar "0 - Cancelar"
		
		Leer opcion
		
		Segun opcion Hacer
			1:
				Definir nuevoNombre Como Caracter
				Definir nuevoNombreYaExiste Como Entero
				
				Mostrar "Nuevo nombre para Fisica-1:"
				Leer nuevoNombre
				// BLOQUE: Validar que no exista otra materia con el mismo nombre iterando sobre el materiasArray, si existe cambiar nuevoNombreYaExiste a 1
				Si nuevoNombreYaExiste Entonces
					// BLOQUE: 	Error: El nombre de la materia ingresado ya existe, por favor elige otro.
					// BLOQUE: 	Regresar a editar materia
				FinSi
				// BLOQUE: Actualizar materia.nombreLength con la nueva cantidad de caracteres
				// BLOQUE: Pedir espacio en materia.nombre para la cantidad de caracteres nuevos
				// BLOQUE: Copiar desde nuevoNombre a materia.nombre
			2: 
				Definir materiaSeleccionada Como Entero
				
				Mostrar "== SELECCIONAR CORRELATIVAS =="
				Mostrar "0 - cancelar"
				// BLOQUE: Mostrar las materias de correlativasArray junto con [ Quitar ] X
				Mostrar "1 - Matematica-1 [ Quitar ] X"
				Mostrar "2 - Algebra-1 [ Quitar ] X"
				// BLOQUE: Mostrar las materias de noCorrelativasArray junto con [ Agregar ] 
				Mostrar "3 - Matematica-2 [ Agregar ] "
				Mostrar "..."
				
				Leer materiaSeleccionada
			3:
				// BLOQUE: Actualizar archivo de materias.dat con la nueva informacion
			0:
				// BLOQUE: Regresar al listado de materias
			De Otro Modo:
				// BLOQUE: Error opcion no valida, intente de nuevo.
		FinSegun
	Hasta Que opcion = 0 
FinSubProceso

SubProceso CrearMateria
    // BLOQUE: Reservar memoria para nueva materia
    // BLOQUE: Leer último ID disponible (contador-id.dat)
    // BLOQUE: Ingresar nombre y pasarlo a minúsculas
	
	// BLOQUE: Reservar espacio para correlativasArray
	// BLOQUE: Iterar en materias.correlativas y buscar la informacion completa de la materia
	// BLOQUE: Guardar la informacion encontrada en el correlativasArray
	
	// BLOQUE: Reservar espacio para noCorrelativasArray
	// BLOQUE: Iterar en materiasArray y hacer una copia total en noCorrelativasArray menos de la materia principal (dado a que no puede ser correlativa de si misma)
	// BLOQUE: Sacar de noCorrelativasArray las materias que se encuentran en materias.correlativas
	
	Definir opcion Como Entero
	
	Repetir
		// Información de la materia seleccionada de ejemplo
		Mostrar "== CREAR MATERIA =="
		Mostrar "id: 7"
		Mostrar "1 - nombre: --"
		// BLOQUE: Iterar en materia.correlativas (array de materiaId) y extraer el nombre de la materia desde el materiasArray
		Mostrar "2 - correlativas: --"
		Mostrar "3 - Confirmar"
		Mostrar "0 - Cancelar"
		
		Leer opcion
		
		Segun opcion Hacer
			1:
				Definir nuevoNombre Como Caracter
				Definir nuevoNombreYaExiste Como Entero
				
				Mostrar "Nuevo nombre para fisica-1:"
				Leer nuevoNombre
				// BLOQUE: Validar que no exista otra materia con el mismo nombre iterando sobre el materiasArray, si existe cambiar nuevoNombreYaExiste a 1
				Si nuevoNombreYaExiste Entonces
					// BLOQUE: 	Error: El nombre de la materia ingresado ya existe, por favor elige otro.
					// BLOQUE: 	Regresar a editar materia
				FinSi
				// BLOQUE: Actualizar materia.nombreLength con la nueva cantidad de caracteres
				// BLOQUE: Pedir espacio en materia.nombre para la cantidad de caracteres nuevos
				// BLOQUE: Copiar desde nuevoNombre a materia.nombre
			2: 
				Definir materiaSeleccionada Como Entero
				
				Mostrar "== SELECCIONAR CORRELATIVAS =="
				Mostrar "0 - cancelar"
				// BLOQUE: Mostrar las materias de correlativasArray junto con [ Quitar ] X
				Mostrar "1 - Matematica-1 [ Quitar ] X"
				Mostrar "2 - Algebra-1 [ Quitar ] X"
				// BLOQUE: Mostrar las materias de noCorrelativasArray junto con [ Agregar ] 
				Mostrar "3 - Matematica-2 [ Agregar ] "
				Mostrar "..."
				
				Leer materiaSeleccionada
			3:
				// BLOQUE: Actualizar archivo de materias.dat con la nueva informacion
			0:
				// BLOQUE: Regresar al listado de materias
			De Otro Modo:
				// BLOQUE: Error opcion no valida, intente de nuevo.
		FinSegun
	Hasta Que opcion = 0 
FinSubProceso

SubProceso EliminarMateria
    // BLOQUE: Mostrar lista de materias
    // BLOQUE: Seleccionar materia por índice
    // BLOQUE: Confirmar eliminación
    // BLOQUE: Eliminar materia y referencias en correlativas del materiasArray
    // BLOQUE: Actualizar materias-length.dat restandole 1
	// BLOQUE: Actualizar materias.dat con la informacion del materiasArray
FinSubProceso

Proceso AdminMaterias
    // BLOQUE: Leer archivo de configuración (menu-principal.txt)
    // BLOQUE: Reservar memoria para opciones del menú
	
    Definir opcion Como Entero
    Definir confirmacion Como Caracter
	
    Repetir
        Mostrar "== ADMINISTRAR MATERIAS =="
        Mostrar "1 - Editar Materias"
        Mostrar "2 - Crear Materia"
        Mostrar "3 - Eliminar Materia"
        Mostrar "0 - Salir"
        Leer opcion
		
        Segun opcion Hacer
            1:
				// BLOQUE: Leer cuantas materias hay desde archivo binario seguimiento-de-materias/bin/materias-length.dat
				// BLOQUE: Reservar espacio para dicha cantidad de materias
                // BLOQUE: Leer materias desde archivo binario seguimiento-de-materias/bin/materias.dat y guardarlas en el espacio reservado
                // BLOQUE: Ordenar materias alfabéticamente
                EditarMateria()
            2:
				// BLOQUE: Leer cuantas materias hay desde archivo binario seguimiento-de-materias/bin/materias-length.dat
				// BLOQUE: Reservar espacio para dicha cantidad de materias
                // BLOQUE: Leer materias desde archivo binario seguimiento-de-materias/bin/materias.dat y guardarlas en el espacio reservado
                // BLOQUE: Ordenar materias alfabéticamente
                CrearMateria()
            3:
				// BLOQUE: Leer cuantas materias hay desde archivo binario seguimiento-de-materias/bin/materias-length.dat
				// BLOQUE: Reservar espacio para dicha cantidad de materias
                // BLOQUE: Leer materias desde archivo binario seguimiento-de-materias/bin/materias.dat y guardarlas en el espacio reservado
                // BLOQUE: Ordenar materias alfabéticamente
                EliminarMateria()
            0:
                Mostrar "¿Está seguro que desea salir? (S/N)"
                Leer confirmacion
                Si confirmacion = "S" Entonces
                    Mostrar "Cerrando aplicación..."
                FinSi
            De Otro Modo:
                // BLOQUE: Opción inválida
        FinSegun
    Hasta Que opcion = 0 Y confirmacion = "S"
FinProceso

