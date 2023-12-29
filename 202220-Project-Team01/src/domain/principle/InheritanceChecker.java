package domain.principle;

import java.util.ArrayList;

import datasource.LinterClass;
import datasource.LinterField;
import datasource.LinterMethod;
import domain.interfaces.PrincipleChecker;

public class InheritanceChecker implements PrincipleChecker{

	@Override
	public void doCheck(ArrayList<LinterClass> classes) {
		String similarities = "";
		for(int i = 0; i < classes.size(); i++) {
			LinterClass c1 = classes.get(i);
			ArrayList<LinterMethod> methods1 = c1.getMethodLinter().getLinterMethods();
			ArrayList<LinterField> fields1 = c1.getFields();
			String c1Name = c1.getName();
			for(int j = i+1; j < classes.size(); j++) {
				LinterClass c2 = classes.get(j);
				String c2Name = c2.getName();
				// Classes which extend or implement one another will, by default, have similarities, so ignore these cases.
				
				if (c1.getExtended().equals(c2Name) || c2.getExtended().equals(c1Name) ||
						c1.getImplemented().contains(c2Name) || c2.getImplemented().contains(c1Name)) {
					continue;
				}
				
				int methodSimilarities = 0;
				int variableSimilarities = 0;
				ArrayList<LinterMethod> methods2 = c2.getMethodLinter().getLinterMethods();
				ArrayList<LinterField> fields2 = c2.getFields();
				for (int q = 0; q < methods1.size(); q++) {
					LinterMethod m1 = methods1.get(q);
					String m1Name = m1.getName();
					if(m1Name.equals("<init>")) {
						continue;
					}
					for (int x = 0; x < methods2.size(); x++) {
						LinterMethod m2 = methods2.get(x);
						String m2Name = m2.getName();
						if(m2Name.equals("<init>")) {
							continue;
						}
						if(m1Name.equals(m2Name) && m1.getArguments().toString().equals(m2.getArguments().toString())) {
							System.out.println("Similar methods " + m1Name + " and " + m2Name + " detected in classes " 
									+ c1Name + " and " + c2Name);
							methodSimilarities++;
						}
					}
				}
				for (int q = 0; q < fields1.size(); q++) {
					LinterField f1 = fields1.get(q);
					String f1Name = f1.getName();
					for (int x = 0; x < fields2.size(); x++) {
						LinterField f2 = fields2.get(x);
						String f2Name = f2.getName();
						if (f1Name.equals(f2Name) && f1.getType().equals(f2.getType())) {
							System.out.println("Similar arguments " + f1Name + " and " + f2Name + " detected in classes "
									+ c1Name + " and " + c2Name);
							variableSimilarities++;
						}
					}
				}
				if (methodSimilarities >= 2 && variableSimilarities >= 3) {
					similarities += "\nClasses " + c1Name + " and " + c2Name +
							" have many similarities. Consider abstracting them.";
				}
			}
		}
		System.out.println(similarities + "\n");
	}

}
