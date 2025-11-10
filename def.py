def f(a,b,n,m):
    if n>m: return False
    if a+b>=41:
        if n%2==0: return True
        else: return False
    k=[f(a+1, b+2, n+1, m), f(a+2, b+1, n+1, m), f(a*2, b, n+1, m), f(a,b*2, n+1, m)]
    return any(k)
for s in range(1,33):
    if f(8,s,0,2):
        print(s)
