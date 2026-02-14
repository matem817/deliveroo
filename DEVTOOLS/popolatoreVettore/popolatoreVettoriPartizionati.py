
print("Inserire la dimensione di una singola partizione: ")
dimPartizione=int(input())

dimPartizione=38
print("Inserire il numero di partizioni: ")
numPartizioni=int(input())

vettore=[""]*numPartizioni
for i in range(numPartizioni):
    print(f"Inserire il valore nella partizione {i}:")
    vettore[i]=input()

print("{")
for i in vettore:
    for j in list(i):
        print(f"\'{j}\',", end="")
    if len(list(i)) > dimPartizione:
        raise Exception("La stringa inserita è più lunga della dimensione della partizione")
    for x in range(dimPartizione - len(list(i))):
        print("\' \',", end="")
    print()
print("}")