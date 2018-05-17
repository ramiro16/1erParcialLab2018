#define TamU 6
#define TamA 13

#define OCUPADO 1
#define LIBRE 0

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4


typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char tarjeta[20];
    char direccion[20];

    int estado;

}eUsuario;

typedef struct
{
    char patente[30];
    int marca;
    int idAuto;
    int id;

    int estado;

}eAuto;

/** \brief Ordena los automoviles por patente
 *
 * \param array de tipo eAuto
 * \param variable de control de iteraciones
 * \return funcion void, sin retorno
 *
 */
void ordenarxPatente(eAuto[],int);

/** \brief Muestra usuarios en array eUsuario y sus datos
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones
 * \return funcion void, sin retorno
 *
 */
void mostrarUsuarios(eUsuario[],int);

/** \brief Muestra automoviles en array eAuto y sus datos
 *
 * \param array de tipo eAuto
 * \param variable de control de iteraciones
 * \return funcion void, sin retorno
 *
 */
void mostrarAutos(eAuto[],int);

/** \brief Muestra los autos estacionados por usuario
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones de eUsuario
 * \param array de tipo eAuto
 * \param variable de control de iteraciones de eAuto
 * \return funcion void, sin retorno
 *
 */
void mostrarAutosxUsuario(eUsuario[],int,eAuto[],int);

/** \brief Muestra los usuarios que estacionaron autos marca AUDI
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones para eUsuario
 * \param array de tipo eAuto
 * \param variable de control de iteraciones para eAuto
 * \return funcion void, sin retorno
 *
 */
void mostrarUsuariosAudi(eUsuario[],int,eAuto[],int);

/** \brief Muestra cada auto estacionado con el nombre de su propietario
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones de eUsuario
 * \param array de tipo eAuto
 * \param variable de control de iteraciones de eAuto
 * \return
 *
 */
void mostrarEstacionadoConPropietario(eUsuario[],int,eAuto[],int);

/** \brief Hardcodea datos en el array
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones
 * \return funcion void, sin retorno
 *
 */
void hardcodearUsuarios(eUsuario[],int);

/** \brief Hardcodea datos en el array
 *
 * \param array de tipo eAuto
 * \param variable de control de iteraciones
 * \return funcion void, sin retorno
 *
 */
void hardcodearAutos(eAuto[],int);

/** \brief Inicializa las posiciones del array en LIBRE
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones
 * \return retorna -1 si no logra inicializar el array
 *         retorna 0 si logra inicializar el array
 */
int inicializarUsuarios(eUsuario[],int);


/** \brief Inicializa las posiciones del array en LIBRE
 *
 * \param array de tipo eAuto
 * \param variablde control de iteraciones
 * \return funcion void, sin retorno
 *
 */
void inicializarAutos(eAuto[],int);

/** \brief Da de alta un usuario y toma sus datos
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones
 * \return -1 si el indice devuelto es menor a 0
 *          0 si logra cargar los datos
 */
int eUsuario_alta(eUsuario[],int);

/** \brief Permite modificar dato en la estructura eUsuario
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones
 * \return -1 si el la variable de control de iteraciones es menor a 0 y si el array es nulo
 *         -2 si toma el id pero no encuentra usuario con el id correspondiente
 *          0 si logra modificar los datos
 */
int eUsuario_modificacion(eUsuario[],int);

/** \brief Permite dar de baja logica a un usuario del array eUsuario
 *
 * \param array de tipo eUsuario
 * \param variable de control de iteraciones
 * \return -1 si cancela la baja
 *          0 si la baja es exitosa
 */
int eUsuario_baja(eUsuario[],int);

/** \brief Da de alta un auto y toma sus datos
 *
 * \param array de tipo eAuto
 * \param variable de control de iteraciones
 * \return -1 Si no logra asignar auto ingresante a un usuario
 *          0 Si logra dar de alta el auto
 */
int eAuto_alta(eAuto[],int,eUsuario[],int);

/** \brief Da de baja un auto y cambia el estado del array a LIBRE
 *
 * \param array de tipo eAuto
 * \param int variable de control de iteraciones
 * \param array de tipo eUsuario
 * \param int variablede control de iteraciones
 * \return -1 si no encuentra el id de auto ingresado o si se cancela la baja
 *          0 si el egreso se lleva a cabo
 */
int finalizarAuto(eUsuario[],int,eAuto[],int); //eAuto_baja;

/** \brief Otorga el indice donde se puedan guardar datos si es que hay.
 *
 * \param array de tipo eUsuario
 * \param int variable de control de iteraciones
 * \return -1 si el limite es menor a 0 y si el array es nulo
 *         -2 si no hay lugar para guardar datos
 *          Indice donde puede guardar datos
 */
int eUsuario_buscarLugarLibre(eUsuario[],int);

/** \brief Genera un id autoincremental
 *
 * \param array de tipo eUsuario
 * \param int variable de control de iteraciones
 * \return 0 si el limite de iteraciones es menor a 0 y si el array es nulo
 *         retorno que sera indice+1 que sera el id generado
 */
int eUsuario_siguienteId(eUsuario[],int);

/** \brief Busca si hay lugar libre en el array eAuto
 *
 * \param array de tipo eAuto
 * \param variable de control de iteraciones
 * \return -1 si el listado es nulo y si la variable de control de iteraciones es menor a 0
 *         -2 si no hay lugar en el array
 *          si hay lugar retorna el indice donde hay lugar.
 */
int eAuto_buscarLugarLibre(eAuto[],int);

/** \brief Genera un id para auto de manera autoincremental
 *
 * \param array de tipo eAuto
 * \param variable de control de iteraciones
 * \return el id que se genera
 *
 */
int eAuto_siguienteId(eAuto[],int);

/** \brief Calcula la recaudacion total de dinero
 *
 * \param array de tipo eAuto
 * \param int variable de control de iteraciones
 * \return devuelve un int que sera la cantidad de dinero recaudado
 *
 */
int recuadacionTotal(eAuto[],int);

/** \brief Calcula la recaudacion total de dinero por marca de auto
 *
 * \param array de tipo eAuto
 * \param int variable de control de iteraciones
 * \return funcion void, no devuelve nada
 *
 */
void recaudacionTotalxMarca(eAuto[],int);
