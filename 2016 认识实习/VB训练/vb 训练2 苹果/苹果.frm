VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3345
   ClientLeft      =   120
   ClientTop       =   465
   ClientWidth     =   4785
   LinkTopic       =   "Form1"
   ScaleHeight     =   3345
   ScaleWidth      =   4785
   StartUpPosition =   3  '����ȱʡ
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Activate()
    Print "Load�¼�"
End Sub

Private Sub Form_Load()
    Caption = "���ش�����"
    AutoRedraw = ture
    Picture = LoadPicture(App.Path + "\1.jpg")
    FontSize = 40
    FontName = "����"
    ForeColor = vbGreen
    
End Sub

Private Sub form_click()
    Caption = "��굥��"
    Print "��굥�����"
End Sub

Private Sub form_dblclick()
    Caption = "���˫��"
    Picture = LoadPicture("")
    Print "���˫��"
End Sub
