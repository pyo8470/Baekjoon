import java.util.*;

class Solution {
    static int rowLength;
    static int colLength;
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        Arrays.sort(mats);
        
        rowLength = park.length;
        colLength = park[0].length;
        
        
        for(int i=0; i<rowLength; i++){
            for(int j=0; j<colLength; j++){
                if (!park[i][j].equals("-1")) continue;
                for(int length : mats){
                    if (check(park,length,j,i)) {
                        answer = Math.max(length,answer);
                    }
                }
            }
        }
        return answer;
        
        
    }
    public static boolean check(String[][] park, int length, int x, int y){
        // 범위 초과 체크: x와 y는 시작 좌표이고, length는 해당 크기
        if (x + length > colLength || y + length > rowLength) {
            return false;
        }
        
        // 주어진 크기만큼 공간이 모두 "-1"인지 확인
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (!park[y + i][x + j].equals("-1")) {
                    return false;
                }
            }
        }
        return true;
    }
}