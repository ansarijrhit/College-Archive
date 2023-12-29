package tests.JordanTests;

public class TestClass1 {
	private String BadCase, camelCase;
	private int index = 0;
	
	public TestClass1() {
		this.index = 0;
	}
	public boolean returnTrue(double unused, int unused2) {
		return true;
	}
	
	public void message() {
		System.out.println(getOne());
		getOne();
	}
	
	public int getOne() {
		int one = 1;
		return one;
	}
	
	public class InnerClass {
		public void doNothing() {
			
		}
	}

	public TestClass1 testReturn() {
		return new TestClass1();
	}
}
