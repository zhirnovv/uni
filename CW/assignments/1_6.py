n = int(input("n: "))
population = [0] * n

for i in range(n):
    population[i] = int(input(str(i+1) + ": "))

possible = False
print(population)

for i in range(n):
    population.sort(reverse=True)
    if population[0] > n-1:
        possible = False
        break

    if population[0] == 0:
        continue

    for j in range(1, n):
        if (population[j] != 0):
            population[0] -= 1
            population[j] -= 1
        else:
            continue

        if (population[0] == 0):
            break

    print(population)

    if population[0] != 0:
        possible = False
        break
    else:
        possible = True

if not possible:
    print("невозможно")
else:
    print("возможно")


