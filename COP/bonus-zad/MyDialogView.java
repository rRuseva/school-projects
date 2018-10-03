import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import java.io.*;
import java.util.*;

class MyDialogView extends JDialog implements ActionListener {
	static ArrayList<Student> students = new ArrayList<Student>();
	int curRec=0, maxLines=0;
	JLabel lblN1,lblFn1,lblS1,lblG1, lblnum;
	
	public MyDialogView(JFrame parent) throws IOException {
		super(parent, "MyDialogViewSystem", true);
		Point parloc = parent.getLocation();
		setBounds(parloc.x + 30, parloc.y + 30, 400, 300);
		setBackground(Color.lightGray);
		setLayout(new BorderLayout());
		readFromFile();
		
		// Panel
		JPanel panel = new JPanel(new GridLayout(4, 2));//panel.setBackground(Color.CYAN);
		customizeLayout(panel);
		JLabel lblN = new JLabel("Names: ");panel.add(lblN);
		lblN1 = new JLabel((String) students.get(curRec).getFName() + " " + students.get(curRec).getLName());panel.add(lblN1);
		
		JLabel lblFn= new JLabel("Faculty Number: ");panel.add(lblFn);
		lblFn1 = new JLabel((String) students.get(curRec).getFNumber());panel.add(lblFn1);
		
		JLabel lblS= new JLabel("Sex: ");panel.add(lblS);
		lblS1 = new JLabel((String) students.get(curRec).getSex());panel.add(lblS1);
		
		JLabel lblG= new JLabel("Grades: ");panel.add(lblG);
		lblG1 = new JLabel((String) students.get(curRec).getGradesS());panel.add(lblG1);
		
		add(panel, BorderLayout.CENTER);
		
		
		JPanel pnl2=new JPanel();pnl2.setBackground(Color.BLUE);
		pnl2.setLayout(new FlowLayout(FlowLayout.RIGHT));
		
		JButton buttonBack = new JButton("<= Back");
		pnl2.add(buttonBack); buttonBack.addActionListener(this);
		
		lblnum = new JLabel(Integer.toString(curRec+1) );
		lblnum.setForeground(Color.WHITE);pnl2.add(lblnum);
		
		JButton buttonNext = new JButton("Next =>");
		pnl2.add(buttonNext); buttonNext.addActionListener(this);
		// End-Button
				JButton button = new JButton("End");
				pnl2.add(button);button.addActionListener(this);

		add(pnl2, BorderLayout.SOUTH);
		// Window-Listener
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent event) {
				endDialog();
			}
		}); // addWindowListener
		//pack();
	} // public MyDialogView(Frame parent)

	private void customizeLayout(JPanel panel) {
		//     
	}

	public void actionPerformed(ActionEvent event) {
		if (event.getActionCommand().equals("<= Back")) {
			if(curRec>0){
				curRec--;
			}
			else curRec=maxLines-1;
			changeLabels();
			System.out.println(curRec);
		}
		
		if (event.getActionCommand().equals("Next =>")) {
			if(curRec<maxLines-1){
				curRec++;
			}
			else curRec=0;
			changeLabels();
			System.out.println(curRec);
		}
		if (event.getActionCommand().equals("End")) {
			endDialog();
		}
	}
	void changeLabels(){
		lblN1.setText((String) students.get(curRec).getFName() + " " + students.get(curRec).getLName());
		lblFn1.setText((String) students.get(curRec).getFNumber());
		lblS1.setText((String) students.get(curRec).getSex());
		lblG1.setText((String) students.get(curRec).getGradesS());
		lblnum.setText(Integer.toString(curRec+1));
	}
	void endDialog() {
		setVisible(false);
		dispose();
		((Window) getParent()).toFront();
		getParent().requestFocus();
	}
	// прочита всички записи във файла и ги записва във динамичния масив students
	public void readFromFile() throws IOException {
			File file = new File("studentsGrades.txt");
			Scanner fileReader = new Scanner(file);
			
			while(fileReader.hasNextLine()){
				maxLines++;
				String text[] = fileReader.nextLine().split(";");
				ArrayList<String> studInfo = new ArrayList<String>();
				for(int j=0; j<=3;j++){
					String text1[]=text[j].split(":");
					studInfo.add(text1[1]);
				}
				Student student = new Student(studInfo.get(0), studInfo.get(1),studInfo.get(2), studInfo.get(3));
				students.add(student);
			}
			fileReader.close();
		}
} // class MyDialogView extends Dialog implements ActionListener

