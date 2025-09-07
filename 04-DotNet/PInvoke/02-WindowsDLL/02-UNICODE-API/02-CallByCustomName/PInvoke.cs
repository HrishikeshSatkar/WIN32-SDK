using System;
using System.Runtime.InteropServices;
public class PInvoke
{
	//code
	[DllImport("user32.dll", EntryPoint = "MessageBoxW", CharSet = CharSet.Unicode)]
	public static extern int MyMessageBox(int n1, String s1, String s2, int n2);
	public static void Main()
    {
		//code
		MyMessageBox(0,"MessageBox() as UNICODE-API","WIN32-UNICODEAPI",0);
    }
}
