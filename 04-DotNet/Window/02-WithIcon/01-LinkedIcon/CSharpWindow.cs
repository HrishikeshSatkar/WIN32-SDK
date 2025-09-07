using System;
using System.Drawing;   //for colors and brushes
using System.Windows.Forms; //win32 chi window mnje .net cha form
public class CSharpWindow:Form
{
    public CSharpWindow()
    {
        //code
        Icon = new Icon("Windows.ico");
        Text = "C#Window";  //caption of window
        Width = 800;    
        Height = 600;
        BackColor = Color.Black;
        ResizeRedraw = true;

        this.KeyDown += new KeyEventHandler(MyKeyDown);
        this.MouseDown += new MouseEventHandler(MyMouseDown); 
    }

    protected override void OnPaint(PaintEventArgs pea)
    {
        //code
        Graphics graphics = pea.Graphics;
        StringFormat stringFormat = new StringFormat();
        stringFormat.Alignment = StringAlignment.Center;
        stringFormat.LineAlignment = StringAlignment.Center;

        String str = "Hello World!!!";
        graphics.DrawString(str, Font, new SolidBrush(System.Drawing.Color.Green), ClientRectangle, stringFormat);
    }

    void MyKeyDown(object sender,KeyEventArgs kea)
    {
        //code
        MessageBox.Show("Some key of keyboard is pressed");
    }

    void MyMouseDown(object sender,MouseEventArgs mea)
    {
        MessageBox.Show("Some button of mouse is clicked");
    }

    public static void Main()
    {
        //code
        Application.Run(new CSharpWindow());
    }
}

