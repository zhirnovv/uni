x1, y1 = map(int, input("Координаты точки А: ").split())
x2, y2 = map(int, input("Координаты точки B: ").split())
delta = x1 * y2 - x2 * y1

if delta < 0:
    print("A")
elif delta > 0:
    print("B")
else:
    print("Углы равны")
