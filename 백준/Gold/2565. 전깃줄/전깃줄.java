import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] dp;
    static int[][] string;
    /** 
     * 헷갈릴 때, LIS 알고리즘 찾아보기.
     * 최장 증가수열 알고리즘
     * * 원소들의 가장 긴 부분 집합
     * dp[i] == arr[i]를 마지막 원소로 갖을 때, 최대 증가 수열 길이
     */
    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 콘솔 입력용
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        string = new int[N][2];
        dp = new int[N];
        for(int i=0; i<N; i++){

            string[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        Arrays.sort(string, (o1,o2) -> o1[0]-o2[0]);
        /**
         * 교차하는 걸 잘라야한다.
         * 전깃줄의 B부분이 증가수열로만 있다면 자를 필요가 없다
         * 그러나 증가수열을 깨부수는 곳이 있다.
         * 역으로 생각해보면 전체 N개중 증가수열 부분집합을 제외한 것이 잘라야하는 줄의 갯수다.
         */
        int max = 1;

        for(int i=0; i<N; i++){
            // 일단 i를 마지막으로 가진다 할 때, 최솟값은 1이된다.
            dp[i] = 1;
            for(int j = 0; j<i; j++){
                //일단 i를 기준으로 앞에서부터 셀 때 i보단 작아야겠지
                //그리고 i바로 이전의 수열의 길이에 대하여 길어져야 갱신하겠지용.
                if(string[j][1] < string[i][1] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    if(max<dp[i]) max = dp[i];
                }
            }
        }
        System.out.println(N-max);
    }
}
