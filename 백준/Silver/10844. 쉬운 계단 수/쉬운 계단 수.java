
import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1_000_000_000L;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // StringTokenizer st;
        int N = Integer.parseInt(br.readLine());

        //마지막 자리 -> 0일 경우 다음에 1밖에 올 수 없다.
        //마지막 자리 -> 9일 경우 다음에 8밖에 올 수 없다.

        Long[][] dp = new Long[N+1][10];
        
        for(int i=0; i<10; i++){
            dp[1][i] = 1L;
        }

        for(int i=2; i<=N; i++){
            dp[i][0] = dp[i-1][1]%MOD;
            for(int j = 1; j<=8; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%MOD;
            }
            dp[i][9] = dp[i-1][8]%MOD;
        }

        long result = 0;
        for(int i=1; i<10; i++){
            result += dp[N][i]%MOD;
        }
        System.out.println(result%MOD);
    }
}