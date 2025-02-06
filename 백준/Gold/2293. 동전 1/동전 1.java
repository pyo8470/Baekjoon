import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static int[] coin;
    static int[] dp;
    static Set<List<Integer>> answer = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        dp = new int[k + 1];
        dp[0] = 1;// 0원을 만드는 법
        coin = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            coin[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(coin); // 작은 값부터 탐색하기 위해 정렬
        // 가장 작은 동전으로 채우는 경우부터 하나씩
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= k; j++) {
                dp[j] += dp[j - coin[i]];
            }

        }

        System.out.println(dp[k]);
        // dfs(0, new Stack<>(), 0);

        // // 결과 출력
        // for (List<Integer> list : answer) {
        // System.out.println(list);
        // }
        // System.out.println(answer.size());
    }

    // public static void dfs(int price, Stack<Integer> stack, int start) {
    // if (price == k) {
    // answer.add(new ArrayList<>(stack)); // 중복된 리스트는 Set에서 자동 제거됨
    // return;
    // }

    // for (int i = start; i < n; i++) { // start부터 탐색하여 중복 방지
    // if (price + coin[i] > k)
    // continue; // 목표 초과 시 탐색 종료

    // stack.add(coin[i]);
    // dfs(price + coin[i], stack, i); // 같은 동전 사용 가능하도록 i 유지
    // stack.pop();
    // }
    // }
}
