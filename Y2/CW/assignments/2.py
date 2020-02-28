count = 0
for i1 in range(0, 10):
    for j1 in range(0, 10):
        for k1 in range(0, 10):
            for i2 in range(0, 10):
                for j2 in range(0, 10):
                    for k2 in range(0, 10):
                        if (i1 + j1 + k1 == i2 + j2 + k2):
                            count += 1

print(count)
