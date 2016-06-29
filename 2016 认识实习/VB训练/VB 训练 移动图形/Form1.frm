VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6630
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   7230
   LinkTopic       =   "Form1"
   ScaleHeight     =   6630
   ScaleWidth      =   7230
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.Image Image1 
      Height          =   2175
      Left            =   0
      Top             =   0
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False


Private Sub Form_KeyDown(KeyCode As Integer, Shift As Integer)
    If (KeyCode = 38) Then
        Image1.Move Image1.Left, Image1.Top - 50
    End If
    If (KeyCode = 40) Then
        Image1.Move Image1.Left, Image1.Top + 50
    End If
    If (KeyCode = 37) Then
        Image1.Move Image1.Left - 50, Image1.Top
    End If
    If (KeyCode = 39) Then
        Image1.Move Image1.Left + 50, Image1.Top
    End If
End Sub

Private Sub Form_Load()
    Image1.Picture = LoadPicture(App.Path + "/1.jpg")
End Sub


