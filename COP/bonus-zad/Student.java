import java.util.ArrayList;

public class Student {
	private String firstName, lastName, facNum, sex, grades;
	
	public Student()
	{
		this.firstName = "";
		this.lastName = "";
		this.facNum = "";
		this.sex = "";
		this.grades = "" ; 
	}
	public Student(String names, String facNum, String sex, String grades)
	{
		String temp[]=names.split(" ");
		this.firstName = temp[1];
		this.lastName = temp[2];
		this.facNum = facNum;
		this.sex = sex;
		this.grades=grades;
	}
	
	public String getFName(){
		return firstName;
	}
	
	public String getLName(){
		return lastName;
	}
	public String getFNumber(){
		return facNum;
	}
	public String getSex(){
		return sex;
	}
	public String getGradesS(){
		return grades;
	}
	public void setFName(String firstName){
		this.firstName = firstName;
	}
	
	public void setLName(String lastName){
		this.lastName = lastName;
	}
	public void setFNumber(String facNumber){
		this.facNum = facNum;
	}
	public void setSex(String _sex){
		this.sex = sex;
	}
	public void setGrades(String _grades){
		this.grades = _grades; 
	}
	
	public void printStudent() {
		System.out.println(firstName + " " + lastName + ", " + 
							facNum + ", " + sex + ", " + grades);
		
	}
}
