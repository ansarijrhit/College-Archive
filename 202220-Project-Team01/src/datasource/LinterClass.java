package datasource;

import java.util.ArrayList;
import java.util.List;

import org.objectweb.asm.Opcodes;
import org.objectweb.asm.Type;
import org.objectweb.asm.tree.ClassNode;

public class LinterClass {
	private String jvmName, name, extended, simpleName, simpleExtended;
	private boolean isPublic, isInterface, isAbstract;
	private List<String> implemented, simpleImplemented;
	private ArrayList<LinterField> fields;
	private MethodLinter methodLinter;
	private ClassNode classNode;
	
	public LinterClass(String jvmName, String name, boolean isPublic, boolean isInterface, boolean isAbstract, String extended, List<String> implemented, MethodLinter methodLinter, ClassNode classNode) {
		this.jvmName = jvmName;
		this.name = name;
		this.isPublic = isPublic;
		this.isInterface = isInterface;
		this.isAbstract = isAbstract;
		this.extended = extended;
		String[] extendedArr = extended.split("/");
		this.simpleExtended = extendedArr[extendedArr.length-1];
		this.implemented = implemented;
		this.simpleImplemented = makeSimpleImplementedList(implemented);
		this.methodLinter = methodLinter;
		String[] nameArr = name.split("/");
		this.simpleName = nameArr[nameArr.length-1];
		this.classNode = classNode;
	}
	private List<String> makeSimpleImplementedList(List<String> implementedInfo) {
		List<String> simple = new ArrayList<String>();
		for(String cur: implementedInfo) {
			String[] implementedArr = cur.split("/");
			String simpleImplemented = implementedArr[implementedArr.length-1];
			simple.add(simpleImplemented);
		}
		return simple;
	}
	public ArrayList<LinterField> getFields() {
		return fields;
	}
	public void setFields(ArrayList<LinterField> fields) {
		this.fields = fields;
	}
	public String getJvmName() {
		return jvmName;
	}
	public String getName() {
		return name;
	}
	public String getSimpleName() {
		return simpleName;
	}
	public boolean getIsPublic() {
		return isPublic;
	}
	public boolean getIsInterface() {
		return isInterface;
	}
	public boolean getIsAbstract() {
		return isAbstract;
	}
	public String getExtended() {
		return extended;
	}
	public String getSimpleExtended() {
		return simpleExtended;
	}
	public List<String> getImplemented() {
		return implemented;
	}
	public List<String> getSimpleImplemented(){
		return simpleImplemented;
	}
	public MethodLinter getMethodLinter() {
		return methodLinter;
	}

	public ClassNode getClassNode() {
		return classNode;
	}

}
