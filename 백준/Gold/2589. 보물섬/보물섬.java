import java.io.*;
import java.util.*;

public class Main {
    static int w, h;
    static char[][] board;
    static int answer = 0;
    /** 상하좌우 */
    static int[][] directions = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());

        h = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());

        board = new char[h][w];
        for (int i = 0; i < h; i++) {
            board[i] = br.readLine().toCharArray();
        }
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (board[y][x] != 'W')
                    Solution(x, y, 0);
            }
        }
        System.out.println(answer);
    }

    /**
     * W : 바다
     * L : 육지
     * 
     * 최단거리 -> 너비우선 탐색
     * 보물 -> 최단 거리 중 가장 먼 곳(브루트 포스)
     * 
     **/
    private static void Solution(int x, int y, int dis) {
        boolean[][] visited = new boolean[h][w];
        Deque<int[]> q = new ArrayDeque<int[]>();
        q.addFirst(new int[] { x, y, dis });
        int dx, dy;
        visited[y][x] = true;
        while (!q.isEmpty()) {
            int[] location = q.removeFirst();
            x = location[0];
            y = location[1];
            dis = location[2];
            /* 상하좌우 움직임 */
            for (int i = 0; i < 4; i++) {
                dx = x + directions[i][0];
                dy = y + directions[i][1];
                if (dx < 0 || dx >= w || dy < 0 || dy >= h || visited[dy][dx] || board[dy][dx] == 'W')
                    continue;
                visited[dy][dx] = true;
                q.addLast(new int[] { dx, dy, dis + 1 });
            }
        }
        answer = Math.max(answer, dis);
    }
}
