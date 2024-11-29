import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // 입력 파일 읽기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // N 입력받기
        int N = Integer.parseInt(br.readLine());
        // 상담 정보 저장 배열
        int[][] counselling = new int[N][2];
        
        // 상담 정보 입력받기
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            counselling[i][0] = Integer.parseInt(st.nextToken()); // time
            counselling[i][1] = Integer.parseInt(st.nextToken()); // price
        }
        
        // DP 배열 초기화
        int[] dp = new int[N + 1];
        
        // DP 계산
        for (int day = 0; day < N; day++) {
            int time = counselling[day][0];
            int price = counselling[day][1];
            
            // day일에 상담을 했을 경우를 가정하여 업데이트
            for (int j = day + time; j <= N; j++) {
                dp[j] = Math.max(dp[j], dp[day] + price);
            }
        }
        
        // 결과 출력
        System.out.println(dp[N]);
    }
}
