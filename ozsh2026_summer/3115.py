n=int(input())
c=[0]*100
for _ in range(n):
    row=input().split()
    s=int(row[-1])
    c[s]+=1
m=0
for i in range(100):
    if c[i]>m:
        m=c[i]
res=[]
for i in range(100):
    if c[i]==m:
        res.append(str(i))
print(" ".join(res))