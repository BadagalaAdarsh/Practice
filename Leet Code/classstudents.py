
def rank(subjects, student_1, student_2, student_3):
    

    mark_1 = sum(student_1)
    mark_2 = sum(student_2)
    mark_3 = sum(student_3)

    array = [mark_1,mark_2,mark_3]

    array.sort()
    array = array[::-1]

    for i in range(3):
        if mark_1 == array[i]:
            one = i+1 

        if mark_2 == array[i]:
            two = i+1 

        if mark_3 == array[i]:
            three = i+1 

    print(one, two, three)

def main():
    subjects = int(input())
    student_1 = list(map(int,input().split()))
    student_2 = list(map(int,input().split()))
    student_3 = list(map(int,input().split())) 
    rank(subjects,student_1, student_2, student_3)

main()
