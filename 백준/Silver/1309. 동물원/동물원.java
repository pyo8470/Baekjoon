
import java.io.*;
import java.util.*;

public class Main {

    // static BufferedWriter bw = new BufferedWriter(new
    // OutputStreamWriter(System.out));
    static long[][] dp;

    /*
     * dp[][0] -> [o|x]
     * dp[][1] -> [x|o]
     * dp[][2] -> [x|x]
     * 
     * 각 모양으로 사자를 놓을 수 있는 경우의 수
     * 0번의 경우 이전 칸의 모양이 x|o, x|x인 경우에만 넣을 수 있음
     * 1번의 경우 이전 칸의 모양이 o|x, x|x인 경우에만 넣을 수 있음
     * 2번의 경우 언제나 가능
     * 
     * dp[n][0] = dp[n-1][1] + d[n-1][2]
     * dp[n][1] = dp[n-1][0] + d[n-1][2]
     * dp[n][2] = dp[n-1][0] + dp[n-1][1] + d[n-1][2]
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(br.readLine());
        dp = new long[N + 1][3];
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = 1;

        int mod = 9901;
        for (int n = 2; n <= N; n++) {
            dp[n][0] = (dp[n - 1][1] + dp[n - 1][2]) % mod;
            dp[n][1] = (dp[n - 1][0] + dp[n - 1][2]) % mod;
            dp[n][2] = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % mod;
        }

        System.out.println(Arrays.stream(dp[N]).sum() % mod);
    }
}