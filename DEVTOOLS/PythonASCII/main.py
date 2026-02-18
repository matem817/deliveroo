
with open("input.txt", "r") as f:
    lines = f.readlines()

output:list[str] =[]
for i in lines:
    y: str = ""
    for x,j in  enumerate(i):
        j=j.replace('\\','\\\\')
        y+=j
    output.append(y)
for i,e in enumerate(output):
    if i==0:
        print(f"cout<<\"{e.strip('\n')}\"<<endl")
    elif i==len(lines)-1:
        print(f"    <<\"{e.strip('\n')}\"<<endl;")
    else:
        print(f"    <<\"{e.strip('\n')}\"<<endl")