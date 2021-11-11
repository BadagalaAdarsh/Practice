def find_closest(a, b, num, decreasing_cost, increasing_cost):

    a, b = max(a, b), min(a, b)
    temp = a
    while temp < num:
        temp *= a

    if temp == num:
        return 0

    answer = float('inf')
    while temp > num:
        answer = min(answer, temp - num)
        temp //= a

    


test = int(input())

for i in range(test):
    num = int(input())
    decreasing_cost = int(input())
    increasing_cost = int(input())

    odd_primes = [ 3, 5, 7, 9]

    closest = float('inf')
    for i in range (4):
        for j in range(i+1, 4):
            closest = min(closest, find_closest(odd_primes[i], odd_primes[j], num, decreasing_cost, increasing_cost))
