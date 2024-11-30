
import java.io.*;
import java.util.*;
public class Main{
    static List<List<Integer>> graph = new ArrayList<>();
    static boolean[] visited;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // 카드의 색 : R,B,Y,G
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int N,M,V;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());
       
        for(int i=0; i<=N; i++){
            graph.add(new ArrayList<>());
        }
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            // 무방향 그래프
            graph.get(start).add(end);
            graph.get(end).add(start);
        }
        for (List<Integer> g : graph){
            g.sort(Comparator.naturalOrder());
        }
        visited = new boolean[N+1];
        dfs(V);
        visited = new boolean[N+1];
        System.out.println();
        bfs(V);
    }
    private static void bfs(int v){
        Deque<Integer> queue = new ArrayDeque<>();
        queue.addLast(v);
        visited[v] = true;
        while(!queue.isEmpty()){
            int current = queue.removeFirst();
            System.out.print(current + " ");
            for (Integer next : graph.get(current)) {
                if (!visited[next]){
                    queue.addLast(next);
                    visited[next] = true;
                }
            }
        }
    }
    private static void dfs(int v){
        if(visited[v] == true) return;
        visited[v] = true;
        System.out.print(v + " ");
        for (Integer next : graph.get(v)){
            if (!visited[next]) dfs(next);
        }
    }
}