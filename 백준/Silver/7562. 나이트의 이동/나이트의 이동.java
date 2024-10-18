import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[][] board;
    static boolean[][] visit;
    static int[] dx = {-2,-2,1,-1,2,2,-1,1};
    static int[] dy = {-1,1,2,2,1,-1,-2,-2};
    static int I, distX, distY;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; t++){
            I = Integer.parseInt(br.readLine());
            board = new int[I][I];
            visit = new boolean[I][I];
            
            st = new StringTokenizer(br.readLine());
            int curX = Integer.parseInt(st.nextToken());
            int curY = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            distX = Integer.parseInt(st.nextToken());
            distY = Integer.parseInt(st.nextToken());

            BFS(curX, curY);
            System.out.println(board[distX][distY]);
        }
    }

    static void BFS(int x, int y){
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y));
        visit[x][y] = true;

        while(!q.isEmpty()){
            Point p = q.poll();

            if(p.x == distX && p.y == distY){
                break;
            }

            for(int i=0; i<8; i++){
                int nx = p.x + dx[i];
                int ny = p.y + dy[i];

                if(nx >= 0 && nx < I && ny >= 0 && ny < I && !visit[nx][ny]){
                    q.add(new Point(nx, ny));
                    visit[nx][ny] = true;
                    board[nx][ny] = board[p.x][p.y] + 1;
                }
            }
        }
    }
}

class Point{
    int x;
    int y;

    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}