import java.io.*;
import java.util.*;

public class Main {
    static int N, M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int max = 0;
        int R = 1, C = 1;
        StringTokenizer st;
        int num;
        for (int r = 1; r <= 9; r++) {
            st = new StringTokenizer(br.readLine());
            for (int c = 1; c <= 9; c++) {
                num = Integer.parseInt(st.nextToken());
                if (num > max) {
                    max = num;
                    R = r;
                    C = c;
                }
            }
        }
        System.out.println(max);
        System.out.println(R + " " + C);
    }
}
