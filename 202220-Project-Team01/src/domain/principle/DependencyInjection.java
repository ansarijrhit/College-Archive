package domain.principle;

import java.util.ArrayList;
import java.util.Spliterators.AbstractIntSpliterator;

import org.objectweb.asm.tree.AbstractInsnNode;
import org.objectweb.asm.tree.MethodInsnNode;

import datasource.LinterClass;
import datasource.LinterMethod;
import domain.interfaces.PrincipleChecker;

public class DependencyInjection implements PrincipleChecker{

    private boolean check;
    private String className;

    @Override
    public void doCheck(ArrayList<LinterClass> classes) {
        for(LinterClass c : classes) {
            check = false;
            className = c.getSimpleName();
            for(LinterMethod lm : c.getMethodLinter().getLinterMethods()) {
                if(lm.getName().equals("<init>") && !c.getIsInterface()) {
                    int i = 0;
                    for(AbstractInsnNode ai : lm.getInsnList()) {
                        if(ai.getType() == 5) { // if type = 5, this means the instruction is a method caller
                            i++; // constructor seemed to ping twice, this line made it so it only appeared once
                            if(i >= 2) check = true;
                        }
                    }
                }
            }
            if(check) {
                System.out.println("Initialization of class found in " + className + "'s constructor. Possible dependency injection needed");
            }
        }
        
    }
    
}
