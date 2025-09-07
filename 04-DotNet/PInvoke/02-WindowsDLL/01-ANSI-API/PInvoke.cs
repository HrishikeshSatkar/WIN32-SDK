using System;
using System.Runtime.InteropServices;
public class PInvoke
{
	//code
	[DllImport("user32.dll")]
	public static extern int MessageBoxA(int n1, String s1, String s2, int n2);
	public static void Main()
    {
		//code
		MessageBoxA(0,"MessageBox() as ANSI-API","WIN32-ANSIAPI",0);
    }
}
