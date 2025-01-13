import java.io.*;
import java.util.*;

public class Main {

    static int K;
    static char[] sign;
    static String max = "", min = "";
    static boolean[] visited = new boolean[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        K = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        sign = new char[K];
        for (int i = 0; i < K; i++) {
            sign[i] = st.nextToken().charAt(0);
        }

        solution(0, new StringBuilder());
        System.out.println(max);
        System.out.println(min);
    }

    public static boolean check(int left, int right, char sign) {
        if (sign == '<') {
            return left < right;
        } else {
            return left > right;
        }
    }

    /** 작은 수부터 탐색 **/
    private static void solution(int depth, StringBuilder num) {
        if (depth == K + 1) {
            if (min.isEmpty()) {
                min = num.toString();
            } else {
                max = num.toString();
            }
            return;
        }

        for (int i = 0; i <= 9; i++) {
            if (!visited[i]) {
                if (depth == 0 || check(num.charAt(depth - 1) - '0', i, sign[depth - 1])) {
                    // depth == 0 -> check 실행하지 않음
                    // 따라서 바로 아래의 구문 적용
                    /*
                     * OR 구문의 특징
                     * 조건1 || 조건2
                     * 조건1 이 참 -> 조건2 실행 x
                     */
                    visited[i] = true;
                    solution(depth + 1, num.append(i));
                    visited[i] = false;
                    num.deleteCharAt(num.length() - 1);
                }
            }
        }
    }
}
