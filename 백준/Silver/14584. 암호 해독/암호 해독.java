
import java.io.*;
import java.util.*;
public class Main{
    static String cipherText;
    static String[] dictionary;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        //StringTokenizer st;
        
        cipherText = br.readLine();
        int N = Integer.parseInt(br.readLine());
        dictionary = new String[N];
        for(int i=0; i<N; i++){
            dictionary[i] = br.readLine();
        }
        
        String rotatedText = new String();
        for(int i=0; i<26; i++){
            // 회전 함수
            rotatedText = rotation(i);
            if(isWordInRotatedText(rotatedText)) break;
        }
        System.out.println(rotatedText);
    }

    public static String rotation(int n){
        StringBuilder rotatedText = new StringBuilder();
        for(char c : cipherText.toCharArray()){
            // 순환하는 
            rotatedText.append((char)('a' + (c-'a'+n)%26));
        }
        return rotatedText.toString();
    }

    public static boolean isWordInRotatedText(String rotatedText){
        boolean answer = false;
        for(String word : dictionary){
            if((answer = rotatedText.contains(word))) return answer;
        }
        return answer;
    }
}