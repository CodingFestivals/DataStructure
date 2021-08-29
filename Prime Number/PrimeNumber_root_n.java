package DataStructure;
import java.lang.*;
public class PrimeNumber_root_n {
	//here we make this method static because non static method can't be access
	//from static main method
	static Boolean isPrime(int n) {
		//divide n by 2 to root(n)
		for(int i=2;i<=Math.sqrt(n);i++) {
			//if n is dividable by i than n is not prime 
			if(n%i==0) {
				return false;
			}
		}
		//otherwise return true means n is prime number
		return true;
	}
	public static void main(String args[]) {
		int n=154;
		if(isPrime(n))  
			System.out.println(n+" is a prime number");
		else
			System.out.println(n+" is not prime");
	}
}
