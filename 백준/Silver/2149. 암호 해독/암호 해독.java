
import java.io.*;
import java.util.*;

public class Main {
    static String key;
    static String cipherText;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // StringTokenizer st;
        // 키와 암호문을 입력받습니다.
        String key = br.readLine();
        String cipherText = br.readLine();

        // 암호문을 키 길이로 나누어 행렬로 구성합니다.
        int keyLength = key.length();
        int rowCount = cipherText.length() / keyLength;
        char[][] matrix = new char[rowCount][keyLength];

        // 키의 알파벳 순서를 정렬한 후, 각 문자의 원래 인덱스를 기록합니다.
        List<Map.Entry<Character, Integer>> sortedKey = new ArrayList<>();
        for (int i = 0; i < keyLength; i++) {
            sortedKey.add(new AbstractMap.SimpleEntry<>(key.charAt(i), i));
        }
        //System.out.println(sortedKey.toString());
        sortedKey.sort(Map.Entry.comparingByKey());
        //System.out.println(sortedKey.toString());
        // 암호문을 행렬에 채웁니다.

        int index = 0;
        // 평문 -> 가로(행 단위)로 읽음
        // 암호문 -> Key 순서를 바꾼 후에, 키에 해당하는 문자들을 세로(열 단위)로 읽음
        // 따라서 sortedKey에서 열을 찾아 원래 평문에 해당하는 자리(열 단위)로 넣어주면 됨
        //System.out.println(cipherText);
        for (int i = 0; i < keyLength; i++) {
            int columnIndex = sortedKey.get(i).getValue(); // 키에서의 원래 인덱스
            for (int j = 0; j < rowCount; j++) {
                matrix[j][columnIndex] = cipherText.charAt(index++);
                //System.out.println(Arrays.deepToString(matrix));
            }
        }
        

        // 행렬에서 열을 읽어 평문을 만듭니다.
        StringBuilder plainText = new StringBuilder();
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < keyLength; j++) {
                plainText.append(matrix[i][j]);
            }
        }

        // 평문을 출력합니다.
        System.out.println(plainText.toString());
    }

}