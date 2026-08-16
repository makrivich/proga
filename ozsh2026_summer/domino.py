n=int(input("Количество: "))
d=[tuple(map(int,input().split()))for _ in range(n)]
deg={}
for u,v in d:
    deg[u]=deg.get(u,0)+1
    deg[v]=deg.get(v,0)+1

odd=[k for k,v in deg.items()if v%2!=0]
if len(odd)not in(0,2):
    print("Составить связную цепочку невозможно.")
else:
    s=odd[0]if odd else d[0][0]
    u_e=[False]*n
    st=[s]
    ch=[]
    while st:
        c=st[-1]
        f=False
        for i,(u,v)in enumerate(d):
            if not u_e[i]:
                if u==c:
                    u_e[i]=True
                    st.append(v)
                    f=True
                    break
                elif v==c:
                    u_e[i]=True
                    st.append(u)
                    f=True
                    break
        if not f:
            x=st.pop()
            if st:
                ch.append((st[-1],x))
    if len(ch)==n:
        ch.reverse()
        print(" : ".join(f"{u}-{v}"for u,v in ch))
    else:
        print("Составить связную цепочку невозможно.")