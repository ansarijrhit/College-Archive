package domain.cursory;

import java.util.ArrayList;

import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.tree.AbstractInsnNode;
import org.objectweb.asm.tree.FieldInsnNode;
import org.objectweb.asm.tree.InsnList;
import org.objectweb.asm.tree.MethodInsnNode;
import org.objectweb.asm.tree.VarInsnNode;

import datasource.LinterClass;
import datasource.LinterMethod;
import domain.interfaces.CursoryChecker;

public class ClassConstructionChecker implements CursoryChecker{

    @Override
    public void doCheck(ArrayList<LinterClass> classes) {
        for(LinterClass c : classes) {
            String className = c.getSimpleName();
            boolean correct = false; // this is so that the not publicly constructable does not ping multiple times for the same class
            for(LinterMethod ml : c.getMethodLinter().getLinterMethods()) {
                if(ml.getIsPublic() && ml.getName().equals("<init>") || ml.getIsPublic() && ml.getRetType().equals(className)) correct = true;
            }
            if(!correct && !c.getIsInterface()) {
                System.out.println("Class " + className + " is not publicly constructable");
            }
        }
    } 
}
