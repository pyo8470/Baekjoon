
import java.io.*;

public class Main {

    // static BufferedWriter bw = new BufferedWriter(new
    // OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // StringTokenizer st = new StringTokenizer(br.readLine()); br.close();

        int N = Integer.parseInt(br.readLine());
        int answer = solution(N);

        System.out.println(answer);
    }

    private static int solution(int N){
        if (N == 1) return 2;
        for (int i = N; i <= 1_000_000_000 ; i++) {
            // 검사 순서 최적화 -> 팰린드롬:O(문자열 길이 : d), 소수 검사:O(log(N))
            if(isPalindrome(i)){ //  
                if(isPrime(i)){ // O
                    return i;
                }
            }
        }
        return 0;
    }

    private static boolean isPrime(int num) {
        for(int i=2; i<(int)Math.sqrt(num) + 1; i++){
            if(num%i == 0) return false;
        }
        return true;
    }

    private static boolean isPalindrome(int num) {
        String number = String.valueOf(num);
        String number_reverse = new StringBuffer(number).reverse().toString();
        
        return number.equals(number_reverse);
    }

}