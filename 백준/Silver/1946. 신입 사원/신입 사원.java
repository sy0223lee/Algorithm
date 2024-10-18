import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for(int t=0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            int[] rank = new int[N+1];
            int cnt = 1; // 서류 순위 1위인 사람 미리 포함

            for(int i=0; i<N; i++){
                st = new StringTokenizer(br.readLine());
                int document = Integer.parseInt(st.nextToken());
                int interview = Integer.parseInt(st.nextToken());
                rank[document] = interview;
            }

            int tmp = rank[1]; // 선발된 사람의 면접 순위
            for(int i=2; i<=N; i++){
                if(rank[i] < tmp){ // 서류 순위는 낮지만 면접 순위가 높다면
                    tmp = rank[i];
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
    }
}
