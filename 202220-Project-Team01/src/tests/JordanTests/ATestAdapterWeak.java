package tests.JordanTests;

public class ATestAdapterWeak implements ATestTarget {

	private ATestAdaptee adaptee;
	
	@Override
	public void doInterfaceStuff() {
		System.out.println("Oh boy, I do love being part of an adapter pattern!");
	}

}
