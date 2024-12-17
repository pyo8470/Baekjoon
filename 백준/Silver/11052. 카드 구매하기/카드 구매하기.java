
import java.io.*;
import java.util.*;

public class Main {

    // static BufferedWriter bw = new BufferedWriter(new
    // OutputStreamWriter(System.out));
    static long[] dp;

    /*
     * 1 5 6 7
     * 0장
     * 최대 한 장을 사는 경우
     * dp[1] = p[1]
     * 최대 두 장을 사는 경우 -> 1장 + 1장 or 2장짜리
     * dp[2] = dp[1] + p[1] or p[2]
     * 최대 세 장을 사는 경우 -> 1장 + 2장(최대) or 1장 + 2장 or 3장 
     * dp[3] = dp[2] + p[1] or dp[1] + p[2] or p[3]
     * 
     * 최대 i 장을 사는 경우 -> 1장(P[1]) + dp[i-1](최대) or 2장 + dp[i-2] .............. j장 -> P[j] + dp[i-j]
     * 
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int N = Integer.parseInt(br.readLine());
        int[] P = new int[N + 1];
        int[] dp = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            P[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = Math.max(dp[i], dp[i - j] + P[j]);
            }
        }

        System.out.println(dp[N]);
    }
}