import java.util.*;
class Solution {
    static long answer;
    static long[] longA;
    static Map<Integer,List<Integer>> graph;
    static boolean[] visited;
    public long solution(int[] a, int[][] edges) {
        int sum=0;
        longA = new long[a.length];
        for(int i=0; i<a.length; i++){
            longA[i] = a[i];
            sum+=longA[i];
        }
        
        if(sum !=0) return -1;
        
        graph = new HashMap<>();
        visited = new boolean[a.length];
        
        for(int i=0; i<a.length; i++){
            graph.put(i,new ArrayList());
        }
        // graph 채우기
        for(int i=0; i<edges.length; i++){
            int s,e;
            s=edges[i][0]; e=edges[i][1];
            graph.get(s).add(e);
            graph.get(e).add(s);
        }
        dfs(0,longA);
        return answer;
    }
    
    public void dfs(int start, long[] a){
        Deque<Integer> stack = new ArrayDeque();
        stack.push(start);
        visited[start] = true;
        // 부모에게 값을 전달해야함
        // 자식, 부모
        Map<Integer,Integer> parent = new HashMap();
        parent.put(start,-1);
        
        // 부모로 전달하기 위한 순서를 저장
        List<Integer> post = new ArrayList();
        while(!stack.isEmpty()){
            int node = stack.pop();
            post.add(node);
            for(int next : graph.get(node)){
                if(!visited[next]){
                    visited[next] = true;
                    stack.push(next);
                    parent.put(next,node);
                }
            }
        }
        
        // 값을 부모로 전달
        Collections.reverse(post);
        // System.out.println(Arrays.toString(post.toArray()));
        // System.out.println(parent);
        for(int node : post){
            // 부모가 있는 경우만
            if(parent.get(node) != -1){
                a[parent.get(node)] += a[node];
                answer += Math.abs(a[node]);
            }
            // System.out.println(node +" " + answer + " "+ Arrays.toString(a));
        }
    }
}