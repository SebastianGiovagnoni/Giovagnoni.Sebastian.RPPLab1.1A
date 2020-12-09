typedef struct
{
  int id;
  int idcliente;
  int importe;
  int cuotas;
  char estado[30];
}prestamos;

/** \brief inicializa las ids de los prestamos en -1
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \return void
 *
 */
void Inicializarprestamos(prestamos* listprestamos, int tam);

/** \brief busca un prestamo por la id que se le pase por parametros
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param id int
 * \return int retorna -1 en caso de no existir y retorna cualquier otro numero en caso de existir
 *
 */
int GetprestamosById(prestamos* listprestamos, int tam,int id);

/** \brief printea un prestamo
 *
 * \param prestamos prestamos
 * \return void
 *
 */
void Mostrarprestamos(prestamos prestamos);

/** \brief muestra la lista de todos los prestamos
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \return void
 *
 */
void Listaprestamos(prestamos* listprestamos, int tam);

/** \brief elimina todos los prestamos que tengan el id de cliente que se pase por parametro
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param idCliente int
 * \return void
 *
 */
void eliminarTodos(prestamos* listprestamos,int tam, int idCliente);

/** \brief lista los prestamos que tengan el id de cliente que se pase por parametro
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param idCliente int
 * \return void
 *
 */
void listarPorId(prestamos* listprestamos,int tam, int idCliente);

/** \brief muestra todos los prestamos que tengan como estado "SALDADO" y la misma id de cliente que se pase por parametro
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \return void
 *
 */
void ListaprestamosSaldados(prestamos* listprestamos, int tam);

/** \brief muestra todos los prestamos que tengan como estado "ACTIVO" y la misma id de cliente que se pase por parametro
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \return void
 *
 */
void ListaprestamosActivos(prestamos* listprestamos, int tam);

/** \brief retorna la cantidad de prestamos que tengan como estado "ACTIVO" y la misma id de cliente que se pase por parametro
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param idCliente int
 * \return int
 *
 */
int cantidadDePrestamosActivos(prestamos* listprestamos, int tam, int idCliente);

/** \brief retorna la cantidad de prestamos que tengan como estado "SALDADO" y la misma id de cliente que se pase por parametro
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param idCliente int
 * \return int
 *
 */
int cantidadDePrestamosSaldados(prestamos* listprestamos, int tam, int idCliente);

/** \brief retorna la cantidad de prestamos que tenga la misma id de cliente que se pase por parametro
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param idCliente int
 * \return int
 *
 */
int cantidadDePrestamos(prestamos* listprestamos, int tam, int idCliente);


