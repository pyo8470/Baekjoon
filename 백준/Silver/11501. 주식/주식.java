
import java.io.*;
import java.util.*;
public class Main{
    static List<List<Integer>> graph = new ArrayList<>();
    static boolean[] visited;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // 카드의 색 : R,B,Y,G
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        
        for(int testcase = 0 ; testcase< T; testcase++){
            int N = Integer.parseInt(br.readLine());
            int[] prices = new int[N];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                prices[i] = Integer.parseInt(st.nextToken());
            }

            long answer = 0;
            int maxPrice = 0;
            // 역방향으로 계산한다.
            for(int i=N-1; i>=0 ; i--){
                if(prices[i]> maxPrice){
                    maxPrice = prices[i];
                }
                // 이익 계산
                answer += (maxPrice-prices[i]);
            }
            System.out.println(answer);
        }   
        
    }
}