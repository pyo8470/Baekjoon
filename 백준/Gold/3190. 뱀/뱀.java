import java.io.*;
import java.util.*;

public class Main {
    static int N, K, L;
    static int[][] board;
    static Map<Integer, Character> directionChanges;
    static int[][] directions = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } }; // 오른쪽, 아래, 왼쪽, 위 (시계 방향);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int row = Integer.parseInt(st.nextToken());
            int col = Integer.parseInt(st.nextToken());
            board[row - 1][col - 1] = 1;
        }

        // 자기 자신의 몸은 2
        board[0][0] = 2;

        /* L -> 왼쪽 90도 회전, D -> 오른쪽 90도 회전 */
        L = Integer.parseInt(br.readLine());
        directionChanges = new HashMap<>();
        for (int i = 0; i < L; i++) {
            st = new StringTokenizer(br.readLine());
            int time = Integer.parseInt(st.nextToken());
            char dir = st.nextToken().charAt(0);
            directionChanges.put(time, dir);
        }
        System.out.println(Solution());
    }

    public static int Solution() {
        /* 오른쪽 방향으로 시작 */
        int time = 0, dir = 0;
        Deque<int[]> snake = new LinkedList<>();
        snake.add(new int[] { 0, 0 });
        int x = 0, y = 0;
        while (true) {
            time++;
            /* 방향 변경 여부 */
            x += directions[dir][0];
            y += directions[dir][1];
            /* 자기 몸과 부딪히는 경우 + 벽에 부딪힐 경우 */
            if (x < 0 || x >= N || y < 0 || y >= N || contains(snake, x, y))
                return time;
            // 뱀 추가
            snake.addFirst(new int[] { x, y });
            /* 다음 칸에 사과가 없는 경우 */
            if (board[y][x] != 1) {
                // 꼬리 삭제
                snake.removeLast();
            } else {
                // 아니라면 사과 먹었으니 삭제
                board[y][x] = 0;
            }
            /* 방향 전환 체크 */
            if (directionChanges.containsKey(time)) {
                char turn = directionChanges.get(time);
                if (turn == 'D') {
                    dir = (dir + 1) % 4;
                } else {
                    dir = (dir + 3) % 4;
                }
            }
        }
    }

    static boolean contains(Deque<int[]> snake, int x, int y) {
        for (int[] pos : snake) {
            if (pos[0] == x && pos[1] == y)
                return true;
        }
        return false;
    }
}
