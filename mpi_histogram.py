from mpi4py import MPI
import random 
import numpy as np


def contar(x, lista):
    if x <= 20:
        lista[0] +=1
    if x <=40 and x >20:
        lista[1] +=1
    if x <=60 and x>40:
        lista[2] +=1
    if x <=80 and x>60:
        lista[3] +=1
    if x<=100 and x>80:
        lista[4] +=1
    return lista
##thread1   thread2  thread3   thread4
##[[0-20], [21, 40], [41-60], [61-80]]
file1 = open("cosas.txt","r+")  

histograma = file1.read().split(" ")
npa = np.asarray(histograma, dtype=np.float32)

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()


numDataPerRank = 20 
sendbuf = histograma[rank*numDataPerRank+1:(rank+1)*numDataPerRank]
lista = [0,0,0,0,0]
for i in sendbuf:
    lista=contar(float(i), lista)


print('Proceso: ',rank, ', (0-20), (21-40), (41-60), (61-80), (81-100): ',lista)

if rank == 0:
    print("(0-20), (21-40), (41-60), (61-80), (81-100)")

        
 