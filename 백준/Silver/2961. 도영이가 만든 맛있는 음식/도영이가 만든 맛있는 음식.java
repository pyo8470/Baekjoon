import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[][] Material;
    static int answer = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        N = Integer.parseInt(br.readLine());
        Material = new int[N][2];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            Material[i][0] = Integer.parseInt(st.nextToken());
            Material[i][1] = Integer.parseInt(st.nextToken());
        }
        Solution();
        System.out.println(answer);
    }

    public static void Solution() {
        // 길이가 1인 조합부터 시작
        for (int i = 1; i <= N; i++) {
            Combinations(0, 0, i, 1, 0);
        }
    }

    public static void Combinations(int start, int depth, int length, int sour, int bitterness) {
        if (depth == length) {
            answer = Math.min(answer, Math.abs(sour - bitterness));
            return;
        }

        for (int i = start; i < N; i++) {
            Combinations(i + 1, depth + 1, length, sour * Material[i][0], bitterness + Material[i][1]);
        }
    }
}
