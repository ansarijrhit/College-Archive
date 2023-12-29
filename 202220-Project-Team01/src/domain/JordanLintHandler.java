package domain;

import java.util.ArrayList;

import org.objectweb.asm.tree.ClassNode;

import domain.cursory.ProperCaseChecker;
import domain.interfaces.Checker;
import domain.pattern.AdapterChecker;
import domain.principle.InheritanceChecker;

public class JordanLintHandler extends LintHandler {
	
	public JordanLintHandler(ArrayList<ClassNode> classes) {
		super(classes);
		cursoryStyleCheck();
		principleCheck();
		patternCheck();
	}
	
	public void cursoryStyleCheck() {
		Checker cc = new ProperCaseChecker();
		cc.doCheck(classes);
	}
	
	public void principleCheck() {
		Checker pc = new InheritanceChecker();
		pc.doCheck(classes);
	}

	public void patternCheck() {
		Checker pc = new AdapterChecker();
		pc.doCheck(classes);
	}
}
