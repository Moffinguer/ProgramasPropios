n=0
b=1
t=int(input("Introduzca numero: "))
q=int(input("Introduzca numero: "))
n=t*1000
n=n*t
while q>0:
    if not q%2==0:
        b=b*t
    q=q//2
    t=t*t
print(b)
