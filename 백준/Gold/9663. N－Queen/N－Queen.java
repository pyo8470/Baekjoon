import java.io.*;
import java.util.*;

public class Main {

    static int N;
    // 각 행에 퀸 하나만 나오게 한다.
    static int[] Board;
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        N = Integer.parseInt(br.readLine());
        Board = new int[N];
        // board[row] = col; -> row 행의 col열에 놓임
        Solution(0);
        System.out.println(answer);
    }

    public static void Solution(int row) {
        if (row == N) {
            answer++;
            return;
        }
        // 세로열 체크
        for (int col = 0; col < N; col++) {
            if (isValid(row, col)) {
                Board[row] = col;
                Solution(row + 1);
            }
        }
    }

    public static boolean isValid(int row, int col) {
        // 대각선 or 같은 열
        /* 대각선 특징 -> 현재 위치의 row col과 다음 위치의 row col의 차이가 같다 */
        for (int i = 0; i < row; i++) {
            if (Board[i] == col || Math.abs(Board[i] - col) == Math.abs(i - row)) {
                return false;
            }
        }
        return true;
    }
}
