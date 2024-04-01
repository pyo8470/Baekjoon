def solution(answers):
    answer = []
    person1 = [1, 2, 3, 4, 5]
    person2 = [2, 1, 2, 3, 2, 4, 2, 5]
    person3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    result = [0,0,0]
    i,j,k = 0,0,0
    for number in answers:
        if person1[i] == number:
            result[0]+=1
        i+=1
        if person2[j] == number:
            result[1]+=1
        j+=1
        if person3[k] == number:
            result[2]+=1
        k+=1
        i = 0 if i >= len(person1) else i
        j = 0 if j >= len(person2) else j
        k = 0 if k >= len(person3) else k
    maxGrade = max(result)
    for i in range(3):
        if maxGrade == result[i]:
            answer.append(i+1)
    return answer