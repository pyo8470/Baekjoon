colors = {"red" :0 ,"orange": 1,"yellow" : 2,"green" :3,"blue":4,"purple":5}
for t in range(int(input())):
    c1,c2 = map(str,input().split())
    c1_index = colors[c1]
    c2_index = colors[c2]
    # print(c1_index, c2_index)
    if c1 == c2:
        print('E')
    elif (c1_index+1)%6 == c2_index or (c1_index-1)%6 == c2_index:
        print('A')
    elif (c1_index+3)%6 == c2_index:
        print('C')
    else:
        print('X')