package domain.cursory;

import java.util.ArrayList;

import datasource.LinterClass;
import datasource.LinterField;
import domain.interfaces.CursoryChecker;

public class GetterChecker implements CursoryChecker{

	@Override
	public void doCheck(ArrayList<LinterClass> classes) {
		for(LinterClass c : classes) {
			for(LinterField f : c.getFields()) {
				if(f.isPublic()) {
					System.out.println("\nfield " + f.getName() + " is listed as public in class " + c.getSimpleName());
					System.out.println("You may want to set " + f.getName() + " to private and create the following getter:\n");
					String methodName = f.getName();
					methodName = methodName.substring(0, 1).toUpperCase() + methodName.substring(1, methodName.length());
					System.out.println("public " + f.getType().getClass().getSimpleName() + " get" + methodName + "(){");
					System.out.println("return this." + f.getName() + ";");
					System.out.println("}\n");
					//possible to set to private and generate getter?
				}
			}
		}
		
	}

}
