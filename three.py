def findbase(m):

    global array 
    
    

    if m == 1:
        return "INFINITY"

    ans = (m+1)//2;
    p = m//2 + 1; 

    for i in range (2,41):
        ans = ans+ (array[i].index(m+1) - array[i].index(p))

    return ans



def main():

    array = [[] for i in range (47)]
    
    global array

    for i in range (2,int(1e6+1)):
        tem = i 

        for j in range(2,41):
            tem *= i 

            if tem > 1e12:
                break 

            array[j].append(tem)

    test = int(input())

    for _ in range (test):

        m = int(input()) 

        result = findbase(m)

        print(result)

main()

