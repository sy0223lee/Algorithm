import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // 양방향에서 접근 할 수 있는 Deque를 활용
        ArrayDeque<Integer> deque = null;
        StringTokenizer st = null;
        int tc = Integer.parseInt(br.readLine());

        for(int t=0; t<tc; t++){
            String cmd = br.readLine();
            int len = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine(), "[],");
            deque = new ArrayDeque<>(len);
            for(int i=0; i<len; i++){
                deque.add(Integer.parseInt(st.nextToken()));
            }

            boolean reverse = false;
            boolean isError = false;
            for(char c : cmd.toCharArray()){
                if(c == 'R'){
                    reverse = !reverse;
                }else{  // c == 'D'
                    if(!reverse){
                        if(deque.pollFirst() == null){
                            System.out.println("error");
                            isError = true;
                            break;
                        }
                    }else{
                        if(deque.pollLast() == null){
                            System.out.println("error");
                            isError = true;
                            break;
                        }
                    }
                }
            }
            if(!isError){
                StringBuilder sb = new StringBuilder();
                sb.append('[');

                if(!deque.isEmpty()){
                    while(deque.size() > 1){
                        if(!reverse){
                            sb.append(deque.pollFirst() + ",");
                        }else{
                            sb.append(deque.pollLast() + ",");
                        }
                    }
                    sb.append(deque.poll());
                }
                sb.append(']');
                System.out.println(sb);
            }
        }
    }
}