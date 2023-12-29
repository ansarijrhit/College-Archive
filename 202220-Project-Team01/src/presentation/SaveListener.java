package presentation;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.ArrayList;

import javax.swing.JTextArea;

import datasource.ConfigSettings;

public class SaveListener implements ActionListener {
	private JTextArea classes;
	private JTextArea linters;
	
	public SaveListener(JTextArea classes, JTextArea linters) {
		this.classes = classes;
		this.linters = linters;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		try {
			ConfigSettings.write(classes.getText().split("\n"), 1);
			ConfigSettings.write(linters.getText().split("\n"), 2);
			System.out.println("Save successful");
		} catch (IOException e1) {
			e1.printStackTrace();
		}
	}

}
