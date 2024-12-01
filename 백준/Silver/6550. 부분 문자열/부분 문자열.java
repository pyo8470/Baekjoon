
import java.io.*;
import java.util.*;
public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        StringTokenizer st;
        
        //6550
        // 입력1 의 처음부터 비교해가면서 인덱스 찾으면 될듯
        String line;
        while((line = br.readLine()) != null){
            st = new StringTokenizer(line);
            char[] s = st.nextToken().toCharArray();
            String t = st.nextToken();

            boolean isSubsequence = false;
            int index = 0;
            char find = s[index];
            for(int i=0; i<t.length(); i++){
                    // 현재 찾는 문자와 같은 경우
                if(t.charAt(i) == find){
                    ++index;
                    // 만약 마지막 문자열
                    if(index == s.length){
                        isSubsequence = true;
                        break;
                    }
                    // 다음 문자로
                    find = s[index];
                    
                }
            }
            String answer = isSubsequence ? "Yes" :"No";
            System.out.println(answer);
        }
    }
}