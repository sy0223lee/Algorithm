import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws IOException{
        // 키보드 입력을 위함
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        double totalGrade = 0.0;
        double totalRate = 0.0;
        double grade;
        String rate;

        // map 인터페이스의 hashmap 클래스 사용
        HashMap<String, Double> rates = new HashMap<>();
        rates.put("A+", 4.5); rates.put("A0", 4.0); rates.put("B+", 3.5);
        rates.put("B0", 3.0); rates.put("C+", 2.5); rates.put("C0", 2.0);
        rates.put("D+", 1.5); rates.put("D0", 1.0); rates.put("F", 0.0);

        for(int i=0; i<20; i++){
            String line = br.readLine();
            String splitLine[] = line.split(" ");   // string을 " " 기준으로 나누기
            grade = Double.parseDouble(splitLine[1]);   // string을 double형으로 변환
            rate = splitLine[2];

            if(!rate.equals("P")){
                totalGrade += grade;
                totalRate += grade * rates.get(rate);
            }
        }
        System.out.println(totalRate / totalGrade);
    }
}
