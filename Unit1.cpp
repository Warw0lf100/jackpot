//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

        HRGN okno1, okno2, okno3;
        TPoint tablica[17] = {Point(30,72), Point(35,245), Point(34,580), Point(42,988), Point(518,988), Point(530,712), Point(558,705), Point(552,631), Point(588,394), Point(562,392), Point(534,569), Point(533,245), Point(536,72), Point(313,65), Point(313,9), Point(252,9), Point(252,65)};
        okno1 = CreatePolygonRgn(tablica, 17, WINDING);
        okno2 = CreateEllipticRgn(548, 328, 612, 398);
        okno3 = CreateRectRgn(Left, Top, Left+Width, Top+Height);
        CombineRgn(okno3, okno1, okno2, RGN_OR);
        SetWindowRgn(Handle, okno3, true);

        DeleteObject(okno1);
        DeleteObject(okno2);
        DeleteObject(okno3);

        drag = false;
        randomize();
        stanKonta=100;
        Saldo->Caption = IntToStr(stanKonta);
        for(int i = 0; i <= 2; i++){
                obrWalce[i] = static_cast<TImage*>(FindComponent("obrWalec"+IntToStr(i+1)));
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

        Timer1->Enabled=true;
        Timer2->Enabled=true;
        Jackpot->Font->Color=clBlack;
        stanKonta -= 5;
        Saldo->Caption=IntToStr(stanKonta);
        Jackpot->Caption="";
        Button1->Enabled=false;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------







void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
       if(Button == mbLeft){
                LX = X;
                LY = Y;
                drag = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if(drag){
                Left += X-LX;
                Top += Y-LY;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if(Button == mbLeft){
                drag = false;
        }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        for(int i=0; i<=2; i++){
                los[i]=random(5);
        }


        for(int i=0; i<=2; i++){
                switch(los[i]){
                        case 0: obrWalce[i]->Picture->LoadFromFile("obrazki/0.jpg");
                                break;
                        case 1: obrWalce[i]->Picture->LoadFromFile("obrazki/1.jpg");
                                break;
                        case 2: obrWalce[i]->Picture->LoadFromFile("obrazki/2.jpg");
                                break;
                        case 3: obrWalce[i]->Picture->LoadFromFile("obrazki/3.jpg");
                                break;
                        case 4: obrWalce[i]->Picture->LoadFromFile("obrazki/4.jpg");
                                break;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
        Timer2->Enabled=false;
        Timer1->Enabled=false;


        if(los[0]==los[1] & los[0]==los[2]){
                Jackpot->Caption="WYGRANA!!!";
                Jackpot->Font->Color =clRed;
                switch(los[0]){
                        case 0:
                                Saldo->Caption = IntToStr(stanKonta += 10);
                                break;
                        case 1:
                                Saldo->Caption = IntToStr(stanKonta += 20);
                                break;
                        case 2:
                                Saldo->Caption = IntToStr(stanKonta += 50);
                                break;
                        case 3:
                                Saldo->Caption = IntToStr(stanKonta += 100);
                                break;
                        case 4:
                                Saldo->Caption = IntToStr(stanKonta += 1000);
                                break;
                }
        }else{
                Jackpot->Caption="Spróbuj jeszcze raz!";
        }

        if(stanKonta<=0){
                Form2->ShowModal();
                stanKonta=100;
                Saldo->Caption = "100";
        }

        Button1->Enabled=true;
        Button1->SetFocus();


}
//---------------------------------------------------------------------------

