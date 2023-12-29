package tests.JordanTests;

public class ATestClientWeak {
	private String BadCase, camelCase;
	private int index = 0;
	private boolean falsy = false;
	
	private ATestTarget testInterface;
	private ATestAdapterWeak aTestAdapter;
	private ATestAdaptee aTestAdaptee;
	
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
