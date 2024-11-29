import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<String> channel = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < N; i++) {
            channel.add(br.readLine());
        }
        
        // 1. KBS1을 첫 번째로 만들기
        for (int i = 0; i < N; i++) {
            if (channel.get(i).equals("KBS1")) {
                for (int j = i; j > 0; j--) {
                    System.out.print(4);  // 4번 버튼을 눌러서 자리 바꾸기
                    Collections.swap(channel, j, j - 1);
                }
                break;  // KBS1을 첫 번째로 만들었으면 끝내기
            } else {
                System.out.print(1);  // 1번 버튼을 눌러서 아래로 내리기
            }
        }
        
        // 2. KBS2를 두 번째로 만들기
        for (int i = 0; i < N; i++) {
            if (channel.get(i).equals("KBS2")) {
                for (int j = i; j > 1; j--) {  // 1번 인덱스에 KBS2를 위치시키기 위해
                    System.out.print(4);  // 4번 버튼을 눌러서 자리 바꾸기
                    Collections.swap(channel, j, j - 1);
                }
                break;  // KBS2를 두 번째로 만들었으면 끝내기
            } else {
                System.out.print(1);  // 1번 버튼을 눌러서 아래로 내리기
            }
        }
    }
}
