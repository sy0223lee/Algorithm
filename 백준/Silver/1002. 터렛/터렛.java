import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for(int i=0; i<T; i++){
            String[] pos = br.readLine().split(" ");
            int x1 = Integer.parseInt(pos[0]);
            int y1 = Integer.parseInt(pos[1]);
            int r1 = Integer.parseInt(pos[2]);
            int x2 = Integer.parseInt(pos[3]);
            int y2 = Integer.parseInt(pos[4]);
            int r2 = Integer.parseInt(pos[5]);
            double d = Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

            if(d == 0 && r1 == r2) // 같은 중심, 같은 거리
                System.out.println(-1);
            else if(d == r1+r2 || d == Math.abs(r1-r2)) // 외접, 내접
                System.out.println(1);
            else if(d > Math.abs(r1-r2) && d < r1+r2) // 두 점에서 만날 때
                System.out.println(2);
            else
                System.out.println(0);
        }
    }   
}
