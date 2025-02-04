#pragma once
#ifndef COLOR_H
#define COLOR_H

#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Macros de colores
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_WHITE    "\033[47m"
#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

// Prototipos de funciones
void centrar_printf(const char* texto, const char* color);
void mostrar_barra_cargando(int segundos);
void inicio(void);
void gotoxy(int x, int y);
void ocultar_cursor(void);
void mostrar_cursor(void);
void limpiar_consola(void);
int factorial(int n);
int es_primo(int n);
void fibonacci(int n);
int suma_digitos(int n);
int mcd(int a, int b);
int mcm(int a, int b);

// Definiciones de funciones

// Imprime el texto centrado en la consola según el ancho actual
void centrar_printf(const char* texto, const char* color) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns = 80; // Valor por defecto si no se obtiene info
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        columns = csbi.dwSize.X;
    }
    int len = (int)strlen(texto);
    int spaces = (columns > len) ? (columns - len) / 2 : 0;
    printf("%s", color);
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("%s\n", texto);
    printf(RESET);
}

// Muestra una barra de carga de 50 pasos durante la cantidad de segundos indicada
void mostrar_barra_cargando(int segundos) {
    int total = 90;
    int ancho_terminal = 80; // Puedes ajustar esto según el tamaño de tu terminal
    int barra_ancho = total + 2; // El tamaño total de la barra incluyendo los corchetes
    int espacios_izquierda = (ancho_terminal - barra_ancho) / 2;

    // Imprimir espacios antes de la barra para centrarla
    for (int i = 0; i < espacios_izquierda; i++) {
        printf(" ");
    }

    printf("Cargando: [");
    for (int i = 0; i < total; i++) {
        Sleep((segundos * 1000) / total); // Espera entre cada paso
        printf("="); // Imprimir el progreso
        fflush(stdout);
    }
    printf("] 100%%\n");
}

// Muestra la animación de inicio con texto centrado y una barra de carga
void inicio() {
    printf("\n\n");
    system("color a");

    centrar_printf("   SSSSSSSSSSSSSSS EEEEEEEEEEEEEEEEEEEEEEIIIIIIIIIIMMMMMMMM               MMMMMMMM", GREEN);
    centrar_printf(" SS:::::::::::::::SE::::::::::::::::::::EI::::::::IM:::::::M             M:::::::M", YELLOW);
    centrar_printf("S:::::SSSSSS::::::SE::::::::::::::::::::EI::::::::IM::::::::M           M::::::::M", BLUE);
    centrar_printf("S:::::S     SSSSSSSEE::::::EEEEEEEEE::::EII::::::IIM:::::::::M         M:::::::::M", RED);
    centrar_printf("S:::::S              E:::::E       EEEEEE  I::::I  M::::::::::M       M::::::::::M", CYAN);
    centrar_printf("S:::::S              E:::::E               I::::I  M:::::::::::M     M:::::::::::M", MAGENTA);
    centrar_printf(" S::::SSSS           E::::::EEEEEEEEEE     I::::I  M:::::::M::::M   M::::M:::::::M", WHITE);
    centrar_printf("  SS::::::SSSSS      E:::::::::::::::E     I::::I  M::::::M M::::M M::::M M::::::M", GREEN);
    centrar_printf("    SSS::::::::SS    E:::::::::::::::E     I::::I  M::::::M  M::::M::::M  M::::::M", CYAN);
    centrar_printf("       SSSSSS::::S   E::::::EEEEEEEEEE     I::::I  M::::::M   M:::::::M   M::::::M", BLUE);
    centrar_printf("            S:::::S  E:::::E               I::::I  M::::::M    M:::::M    M::::::M", RED);
    centrar_printf("            S:::::S  E:::::E       EEEEEE  I::::I  M::::::M     MMMMM     M::::::M", MAGENTA);
    centrar_printf("SSSSSSS     S:::::SEE::::::EEEEEEEE:::::EII::::::IIM::::::M               M::::::M", YELLOW);
    centrar_printf("S::::::SSSSSS:::::SE::::::::::::::::::::EI::::::::IM::::::M               M::::::M", BRIGHT_GREEN);
    centrar_printf("S:::::::::::::::SS E::::::::::::::::::::EI::::::::IM::::::M               M::::::M", BRIGHT_BLUE);
    centrar_printf(" SSSSSSSSSSSSSSS   EEEEEEEEEEEEEEEEEEEEEEIIIIIIIIIIMMMMMMMM               MMMMMMMM", BRIGHT_RED);

    printf("\n\n");
    mostrar_barra_cargando(1);
    printf(CYAN"\t\t\t\t\t");
    system("pause");
    printf(RESET);
}

// Mueve el cursor a la posición (x,y) en la consola
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Oculta el cursor de la consola
void ocultar_cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Muestra el cursor de la consola
void mostrar_cursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

// Limpia la consola (en Windows)
void limpiar_consola() {
    system("cls");
}

// Calcula el factorial de n
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Devuelve 1 si n es primo, 0 en caso contrario (usa i*i <= n para evitar float)
int es_primo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Muestra los primeros n números de la secuencia de Fibonacci
void fibonacci(int n) {
    int a = 0, b = 1, temp;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

// Suma los dígitos de n
int suma_digitos(int n) {
    int suma = 0;
    while (n) {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}

// Calcula el máximo común divisor usando el algoritmo de Euclides
int mcd(int a, int b) {
    return (b == 0) ? a : mcd(b, a % b);
}

// Calcula el mínimo común múltiplo
int mcm(int a, int b) {
    return (a * b) / mcd(a, b);
}

#endif // COLOR_H
