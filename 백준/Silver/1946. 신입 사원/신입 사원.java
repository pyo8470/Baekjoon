
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;
public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // 카드의 색 : R,B,Y,G
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for (int testcase=0; testcase<T; testcase++){
            int answer = 1;
            List<int[]> applicants = new ArrayList<>();
            int N = Integer.parseInt(br.readLine());
            for(int i = 0 ; i<N; i++){
                st = new StringTokenizer(br.readLine());
                int first = Integer.parseInt(st.nextToken());
                int second = Integer.parseInt(st.nextToken());
                applicants.add(new int[]{first,second});
            }
            applicants.sort(Comparator.comparingInt(score -> score[0]));
            // applicants.stream()
            //       .forEach(array -> System.out.println(array[0] + " " + array[1]));
            
            // 2차 점수 기준으로 거르기 시작
            int max = applicants.get(0)[1];
            for(int i=1; i<N; i++){
                // 2차 순위가 더 높다면 뽑는다
                if (max > applicants.get(i)[1]){
                    answer++;
                    max = applicants.get(i)[1];
                }
            }
            System.out.println(answer);
        }
    }
}