import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] dp;
    static int[] dpRev;
    /** 
     * 헷갈릴 때, LIS 알고리즘 찾아보기.
     * 최장 증가수열 알고리즘
     * * 원소들의 가장 긴 부분 집합
     * dp[i] == arr[i]를 마지막 원소로 갖을 때, 최대 증가 수열 길이
     */

    /*
     *  이 문제닌 LIS를 앞뒤로 수행한다.
        역방향 dp와 순방향 dp의 값을 합친것중에 가장 큰 것을 고르기.
     */ 
    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 콘솔 입력용
        N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        int[] revA = new int[N];
        dp = new int[N];
        dpRev = new int[N];
        A = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        for(int i = 0; i<A.length; i++){
            revA[i] = A[A.length-i-1];
        }
        // System.out.println(Arrays.toString(A));
        // System.out.println(Arrays.toString(revA));
        // 순방향 LIS
        for(int i=0; i<N; i++){
            dp[i] = 1;
            dpRev[i] = 1;
            for(int j=0; j<i; j++){
                if(A[j] < A[i] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
                if(revA[j] < revA[i] && dpRev[j] + 1 > dpRev[i]){
                    dpRev[i] = dpRev[j] + 1;
                }
            }
        }
        // System.out.println(Arrays.toString(dp));
        // System.out.println(Arrays.toString(dpRev));
        int max = 1;
        for(int i=0; i<N; i++){
            int sum =dp[i] + dpRev[N-i-1];
            if(max < sum){
                max = sum;
            }
        }
        
        
        // 중간부분에 겹치는거 하나 빼주기.
        System.out.println(max-1);
    }
}
