/*
 * 2.1 Да се състави Applet или Application на Java, имащ следната функционалност:
 * 1)начертаваедна окръжност (с радиус 100пиксела).
 * 2)дава възможностза поставяне на точки с помощта на мишката (щракване с левия бутон, 
 * точката е окръжност с радиус5 пиксела).
 * Точките трябва да могат да се поставят само ако въпросната малка 
 * окръжност се съдържа изцяло в голямата окръжност. 
 */
import java.util.*;
import java.awt.*;
import java.awt.event.*;

public class dotsInCircle extends Frame implements MouseListener {
	
	static int xC=350, yC=220, r=150;
	static ArrayList<Integer> x = new ArrayList<Integer>();
	static ArrayList<Integer> y = new ArrayList<Integer>();
	static int dotsC = 0;
	
	dotsInCircle() {
		super("BlackBoard-2.1");
		setBackground(Color.white);
		setLocation(200, 100);
		setSize(700, 400);
		
		addWindowListener(new WindowClosingAdapter(true));
		addMouseListener(this);
		setVisible(true);
	}
		
	public static void main(String[] args) {
		dotsInCircle wnd = new dotsInCircle();
	}
	
	public void paint(Graphics g) {

		// given big circle
		g.setColor(Color.red);
		g.fillOval(xC-r, yC-r, 2*r, 2*r);
		
		//center of the circle
		g.setColor(Color.white);
		g.drawString("("+(xC) +","+(yC) +")", (xC)-5, yC-10);
		g.fillOval(xC-2, yC-2, 5, 5);
		
		//user's points
		g.setColor(Color.blue);
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
	public void mouseClicked(MouseEvent e)  {}
	public void mouseEntered(MouseEvent e)  {}
	public void mouseExited(MouseEvent e)   {}
	public void mouseReleased(MouseEvent e) {}

}
