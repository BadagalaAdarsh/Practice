def ispossible(a,b,c,x,y):
    if (a+b+c) != (x + y):
        return "NO"

    elif ( y < min(a, min(b,c))) or (x < min(a, min(b,c))):
        return "NO"

    return "YES"


def main():

    test = int(input())

    for _ in range (test):

        a,b,c,x,y = map(int,input().split())

        result = ispossible(a,b,c,x,y)

        print(result)

main()
