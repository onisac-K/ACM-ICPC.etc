VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5625
   ClientLeft      =   5520
   ClientTop       =   4620
   ClientWidth     =   8490
   LinkTopic       =   "Form1"
   ScaleHeight     =   5625
   ScaleWidth      =   8490
   Begin VB.PictureBox Picture1 
      Height          =   1815
      Left            =   2280
      ScaleHeight     =   1755
      ScaleWidth      =   3675
      TabIndex        =   1
      Top             =   1320
      Width           =   3735
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ÏÔÊ¾"
      Height          =   615
      Left            =   3240
      TabIndex        =   0
      Top             =   3720
      Width           =   1815
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Dim a(15) As Integer
    Dim i As Integer
    For i = 1 To 10
        a(i) = Int(Rnd * 100) + 1
    Next i
    Dim sum As Integer, max As Integer, min As Integer, avg As Integer, s As String
    
    max = 0
    min = 101
    For i = 1 To 10
        sum = sum + a(i)
    Next i
    For i = 1 To 10
        If (a(i) > max) Then max = a(i)
    Next i
    For i = 1 To 10
        If (a(i) < min) Then min = a(i)
    Next i
    avg = Int(sum / 10)
    For i = 1 To 10
        s = s + CStr(a(i)) + " "
    Next i
    Picture1.Print s
    
    Picture1.Print "the max num is "; max; Spc(3); "the min num is "; min;
    Picture1.Print
    Picture1.Print "the sum num is "; sum; Spc(3); "the avg num is "; avg;
     
End Sub

