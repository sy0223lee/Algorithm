import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> maxPQ = new PriorityQueue<>(Comparator.reverseOrder()); // 내림차순
        PriorityQueue<Integer> minPQ = new PriorityQueue<>(); // 오름차순

        for(int i=0; i<N; i++){
            // 최대힙과 최소힙의 크기가 같으면 최대힙에 add
            if(maxPQ.size() == minPQ.size()){
                maxPQ.add(Integer.parseInt(br.readLine()));

                // 최대힙 peek() < 최소힙 peek()가 성립하지 않으면 바꿔주기
                if(!minPQ.isEmpty() && maxPQ.peek() > minPQ.peek()){
                    minPQ.add(maxPQ.poll());
                    maxPQ.add(minPQ.poll());
                }
            }else{
                minPQ.add(Integer.parseInt(br.readLine()));

                // 최대힙 peek() < 최소힙 peek()가 성립하지 않으면 바꿔주기
                if(maxPQ.peek() > minPQ.peek()){
                    minPQ.add(maxPQ.poll());
                    maxPQ.add(minPQ.poll());
                }
            }

            System.out.println(maxPQ.peek());
        }
    }
}
