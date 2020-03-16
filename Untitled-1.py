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

x = [0,0,0,0,0]
print(contar(18.9, x))

print(contar(18.9, x))

