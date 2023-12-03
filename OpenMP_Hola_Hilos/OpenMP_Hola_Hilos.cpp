#include <stdio.h>
#include <omp.h>

int main() {
    int numeroHilos;
    printf("Ingresar el numero de hilos: ");
    scanf_s("%d", &numeroHilos);

    // Obtener el número de procesadores disponibles en el sistema
    int numeroProcesadores = omp_get_num_procs();
    printf("Este computador usa %d procesador(es)\n", numeroProcesadores);

    // Establecer el número de hilos a usar en la región paralela
    omp_set_num_threads(numeroHilos);
    printf("En este ejemplo se desea usar %d hilo(s)\n", numeroHilos);
    printf("En este momento se esta(n) ejecutando %d hilo(s)\n", omp_get_num_threads());

    printf("\nAcabo de entrar a la seccion paralela\n");

    // Región paralela, donde cada hilo ejecuta el siguiente bloque de código en paralelo
#pragma omp parallel
    {
        // Obtener el ID del hilo actual
        int idHilo = omp_get_thread_num();
        // Imprimir un mensaje desde cada hilo
        printf("Hola, soy el hilo %d, en este momento se esta(n) ejecutando %d hilo(s)\n", idHilo, omp_get_num_threads());
    }

    printf("Acabo de salir de la seccion paralela\n");

    printf("\nEn este momento se esta(n) ejecutando %d hilo(s)\n", omp_get_num_threads());
    return 0;
}
