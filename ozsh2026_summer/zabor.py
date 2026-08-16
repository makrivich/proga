import math,turtle

n=int(input("Число вершин: "))

p=[]
for _ in range(n):
    row=input().split()
    x=float(row[0])
    y=float(row[1])
    p.append((x,y))

p0=p[0]
for x in p:
    if(x[1]<p0[1])or(x[1]==p0[1]and x[0]<p0[0]):
        p0=x

pts_to_sort=[]
for x in p:
    if x!=p0:
        angle=math.atan2(x[1]-p0[1],x[0]-p0[0])
        dist=(x[0]-p0[0])**2+(x[1]-p0[1])**2
        pts_to_sort.append((angle,dist,x))

pts_to_sort.sort()

sp=[]
for item in pts_to_sort:
    sp.append(item[2])

h=[p0]
for x in sp:
    while len(h)>1 and math.atan2(x[1]-p0[1],x[0]-p0[0])==math.atan2(h[-1][1]-p0[1],h[-1][0]-p0[0]):
        h.pop()
    h.append(x)

st=[]
for x in h:
    while len(st)>=2 and(st[-1][0]-st[-2][0])*(x[1]-st[-1][1])-(st[-1][1]-st[-2][1])*(x[0]-st[-1][0])<=0:
        st.pop()
    st.append(x)

m=len(st)
l=0.0
for i in range(m):
    dx=st[(i+1)%m][0]-st[i][0]
    dy=st[(i+1)%m][1]-st[i][1]
    l+=math.hypot(dx,dy)

print(f"\nДлина забора: {l:.2f}\nВершины:")
for x,y in st:
    print(f"({x}, {y})")

min_x,max_x=p[0][0],p[0][0]
min_y,max_y=p[0][1],p[0][1]
for x,y in p:
    if x<min_x:min_x=x
    if x>max_x:max_x=x
    if y<min_y:min_y=y
    if y>max_y:max_y=y

wx=max_x-min_x if max_x!=min_x else 1
wy=max_y-min_y if max_y!=min_y else 1

to_scr=lambda x,y:((x-min_x)/wx*400-200,(y-min_y)/wy*400-200)

t=turtle.Turtle()
t.speed(0)
t.penup()

for x,y in p:
    t.goto(to_scr(x,y))
    t.dot(6)

t.color("red")
t.pensize(2)
t.goto(to_scr(st[0][0],st[0][1]))
t.pendown()

hull_draw=[]
for i in range(1,len(st)):
    hull_draw.append(st[i])
hull_draw.append(st[0])

for x,y in hull_draw:
    t.goto(to_scr(x,y))

t.hideturtle()
turtle.done()