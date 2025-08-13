SubProceso VerEditarMateria
	Definir opcion Como Entero
	
	Repetir
		// Información de la materia seleccionada de ejemplo
		Mostrar "== MATERIA fisica-1 =="
		Mostrar "id: 3"
		Mostrar "nombre: fisica-1"
		// BLOQUE: Iterar en materia.correlativas (array de materiaId) y extraer el nombre de la materia desde el materiasArray
		Mostrar "correlativas: matematica-1; algebra-1"
		Mostrar "estado: No cursada"
		Mostrar "1 - Editar estado"
		Mostrar "0 - Volver"
		Leer opcion
		
		Segun opcion Hacer
			1:
				Mostrar "== NUEVO ESTADO DE fisica-1 =="
				Mostrar "1 - no cursada"
				Mostrar "2 - en curso"
				Mostrar "3 - siguiente cuatrimestre"
				Mostrar "4 - final pendiente"
				Mostrar "5 - aprobada"
				Mostrar "0 - Cancelar"
				Leer nuevoEstado
				Si nuevoEstado = 5 Entonces
					// BLOQUE: Verificar que las correlativas hayan sido aprobadas
					Si correlativasNoAprobadas Entonces
						Mostrar "Error: La materia requiere que la correlativa ${Nombre} haya sido aprobada"
						// BLOQUE: Regresar a editar estado
					FinSi	
				FinSi
				// BLOQUE: Guardar nuevo estado en archivo binario seguimiento-de-materias/bin/${materiaId}.dat
			0: // BLOQUE: Regresar a editar estado
			De Otro Modo:
				// BLOQUE: Error opcion no valida, intente de nuevo.
		FinSegun
	Hasta Que opcion = 0 
FinSubProceso

Proceso SeguimientoMaterias
    // Inicialización de la aplicación
	
	// BLOQUE: Leer cuantas materias hay desde archivo binario seguimiento-de-materias/bin/materias-length.dat
	// BLOQUE: Reservar espacio para dicha cantidad de materias
	// BLOQUE: Leer materias desde archivo binario seguimiento-de-materias/bin/materias.dat y guardarlas en el espacio reservadp
    // BLOQUE: Verificar que existan los archivos de estado por cada materia sino crearlos
	
    // BLOQUE: Leer archivo de configuración del menú principal
    // BLOQUE: Reservar memoria para opciones del menú

	Definir opcion Como Entero
	
	Definir confirmacion Como Caracter
	
    Repetir
		Mostrar "== SEGUIMIENTO DE MATERIAS =="
        Mostrar "1 - Ver listado de materias"
        Mostrar "2 - Filtrar materias Cursables"
        Mostrar "3 - Filtrar materias En Curso"
        Mostrar "4 - Filtrar materias Siguiente Cuatrimestre"
        Mostrar "5 - Filtrar materias con Final Pendiente"
        Mostrar "6 - Filtrar materias Aprobadas"
        Mostrar "0 - Salir"
        Leer opcion
		
        Segun opcion Hacer
            1:
				// BLOQUE: Leer cuantas materias hay desde archivo binario seguimiento-de-materias/bin/materias-length.dat
				// BLOQUE: Reservar espacio para dicha cantidad de materias
                // BLOQUE: Leer materias desde archivo binario seguimiento-de-materias/bin/materias.dat y guardarlas en el espacio reservado
                // BLOQUE: Ordenar materias alfabéticamente
                Mostrar "Listado de materias"
                // Seleccionar una materia de la lista y usarla en el submenú para ver información y editar estado
				VerEditarMateria()
				
            2:
				// BLOQUE: Leer cuantas materias hay desde archivo binario seguimiento-de-materias/bin/materias-length.dat
				// BLOQUE: Reservar espacio para dicha cantidad de materias
                // BLOQUE: Leer materias desde archivo binario seguimiento-de-materias/bin/materias.dat y guardarlas en el espacio reservado
                // BLOQUE: Filtrar materias las materias con estado No Cursada (1)
				// BLOQUE: Entre las materias No Cursadas revisar que las correlatividades de cada materia esten con Final Pendiente (4) o Aprobadas (5)
				// BLOQUE: Ordenar materias alfabéticamente
                Mostrar "Materias cursables"
				// Seleccionar una materia de la lista y usarla en el submenú para ver información y editar estado
				VerEditarMateria()
				
            3, 4, 5, 6:
				// BLOQUE: Leer cuantas materias hay desde archivo binario seguimiento-de-materias/bin/materias-length.dat
				// BLOQUE: Reservar espacio para dicha cantidad de materias
                // BLOQUE: Leer materias desde archivo binario seguimiento-de-materias/bin/materias.dat y guardarlas en el espacio reservado
                // BLOQUE: Filtrar materias según estado
				// BLOQUE: Ordenar materias alfabéticamente
                Mostrar "Materias filtradas"
				// Seleccionar una materia de la lista y usarla en el submenú para ver información y editar estado
                VerEditarMateria()
				
            0:
                Mostrar "¿Está seguro que desea salir? (S/N)"
                Leer confirmacion
                Si confirmacion = "S" Entonces
                    Mostrar "Cerrando aplicación..."
                FinSi
			De Otro Modo:
				// BLOQUE: Error opcion no valida, intente de nuevo.
        FinSegun
    Hasta Que opcion = 0 Y confirmacion = "S"
FinProceso
