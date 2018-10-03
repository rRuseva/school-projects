

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;



public class DialogExample1 extends Frame implements ActionListener, MouseListener, TextListener {
	int xC=350, yC=350, r=100;
	static ArrayList<Integer> x = new ArrayList<Integer>();
	static ArrayList<Integer> y = new ArrayList<Integer>();
	static int dotsC = 0;
	Label lbl1=null;
	TextField tfX, tfY, tfR;
	
	
	public static void main(String[] args) {
		DialogExample1 wnd = new DialogExample1();
		wnd.setLocation(100, 100);
		wnd.setSize(700, 700);
		wnd.setVisible(true);
		
	} // public static void main(String[] args)

	public DialogExample1() {
		super("MyBlackBoard");
		setBackground(Color.black);
		setLayout(new FlowLayout());
		Label lblX = new Label ("x = ",Label.LEFT);
		lblX.setForeground(Color.white);
		add(lblX);
		
		tfX =  new TextField(""+ xC, 20);
		tfX.addActionListener(this);
		tfX.addTextListener(this);
		add(tfX);
		Label lblY = new Label ("y = ",Label.LEFT);
		lblY.setForeground(Color.white);
		add(lblY);
		tfY = new TextField(""+yC,20);
		tfY.addActionListener(this);
		tfY.addTextListener(this);
		add(tfY);
		
		Label lblR = new Label ("radius r = ",Label.LEFT);
		lblR.setForeground(Color.white);
		add(lblR);
		tfR = new TextField(""+r,20);
		tfR.addActionListener(this);
		tfR.addTextListener(this);
		add(tfR);

		Button button0 = new Button("Clear");
		button0.addActionListener(this);
		add(button0);
		// End-Button
		Button button1 = new Button("End");
		button1.addActionListener(this);
		add(button1);
		// Window-Listener
		addWindowListener(new textFields(true));
		addMouseListener(this);
	}
	
	public void actionPerformed(ActionEvent event) {
		String cmd = event.getActionCommand();
		Object obj = event.getSource();
		int k=0, p=0, r2=0;
		if (obj instanceof TextField) {
			try{				
				k=Integer.parseInt(tfX.getText());
				if(k> r && k < 700-r) {
					xC=k;
					clearWND();
				}
				else System.out.println("invalid x coordinate ");
			} catch(NumberFormatException exX){
		    	System.out.println("invalid x coordinate ");
		    }
			
			try{
				p=Integer.parseInt(tfY.getText());
				if(p> 40+r && p < 700-r) {
					yC=p;
					clearWND();
				}
				else System.out.println("invalid y coordinate ");
			} catch(NumberFormatException exY){
				System.out.println("invalid y coordinate ");
		    }
			try{
				r2=Integer.parseInt(tfR.getText());
				if(((xC+r2)< 700 ||(xC-r2)>0) && ((yC-r2)> 100 || (yC+r2)<700)) {
					r=r2;
					clearWND();
				}
				else System.out.println("invalid radius ");
			} catch(NumberFormatException exR){
		    	System.out.println("invalid radius ");
		    }
			System.out.println("ButtonAction: "+event.getActionCommand());
			repaint();
		} else if (cmd.equals("Clear")) {
			clearWND();
			
		}else if (cmd.equals("End")) {
			setVisible(false);
			dispose();
			System.exit(0);
		} // else if (cmd.equals("End")) {
		
	} // public void actionPerformed(ActionEvent event) {
	public void clearWND(){
		x.clear();
		y.clear();
		dotsC = 0;
		repaint();
	}
	public void paint(Graphics g) {
		// given big circle
		g.setColor(Color.white);
		g.fillOval(xC-r, yC-r, 2*r, 2*r);
		g.drawString("Circle center coordinates are: ("+xC+", "+yC+")", xC-r, yC-r*3/2);
		//center of the circle
		g.setColor(Color.blue);
		g.drawString("("+(xC) +","+(yC) +")", (xC)-5, yC-10);
		g.fillOval(xC-2, yC-2, 5, 5);
		
		//user's points
		g.setColor(Color.red);
		for(int j=0; j<=dotsC-1; j++){
			int cX = x.get(j);
			int cY= y.get(j);
			g.drawString("("+cX +","+cY +")", cX-5, cY-10);
			g.fillOval(cX-2, cY-2, 5, 5);
		}
	}
	//checks if given point is inside big white circle
	public boolean inCircle (int x, int y){
		int d = (x-xC)*(x-xC) + (y-yC)*(y-yC);
		if(d<(r-2)*(r-2))
			return true;
		else 
			return false;
	}

	@Override
	public void mousePressed(MouseEvent e) {
		if(e.getButton()==MouseEvent.BUTTON1){
			int currX = e.getX();
			int currY = e.getY();
			if(inCircle(currX,currY)){
				dotsC++;
				x.add(currX);
				y.add(currY);
				System.out.println("dotsC = "+dotsC); 
				System.out.println("("+currX +","+currY +")");
			}
			
		}
		repaint();
	}
	
	@Override
	public void mouseClicked(MouseEvent e) {}
	@Override
	public void mouseEntered(MouseEvent e) {}
	@Override
	public void mouseExited(MouseEvent e) {	}
	@Override
	public void mouseReleased(MouseEvent e) {}

	@Override
	public void textValueChanged(TextEvent e) {
		// TODO Auto-generated method stub
		
	}
	
} // public class DialogExample extends Frame implements ActionListener