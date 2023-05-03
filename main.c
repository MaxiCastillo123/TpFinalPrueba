#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <windows.h>

#define ESC 27

typedef struct
{
    int idCliente;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[50];
    char domicilio[45];
    char movil [12];
    int eliminado;
} stCliente;

typedef struct
{
    int id;
    int idCliente;
    int anio;
    int mes;
    int dia;
    int datosConsumidos;
    int cantidadDeDatosConsumidos;
    int baja;
} stConsumos;

stCliente cargaUnCliente();
void mostrarUnCliente(stCliente a);
stConsumos cargaUnConsumo();
void mostrarUnConsumo(stConsumos a);
void cargaArchivoCliente(char nombreArchivo[]);
void cargaArchivoConsumos(char nombreArchivo[]);
void muestraArchivoClientes(char nombreArchivo[]);
void muestraArchivoConsumos(char nombreArchivo[]);
int ultimoIdCliente(char nombreArchivo[]);
int ultimoIdConsumo(char nombreArchivo[]);
int busquedaDNI(char nombreArchivo[]);
stConsumos cargaUnConsumo2();
stConsumos cargaUnConsumoAnioActual();
stConsumos seleccionaUnaFecha();




int main()
{
    srand(time(NULL));
    stCliente clientes[50];
    int validosClientes = 0;
    /*time_t*/



    printf("\nArchivo Clientes");
    printf("\n");
    muestraArchivoClientes("prueba4.DAT");

    cargaArchivoCliente2("prueba4.DAT");
    modificacionDniCliente("prueba4.DAT");

    muestraArchivoClientes("prueba4.DAT");


    ///busquedaDNI("prueba3.DAT");
    /*
        validosClientes = arch2arreglo("CLIENTES.DAT",clientes,50,validosClientes);

        muestraArregloClientes(clientes,validosClientes);
        busquedaCliente(clientes,validosClientes);
*/
        cargaArchivoConsumos2("CONSUMOS4.DAT", "prueba4.DAT");
        printf("\nArchivo Consumos");
        muestraArchivoConsumos("CONSUMOS4.DAT");

        printf("\nLa cantidad de datos consumidos ese dia fueron de : %d", funcionAcumulador());
    return 0;
}

stCliente cargaUnCliente()
{

    stCliente a;
    system("cls");
    printf("\nDni del cliente: ");
    fflush(stdin);
    gets(a.dni);
    printf("\nNumero del cliente: ");
    fflush(stdin);
    scanf("%d", &a.nroCliente);
    printf("\nNombre del cliente: ");
    fflush(stdin);
    gets(a.nombre);
    printf("\nApellido del cliente: ");
    fflush(stdin);
    gets(a.apellido);
    printf("\nEmail del cliente: ");
    fflush(stdin);
    gets(a.email);
    printf("\nDomicilio del cliente: ");
    fflush(stdin);
    gets(a.domicilio);
    printf("\nMovil del cliente: ");
    fflush(stdin);
    gets(a.movil);
    printf("\nEl usuario se encuentra activo? (0 por si, -1 por no): ");
    fflush(stdin);
    scanf("%d", &a.eliminado);
    system("cls");

    return a;
}

void mostrarUnCliente(stCliente a)
{

    printf("ID cliente: %d", a.idCliente);
    printf("\nDatos del Cliente N %d", a.nroCliente);
    printf("\nApellido y Nombre: %s, %s", a.apellido, a.nombre);
    printf("\nDNI: %s", a.dni);
    printf("\nEmail: %s", a.email);
    printf("\nDomicilio: %s", a.domicilio);
    printf("\nMovil: %s", a.movil);
    if(a.eliminado == 0)
    {
        printf("\nActivo: Si\n");
    }
    else
    {
        printf("\nActivo: No\n");
    }
    printf("========================================\n");
}

stConsumos cargaUnConsumo()
{

    stConsumos a;
    a.anio = rand()%2022-1940 + 1940;
    printf("\nIngrese el año de consumo: ");
    scanf("%d", &a.anio);
    printf("\nIngrese el mes de consumo: ");
    scanf("%d", &a.mes);

    if(a.mes >12)
    {

        while(a.mes >12)
        {
            printf("Mes no valido, ingreselo nuevamente: ");
            scanf("%d", &a.mes);
        }
    }
    printf("\nIngrese el dia de consumo: ");
    scanf("%d", &a.dia);

    if(a.dia >29 && a.mes == 2 && (a.anio%4 == 0))
    {
        while(a.dia > 29)
        {
            printf("\nFecha invalida. Valida hasta el 29. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if(a.dia>28 && a.mes == 2 && (a.anio%4 != 0))
    {
        while(a.dia > 28)
        {
            printf("\nFecha invalida. Valida hasta el 28. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if(a.mes == 1|| a.mes == 3 || a.mes == 5|| a.mes == 7|| a.mes == 8|| a.mes == 10|| a.mes == 12 && a.dia>31)
    {
        while(a.dia > 31)
        {
            printf("\nFecha invalida. Valida hasta 31. Ingresela nuevamante: ");
            scanf("%d", &a.dia);
        }
    }
    else
    {
        while(a.dia > 30 && a.mes == 6 || a.mes == 4 || a.mes ==9 || a.mes ==11)
        {
            printf("\nFecha invalida. Valida hasta 30. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    printf("\nIngrese la cantidad de MB consumidos: ");
    scanf("%d", &a.datosConsumidos);
    printf("\nEl usuario se encuentra activo? (0 por si, -1 por no): ");
    scanf("%d", &a.baja);
    a.cantidadDeDatosConsumidos = a.cantidadDeDatosConsumidos + a.datosConsumidos;
    return a;
}

void mostrarUnConsumo(stConsumos a)
{

    printf("\nID Consumo: %d", a.id);
    printf("\nID cliente: %d", a.idCliente);
    printf("\nFecha del consumo: %d/%d/%d", a.dia,a.mes,a.anio);
    printf("\nCantidad de MB consumidos: %d", a.datosConsumidos);
    if(a.baja == 0)
    {
        printf("\nActivo: Si\n");
    }
    else
    {
        printf("\nActivo: No\n");
    }
    printf("========================================\n");

}


void cargaArchivoCliente(char nombreArchivo[])
{
    stCliente a;
    static int i = 0;
    i = ultimoIdCliente(nombreArchivo);
    char opcion = 0;
    FILE *archi = fopen(nombreArchivo, "ab");

    if(archi)
    {
        do
        {
            a = cargaUnCliente();
            i++;
            a.idCliente = i;
            fwrite(&a, sizeof(stCliente), 1, archi);
            printf("\nDesea seguir cargando clientes? ESC PARA SALIR: ");
            opcion = getch();
        }
        while(opcion != 27);

    }
    fclose(archi);
}

void cargaArchivoConsumos(char nombreArchivo[])
{
    stConsumos a;
    static int i = 0;
    i = ultimoIdConsumo(nombreArchivo);
    char opcion = 0;
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi)
    {
        do
        {
            a = cargaUnConsumo();
            i++;
            a.id = i;
            fwrite(&a,sizeof(stConsumos),1,archi);
            printf("\nDesea seguir cargando consumos? ESC PARA SALIR: ");
            opcion = getch();
        }
        while(opcion != 27);
    }
    fclose(archi);
}

void muestraArchivoClientes(char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stCliente a;
    if(archi)
    {
        while(fread(&a, sizeof(stCliente),1,archi)>0)
        {
            mostrarUnCliente(a);
        }
    }
    fclose(archi);
}

void muestraArchivoConsumos(char nombreArchivo[])
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stConsumos a;
    if(archi)
    {
        while(fread(&a,sizeof(stConsumos),1,archi)>0)
        {
            mostrarUnConsumo(a);
        }
    }
    fclose(archi);
}


int ultimoIdCliente(char nombreArchivo[])
{
    int id = 0;
    stCliente e;
    FILE *arch = fopen(nombreArchivo, "rb");
    if(arch)
    {
        fseek(arch, -1*sizeof(stCliente), SEEK_END);
        if(fread(&e, sizeof(stCliente), 1, arch)>0)
        {
            id = e.idCliente;
        }
        fclose(arch);
    }

    return id;
}

int ultimoIdConsumo(char nombreArchivo[])
{
    int id = 0;
    stConsumos e;
    FILE *arch = fopen(nombreArchivo, "rb");
    if(arch)
    {
        fseek(arch, -1*sizeof(stConsumos), SEEK_END);
        if(fread(&e, sizeof(stConsumos), 1, arch)>0)
        {
            id = e.id;
        }
        fclose(arch);
    }

    return id;
}

stCliente busquedaClientes()
{
    stCliente b;

    printf("\nDNI del cliente: ");
    gets(b.dni);

    return b;
}

void busquedaCliente(stCliente a[], int v)
{

    stCliente b = busquedaClientes();
    int flag = 0;
    int i = 0;

    while(i < v && strcmp(b.dni, a[i].dni) == 0)  ///
    {

        if(strcmp(b.dni, a[i].dni) != 0 )
        {

            i++;

        }
        else
        {
            flag = 1;
        }
        i++;
    }



    system("pause");


    if(flag == 1)
    {
        printf("\n===================\n");
        mostrarUnCliente(a[i-1]);

    }
    else
    {
        printf("\nEl Cliente no se encuentra en la base de datos.");
    }

}

int arch2arreglo(char nombreArchivo[], stCliente e[], int dim, int v)
{
    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(v<dim && fread(&e[v], sizeof(stCliente), 1, archi) > 0)
        {
            v++;
        }

        fclose(archi);
    }
    return v;
}

void muestraArregloClientes(stCliente a[], int v)
{
    for(int i = 0; i<v; i++)
    {
        mostrarUnCliente(a[i]);
    }
}

int busquedaDNI(char nombreArchivo[])
{
    stCliente b = busquedaClientes();
    int flag = 0;
    stCliente a;

    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {

                flag = 1;

            }
        }
        fclose(archi);
    }
    return flag;
}

stCliente cargaUnCliente2()
{

    stCliente a;
    printf("\nNumero del cliente: ");
    fflush(stdin);
    scanf("%d", &a.nroCliente);
    printf("\nNombre del cliente: ");
    fflush(stdin);
    gets(a.nombre);
    printf("\nApellido del cliente: ");
    fflush(stdin);
    gets(a.apellido);
    printf("\nEmail del cliente: ");
    fflush(stdin);
    gets(a.email);
    printf("\nDomicilio del cliente: ");
    fflush(stdin);
    gets(a.domicilio);
    printf("\nMovil del cliente: ");
    fflush(stdin);
    gets(a.movil);
    a.eliminado = 0;
    system("cls");

    return a;
}

void cargaArchivoCliente2(char nombreArchivo[])
{
    stCliente a;

    static int i = 0;
    i = ultimoIdCliente(nombreArchivo);
    int existe = 1;
    char dni[50];
    char opcion = 0;
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi)
    {
        printf("\nVerifiquemos que el cliente no exista en la base de datos.");
        do
        {
            while(existe == 1){
            printf("\nIngrese un DNI: ");

            gets(dni);
            printf("\nEXISTE VALE: %d",existe);
            existe = comprobacionDni(nombreArchivo, dni);
            printf("\nEXISTE VALE: %d",existe);
            if(existe == 1){
                printf("\nEl cliente ya existe, ingrese otro dni");
            }else{
                printf("\nNo se ha encontrado al cliente, prosiga con la carga");
                }
            }
            a = cargaUnCliente2();
            i++;
            strcpy(a.dni,dni);
            a.idCliente = i;
            fwrite(&a, sizeof(stCliente), 1, archi);
            existe =1;
            fclose(archi);
            printf("\nDesea seguir cargando clientes? ESC PARA SALIR: ");
            opcion = getch();
            FILE *archi = fopen(nombreArchivo, "ab");
            fflush(stdin);

        }while(opcion != 27);

    fclose(archi);
    }
}


stConsumos cargaUnConsumo2()
{

    stConsumos a;

    a.anio = rand()%(2022-2010) + 2010;
    /*printf("\nIngrese el año de consumo: ");
    scanf("%d", &a.anio);
    /*printf("\nIngrese el mes de consumo: ");
    scanf("%d", &a.mes);*/
    a.mes = rand()%(12 -1) + 1;

    if(a.mes == 1){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 2 && (a.anio%4 == 0) ){
        a.dia = rand()%(29 - 1) + 1;
    }else if(a.mes == 2 && (a.anio%4 != 0)){
        a.dia = rand()%(28-1)+1;
    }else if(a.mes == 3){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 4){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 5){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 6){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 7){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 8){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 9){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 10){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 11){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 12){
        a.dia = rand()%(31 - 1) + 1;
    }
    printf("\nIngrese la cantidad de MB consumidos: ");
    scanf("%d", &a.datosConsumidos);
    printf("\nEl usuario se encuentra activo? (0 por si, -1 por no): ");
    scanf("%d", &a.baja);
    a.cantidadDeDatosConsumidos = a.cantidadDeDatosConsumidos + a.datosConsumidos;
    return a;
}


void cargaArchivoConsumos2(char nombreArchivoConsumos[], char nombreArchivoClientes[])
{
    stConsumos a;
    static int i = 0;
    int iClientes = 0;
    iClientes = ultimoIdCliente(nombreArchivoClientes);
    i = ultimoIdConsumo(nombreArchivoConsumos);
    char opcion = 0;
    FILE *archi = fopen(nombreArchivoConsumos, "ab");
    if(archi)
    {
        do
        {
            a = cargaUnConsumoAnioActual();
            i++;
            a.id = i;
            a.idCliente = rand()%iClientes + 1;
            fwrite(&a,sizeof(stConsumos),1,archi);
            printf("\nDesea seguir cargando consumos? ESC PARA SALIR: ");
            opcion = getch();
        }
        while(opcion != 27);
    }
    fclose(archi);
}

stConsumos cargaUnConsumoAnioActual()
{

    stConsumos a;
    time_t t =time(NULL);
    struct tm tiempoLocal = *localtime(&t);

    a.anio = tiempoLocal.tm_year + 1900;
    a.mes = rand()%(tiempoLocal.tm_mon+1) +1;
    if(a.mes == tiempoLocal.tm_mon+1){
    a.dia = rand()%(tiempoLocal.tm_mday - 1) + 1;
    }else if(a.mes == 1){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 2 && (a.anio%4 == 0) ){
        a.dia = rand()%(29 - 1) + 1;
    }else if(a.mes == 2 && (a.anio%4 != 0)){
        a.dia = rand()%(28-1)+1;
    }else if(a.mes == 3){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 4){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 5){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 6){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 7){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 8){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 9){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 10){
        a.dia = rand()%(31 - 1) + 1;
    }else if(a.mes == 11){
        a.dia = rand()%(30 - 1) + 1;
    }else if(a.mes == 12){
        a.dia = rand()%(31 - 1) + 1;
    }
    a.datosConsumidos = rand()&2000;
    a.baja = 0;
    return a;
}

int funcionAcumulador(char nombreArchivo[]){

FILE *archi = fopen(nombreArchivo, "rb");
stConsumos a;
stConsumos b = seleccionaUnaFecha();
int consumo = 0;
if(archi){
    while(fread(&a,sizeof(stConsumos), 1,archi) >0){
        if(b.anio == a.anio && b.dia == a.dia && b.mes == a.mes){
            consumo = a.datosConsumidos + consumo;
        }
    }
}
    return consumo;
}

stConsumos seleccionaUnaFecha(){

stConsumos a;

    printf("\nIngrese el año de consumo: ");
    scanf("%d", &a.anio);
    printf("\nIngrese el mes de consumo: ");
    scanf("%d", &a.mes);
     if(a.mes >12)
    {

        while(a.mes >12)
        {
            printf("Mes no valido, ingreselo nuevamente: ");
            scanf("%d", &a.mes);
        }
    }
    printf("\nIngrese el dia de consumo: ");
    scanf("%d", &a.dia);

    if(a.dia >29 && a.mes == 2 && (a.anio%4 == 0))
    {
        while(a.dia > 29)
        {
            printf("\nFecha invalida. Valida hasta el 29. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if(a.dia>28 && a.mes == 2 && (a.anio%4 != 0))
    {
        while(a.dia > 28)
        {
            printf("\nFecha invalida. Valida hasta el 28. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if(a.mes == 1|| a.mes == 3 || a.mes == 5|| a.mes == 7|| a.mes == 8|| a.mes == 10|| a.mes == 12 && a.dia>31)
    {
        while(a.dia > 31)
        {
            printf("\nFecha invalida. Valida hasta 31. Ingresela nuevamante: ");
            scanf("%d", &a.dia);
        }
    }
    else
    {
        while(a.dia > 30 && a.mes == 6 || a.mes == 4 || a.mes ==9 || a.mes ==11)
        {
            printf("\nFecha invalida. Valida hasta 30. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    return a;
}


int comprobacionDni(char nombreArchivo [], char dni[])
{
    stCliente a;
    int flag = 0;
    FILE *archi = fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, dni) == 0)
            {
                flag=1;
            }
        }
        fclose(archi);
        printf("\nLA FLAG VALE: %d", flag);
    }
    return flag;
}

void modificacionDniCliente(char nombreArchivo[])
{
    printf("\nElija el cliente al que quiera modificar el Nro. de DNI\n");
    stCliente b = busquedaClientes();
    stCliente a;
    stCliente c;
    int flag = 0;
    int existe = 1;
    int cant = 0;
    int compara = 1;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                cant = ftell(archi)/sizeof(stCliente);
                printf("\n cantidad %d", cant);
                flag++;
                printf("\nNro. de DNI actual: %s", a.dni);
                //fwrite(&a, sizeof(stCliente), 1, archi);
                rewind(archi);
                while(compara != 0)
                {
                    fseek(archi, (cant-1)*sizeof(stCliente), 0);//1 = SEEK_CUR
                    printf("\nIngrese el nuevo DNI: ");
                    fflush(stdin);
                    gets(c.dni);
                    compara = comprobacionDni(nombreArchivo, c.dni);
                    printf("\nDato de compara DNI %d", compara);
                if(compara != 0)
                {
                    //rewind(archi);
                    printf("\nEl DNI ingresado ya existe.");
                }
                else
                {

                    printf("\nPausa 1\n");
                    //fseek(archi, (cant-1)*sizeof(stCliente), 0);
                    strcpy(a.dni, c.dni);
                    fwrite(&a, sizeof(stCliente), 1, archi);
                    //muestraUnCliente(a);
                }
                }
            }
        }
        if(flag == 0)
        {
            printf("\n El cliente no se encuentra en la base de datos.");
        }
    }
    fclose(archi);
}

