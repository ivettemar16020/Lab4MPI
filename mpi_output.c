/* File:     mpi_output.c
 *
 * Purpose:  A program in which multiple MPI processes try to print 
 *           a message.
 *
 * Compile:  mpicc -g -Wall -o mpi_output mpi_output.c
 * Usage:    mpiexec -n<number of processes> ./mpi_output
 *
 * Input:    None
 * Output:   A message from each process
 *
 * IPP:      Section 3.3.1  (pp. 97 and ff.)
 */
#include <stdio.h>
#include <mpi.h> 

int main(int argc, char **argv) {
   int my_rank, comm_sz, flag, i;
   char message[] = "Alguien tiene un palillo?";

   MPI_Init(&argc, &argv); 
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 

   if (my_rank == 0) {
      MPI_Send(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
      printf("1 SIZE = %d RANK = %d MESSAGE = %s \n",comm_sz,my_rank, message);
    } else {
        int buffer;
        MPI_Status status;
        MPI_Probe(MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        MPI_Get_count(&status, MPI_INT, &buffer);
      if (buffer == 1) {
        printf("2 SIZE = %d RANK = %d MESSAGE = %s \n",comm_sz,my_rank, message);
        MPI_Recv(&message, buffer, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
          if (my_rank + 1 != comm_sz) {
          MPI_Send(&message, 1, MPI_INT, ++my_rank, 0, MPI_COMM_WORLD);
          }
        };
      };

      //printf("Proc %d of %d Alguien tiene un palillo?\n", my_rank, comm_sz);
   

   MPI_Finalize();
   return 0;
}  /* main */
