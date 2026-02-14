dimOpzione=eval(input("Inserire la dimensione di un'opzione: "))
with open("input.txt", "r") as f:
    lines = f.readlines()
if len(lines) < 54:
    raise Exception("Il numero di opzioni inserite non è sufficiente, inserire almeno 54 opzioni")
print("{")
for i in lines:
    for j in list(i):
        print(f"\'{j}\',", end="")
    if len(list(i)) > dimOpzione:
        raise Exception("La stringa inserita è più lunga della dimensione della partizione")
    for x in range(dimOpzione - len(list(i))):
        print("\' \',", end="")
    print()
print("}")