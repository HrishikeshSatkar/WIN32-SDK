using System;
using System.Runtime.InteropServices;
public class PInvoke
{
	//code
	[DllImport("user32.dll", CharSet = CharSet.Unicode)]
	public static extern int MessageBoxW(int n1, String s1, String s2, int n2);
	public static void Main()
    {
		//code
		MessageBoxW(0,"MessageBox() as UNICODE-API","WIN32-UNICODEAPI",0);
    }
}
