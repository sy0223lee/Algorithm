import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        Stack<Character> st = new Stack<>();
        Boolean isVps = true;

        for(int i=0; i<T; i++){
            isVps = true;
            st = new Stack<>();
            String str = br.readLine();

            for(int j=0; j<str.length(); j++){
                // JAVA는 str[i] 대신 str.charAt(i) 사용
                if(str.charAt(j) == '(')
                    st.push('(');
                else{
                    if(st.isEmpty()){
                        isVps = false;
                        break;
                    }
                    else st.pop();
                }
            }

            if(st.isEmpty() && isVps)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
