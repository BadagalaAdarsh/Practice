# QUESTION:1- Add and Concatenation of List

#### A string of comma separated numbers are given such that the numbers 4 and 7 are already present in the list. Assume that 7 always comes after 4 in the given string. 
#### Case-1: num1= add all numbers which do not lie between 4 and 7 in the input( excluding 4 and 7).
#### Case-2: num2= numbers formed by concatenating all numbers from 4 to 7(including 4 and 7)
#### Return the sum of num1 and num2
#### Constraints:
#### 47 <= num1+num2 <= 10^9
#### Sample Testcase:
#### Input:
#### 3,1,6,4,2,3,7,2
#### Output:
#### 4249
#### Input:
#### 4,7
#### Output:
#### 47


```python
def addAndConcatenate( inputstr ):
    #converting the string into list of numbers
    listOfNums = list(map(int,inputstr.split(",")))
    
    
    #getting num1 from adding digits before 4 and after 7
    num1 = sum(listOfNums[:listOfNums.index(4)]) + sum(listOfNums[listOfNums.index(7)+1:])
    
    
    #extracting digits and concatenating them including 4 and 7
    digitsOfNum2 = listOfNums[listOfNums.index(4):listOfNums.index(7)+1]
    
    
    #to concatenate create an empty string for num2
    num2=""
    
    #iterating each digit
    for digit in digitsOfNum2:
        #concatenating to form num2
        num2 += str(digit)
        
    #converting string num2 into integer and adding with number and returning it
    return int(num2)+num1

# Main Function
if __name__ == '__main__':
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the  function
    print(addAndConcatenate(inputstr))

```

# QUESTION:2- Remove duplicates and reverse

#### A string is given, remove duplicates from the string and reverse the string having no duplicate values. Return the reversed string.
#### ~input string contains both lowercase and UPPERCASE letters
#### ~The ouput should be case-sensitive i.e, ‘a’ and ‘A’ are not same.

#### Constraints:
#### 	1 <= string.length <= 10^7
#### Sample Testcase:
#### Input: infosys
#### Output: ysofni

#### Input: google
#### Output: elog


```python
def removeDuplicatesAndReverse(inputstr):
    #remove duplicates using the dict.fromkeys()
    listOfCharacters = list(dict.fromkeys(inputstr))
    
    
    #reverse the string
    listOfCharacters.reverse()
    
    
    #convert the list into string and return it.
    return "".join(listOfCharacters)

# Main Function
if __name__ == '__main__':
    # Taking the input for the problem
    inputstr = input()
    
    
    # Calling the removeDuplicatesAndReverse function
    # Printing the result
    print(removeDuplicatesAndReverse(inputstr))

```

# QUESTION:3- OTP Generator

#### A number as a string is given as an input, separate odd places integers from it. Square the digits at that odd places and return the first four digits.

#### Constraints:
#### 1 <= digit <= 9
#### 10 <= len(num_string) <= 10^7

#### Sample Testcase:
#### Input: 5624381275
#### Output: 3616

#### Explanation:
#### Getting digits at odd places= 6, 4, 8, 2, 5
#### Square the numbers= 36, 16, 64, 4, 25
#### OTP should be 1st 4 digits=3616


```python
def OTPGenerator(num_string):
    
    length = len(num_string)
    result = ""
    
    
    #getting odd indexes values
    for odd_index in range(1,length,2):
        
        #concatenate the square value of odd index digit
        result += str(int(num_string[odd_index])**2)
        if len(result)>=4:
            break
    
    #print the first 4 digits
    print(result[:4])

# Main Function
if __name__ == '__main__':
    
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the OTPGenerator function
    OTPGenerator(inputstr)

```

# QUESTION:4- Largest Even Number

#### Given a string as input, containing both characters, numerals and special characters. Take each integer from it only once and from the largest even number possible. Print largest even number possible and if the number can’t be made, then print -1.

#### Constraints:
#### 	-1 <= Number <= 10^9
#### Sample Testcase:
#### Input: asdf@75483
#### Output: 87534

#### Input: infytq351739
#### Output: -1


```python
def evenLargestNumber(input_string):
    
    #separating digits and removing duplicates
    digits = [i for i in set(input_string) if i.isdigit()]
    
    
    #sort digits
    digits.sort()
    
    #reverse digits
    digits.reverse()
    
    #forming number
    num = int(''.join(digits))

    print(num)
    #if even print
    if(num%2 == 0):
        return num
    
    #if odd then
    else:
        length = len(digits)
        #traversing from end
        
        for i in range(length-1, 0, -1):
            
            #finding least even
            if int(digits[i])%2 == 0:
                a = digits[i]
                #removing from digits
                
                digits.remove(a)
                digits.insert(length-1,a)
                even = int(''.join(digits))
                return even
        else:
            return -1

# Main Function
if __name__ == '__main__':
    
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the evenLargestNumber function
    print(evenLargestNumber(inputstr))


```

# QUESTION:5- Valid Parenthesis

#### A non-empty string is given containing only brackets {,},[,],(,). If the brackets are properly nested return 0, if brackets are not properly nested, return unbalanced position adding one to it.

#### Constraints:
#### 1 <= sequence.length <= 10^6

#### Sample Testcase:
#### Input:
#### {([])}[]
#### Output:
#### 0

#### Input:
#### {{[]}}}
#### Output:
#### 7

#### Input:
#### {([])][]
#### Output:
#### 6


```python
def validParanthesis(input_str):
    
    stack = []
    counter = 0
    
    #iterating each bracket
    for brac in input_str:
        if(brac == '[' or brac == '{' or brac == '('):
            stack.append(brac)
            counter += 1
            continue
            
        #if character is a closed bracket and stack is empty return that position+1
        if(len(stack) == 0):
            return counter+1
        
        #pop if closed
        bracOut = stack.pop()
        
        #checking for correct nesting
        if( brac == ']' and bracOut == '['):
            counter += 1
        elif( brac == '}' and bracOut == '{'):
            counter += 1
        elif( brac == ')' and bracOut == '('):
            counter += 1
        else:
            return counter+1
        
        
    if(len(stack) == 0):
        return 0
    else:
        return counter+1

# Main Function
if __name__ == '__main__':
    
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the validParanthesis function
    print(validParanthesis(inputstr))

```

# QUESTION:6- Password Generator

#### Find the maximum digit from code which is less than or equal to(<=) the length of name and put the place char in the final string,  if there is no any digit found which satisfies the given condition then simply put ‘X’. Then return the formed string.

#### Constraints:
#### 	0 <= digit <= 10^9
#### 	1 <= name.length <= 20
#### 	1 <= inputString.length <= 10^7

#### Sample Testcase:
#### Input:
#### Anchal:23581,Aman:57568,Sonakshi:34848,Ria:14585
#### Output:
#### aXiR

#### Input:
#### Sonakshi:34848,Naman:4739,Prachi:2949,Ekta:9889
#### Output:
#### iacX


```python
def passwordgenerator(inputstr):
    
    #taking an empty string for storing result
    result = ""
    
    # separating each character and code by splitting
    char_codes = inputstr.split(",")
    
    # iterating each charcode pair in char_codes and getting string and code
    for charCode in char_codes:
        string , num = charCode.split(":")
        #find the length of string
        length = len(string)
        #initializing the sum to zero
        maxDigit = 0
        
        for digit in num:
            #finding the maximum digit which is less than or equal to the length of string
            if(int(digit) <= length and int(digit) >= int(maxDigit)):
                maxDigit = digit
        
        #if no digit satisfies the condition
        if maxDigit == 0:
            result += 'X'
        
        #placing the character in the final result string
        else:
            result += string[int(maxDigit)-1]
    
    #return the result
    return result

# Main Function
if __name__ == '__main__':
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the passwordgenerator function
    print(passwordgenerator(inputstr))




```

# QUESTION:7- Character Shifting

#### Find the sum of square of digits from code. If the sum of squares of digits of code are:
####   EVEN- Then add the last 2 characters in the beginning
####   ODD- Then add first character at the end

#### Constraints:
#### 	0 <= sum <= 10^9

#### Sample Testcase:
#### Input :
#### abcd:1234,bcdgfhf:127836,sdjks:1245
#### Output:
####  cdab cdgfhfb kssdj



```python
def generatecode(inputstr) : #inputstr is a string
    
    # separating each character and code by splitting
    char_codes = inputstr.split(",")
    
    #iterating each charcode pair in char_codes and getting string and code
    for charCode in char_codes:
        string , num = charCode.split(":")
        
        #find the length of string
        length = len(string)
        
        #initializing the sum to zero
        sumOfSquares = 0
        
        #iterating through each digit into the num
        for digit in num:
            
            #as digit is character convert into integer and find square of it and add it to the sum
            sumOfSquares += (int(digit)**2)
            
        #finding if it is even
        if(sumOfSquares % 2 == 0):
            
            #slicig string from index 2 to till end
            s = string[length-2:length]
            
            #concatenating the first 2 characters at the end
            print(s + string[0:length-2],end=" ")
        else:
            #getting the first character of the string
            s = string[0]
            
            #concatenating the last character with remaining part at end
            print(string[1:length]+s, end=" ")

# Main Function
if __name__ == '__main__':
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the generatecode function
    generatecode(inputstr)

```

# QUESTION:8- Longest Prefix also suffix

#### Given a string, find length of the longest prefix which is also suffix. The prefix and suffix should not be overlap.

#### Constraints:
#### 	1 <= string.length <= 2*10^6

#### Sample Testcases:
#### Input:
#### abcdabc
#### Output:
#### 3

#### Input:
#### ababa
#### Output:
#### 1


```python
def longestPrefixSuffix(input_string):
    
    #finding length
    length = len(input_string)
    
    #getting mid index
    mid = length//2
    
    #iterating from length of mid to 0
    for i in range(mid,0,-1):
        
        #getting prefix
        prefix = input_string[0:i]
        
        #getting suffix
        suffix = input_string[length-i:length]
        
        #comparing, if same return
        if(prefix == suffix):
            return len(prefix)

# Main Function
if __name__ == '__main__':
    
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the longestPrefixSuffix function
    print(longestPrefixSuffix(inputstr))
```

# QUESTION:9- Minimum distinct elements

#### Given a size representing the lenght of the list of numbers and string which is a combination of repeated and distant elements which are space separated and number of elements that can be deleted X, you have to delete any X elements from the list so that list will have minimum distinct number.

#### Input Format :
#### First line contains the size of the list
#### Second line contains the string of numbers of given size seperated with space
#### Third line contains the value X
 
#### Constraints:
#### 0 <= size <= 10^9
####  0 <= number <= 10^9
#### 0 <= X <= size

#### Sample Testcase:

#### Input:
#### 10
#### 1 1 1 2 2 3 3 4 5 6
#### 4
#### Output:
#### 3

#### Input:
#### 9
#### 1 1 1 2 2 2 4 5 6
#### 3
#### Output:
#### 2


```python
def minimumDistinctElements(X, input_str):
    
    #making into a list
    list_num = list(map(int,input_str.split(" ")))
    
    #a list to store the frequency of each value
    list_count = []
    
    #getting unique elements
    unique = set(list_num)
    
    for num in unique:
        
        #finding the frequency
        count = list_num.count(num)
        
        #appen to list
        list_count.append(count)
        
        #sorting the frequencies
        
    list_count.sort()
    length = len(list_count)
    
    for cnt in list_count:
        
        #comparing with each of frequency
        if(cnt <= X):
            X -= cnt
            length -= 1
        else:
            break
    
    #returning the length
    return length

# Main Function
if __name__ == '__main__':
    
    # Taking the input for the problem
    size = int(input())
    inputstr = input()
    X = int(input())
    
    # Calling the minimumDistinctElements function
    print(minimumDistinctElements(X, inputstr))
```

# QUESTION:10- Minimum Consecutive Number

#### Input a matrix, check if we do get the same number consecutively at least 4 times in any fashion, horizontally, vertically and diagonally. Record those sets. If we get multiple values, then print minimum of them, And if no such consecutive numbers then print -1.

#### Constraints:
#### 	6 <= rows, columns <= 100
#### 	0 <= matrix[row][col] <= 9
#### Sample Testcase:
#### Input: 6 6
####             1 3 3 3 3 9
####             1 6 9 2 3 9
####             1 2 2 5 4 9
####             2 2 4 5 7 9
####             2 4 5 6 7 2
####             1 2 3 4 5 6
#### Output: 2


```python
def minimumConsecutiveNumbers(row, col, matrix):
    
    #traversing the matrix
    for i in range(row):
        for j in range(col):
            if(j < col-3):
                #for consecutive numbers in all rows
                
                if(matrix[i][j] == matrix[i][j+1] == matrix[i][j+2] ==matrix[i][j+3]):
                    
                    #if equal we can add into list num
                    list_num.append(matrix[i][j])
            if (i < row - 3):
                # for consecutive numbers in all cols
                
                if (matrix[i][j] == matrix[i+1][j] == matrix[i+2][j] == matrix[i+3][j]):
                    
                    # if equal we can add into list num
                    list_num.append(matrix[i][j])
                    
            if (j < col - 3 and i>=3):
                # for consecutive numbers in all right to left diagonals
                
                if (matrix[i][j] == matrix[i-1][j + 1] == matrix[i-2][j + 2] == matrix[i-3][j + 3]):
                    # if equal we can add into list num
                    list_num.append(matrix[i][j])
                    
            if (j >=3 and i>=3):
                # for consecutive numbers in all left to right diagonals
                
                if (matrix[i][j] == matrix[i-1][j - 1] == matrix[i-2][j-2] == matrix[i-3][j-3]):
                    # if equal we can add into list num
                    list_num.append(matrix[i][j])
                    
    if(len(list_num)==0):
        return -1
    
    else:
        #minimum element is returned
        return min(list_num)

if __name__=="__main__":
    
    # obtaining the rows and column sizes
    row, col = map(int, input().split(" "))
    
    # used to store all the consecutive elements
    list_num = []
    matrix = []
    
    for i in range(row):
        row_no = list(map(int, input().split(" ")))
        matrix.append(row_no)
        
    print(minimumConsecutiveNumbers(row, col, matrix))

```

# QUESTION:11 - Longest Fibonocci Subset

#### Given a comma separated string with positive numbers and the task is to find the largest subset from array that contain elements which are fibonacci numbers. If more than two elements exist then print its length else print -1.
#### It contains repeated numbers too.
#### Constraints:
#### 	0 <= num <= 10^9

#### Sample Testcase:
#### Input: 3, 2, 2, 8, 9, 10, 8
#### Output:5

#### Input:2, 6, 3, 5, 8, 9
#### Output: 4


```python
def largestSubsetOfFibanocciNumbers(inputstr):
    
    # Converting the string of numbers into list of numbers
    arr = list(map(int,inputstr.split(",")))
    
    # sorting the array
    arr.sort()
    
    # Storing the maximum number
    maxNumber = arr[-1]
    
    # Initialisng the num1 and num2 with first two fibanocci numbers 0,1
    num1, num2 = 0,1
    
    # Declaring fibanocciList to store the fibanocci numbers
    fibanocciList = []
    fibanocciList.append(num1)
    fibanocciList.append(num2)
    
    # Storing all the fibanocci numbers upto maxNum in fibanocciList
    while(num2 <= maxNumber):
        sum = num1 + num2
        num1, num2 = num2, sum
        
        # Storing the fibanocci number in the fibanocciList
        fibanocciList.append(num2)
        
    # Declaring a fibanocciSequence list to store the fibanocci numbers in the given array
    fibanocciSequence = []
    
    # Looping through all the elements in the list
    for index in range(len(arr)):
        
        # If arr[index] is a fibanocci number
        if arr[index] in fibanocciList:
            
            # Then append it to the fibanocci sequence
            fibanocciSequence.append(arr[index])
            
    # If fibanocciSequence Contains more than 2 elements
    if len(fibanocciSequence) > 2:
        
        # Then print its length
        print(len(fibanocciSequence))
    else:
        
        # else print -1
        print(-1)

# Main Function
if __name__ == '__main__':
    
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the largestSubsetOfFibanocciNumbers function
    largestSubsetOfFibanocciNumbers(inputstr)
```

# QUESTION:12 - Alternate even odd

#### Given a string containing atleast one special character, one even and odd digit, return an output string based on number of special characters as below:

#### If the number of special characters is odd, append all the odd digits and even digits alternatively to the output string, starting with odd digit.

#### If the number of special characters is even, append all the even digits and odd digits alternatively to the output string, starting with even digit.

#### After arranging the digits based on the above two points, if there are any additional digits remaining, append them at end of output string

#### Constraints:
#### 	3 <= string.length <= 10^7

#### Sample Testcase:
#### Input: A5c67r21i@p#8t
#### Output: 652781

#### Input:h93@5213#w4rld&
#### Output: 9234513


```python
def alternateEvenWord(inputstr):
    
    # Declaring evenList and oddList to store respective numbers
    evenList, oddList = [], []
    
    # Initialising the specialCharCount to 0
    specialCharsCount = 0
    
    # Declaring the result string
    result = ""
    
    # Iterating through each character in the inputstr
    for character in inputstr:
        
        # If character is not alphabet and number
        # i.e, if it is a special character
        if not(character.isalnum()):
            
            # Then increment the specialCharsCount
            specialCharsCount += 1
            
        # If character is a digit
        elif character.isdigit():
            
            # If digit is an even number
            if int(character)%2 == 0:
                
                # Append it to the evenList
                evenList.append(character)
            else:
                
                # Else Append it to the oddList
                oddList.append(character)
                
    # If the special character count is odd
    if specialCharsCount%2 != 0:
        
        # swap the contents of evenList and oddList
        # i.e, oddList contains even numbers and viceversa
        oddList, evenList = evenList, oddList
        
    # Initialising the size with maximum length of evenList or oddList
    size = max(len(evenList), len(oddList))
    
    # Running the loop till the index reaches the Size
    for index in range(size):
        
        # If index value < length of evenList then append the digit to result
        # If specialCharCount is odd evenList Contains odd numbers so first they will be appended
        # or else it contains even numbers and they are appended first and viceversa.
        if index < len(evenList):
            
            # converting the int type to str type to concatenate with the result
            result += str(evenList[index])
            
        if index < len(oddList):
            
            # converting the int type to str type to concatenate with the result
            result += str(oddList[index])
            
    # returning the result
    return result

# Main Function
if __name__ == '__main__':
    
    # Taking the input for the problem
    inputstr = input()
    
    # Calling the alternateEvenWord function
    print(alternateEvenWord(inputstr))
```

# QUESTION:13 -Pronic number

#### Given a string of random numbers, your job is to find all the substrings which are pronic numbers and print the output with comma separated.
#### If there are no substrings which are pronic numbers then print -1

#### A pronic number is a number which is the product of two consecutive integers, that is, a number of the form n(n + 1) and n>1. Like 6 is the pronic number as 2*3 = 6.
#### The pronic numbers are : 2,6,12,20,30,42,56,72,90,…..

#### Constraints:
#### 1 <= number <= 10^9

#### Sample Testcases :
#### Input : 
#### 123456
#### Output : 
#### 2,6,12,56
#### Input:
#### 13579
#### Output:
#### -1


```python
# Importing math library to make use of sqrt function
import math

def ispronic(number):
    
    # finding the square root of the number
    x = math.floor(number**0.5)
    
    # If it is a pronic number then
    if x*(x+1) == number:
        return True
    else:
        return False

def pronicNumbers(inputstr):
    
    # Declaring a list to store all the substrings in the inputstr
    allSubstrings = []
    
    for i  in range(len(inputstr)):
        for j in range(i,len(inputstr)):
            
            # Storing the substring inputstr[i....j]
            allSubstrings.append(inputstr[i:j+1])
            
    # Declaring pronicNums list to store the pronic Numbers
    pronicNums = []
    
    # Iterating through each number in the allSubstrings list
    for number in allSubstrings:
        
        # Converting the number(str type) into int type
        num = int(number)
        
        # if number is greater than 0 and
        # if it is a pronic number and if it doesn't exit in the list(not duplicate value)
        
        if num>0 and ispronic(num) and num not in pronicNums:
            
            # Appending it to the pronic Numbers List
            pronicNums.append(int(number))

    # Sorting the list
    pronicNums.sort()

    if len(pronicNums)>0:
        
        # printing the list with comma separated
        print(*pronicNums,sep=',')
    else:
        print("-1")

# Main Function
if __name__=='__main__':
    
    # Taking the input
    inputstr = input()
    
    # Calling the function
    pronicNumbers(inputstr)
```

# QUESTION:14 -Identify max count of zeros

#### Consider a non-zero positive decimal number, inputnum, an integer base greater than 1 and print outputnum, the maximum number of consecutive set of zeroes after converting inputnum to its base notation. Print -1  if there exists no zero after conversion of inputnum.

#### Constraints:

####     2 <= base <= 10
####     1 <= number  <= 10^9

#### Sample Testcase:
#### Input: 
#### 64
#### 2
#### Output: 
#### 6


```python
# function to convert a number into a particular base
def conversion(number, base):
    output = ""
    while number > 0:
        # finding remainder and adding the value to output
        value = int(number % base)

        if value < 10:
            output += str(value)
        else:
            output += chr(ord('A') + value - 10)
        # decreasing the value by base after every iteration
        number //= base

    output = output[::-1]
    return output

# function to calculate count of consectuive zeros
def countOfConsectuiveZeros():
    
    # input number
    number = int(input())
    
    # value of base number input
    base = int(input())
    
    # calling function for conversion into required base
    convertedValue = conversion(number, base)

    count = 0
    outnum = 0
    
    for i in range(len(convertedValue)):
        # if value is not zero then reset count to zero else increment count
        
        if convertedValue[i] != '0':
            count = 0
        else:
            count += 1
            outnum = max(outnum, count)
            
    # printing output
    if outnum > 0:
        print(outnum)
    else:
        print('-1')


if __name__ == '__main__':
    # calling the below function which takes input and prints output
    countOfConsectuiveZeros()
```

# QUESTION:15- Nearest greatest palindrome

#### Given a number as input. Write a program to find the next greatest palindrome for the given number.

#### Constraints:
#### 1 <= num <= 10^9

#### Sample Testcase:

#### Input: 
#### 12300
#### Output: 
#### 12321
#### Input : 
#### 1221
#### Output : 
#### 1221


```python
# function to find nearest greatest nearest_palindrome
def nearest_palindrome(number):
    
    # increasing the value of number and checking for palindrome
    while True:
        
        # checking palindrome
        
        reverse = int(str(number)[::-1])
        if reverse == number:
            return int(number)
        number += 1


def greatestNearestPalindrome():
    number = int(input())
    print(nearest_palindrome(number))


if __name__ == '__main__':
    # calling the below function which takes input and prints output
    greatestNearestPalindrome()
```
