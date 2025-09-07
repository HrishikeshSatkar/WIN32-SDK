using System;
using System.Runtime.InteropServices;
public class PInvoke
{
	//code
	[DllImport("MyDllServer.dll")]
	public static extern int SumOfTwoIntegers(int n1, int n2);
	public static void Main()
    {
		//code
		int iNum1 = 75;
		int iNum2 = 25;
		int iNum3 = SumOfTwoIntegers(iNum1, iNum2);
		Console.WriteLine("Sum of " + iNum1 + " and " + iNum2 + " is " + iNum3);
    }
}
