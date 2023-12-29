package domain.pattern;

import java.util.ArrayList;
import java.util.HashMap;

import org.objectweb.asm.Opcodes;

import datasource.LinterClass;
import datasource.LinterField;
import domain.interfaces.PatternChecker;

public class StrategyCheck implements PatternChecker {

    private ArrayList<String> interfaces;
    private HashMap<String, LinterField> fields;

    @Override
    public void doCheck(ArrayList<LinterClass> classes) {
        this.interfaces = new ArrayList<>();
        this.fields = new HashMap<>();
        for(LinterClass c : classes) { 
            if(c.getIsInterface()) {
                interfaces.add(c.getSimpleName()); //adds project interfaces to array list for later comparison
            }
            else {    
                for(int i = 0; i < c.getFields().size(); i++) {
                    LinterField f = c.getFields().get(i);
                    fields.put(f.getType(), f);
                }
            }
        }
        if(isStrategy()) { // checks if any fiels match interfaces used in project
            System.out.println("Strategy Pattern in Use");
        }
    }

    private boolean isStrategy() {
            for(String f : fields.keySet()) {
                LinterField lf = fields.get(f);
                for(String i : interfaces) {
                    
                    if(i.equals(f)) {
                        if(lf.getAccess() == Opcodes.ACC_FINAL) {
                            System.out.println("Incorrect use of Strategy Pattern, Strategy variable can not be final or else it can not change at runtime");
                            return false;
                        }
                        return true;
                }
                
            }
        }
        return false;
    }
    
}
