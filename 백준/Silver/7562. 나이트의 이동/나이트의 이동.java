
import java.io.*;
import java.util.*;

public class Main {
    static boolean [][] visited;
    static int L;
    static int[] dx = new int[]{-2,-1,1,2,2,1,-1,-2};
    static int[] dy = new int[]{-1,-2,-2,-1,1,2,2,1};
    // static BufferedWriter bw = new BufferedWriter(new
    // OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        int answer;
        for(int i=0; i<T; i++){
            L = Integer.parseInt(br.readLine());
            int x,y,goalX,goalY;
            visited = new boolean[L][L];
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken()); 
            y = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            goalX = Integer.parseInt(st.nextToken());
            goalY = Integer.parseInt(st.nextToken());
            answer = bfs(x,y,goalX,goalY);
            System.out.println(answer);
        }
    }

    public static int bfs(int x,int y,int goalX,int goalY){
        if ( x == goalX && y== goalY) return 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x,y,0});
        visited[y][x] = true;

        while(!queue.isEmpty()){
            int[] data = queue.poll();
            int curX = data[0], curY = data[1], curCount = data[2];
            if ( curX == goalX && curY== goalY){
                    return curCount;
            }
            // 체스의 8방향
            for(int idx = 0; idx <8; idx++){
                int nextX = curX + dx[idx];
                int nextY = curY + dy[idx];
                
                // 좌표 유효성 검사
                if (nextX>=0 && nextX<L && nextY>=0 && nextY <L){
                    if(!visited[nextY][nextX]){
                        queue.add(new int[]{nextX,nextY,curCount + 1});
                        visited[nextY][nextX] = true;
                    }
                }
            }
        }
        return -1;
    }
}