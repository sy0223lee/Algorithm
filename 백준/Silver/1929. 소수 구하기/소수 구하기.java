import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.lang.Math;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        boolean isPrime = true;

        for(int num = M; num <= N; num++){
            if(num < 2) isPrime = false;
            
            for(int div = (int)Math.sqrt(num); div > 1; div--){
                if(num % div == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime)
                System.out.println(num);
            else
                isPrime = true;
        }
    }
}
