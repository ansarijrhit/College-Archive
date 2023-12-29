package domain.cursory;

import java.util.ArrayList;
import java.util.regex.Pattern;

import datasource.LinterClass;
import datasource.LinterField;
import datasource.LinterMethod;
import domain.interfaces.PrincipleChecker;

public class ProperCaseChecker implements PrincipleChecker{
	
	public boolean camelCase(String fieldName) {
//		Pattern p = Pattern.compile("^[a-z]+(?:[A-Z][a-z]+)*$");
		return Pattern.compile("^[a-z]+([A-Z][a-z0-9]+|[0-9]+)*+").matcher(fieldName).matches();
	}

	public boolean pascalCase(String fieldName) {
//		Pattern p = Pattern.compile("^[A-Z][a-z]+(?:[A-Z][a-z]+)*$");
//		return p.matcher(fieldName).matches();
		return Pattern.compile("([A-Z]*[a-z0-9]+)*+").matcher(fieldName).matches();
	}

	@Override
	public void doCheck(ArrayList<LinterClass> classes) {
		for(LinterClass c : classes) {
			String className = c.getSimpleName();
			if (!pascalCase(className)) {
				System.out.println("Class " + className + " is not named in pascal case (ex: PascalCase)");
			}
			for (LinterField f : c.getFields()) {
				if (!camelCase(f.getName())) {
					System.out.println(f.getType() + " " + f.getName() + " in class " + className + " is not in camel case (ex: camelCase)");
				}
			}
			for (LinterMethod m : c.getMethodLinter().getLinterMethods()) {
				String mName = m.getName();
				if(mName.equals("<init>")) {
					continue;
				}
				if (!camelCase(mName)) {
					System.out.println("Method " + mName + " in class " + className + " is not in camel case (ex: camelCase)");
				}
				for(String f : m.getArgumentNames()) {
					if (!camelCase(f)) {
						System.out.println("Field " + f + " in method " + mName + " in class " + className + " is not in camel case (ex: camelCase)");
					}
				}
				for(String v : m.getLocalVarNames()) {
					if (!camelCase(v)) {
						System.out.println("Local variable " + v + " in method " + mName + " in class " + className + " is not in camel case (ex: camelCase)");
					}
				}
			}
		}
	}


}
