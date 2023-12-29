package tests.HunterTests;

public class TypePredicatedTest {
	private TypePredicatedExtendedTest f1;
	private TypePredicatedImplementedTest f2;
	private TypePredicatedInterface p1;
	private TypePredicatedSuperClass p2;
	
	public TypePredicatedTest() {
		
	}
	
	public void typePredicatedMethod() {
		TypePredicatedExtendedTest f1 = new TypePredicatedExtendedTest();
		TypePredicatedImplementedTest f2 = new TypePredicatedImplementedTest();
	}
	
	public void generalizedMethod() {
		TypePredicatedSuperClass f1 = new TypePredicatedExtendedTest();
		TypePredicatedInterface f2 = new TypePredicatedImplementedTest();
	}
}
