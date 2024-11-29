import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int temp = N;
        int count = 0;

        while (true) {
            count++;

            // 두 자릿수 계산
            int first = temp / 10;   // 십의 자리
            int second = temp % 10; // 일의 자리
            int third = (first + second) % 10;

            // 새로운 숫자 생성
            temp = (second * 10) + third;

            // 초기값과 같으면 종료
            if (temp == N) {
                break;
            }
        }

        // 결과 출력
        System.out.println(count);
    }
}
