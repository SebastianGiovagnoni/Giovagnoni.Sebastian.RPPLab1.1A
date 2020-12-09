
/** \brief Da de alta un prestamo
 *
 * \param listprestamos prestamos*
 * \param tamA int
 * \param id int*
 * \param listcliente cliente*
 * \param tamC int
 * \return void
 *
 */
void Altaprestamos(prestamos* listprestamos, int tamA, int* id,cliente* listcliente, int tamC);

/** \brief se cambia el estado de prestamo de activo a saldado
 *
 * \param
 * \param
 * \return
 *
 */
void saldarPrestamo (prestamos* listprestamos, int tam, cliente* listcliente, int tamC);

/** \brief se cambia el estado del prestamo de saldado a activo
 *
 * \param
 * \param
 * \return
 *
 */
void reanudarPrestamo (prestamos* listprestamos, int tam, cliente* listcliente, int tamC);

/** \brief imprime todos los prestamos junto con el cuil del cliente
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param listclientes cliente*
 * \param tamC int
 * \return void
 *
 */
void imprimirPrestamos(prestamos* listprestamos, int tam, cliente* listclientes, int tamC);

/** \brief muestra el cliente con mas prestamos activos
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param listclientes cliente*
 * \param tamC int
 * \return void
 *
 */
void informaClientesMasPrestamosActivos(prestamos* listprestamos, int tam, cliente* listclientes, int tamC);

/** \brief muestra el cliente con mas prestamos saldados
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param listclientes cliente*
 * \param tamC int
 * \return void
 *
 */
void informaClientesMasPrestamosSaldados(prestamos* listprestamos, int tam, cliente* listclientes, int tamC);

/** \brief muestra el cliente con mas prestamos
 *
 * \param listprestamos prestamos*
 * \param tam int
 * \param listclientes cliente*
 * \param tamC int
 * \return void
 *
 */
void informaClientesMasPrestamos(prestamos* listprestamos, int tam, cliente* listclientes, int tamC);

