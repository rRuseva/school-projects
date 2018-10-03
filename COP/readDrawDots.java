/*
 * 1.1 В един текстов файл са зададени координатите на точки. В един ред са дадените 
 * Х и У за една точка. Като разделител служи интервал. Да се състави Application на 
 * Java за прочитане на този файл и за графично представяне на точките.
 */
import java.io.*;
import java.util.*;
import java.awt.*;

public class readDrawDots extends Frame  {
	
	static ArrayList<Integer> x = new ArrayList<Integer>();
	static ArrayList<Integer> y = new ArrayList<Integer>();
	static int dotsC = 0;
	
	readDrawDots() {
		super("BlackBoard-1.1");
		setBackground(Color.white);
		setLocation(200, 100);
		setSize(600, 400);
		addWindowListener(new WindowClosingAdapter(true));

		setVisible(true);
	}
	
	public static void readCoordinates (String filePath) throws IOException{
		
		BufferedReader reader= new BufferedReader(new FileReader(filePath));
		
		String line;
		int currX=0, currY=0;
	    int lineC=1;
		while ((line = reader.readLine()) != null) {
		    String coordinate[]=line.split(" ");
		    if(coordinate.length==2){
		    	dotsC++;
			    try{
			    	currX = Integer.parseInt(coordinate[0]);
			    } catch(NumberFormatException ex){
			    	System.out.println("invalid x coordinate at row " + lineC +"...");
			    	currX = 0;
			    }
			    try{
			    	currY = Integer.parseInt(coordinate[1]);
			    } catch(NumberFormatException ex){
			    	System.out.println("invalid y coordinate at row " + lineC +"...");
			    	currY = 0;
			    }
			    if(currX>0 && currY>0){    
				    x.add(currX);
				    y.add(currY);
			    }
			    else dotsC--;
			}
		    lineC++;
		}
		reader.close();
	}
	
	public static void main(String[] args) throws Exception{
		String file = "dots.txt";
		readCoordinates (file);
		
		readDrawDots wnd = new readDrawDots();
		
		
	}
	public void paint(Graphics g) {
		
		g.setColor(Color.blue);
		for(int j=0; j<=dotsC-1; j++){
			int cX = x.get(j);
			int cY= y.get(j);
			g.drawString("("+cX +","+cY +")", cX+10,cY);
			g.fillOval(cX, cY, 5, 5);
		}
	}

}
