package domain.principle;

import java.util.ArrayList;
import java.util.List;

import org.objectweb.asm.tree.AbstractInsnNode;
import org.objectweb.asm.tree.LocalVariableNode;
import org.objectweb.asm.tree.VarInsnNode;

import datasource.ClassLinter;
import datasource.LinterClass;
import datasource.LinterField;
import datasource.LinterMethod;
import datasource.MethodLinter;
import domain.interfaces.PrincipleChecker;

public class TypePredicatedChecker implements PrincipleChecker {
	
	@Override
	public void doCheck(ArrayList<LinterClass> classes) {
		for(LinterClass source : classes) {
			checkFields(source, classes);
			checkMethods(source, classes);
		}

	}

	private void checkMethods(LinterClass source, ArrayList<LinterClass> classes) {
		for(LinterMethod m : source.getMethodLinter().getLinterMethods()) {
			//TODO: detect type predicated code inside of methods
			//System.out.println(m.getName());
			for(String type : m.getSimpleLocalVarTypes()) {
				
				//for each variable, get its linterclass
				LinterClass curClass = null;
				for(LinterClass c: classes) {
					if(c.getSimpleName().equals(type)) {
						curClass = c;
					}
				}
				
				//if null or constructor, skip
				if(curClass == null || m.getName().equals("<init>")) {
					continue;
				}
				
				//then get generalizations
				ArrayList<String> generalizations = getGeneralizationNames(curClass);
				
				//print result
				printMethodResult(source, m, curClass, generalizations);
			}
		}
	}

	private void checkFields(LinterClass source, ArrayList<LinterClass> classes) {
		for(LinterField f : source.getFields()) {
			//use name to get class node
			LinterClass curClass = getLinterClassByName(f.getType(), classes);
			
			//if null, skip since it is not in the directory
			if(curClass == null) {
				continue;
			}
			
			//get any generalizations
			ArrayList<String> generalizations = getGeneralizationNames(curClass);
			
			//print result
			printFieldResult(source, f, curClass, generalizations);
		}
	}

	private ArrayList<String> getGeneralizationNames(LinterClass curClass) {
		ArrayList<String> generalizations = new ArrayList<String>();
			//add extended class if it has one
		if(!(curClass.getSimpleExtended().equals("Object"))) {
			generalizations.add(curClass.getSimpleExtended());
		}
		
		//add implemented classes if it has any
		for(String curImp : curClass.getSimpleImplemented()) {
			generalizations.add(curImp);
		}
			
		return generalizations;
	}

	private LinterClass getLinterClassByName(String name, ArrayList<LinterClass> classes) {
		for(LinterClass source : classes) {
			if(source.getSimpleName().equals(name)) {
				return source;
			}
		}
		return null;
		
	}

	//once you know the type is type predicated, you can print the result
	private void printFieldResult(LinterClass source, LinterField f, LinterClass predication, ArrayList<String> generalizations) {
		if(generalizations.size() == 0) {
			return;
		}
		System.out.println("Type predicated code detected. Class: " + source.getSimpleName() + " has a field named " + f.getName() +" using the Class: " + 
						    predication.getSimpleName() + " instead of its generalize form(s) Classes: " + generalizations);
	}
	
	private void printMethodResult(LinterClass source, LinterMethod m, LinterClass predication, ArrayList<String> generalizations) {
		if(generalizations.size() == 0) {
			return;
		}
		System.out.println("Type predicated code detected. Class: " + source.getSimpleName() + " has a var in method named " + m.getName() + " using the Class: " + 
						    predication.getSimpleName() + " instead of its generalize form(s) Classes: " + generalizations);
	}
}
