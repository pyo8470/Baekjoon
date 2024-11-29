import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int answerIndex = 0;
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        ArrayList<Nation> list = new ArrayList<>();
        while(N --> 0){
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int gold = Integer.parseInt(st.nextToken());
            int silver = Integer.parseInt(st.nextToken());
            int bronze = Integer.parseInt(st.nextToken());
            list.add(new Nation(num, gold, silver, bronze, 0));
        }

        Collections.sort(list);
        list.get(0).rank = 1;
        
        for(int i=1; i<list.size();i++){
            Nation now = list.get(i);
            Nation prev = list.get(i-1);

            // 국가번호가 K 
            if(list.get(i).num == K){
                answerIndex = i;
            }
            
            // 등수가 같은 경우
            if(now.gold == prev.gold && now.silver == prev.silver && now.bronze == prev.bronze){
                list.get(i).rank = prev.rank;
            }
            else{
                list.get(i).rank = i+1;
            }
        }
        System.out.println(list.get(answerIndex).rank);
    }
}

class Nation implements Comparable<Nation>{
    int num,gold,silver,bronze,rank;

    Nation(int num, int gold, int silver, int bronze, int rank){
        this.num = num;
        this.gold = gold;
        this.silver = silver;
        this.bronze = bronze;
        this. rank = rank;
    }

    @Override
    public int compareTo(Nation n){
        // 금메달 개수가 같을 경우
        if(this.gold == n.gold){
            // 은메달 마저 같을 경우
            if(this.silver == n.silver){
                return n.bronze - this.bronze;
            }
            else{
                return n.silver - this.silver;
            }
        }
        else{
            return n.gold - this.gold;
        }
    }
}