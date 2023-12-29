package presentation;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import datasource.ConfigSettings;

public class RunListener implements ActionListener{

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			Main.runLinters();
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		
	}

}
