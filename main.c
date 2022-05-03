#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
# define M_PI 3.14159265358979323846 
#include "pila.c"

void clrscr() {
    system("@cls||clear");
}


//---------Trabajo Práctico N° 4: Arreglos---------//

void print_array(int * array, int len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (len-i > 1) {printf(", ");}
    }
    printf("}\n");
}

//1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
int scanarray(int * array, int len) {
    int e;
    for (int i = 0; i < len; i++) {
        printf("Ingrese un valor entero: ");
        scanf("%d", &e);
        array[i] = e;
    }
    return len;
}

int Ejercicio1() {
    int *array = (int*)malloc(sizeof(int) * 3);
    scanarray(array, 3);
    print_array(array, 3);
}

//2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.
int Ejercicio2() {
    int array[3] = {1, 2, 3};
    print_array(array, 3);
}

//3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.
int sum_array(int * array, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sum + array[i];
    }
    return sum;
}

int Ejercicio3() {
    int *array = (int*)malloc(sizeof(int) * 7);
    scanarray(array, 7);
    int sum = sum_array(array, 7);
    printf("La suma de los valores del arreglo es igual a %d\n", sum);
}

//4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
Pila join_array_and_pila(int *array, int len, Pila *p) {
    for (int i = 0; i < len; i++) {
        apilar(p, array[i]);
    }
    mostrar(p);
}

int Ejercicio4() {
    Pila pila;
    inicpila(&pila);
    for (int i = 0; i < 5; i++) {
        leer(&pila);
    }
    int *array = (int*)malloc(sizeof(int) * 5);
    scanarray(array, 5);
    join_array_and_pila(array, 5, &pila);
}

//5. Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)
void load_array(float *array) {
    float num = 0.1;
    for (int i = 0; i < 100; i++) {
        array[i]  = num * M_PI;
        num = num + 0.1;
    }
}

float sum_float_array(float *array) {
    float sum = 0;
    for (int i = 0; i < 100; i++) {
        sum = sum + array[i];
    }
    return sum;
}


int Ejercicio5() {
    float *array = (float*)malloc(sizeof(float) * 100);
    load_array(array);
    printf("La suma de todos los elementos es de %.2f\n", sum_float_array(array));
}

//6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
bool is_in_array(char *array, int len, char c) {
    for (int i = 0; i < len; i++) {
        if (array[i] = c) {
            return true;
        }
    }
    return false;
}

int Ejercicio6() {
    char array[] = {'a', 'b', 'c', 'd'};
    if (is_in_array(array, 4, 'b')) {
        printf("SI");
    }
    else {
        printf("NO");
    }
}

//7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.
void insert_char(char *array, char e) {
    char a;
    char b;
    int pos;
    int len = strlen(array);
    for (int i = 0; i < len; i++) {
        a = array[i];
        b = array[i+1];
        if (e >= a && e <= b) {
            pos = i+1;
            break;
        }
    }
    for (int i = len; i >= pos; i--) {
        array[i+1] = array[i];
    }
    array[pos] = e;
}

int Ejercicio7() {
    fflush(stdin);
    char *array = (char*)malloc(sizeof(char) * 9);

    fgets(array, 9, stdin);
    printf("%s", array);
    insert_char(array, 'f');
    insert_char(array, 'b');
    insert_char(array, 'c');
    insert_char(array, 'd');
    printf("%s", array);
}

char max_char(char *a, int len) {
    char max = a[0];
    for (int i = 0; i < len; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

//8. Realizar una función que obtenga el máximo carácter de un arreglo dado.
int Ejercicio8() {
    char a[] = {"Hola"};
    printf("%c", max_char(a, strlen(a)));
}

bool is_palindrome(char *a, int len) {
    for (int i = 0, c = len-1; i < len; i++, c--) {
        if (a[i] != a[c]) {
            return false;
        }
    }
    return true;
}


//9. Realizar una función que determine si un arreglo es capicúa.
int Ejercicio9() {
    char a[] = {"canoa"};
    char b[] = {"lolol"};
    if (is_palindrome(a, strlen(a))) {
        printf("a es capicua\n");
    }
    else {
        printf("a no es capicua\n");
    }
    if (is_palindrome(b, strlen(b))) {
        printf("b es capicua\n");
    }
    else {
        printf("b no es capicua\n");
    }
}

void invert_array(char *a, int len) {
    char tmp;
    for (int i = 0, c = len-1; i < len / 2; i++, c--) {
        tmp = a[i];
        a[i] = a[c];
        a[c] = tmp;
    }
}

//10. Realizar una función que invierta los elementos de un arreglo.  (sin utilizar un arreglo auxiliar)
int Ejercicio10() {
    char a[] = "abcdefgh";
    invert_array(a, strlen(a));
    printf(a);
}

//---------Selección---------//
int min_char_pos(char *a, int len, int from) {
    char min = a[from];
    int pos = 0;
    for (int i = from; i < len; i++) {
        if (a[i] < min) {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}

void sort_s(char *a, int len) {
    char tmp;
    int pos = 0;
    for (int step = 0; step < len-1; step++) {
        printf(a);
        pos = min_char_pos(a, len, step);
        tmp = a[pos];
        a[pos] = a[step];
        a[step] = tmp;
        printf("\nmin pos: %d || step: %d\n", pos, step);
    }
}
//---------Inserción---------//

void sort_i(char *a, int len) {
    char aux;
    int pos;
    for (int i = 0; i < len; i++) {
        pos = i;
        aux = a[i];
        while(pos > 0 && a[pos-1] > aux) {
            a[pos] = a[pos-1];
            pos--;
        }
        a[pos] = aux;
    }
}

//11. Ordenar un arreglo según los siguientes métodos:
int Ejercicio11() {
    char a[] = {"casdb"};
    sort_s(a, strlen(a));
    printf(a);
    char b[] = {"casdb"};
    sort_i(b, strlen(a));
    printf(a);
}

//12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.
char join_arrays_2(char *a, char *b, char *r) {
    int lena = strlen(a);
    int lenb = strlen(b);
    printf("%d || %d\n", lena, lenb);
    int pos = 0;
    char result[8];
    for (int i, j; i < lena, j < lenb; i++, j++) {
        result[pos] = a[i];
        pos++;
        result[pos] = b[j];
        pos++;
    }
    printf(result);
    r = result;
}

int Ejercicio12() {
    char arr[] = {"aceg"};
    char brr[] =  {"bdfh"};
    char r[10];
    join_arrays_2(arr, brr, r);
    printf(r);
}

//13. Dado un el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todo los elementos 
//    anteriores al índice actual: {1,6,12,19,27}.
int Ejercicio13() {
    
}



int main() {
    int s = 0;
    int a;
    while(1 > 0) {
        clrscr();        
        printf("\n--------------Menu--------------\n\n[1] Ejercicio 1\n[2] Ejercicio 2\n[3] Ejercicio 3\n[4] Ejercicio 4\n[5] Ejercicio 5\n[6] Ejercicio 6\n[7] Ejercicio 7\n[8] Ejercicio 8\n[9] Ejercicio 9\n[10] Ejercicio 10\n[11] Ejercicio 11\n[12] Ejercicio 12\n[13] Ejercicio 13\n\n");
        printf("\nSeleccione un ejercicio: ");
        scanf("%d", &s);
        printf("\n-------------\n\n");
        switch (s) {
            case 1:
                Ejercicio1();
                break;
            case 2:
                Ejercicio2();
                break;
            case 3:
                Ejercicio3();
                break;
            case 4:
                Ejercicio4();
                break;
            case 5:
                Ejercicio5();
                break;
            case 6:
                Ejercicio6();
                break;
            case 7:
                Ejercicio7();
                break;
            case 8:
                Ejercicio8();
                break;
            case 9:
                Ejercicio9();
                break;
            case 10:
                Ejercicio10();
                break;
            case 11:
                Ejercicio11();
                break;
            case 12:
                Ejercicio12();
                break;
            case 13:
                Ejercicio13();
                break;
            default:
                printf("ejercicio fuera de rango");
                break;
        }
        printf("\n----------\n\n");
        printf("Introduzca 1 para continuar o 0 para cerrar: ");
        scanf("%d", &a);
        if (a == 0) {
            break;
        }
        printf("\n----------\n\n");
    }
    return 0;
}