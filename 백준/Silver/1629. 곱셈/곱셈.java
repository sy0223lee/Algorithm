import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static long C;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long A = Integer.parseInt(st.nextToken());
        long B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        System.out.println(pow(A, B));
    }

    static long pow(long A, long B){
        if(B == 1){ // B가 1이면 한 번만 곱하는 것
            return A % C;
        }     

        long temp = pow(A, B/2); // B의 절반에 해당하는 A^(B/2)
        if(B%2 == 1){ // B가 홀수면 A^(B/2)*A^(B/2)*A이므로 A 한 번 더 곱해주기
            return ((temp*temp) % C) * (A%C) % C;
            /* (temp*temp*A)가 long 형 범위를 넘어갈 수 있으므로
             * 바로 %C를 하면 잘못된 계산 결과가 나올 수 있음
             * 따라서 ((temp*temp%C)*(A%C))%C 해줘야 함
             */
        }
        // B가 짝수이면 A^(B/2)*A^(B/2) 으로 반환
        return temp*temp % C;
    }
}
