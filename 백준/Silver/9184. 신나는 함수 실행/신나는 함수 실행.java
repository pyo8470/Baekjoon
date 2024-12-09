
import java.io.*;
import java.util.*;

public class Main {

    // static BufferedWriter bw = new BufferedWriter(new
    // OutputStreamWriter(System.out));
    static int a,b,c;
    static int[][][] dp = new int[21][21][21];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        //StringTokenizer st = new StringTokenizer(br.readLine());
        StringTokenizer st;
        while (true) {
            st =new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()); 
            b = Integer.parseInt(st.nextToken()); 
            c = Integer.parseInt(st.nextToken());
            if(a==-1 && b==-1 && c==-1) break;

            System.out.printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
        }
    }
    /** 메모이제이션 
     *  dp[][][] 배열에 각각 a,b,c에 관한 값들을 집어넣는다(memo)
     * **/
    static int w(int a, int b, int c) { 
        if(a>=0 && a<=20 && b>=0 && b<=20 && c>=0 && c<=20 && dp[a][b][c] != 0){
            return dp[a][b][c];
        }
		
        if(a <= 0 || b <= 0 || c <= 0) {
            return 1;
        }
            
        if(a > 20 || b > 20 || c > 20) {
            return dp[20][20][20] = w(20, 20, 20);
        }
            
        if(a < b && b < c) {
            return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        }
        
        return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

}