import java.util.*;

class Solution {
    static boolean[] visited;
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(n,i,computers);
                answer +=1;
            }
            
        }
        return answer;
    }
    
    private static void dfs(int n,int node, int[][] computers){
        visited[node] = true;
        for(int i=0; i<n; i++){
            int nextNode = i;
            if(nextNode != node && computers[node][i] == 1 && !visited[nextNode]){
                dfs(n,i,computers);
            }
        }
    }
}