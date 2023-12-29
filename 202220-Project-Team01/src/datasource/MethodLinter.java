package datasource;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;

import org.objectweb.asm.Opcodes;
import org.objectweb.asm.Type;
import org.objectweb.asm.tree.AbstractInsnNode;
import org.objectweb.asm.tree.ClassNode;
import org.objectweb.asm.tree.InsnList;
import org.objectweb.asm.tree.LocalVariableNode;
import org.objectweb.asm.tree.MethodInsnNode;
import org.objectweb.asm.tree.MethodNode;
import org.objectweb.asm.tree.ParameterNode;
import org.objectweb.asm.tree.VarInsnNode;

public class MethodLinter extends Linter {
	
	private ArrayList<LinterMethod> methods;
	private ArrayList<String> localVarNames;
	private ArrayList<String> classMethodCalls;
	
	public MethodLinter(ClassNode c) {
		super(c);
	}
	
	protected void printMe(ClassNode classNode) {
		methods = new ArrayList<LinterMethod>();
		List<MethodNode> cMethods = (List<MethodNode>) classNode.methods;
		for (MethodNode method : cMethods) {
			ArrayList<String> argumentTypes = new ArrayList<String>();
			ArrayList<String> argumentNames = new ArrayList<String>();
//			 for (LocalVariableNode var : method.localVariables) {
//			 	argumentTypes.add(var.signature);
//			 	argumentNames.add(var.name);
//			 }
			printInstructions(method);
			ArrayList<String> localVarTypes = getLocalVarTypes(method);
			
			methods.add(new LinterMethod(method.name, method.desc, Type.getReturnType(method.desc).getClassName(), argumentTypes, 
					argumentNames, localVarNames, localVarTypes, classMethodCalls, ((method.access & Opcodes.ACC_STATIC) != 0), 
					((method.access & Opcodes.ACC_PUBLIC) != 0), ((method.access & Opcodes.ACC_FINAL) != 0), ((method.access & Opcodes.ACC_ABSTRACT) != 0), method.instructions));
			
		}
	}
	
	private void printInstructions(MethodNode methodNode) {
		InsnList instructions = methodNode.instructions;
		localVarNames = new ArrayList<String>();
		classMethodCalls = new ArrayList<String>();
		for (int i = 0; i < instructions.size(); i++) {
	
			// We don't know immediately what kind of instruction we have.
			AbstractInsnNode insn = instructions.get(i);
			if (insn instanceof VarInsnNode) {
				VarInsnNode varInsn = (VarInsnNode) insn;				
				LocalVariableNode v = getLocalVariableNode(varInsn, methodNode);
				localVarNames.add(v.name);
			}
			else if (insn instanceof MethodInsnNode) {
				MethodInsnNode methodCall = (MethodInsnNode) insn;
				classMethodCalls.add(methodCall.owner);
			} 
		}
	}
	
	private ArrayList<String> getLocalVarTypes(MethodNode methodNode) {
		InsnList instructions = methodNode.instructions;
		ArrayList<String> localVarTypes = new ArrayList<String>();
		for (int i = 0; i < instructions.size(); i++) {
	
			// We don't know immediately what kind of instruction we have.
			AbstractInsnNode insn = instructions.get(i);
			if (insn instanceof VarInsnNode) {
				VarInsnNode varInsn = (VarInsnNode) insn;				
				LocalVariableNode v = getLocalVariableNode(varInsn, methodNode);
				localVarTypes.add(v.desc);
			}
		}
		return localVarTypes;
	}
	
	// Method Source: https://www.javatips.net/api/org.objectweb.asm.tree.localvariablenode
	
	private LocalVariableNode getLocalVariableNode(VarInsnNode varInsnNode, MethodNode methodNode) {
        int varIndex = varInsnNode.var;
        int instrIndex = getInstructionIndex(varInsnNode);
        List<?> localVariables = methodNode.localVariables;
        for (int i = 0; i < localVariables.size(); i++) {
            LocalVariableNode localVariableNode = (LocalVariableNode) localVariables.get(i);
            if (localVariableNode.index == varIndex) {
                int scopeEndInstrIndex = getInstructionIndex(localVariableNode.end);
                if (scopeEndInstrIndex >= instrIndex) {
                    return localVariableNode;
                }
            }
        }
        throw new RuntimeException("Variable with index " + varIndex + " and scope end >= " + instrIndex
                + " not found for method " + methodNode.name + "!");
    }
	private int getInstructionIndex(AbstractInsnNode insnNode) {
        try {
            Field indexField = AbstractInsnNode.class.getDeclaredField("index");
            indexField.setAccessible(true);
            Object indexValue = indexField.get(insnNode);
            return ((Integer) indexValue).intValue();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
	
	public ArrayList<LinterMethod> getLinterMethods() {
		return methods;
	}
}
