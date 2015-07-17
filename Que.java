import java.util.*;
import java.io.*;

public class Que{
	public static void main(String args[]) throws java.io.IOException{
		char c;
		String tempstring;
		//Scanner s=new Scanner(System.in);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Qbuilder q1=new Qbuilder();
		q1.queSpaceAlloc();


		System.out.println("Start application? [y/n]");
		tempstring=br.readLine();
		c=tempstring.charAt(0);

		while(c=='y'){
			System.out.println("want to enqueue? [y/n]");
		//c=br.readLine().charAt(0);
			tempstring=br.readLine();
			c=tempstring.charAt(0);
			while(c=='y'){
				float temp;
				System.out.println("enter no.");
				temp=Float.parseFloat(br.readLine());
				q1.enqueue(temp);
				System.out.println("another? [y/n]");
				tempstring=br.readLine();
				c=tempstring.charAt(0);
			}
			System.out.println("want to dequeue? [y/n]");
			tempstring=br.readLine();
			c=tempstring.charAt(0);
			while(c=='y'){
				q1.dequeue();
				System.out.println("another? [y/n]");
				tempstring=br.readLine();
				c=tempstring.charAt(0);
			}
			System.out.println("CONTINUE? [y/n]" );
			tempstring=br.readLine();
			c=tempstring.charAt(0);
		}
		q1.display();

	}
}
class Qbuilder{

	private float a[];
	private int n;
	private int front=0,rear=0;

	public void queSpaceAlloc(){
		System.out.println("enter the size?");
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		a=new float[n];
	}

	public void enqueue(float x){
		if(rear==n)
		{
			if(front>0){
				rear=0;
				a[rear]=x;
				rear++;
			}
			else {
				System.out.println("QUE FULLY FILLED");
				display();
				System.exit(0);
			}
		}
		else if(rear==(front)&&rear!=0){
			System.out.println("QUE FULLY FILLED");
			display();
			System.exit(0);
		}
		else{
			a[rear]=x;
			rear++;
		}


	}

	public void dequeue(){
		System.out.println(a[front]);
		a[front]=0;
		front++;

	}

	public void display(){
		for(int i=0;i<n;i++){
			System.out.println(a[i]);
		}
	}

}