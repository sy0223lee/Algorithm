import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Point{
    int x;
    int y;

    Point(int x, int y){
        this.x = x;
        this.y = y;
    }
}

public class Main{
    static int N, M;
    static int ans = Integer.MAX_VALUE;
    static int[][] map;
    static ArrayList<Point> house = new ArrayList<>(); // 집 좌표를 저장할 리스트
    static ArrayList<Point> chicken = new ArrayList<>(); // 치킨집 좌표를 저장할 리스트
    static boolean[] select; // 선택한 치킨집

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; j++){
                map[i][j] = Integer.parseInt(st.nextToken());

                if(map[i][j] == 1){
                    house.add(new Point(i, j));
                }else if(map[i][j] == 2){
                    chicken.add(new Point(i, j));
                }
            }
        }

        select = new boolean[chicken.size()]; // 총 치킨집 개수 크기로 생성
        backtracking(0, 0);
        System.out.println(ans);
    }

    public static void backtracking(int idx, int cnt){ // 치킨집 고르는 함수
        if(cnt == M){
            // 치킨거리 계산
            int sum = 0;
            for(int i=0; i<house.size(); i++){
                int min = Integer.MAX_VALUE;
                for(int j=0; j<chicken.size(); j++){
                    if(select[j]){
                        int dist = Math.abs(house.get(i).x - chicken.get(j).x)
                                    + Math.abs(house.get(i).y - chicken.get(j).y);
                        min = Math.min(min, dist);
                    }
                }
                sum += min;
            }
            ans = Math.min(ans, sum);
            return;
        }
        for(int i=idx; i<chicken.size(); i++){
            if(!select[i]){ // 선택되지 않은 치킨집이면
                select[i] = true;
                backtracking(i + 1, cnt + 1);
                select[i] = false;
            }
        }
    }
}