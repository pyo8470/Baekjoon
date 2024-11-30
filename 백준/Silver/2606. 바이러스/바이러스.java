
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.IntStream;
public class Main{
    static boolean[] visited;
    static List<List<Integer>> graph;

    private static void dfs(int n){
        visited[n] = true;
        for(int v : graph.get(n)){
            // 방문하지 않은 노드
            if(visited[v] == false) {
                dfs(v);
            }
        }

    }
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        
        int N = Integer.parseInt(br.readLine());
        int num_edge = Integer.parseInt(br.readLine());

        visited = new boolean[N];
        graph = new ArrayList<>();
        for(int i=0; i<N; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i<num_edge; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph.get(a-1).add(b-1);
            graph.get(b-1).add(a-1);
        }
        dfs(0);
        
        // boolean[]를 Boolean[]로 변환한 후 스트림을 사용
        long count = IntStream.range(1,N)
                            .filter(i -> visited[i])  // true인 값만 필터링
                            .count();  // 개수 세기

        System.out.println(count);  // 출력

    }

    
}