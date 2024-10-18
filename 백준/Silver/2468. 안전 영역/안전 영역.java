import java.io.*;
import java.util.*;

class Point{
    public int x;
    public int y;

    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int[][] map;
    static boolean[][] visit;
    static int N;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        int maxH = 0;
        int answer = 0;

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; j++){
                int h = Integer.parseInt(st.nextToken());
                map[i][j] = h;
                maxH = Math.max(maxH, h);
            }
        }

        for(int h=0; h<maxH; h++){ // 홍수 높이
            visit = new boolean[N][N];
            int cnt = 0;

            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(map[i][j] > h && !visit[i][j]){ // 처음 만나는 구역인 경우
                        cnt++;
                        BFS(i, j, h);
                    }        
                    answer = Math.max(answer, cnt);
                }
            }            
        }
        System.out.println(answer);
    }

    static void BFS(int i, int j, int h){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(i, j));
        visit[i][j] = true;

        while(!q.isEmpty()){
            Point point = q.poll();
            int x = point.x;
            int y = point.y;

            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N){
                    continue;
                }

                if(map[nx][ny] > h && !visit[nx][ny]){
                    q.add(new Point(nx, ny));
                    visit[nx][ny] = true;
                }
            }
        }
    }
}
