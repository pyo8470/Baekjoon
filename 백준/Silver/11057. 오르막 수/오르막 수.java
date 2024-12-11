
import java.io.*;
import java.util.*;

public class Main {

    // static BufferedWriter bw = new BufferedWriter(new
    // OutputStreamWriter(System.out));
    static long[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(br.readLine());
        dp = new long[N + 1][10];

        Arrays.fill(dp[1], 1L);

        for (int i = 2; i <= N; i++) {
            dp[i][0] = Arrays.stream(dp[i - 1]).sum() % 10007;
            for (int j = 1; j < 10; j++) {
                // 음수를 고려하여 10007더해줌
                dp[i][j] = (dp[i][j - 1] % 10007 - dp[i - 1][j - 1] % 10007 + 10007) % 10007;
            }
        }
        System.out.println(Arrays.stream(dp[N]).sum() % 10007);
    }
}