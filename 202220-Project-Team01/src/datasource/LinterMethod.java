package datasource;

import java.util.ArrayList;
import java.util.List;

import org.objectweb.asm.Opcodes;
import org.objectweb.asm.Type;
import org.objectweb.asm.tree.InsnList;

public class LinterMethod {
	
	private String name, signature, retType;
	private boolean isPublic, isStatic, isFinal, isAbstract;
	private ArrayList<String> arguments, argumentNames, localVarNames, localVarTypes, classMethodCalls;
	private InsnList instructions;
	public LinterMethod(String name, String signature, String retType, ArrayList<String> arguments, 
			ArrayList<String> argumentNames, ArrayList<String> localVarNames, ArrayList<String> localVarTypes, 
			ArrayList<String> classMethodCalls, boolean isStatic, boolean isPublic, boolean isFinal, 
			boolean isAbstract, InsnList instructions) {
		super();
		this.name = name;
		this.signature = signature;
		this.retType = retType;
		this.isPublic = isPublic;
		this.isStatic = isStatic;
		this.isFinal = isFinal;
		this.isAbstract = isAbstract;
		this.arguments = arguments;
		this.argumentNames = argumentNames;
		this.localVarNames = localVarNames;
		this.localVarTypes = localVarTypes;
		this.classMethodCalls = classMethodCalls;
		this.instructions = instructions;
	}

    public String getName() {
		return name;
	}
	public String getSignature() {
		return signature;
	}
	public String getRetType() {
		String[] arr = retType.split("\\.");
		return arr[arr.length - 1];
	}
	public boolean getIsPublic() {
		return isPublic;
	}
	public boolean getIsStatic() {
		return isStatic;
	}
	public InsnList getInsnList() {
		return instructions;
	}
	public ArrayList<String> getArguments() {
		return arguments;
	}
	public ArrayList<String> getArgumentNames() {
		return argumentNames;
	}
	public ArrayList<String> getLocalVarNames() {
		return localVarNames;
	}
	public ArrayList<String> getLocalVarTypes(){
		return localVarTypes;
	}
	public ArrayList<String> getClassMethodCalls(){
		return classMethodCalls;
	}
	public List<String> getSimpleLocalVarTypes(){
		List<String> simple = new ArrayList<String>();
		for(String cur: localVarTypes) {
			String[] typeArr = cur.split("/");
			String simpleType = typeArr[typeArr.length-1];
			simpleType = simpleType.substring(0, simpleType.length()-1);
			simple.add(simpleType);
		}
		return simple;
	}
	public boolean getIsFinal() {
		return isFinal;
	}
	public boolean isAbstract() {
		return isAbstract;
	}
}
