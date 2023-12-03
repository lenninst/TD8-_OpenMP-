#include <iostream>
#include <omp.h>

void subdomain(float* x, int istart, int ipoints)
{
   for (int i = 0; i < ipoints; i++)
      x[istart + i] = 123.456;
}

void sub(float* x, int npoints)
{
   int iam, nt, ipoints, istart;

#pragma omp parallel default(shared) private(iam, nt, ipoints, istart)
   {
      iam = omp_get_thread_num();
      nt = omp_get_num_threads();

#pragma omp single
      {
         ipoints = npoints / nt;
         std::cout << "Particiones \n" << ipoints << std::endl;
      }

      istart = iam * ipoints;

      if (iam == nt - 1)
         ipoints = npoints - istart;

#pragma omp barrier

#pragma omp single
      {
         std::cout << "Inicia Asignacion" << std::endl;
      }

      subdomain(x, istart, ipoints);
   }
}

int main()
{
   float array[1000]; 
   sub(array, 1000);

   return 0;
}
