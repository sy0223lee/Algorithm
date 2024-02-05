import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        
        List<Integer> numbers = new ArrayList<>();
        for(int i=0; i<N; i++){
            numbers.add(Integer.parseInt(br.readLine()));
        }
        
        Collections.sort(numbers);

        // for(int num : numbers){  // 시간 초과
        //     System.out.println(num);
        // }

        StringBuffer sb = new StringBuffer();
        for (Integer num : numbers) {
            sb.append(num).append('\n');
        }
        System.out.print(sb);
    }
}