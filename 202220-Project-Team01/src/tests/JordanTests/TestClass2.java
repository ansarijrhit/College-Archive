package tests.JordanTests;

import java.util.ArrayList;

import datasource.LinterClass;
import domain.interfaces.PatternChecker;

public class TestClass2 implements PatternChecker {
	private int index = 0;
	private String camelCase;
	private boolean falsy = false;
	
	public boolean returnTrue(double unused) {
		return true;
	}
	
	private static void BadCase(String MoreBadCase) {
		int EvenMoreBadCase = 0;
	}
	
	public int getOne() {
		int one = 1;
		return one;
	}
	
	public void message() {
		
	}

	@Override
	public void doCheck(ArrayList<LinterClass> classes) {
		// TODO Auto-generated method stub
		
	}
}
