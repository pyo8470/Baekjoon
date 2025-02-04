import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] numbers;
    static boolean[] visited;
    static List<Integer> result = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));

        N = Integer.parseInt(br.readLine());
        numbers = new int[N + 1];

        visited = new boolean[N + 1];
        // 먼저 자기 자신과 숫자가 같은 경우는 init에 추가
        for (int i = 1; i <= N; i++) {
            numbers[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 1; i <= N; i++) {
            visited[i] = true;
            dfs(i, i);
            visited[i] = false;
        }
     
        System.out.println(result.size());
        result.stream().forEach(System.out::println);
    }

    private static void dfs(int current, int startNum) {
        int next = numbers[current];
        /* 사이클 발생 */
        if (!visited[next]) {
            visited[next] = true;
            dfs(next, startNum);
            visited[next] = false;
        }

        if (startNum == numbers[next]) {
            result.add(startNum);
            // stack[current] = true;
        }
    }
}
