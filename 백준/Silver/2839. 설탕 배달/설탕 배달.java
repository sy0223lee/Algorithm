import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int M;  // 전체 무게
        int count = -1; // 봉지 개수
        
        M = Integer.parseInt(br.readLine());

        for(int i = M/5; i >= 0; i--){
            int leftM = M - 5*i;

            if(leftM % 3 == 0){
                count += (i + leftM / 3) + 1;
                break;
            }
        }

        System.out.println(count);
        br.close();
    }    
}
