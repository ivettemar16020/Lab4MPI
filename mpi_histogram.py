from mpi4py import MPI
import random 


histograma = [] 



comm = MPI.COMM_WORLD
rank = comm.Get_rank()



file1 = open("cosas.txt","r+")  

print(file1.read())



print(histograma)
print('My rank is ',rank)