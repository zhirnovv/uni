xa, ya = map(int, input("Координаты точки A: ").split())
xb, yb = map(int, input("Координаты точки B: ").split())
xc, yc = map(int, input("Координаты точки C: ").split())

if ((xb <= xa and xa <= xc) or (xc <= xa and xa <= xb)) and ((xa-xb)*(yc-yb) - (ya-yb)*(xc-xb)) == 0:
    print ('да')
else:
    print('нет') 

