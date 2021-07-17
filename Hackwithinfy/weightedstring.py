def shorteststring():

    di = {}

    li = [1,3]

    for i in range(4,29):
        li.append(i*li[-1])

    li = li[:27]
    x = 0

    for i in range(65,91):
        if li[x] not in di:
            di[li[x]] = chr(i)
            x += 1

    s = ""

    for i in range(26,-1,-1):

        if n//li[i] > 0:
            s += di[li[i]]*(n//li[i])
            n = n%li[i]

    return "".join(sorted(s))


def main():

    n = int(input())

    result = shorteststring(n)
    print(result)

main()

