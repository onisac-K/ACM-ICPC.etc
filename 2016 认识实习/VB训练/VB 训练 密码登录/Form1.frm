VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5295
   ClientLeft      =   60
   ClientTop       =   450
   ClientWidth     =   8430
   LinkTopic       =   "Form1"
   ScaleHeight     =   5295
   ScaleWidth      =   8430
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command1 
      Caption         =   "sure ?"
      Height          =   495
      Left            =   1440
      TabIndex        =   4
      Top             =   3240
      Width           =   1215
   End
   Begin VB.TextBox Text2 
      Height          =   495
      Left            =   3000
      MaxLength       =   6
      TabIndex        =   3
      Top             =   1680
      Width           =   1455
   End
   Begin VB.TextBox Text1 
      Height          =   495
      Left            =   3000
      MaxLength       =   6
      TabIndex        =   2
      Top             =   960
      Width           =   1455
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      Caption         =   "password"
      Height          =   375
      Left            =   1200
      TabIndex        =   1
      Top             =   1680
      Width           =   1215
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      Caption         =   "doc num"
      Height          =   255
      Left            =   1320
      TabIndex        =   0
      Top             =   1080
      Width           =   975
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Dim i As Integer
        If Not Text2 = "123456" Then
             i = MsgBox("wrong password", 5 + 64 + 0 + 4096)
                If i = 2 Then
                    End
                Else
                    Text2 = ""
                Text2.SetFocus
                End If
        Else
            MsgBox "fuck you"
        End If
End Sub

Private Sub Text1_lostfocus()
    If Not IsNumeric(Text1) Then
        MsgBox "it must be number"
        Text1 = ""
        Text1.SetFocus
        End If
End Sub
