import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    private static int K, N;
    private static long nLen;
    private static long[] kLen;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] lens = br.readLine().split(" ");
        K = Integer.parseInt(lens[0]);
        N = Integer.parseInt(lens[1]);
        kLen = new long[K];

        long max = 0;
        for(int i=0; i<K; i++){
            kLen[i] = Long.parseLong(br.readLine());
            if(max < kLen[i]) max = kLen[i];
        }

        System.out.println(binarySearch(1, max));
    }
    
    private static long binarySearch(long left, long right){
        if(left <= right) {
            long mid = (left + right) / 2;
            int cnt = 0;

            for(long len : kLen){
                cnt += len / mid;
            }

            if(cnt >= N){
                nLen = mid;
                binarySearch(mid+1, right);
            }
            else
                binarySearch(left, mid-1);
        }
        return nLen;
    }
}