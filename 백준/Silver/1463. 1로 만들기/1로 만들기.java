import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[] visit = new int[1000001];

    public static void BFS(int n){
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        visit[n] = 1;

        while(!q.isEmpty()){
            n = q.poll();

            if(n < 1) break;

            // 3으로 나누어 떨어지고 아직 방문 X
            if(n%3 == 0 && visit[n/3] == 0){
                q.add(n/3);
                visit[n/3] = visit[n] + 1;
            }
            // 2로 나누어 떨어지고 아직 방문 X
            if(n%2 == 0 && visit[n/2] == 0){
                q.add(n/2);
                visit[n/2] = visit[n] + 1;
            }
            // -1 아직 방문 X
            if(visit[n-1] == 0){
                q.add(n-1);
                visit[n-1] = visit[n] + 1;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        BFS(N);
        System.out.println(visit[1] - 1);
    }
}
