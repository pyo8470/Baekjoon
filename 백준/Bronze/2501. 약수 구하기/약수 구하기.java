import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int N, K;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            if (N % i == 0) {
                A.add(i);
            }
        }
        int answer = A.size() >= K ? A.get(K - 1) : 0;
        System.out.println(answer);
    }
}
