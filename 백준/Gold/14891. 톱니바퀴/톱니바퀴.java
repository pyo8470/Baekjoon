import java.io.*;
import java.util.*;

public class Main {
    static int K;
    static char[][] wheel = new char[4][8];
    static int[][] rotation;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int answer = 0;
        for (int i = 0; i < 4; i++) {
            wheel[i] = br.readLine().toCharArray();
        }

        K = Integer.parseInt(br.readLine());
        rotation = new int[K][2];
        for (int i = 0; i < K; i++) {
            rotation[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }
        Solution();
        for (int i = 0; i < 4; i++) {
            answer += (1 << i) * (wheel[i][0] - '0');

        }
        System.out.println(answer);
    }

    /**
     * N극 -> 0, S극 -> 1
     * rotation[0] -> 회전시킨 톱니바퀴의 번호
     * rotation[1] -> 방향(1: 시계 방향, -1: 반시계 방향)
     * 
     * 회전시키기 전, 극이 다르다면 -> 반대로 회전하게 된다
     * 3시 인덱스 : 2, 9시 인덱스 -> 6
     */

    private static void Solution() {
        int num;
        for (int i = 0; i < K; i++) {
            num = rotation[i][0] - 1;
            int[] direction = new int[4];
            direction[num] = rotation[i][1];

            /* 회전 전파 */
            // 왼쪽
            for (int k = num; k > 0; k--) {
                if (wheel[k][6] != wheel[k - 1][2]) {
                    direction[k - 1] = -direction[k];
                }
                // 같은 극 일 경우 바로 멈추기
                else
                    break;
            }
            // 오른쪽
            for (int k = num; k < 3; k++) {
                if (wheel[k][2] != wheel[k + 1][6]) {
                    direction[k + 1] = -direction[k];
                } else
                    break;
            }

            for (int k = 0; k < 4; k++) {
                if (direction[k] != 0)
                    rotate(k, direction[k]);
            }
        }
    }

    private static void rotate(int idx, int dir) {
        char[] temp = Arrays.copyOf(wheel[idx], 8);
        /* 시계 방향 회전 */
        if (dir == 1) {
            for (int i = 1; i < 8; i++) {
                wheel[idx][i] = temp[i - 1];
            }
            wheel[idx][0] = temp[7];
        } else {
            for (int i = 0; i < 7; i++) {
                wheel[idx][i] = temp[i + 1];
            }
            wheel[idx][7] = temp[0];
        }
    }
}
