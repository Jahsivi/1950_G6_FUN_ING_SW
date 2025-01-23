#include <stdio.h>
#include <string.h>

struct Prenda {
    char genero[10];  // Hombre o Mujer
    char talla[3];    // XS, S, M, L
    char color[20];   // Color de la prenda
    int cantidad;     // Cantidad de la prenda
};

void ingresarDatos(struct Prenda *p) {
    // Ingresar genero (hombre o mujer)
    printf("Ingrese el genero (Hombre/Mujer): ");
    scanf("%s", p->genero);
    if (strcmp(p->genero, "Hombre") != 0 && strcmp(p->genero, "Mujer") != 0) {
        do {
            printf("Error: Ingrese un genero valido (Hombre/Mujer): ");
            scanf("%s", p->genero);
        } while (strcmp(p->genero, "Hombre") != 0 && strcmp(p->genero, "Mujer") != 0);
    }

    // Ingresar talla (XS, S, M, L)
    printf("Ingrese la talla (XS, S, M, L): ");
    scanf("%s", p->talla);
    if (strcmp(p->talla, "XS") != 0 && strcmp(p->talla, "S") != 0 && strcmp(p->talla, "M") != 0 && strcmp(p->talla, "L") != 0) {
        do {
            printf("Error: Ingrese una talla valida (XS, S, M, L): ");
            scanf("%s", p->talla);
        } while (strcmp(p->talla, "XS") != 0 && strcmp(p->talla, "S") != 0 && strcmp(p->talla, "M") != 0 && strcmp(p->talla, "L") != 0);
    }

    // Ingresar color
    printf("Ingrese el color de la prenda: ");
    scanf("%s", p->color);

    // Ingresar cantidad
    printf("Ingrese la cantidad de la prenda: ");
    scanf("%d", &p->cantidad);
    if (p->cantidad <= 0) {
        do {
            printf("Error: Ingrese una cantidad valida (mayor que 0): ");
            scanf("%d", &p->cantidad);
        } while (p->cantidad <= 0);
    }
}

void guardarDatos(struct Prenda p) {
    // Aquí puedes guardar los datos en un archivo o base de datos
    printf("\nDatos de la prenda guardados correctamente:\n");
    printf("Genero: %s\n", p.genero);
    printf("Talla: %s\n", p.talla);
    printf("Color: %s\n", p.color);
    printf("Cantidad: %d\n", p.cantidad);
}

void mostrarMenu() {
    printf("\nSelecciona una opción:\n");
    printf("1. Ingresar nueva prenda\n");
    printf("2. Mostrar datos de la prenda\n");
    printf("3. Salir\n");
}

int main() {
    struct Prenda nuevaPrenda;
    int opcion;

    do {
        mostrarMenu();
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            ingresarDatos(&nuevaPrenda);
            guardarDatos(nuevaPrenda);
        }
        if (opcion == 2) {
            printf("\nDatos de la prenda:\n");
            printf("Genero: %s\n", nuevaPrenda.genero);
            printf("Talla: %s\n", nuevaPrenda.talla);
            printf("Color: %s\n", nuevaPrenda.color);
            printf("Cantidad: %d\n", nuevaPrenda.cantidad);
        }
        if (opcion == 3) {
            printf("Saliendo del programa.\n");
        }
        if (opcion != 1 && opcion != 2 && opcion != 3) {
            printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

    return 0;
}