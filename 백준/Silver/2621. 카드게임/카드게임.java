
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
public class Main{
    static String[] colors = new String[5];
    static Integer[] numbers = new Integer[5];
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        // 카드의 색 : R,B,Y,G
        StringTokenizer st;
        

        for (int i=0; i<5; i++){
            st = new StringTokenizer(br.readLine());
            colors[i] = st.nextToken();
            numbers[i] = Integer.valueOf(st.nextToken());
        }
        br.close();

        int answer = calculate();
        System.out.println(answer);
    }
    private static int calculate(){
        // 각 색깔과 숫자의 개수를 센다.
        Map<Integer,Integer> numberCount = new HashMap<>();
        Map<String,Integer> colorCount = new HashMap<>();
        int answer = 0;
        for(String color : colors){
            // color
            colorCount.put(color,colorCount.getOrDefault(color,0)+1);
        }
        for(Integer number : numbers){
            numberCount.put(number,numberCount.getOrDefault(number, 0)+1);
        }
        

        // 1. 같은 색의 카드가 5장 && 연속적
        boolean allSameColor = colorCount.size() == 1;
        boolean isConsecutive = true;
        Arrays.sort(numbers);

        for(int i=0 ; i<numbers.length-1; i++){
            if (numbers[i] != numbers[i+1] -1){
                isConsecutive = false;
                break;
            }
        }
        // 1.번 조건이라면
        if (allSameColor && isConsecutive){
            answer = numbers[4] + 900;
            return answer;
        }

        // 2. 카드 5장 중 4장이 같음
        for(int key : numberCount.keySet()){
            if (numberCount.get(key) == 4){
                answer = key + 800;
                return answer;
            }
        }
        // 3. 카드 5장 중 3장의 숫자가 같고 나머지 2장도 숫자가 같다
        if(numberCount.containsValue(3) && numberCount.containsValue(2)){
            for (int key : numberCount.keySet()){
                if (numberCount.get(key) == 3){
                    answer += key*10;
                }
                else if(numberCount.get(key) == 2){
                    answer += key;
                }
            }
            return answer+700;
        }
        // 4. 5장의 카드 색깔이 모두 같을 때 점수는 가장 높은 숫자에 600을 더한다
        if(allSameColor){
            // 이미 numbers는 정렬된 상태이다
            answer = numbers[4] + 600;
            return answer;
        }
        // 5. 5장의 숫자가 모두 연속적일 때
        if(isConsecutive){
            answer = numbers[4] + 500;
            return answer;
        }

        // 6. 카드 5장 중 3장의 숫자가 같을 때
        if(numberCount.containsValue(3)){
            for (int key : numberCount.keySet()){
                if (numberCount.get(key) == 3){
                    answer = key + 400;
                    return answer;
                }
            }
        }
        // 7. 카드 5장 중 두 장의 숫자가 같고 또 다른 2장의 숫자가 같을 때
        List<Integer> twoCountKeys = new ArrayList<>();
        if(numberCount.containsValue(2)){
            for (int key : numberCount.keySet()){
                if (numberCount.get(key) == 2){
                    twoCountKeys.add(key);
                }
            }  

            if (twoCountKeys.size() == 2){
                answer = Collections.max(twoCountKeys)*10;
                answer += Collections.min(twoCountKeys);
                answer += 300;
                return answer;  
            }
            // 8. 카드 5장 중 2장이 같을 때
            answer = twoCountKeys.get(0) + 200;
            return answer;
        } 

        answer = numbers[4] + 100;
        return answer;
    }
}