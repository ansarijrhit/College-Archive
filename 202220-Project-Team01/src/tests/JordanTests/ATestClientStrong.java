package tests.JordanTests;

public class ATestClientStrong {
	private String BadCase, camelCase;
	private int index = 0;
	private boolean falsy = false;
	
	private ATestTarget testInterface;
	
	public boolean returnTrue(double unused) {
		return true;
	}
	
	public void message() {
		System.out.println(getOne());
		getOne();
	}
	
	public int getOne() {
		return 1;
	}
}
