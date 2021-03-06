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
  int my_rank, comm_sz, i;

  MPI_Init(NULL, NULL); 
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); 
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
  for(i = comm_sz - 1; i>= 0; i--){
    MPI_Barrier(MPI_COMM_WORLD);
    if (i == my_rank){
      printf("Proc %d of %d > Alguien tiene un palillo?\n", my_rank, comm_sz);
    }
  }

   MPI_Finalize();
   return 0;
}  /* main */
