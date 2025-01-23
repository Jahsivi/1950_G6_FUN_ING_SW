#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIO 50
#define MAX_CONTRASENA 50

int validar_contrasena(const char *contrasena) {
    int tiene_mayuscula = 0, tiene_minuscula = 0, tiene_numero = 0, tiene_especial = 0;

    for (int i = 0; i < strlen(contrasena); i++) {
        if (isupper(contrasena[i])) tiene_mayuscula = 1;
        else if (islower(contrasena[i])) tiene_minuscula = 1;
        else if (isdigit(contrasena[i])) tiene_numero = 1;
        else tiene_especial = 1;
    }

    return tiene_mayuscula && tiene_minuscula && tiene_numero && tiene_especial;
}

int validar_usuario(const char *usuario) {
    int tiene_alfabetico_o_numero = 0;

    for (int i = 0; i < strlen(usuario); i++) {
        if (isalpha(usuario[i]) || isdigit(usuario[i])) {
            tiene_alfabetico_o_numero = 1;
            break;
        }
    }

    return tiene_alfabetico_o_numero;
}

int main() {
    char usuarioRegistrado[MAX_USUARIO];
    char contrasenaRegistrada[MAX_CONTRASENA];
    char usuarioIngresado[MAX_USUARIO];
    char contrasenaIngresada[MAX_CONTRASENA];
    int opcion;
    int registroCompleto = 0;

    do {
        printf("==== Menú ====\n");
        printf("1. Registrarse\n");
        printf("2. Iniciar sesión\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Consumir el salto de línea restante

        if (opcion == 1) { // Registro de usuario
            printf("=== Registro ===\n");

            do {
                printf("Ingrese un nombre de usuario: ");
                fgets(usuarioRegistrado, MAX_USUARIO, stdin);
                usuarioRegistrado[strcspn(usuarioRegistrado, "\n")] = '\0'; // Eliminar el salto de línea

                if (!validar_usuario(usuarioRegistrado)) {
                    printf("El nombre de usuario debe contener al menos un carácter alfabético o un número.\n");
                }
            } while (!validar_usuario(usuarioRegistrado));

            do {
                printf("Ingrese una contraseña: ");
                fgets(contrasenaRegistrada, MAX_CONTRASENA, stdin);
                contrasenaRegistrada[strcspn(contrasenaRegistrada, "\n")] = '\0'; // Eliminar el salto de línea

                if (!validar_contrasena(contrasenaRegistrada)) {
                    printf("La contraseña debe contener al menos una letra mayúscula, una letra minúscula, un número y un carácter especial.\n");
                }
            } while (!validar_contrasena(contrasenaRegistrada));

            registroCompleto = 1;
            printf("¡Registro exitoso! Ahora puede iniciar sesión.\n\n");
        } else if (opcion == 2) { // Inicio de sesión
            if (!registroCompleto) {
                printf("Primero debe registrarse antes de iniciar sesión.\n\n");
                continue;
            }

            printf("=== Iniciar sesión ===\n");
            printf("Ingrese su nombre de usuario: ");
            fgets(usuarioIngresado, MAX_USUARIO, stdin);
            usuarioIngresado[strcspn(usuarioIngresado, "\n")] = '\0'; // Eliminar el salto de línea

            printf("Ingrese su contraseña: ");
            fgets(contrasenaIngresada, MAX_CONTRASENA, stdin);
            contrasenaIngresada[strcspn(contrasenaIngresada, "\n")] = '\0'; // Eliminar el salto de línea

            // Validar usuario y contraseña
            if (strcmp(usuarioRegistrado, usuarioIngresado) == 0 &&
                strcmp(contrasenaRegistrada, contrasenaIngresada) == 0) {
                printf("¡Inicio de sesión exitoso! Bienvenido, %s.\n\n", usuarioRegistrado);
            } else {
                printf("Nombre de usuario o contraseña incorrectos. Inténtelo de nuevo.\n\n");
            }
        } else if (opcion == 3) { // Salir
            printf("Saliendo del programa...\n");
        } else {
            printf("Opción no válida. Intente de nuevo.\n\n");
        }
    } while (opcion != 3);

    return 0;
}