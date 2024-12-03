
import java.io.*;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class Main {
    
    static int N;
    static int M;
    static int[] arr;
    static StringBuilder sb = new StringBuilder();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine()); br.close();
        N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
        arr = new int[M+1];
        Combination(0);
        bw.write(sb.toString());

        bw.flush();
    }
    public static void Combination(int depth){
        if (depth == M){
            for(int i=0; i<M; i++){
                sb.append(arr[i] +" ");
            }
            sb.append("\n");
            return;
        }

        for(int i=1; i<=N; i++){
            arr[depth] = i;
            Combination(depth+1);
        }
    }
}