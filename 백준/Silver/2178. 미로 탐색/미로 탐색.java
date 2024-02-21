import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static boolean[][] map;
    static int[][] dist;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new boolean[N+1][M+1];
        dist = new int[N+1][M+1];

        for(int i=1; i<=N; i++){
            String str = br.readLine();
            for(int j=1; j<=M; j++){
                map[i][j] = str.charAt(j-1) == '1' ? true : false;
            }
        }

        System.out.println(BFS(1, 1));
    }

    static int BFS(int x, int y){
        Queue<int []> q = new LinkedList<>();
        q.add(new int[] {x, y});
        dist[x][y] = 1;

        while(!q.isEmpty()){
            int[] pos = q.poll();
            x = pos[0]; y = pos[1];

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 1 || nx > N || ny < 1 || ny > M)
                    continue;
                if(map[nx][ny] && dist[nx][ny] == 0){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.add(new int[] {nx, ny});
                }
            }
        }
        
        return dist[N][M];
    }
}
