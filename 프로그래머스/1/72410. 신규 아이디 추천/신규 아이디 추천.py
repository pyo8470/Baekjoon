
    
        
def solution(new_id):
    periodCount = 0
    answer = ''
    ## 1단
    new_id=new_id.lower()
    
    ## 2단
    temp = ''
    for i in new_id:
        if i.isdigit() or i.islower() or i == '-' or i =='_' or i =='.':
            temp +=i
    new_id=temp
    ## 3단
    while '..' in new_id:
        new_id = new_id.replace('..','.')
    
    ## 4단
    new_id = new_id.strip('.')
    ## 5단
    if new_id == '':
        new_id = 'a'
        
    ## 6단
    if len(new_id) >= 16:
        new_id = new_id[:15]
        new_id = new_id.rstrip('.')
    
    ## 7단
    length = len(new_id)
    if length <=2:
        k = new_id[-1]
        for i in range(length,3):
            new_id+=k
    return new_id