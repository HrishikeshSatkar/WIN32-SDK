Imports System.Windows.Forms
Imports AutomationServerTypeLibForDotNet
Public Class VBAutomationClient
	Inherits Form
	Public Sub New()
		Dim MyIDispatch As Object
		Dim MyRef As New CMyMathClass
		MyIDispatch = MyRef
		Dim num1 = 175
		Dim num2 = 125
		Dim sum = MyIDispatch.SumOfTwoIntegers(num1, num2)
		Dim str As String = String.Format("Sum Of {0} And {1} Is {2}", num1, num2, sum)
		MsgBox(str)
		Dim subtract = MyIDispatch.SubtractionOfTwoIntegers(num1, num2)
		str = String.Format("Subtraction Of {0} And {1} Is {2}", num1, num2, subtract)
		MsgBox(str)
		End
	End Sub

	<STAThread()>
	Shared Sub Main()
		Application.EnableVisualStyles()
		Application.Run(New VBAutomationClient())
	End Sub
End Class


