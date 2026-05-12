#include <stdio.h>
#include <string.h>

#define MAX 50

char nombres[MAX][30];
int cantidades[MAX];
float tiempos[MAX];
float recursos[MAX];

int totalProductos = 0;

/* INGRESAR PRODUCTOS */
void ingresarProductos() {

    printf("\nNombre del producto: ");
    scanf("%s", nombres[totalProductos]);

    printf("Cantidad demandada: ");
    scanf("%d", &cantidades[totalProductos]);

    printf("Tiempo por unidad: ");
    scanf("%f", &tiempos[totalProductos]);

    printf("Recursos por unidad: ");
    scanf("%f", &recursos[totalProductos]);

    totalProductos++;

    printf("\nProducto registrado correctamente.\n");
}

/* MOSTRAR PRODUCTOS */
void mostrarProductos() {

    int i;

    if(totalProductos == 0) {
        printf("\nNo existen productos registrados.\n");
        return;
    }

    printf("\n--- LISTA DE PRODUCTOS ---\n");

    for(i = 0; i < totalProductos; i++) {

        printf("\nProducto #%d\n", i + 1);
        printf("Nombre: %s\n", nombres[i]);
        printf("Cantidad: %d\n", cantidades[i]);
        printf("Tiempo: %.2f\n", tiempos[i]);
        printf("Recursos: %.2f\n", recursos[i]);
    }
}

/* BUSCAR PRODUCTO */
int buscarProducto(char nombreBuscar[]) {

    int i;

    for(i = 0; i < totalProductos; i++) {

        if(strcmp(nombres[i], nombreBuscar) == 0) {
            return i;
        }
    }

    return -1;
}

/* EDITAR PRODUCTO */
void editarProducto() {

    char nombreBuscar[30];
    int posicion;

    printf("\nIngrese el nombre del producto a editar: ");
    scanf("%s", nombreBuscar);

    posicion = buscarProducto(nombreBuscar);

    if(posicion == -1) {

        printf("\nProducto no encontrado.\n");

    } else {

        printf("\nNuevo nombre: ");
        scanf("%s", nombres[posicion]);

        printf("Nueva cantidad: ");
        scanf("%d", &cantidades[posicion]);

        printf("Nuevo tiempo: ");
        scanf("%f", &tiempos[posicion]);

        printf("Nuevo recurso: ");
        scanf("%f", &recursos[posicion]);

        printf("\nProducto editado correctamente.\n");
    }
}

/* ELIMINAR PRODUCTO */
void eliminarProducto() {

    char nombreBuscar[30];
    int posicion;
    int i;

    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf("%s", nombreBuscar);

    posicion = buscarProducto(nombreBuscar);

    if(posicion == -1) {

        printf("\nProducto no encontrado.\n");

    } else {

        for(i = posicion; i < totalProductos - 1; i++) {

            strcpy(nombres[i], nombres[i + 1]);
            cantidades[i] = cantidades[i + 1];
            tiempos[i] = tiempos[i + 1];
            recursos[i] = recursos[i + 1];
        }

        totalProductos--;

        printf("\nProducto eliminado correctamente.\n");
    }
}

/* CALCULAR PRODUCCION */
void calcularProduccion() {

    float tiempoTotal = 0;
    float recursosTotales = 0;

    float tiempoDisponible;
    float recursosDisponibles;

    int i;

    for(i = 0; i < totalProductos; i++) {

        tiempoTotal += cantidades[i] * tiempos[i];
        recursosTotales += cantidades[i] * recursos[i];
    }

    printf("\nTiempo total requerido: %.2f", tiempoTotal);
    printf("\nRecursos totales requeridos: %.2f\n", recursosTotales);

    printf("\nIngrese tiempo disponible: ");
    scanf("%f", &tiempoDisponible);

    printf("Ingrese recursos disponibles: ");
    scanf("%f", &recursosDisponibles);

    if(tiempoTotal <= tiempoDisponible &&
       recursosTotales <= recursosDisponibles) {

        printf("\nLa fabrica SI puede cumplir la demanda.\n");

    } else {

        printf("\nLa fabrica NO puede cumplir la demanda.\n");
    }
}

/* MENU PRINCIPAL */
int main() {

    int opcion;

    do {

        printf("\n========== MENU ==========");
        printf("\n1. Ingresar producto");
        printf("\n2. Mostrar productos");
        printf("\n3. Editar producto");
        printf("\n4. Eliminar producto");
        printf("\n5. Calcular produccion");
        printf("\n6. Salir");

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                ingresarProductos();
                break;

            case 2:
                mostrarProductos();
                break;

            case 3:
                editarProducto();
                break;

            case 4:
                eliminarProducto();
                break;

            case 5:
                calcularProduccion();
                break;

            case 6:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    } while(opcion != 6);

    return 0;
}