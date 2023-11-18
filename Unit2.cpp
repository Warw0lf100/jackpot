//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        HRGN rgn;
        rgn = CreateRoundRectRgn(0, 0, 834, 548, 20, 30);
        SetWindowRgn(Handle, rgn, true);
        DeleteObject(rgn);
        drag=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
        Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
       if(Button == mbLeft){
                LX = X;
                LY = Y;
                drag = true;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if(Button == mbLeft){
                drag = false;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if(drag){
                Left += X-LX;
                Top += Y-LY;
        }
}
//---------------------------------------------------------------------------

