package tests.HunterTests;

public abstract class TemplateAbstractTest {
	
	public TemplateAbstractTest() {
		
	}
	
	public static final void implementedFinalTestMethod() {
		System.out.println("this is the final method");
	}
	
	abstract void abstractTestMethod1();
	abstract void abstractTestMethod2();
	void nonAbstractMethod() {
		
	}
}
