
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int M, N, K;
    static int[][] grid;
    static boolean[][] visited;
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    // static BufferedWriter bw = new BufferedWriter(new
    // OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Main.grid = new int[N][M];
        visited = new boolean[N][M];
        List<Integer> answer = new ArrayList<>();
        int x1, x2, y1, y2;
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            x1 = Integer.parseInt(st.nextToken());
            y1 = Integer.parseInt(st.nextToken());
            x2 = Integer.parseInt(st.nextToken());
            y2 = Integer.parseInt(st.nextToken());
            // 어차피 좌표를 알맞게 맞출 필요는 없을듯
            for (int x = x1; x <= x2 - 1; x++) {
                for (int y = y1; y <= y2 - 1; y++) {
                    grid[y][x] = 1;
                }
            }
        }

        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                if (grid[y][x] == 0 && !visited[y][x]) {
                    int num = bfs(x, y);
                    answer.add(num);
                }
            }
        }
        Collections.sort(answer);
        System.out.println(answer.size());
        answer.forEach(num -> System.out.print(num + " "));
        br.close();
    }

    private static int bfs(int x, int y) {
        int count = 1;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] { x, y });
        visited[y][x] = true;
        while (!queue.isEmpty()) {
            int[] data = queue.poll();
            int curX = data[0];
            int curY = data[1];

            for (int index = 0; index < 4; index++) {
                int nextX = curX + dx[index];
                int nextY = curY + dy[index];

                if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
                    if (!visited[nextY][nextX] && grid[nextY][nextX] == 0) {
                        queue.add(new int[] { nextX, nextY });
                        visited[nextY][nextX] = true;
                        count++;
                    }
                }
            }   
        }
        return count;
    }

}