
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // StringTokenizer st;
        // 키와 암호문을 입력받습니다.
        int N = Integer.parseInt(br.readLine());

        // 0은 두개 씩 짝 지어서 붙어있음

        // n = 1 -> 1 // 1
        // n = 2 -> 2 // 01 11
        // n = 3 -> 3 // 111 001 100
        // n = 4 -> 5 // 1111 1100 1001 0011 0000
        // n = 5 ->   // 11111 11100 11001 10011 00111 10000 00001 00100

        long[] dp = new long [N+1];
        dp[0] = 1; dp[1] = 1;
        for(int i=2; i<=N; i++){
            dp[i] = (dp[i-1] + dp[i-2])%15746;
        }
        System.out.println(dp[N]);
    }
}