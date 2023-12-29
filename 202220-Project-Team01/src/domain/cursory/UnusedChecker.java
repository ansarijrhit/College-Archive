package domain.cursory;

import java.util.ArrayList;
import java.util.HashMap;

import datasource.LinterClass;
import datasource.LinterField;
import datasource.LinterMethod;
import domain.interfaces.CursoryChecker;

public class UnusedChecker implements CursoryChecker{

	@Override
	public void doCheck(ArrayList<LinterClass> classes) {
		HashMap<String, Boolean> fieldMap = new HashMap<String, Boolean>();
		HashMap<String, Boolean> methodMap = new HashMap<String, Boolean>();
		
		for(LinterClass c : classes) {
			//set up hashmaps
			for(LinterField f : c.getFields()) {
				fieldMap.put(f.getName(), false);
			}
			for(LinterMethod m : c.getMethodLinter().getLinterMethods()) {
				methodMap.put(m.getName(), false);
			}
			
			System.out.println(fieldMap.keySet());
			System.out.println(methodMap.keySet());
			
			//go line by line in each method to see if the fields/methods are ever used
			
			for(LinterMethod m : c.getMethodLinter().getLinterMethods()) {
				
			}
		}
	}

}
