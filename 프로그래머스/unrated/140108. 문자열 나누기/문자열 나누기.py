def solution(s):
    x=s[0]
    isX=1
    notX=0
    List = [x]
    for i in range(1,len(s)):
        if isX == notX:
            x=s[i]
            isX=0
            notX=0
            List.append(x)
        if x == s[i] :
            isX +=1
        elif x != s[i]:
            notX +=1
    return len(List)