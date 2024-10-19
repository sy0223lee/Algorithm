import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] map;
    static boolean[][] visit;
    static int[] dx = {-1,-1,-1,0,0,1,1,1};
    static int[] dy = {-1,0,1,-1,1,-1,0,1};
    static int w, h, island;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        w = Integer.parseInt(st.nextToken());
        h = Integer.parseInt(st.nextToken());

        while(w != 0 || h != 0){
            map = new int[h][w];
            visit = new boolean[h][w];
            island = 0;
            // 지도 값 저장
            for(int i=0; i<h; i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0; j<w; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            // DFS
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(map[i][j] == 1 && !visit[i][j]){
                        visit[i][j] = true;
                        DFS(i, j);
                        island++;
                    }
                }
            }

            System.out.println(island);

            // 다음 테스트케이스 입력
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
        }
    }

    static void DFS(int x, int y){
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < h && ny >=0 && ny < w && map[nx][ny] == 1 && !visit[nx][ny]){
                visit[nx][ny] = true;
                DFS(nx, ny);
            }
        }
    }
}
