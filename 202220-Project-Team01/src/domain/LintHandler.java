package domain;

import java.io.IOException;
import java.util.ArrayList;

import org.objectweb.asm.ClassReader;
import org.objectweb.asm.tree.ClassNode;

import datasource.ClassLinter;
import datasource.LinterClass;

public abstract class LintHandler {
	protected ArrayList<LinterClass> classes;
	
	public LintHandler(ArrayList<ClassNode> myClasses) {
		ArrayList<ClassLinter> classLinters = new ArrayList<ClassLinter>();
//		int j = 0;
//		ArrayList<ClassNode> innerClasses = new ArrayList<ClassNode>();
		for(ClassNode c : myClasses) {
			classLinters.add(new ClassLinter(c));
//			for(String name : classLinters.get(j).getInnerClasses()) {
//				ClassReader reader;
//				try {
//					reader = new ClassReader(name);
//
//					// 2. ClassNode is just a data container for the parsed class
//					ClassNode classNode = new ClassNode();
//
//					// 3. Tell the Reader to parse the specified class and store its data in our
//					// ClassNode.
//					// EXPAND_FRAMES means: I want my code to work. (Always pass this flag.)
//					reader.accept(classNode, ClassReader.EXPAND_FRAMES);
//
//					// Now we can navigate the classNode and look for things we are interested in.
//					classLinters.add(new ClassLinter(classNode));
//				} catch (IOException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
//			}
//			j++;
		}
//		classLinters = classLinters.addAll(innerClasses);
		this.classes = new ArrayList<LinterClass>();
		for(int i = 0; i < classLinters.size(); i++) {
			this.classes.add(classLinters.get(i).getLinterClass());
		}
	}
	
	public abstract void cursoryStyleCheck();
	public abstract void principleCheck();
	public abstract void patternCheck();
}
