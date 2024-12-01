
import java.io.*;
import java.util.*;
public class Main{
    
        // 먼저, 대각선으로 가는 시간이 그냥 가는 것보다 큰 경우
    static long X,Y,w,s;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st;
        long[] information = new long[4]; 
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            information[i] = Long.parseLong(st.nextToken());
        }
        X = information[0]; 
        Y = information[1];
        w = information[2]; 
        s = information[3];
        
        long answer = calculate();
        System.out.println(answer);
    }

    private static long calculate(){
        long answer1,answer2,answer3;

        //1. 평행이동만 할떄
        answer1 = (X+Y) * w;


        answer2 = 0;
        //
        if((X+Y) % 2 == 0){
            answer2 = Math.max(X,Y) * s;
        }else{
            answer2 = (Math.max(X,Y) - 1) * s + w;
        }

        answer3 = (Math.min(X, Y))*s+(Math.abs(X-Y))*w;
        
        long answer = Math.min(answer1, Math.min(answer2, answer3));

        return answer;
    }
}