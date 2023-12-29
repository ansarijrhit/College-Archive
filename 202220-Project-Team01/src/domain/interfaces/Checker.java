package domain.interfaces;

import java.util.ArrayList;

import datasource.LinterClass;

public interface Checker {
	public void doCheck(ArrayList<LinterClass> classes);
}
