import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int[] num;
    static int max = 0;
    static boolean[] visited;
    static List<Integer> numberComb = new ArrayList<>();

    /* |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| */
    /* 그냥 흔한 조합 문제 */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        num = new int[N];
        visited = new boolean[N];
        for (int i = 0; i < N; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        solution(0);
        System.out.println(max);
        br.close();
    }

    private static void solution(int depth) {
        if (depth == N) {
            max = Math.max(getResult(), max);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                numberComb.add(num[i]);
                visited[i] = true;
                solution(depth + 1);
                visited[i] = false;
                numberComb.remove(numberComb.size() - 1);
            }
        }
    }

    private static int getResult() {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += Math.abs(numberComb.get(i) - numberComb.get(i + 1));
        }
        return sum;
    }
}
