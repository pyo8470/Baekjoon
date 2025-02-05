import java.io.*;
import java.util.*;

public class Main {
    static int R, C, T;
    static int[][] room;

    // 상하좌우
    static int[] dx = { 0, 0, -1, 1 };
    static int[] dy = { -1, 1, 0, 0 };

    static int robotUpperY;
    static int robotLowerY;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        room = new int[R][C];
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                room[i][j] = Integer.parseInt(st.nextToken());
                if (room[i][j] == -1) {
                    // 로봇의 아랫 부분
                    robotLowerY = i;
                }
            }
        }
        robotUpperY = robotLowerY - 1;
        for (int t = 0; t < T; t++) {
            Solution();
        }

        int sum = 0;
        for (int[] r : room) {
            sum += Arrays.stream(r).sum();
        }
        System.out.println(sum + 2);

    }
    /*
     * 1. 미세먼지 확산 (공청기 x 칸 x인 경우) 미세먼지 량 A
     * 1-1. 인접한 네 방향(상하좌우)
     * 1-2. 확산량 해당 칸 1/5(int) : 1/5 * A
     * 1-3. 남은량 A-(1/5*A)* 확산 칸
     * 2. 공청기 작동
     * 2-1. 바람(위쪽 -> 반시계, 아래쪽 -> 시계방향 순환)
     * 2-2. 바람 -> 미세먼지가 바람의 방향대로 모두 한 칸씩 이동
     * 2-3. 공청기로 들어간 미세먼지 -> 모두 정화
     */

    static private void Solution() {
        room = dustSimulation();
        airSimulation();

    }

    static private int[][] dustSimulation() {
        int[][] temp = new int[R][C];

        int nx, ny;
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (room[y][x] == -1) {
                    temp[y][x] = -1;
                    continue;
                }

                // 상하좌우
                int dust = room[y][x];
                if (dust == 0)
                    continue;
                int spread = (int) dust / 5;
                int sum = 0;
                for (int i = 0; i < 4; i++) {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    // 탈출조건
                    if (nx < 0 || nx >= C || ny < 0 || ny >= R || room[ny][nx] == -1)
                        continue;
                    temp[ny][nx] += spread;
                    sum += spread;
                }
                temp[y][x] += (dust - sum);
            }
        }
        return temp;
    }

    static private void airSimulation() {
        // 위쪽 순환 시작
        // 우 상 좌 하, 따라서 역순으로 계산 시작
        // 하
        for (int y = robotUpperY - 1; y > 0; y--) {

            room[y][0] = room[y - 1][0];
        }

        // 좌
        for (int x = 0; x < C - 1; x++) {
            room[0][x] = room[0][x + 1];
        }
        // 상
        for (int y = 0; y < robotUpperY; y++) {

            room[y][C - 1] = room[y + 1][C - 1];
        }
        // 우
        for (int x = C - 1; x > 0; x--) {
            room[robotUpperY][x] = room[robotUpperY][x - 1];
        }

        // 공청기 들어감
        room[robotUpperY][1] = 0;
        // 아래쪽 순환 (우 하 좌 상)
        // 상 (왼쪽 끝)
        for (int y = robotLowerY + 1; y < R - 1; y++) {

            room[y][0] = room[y + 1][0];
        }
        // 좌(맨 아래)
        for (int x = 0; x < C - 1; x++) {
            room[R - 1][x] = room[R - 1][x + 1];
        }
        // 하(오른쪽 끝)
        for (int y = R - 1; y > robotLowerY; y--) {

            room[y][C - 1] = room[y - 1][C - 1];
        }
        // 우
        for (int x = C - 1; x > 0; x--) {
            room[robotLowerY][x] = room[robotLowerY][x - 1];
        }

        room[robotLowerY][1] = 0;

    }
}
