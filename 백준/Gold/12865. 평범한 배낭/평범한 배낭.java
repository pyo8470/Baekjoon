import java.io.*;
import java.util.*;

public class Main {
    static int N, K;
    static int[][] bag;
    static int[] dp;
    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 콘솔 입력용
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        dp = new int[K+1];
        bag = new int[N][2];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            bag[i][0] = Integer.parseInt(st.nextToken()); // 무게
            bag[i][1] = Integer.parseInt(st.nextToken()); // 가치
        }

        Arrays.sort(bag, (o1, o2)->{
            // 무게가 같다면
            if(o1[0] == o2[0])
                return o2[1]-o1[1];
            return o1[0]-o2[0];
        });

        
        for(int i= 0 ; i<N; i++){
            int w = bag[i][0];
            int v = bag[i][1];
            for(int j=K; j>=w; j--){
                dp[j] = Math.max(dp[j],dp[j-w]+v);
            } 
        }

        System.out.println(dp[K]);
    }
}
