import random
import os
filepath = os.getcwd()
n = 100
sources = ['T', 'A', 'G', 'C']
# sources.extend(['*'] * 5)
with open(filepath + "\\in.txt", "w") as file:
    for i in range(n):
        r = random.randint(4, 50)
        c = random.randint(4, 1000)
        file.writelines(f"{r} {c}\n")
        for j in range(r):
            for k in range(c):
                file.write(random.choice(sources))
            file.write('\n')

    
