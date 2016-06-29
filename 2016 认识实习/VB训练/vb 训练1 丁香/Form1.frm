VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "丁香"
   ClientHeight    =   7275
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   7740
   BeginProperty Font 
      Name            =   "宋体"
      Size            =   12
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   7275
   ScaleWidth      =   7740
   StartUpPosition =   3  '窗口缺省
   Begin VB.PictureBox Picture1 
      Height          =   975
      Left            =   2880
      ScaleHeight     =   915
      ScaleWidth      =   1875
      TabIndex        =   3
      Top             =   1920
      Width           =   1935
   End
   Begin VB.CommandButton Command1 
      Caption         =   "退出"
      Height          =   615
      Left            =   3240
      TabIndex        =   2
      Top             =   5280
      Width           =   975
   End
   Begin VB.OptionButton Option2 
      Caption         =   "功能"
      Height          =   495
      Left            =   4560
      TabIndex        =   1
      Top             =   3840
      Width           =   1095
   End
   Begin VB.OptionButton Option1 
      Caption         =   "特点"
      Height          =   255
      Left            =   2160
      TabIndex        =   0
      Top             =   3960
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "丁香"
      Height          =   375
      Left            =   1800
      TabIndex        =   4
      Top             =   1080
      Width           =   1455
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    End
End Sub

Private Sub Option1_Click()
    Picture1.Cls
    Picture1.Print "fuck away"

End Sub

Private Sub Option2_Click()
    Picture1.Cls
    Picture1.Print "fuck off"
End Sub


