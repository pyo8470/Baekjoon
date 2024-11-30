
import java.io.*;
public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int N = Integer.parseInt(br.readLine());
        char[][] room = new char[N][N];

        for(int i = 0; i<N; i++){
            room[i] = br.readLine().toCharArray();
        }

        int horizon = 0, vertical = 0 ;
        // 가로 계산
        for (int i=0; i<N; i++){
            int count = 0;
            for (int j = 0; j<N; j++){
                if(room[i][j] == '.'){
                    count++;
                }
                else{
                    if (count >= 2) vertical++;
                    count = 0;
                }
            }
            // 마지막 자리 처리
            if (count >= 2) vertical++;
        }

        for (int i=0; i<N; i++){
            int count = 0;
            for (int j=0; j<N; j++){
                if(room[j][i] == '.') count++;
                else{
                    if (count>=2) horizon++;
                    count = 0;
                }
            }
            if (count >= 2) horizon++;
        }
        System.out.println(vertical + " " + horizon);
    }
}