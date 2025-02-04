import java.io.*;
import java.util.*;

public class Main {
    static int w, h;
    static int p, q;
    static int t;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        p = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        t = Integer.parseInt(br.readLine());

        Solution();
    }

    //
    private static void Solution() {
        // 위치 -> 가로 따로 계산, 세로 따로 계산
        int x = p, y = q;
        x = (x + t) % (w * 2);
        y = (y + t) % (h * 2);

        if (x > w)
            x = w * 2 - x;
        if (y > h)
            y = h * 2 - y;
        System.out.println(x + " " + y);
    }
}
