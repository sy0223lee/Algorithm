import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] pos = br.readLine().split(" ");

        int N = Integer.parseInt(pos[0]);
        int K = Integer.parseInt(pos[1]);
        int[] visit = new int[100001];
        Queue<Integer> q = new LinkedList<>();

        q.add(N);
        visit[N] = 1;

        while(!q.isEmpty()){
            int v = q.remove();

            if(v == K){
                System.out.println(visit[K]-1);
                break;
            }

            if(v-1 >= 0 && visit[v-1] == 0){
                q.add(v-1);
                visit[v-1] = visit[v] + 1;
            }
            if(v+1 <= 100000 && visit[v+1] == 0){
                q.add(v+1);
                visit[v+1] = visit[v] + 1;
            }
            if(v*2 <= 100000 && visit[v*2] == 0){
                q.add(v*2);
                visit[v*2] = visit[v] + 1;
            }
        }
    }
}
