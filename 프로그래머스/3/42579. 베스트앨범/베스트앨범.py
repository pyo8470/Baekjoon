def solution(genres, plays):
    answer = []
    k = {k : 0 for k in genres}
    know = {k : [] for k in genres}
    for i in range(len(plays)):
        k[genres[i]] += plays[i]
        know[genres[i]].append([i,plays[i]])
    k = dict(sorted(k.items(), key=lambda item: item[1], reverse=True))
    result = {}
    for num, value in know.items():
        sorted_songs = sorted(value, key=lambda x: x[1], reverse=True)
        result[num] = sorted_songs
    for GENRE, SUM in k.items():
        length = len(result[GENRE])
        if length >= 2:
            for i in range(2):
                answer.append(result[GENRE][i][0])
        else:
            answer.append(result[GENRE][0][0])
                
    return answer