//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
        HRGN rgn;
        rgn = CreateRoundRectRgn(0, 0, 822, 701, 20, 30);
        SetWindowRgn(Handle, rgn, true);
        DeleteObject(rgn);
        drag=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
       if(Button == mbLeft){
                LX = X;
                LY = Y;
                drag = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if(Button == mbLeft){
                drag = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if(drag){
                Left += X-LX;
                Top += Y-LY;
        }
}
//---------------------------------------------------------------------------

