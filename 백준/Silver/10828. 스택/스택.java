import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
        int cmdCount = Integer.parseInt(br.readLine());
        int[] stack = new int[cmdCount];
        int index = -1;  

        for(int i=0; i<cmdCount; i++){
            String[] cmd = br.readLine().split(" ");

            switch (cmd[0]) {
                case "push":
                    stack[++index] = Integer.parseInt(cmd[1]);
                    break;
                case "pop":
                    if(index < 0)
                        System.out.println(-1);
                    else{
                        System.out.println(stack[index]);
                        stack[index--] = 0;
                    }
                    break;
                case "size":
                    System.out.println(index + 1);
                    break;
                case "empty":
                    if(index < 0)
                        System.out.println(1);
                    else
                        System.out.println(0);
                    break;
                case "top":
                    if(index < 0)
                        System.out.println(-1);
                    else{
                        System.out.println(stack[index]);
                    }
                    break;            
                default:
                    break;
            }
        }
    }
}
