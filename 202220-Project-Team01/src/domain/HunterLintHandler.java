package domain;

import java.util.ArrayList;

import org.objectweb.asm.tree.ClassNode;

import domain.cursory.GetterChecker;
import domain.interfaces.Checker;
import domain.pattern.TemplateChecker;
import domain.principle.TypePredicatedChecker;

public class HunterLintHandler extends LintHandler{

	public HunterLintHandler(ArrayList<ClassNode> classes) {
		super(classes);
		cursoryStyleCheck();
		principleCheck();
		patternCheck();
	}

	@Override
	public void cursoryStyleCheck() {
		Checker cc = new GetterChecker();
		cc.doCheck(classes);
	}

	@Override
	public void principleCheck() {
		Checker cc = new TypePredicatedChecker();
		cc.doCheck(classes);
	}

	@Override
	public void patternCheck() {
		Checker cc = new TemplateChecker();
		cc.doCheck(classes);
	}

}
