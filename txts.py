import random
file1 = open("cosas.txt","a") 
histograma = []
for n in range(0,19):
    file1.write(str(random.uniform(0.0, 100.0)) + " ")

file1.close()

