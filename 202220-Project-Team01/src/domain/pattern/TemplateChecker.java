package domain.pattern;

import java.util.ArrayList;

import datasource.LinterClass;
import datasource.LinterField;
import datasource.LinterMethod;
import domain.interfaces.PatternChecker;

public class TemplateChecker implements PatternChecker{

	@Override
	public void doCheck(ArrayList<LinterClass> classes) {		
		for(LinterClass source : classes) {
			//if the current class extends something
			if(!(source.getSimpleExtended().equals("Object"))){
				
				//get extended class
				LinterClass extended = getExtendedClass(source, classes);
				
				//determine if extended class is abstract
				boolean extendedIsAbstract = extended.getIsAbstract();
				
				//determine if extended class has a final method
				String finalMethod = getFinalMethod(extended);
				
				//determine if abstract methods are used in the extended class
				ArrayList<String> usedAbstractMethods = getAbstractMethodNames(extended);
				
				//print result
				printResult(extendedIsAbstract, finalMethod, source, extended, usedAbstractMethods);
			}
		}
		
		
	}
	
	private LinterClass getExtendedClass(LinterClass source, ArrayList<LinterClass> classes) {
		//DONE: find the extend class of the source class
		for(LinterClass cur : classes) {
			if(cur.getSimpleName().equals(source.getSimpleExtended())) {
				//System.out.println("class: " + source.getSimpleName() + " extends class: " + cur.getSimpleName());
				return cur;
			}
		}
		return null;
	}
	
	private String getFinalMethod(LinterClass abstr) {
		//DONE: determine if a final method exists
		for(LinterMethod cur : abstr.getMethodLinter().getLinterMethods()) {
			if(cur.getIsFinal()) {
				//System.out.println("class: " + abstr.getSimpleName() + " has final method: " + cur.getName());
				return cur.getName();
			}
		}
		return null;
	}
	
//	private ArrayList<String> getUsedAbstractMethodNames(LinterClass source, LinterClass abstr){
//		//TODO: determine shared methods
//		ArrayList<String> em = getAbstractMethodNames(abstr);
//		System.out.println("extended has abstract methods: " + em.toString());
//		ArrayList<String> shared = new ArrayList<String>();
//		
//		for(LinterMethod cur : source.getMethodLinter().getLinterMethods()) {
//			if(em.contains(cur.getName())){
//				shared.add(cur.getName());
//			}
//		}
//		
//		System.out.println("the following abstract classes are implemented in source: " + shared.toString());
//		return shared;
//	}

	private ArrayList<String> getAbstractMethodNames(LinterClass extended) {
		ArrayList<String> methods = new ArrayList<String>();
		for(LinterMethod cur : extended.getMethodLinter().getLinterMethods()) {
			if(cur.isAbstract()) {
				methods.add(cur.getName());
			}
		}
		//System.out.println("the extended class has abstract methods: " + methods.toString());
		return methods;
	}
	
	private void printResult(boolean extendedIsAbstract, String finalMethod, LinterClass source, LinterClass extended, ArrayList<String> usedAbstractMethods) {
		if(extendedIsAbstract && (finalMethod != null) && (usedAbstractMethods.size() > 0)) {
			System.out.println("Template Method Detected. Class: " + source.getSimpleName() + " extends abstract Class: " + extended.getSimpleName() 
			+ " which uses the final method " + finalMethod + " and implements the abstract methods " + usedAbstractMethods.toString());
		}
		
		//missing abstract method implementations
		if(extendedIsAbstract && (finalMethod != null) && !(usedAbstractMethods.size() > 0)) {
			System.out.println("Improper Template Method Detected. Class: " + source.getSimpleName() + " extends the abstract Class: " + extended.getSimpleName()
			+ " which uses the final method " + finalMethod + " but does not implement any abstract methods");
		}
		
		//missing final method
		if(extendedIsAbstract && !(finalMethod != null) && (usedAbstractMethods.size() > 0)) {
			System.out.println("Improper Template Method Detected. Class: " + source.getSimpleName() + " extends abstract Class: " + extended.getSimpleName() 
			+ " and implements the abstract methods " + usedAbstractMethods.toString() + " but its template does not have a final method");
		}
		
		//missing abstract implementations and final method
		if(extendedIsAbstract && !(finalMethod != null) && !(usedAbstractMethods.size() > 0)) {
			System.out.println("Improper Template Method Detected. Class: " + source.getSimpleName() + " extends abstract Class: " + extended.getSimpleName() 
			+ " but it does not implement abstract methods nor does its template have a final method");
		}
	}




	

	

	

}
