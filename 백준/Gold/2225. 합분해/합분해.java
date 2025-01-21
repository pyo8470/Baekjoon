import java.io.*;
import java.util.*;

public class Main {

    static int N, K;
    // 각 행에 퀸 하나만 나오게 한다.
    static int answer = 0;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        br.close();
        /* dp[N][K] = dp[N-1][K] + dp[N][K-1] */
        dp = new int[N + 1][K + 1];
        for (int i = 0; i <= N; i++) {
            dp[i][1] = 1; // K=1일 때 모든 dp[n][1] = 1
        }
        for (int i = 0; i <= K; i++) {
            dp[0][i] = i; // N=0일 때 dp[0][k] = k
        }
        for (int n = 1; n < N; n++) {
            for (int k = 2; k <= K; k++) {
                dp[n][k] = (dp[n - 1][k] + dp[n][k - 1]) % 1_000_000_000;
            }
        }
        System.out.println(dp[N - 1][K]);
    }
}
