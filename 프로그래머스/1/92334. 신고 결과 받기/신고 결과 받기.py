def solution(id_list, report, k):
    answer = [0] * len(id_list)
    ## 중복 제거
    report = set(report)
    ## 각 유저가 신고 당한 횟수
    reportedCount = {key : 0 for key in id_list}
    
    for query in report:
        reporter, reported = query.split()
        ## 신고 당한 사람의 count +=1
        reportedCount[reported]+=1
    for query in report:
        reporter, reported = query.split()
        ## 신고 횟수 넘어 섬
        if reportedCount[reported] >= k:
            answer[id_list.index(reporter)] +=1
    return answer