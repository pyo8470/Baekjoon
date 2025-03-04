import java.util.*;
class Solution {
    static int[][] matrix;
    public int solution(int n, int[][] results) {
        int answer = 0;
        matrix = new int[n][n];
        
        for(int i=0; i<results.length; i++){
            int winner = results[i][0];
            int loser = results[i][1];
            // 이김
            matrix[winner-1][loser-1] = 1;
            matrix[loser-1][winner-1] = -1;
        }
        
       
        
        // 플로이드-워셜 알고리즘
        // matrix[i][j] == 1 matrix[j][k] == 1 -> matrix[i][k] == 1
        System.out.println(Arrays.deepToString(matrix));
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                for(int k=0; k<n; k++){
                    if(matrix[i][j] == 1 && matrix[j][k] == 1){
                        // System.out.println(i+" " + j+" " +k + " " + 1);
                        matrix[i][k] = 1;
                    }
                    if(matrix[i][j] == -1 && matrix[j][k] == -1){
                        // System.out.println(i+" " + j+" " +k + " " + -1);
                        matrix[i][k] = -1;
                    }
                }
            }
        }
        
        
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(matrix[i][j] !=0) count++;
            }
            if (count == n-1) answer++;
        }
        return answer;
    }
}