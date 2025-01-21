import java.io.*;
import java.util.*;

public class Main {

    static int N;
    // 각 행에 퀸 하나만 나오게 한다.

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringBuilder answer = new StringBuilder(br.readLine().strip());
        int N = Integer.parseInt(br.readLine());
        int s = 0, e = 0;
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            s += Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
        }
        answer = new StringBuilder(answer.subSequence(s, s + e));
        System.out.println(answer);
    }
}
