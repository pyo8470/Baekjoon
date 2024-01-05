# def solution(genres, plays):
#     answer = []
#     k = {k : 0 for k in genres}
#     know = {k : [] for k in genres}
#     for i in range(len(plays)):
#         k[genres[i]] += plays[i]
#         know[genres[i]].append([i,plays[i]])
#     k = dict(sorted(k.items(), key=lambda item: item[1], reverse=True))
#     result = {}
#     for num, value in know.items():
#         sorted_songs = sorted(value, key=lambda x: x[1], reverse=True)
#         result[num] = sorted_songs
#     for GENRE, SUM in k.items():
#         length = len(result[GENRE])
#         if length >= 2:
#             for i in range(2):
#                 answer.append(result[GENRE][i][0])
#         else:
#             answer.append(result[GENRE][0][0])
                
#     return answer

def solution(genres, plays):
    answer = []
    genre_sum = {}  # 장르별 총 재생 횟수
    genre_songs = {}  # 장르별 노래 정보
    
    # 각 장르의 총 재생 횟수와 노래 정보 초기화
    for i in range(len(plays)):
        genre_sum[genres[i]] = genre_sum.get(genres[i], 0) + plays[i]
        genre_songs[genres[i]] = genre_songs.get(genres[i], []) + [(i, plays[i])]

    # 장르별 총 재생 횟수로 내림차순 정렬
    sorted_genres = sorted(genre_sum.items(), key=lambda x: x[1], reverse=True)

    # 정렬된 장르 순서대로 노래 선택
    for genre, _ in sorted_genres:
        songs = sorted(genre_songs[genre], key=lambda x: x[1], reverse=True)
        ## :2이지만 원소가 하나라면 한개까지만 가져온다
        answer.extend([song[0] for song in songs[:2]])

    
    return answer
