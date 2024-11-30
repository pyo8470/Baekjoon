
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // 카드의 색 : R,B,Y,G
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for (int testcase=0; testcase<T; testcase++){
            // int answer = 1;
            // List<int[]> applicants = new ArrayList<>();
            // int N = Integer.parseInt(br.readLine());
            // for(int i = 0 ; i<N; i++){
            //     st = new StringTokenizer(br.readLine());
            //     int first = Integer.parseInt(st.nextToken());
            //     int second = Integer.parseInt(st.nextToken());
            //     applicants.add(new int[]{first,second});
            // }
            // applicants.sort(Comparator.comparingInt(score -> score[0]));
            // // applicants.stream()
            // //       .forEach(array -> System.out.println(array[0] + " " + array[1]));
            
            // // 2차 점수 기준으로 거르기 시작
            // int max = applicants.get(0)[1];
            // for(int i=1; i<N; i++){
            //     // 2차 순위가 더 높다면 뽑는다
            //     if (max > applicants.get(i)[1]){
            //         answer++;
            //         max = applicants.get(i)[1];
            //     }
            // }
            // System.out.println(answer);

            //TreeSet 이용
            // int answer = 1;
            // int N = Integer.parseInt(br.readLine());

            // TreeSet<int[]> applicants = new TreeSet<>(Comparator.comparingInt(array -> array[0]));

            // for(int i = 0; i<N;i++){
            //     st = new StringTokenizer(br.readLine());
            //     int first = Integer.parseInt(st.nextToken());
            //     int second = Integer.parseInt(st.nextToken());
            //     applicants.add(new int[]{first,second});
            // }

            // // 2차 점수 기준으로 거르기
            // Iterator<int[]> iterator = applicants.iterator();
            // int[] firstApplicant = iterator.next();
            // int max = firstApplicant[1];

            // while(iterator.hasNext()){
            //     int[] applicant = iterator.next();
            //     if (max > applicant[1]){
            //         answer++;
            //         max=applicant[1];
            //     }
            // }
            // System.out.println(answer);

            //PriorityQueue
            int answer = 1;

            int N = Integer.parseInt(br.readLine());

            // PriorityQueue를 사용하여 첫 번째 점수 기준으로 정렬
            PriorityQueue<int[]> applicants = new PriorityQueue<>(Comparator.comparingInt(array -> array[0]));

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                int first = Integer.parseInt(st.nextToken());
                int second = Integer.parseInt(st.nextToken());
                applicants.offer(new int[]{first, second});
            }

            // 2차 점수 기준으로 거르기 시작
            int[] firstApplicant = applicants.poll();
            int max = firstApplicant[1];

            while (!applicants.isEmpty()) {
                int[] applicant = applicants.poll();
                if (max > applicant[1]) {
                    answer++;
                    max = applicant[1];
                }
            }

            System.out.println(answer);
        }
    }
}