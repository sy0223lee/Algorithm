import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int[][] meet = new int[N][2];
        
        for(int i=0; i<N; i++){
            String[] times = br.readLine().split(" ");
            meet[i][0] = Integer.parseInt(times[0]); // 시작 시간
            meet[i][1] = Integer.parseInt(times[1]); // 종료 시간
        }
        // 2차원 배열 정렬을 위해 comparator 재정의
        Arrays.sort(meet, new Comparator<int[]>() {
            public int compare(int[] a1, int[] a2) {
                // 종료 시간을 기준으로 오름차순
                // 종료 시간 같으면 시작 시간 오름차순
                if(a1[1] == a2[1]) return a1[0] - a2[0];
                return a1[1] - a2[1];
            }
        });

        int cnt = 1;
        int end = meet[0][1];
        for(int i=1; i<N; i++){
            if(end <= meet[i][0]){
                cnt++;
                end = meet[i][1];
            }
        }

        System.out.println(cnt);
    }
}
