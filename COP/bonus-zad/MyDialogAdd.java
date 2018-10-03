import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import java.io.*;
import java.util.*;

class MyDialogAdd extends JDialog implements ActionListener, ItemListener {
	String[] labels = {"First Name: ", "Last Name: ", "Faculty Number: "};
	int numPairs = labels.length;
	JTextField[] tFs = new JTextField[numPairs] ;
	JRadioButton rbM; JRadioButton rbF;
	JTextField tfGr = new JTextField(5);
	String[] inputInfo = new String[numPairs] ;
	String inputGrades = ""; String sex ="";
	
	
	//dialog window for adding information
	public MyDialogAdd(JFrame parent) {
		super(parent, "MyDialogAddSystem", true);
		Point parloc = parent.getLocation();
		this.setBounds(parloc.x + 60, parloc.y + 60, 600, 600);
		this.setBackground(Color.LIGHT_GRAY);
		setLayout(new BorderLayout());
		
		JPanel pnlTitle=new JPanel();//pnlTitle.setBackground(Color.YELLOW);
		pnlTitle.setLayout(new FlowLayout(FlowLayout.CENTER));
		JLabel lblT = new JLabel("Fill in:");
		pnlTitle.add(lblT);
		add(pnlTitle, BorderLayout.NORTH);
		 
		// main Panel with form inputs
		JPanel pnlCont=new JPanel();
		pnlCont.setLayout(new GridLayout(3,1));
		
		//inner panel with text fields
		JPanel pnlTF = new JPanel(new SpringLayout()); 
		
		for (int i = 0; i < numPairs; i++) {
		    JLabel l = new JLabel(labels[i], JLabel.TRAILING);
		    pnlTF.add(l);
		    tFs[i] = new JTextField(labels[i],5);
		    l.setLabelFor(tFs[i]);
		    pnlTF.add(tFs[i]);
		}		
		//Lay out the panel.
	    SpringUtilities.makeCompactGrid(pnlTF, numPairs, 2, 3, 3, 3, 3); 
	    pnlCont.add(pnlTF);

	    //inner panel with sex radio buttons
	    JPanel pnlRB = new JPanel(new GridLayout(1,2));

	    pnlRB.add(new JLabel("Sex: "));
	    ButtonGroup rbg=new ButtonGroup();
	    
	    rbM = new JRadioButton("Male",true);rbg.add(rbM); pnlRB.add(rbM) ;rbM.addActionListener(this);
	    rbF = new JRadioButton("Female", false);rbg.add(rbF); pnlRB.add(rbF);rbF.addActionListener(this);
	    
	    pnlCont.add(pnlRB);
	    
	    //inner panel with input fields for grades
  		JPanel pnlGr = new JPanel(new SpringLayout());
	    JLabel l = new JLabel("Grades");
	    pnlGr.add(l);
	    
	    l.setLabelFor(tfGr);
	    pnlGr.add(tfGr);

  		//Lay out the panel.
  	    SpringUtilities.makeCompactGrid(pnlGr, 1, 2, 3, 3, 3, 3); 
  	    pnlCont.add(pnlGr);
    
  	    
		add(pnlCont, BorderLayout.CENTER);

		//borders		
		JPanel panel1 = new JPanel(); 
	    add(panel1, BorderLayout.WEST);
	    
	    JPanel panel2=new JPanel();
	    add(panel2, BorderLayout.EAST);
	    
		 
		//buttons
		JPanel pnl2=new JPanel();pnl2.setBackground(Color.BLUE);
		pnl2.setLayout(new FlowLayout(FlowLayout.RIGHT));
		
		// Dialog-Button Add
		JButton buttonAdd = new JButton("Add");
		buttonAdd.addActionListener(this);
		pnl2.add(buttonAdd);
		
		// End-Button
		JButton button = new JButton("End");
		button.addActionListener(this);
		pnl2.add(button);

		add(pnl2, BorderLayout.SOUTH);
		// Window-Listener
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent event) {
				endDialog();
			}
		}); // addWindowListener
		//pack();
	} // public MyDialogAdd(Frame parent)

	private void customizeLayout(JPanel panel) {}

	public void actionPerformed(ActionEvent event) {
		//get text fields values
		String cmd = event.getActionCommand();
		Object obj = event.getSource();
		
		for (int i =0; i < numPairs; i++){
			inputInfo[i] = tFs[i].getText();
		}
		if (rbM.isSelected()) sex="Male";
		else sex="Female";
		
		inputGrades = tfGr.getText();
		
		if (event.getActionCommand().equals("Add")) {
			addRecord();
		}
		if (event.getActionCommand().equals("End")) {
			endDialog();
		}
	}

	void endDialog() {
		setVisible(false);
		dispose();
		((Window) getParent()).toFront();
		getParent().requestFocus();
	}

	public void itemStateChanged(ItemEvent arg0) {}
	
	public void addRecord(){
		String fileTitle = "studentsGrades.txt";
		try{
			FileWriter writer = new FileWriter(fileTitle, true);
		    writer.append("Names: "+inputInfo[0]+" "+ inputInfo[1]+ ";"
		    				+ "Faculty Number: "+ inputInfo[2] +";"
		    				+"Sex: "+ sex+";"
		    				+"Grades: " + inputGrades + ";\r\n");
		    //writer.append(System.lineSeparator());
		    writer.close();
		    endDialog();
		} catch (IOException e) {
		   // do something
			System.out.println("Record NOT added");
		}
	}

} // class MyDialogAdd extends Dialog implements ActionListener
