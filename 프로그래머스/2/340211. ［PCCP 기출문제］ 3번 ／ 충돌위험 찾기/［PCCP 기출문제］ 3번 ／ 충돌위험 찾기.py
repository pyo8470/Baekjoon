from typing import Tuple, Union, List
from collections import Counter 

class Robot:
    def __init__(self,points):
        self.points: List[List[int,int]] = points
        
        self.progress = 0
        self.n = len(points)-1
        self.pos: List[int,int] = points[0]
    
    @property
    def active(self) -> bool:
        return self.progress<self.n
    
    def move(self):
        if not self.active:
            return
        
        ## 이동할 위치
        r_t,c_t = self.points[self.progress+1]
        ## 현재 위치
        r,c = self.pos
        
        ## 왼쪽으로 이동해야하는 경우
        if r_t < r:
            self.pos[0] -= 1
        elif r_t > r:
            self.pos[0] += 1
        ## 위로 가야할 경우
        elif c_t < c :
            self.pos[1] -= 1
        elif c_t > c :
            self.pos[1] += 1
        
        if self.pos == self.points[self.progress+1]:
            self.progress += 1
        
def solution(points, routes):
    answer = 0
    t = 0
    robots: list[Robot] = []
    for route in routes:
        p = list()
        for idx in route:
            r,c = points[idx-1]
            p.append([r,c])
        robots.append(Robot(p))
    
    ## 모두 움직일 때 까지
    while robots:
        c = Counter()
        for robot in robots:
            c[tuple(robot.pos)] += 1 # list는 hashable하지 않으니 tuple로 변환
        # print(c)
        # 2개 이상의 로봇이 있는 좌표의 수를 찾고 answer에 더함
        for location, v in c.items():
            if v >= 2:
                answer += 1
        # 2. 목표를 이룬 로봇들은 갈 곳이 없으니 제거
        robots = [r for r in robots if r.active]
        for robot in robots:
            robot.move()
    return answer