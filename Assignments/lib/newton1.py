import math

def f1(x): 
    return math.cos(x[1] * x[0]) - math.exp(-3 * x[2]) + x[3] * x[4] ** 2 - x[5] - math.sinh(2 * x[7]) * x[8] + 2 * x[9] + 2.000433974165385440

def f2(x): 
    return math.sin(x[1] * x[0]) + x[2] * x[8] * x[6] - math.exp(-x[9] + x[5]) + 3 * x[4] ** 2 - x[5] * (x[7] + 1) + 10.886272036407019994

def f3(x): 
    return x[0] - x[1] + x[2] - x[3] + x[4] - x[5] + x[6] - x[7] + x[8] - x[9] - 3.1361904761904761904

def f4(x): 
    return 2 * math.cos(-x[8] + x[3]) + x[4] / (x[2] + x[0]) - math.sin(x[1] ** 2) + math.cos(x[6] * x[9]) ** 2 - x[7] - 0.1707472705022304757

def f5(x): 
    return math.sin(x[4]) + 2 * x[7] * (x[2] + x[0]) - math.exp(-x[6] * (-x[9] + x[5])) + 2 * math.cos(x[1]) - 1.0 / (-x[8] + x[3]) - 0.3685896273101277862

def f6(x):
    return math.exp(x[0] - x[3] - x[8]) + x[4] ** 2 / x[7] + math.cos(3 * x[9] * x[1]) / 2 - x[5] * x[2] + 2.0491086016771875115

def f7(x):
    return x[1] ** 3 * x[6] - math.sin(x[9] / x[4] + x[7]) + (x[0] - x[5]) * math.cos(x[3]) + x[2] - 0.7380430076202798014

def f8(x):
    return x[4] * (x[0] - 2 * x[5]) ** 2 - 2 * math.sin(-x[8] + x[2]) + 0.15e1 * x[3] - math.exp(x[1] * x[6] + x[9]) + 3.5668321989693809040

def f9(x):
    return 7 / x[5] + math.exp(x[4] + x[3]) - 2 * x[1] * x[7] * x[9] * x[6] + 3 * x[8] - 3 * x[0] - 8.4394734508383257499

def f10(x):
    return x[9] * x[0] + x[8] * x[1] - x[7] * x[2] + math.sin(x[3] + x[4] + x[5]) * x[6] - 0.78238095238095238096

def f1dx1(x):
    return -x[1] * math.sin(x[1] * x[0]) 
def f1dx2(x):
    return -x[0] * math.sin(x[1] * x[0])
def f1dx3(x):
    return 3 * math.exp(-3 * x[2])
def f1dx4(x):
    return x[4] ** 2
def f1dx5(x):
    return 2 * x[3] * x[4]
def f1dx6(x):
    return -1 
def f1dx7(x):
    return 0 
def f1dx8(x):
    return -2 * math.cosh(2 * x[7]) * x[8] 
def f1dx9(x):
    return -math.sinh(2 * x[7])
def f1dx10(x):
    return 2

def f2dx1(x):
    return x[1] * math.cos(x[1] * x[0]) 
def f2dx2(x):
    return x[0] * math.cos(x[1] * x[0]) 
def f2dx3(x):
    return x[8] * x[6] 
def f2dx4(x):
    return 0 
def f2dx5(x):
    return 6 * x[4]
def f2dx6(x):
    return -math.exp(-x[9] + x[5]) - x[7] - 1
def f2dx7(x):
    return x[2] * x[8] 
def f2dx8(x):
    return -x[5] 
def f2dx9(x):
    return x[2] * x[6]
def f2dx10(x):
    return math.exp(-x[9] + x[5])

def f3dx1(x):
    return 1 
def f3dx2(x):
    return -1 
def f3dx3(x):
    return 1 
def f3dx4(x):
    return -1 
def f3dx5(x):
    return 1 
def f3dx6(x):
    return -1 
def f3dx7(x):
    return 1 
def f3dx8(x):
    return -1 
def f3dx9(x):
    return 1 
def f3dx10(x):
    return -1

def f4dx1(x):
    return -x[4] / (x[2] + x[0]) ** 2 
def f4dx2(x):
    return -2 * x[1] * math.cos(x[1] ** 2)
def f4dx3(x):
    return -x[4] / (x[2] + x[0]) ** 2 
def f4dx4(x):
    return -2 * math.sin(-x[8] + x[3])
def f4dx5(x):
    return 1.0 / (x[2] + x[0]) 
def f4dx6(x):
    return 0 
def f4dx7(x):
    return -2 * math.cos(x[6] * x[9]) * x[9] * math.sin(x[6] * x[9]) 
def f4dx8(x):
    return -1
def f4dx9(x):
    return 2 * math.sin(-x[8] + x[3]) 
def f4dx10(x):
    return -2 * math.cos(x[6] * x[9]) * x[6] * math.sin(x[6] * x[9])

def f5dx1(x):
    return 2 * x[7] 
def f5dx2(x):
    return -2 * math.sin(x[1]) 
def f5dx3(x):
    return 2 * x[7] 
def f5dx4(x):
    return 1.0 / (-x[8] + x[3]) ** 2 
def f5dx5(x):
    return math.cos(x[4])
def f5dx6(x):
    return x[6] * math.exp(-x[6] * (-x[9] + x[5])) 
def f5dx7(x):
    return -(x[9] - x[5]) * math.exp(-x[6] * (-x[9] + x[5])) 
def f5dx8(x):
    return 2 * x[2] + 2 * x[0]
def f5dx9(x):
    return -1.0 / (-x[8] + x[3]) ** 2 
def f5dx10(x):
    return -x[6] * math.exp(-x[6] * (-x[9] + x[5]))

def f6dx1(x):
    return math.exp(x[0] - x[3] - x[8]) 
def f6dx2(x):
    return -1.5 * x[9] * math.sin(3 * x[9] * x[1]) 
def f6dx3(x):
    return -x[5] 
def f6dx4(x):
    return -math.exp(x[0] - x[3] - x[8])
def f6dx5(x):
    return 2 * x[4] / x[7] 
def f6dx6(x):
    return -x[2]
def f6dx7(x):
    return 0
def f6dx8(x):
    return -x[4] ** 2 / x[7] ** 2 
def f6dx9(x):
    return -math.exp(x[0] - x[3] - x[8]) 
def f6dx10(x):
    return -1.5 * x[1] * math.sin(3 * x[9] * x[1])

def f7dx1(x):
    return math.cos(x[3]) 
def f7dx2(x):
    return 3 * x[1] ** 2 * x[6] 
def f7dx3(x):
    return 1 
def f7dx4(x):
    return -(x[0] - x[5]) * math.sin(x[3]) 
def f7dx5(x):
    return x[9] / x[4] ** 2 * math.cos(x[9] / x[4] + x[7])
def f7dx6(x):
    return -math.cos(x[3]) 
def f7dx7(x):
    return x[1] ** 3 
def f7dx8(x):
    return -math.cos(x[9] / x[4] + x[7]) 
def f7dx9(x):
    return 0 
def f7dx10(x):
    return -1.0 / x[4] * math.cos(x[9] / x[4] + x[7])

def f8dx1(x):
    return 2 * x[4] * (x[0] - 2 * x[5]) 
def f8dx2(x):
    return -x[6] * math.exp(x[1] * x[6] + x[9]) 
def f8dx3(x):
    return -2 * math.cos(-x[8] + x[2]) 
def f8dx4(x):
    return 1.5
def f8dx5(x):
    return (x[0] - 2 * x[5]) ** 2 
def f8dx6(x):
    return -4 * x[4] * (x[0] - 2 * x[5]) 
def f8dx7(x):
    return -x[1] * math.exp(x[1] * x[6] + x[9]) 
def f8dx8(x):
    return 0 
def f8dx9(x):
    return 2 * math.cos(-x[8] + x[2])
def f8dx10(x):
    return -math.exp(x[1] * x[6] + x[9])

def f9dx1(x):
    return -3 
def f9dx2(x):
    return -2 * x[7] * x[9] * x[6]
def f9dx3(x):
    return 0 
def f9dx4(x):
    return math.exp(x[4] + x[3]) 
def f9dx5(x):
    return math.exp(x[4] + x[3])
def f9dx6(x):
    return -7.0 / x[5] ** 2 
def f9dx7(x):
    return -2 * x[1] * x[7] * x[9] 
def f9dx8(x):
    return -2 * x[1] * x[9] * x[6] 
def f9dx9(x):
    return 3 
def f9dx10(x):
    return -2 * x[1] * x[7] * x[6]

def f10dx1(x):
    return x[9] 
def f10dx2(x):
    return x[8] 
def f10dx3(x):
    return -x[7] 
def f10dx4(x):
    return math.cos(x[3] + x[4] + x[5]) * x[6] 
def f10dx5(x):
    return math.cos(x[3] + x[4] + x[5]) * x[6]
def f10dx6(x):
    return math.cos(x[3] + x[4] + x[5]) * x[6] 
def f10dx7(x):
    return math.sin(x[3] + x[4] + x[5]) 
def f10dx8(x):
    return -x[2] 
def f10dx9(x):
    return x[1] 
def f10dx10(x):
    return x[0]
