package datasource;

import org.objectweb.asm.tree.ClassNode;

public abstract class Linter {
	protected ClassNode c;
	
	public Linter(ClassNode c) {
		this.c = c;
		printMe(c);
	}
	
	protected abstract void printMe(ClassNode classNode);
}
