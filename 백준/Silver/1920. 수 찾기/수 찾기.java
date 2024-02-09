import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    private static int[] A;
    private static int N, M;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        String[] nums = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            A[i] = Integer.parseInt(nums[i]);
        }

        Arrays.sort(A);

        M = Integer.parseInt(br.readLine());
        nums = br.readLine().split(" ");
        for(int i=0; i<M; i++){
            System.out.println(binarySearch(0, N-1, Integer.parseInt(nums[i])));
        }
    }

    private static int binarySearch(int low, int high, int target){
        if(low > high)
            return 0;
        int mid = (low + high) / 2;

        if(A[mid] == target)
            return 1;
        
        // 찾는 수가 더 작다면, 검사 범위를 더 작게 잡아야 한다.
        if(A[mid] > target)
            return binarySearch(low, mid - 1, target);
            
        // 찾는 수가 더 크다면, 검사 범위를 더 크게 잡아야 한다.
        else
            return binarySearch(mid + 1, high, target);
    }
}
