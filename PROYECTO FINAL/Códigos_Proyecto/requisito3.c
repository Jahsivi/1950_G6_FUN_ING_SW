#include <stdio.h>
#include <string.h>

#define MAX_PRENDAS 100

// Definición de la estructura para las prendas
typedef struct {
    char tipo[20];       // Tipo: Jean, blusa, etc.
    char genero[10];     // Hombre o Mujer
    char talla[5];       // Tallas: XS, S, M, etc.
    int cantidad;        // Cantidad disponible
} Prenda;

// Función para filtrar y mostrar las prendas según los criterios
void filtrarPrendas(Prenda prendas[], int total, const char* tipo, const char* genero, const char* talla) {
    int encontrado = 0;
    printf("\nResultados de la busqueda:\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        if ((strcmp(tipo, "") == 0 || strcmp(prendas[i].tipo, tipo) == 0) &&
            (strcmp(genero, "") == 0 || strcmp(prendas[i].genero, genero) == 0) &&
            (strcmp(talla, "") == 0 || strcmp(prendas[i].talla, talla) == 0)) {
            printf("Tipo: %s, Género: %s, Talla: %s, Cantidad: %d\n",
                   prendas[i].tipo, prendas[i].genero, prendas[i].talla, prendas[i].cantidad);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron prendas que coincidan con los criterios.\n");
    }
}

int main() {
    Prenda prendas[MAX_PRENDAS] = {
        {"Jean", "Hombre", "M", 100},
        {"Blusa", "Mujer", "S", 100},
        {"Chaqueta", "Hombre", "L", 100},
        {"Vestido", "Mujer", "M", 100},
        {"Camiseta", "Hombre", "XL", 100},
        {"Falda", "Mujer", "S", 100},
        {"Short", "Mujer", "M", 100},
        {"Abrigo", "Hombre", "L", 100}
    };
    int totalPrendas = 8; // Número de prendas en el inventario

    char tipo[20] = "", genero[10] = "", talla[5] = "";

    printf("Filtro de Búsqueda:\n");
    printf("Ingrese el tipo de prenda (o deje en blanco para no filtrar): ");
    fgets(tipo, sizeof(tipo), stdin);
    tipo[strcspn(tipo, "\n")] = 0; // Eliminar el salto de línea

    printf("Ingrese el género (Hombre/Mujer) (o deje en blanco para no filtrar): ");
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = 0;

    printf("Ingrese la talla (o deje en blanco para no filtrar): ");
    fgets(talla, sizeof(talla), stdin);
    talla[strcspn(talla, "\n")] = 0;

    filtrarPrendas(prendas, totalPrendas, tipo, genero, talla);

    return 0;
}