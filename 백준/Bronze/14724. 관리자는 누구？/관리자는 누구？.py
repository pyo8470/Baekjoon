import sys
input = sys.stdin.readline

N = int(input())
solved = [list(map(int, input().split())) for _ in range(9)]
candidate = ['PROBRAIN', 'GROW', 'ARGOS', 'ADMIN', 
             'ANT', 'MOTION', 'SPG', 'COMON', 'ALMIGHTY']

# 각 리스트의 최댓값과 그 인덱스를 찾기
max_index = max(range(9), key=lambda i: max(solved[i]))

# 최댓값을 가진 리스트의 이름 출력
print(candidate[max_index])
