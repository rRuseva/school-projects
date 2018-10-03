import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
import java.io.*;
import java.util.*;

//main window
public class MyDialogSystem extends JFrame implements ActionListener {
	public static void main(String[] args) {
		MyDialogSystem wnd = new MyDialogSystem();
		wnd.setLocation(200, 100);
		wnd.setSize(600, 300);
		wnd.setVisible(true);
	} // public static void main(String[] args)

	public MyDialogSystem() {
		super("Welcome");
		setBackground(Color.lightGray);
		setLayout(new BorderLayout());
		JLabel lbl1=new JLabel("<html><div style='text-align: center;'>Welcome to my system. <br/>"
				+ "If you want to add new record click 'Add' button. "
				+ "If you want to review other record click 'View' button.</div></html>", SwingConstants.CENTER);
		add(lbl1, BorderLayout.NORTH);
		
		// Panel centered with buttons
		JPanel panel = new JPanel();
		customizeLayout(panel);
		add(panel, BorderLayout.CENTER);
		
		// Dialog-Button Add
		JButton buttonAdd = new JButton("Add");
		buttonAdd.addActionListener(this);
		panel.add(buttonAdd);
		
		// Dialog-Button View
		JButton buttonView = new JButton("View");
		buttonView.addActionListener(this);
		panel.add(buttonView);
		buttonView.setLocation(350, 150);
		
		// End-Button
		JButton buttonEnd = new JButton("End");
		buttonEnd.addActionListener(this);
		panel.add(buttonEnd);
		
		// Window-Listener
		addWindowListener(new WindowClosingAdapter(true));
	}
	private void customizeLayout(JPanel panel) {}
	public void actionPerformed(ActionEvent event) {
		String cmd = event.getActionCommand();
		if (cmd.equals("Add")) {
			MyDialogAdd dlg = new MyDialogAdd(this);
			dlg.setVisible(true);
		}else if (cmd.equals("View")) {
			MyDialogView dlg=null;
			try {
				dlg = new MyDialogView(this);
			} catch (IOException e) {
				e.printStackTrace();
			}
			dlg.setVisible(true);
		} else if (cmd.equals("End")) {
			setVisible(false);
			dispose();
			System.exit(0);
		} // else if (cmd.equals("End")) {
	} // public void actionPerformed(ActionEvent event) {
} // public class DialogExample extends Frame implements ActionListener
