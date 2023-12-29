package presentation;

import java.io.IOException;
import java.util.ArrayList;

import org.objectweb.asm.ClassReader;
import org.objectweb.asm.tree.ClassNode;

import datasource.ClassLinter;
import datasource.ConfigSettings;
import datasource.LinterClass;
import domain.HunterLintHandler;
import domain.IanLintHandler;
import domain.JordanLintHandler;
import domain.LintHandler;
import domain.cursory.ClassConstructionChecker;
import domain.interfaces.Checker;

// FIXME: this code has TERRIBLE DESIGN all around
public class Main {
	String[] fieldForAnalysisByThisProgram = new String[1];
	
	public static void runLinters() throws IOException{
		ArrayList<String> classNames = ConfigSettings.load(1);
		ArrayList<String> linterNames = ConfigSettings.load(2);
		ArrayList<ClassNode> classes = getClassNodes(classNames);
		
		for(String l : linterNames) {
			switch (l) {
				case "HunterLintHandler": new HunterLintHandler(classes);
												  break;
												  
				case "IanLintHandler":    new IanLintHandler(classes);
				  								  break;
				  								  
				case "JordanLintHandler": new JordanLintHandler(classes);
				  								  break;
				  								  
				default: System.out.println("lint handler not found");
			}
				
		}
	}
	
	public static ArrayList<ClassNode> getClassNodes(ArrayList<String> classNames) throws IOException{
		ArrayList<ClassNode> classes = new ArrayList<ClassNode>();
		
		for (String className : classNames) {
			// The 3 steps read in a Java class:
			// 1. ASM's ClassReader does the heavy lifting of parsing the compiled Java
			// class.
			ClassReader reader = null;
			try {
			 reader = new ClassReader(className);
			} catch(IOException e) {
				 System.err.println("Class " + className + " not found. Continuing...");
				continue;
			}

			// 2. ClassNode is just a data container for the parsed class
			ClassNode classNode = new ClassNode();

			// 3. Tell the Reader to parse the specified class and store its data in our
			// ClassNode.
			// EXPAND_FRAMES means: I want my code to work. (Always pass this flag.)
			reader.accept(classNode, ClassReader.EXPAND_FRAMES);

			// Now we can navigate the classNode and look for things we are interested in.
			classes.add(classNode);
		}
		
		return classes;
		
	}
	
	public static void main(String[] args) throws IOException {	
		new LinterView();
	}
}
