#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param Lista el array se pasa como parametro.
 * @param Variable control de iteraciones.
 * @return El primer indice disponible.-1 si no logra encontrar posicion libre
 */
int obtenerEspacioLibre(EPersona*,int tam);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param Lista el array se pasa como parametro.
 * @param Dni el dni a ser buscado en el array.
 * @return El indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona*,int);


/** \brief Ordena los datos de las personas por el nombre, alfabaticamente de la A a la Z.
 *
 * \param Array persona como parametro
 * \param Variable de contro de cantidad de iteraciones.
 * \return Retorna void.
 *
 */
void ordenarPersonas(EPersona*,int);

/** \brief Baja logica de datos de persona.
 *
 * \param Array persona como parametro.
 * \param Variable de contro de cantidad de iteraciones.
 * \return Retorna void.
 *
 */
int borrarPersona(EPersona*,int);

/** \brief Ingresa datos de la persona.
 *
 * \param Array persona como parametro.
 * \param Variable de control de cantidad de iteraciones.
 * \return Retorna -1 si logra cargar datos, 0 si logra cargar.
 *
 */
int altaPersona(EPersona*, int);

/** \brief Inicializa todas las posiciones del array en 0.
 *
 * \param Array persona como parametro.
 * \param Variable de control de cantidad de iteraciones.
 * \return Retorna void.
 *
 */

void inicializarPersona(EPersona*,int);

/** \brief Muestra los datos de todas las personas por pantalla.
 *
 * \param Array persona como parametro.
 * \param Variable de control de cantidad de iteraciones.
 * \return Retorna void.
 *
 */

void mostrarPersona(EPersona[],int);

/** \brief Muestra por pantalla un grafico con la cantidad de personas segun parametros establecidos.
 *
 * \param Primer contador de cantidad de datos(Menores de 18).
 * \param Segundo contador de cantidad de datos(Entre 18 y 35).
 * \param Tercer contador de cantidad de datos(Mayores de 35).
 * \return Retorna un void.
 *
 */

void graficoEdades(int,int,int);

void jarcodear(EPersona*);

#endif // FUNCIONES_H_INCLUDED
