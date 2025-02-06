import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        int n;
        while ((n = Integer.parseInt(br.readLine())) != -1) {
            List<Integer> div = new ArrayList<>();
            for (int i = 1; i < n; i++) {
                if (n % i == 0)
                    div.add(i);
            }
            if (div.stream().reduce(0, Integer::sum) == n) {
                System.out.print(n + " = ");
                for (int i = 0; i < div.size() - 1; i++) {
                    System.out.print(div.get(i) + " + ");
                }
                System.out.println(div.get(div.size() - 1));
            } else {
                System.out.println(n + " is NOT perfect.");
            }
        }
    }
}
