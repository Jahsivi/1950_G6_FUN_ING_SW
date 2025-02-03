#include <stdio.h>
#include <string.h>

struct Prenda {
    char genero[10];    // Hombre o Mujer
    char talla[3];      // XS, S, M, L
    char color[20];     // Color de la prenda
    char tipoPrenda[20];// Tipo de prenda (Falda, Chompa, etc.)
    int cantidad;       // Cantidad de la prenda
};

void editarDatos(struct Prenda *p) {
    int opcion;
    
    printf("\n¿Qué desea editar?\n");
    printf("1. Tipo de prenda\n");
    printf("2. Género\n");
    printf("3. Talla\n");
    printf("4. Color\n");
    printf("5. Cantidad\n");
    printf("6. Cancelar\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese el nuevo tipo de prenda: ");
        scanf("%s", p->tipoPrenda);
    } 
    else if (opcion == 2) {
        printf("Ingrese el nuevo género (Hombre/Mujer): ");
        scanf("%s", p->genero);
        while (strcmp(p->genero, "Hombre") != 0 && strcmp(p->genero, "Mujer") != 0) {
            printf("Error: Ingrese un género válido (Hombre/Mujer): ");
            scanf("%s", p->genero);
        }
    } 
    else if (opcion == 3) {
        printf("Ingrese la nueva talla (XS, S, M, L): ");
        scanf("%s", p->talla);
        while (strcmp(p->talla, "XS") != 0 && strcmp(p->talla, "S") != 0 && strcmp(p->talla, "M") != 0 && strcmp(p->talla, "L") != 0) {
            printf("Error: Ingrese una talla válida (XS, S, M, L): ");
            scanf("%s", p->talla);
        }
    } 
    else if (opcion == 4) {
        printf("Ingrese el nuevo color: ");
        scanf("%s", p->color);
    } 
    else if (opcion == 5) {
        printf("Ingrese la nueva cantidad: ");
        scanf("%d", &p->cantidad);
        while (p->cantidad <= 0) {
            printf("Error: Ingrese una cantidad válida (mayor que 0): ");
            scanf("%d", &p->cantidad);
        }
    } 
    else if (opcion == 6) {
        printf("Edición cancelada.\n");
        return;
    } 
    else {
        printf("Opción no válida.\n");
        return;
    }

    char confirmacion;
    printf("\n¿Desea guardar los cambios realizados? (S/N): ");
    scanf(" %c", &confirmacion);

    while (confirmacion != 'S' && confirmacion != 's' && confirmacion != 'N' && confirmacion != 'n') {
        printf("Entrada inválida. ¿Desea guardar los cambios realizados? (S/N): ");
        scanf(" %c", &confirmacion);
    }

    if (confirmacion == 'N' || confirmacion == 'n') {
        printf("Los cambios han sido descartados.\n");
    } else {
        printf("Los cambios han sido guardados exitosamente.\n");
    }
}

int main() {
    struct Prenda miPrenda = {"Mujer", "M", "Rojo", "Chompa", 5};
    int opcion;

    do {
        printf("\nMenú de edición:\n");
        printf("1. Editar prenda\n");
        printf("2. Mostrar prenda\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            editarDatos(&miPrenda);
        } 
        else if (opcion == 2) {
            printf("\nDatos de la prenda:\n");
            printf("Tipo: %s\n", miPrenda.tipoPrenda);
            printf("Género: %s\n", miPrenda.genero);
            printf("Talla: %s\n", miPrenda.talla);
            printf("Color: %s\n", miPrenda.color);
            printf("Cantidad: %d\n", miPrenda.cantidad);
        } 
        else if (opcion == 3) {
            printf("Saliendo del programa.\n");
        } 
        else {
            printf("Opción no válida. Intente nuevamente.\n");
        }

    } while (opcion != 3);

    return 0;
}
