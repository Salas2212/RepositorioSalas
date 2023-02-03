#Nombre: Juan Esteban Salas
#Codigo: 8975783
#Estructuras de Datos

#=============Tarea 1===============
#Punto 1
#Codigo
def verificarDiagonales(matriz):
    y,z,state=0, -1, True
    for i in range(len(matriz)):
        if matriz[i][y] == matriz[i][z]:
            y+=1
            z-=1
        else:
            state=False
    return state
#Input
mat = [
    [11, 23, 76, 34, 11],
    [14, 30, 92, 30, 101],
    [12, 45, 58, 92, 22],
    [74, 56, 49, 56, 100],
    [99, 5, 28, 47, 99]]
#Output
verificarDiagonales(mat)
#=================================
#Punto 2
#Codigo
def esCapicua(list):
    y=-1
    state=True
    for x in range(len(list)):
        if list[x] == list[y]:
            y-=1
        else:
            state=False
    return state
#Input & Output
esCapicua([42, 12, 90, 90, 12, 42])
#=================================
#Punto 3 A
#Codigo
def diferenciaListas(listA,listB):
    lista=[]
    ban=0
    for a in range(len(listA)):
        state=True
        for b in range(0,len(listB)):
            if state == True:
                if listA[a] == listB[b]:
                    if listA[a] == ban:
                        state=True
                    else:
                        ban=listB[b]
                        state=False
        if state == True:
            lista.append(listA[a])
    return lista
#Input
listaA = [40, 10, 22, 12, 33, 33, 33]
listaB = [41, 22, 31, 15, 13, 12, 33, 19]
#Output 1
diferenciaListas(listaA,listaB)
#Output 2
diferenciaListas(listaB,listaA)

#Punto 3B
#Codigo
def lecturaDatos():
    listAB=[]
    repet=0
    ans=[]
    ejec=int(input())
    ejec=ejec*2
    while ejec != 0:
        n=""
        lista1=[]
        listA=input()
        for i in range(len(listA)):
            if listA[i] != " ":
                n+=listA[i]
            if listA[i] == " " or i == len(listA)-1:
                lista1.append(int(n))
                n=""
        lista1.remove(lista1[0])
        listAB.append(lista1)
        repet+=1
        if repet == 2:
            ans.append(diferenciaListas(listAB[0],listAB[1]))
            listAB=[]
            repet=0
        ejec-=1
    for i in range(len(ans)):
        for j in range(len(ans[i])):
            if j == len(ans[i])-1:
                print(ans[i][j],end="\n")
            else:
                print(ans[i][j],end=", ")
lecturaDatos()
#8 41 22 31 15 13 12 33 19
#7 40 10 22 12 33 33 33
#10 10 11 12 13 14 10 10 12 16 19
#5 10 10 12 12 11
#=================================
#Punto 4
#Codigo
def mostrarPrimos(N):
    primos=[]
    digitos=[]
    for n in range(2,N+1):
        state=0
        for m in range(1,n+1):
            op=n%m
            if op == 0:
                state+=1
        if state == 2:
            primos.append(n)
            if n / 10 < 1:
                digitos.append(n)
            else:
                n=str(n)
                n1=int(n[0])
                n2=int(n[-1])
                sum=n1+n2
                for i in primos:
                    if sum == i:
                        digitos.append(int(n))
    print("Números primos entre 1 y %d:" % N)
    for items in primos:
        print("--> %d," % items)
    print("Números entre 1 y %d con suma de dígitos con valor primo:" % N)
    for items in digitos:
        print(items,end=", ",sep="\n")
#Input & Output
mostrarPrimos(100)
#=================================
#Punto 5
#Codigo
def sumarValoresMatriz(mat,par):
    sum=0
    for i in range(0,len(par)):
        x=0
        v=par[i][x]
        if v in mat:
            x+=1
            for j in range(len(mat[v])):
                if par[i][x] == mat[v][j][0]:
                    sum+=mat[v][j][1]
    return print(sum)

#Input
disp = {0 : [(0, 1), (5, 4), (7, 5)],
1 : [(6, 4), (7, 7)],
2 : [(0, 2), (1, 2), (4, 9), (6, 1)],
4 : [(2, 8), (3, 1), (5, 7)],
6 : [(0, 3), (5, 6), (7, 2)],
7 : [(0, 4), (1, 4), (2, 7)],
8 : [(1, 9), (3, 8), (5, 7), (7, 6)]}
#Output
sumarValoresMatriz(disp, [(0, 0), (8, 3), (3, 5), (7, 2), (4, 3), (4,6)])
