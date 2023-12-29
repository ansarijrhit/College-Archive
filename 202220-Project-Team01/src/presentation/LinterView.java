package presentation;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import datasource.ConfigSettings;

public class LinterView{
	private ArrayList<String> classes;
	private ArrayList<String> linters;
	public LinterView() {
		this.classes = ConfigSettings.load(1);
		this.linters = ConfigSettings.load(2);;
		JFrame f = new JFrame();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.getContentPane().add(constructPanel());
		f.pack();
		f.setResizable(true);
		f.setVisible(true);
	}
	
	private JPanel constructPanel() {
		Font labelFont = new Font("Courier", Font.BOLD, 40);
		Font textFont = new Font("Courier", Font.BOLD, 20);
		
		//add panel
		JPanel p = new JPanel();
		p.setFont(textFont);
		p.setLayout(new GridBagLayout());
		p.setPreferredSize(new Dimension(1000,600));
		GridBagConstraints gbc = new GridBagConstraints();
		
		//add class label
		JLabel classLabel = new JLabel("Classes:");
		classLabel.setFont(labelFont);
		gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.HORIZONTAL;
		gbc.gridx = 0;
		gbc.gridy = 0;
		gbc.weightx = 1;
		gbc.weighty = 0.2;
		p.add(classLabel, gbc);
		
		
		//add linter label 
		JLabel linterLabel = new JLabel("Linters:");
		linterLabel.setFont(labelFont);
		gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.HORIZONTAL;
		gbc.gridx = 1;
		gbc.gridy = 0;
		gbc.weightx = 1;
		gbc.weighty = 0.2;
		p.add(linterLabel, gbc);
		
		//add class text box
		JTextArea classes = new JTextArea();
		classes.setFont(textFont);
		classes.setRows(20);
		classes.setText(convertToList(this.classes));
		classes.setLineWrap(true);
		gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.BOTH;
		gbc.insets = new Insets(3,3,3,3);
		gbc.gridx = 0;
		gbc.gridy = 1;
		gbc.weightx = 1;
		gbc.weighty = 4;
		p.add(classes, gbc);
		
		//add linter text box
		JTextArea linters = new JTextArea();
		linters.setFont(textFont);
		linters.setRows(20);
		linters.setText(convertToList(this.linters));
		linters.setLineWrap(true);
		gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.BOTH;
		gbc.insets = new Insets(3,3,3,3);
		gbc.gridwidth = 5;
		gbc.gridx = 1;
		gbc.gridy = 1;
		gbc.weightx = 1;
		gbc.weighty = 4;
		p.add(linters, gbc);

		
		//add save button
		JButton save = new JButton("Save");
		save.addActionListener(new SaveListener(classes, linters));
		gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.BOTH;
		gbc.insets = new Insets(10,10,10,10);
		gbc.gridx = 0;
		gbc.gridy = 2;
		gbc.weightx = 1;
		gbc.weighty = 1;
		p.add(save, gbc);
		
		//add run button
		JButton run = new JButton("Run");
		run.addActionListener(new RunListener());
		gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.BOTH;
		gbc.insets = new Insets(10,10,10,10);
		gbc.gridx = 1;
		gbc.gridy = 2;
		gbc.weightx = 1;
		gbc.weighty = 1;
		p.add(run, gbc);
		
		return p;
	}

	private String convertToList(ArrayList<String> items) {
		StringBuilder sb = new StringBuilder();
		for(String i : items){
			sb.append(i);
			sb.append("\n");
		}
		
		return sb.toString();
	}

	public void init() {
		
	}
	
	public void update() {
		
	}
	
	public void setLinters() {
		
	}
	
	public void setClasses() {
		
	}
}
