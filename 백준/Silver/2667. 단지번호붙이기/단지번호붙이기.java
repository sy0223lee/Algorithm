import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {
    static int[][] map;
    static int N;   // 지도의 크기
    static int cnt;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> houses = new ArrayList<>();   // 가구 수를 저장할 리스트
        
        // 입력
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for(int i=0; i<N; i++){
            String str = br.readLine();
            for(int j=0; j<N; j++){
                map[i][j] = str.charAt(j) - '0';
            }
        }
        
        // BFS
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j] == 1){
                    cnt = 0;
                    BFS(i, j);
                    houses.add(cnt);
                }
            }
        }

        Collections.sort(houses); // 리스트 정렬

        // 출력
        System.out.println(houses.size());
        for(int h : houses){
            System.out.println(h);
        }
    }

    public static void BFS(int x, int y){
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        qx.add(x); qy.add(y);
        cnt++;
        map[x][y] = 0; // 방문 했으면 0으로 변경

        while(!qx.isEmpty()){
            x = qx.poll(); y = qy.poll();

            for(int i=0; i<4; i++){
                int nx = x + dx[i], ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                
                if(map[nx][ny] == 1){
                    qx.add(nx); qy.add(ny);
                    cnt++;
                    map[nx][ny] = 0;
                }
            }
        }
    }
}