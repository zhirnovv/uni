source = int(input("Введите число: "))
sieve = [True] * (source-1)

for i in range(source-1):
    if sieve[i] == False:
        continue
    print(i+2)
    for j in range(i+1, len(sieve)):
        if (j + 2) % (i + 2) == 0:
            sieve[j] = False

representation = []

while sieve[source-2] != True:
    for i in range(source-2):
        if (source % (i+2) == 0) and sieve[i] == True:
            source //= (i + 2)
            representation.append(str(i+2))
            break
    print(source)
    if (source == 1):
        break

representation.append(str(source))
print(representation)

print(' * '.join(representation))
