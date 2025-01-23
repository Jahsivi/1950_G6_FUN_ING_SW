#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIO 50
#define MAX_CONTRASENA 50
#define MAX_PRENDAS 100

// Definición de la estructura para las prendas
typedef struct {
    char tipo[20];       // Tipo de prenda: Jean, blusa, etc.
    char genero[10];     // Género: Hombre o Mujer
    char talla[5];       // Tallas: XS, S, M, L, etc.
    int cantidad;        // Cantidad disponible de esa prenda
} Prenda;

// Función para validar la contraseña según ciertas reglas
int validar_contrasena(const char *contrasena) {
    int tiene_mayuscula = 0, tiene_minuscula = 0, tiene_numero = 0, tiene_especial = 0;

    // Recorre cada carácter de la contraseña
    for (int i = 0; i < strlen(contrasena); i++) {
        // Verifica si el carácter es mayúscula
        if (isupper(contrasena[i])) tiene_mayuscula = 1;
        // Verifica si el carácter es minúscula
        else if (islower(contrasena[i])) tiene_minuscula = 1;
        // Verifica si el carácter es un número
        else if (isdigit(contrasena[i])) tiene_numero = 1;
        // Verifica si el carácter es un carácter especial (no alfabético ni numérico)
        else tiene_especial = 1;
    }

    // Retorna 1 si la contraseña cumple con todos los requisitos (mayúscula, minúscula, número, especial)
    return tiene_mayuscula && tiene_minuscula && tiene_numero && tiene_especial;
}

// Función para validar que el nombre de usuario contenga al menos un carácter alfabético o un número
int validar_usuario(const char *usuario) {
    int tiene_alfabetico_o_numero = 0;

    // Recorre cada carácter del usuario
    for (int i = 0; i < strlen(usuario); i++) {
        // Verifica si el carácter es alfabético o numérico
        if (isalpha(usuario[i]) || isdigit(usuario[i])) {
            tiene_alfabetico_o_numero = 1;
            break; // Si se encuentra al menos un carácter válido, se puede salir del ciclo
        }
    }

    // Retorna 1 si se encuentra un carácter alfabético o un número en el usuario
    return tiene_alfabetico_o_numero;
}

// Función para filtrar y mostrar las prendas según los criterios proporcionados
void filtrarPrendas(Prenda prendas[], int total, const char* tipo, const char* genero, const char* talla) {
    int encontrado = 0; // Variable para verificar si encontramos prendas que coincidan con los filtros
    printf("\nResultados de la búsqueda:\n");
    printf("--------------------------------------------\n");

    // Recorremos todas las prendas en el inventario
    for (int i = 0; i < total; i++) {
        // Comprobamos si la prenda cumple con los filtros proporcionados
        if ((strcmp(tipo, "") == 0 || strcmp(prendas[i].tipo, tipo) == 0) &&
            (strcmp(genero, "") == 0 || strcmp(prendas[i].genero, genero) == 0) &&
            (strcmp(talla, "") == 0 || strcmp(prendas[i].talla, talla) == 0)) {
            // Si coincide, imprimimos la prenda
            printf("Tipo: %s, Género: %s, Talla: %s, Cantidad: %d\n", prendas[i].tipo, prendas[i].genero, prendas[i].talla, prendas[i].cantidad);
            encontrado = 1; // Marcamos que encontramos al menos una prenda que cumple con el filtro
        }
    }

    // Si no encontramos ninguna prenda que coincida con los filtros, mostramos un mensaje
    if (!encontrado) {
        printf("No se encontraron prendas que coincidan con los criterios.\n");
    }
}

// Función para ingresar los detalles de una prenda
void ingresarPrenda(Prenda *p) {
    printf("Tipo de prenda: ");
    fgets(p->tipo, sizeof(p->tipo), stdin);
    p->tipo[strcspn(p->tipo, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Género (Hombre/Mujer): ");
    fgets(p->genero, sizeof(p->genero), stdin);
    p->genero[strcspn(p->genero, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Talla (XS/S/M/L): ");
    fgets(p->talla, sizeof(p->talla), stdin);
    p->talla[strcspn(p->talla, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Cantidad: ");
    scanf("%d", &p->cantidad);
    getchar(); // Consumir el salto de línea restante
}

int main() {
    char usuarioRegistrado[MAX_USUARIO];
    char contrasenaRegistrada[MAX_CONTRASENA];
    char usuarioIngresado[MAX_USUARIO];
    char contrasenaIngresada[MAX_CONTRASENA];
    int opcion, totalPrendas = 0;
    Prenda prendas[MAX_PRENDAS];  // Inventario de prendas
    int registroCompleto = 0; // Bandera para verificar si el registro fue exitoso

    // Paso 1: Registro
    printf("=== Registro ===\n");

    // Bucle para ingresar y validar el nombre de usuario
    do {
        printf("Ingrese un nombre de usuario: ");
        fgets(usuarioRegistrado, MAX_USUARIO, stdin);
        usuarioRegistrado[strcspn(usuarioRegistrado, "\n")] = '\0'; // Eliminar el salto de línea

        if (!validar_usuario(usuarioRegistrado)) {
            printf("El nombre de usuario debe contener al menos un carácter alfabético o un número.\n");
        }
    } while (!validar_usuario(usuarioRegistrado));

    // Bucle para ingresar y validar la contraseña
    do {
        printf("Ingrese una contraseña: ");
        fgets(contrasenaRegistrada, MAX_CONTRASENA, stdin);
        contrasenaRegistrada[strcspn(contrasenaRegistrada, "\n")] = '\0'; // Eliminar el salto de línea

        if (!validar_contrasena(contrasenaRegistrada)) {
            printf("La contraseña debe contener al menos una letra mayúscula, una letra minúscula, un número y un carácter especial.\n");
        }
    } while (!validar_contrasena(contrasenaRegistrada));

    printf("¡Registro exitoso! Ahora puede iniciar sesión.\n\n");

    // Paso 2: Iniciar sesión
    printf("=== Iniciar sesión ===\n");

    // Solicitando datos para iniciar sesión
    do {
        printf("Ingrese su nombre de usuario: ");
        fgets(usuarioIngresado, MAX_USUARIO, stdin);
        usuarioIngresado[strcspn(usuarioIngresado, "\n")] = '\0'; // Eliminar el salto de línea

        printf("Ingrese su contraseña: ");
        fgets(contrasenaIngresada, MAX_CONTRASENA, stdin);
        contrasenaIngresada[strcspn(contrasenaIngresada, "\n")] = '\0'; // Eliminar el salto de línea

        if (strcmp(usuarioRegistrado, usuarioIngresado) != 0 || strcmp(contrasenaRegistrada, contrasenaIngresada) != 0) {
            printf("Nombre de usuario o contraseña incorrectos. Intente de nuevo.\n\n");
        }
    } while (strcmp(usuarioRegistrado, usuarioIngresado) != 0 || strcmp(contrasenaRegistrada, contrasenaIngresada) != 0);

    printf("¡Inicio de sesión exitoso! Bienvenido, %s.\n\n", usuarioRegistrado);

    // Paso 3: Menú para ingresar y filtrar prendas
    int menu = 0;
    do {
        // Menú para ingresar y filtrar prendas
        printf("==== Menú de Prendas ====\n");
        printf("1. Ingresar prendas\n");
        printf("2. Filtrar prendas\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &menu);
        getchar(); // Consumir el salto de línea restante después de leer la opción

        if (menu == 1) { // Opción de ingresar prendas
            if (totalPrendas < MAX_PRENDAS) {
                ingresarPrenda(&prendas[totalPrendas]);
                totalPrendas++;
            } else {
                printf("No se pueden ingresar más prendas.\n");
            }
        } else if (menu == 2) { // Opción de filtrar prendas
            char tipo[20] = "", genero[10] = "", talla[5] = "";

            // Solicitar filtros
            printf("Ingrese el tipo de prenda (o deje en blanco para no filtrar): ");
            fgets(tipo, sizeof(tipo), stdin);
            tipo[strcspn(tipo, "\n")] = '\0';

            printf("Ingrese el género (Hombre/Mujer) (o deje en blanco para no filtrar): ");
            fgets(genero, sizeof(genero), stdin);
            genero[strcspn(genero, "\n")] = '\0';

            printf("Ingrese la talla (o deje en blanco para no filtrar): ");
            fgets(talla, sizeof(talla), stdin);
            talla[strcspn(talla, "\n")] = '\0';

            // Llamar a la función de filtrado
            filtrarPrendas(prendas, totalPrendas, tipo, genero, talla);
        } else if (menu == 3) { // Opción de salir
            printf("Saliendo del programa...\n");
        } else {
            printf("Opción no válida. Intente de nuevo.\n\n");
        }

    } while (menu != 3); // El ciclo continúa hasta que el usuario elija salir

    return 0;
}
