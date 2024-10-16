import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();
        int len1 = str1.length();
        int len2 = str2.length();

        // dp[0][n]과 dp[n][0]에 0을 저장해놓고 사용하기 위해 배열 크기를 하나씩 키움
        int dp[][] = new int[len1 + 1][len2 + 1];

        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){
                if(str1.charAt(i-1) == str2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        System.out.println(dp[len1][len2]);
    }
}
