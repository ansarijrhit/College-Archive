package domain.pattern;

import java.util.ArrayList;
import java.util.HashMap;

import datasource.LinterClass;
import datasource.LinterField;
import datasource.LinterMethod;
import domain.interfaces.PatternChecker;

public class AdapterChecker implements PatternChecker {
	
	private class Client {
		private String name;
		private ArrayList<String> composedClasses;
		private Client(String name) {
			this.name = name;
			this.composedClasses = new ArrayList<String>();
		}
		private String getName() {
			return name;
		}
		private void addComposedClass(String c) {
			composedClasses.add(c);
		}
		private ArrayList<String> getComposedClasses() {
			return composedClasses;
		}
	}
	
	private class Target {
		private String name;
		private Client client = null;
		private Adapter adapter = null;
		private Target(String name) {
			this.name = name;
		}
		private void setClient(Client client) {
			this.client = client;
		}
		private void setAdapter(Adapter adapter) {
			this.adapter = adapter;
		}
		private String getName() {
			return name;
		}
		private Client getClient() {
			return client;
		}
		private Adapter getAdapter() {
			return adapter;
		}
	}
	
	private class Adapter {
		private String name;
		private Target target;
		private Adaptee adaptee = null;
		private ArrayList<String> classMethodCalls;
		private Adapter(String name, Target target, ArrayList<String> classMethodCalls) {
			this.name = name;
			this.target = target;
			this.classMethodCalls = classMethodCalls;
		}
		private void setAdaptee(Adaptee adaptee) {
			this.adaptee = adaptee;
		}
		private String getName() {
			return name;
		}
		private Adaptee getAdaptee() {
			return adaptee;
		}
		private ArrayList<String> getClassMethodCalls() {
			return classMethodCalls;
		}
	}
	
	private class Adaptee {
		private String name;
		private Adaptee(String name) {
			this.name = name;
		}
		private String getName() {
			return name;
		}
	}

	@Override
	public void doCheck(ArrayList<LinterClass> classes) {
		ArrayList<String> classNames = new ArrayList<String>();
		ArrayList<String> interfaces = new ArrayList<String>();
		ArrayList<String> composedInterfaces = new ArrayList<String>();
		ArrayList<LinterClass> adapters = new ArrayList<LinterClass>();
		HashMap<String, Target> targets = new HashMap<String, Target>();
		HashMap<String, Adapter> adapterBois = new HashMap<String, Adapter>();
		for(LinterClass c1 : classes) {
			if (c1.getIsInterface()) {
				interfaces.add(c1.getSimpleName());
			}
			classNames.add(c1.getSimpleName());
		}
		for(LinterClass c1 : classes) {
			Client c = null;
			boolean firstC = true;
			for (LinterField f1 : c1.getFields()) {
				if (classNames.contains(f1.getType())) {
					if (firstC) {
						c = new Client(c1.getSimpleName());
						firstC = false;
					}
					if (interfaces.contains(f1.getType())) {
						Target t = new Target(f1.getType());
						t.setClient(c);
						targets.put(f1.getType(), t);
						composedInterfaces.add(f1.getType());
					}
					c.addComposedClass(f1.getType());
				}
			}
		}
		for(LinterClass c1 : classes) {
			for (String c2 : c1.getImplemented()) {
				String[] c2arr = c2.split("/");
				c2 = c2arr[c2arr.length-1];
				if (composedInterfaces.contains(c2)) {
					ArrayList<String> classMethodCalls = new ArrayList<String>();
					for(LinterMethod m : c1.getMethodLinter().getLinterMethods()) {
						for(String s : m.getClassMethodCalls()) {
							String[] methodNameArr = s.split("/");
							String methodName = methodNameArr[methodNameArr.length-1];
							classMethodCalls.add(methodName);
						}
					}
					Adapter a = new Adapter(c1.getSimpleName(), targets.get(c2), classMethodCalls);
					adapterBois.put(c1.getSimpleName(), a);
					targets.get(c2).setAdapter(a);
					adapters.add(c1);
				}
			}
		}
		for(LinterClass c1 : adapters) {
			for (LinterField f1 : c1.getFields()) {
				if (classNames.contains(f1.getType())) {
					Adaptee a = new Adaptee(f1.getType());
					adapterBois.get(c1.getSimpleName()).setAdaptee(a);
				}
			}
		}
		
		for(Target t : targets.values()) {
			if (t.getClient() != null && t.getAdapter() != null) {
				if (t.getAdapter().getAdaptee() != null) {
					boolean success = true;
					String adapterDetected = "Adapter Pattern incorrectly implemented:\n";
					if (!t.getAdapter().getClassMethodCalls().contains(t.getAdapter().getAdaptee().getName())) {
//						System.out.println("Weak adapter pattern detected (Adapter does not call Adaptee):");
						adapterDetected += "- Adapter does not call Adaptee\n";
						success = false;
					} 
					if (t.getClient().getComposedClasses().contains(t.getAdapter().getName())) {
//						System.out.println("Almost adapter pattern (Client composes Adapter):");
						adapterDetected += "- Client composes Adapter\n";
						success = false;
					}
					if (t.getClient().getComposedClasses().contains(t.getAdapter().getAdaptee().getName())) {
//						System.out.println("Client composes Adaptee");
						adapterDetected += "- Client composes Adaptee";
						success = false;
					}
					else if (success) {
//						System.out.println("Adapter pattern detected:");
						adapterDetected = "Adapter pattern detected";
					}
					System.out.println(adapterDetected);
					System.out.println("\tClient: " + t.getClient().getName());
					System.out.println("\tTarget: " + t.getName());
					System.out.println("\tAdapter: " + t.getAdapter().getName());
					System.out.println("\tAdaptee: " + t.getAdapter().getAdaptee().getName());
				}
			}
		}
	}

}
