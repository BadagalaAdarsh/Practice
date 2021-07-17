def choose_dish(array,n):

    frequency = [0 for i in range (1001)]
    max = 0
    i = 0

    while i < n - 1:
        
        frequency[array[i]] += 1

        if array[i] == array[i+1]:
            i += 1

        i += 1

    for i in range (1,1001):
        
        if frequency[i] > max:
            max = frequency[i]
            result = i 

    return result

        
def main():

    test = int(input())

    for _ in range (test):

        n = int(input())
        array = list(map(int,input().split()))

        result = choose_dish(array,n)
        print(result)
        
main()
