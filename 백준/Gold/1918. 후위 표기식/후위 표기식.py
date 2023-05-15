def getPriority(i : chr) -> int:
    if(i=='(' or i==')'):
        return 0
    if(i == '+' or i == '-'):
        return 1
    if(i == '*' or i == '/'):
        return 2
infix  = input()
operatorStack = []
postfix = []

for ch in infix:
    ## 연산자인 경우와 비 연산자인 경우 분리
    if(ch.isupper()):
        postfix.append(ch)
    else:
        # 괄호
        if(ch == '('):
        #좌괄호 -> 스택에 푸시
            operatorStack.append(ch)
        #우괄화 
        elif(ch == ')'):
            while(operatorStack[-1] != '('):
                # 후위
                postfix.append(operatorStack.pop())
            operatorStack.pop()
        else:
            if (ch == '+' or ch == '-' or ch == '*' or ch == '/'):
            # 스택이 안비어있고, 스택의 연산자의 우선순위가 들어오는 연산자보다 높은 경우
                while(operatorStack != [] and getPriority(ch) <= getPriority(operatorStack[-1])):
                    postfix.append(operatorStack.pop())
                operatorStack.append(ch)
while(operatorStack!=[]):
    postfix.append(operatorStack.pop())
print("".join(postfix))


