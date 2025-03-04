import java.util.*;
class Solution {
    static String start,end;
    static int length;
    static boolean[] visited;
    static int answer = Integer.MAX_VALUE;
    public int solution(String begin, String target, String[] words) {
        start = new String(begin);
        length = target.length();
        end = new String(target);
        visited = new boolean[words.length];
        
        dfs(begin,target,words,0);
        if(answer == Integer.MAX_VALUE)
            answer = 0;
        return answer;
    }
    
    private static void dfs(String begin, String target, String[] words, int count){
        if(begin.equals(target)){
            answer = Math.min(answer,count); 
            return;
        }
        
        for(int i=0; i<words.length; i++){
            if(visited[i]) continue;
            
            if(canChange(begin,words[i])){
                visited[i] = true;
                dfs(words[i],target,words,count+1);
                visited[i] = false;
            }
        }
    }
    private static boolean canChange(String s1, String s2){
        int diffCount = 0;
        
        for(int i=0; i<length; i++){
            if(s1.charAt(i) != s2.charAt(i))
                diffCount++;
        }
        return diffCount==1;
    }
}