# Fill list n with zero
n = [0] * (2000+5)
n[ 0 ] = 1
n[ 1 ] = 3

for i in range(2, 2005):
    n[ i ] = 3 * n[i - 1] - n[i - 2]

while True:
    x = int(input())
    if x == 0:
        break
    print(n[ x ])