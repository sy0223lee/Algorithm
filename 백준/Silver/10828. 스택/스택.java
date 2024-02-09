import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
        int cmdCount = Integer.parseInt(br.readLine());
        int[] stack = new int[cmdCount];  

        for(int i=0; i<cmdCount; i++){
            String[] cmd = br.readLine().split(" ");

            switch (cmd[0]) {
                case "push":
                    for(int j=0; j<cmdCount; j++){
                        if(stack[j] == 0){
                            stack[j] = Integer.parseInt(cmd[1]);
                            break;
                        }
                    }
                    break;
                case "pop":
                    if(stack[0] == 0)
                        System.out.println(-1);
                    else{
                        for(int j=0; j<cmdCount; j++){
                            if(stack[j] == 0){
                                System.out.println(stack[j-1]);
                                stack[j-1] = 0;
                                break;
                            }
                        }
                    }
                    break;
                case "size":
                    for(int j=0; j<cmdCount; j++){
                        if(stack[j] == 0){
                            System.out.println(j);
                            break;
                        }
                    }
                    break;
                case "empty":
                    if(stack[0] == 0)
                        System.out.println(1);
                    else
                        System.out.println(0);
                    break;
                case "top":
                    if(stack[0] == 0)
                        System.out.println(-1);
                    else{
                        for(int j=1; j<cmdCount; j++){
                            if(stack[j] == 0){
                                System.out.println(stack[j-1]);
                                break;
                            }
                        }
                    }
                    break;            
                default:
                    break;
            }
        }
    }
}
