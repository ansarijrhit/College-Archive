package datasource;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class ConfigSettings {
	static String classFileConfig = "classConfig.txt";
	static String linterFileConfig = "linterConfig.txt";
	
	public static void write(String[] values, int fileID) throws IOException{
		BufferedWriter w;
		String chosenFile = getFileNameByID(fileID);

		w = new BufferedWriter(new FileWriter(chosenFile));
		for(String cur : values) {
			w.write(cur);
			if(cur == values[values.length-1]) {
				break;
			}
			w.write("\n");
		}
		w.close();
	}

	public static ArrayList<String> load(int fileID) {
		//1 is classes
		//2 is linters
		String chosenFile = getFileNameByID(fileID);
		Scanner s;
		
		ArrayList<String> toReturn = new ArrayList<String>();
		try {
			s = new Scanner(new File(chosenFile));
			while(s.hasNext()) {
				
				toReturn.add(s.next());
			}
			s.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
			

		return toReturn;
	}

	private static String getFileNameByID(int fileID) {
		switch(fileID) {
		case 1: return classFileConfig;
		case 2: return linterFileConfig;
		}
		return null;
	}

}
