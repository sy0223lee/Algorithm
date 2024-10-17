import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Long> pq = new PriorityQueue<>();
        long answer = 0;

        int N = Integer.parseInt(br.readLine());
        for(int i=0; i<N; i++){
            pq.add(Long.parseLong(br.readLine()));
        }

        // 큐에 2개 이상 있어야 비교 가능, 카드가 1개로 다 묶이면 while문 탈출
        while(pq.size() > 1){
            // 합칠 카드 묶음
            long a = pq.poll();
            long b = pq.poll();
            // 총 비교 횟수
            answer += (a + b);
            // 새로 생긴 카드 묶음
            pq.add(a + b);
        }

        System.out.println(answer);
    }
}