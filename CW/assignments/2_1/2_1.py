f = open("in.txt", "r")
a, b = map(int, f.read().split())
f.close()

print(a, b)

sieve = [True] * (b-1)

for i in range(b-1):
    for j in range(i+1, len(sieve)):
        if (j + 2) % (i + 2) == 0:
            sieve[j] = False

primes = []

for i in range(a-2, b-1):
    if sieve[i] == True:
        primes.append(i+2)

f = open("out.txt", "w")
f.write(str(primes))
f.close
