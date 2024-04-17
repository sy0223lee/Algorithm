import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws Exception {
        StringTokenizer st;
        String cmd = null;
        int set = 0;
        int num = 0;
        int M = Integer.parseInt(br.readLine());
        while(M-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            cmd = st.nextToken();            
            switch (cmd) {
                case "add":
                    // 1 << 1 = 10 이므로 1 << x-1 해주기
                    num = Integer.parseInt(st.nextToken()) - 1;
                    set = set | (1 << num);
                    break;
                case "remove":
                    num = Integer.parseInt(st.nextToken()) - 1;
                    set = set & ~(1 << num);
                    break;
                case "check":
                    num = Integer.parseInt(st.nextToken()) - 1;
                    if((set & (1 << num)) > 0){
                        bw.write("1\n");
                    }else{
                        bw.write("0\n");
                    }
                    break;
                case "toggle":
                    num = Integer.parseInt(st.nextToken()) - 1;
                    set = set ^ (1 << num);
                    break;
                case "all":
                    // 사칙연산자가 shift 연산자보다 우선순위 높음
                    set = (1 << 21) - 1;
                    break;
                case "empty":
                    set = 0;
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}