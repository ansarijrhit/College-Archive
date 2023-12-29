package domain;

import java.util.ArrayList;

import org.objectweb.asm.tree.ClassNode;

import domain.cursory.ClassConstructionChecker;
import domain.interfaces.Checker;
import domain.pattern.StrategyCheck;
import domain.principle.DependencyInjection;

public class IanLintHandler extends LintHandler{

    public IanLintHandler(ArrayList<ClassNode> classes) {
        super(classes);
        cursoryStyleCheck();
        principleCheck();
        patternCheck();
    }

    @Override
    public void cursoryStyleCheck() {
        Checker cursoryCheck = new ClassConstructionChecker();
        cursoryCheck.doCheck(classes);
    }

    @Override
    public void principleCheck() {
        Checker pCheck = new DependencyInjection();
        pCheck.doCheck(classes);
    }

    @Override
    public void patternCheck() {
        Checker patCheck = new StrategyCheck();
        patCheck.doCheck(classes);
    }
    
}
