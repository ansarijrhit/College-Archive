package tests.HunterTests;

public class GetterTestClass {
	private String unusedField;
	private String usedField;
	public String publicTestField;
	
	public GetterTestClass() {
		this.unusedField = "not using";
		this.usedField = "using";
	}
	
	private boolean usedMethod() {
		return false;
	}
	
	private boolean unusedMethod() {
		return usedMethod();
	}
}
