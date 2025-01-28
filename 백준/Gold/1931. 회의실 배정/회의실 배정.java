import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] time;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        N = Integer.parseInt(br.readLine());
        time = new int[N][2];
        StringTokenizer st;

        int answer = 1;
        for(int i=0 ;i<N; i++){
            st = new StringTokenizer(br.readLine());
            time[i][0] = Integer.parseInt(st.nextToken());
            time[i][1] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(time, (a, b) -> {
            if (a[1] == b[1]) {
                return Integer.compare(a[0], b[0]); // 두 번째가 같다면 첫 번째 열로 정렬
            }
            return Integer.compare(a[1], b[1]); // 기본은 두 번째 열로 정렬
        });
        
        // System.out.println(Arrays.deepToString(time));
        int end = time[0][1];
        for(int i=1; i<N; i++){
            int start = time[i][0];
            if(end <= start) {
                end = time[i][1];
                answer++;
            }
        }
        System.out.println(answer);
    }
}

/* e s
 * 4 3
 * 4 0
 * 4 5 
 * 
 */