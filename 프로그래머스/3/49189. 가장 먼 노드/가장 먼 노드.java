import java.util.*;
class Solution {
    // 너비우선탐색
    static int[] dist;
    static List<List<Integer>> matrix = new ArrayList<>();
    static boolean[] visited;
    static int max;
    public int solution(int n, int[][] edge) {
        int answer = 0;
        dist = new int [n];
        visited = new boolean[n];
        
        for(int i=0; i<n; i++){
            List list = new ArrayList<>();
            matrix.add(list);
        }
        for(int i=0; i<edge.length; i++){
            int s = edge[i][0], e= edge[i][1];
            matrix.get(s-1).add(e-1);
            matrix.get(e-1).add(s-1);
        
        }
        bfs();
        
        for(int i=0; i<n; i++){
            if(dist[i] == max)
                answer++;
        }
        return answer;
    }
    
    public static void bfs(){
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{0,0});
        visited[0] = true;
        while(!q.isEmpty()){
            int[] info = q.poll();
            
            int curNode = info[0];
            int distance = info[1];
            for(int nextNode : matrix.get(curNode)){
                if(!visited[nextNode]){
                    q.offer(new int[]{nextNode,distance+1});
                    visited[nextNode] = true;
                    dist[nextNode] = Math.max(distance+1,dist[nextNode]);
                    max = Math.max(max,dist[nextNode]);
                }
            }
        }
    }
}