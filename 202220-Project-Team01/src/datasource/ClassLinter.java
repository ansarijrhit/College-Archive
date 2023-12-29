package datasource;

import org.objectweb.asm.tree.ClassNode;

import java.util.ArrayList;
import java.util.List;

import org.objectweb.asm.Opcodes;
import org.objectweb.asm.Type;
import org.objectweb.asm.tree.FieldNode;
import org.objectweb.asm.tree.InnerClassNode;


public class ClassLinter extends Linter {
	
	private LinterClass linterClass;
	ArrayList<String> innerClasses = new ArrayList<String>();
	static ArrayList<String> principleChecks = new ArrayList<>();
	static ArrayList<String> patternChecks = new ArrayList<>();
	static ArrayList<String> cursoryChecks = new ArrayList<>();
	
	public ClassLinter(ClassNode c) {
		super(c);
		printFields(c);
		printInnerClasses(c);
		addChecks(c);
	}
	
	private void addChecks(ClassNode c) {
		List<String> unsplitArr = c.interfaces;
		List<String> splitArr = new ArrayList<>();
		String[] classNameArray = c.name.split("/");
		String className = classNameArray[classNameArray.length - 1];
		for(String s : unsplitArr) {
			String[] arr = s.split("/");
			splitArr.add(arr[arr.length - 1]);
		}
		for(int i = 0; i < splitArr.size(); i++) {
			String comp = splitArr.get(i);
			if(comp.equals("CursoryChecker")) {
				cursoryChecks.add(className);
			} else if (comp.equals("PatternChecker")) {
				patternChecks.add(className);
			} else if (comp.equals("PrincipleChecker")) {
				cursoryChecks.add(className);
			}
		}
	}

	protected void printMe(ClassNode classNode) {
// 		System.out.println("Class's Internal JVM name: " + classNode.name);
		String uName = Type.getObjectType(classNode.name).getClassName().replace('.', '/');
// 		System.out.println("User-friendly name: " + Type.getObjectType(classNode.name).getClassName());
// 		System.out.println("public? " + ((classNode.access & Opcodes.ACC_PUBLIC) != 0));
		String[] classNameArr = classNode.name.split("/");
		String className = classNameArr[classNameArr.length - 1];
// //		System.out.println("Pascal Case? " + n.pascalCase(className));
// 		System.out.println("Extends: " + classNode.superName);
// 		System.out.println("Implements: " + classNode.interfaces);
		linterClass = new LinterClass(classNode.name, uName, ((classNode.access & Opcodes.ACC_PUBLIC) != 0), 
				(classNode.access & Opcodes.ACC_INTERFACE) != 0, (classNode.access & Opcodes.ACC_ABSTRACT) != 0,
				classNode.superName, classNode.interfaces, new MethodLinter(c), classNode);
	}
	
	private void printFields(ClassNode classNode) {
		// Print all fields (note the cast; ASM doesn't store generic data with its
		// Lists)
		ArrayList<LinterField> fields = new ArrayList<LinterField>();
		List<FieldNode> cFields = (List<FieldNode>) classNode.fields;
		for (FieldNode field : cFields) {
			// System.out.println("	Field: " + field.name);
//			String name, String desc, String type, String signature, int access, Object value,
//			boolean isPublic
			fields.add(new LinterField(field.name, field.desc, Type.getObjectType(field.desc).getClassName(),
					field.signature, field.access, field.value, ((field.access & Opcodes.ACC_PUBLIC) != 0)));
		}
		linterClass.setFields(fields);
	}
	
	private void printInnerClasses(ClassNode classNode) {
		List<InnerClassNode> innerClass = classNode.innerClasses;
        for(InnerClassNode c: innerClass){
            // System.out.println(c.name);
        	innerClasses.add(c.name);
        }
	}
	
	public ArrayList<String> getInnerClasses() {
		return innerClasses;
	}
	
	public LinterClass getLinterClass() {
		return linterClass;
	}
}
