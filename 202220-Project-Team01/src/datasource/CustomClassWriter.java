package datasource;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.regex.Pattern;
import java.util.stream.Stream;

import org.objectweb.asm.ClassReader;
import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.ClassWriter;
import org.objectweb.asm.FieldVisitor;
import org.objectweb.asm.Label;
import org.objectweb.asm.MethodVisitor;
import org.objectweb.asm.Opcodes;
import org.objectweb.asm.tree.ClassNode;
import org.objectweb.asm.tree.FieldNode;

public class CustomClassWriter {
	ClassReader reader;
	ClassWriter writer;

	public static void main(String[] args) {
		new CustomClassWriter("tests.TestClass");
	}
	
	public CustomClassWriter(String className) {
		try {
			reader = new ClassReader(className);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		ClassNode classNode = new ClassNode();
		reader.accept(classNode, ClassReader.EXPAND_FRAMES);
		ClassLinter cl = new ClassLinter(classNode);
		LinterClass lc = cl.getLinterClass();
		
		writer = new ClassWriter(reader, 0);
		CustomClassAdapter ca = new CustomClassAdapter();
		
		ArrayList<LinterField> fields = lc.getFields();
		
		
		for(LinterField f : fields) {
			if (!camelCase(f.getName())) {
				byte[] ret = ca.addField(f);
//				ca.visitField(f.getAccess(), f.getName(), toCamelCase(f.getName()), f.getDesc(), f.getSignature(), f.getValue());
//				output = concatenate(output, ret);
			}
		}

		byte[] output = writer.toByteArray();
	}
	public <T> byte[] concatenate(byte[] a, byte[] b) {
	    int aLen = a.length;
	    int bLen = b.length;

	    @SuppressWarnings("unchecked")
	    byte[] c = (byte[]) Array.newInstance(a.getClass().getComponentType(), aLen + bLen);
	    System.arraycopy(a, 0, c, 0, aLen);
	    System.arraycopy(b, 0, c, aLen, bLen);

	    return c;
	}

	public boolean camelCase(String fieldName) {
//		Pattern p = Pattern.compile("^[a-z]+(?:[A-Z][a-z]+)*$");
		return Pattern.compile("^[a-z]+([A-Z][a-z0-9]+|[0-9]+)*+").matcher(fieldName).matches();
	}
	
	public String toCamelCase(String fieldName) {
		return (fieldName.charAt(0) + "").toLowerCase() + fieldName.substring(1, fieldName.length());
	}
	
	public void modifyField(FieldNode f) {
		FieldVisitor fv = writer.visitField(f.access, f.name, f.desc, f.signature, f.value);
	}
	
	public class CustomClassAdapter {
	    AddFieldAdapter addFieldAdapter;
	    public byte[] addField(LinterField f) {
	        addFieldAdapter = new AddFieldAdapter(toCamelCase(f.getName()), f.getDesc(), f.getAccess(), writer);
	        reader.accept(addFieldAdapter, 0);
	        return writer.toByteArray();
	    }
	}
	
	public class AddFieldAdapter extends ClassVisitor {
	    private String fieldName;
	    private String fieldDesc;
	    private int access = org.objectweb.asm.Opcodes.ACC_PUBLIC;
	    private boolean isFieldPresent;

	    public AddFieldAdapter(
	      String fieldName, String fieldDesc, int fieldAccess, ClassVisitor cv) {
	        super(Opcodes.ASM9, cv);
	        this.cv = cv;
	        this.fieldName = fieldName;
	        this.fieldDesc = fieldDesc;
	        this.access = fieldAccess;
	    }
	    
	    @Override
	    public FieldVisitor visitField(
	      int access, String name, String desc, String signature, Object value) {
	        if (name.equals(fieldName)) {
	            isFieldPresent = true;
	        }
	        return cv.visitField(access, name, desc, signature, value); 
	    }
	    
	    @Override
	    public void visitEnd() {
	        if (!isFieldPresent) {
	            FieldVisitor fv = cv.visitField(
	              access, fieldName, fieldDesc, null, null);
	            if (fv != null) {
	                fv.visitEnd();
	            }
	        }
	        cv.visitEnd();
	    }
	}

//	public class ClassAdapter extends ClassVisitor {
//		private ClassWriter cw;
//		public ClassAdapter(ClassWriter cw) {
//			super(Opcodes.ASM9);
//			this.cw = cw;
//		}
//
//		@Override
//		public MethodVisitor visitMethod(int access, String name, String desc, String signature, String[] exceptions) {
//			MethodVisitor mv = cv.visitMethod(access, name, desc, signature, exceptions);
//			return mv;
//		}
//
//		@Override
//		public FieldVisitor visitField(int access, String name, String descriptor, String signature,
//				Object value) {
//			return null;
//		}
//
//		public FieldVisitor visitField(int access, String name, String newName, String descriptor, String signature,
//				Object value) {
//			this.visitField(access, name, descriptor, signature, value);
//			FieldVisitor fv = cw.visitField(access, newName, descriptor, signature, value);
//			return fv;
//		}
//	}
//
//	public class MethodAdapter extends MethodVisitor {
//		public MethodAdapter(MethodVisitor mv) {
//			super(Opcodes.ASM9, mv);
//		}
//
//		@Override
//		public void visitLocalVariable(String name, String desc, String signature, Label start, Label end, int index) {
//			// Put your rename logic here
//			if (name.equals("c"))
//				name = "e";
//			else if (name.equals("d"))
//				name = "f";
//			super.visitLocalVariable(name, desc, signature, start, end, index);
//		}
//	}

}