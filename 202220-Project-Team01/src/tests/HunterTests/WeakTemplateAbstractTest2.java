package tests.HunterTests;

public abstract class WeakTemplateAbstractTest2 {
	public WeakTemplateAbstractTest2() {
		
	}
	
	public void implementedNonFinalTestMethod() {
		System.out.println("this is not a final method");
	}
	
	abstract void abstractTestMethod1();
	abstract void abstractTestMethod2();
	void nonAbstractMethod() {
		
	}
}
