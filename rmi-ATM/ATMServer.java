/*This is the server owning the remote objects and registering in the RMI registry, those remotely callable objects*/

import java.rmi.Naming;		//for naming the object and registering it with RMI registry
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;


/*--class should extend Uni...* class to extend and implement interface containing remotely callable methods defined in ATM interface<ATM.java
 --The Unicast* class is used to create Remotely referentiable objects(proxy objects) */
 
public class ATMServer extends UnicastRemoteObject implements ATM
{
	static int balance;
	public ATMServer() throws RemoteException	
	{
		super();
	}
	public void init(int b)		//method overriding
	{
		balance=b;
		System.out.println("Client Account Initialized..");
	}
	public int withDraw(int b)	//method overriding
	{
		System.out.println("Client withdrew :"+b);
		return(balance=balance-b);
	}
	public int checkBalance()	//method overriding
	{
		System.out.println("Client check balance...");
		return balance;
	}
	public static void main(String args[])
	{
		try
		{
			ATMServer obj=new ATMServer();		//create object
			Naming.rebind("ATMmachine",obj);	//bind object to RMI registry with ATMmachine as name
			System.out.println("RMI server is now started...");
		}
		catch(Exception e)
		{
			System.out.println("Server Error");
			e.printStackTrace();
		}
	}
}
