import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> numList = new ArrayList<>();

        String input = br.readLine();
        StringTokenizer stMinus = new StringTokenizer(input, "-");
        while(stMinus.hasMoreElements()){
            String token = stMinus.nextToken();
            StringTokenizer stPlus = new StringTokenizer(token, "+");
            int sum = 0;
            while(stPlus.hasMoreElements()){
                String numStr = stPlus.nextToken();
                int num = Integer.parseInt(numStr);
                sum += num;
            }
            numList.add(sum);
        }
        int result = numList.get(0);
        int len = numList.size();
        for(int i=1; i<len; i++){
            result -= numList.get(i);
        }
        System.out.println(result);
    }
}
