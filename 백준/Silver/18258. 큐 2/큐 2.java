import java.io.*;
import java.util.*;

public class Main {
    // 사실 구현보다 출력 최적화가 더 어려운듯 ㅋ
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int n;

        n = Integer.parseInt(br.readLine());
        String command;
        int X;
        StringBuilder sb = new StringBuilder();
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            command = st.nextToken();

            if (command.equals("push")) {
                X = Integer.parseInt(st.nextToken());
                q.add(X);
            } else if (command.equals("pop")) {
                sb.append(q.isEmpty() ? "-1\n" : q.removeFirst() + "\n");
            } else if (command.equals("size")) {
                sb.append(q.size() + "\n");
            } else if (command.equals("empty")) {
                sb.append(q.isEmpty() ? "1\n" : "0\n");
            } else if (command.equals("front")) {
                sb.append(!q.isEmpty() ? q.getFirst()+"\n" : "-1\n");
            } else if (command.equals("back")) {
                sb.append(!q.isEmpty() ? q.getLast()+"\n" : "-1\n");
            }
        }
        System.out.print(sb.toString());
    }
}
