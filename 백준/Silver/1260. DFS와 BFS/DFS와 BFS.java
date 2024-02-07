import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static boolean[][] map;
    static boolean[] visit;
    static int N, M, V; // 정점의 개수, 간선의 개수, 시작 정점 번호

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        map = new boolean[N+1][N+1];
        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            
            map[x][y] = map[y][x] = true;
        }

        visit = new boolean[N+1];
        DFS(V);
        System.out.println();
        visit = new boolean[N+1];
        BFS(V);
    }

    public static void DFS(int v){
        visit[v] = true;
        System.out.print(v + " ");

        for(int i=1; i<=N; i++){
            if(map[v][i] && !visit[i])
                DFS(i);
        }
    }

    public static void BFS(int v){
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        visit[v] = true;

        while(!q.isEmpty()){
            v = q.poll();
            System.out.print(v + " ");

            for(int w=1; w<=N; w++){
                if(map[v][w] && !visit[w]){
                    q.add(w);
                    visit[w] = true;
                }
            }
        }
    }
}
