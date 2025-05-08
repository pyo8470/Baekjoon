

T = 10
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    buildings = list(map(int,input().split()))
    length = len(buildings)
    answer = []
    for i in range(2,length-2):
        temp = []
        for j in range(1,3):
            current = buildings[i]
            surLeft = buildings[i-j]
            surRight = buildings[i+j]
            temp.append(max(0,current - surLeft))
            temp.append(max(0,current - surRight))
        answer.append(min(temp))
    print(f"#{test_case} {sum(answer)}")