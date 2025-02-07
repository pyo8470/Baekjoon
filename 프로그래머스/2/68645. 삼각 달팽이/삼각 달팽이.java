import java.util.*;
class Solution {
    // 상,하,좌,우
    // 실제 배열에서의 방향 -> 하, 우, 좌상 반복
    static int[] dx = {0,1,-1};
    static int[] dy = {1,0,-1};
    public int[] solution(int n) {
        List<Integer> answer = new ArrayList();
        int[][] snail = new int[n][n];
        int sum = n*(n+1)/2; 
        int x=0,y=0;
        // 초기 방향은 아래
        int dir = 0;
        for(int i=1; i<=sum; i++){
            snail[y][x] = i;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=n || snail[ny][nx] != 0){
                dir = (dir+1)%3;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            x = nx;
            y = ny;
            // 다음이 벽이거나 0인 경우 방향 전환
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(snail[i][j] != 0){
                    answer.add(snail[i][j]);
                }
            }
        }
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}