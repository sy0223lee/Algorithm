import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static int R, C, ans = 1;
    static String[] board;
    static int[] dx = {1,0,-1,0};
    static int[] dy = {0,1,0,-1};
    // static Set<Character> cSet = new HashSet<>(); // Set 사용 시 메모리 사용 증가
    static boolean[] cArr = new boolean[26]; // 배열 사용 시 메모리 사용을 줄일 수 있음!

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        board = new String[R];

        // 보드판 값 저장
        for(int i=0; i<R; i++){
            board[i] = br.readLine();
        }
        // DFS
        DFS(0, 0, 1);
        System.out.println(ans);
    }

    static void DFS(int x, int y, int cnt){
        cArr[board[x].charAt(y) - 'A'] = true;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 벗어나는 경우
            if(nx < 0 || nx >= R || ny < 0 || ny >= C){
                continue;
            }

            char nc = board[nx].charAt(ny);
            if(!cArr[nc - 'A']){
                ans = Math.max(ans, cnt + 1);
                DFS(nx, ny, cnt + 1);
                // 백트레킹
                cArr[nc - 'A'] = false;
            }
        }
    }
}
