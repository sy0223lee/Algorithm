import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stA, stB;

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> A = new PriorityQueue<>(); // 오름차순 정렬
        PriorityQueue<Integer> B = new PriorityQueue<>(Collections.reverseOrder()); // 내림차순 정렬
        int S = 0;

        stA = new StringTokenizer(br.readLine());
        stB = new StringTokenizer(br.readLine());
        for(int i=0; i<N; i++){
            A.add(Integer.parseInt(stA.nextToken()));
            B.add(Integer.parseInt(stB.nextToken()));
        }
        for(int i=0; i<N; i++){
            S += (A.poll() * B.poll());
        }
        
        System.out.println(S);
    }
}
