typedef struct
{
    int id;
    int cuil;
    char nombre[30];
    char apellido[30];
}cliente;

/** \brief inicializa las ids de cliente en -1
 *
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Inicializarcliente(cliente* listcliente, int tam);

/** \brief busca un cliente por la id que se le pase por parametros
 *
 * \param listcliente cliente*
 * \param tam int
 * \param id int
 * \return int retorna -1 en caso de no existir y retorna cualquier otro numero en caso de existir
 *
 */
int GetclienteById(cliente* listcliente, int tam,int id);

/** \brief printea un cliente
 *
 * \param cliente cliente
 * \return void
 *
 */
void Mostrarcliente(cliente cliente);

/** \brief muestra el listado de clientes
 *
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Listacliente(cliente* listcliente, int tam);

/** \brief da de alta un cliente
 *
 * \param listcliente cliente*
 * \param tam int
 * \param id int*
 * \return void
 *
 */
void Altacliente(cliente* listcliente, int tam, int* id);

/** \brief elimina un cliente y a su vez tambien elimina los prestamos que estan asociados a su id
 *
 * \param listcliente cliente*
 * \param tam int
 * \param listprestamos prestamos*
 * \param tamP int
 * \return void
 *
 */
void Eliminarcliente(cliente* listcliente, int tam, prestamos* listprestamos, int tamP);

/** \brief modifica un cliente (nombre,apellido,cuil)
 *
 * \param listcliente cliente*
 * \param tam int
 * \return void
 *
 */
void Modificarcliente(cliente* listcliente, int tam);

/** \brief imprime un listado de clientes junto a la cantidad de prestamos activos
 *
 * \param listcliente cliente*
 * \param tam int
 * \param listprestamos prestamos*
 * \param tamP int
 * \return void
 *
 */
void imprimirClientes(cliente* listcliente, int tam, prestamos* listprestamos, int tamP);
