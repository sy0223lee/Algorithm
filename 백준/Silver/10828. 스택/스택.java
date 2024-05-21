import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class MyStack{
	// 데이터를 저장할 수 있는 int형 배열이 멤버 변수로 정의
	private int[] stack;
	private int index;	
	
	public MyStack(int size) {
		this.stack = new int[size];
		this.index = -1;
	}
	// push, pop, top, empty, size 메소드 정의
	public void push(int num) {
		stack[++index] = num;
	}
	public int pop() {
		if(index < 0) {
			return -1;
		}else {
			int num = stack[index];
			stack[index--] = 0;
			return num;
		}
	}
	public int top() {
		if(index < 0) {
			return -1;
		}else {
			return stack[index];
		}
	}
	public int empty() {
		if(index < 0) {
			return 1;
		}else {
			return 0;
		}
	}
	public int size() {
		return index + 1;
	}
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		MyStack st = new MyStack(N);
		
		for(int i=0; i<N; i++) {
			String[] cmd = br.readLine().split(" ");
			switch (cmd[0]) {
			case "push":
				st.push(Integer.parseInt(cmd[1]));
				break;
			case "pop":
				System.out.println(st.pop());
				break;
			case "size":
				System.out.println(st.size());
				break;
			case "empty":
				System.out.println(st.empty());
				break;
			case "top":
				System.out.println(st.top());
				break;
			}
		}
	}
}