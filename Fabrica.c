#include <stdio.h>
#include <string.h>

#define MAX 50

char nombres[MAX][30];
int cantidades[MAX];
float tiempos[MAX];
float recursos[MAX];

int totalProductos = 0;

void ingresarProductos() {
    printf("Nombre: ");
    scanf("%s", nombres[totalProductos]);

    printf("Cantidad: ");
    scanf("%d", &cantidades[totalProductos]);

    printf("Tiempo por unidad: ");
    scanf("%f", &tiempos[totalProductos]);

    printf("Recursos por unidad: ");
    scanf("%f", &recursos[totalProductos]);

    totalProductos++;
}

void mostrarProductos() {
    int i;

    for(i = 0; i < totalProductos; i++) {
        printf("\nProducto: %s", nombres[i]);
        printf("\nCantidad: %d", cantidades[i]);
        printf("\nTiempo: %.2f", tiempos[i]);
        printf("\nRecursos: %.2f\n", recursos[i]);
    }
}

void calcularProduccion() {

    float tiempoTotal = 0;
    float recursosTotales = 0;

    int i;

    for(i = 0; i < totalProductos; i++) {

        tiempoTotal += cantidades[i] * tiempos[i];
        recursosTotales += cantidades[i] * recursos[i];
    }

    printf("\nTiempo total: %.2f", tiempoTotal);
    printf("\nRecursos totales: %.2f\n", recursosTotales);
}

int main() {

    int opcion;

    do {

        printf("\n1. Ingresar");
        printf("\n2. Mostrar");
        printf("\n3. Calcular");
        printf("\n4. Salir");
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                ingresarProductos();
                break;

            case 2:
                mostrarProductos();
                break;

            case 3:
                calcularProduccion();
                break;
        }

    } while(opcion != 4);

    return 0;
}