import java.io.*;
import java.util.*;

public class Main {
    static int N, M, K;
    static int x, y;
    /* 동 서 북 남 */
    static int[][] directions = new int[][] { { 0, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
    static int[] commands;
    static int[][] maps;
    /* 1 2 3 4 5 6 */
    /* 반대면 계산 -> 6 - 현재 인덱스 */
    /*
     * [1]
     * [4][0][3] ← 정면에서 보는 주사위 0이 위, 2는 바닥면
     * [5]
     * [2]
     * 
     */
    static int[] dice = new int[6];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        maps = new int[N][M];

        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        K = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                maps[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        commands = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        Solution();
    }

    public static void Solution() {

        int dx, dy;
        for (int i = 0; i < commands.length; i++) {
            int dir = commands[i];
            dx = x + directions[dir][0];
            dy = y + directions[dir][1];
            if (dx < 0 || dx >= N || dy < 0 || dy >= M)
                continue;
            x = dx;
            y = dy;
            // 주사위 굴리기

            rollDice(dir);
            // 현재 숫자
            int num = maps[x][y];
            /* Map에 0이 쓰여져 있을 때 */
            if (num == 0) {
                // 주사위 번호 복사
                maps[x][y] = dice[2];
            } else {
                dice[2] = maps[x][y];
                maps[x][y] = 0;
            }
            System.out.println(dice[0]);
        }
    }

    public static void rollDice(int dir) {
        int[] temp = dice.clone();
        if (dir == 1) { // 동쪽 (→)
            dice[0] = temp[4];
            dice[2] = temp[3];
            dice[3] = temp[0];
            dice[4] = temp[2];
        } else if (dir == 2) { // 서쪽 (←)
            dice[0] = temp[3];
            dice[2] = temp[4];
            dice[3] = temp[2];
            dice[4] = temp[0];
        } else if (dir == 3) { // 북쪽 (↑)
            dice[0] = temp[5];
            dice[1] = temp[0];
            dice[2] = temp[1];
            dice[5] = temp[2];
        } else if (dir == 4) { // 남쪽 (↓)
            dice[0] = temp[1];
            dice[1] = temp[2];
            dice[2] = temp[5];
            dice[5] = temp[0];
        }
    }
}
