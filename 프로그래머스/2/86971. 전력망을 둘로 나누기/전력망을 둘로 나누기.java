import java.util.*;
class Solution {
    static Map<Integer,List<Integer>> graph;
    static boolean[] visited;
    /*
    일단 잘라보고(brute force) 사이클 찾아야 할 듯)
    */
    
    public int solution(int n, int[][] wires) {
        int answer = Integer.MAX_VALUE;
        
        for(int i=0; i<wires.length; i++){
            visited = new boolean[n+1];
            // 간선 간편하게 관리
            graph = new HashMap<>();
            
            for (int j = 1; j <= n; j++) {
                graph.put(j, new ArrayList<>());
            }
            
            for(int j=0; j<wires.length; j++){
                if(i!=j){
                    int s = wires[j][0];
                    int e = wires[j][1];
                    graph.get(s).add(e);
                    graph.get(e).add(s);
                }
            }
            
            int count = dfs(1);
            answer = Math.min(answer,Math.abs((n-count)-count));
        }
        return answer;
    }
    
    public int dfs(int vertex){
        visited[vertex] = true;
        int count = 1;
        for(int i : graph.get(vertex)){
            if(!visited[i]){
                count+=dfs(i);
            }
        }
        return count;
    }
    
}