#include <iostream>
#include <omp.h>

void simple(int n, float* a, float* b)
{
   int i;

#pragma omp parallel for
   for (i = 1; i < n; i++)
   {
      std::cout << "Hilo" << omp_get_thread_num()
         << ": Procesando iteracion" << i << std::endl;

      b[i] = (a[i] + a[i - 1]) / 2.0;

      std::cout << "Hilo" << omp_get_thread_num()
         << ":  Iteraticion completa " << i << std::endl;
   }
}

int main()
{
   const int size = 5;
   float input[size] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
   float output[size];

   int num_threads;
   std::cout << "Definir la cantidad de hilos: ";
   std::cin >> num_threads;

   // Establecer el número de hilos manualmente
   omp_set_num_threads(num_threads);

   std::cout << "Main: Se inicio la operacion en paralelo con: "
      << num_threads << " hilos" << std::endl;

   simple(size, input, output);

   std::cout << "Main: La operacion en paralelo se completo" << std::endl;

   std::cout << "A. Input: ";
   for (int i = 0; i < size; i++)
      std::cout << input[i] << " ";
   std::cout << std::endl;

   std::cout << "B. Output: ";
   for (int i = 0; i < size; i++)
      std::cout << output[i] << " ";
   std::cout << std::endl;

   return 0;
}
