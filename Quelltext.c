#include <iostream>//standart C++ bibliothek
#include <string>
#include <sstream>
#include <cstdlib>
#include "bitmap_image.hpp"


//http://www.rubikssolver.com/
//http://www.rubiks.com/solving-center/pdf/Rubiks_cube_3x3_solution-en.pdf

int realcubecheck(int[6][3][3]);
int realcubecheck2(int[6][3][3]);
int Loesungsweg(int[6][3][3],int[6][3][3]);
int move1check(int[6][3][3],int[6][3][3]);
int move2check(int[6][3][3],int[6][3][3]);
int move3check(int[6][3][3],int[6][3][3]);
int move4check(int[6][3][3],int[6][3][3]);
int move5check(int[6][3][3],int[6][3][3]);
int move6check(int[6][3][3]);
int move6acheck(int[6][3][3]);
int move6bcheck(int[6][3][3]);
int move6ccheck(int[6][3][3]);
int move6dcheck(int[6][3][3]);
int move7check(int[6][3][3]);
int rueckmove7check(int[6][3][3]);
int move8check(int[6][3][3]);
int move9check(int[6][3][3]);
int move10check(int[6][3][3]);


void Wiederherstellen(int[6][3][3],int[6][3][3]);
void ZurücksetzungReferenz(int,int[500],int[6][3][3],int[6][3][3]);

void obenLinksdrehung(int[6][3][3]);
void nachobenRechteSpaltedrehung(int[6][3][3]);
void nachobenLinkeSpealtedrehung(int[6][3][3]);
void untenLinksdrehung(int[6][3][3]);
void VordergrundRechtsdrehung(int[6][3][3]);
void HintergrundRechtsdrehung(int[6][3][3]);
void Mittedrehung(int[6][3][3]);//nach links
void MittlereSpaltedrehung(int[6][3][3]);//nach unten
void Cubedrehung(int[6][3][3]);

//------------------------------------------------------------
void r_obenLinksdrehung(int[6][3][3]);                         //"r_" steht für reverse, also rückgängig
void r_nachobenRechteSpaltedrehung(int[6][3][3]);
void r_nachobenLinkeSpealtedrehung(int[6][3][3]);
void r_untenLinksdrehung(int[6][3][3]);
void r_VordergrundRechtsdrehung(int[6][3][3]);
void r_HintergrundRechtsdrehung(int[6][3][3]);
//------------------------------------------------------------Motive zum Lösen des 3.Schrittes
void motiv1(int[6][3][3]);
void motiv2(int[6][3][3]);
void Rueckmotiv1(int[6][3][3]);
void Rueckmotiv2(int[6][3][3]);

//------------------------------------------------------------Motive zum Lösen des 4,5,6,7.Schrittes
void Schritt4Motiv1(int[6][3][3]);
void Schritt4Motiv2(int[6][3][3]);
void Schritt5Motiv(int[6][3][3]);
void Schritt6Motiv(int[6][3][3]);
void Schritt7Motiv1(int[6][3][3]);
void Schritt7Motiv2(int[6][3][3]);
//-----------------------------------------------------------------------------------------------
void Arraymanipulation(int[500],int[500]);
int Motive(int,int,int[500]);
std::string Int2Str(int);

int main()
{int programmschluss;	
 int RubicsCube[6][3][3],BackupCube[6][3][3],Farbe[6][3][3];
 int Array[500];
 int Array2[500];
 int Array3[500];
 int a,b,c,d,e,x,aa,bb,cc,dd,y;
 int gultigerwurfel,gultigerwurfel2;
 int sechser;
 int move;
 int Nullstelle;
 
 int M1S3[8],M2S3[8];
 int RM1S3[8],RM2S3[8];
 int M1S4[6],M2S4[6];
 int MS5[8];
 int MS6[13];
 int M1S7[12],M2S7[12];

 int DrehungsNummer;

 int xx;
 Nullstelle=0;
 for(a=0;a<=499;a++){Array2[a]=0;Array3[a]=0;};

 
 M1S3[0]=4;M1S3[1]=-2;M1S3[2]=-4;M1S3[3]=2;M1S3[4]=-4;M1S3[5]=5;M1S3[6]=4;M1S3[7]=-5;
 M2S3[0]=-4;M2S3[1]=-3;M2S3[2]=4;M2S3[3]=3;M2S3[4]=4;M2S3[5]=-5;M2S3[6]=-4;M2S3[7]=5;

 RM1S3[0]=-5;RM1S3[1]=4;RM1S3[2]=5;RM1S3[3]=-4;RM1S3[4]=2;RM1S3[5]=-4;RM1S3[6]=-2;RM1S3[7]=4;
 RM2S3[0]=5;RM2S3[1]=-4;RM2S3[2]=-5;RM2S3[3]=4;RM2S3[4]=3;RM2S3[5]=4;RM2S3[6]=-3;RM2S3[7]=-4;

 M1S4[0]=5;M1S4[1]=-4;M1S4[2]=-3;M1S4[3]=4;M1S4[4]=3;M1S4[5]=-5;
 M2S4[0]=5;M2S4[1]=-3;M2S4[2]=-4;M2S4[3]=3;M2S4[4]=4;M2S4[5]=-5;

 MS5[0]=-3;MS5[1]=-4;MS5[2]=3;MS5[3]=-4;MS5[4]=-3;MS5[5]=-4;MS5[6]=-4;MS5[7]=3;

 MS6[0]=3;MS6[1]=5;MS6[2]=3;MS6[3]=-6;MS6[4]=-6;MS6[5]=-3;MS6[6]=-5;MS6[7]=3;MS6[8]=-6;MS6[9]=-6;MS6[10]=-3;MS6[11]=-3;MS6[12]=4;

 M1S7[0]=5; M1S7[1]=5; M1S7[2]=-4; M1S7[3]=2; M1S7[4]=3; M1S7[5]=5; M1S7[6]=5; M1S7[7]=-2; M1S7[8]=-3; M1S7[9]=-4; M1S7[10]=5; M1S7[11]=5;

 M2S7[0]=5; M2S7[1]=5; M2S7[2]=4; M2S7[3]=2; M2S7[4]=3; M2S7[5]=5; M2S7[6]=5; M2S7[7]=-2; M2S7[8]=-3; M2S7[9]=4; M2S7[10]=5; M2S7[11]=5;

   for(a=0;a<=5;a++)
  {for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {Farbe[a][b][c]=a+1;};};};

  gultigerwurfel2=0;
  while(gultigerwurfel2==0){ 
  gultigerwurfel=0;
  while(gultigerwurfel==0){
  printf("\nSeite 1:\n");
  scanf("%d %d %d",&RubicsCube[0][0][0],&RubicsCube[0][0][1],&RubicsCube[0][0][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[0][1][0],&RubicsCube[0][1][1],&RubicsCube[0][1][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[0][2][0],&RubicsCube[0][2][1],&RubicsCube[0][2][2]);
  printf("\n");
  printf("\n");

  printf("\nSeite 2:\n");
  scanf("%d %d %d",&RubicsCube[1][0][0],&RubicsCube[1][0][1],&RubicsCube[1][0][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[1][1][0],&RubicsCube[1][1][1],&RubicsCube[1][1][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[1][2][0],&RubicsCube[1][2][1],&RubicsCube[1][2][2]);
  printf("\n");
  printf("\n");

  printf("\nSeite 3:\n");
  scanf("%d %d %d",&RubicsCube[2][0][0],&RubicsCube[2][0][1],&RubicsCube[2][0][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[2][1][0],&RubicsCube[2][1][1],&RubicsCube[2][1][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[2][2][0],&RubicsCube[2][2][1],&RubicsCube[2][2][2]);
  printf("\n");
  printf("\n");

  printf("\nSeite 4:\n");
  scanf("%d %d %d",&RubicsCube[3][0][0],&RubicsCube[3][0][1],&RubicsCube[3][0][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[3][1][0],&RubicsCube[3][1][1],&RubicsCube[3][1][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[3][2][0],&RubicsCube[3][2][1],&RubicsCube[3][2][2]);
  printf("\n");
  printf("\n");
  
  printf("\nSeite 5:\n");
  scanf("%d %d %d",&RubicsCube[4][0][0],&RubicsCube[4][0][1],&RubicsCube[4][0][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[4][1][0],&RubicsCube[4][1][1],&RubicsCube[4][1][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[4][2][0],&RubicsCube[4][2][1],&RubicsCube[4][2][2]);
  printf("\n");
  printf("\n");

  printf("\nSeite 6:\n");
  scanf("%d %d %d",&RubicsCube[5][0][0],&RubicsCube[5][0][1],&RubicsCube[5][0][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[5][1][0],&RubicsCube[5][1][1],&RubicsCube[5][1][2]);
  printf("\n");
  scanf("%d %d %d",&RubicsCube[5][2][0],&RubicsCube[5][2][1],&RubicsCube[5][2][2]);
  printf("\n");
  printf("\n");

   for(a=0;a<=5;a++)
  {printf("Seite %d:",a+1);
   printf("\n");
   for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {printf("%d ",RubicsCube[a][b][c]);}
   printf("\n");}
   printf("\n");};

   gultigerwurfel=1;
   if((realcubecheck(RubicsCube)==0)||(realcubecheck2(RubicsCube)==0))
  {gultigerwurfel=0;printf("ungueltiger Wuerfel, bitte erneut eingeben \n");};};

   gultigerwurfel2=1;
   if(Loesungsweg(Farbe,RubicsCube)==1)
   {gultigerwurfel2=0;printf("bereits geloester Wuerfel, bitte erneut eingeben \n");};};
//-----------------------------------------------------------------------------------------------bis hier Kontrolle gültigen Würfels!


   for(a=0;a<=5;a++)
  {for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {BackupCube[a][b][c]=RubicsCube[a][b][c];};};}//BackupCube = Momentane Lage des reele Würfels ; RubicsCube = Lage mit Drehungen des Würfel
   
   move=1;

   while(move<=5)//dieser while-loop führt folgendes 6 mal aus um alle Schritte zu erfüllen
   {c=1;d=1;//d ist die Zahl mit der man in die Hauptschleife gelangt
   for(a=1;a<=499;a++){Array[a]=0;};//alle Referenzen werden auf Null gestellt (außer Array[0])
   
   Array[0]=-1;//Array[0] wird als -1 gesetzt
   r_obenLinksdrehung(RubicsCube);//erste Drehung wird außerhalb des Loops geschrieben, denn sonst könnte die Hauptschleife ihre Arbeit nicht machen, da sie erst ab der zweiten Referenz anfängt zu prüfen
   if(move==1)
   {if(move1check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==2)
   {if(move2check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==3)
   {if(move3check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==4)
   {if(move4check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==5)
   {if(move5check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};};

   b=1;//b ist die Position der 1.Nullstelle

   while(d==1)//solange d==1, ist der Würfel noch nicht gelöst
   {sechser=0;c=1;
    for(a=b;a>=0;a=a-1){if(Array[b-c]==6){sechser++;c++;}else{a=-1;};};
	/* der Mechanismus, dass b immer mit c subtrahiert wird (c wird immer um eins größer), 
	geht von hinten nach vorne im Array und kontrolliert alle Stellen mit einer 6, die sich am Ende der Nicht-Nullzahlen befinden */
	a=0;//a ist die Nummer (Variable), die im Array im Moment zugreift
	while(a<=b-2)
   {    if((Array[a]==-1)&&(a!=b-sechser-1)){r_obenLinksdrehung(RubicsCube);}//der Term b-sechser-1 bringt jemandem an der Stelle bevor die 6er am Ende beginnen
   else if((Array[a]==-2)&&(a!=b-sechser-1)){r_nachobenRechteSpaltedrehung(RubicsCube);}
   else if((Array[a]==-3)&&(a!=b-sechser-1)){r_nachobenLinkeSpealtedrehung(RubicsCube);}
   else if((Array[a]==-4)&&(a!=b-sechser-1)){r_untenLinksdrehung(RubicsCube);}
   else if((Array[a]==-5)&&(a!=b-sechser-1)){r_VordergrundRechtsdrehung(RubicsCube);}
   else if((Array[a]==-6)&&(a!=b-sechser-1)){r_HintergrundRechtsdrehung(RubicsCube);}
	   
   else if((Array[a]==1)&&(a!=b-sechser-1)){obenLinksdrehung(RubicsCube);}
   else if((Array[a]==2)&&(a!=b-sechser-1)){nachobenRechteSpaltedrehung(RubicsCube);}
   else if((Array[a]==3)&&(a!=b-sechser-1)){nachobenLinkeSpealtedrehung(RubicsCube);}
   else if((Array[a]==4)&&(a!=b-sechser-1)){untenLinksdrehung(RubicsCube);}
   else if((Array[a]==5)&&(a!=b-sechser-1)){VordergrundRechtsdrehung(RubicsCube);}
   else if((Array[a]==6)&&(a<b-sechser)){HintergrundRechtsdrehung(RubicsCube);}
   /*in diesem Fall könnte der vorherige Term auch benutzt werden, da aber die Stelle vor der "ersten"
   6 eh keine 6 sein kann (sie würde sonst auch zu dern sechsern zählen) kann man auch den Term 
   a<b-sechser benutzen, weil es für alle 6er vor den sechsern gilt*/

//Alle Schritte bis hier waren da um alle Drehungungen vor den sechsern wiederauszuführen, da diese unverändert bleiben
//--------------------------------------------------------------------------------------------------------------------------
   else if((Array[a]==-1)&&(a==b-sechser-1)){r_nachobenRechteSpaltedrehung(RubicsCube);Array[a]=-2;}//wenn die Drehung vor den 6ern ist von -1 bis 5 ist,
   else if((Array[a]==-2)&&(a==b-sechser-1)){r_nachobenLinkeSpealtedrehung(RubicsCube);Array[a]=-3;}//dann wird sie um eins vergrößert
   else if((Array[a]==-3)&&(a==b-sechser-1)){r_untenLinksdrehung(RubicsCube);Array[a]=-4;}
   else if((Array[a]==-4)&&(a==b-sechser-1)){r_VordergrundRechtsdrehung(RubicsCube);Array[a]=-5;}
   else if((Array[a]==-5)&&(a==b-sechser-1)){r_HintergrundRechtsdrehung(RubicsCube);Array[a]=-6;}
   else if((Array[a]==-6)&&(a==b-sechser-1)){obenLinksdrehung(RubicsCube);Array[a]=1;}

   else if((Array[a]==1)&&(a==b-sechser-1)){nachobenRechteSpaltedrehung(RubicsCube);Array[a]=2;}
   else if((Array[a]==2)&&(a==b-sechser-1)){nachobenLinkeSpealtedrehung(RubicsCube);Array[a]=3;}
   else if((Array[a]==3)&&(a==b-sechser-1)){untenLinksdrehung(RubicsCube);Array[a]=4;}
   else if((Array[a]==4)&&(a==b-sechser-1)){VordergrundRechtsdrehung(RubicsCube);Array[a]=5;}
   else if((Array[a]==5)&&(a==b-sechser-1)){HintergrundRechtsdrehung(RubicsCube);Array[a]=6;}
   else if((Array[a]==6)&&(a>=b-sechser)){r_obenLinksdrehung(RubicsCube);Array[a]=-1;};
   //wenn sie aber 6 ist, dann werden alle secher-Zahlen der Reihe nach, immer den selben Loop ausführend auf 1 gestellt
   a++;};
/*Alle Schritte bis hier werden ausgeführt nur wenn secher>0 ist, da a wegen der Definition des while-loops maximal b-2 werden kann und
wenn keine 6er vorhanden wären a b-1 entsprechen würde */

   if((Array[b-1]==6)&&(b==sechser)){r_obenLinksdrehung(RubicsCube);Array[b-1]=-1;Array[b]=-1;b++;r_obenLinksdrehung(RubicsCube);
   if(move==1)//bei jedem Wert von "move" wird jeweils eine andere Funktion ausgeführt, um alle Schritte zu erfüllen
   {if(move1check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==2)
   {if(move2check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==3)
   {if(move3check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==4)
   {if(move4check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==5)
   {if(move5check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};};}
   //falls alle Referenzen vor der 0 den Wert 6 haben, dann wird zweimal die Drehung 
   //eins ausgeführt, was die Anzahl der Drehungen in der vorherigen erhöht und somit b um 1 vergrößert

   else if((Array[b-1]==6)&&(b!=sechser)){r_obenLinksdrehung(RubicsCube);Array[b-1]=-1;//falls sie eine einfache 6 ist, dann wird bloß Drehung eins ausgeführt
   if(move==1)
   {if(move1check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==2)
   {if(move2check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==3)
   {if(move3check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==4)
   {if(move4check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};}
   else if(move==5)
   {if(move5check(Farbe,RubicsCube)==1){d=0;} else{Wiederherstellen(RubicsCube,BackupCube);};};}

   else{
   for(a=0;a<=10;a++)     
   {    if(Array[b-1]==-1){r_nachobenRechteSpaltedrehung(RubicsCube);Array[b-1]=-2;}//Hier wird nur die letzte Zahl bearbeitet, falls    
   else if(Array[b-1]==-2){r_nachobenLinkeSpealtedrehung(RubicsCube);Array[b-1]=-3;}//sie von -1 bis 5 ist, dann wird einfach die nächste Drehung ausgeführt.
   else if(Array[b-1]==-3){r_untenLinksdrehung(RubicsCube);Array[b-1]=-4;}
   else if(Array[b-1]==-4){r_VordergrundRechtsdrehung(RubicsCube);Array[b-1]=-5;}
   else if(Array[b-1]==-5){r_HintergrundRechtsdrehung(RubicsCube);Array[b-1]=-6;}
   else if(Array[b-1]==-6){obenLinksdrehung(RubicsCube);Array[b-1]=1;} 
	   
   else if(Array[b-1]==1){nachobenRechteSpaltedrehung(RubicsCube);Array[b-1]=2;}//Hier wird nur die letzte Zahl bearbeitet, falls    
   else if(Array[b-1]==2){nachobenLinkeSpealtedrehung(RubicsCube);Array[b-1]=3;}//sie von 1-5 ist, dann wird einfach die nächste Drehung ausgeführt.
   else if(Array[b-1]==3){untenLinksdrehung(RubicsCube);Array[b-1]=4;}
   else if(Array[b-1]==4){VordergrundRechtsdrehung(RubicsCube);Array[b-1]=5;}
   else if(Array[b-1]==5){HintergrundRechtsdrehung(RubicsCube);Array[b-1]=6;}

   if(move==1)
   {if(move1check(Farbe,RubicsCube)==0){ZurücksetzungReferenz(b,Array,RubicsCube,BackupCube);}else{d=0;a=12;};}//wenn sie nicht den Würfel löst wird sie hier zurückgesetzt
   else if(move==2)
   {if(move2check(Farbe,RubicsCube)==0){ZurücksetzungReferenz(b,Array,RubicsCube,BackupCube);}else{d=0;a=12;};}
   else if(move==3)
   {if(move3check(Farbe,RubicsCube)==0){ZurücksetzungReferenz(b,Array,RubicsCube,BackupCube);}else{d=0;a=12;};}
   else if(move==4)
   {if(move4check(Farbe,RubicsCube)==0){ZurücksetzungReferenz(b,Array,RubicsCube,BackupCube);}else{d=0;a=12;};}
   else if(move==5)
   {if(move5check(Farbe,RubicsCube)==0){ZurücksetzungReferenz(b,Array,RubicsCube,BackupCube);}else{d=0;a=12;};};};};};

   for(a=0;a<=5;a++)
  {for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {BackupCube[a][b][c]=RubicsCube[a][b][c];};};}//BackupCube bekommt die Werte des Würfels im erwünschten Schritt ; RubicsCube = Lage mit Drehungen des Würfel

//-------------------------------------------------------------------------------------------bis hier ist der Mechanismus zum Lösen des Programmes
 
  {for(a=0;a<=499;a++)
	    if(Array[a]==-1){printf("1.Seite: 1.Zeile nach rechts drehen\n");Array2[Nullstelle]=-1;Nullstelle++;}
   else if(Array[a]==-2){printf("1.Seite: 3.Spalte nach unten drehen\n");Array2[Nullstelle]=-2;Nullstelle++;}
   else if(Array[a]==-3){printf("1.Seite: 1.Spalte nach unten drehen\n");Array2[Nullstelle]=-3;Nullstelle++;}
   else if(Array[a]==-4){printf("1.Seite: 3.Zeile nach rechts drehen\n");Array2[Nullstelle]=-4;Nullstelle++;}
   else if(Array[a]==-5){printf("2.Seite: 1.Spalte nach oben drehen\n");Array2[Nullstelle]=-5;Nullstelle++;}
   else if(Array[a]==-6){printf("2.Seite: 3.Spalte nach oben drehen\n");Array2[Nullstelle]=-6;Nullstelle++;} 
	  
   else if(Array[a]==1){printf("1.Seite: 1.Zeile nach links drehen\n");Array2[Nullstelle]=1;Nullstelle++;}
   else if(Array[a]==2){printf("1.Seite: 3.Spalte nach oben drehen\n");Array2[Nullstelle]=2;Nullstelle++;}
   else if(Array[a]==3){printf("1.Seite: 1.Spalte nach oben drehen\n");Array2[Nullstelle]=3;Nullstelle++;}
   else if(Array[a]==4){printf("1.Seite: 3.Zeile nach links drehen\n");Array2[Nullstelle]=4;Nullstelle++;}
   else if(Array[a]==5){printf("2.Seite: 1.Spalte nach unten drehen\n");Array2[Nullstelle]=5;Nullstelle++;}
   else if(Array[a]==6){printf("2.Seite: 3.Spalte nach unten drehen\n");Array2[Nullstelle]=6;Nullstelle++;};} 
   
   move++;};

   //2nd mainloop:
aa=0;bb=0;cc=0;dd=0;
x=0;
y=0;

while(y<4)
{if(move6acheck(RubicsCube)==1){aa=1;}else{aa=0;};
 if(move6bcheck(RubicsCube)==1){bb=1;}else{bb=0;};
 if(move6ccheck(RubicsCube)==1){cc=1;}else{cc=0;};
 if(move6dcheck(RubicsCube)==1){dd=1;}else{dd=0;};


if((aa==1)&&(bb==1)&&(cc==1)&&(dd==1)){y=4;};  
	 if(move6check(RubicsCube)==1){motiv1(RubicsCube);printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
	 printf("bitte Motiv 1 durchfuehren(Seite 1 entspricht der gelben Seite auf dem 1.Bild)\n");Array2[Nullstelle]=21;Nullstelle++;}
else if(move6check(RubicsCube)==2){motiv2(RubicsCube);printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
printf("bitte Motiv 2 durchfuehren(Seite 1 entspricht der roten Seite auf dem 2.Bild)\n");Array2[Nullstelle]=22;Nullstelle++;}
else if(move6check(RubicsCube)==3){obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
								   motiv1(RubicsCube);obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
								                      obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
								     				  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
								   printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
								   printf("1.Seite: 3.Zeile nach rechts drehen\nbitte Motiv 1 durchfuehren(Seite 2 entspricht der gelben Seite auf dem 1.Bild)\n");Array2[Nullstelle]=23;Nullstelle++;}
else if(move6check(RubicsCube)==4){obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
                                     motiv2(RubicsCube);obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
									                    obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
														obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
									 printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
									 printf("1.Seite: 3.Zeile nach rechts drehen\nbitte Motiv 2 durchfuehren(Seite 2 entspricht der roten Seite auf dem 2.Bild\n");Array2[Nullstelle]=24;Nullstelle++;}
else if(move6check(RubicsCube)==5){obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
                                    obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
									motiv1(RubicsCube);obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
									                   obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
									printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
									printf("1.Seite: 3.Zeile nach rechts drehen\n1.Seite: 3.Zeile nach rechts drehen\nbitte Motiv 1 durchfuehren(Seite 3 entspricht der gelben Seite auf dem 1.Bild\n");Array2[Nullstelle]=25;Nullstelle++;}
else if(move6check(RubicsCube)==6){obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
                                      obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
								      motiv2(RubicsCube);obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
									                     obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
									  printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
									  printf("1.Seite: 3.Zeile nach rechts drehen\n1.Seite: 3.Zeile nach rechts drehen\nbitte Motiv 2 durchfuehren(Seite 3 entspricht der roten Seite auf dem 2.Bild\n");Array2[Nullstelle]=26;Nullstelle++;}
else if(move6check(RubicsCube)==7){obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
                                    obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
									obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
									motiv1(RubicsCube);obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
									printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
									printf("1.Seite: 3.Zeile nach rechts drehen\n1.Seite: 3.Zeile nach rechts drehen\n1.Seite: 3.Zeile nach rechts drehen\nbitte Motiv 1 durchfuehren(Seite 4 entspricht der gelben Seite auf dem 1.Bild\n");Array2[Nullstelle]=27;Nullstelle++;}
else if(move6check(RubicsCube)==8){obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
                                      obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
	  					    		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);
   								      motiv2(RubicsCube);obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
								      printf("1.Seite: 3.Zeile nach %dmal nach links drehen\n",y);xx=0;
	 while(xx<y){Array2[Nullstelle]=4;Nullstelle++;xx++;};y=0;
									  printf("1.Seite: 3.Zeile nach rechts drehen\n1.Seite: 3.Zeile nach rechts drehen\n1.Seite: 3.Zeile nach rechts drehen\nbitte Motiv 2 durchfuehren(Seite 4 entspricht der roten Seite auf dem 2.Bild\n");Array2[Nullstelle]=28;Nullstelle++;}
                                      
else if(move6check(RubicsCube)==0)
    {
     if((aa==1)&&(bb==1)&&(cc==1)&&(dd==1)){y=4;}
	 else if((y<3)&&((aa==0)||(bb==0)||(cc==0)||(dd==0))){untenLinksdrehung(RubicsCube);y++;}
     else if((y==3)&&((aa==0)||(bb==0)||(cc==0)||(dd==0))){untenLinksdrehung(RubicsCube);
	 y=0;
	//aa ist für das rechte steinchen der seite 1
	//bb ist für das linke steinchen der seite 1
	//cc ist für das rechte steinchen der seite 3
	//dd ist für das linke steinchen der seite 3
	 if(bb==0){
		  Rueckmotiv1(RubicsCube);
		  printf("bitte Rueckmotiv 1 durchfuehren(Seite 1 entspricht der gelben Seite auf dem 1.Bild\n");Array2[Nullstelle]=29;Nullstelle++;}
	 else if(aa==0){
		  Rueckmotiv2(RubicsCube);
		  printf("bitte Rueckmotiv 2 durchfuehren(Seite 1 entspricht der roten Seite auf dem 2.Bild\n");Array2[Nullstelle]=210;Nullstelle++;}
	 else if(dd==0){
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
		  Rueckmotiv1(RubicsCube);
		  printf("bitte Rueckmotiv 1 durchfuehren(Seite 3 entspricht der gelben Seite auf dem 1.Bild\n");Array2[Nullstelle]=211;Nullstelle++;
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);}
	 else if(cc==0){
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
		  Rueckmotiv2(RubicsCube);
		  printf("bitte Rueckmotiv 2 durchfuehren(Seite 3 entspricht der roten Seite auf dem 2.Bild\n");Array2[Nullstelle]=212;Nullstelle++;
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);
		  obenLinksdrehung(RubicsCube);Mittedrehung(RubicsCube);untenLinksdrehung(RubicsCube);};
	 
	 };};};


	 //3rd mainloop:
  y=0;

   for(a=0;a<=5;a++)
  {for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {BackupCube[a][b][c]=RubicsCube[a][b][c];};};};

if(move7check(RubicsCube)==1){y=1;};

if(y==0)
{if(rueckmove7check(RubicsCube)==1)
   {Schritt4Motiv1(RubicsCube);
   printf("bitte Motiv 1 durchfuehren\n");Array2[Nullstelle]=31;Nullstelle++;
   for(a=0;a<=5;a++)
  {for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {BackupCube[a][b][c]=RubicsCube[a][b][c];};};};};};
   

 if(y==0){Schritt4Motiv1(RubicsCube);
          if(move7check(RubicsCube)==1){printf("1.Seite: 3.Zeile 0mal nach links drehen\nbitte Motiv 1(von Schritt 4) durchfuehren\n");Array2[Nullstelle]=32;Nullstelle++;y=1;}
		  else{Wiederherstellen(RubicsCube,BackupCube);};};

 if(y==0){untenLinksdrehung(RubicsCube);
	      Schritt4Motiv1(RubicsCube);
          if(move7check(RubicsCube)==1){printf("1.Seite: 3.Zeile 1mal nach links drehen\nbitte Motiv 1(von Schritt 4) durchfuehren\n");Array2[Nullstelle]=33;Nullstelle++;y=1;}
		  else{Wiederherstellen(RubicsCube,BackupCube);};};


 if(y==0){untenLinksdrehung(RubicsCube);
          untenLinksdrehung(RubicsCube);
	      Schritt4Motiv1(RubicsCube);
          if(move7check(RubicsCube)==1){printf("1.Seite: 3.Zeile 2mal nach links drehen\nbitte Motiv 1(von Schritt 4) durchfuehren\n");Array2[Nullstelle]=34;Nullstelle++;y=1;}
		  else{Wiederherstellen(RubicsCube,BackupCube);};};

 if(y==0){r_untenLinksdrehung(RubicsCube);
	      Schritt4Motiv1(RubicsCube);
          if(move7check(RubicsCube)==1){printf("1.Seite: 3.Zeile 1mal nach rechts drehen\nbitte Motiv 1(von Schritt 4) durchfuehren\n");Array2[Nullstelle]=35;Nullstelle++;y=1;}
		  else{Wiederherstellen(RubicsCube,BackupCube);};};


 if(y==0){Schritt4Motiv2(RubicsCube);
          if(move7check(RubicsCube)==1){printf("bitte Motiv 2 durchfuehren");Array2[Nullstelle]=36;Nullstelle++;y=1;}
		  else{Wiederherstellen(RubicsCube,BackupCube);};};

 if(y==0){untenLinksdrehung(RubicsCube);
	      Schritt4Motiv2(RubicsCube);
          if(move7check(RubicsCube)==1){printf("1.Seite: 3.Zeile 1mal nach links drehen\nbitte Motiv 2(von Schritt 4) durchfuehren\n");Array2[Nullstelle]=37;Nullstelle++;y=1;}
		  else{Wiederherstellen(RubicsCube,BackupCube);};};

y=0;      

 if(move8check(RubicsCube)==4){y=1;};
 while(y<1){

 if(move8check(RubicsCube)==0){
 if(RubicsCube[1][2][0]==6){Schritt5Motiv(RubicsCube);printf("bitte motiv des 5.Schrittes durchführen\n");Array2[Nullstelle]=51;Nullstelle++;}
 else if(RubicsCube[2][2][0]==6){untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile nach links drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=52;Nullstelle++;}
 else if(RubicsCube[3][2][0]==6){untenLinksdrehung(RubicsCube);untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile 2mal nach links drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=53;Nullstelle++;}
 else if(RubicsCube[0][2][0]==6){r_untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile nach rechts drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=54;Nullstelle++;};}

 else if(move8check(RubicsCube)==1){
 if(RubicsCube[5][0][2]==6){Schritt5Motiv(RubicsCube);printf("bitte motiv des 5.Schrittes durchführen\n");Array2[Nullstelle]=55;Nullstelle++;}
 else if(RubicsCube[5][2][2]==6){untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile nach links drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=56;Nullstelle++;}
 else if(RubicsCube[5][2][0]==6){untenLinksdrehung(RubicsCube);untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile 2mal nach links drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=57;Nullstelle++;}
 else if(RubicsCube[5][0][0]==6){r_untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile nach rechts drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=58;Nullstelle++;};}

 else if(move8check(RubicsCube)==2){
 if(RubicsCube[0][2][2]==6){Schritt5Motiv(RubicsCube);printf("bitte motiv des 5.Schrittes durchführen\n");Array2[Nullstelle]=59;Nullstelle++;}
 else if(RubicsCube[1][2][2]==6){untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile nach links drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=510;Nullstelle++;}
 else if(RubicsCube[2][2][2]==6){untenLinksdrehung(RubicsCube);untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile 2mal nach links drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=511;Nullstelle++;}
 else if(RubicsCube[3][2][2]==6){r_untenLinksdrehung(RubicsCube);Schritt5Motiv(RubicsCube);printf("1.Seite: 3.Zeile nach rechts drehen\nbitte motiv des 5.Schrittes durchfuehren\n");Array2[Nullstelle]=512;Nullstelle++;};};
 
 if(move8check(RubicsCube)==4){y=1;};}

	 //4th mainloop:
     x=0;
	 if(move9check(RubicsCube)==1){x=4;};
	 while(x<4)
     {if(move9check(RubicsCube)!=0)
     {if((move9check(RubicsCube)==14)||(move9check(RubicsCube)==23)){Schritt6Motiv(RubicsCube);
     printf("bitte Motiv des 6.Schrittes durchführen(Seite 1 bleibt gleich)\n");Array2[Nullstelle]=61;Nullstelle++;}
	 else{if(move9check(RubicsCube)==12){Schritt6Motiv(RubicsCube);printf("bitte Motiv des 6.Schrittes durchführen(Seite 1 bleibt gleich)\n");Array2[Nullstelle]=62;Nullstelle++;}
	 else if(move9check(RubicsCube)==13){Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);
	 Schritt6Motiv(RubicsCube);Cubedrehung(RubicsCube);printf("bitte Motiv des 6.Schrittes durchführen(Seite 4 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=63;Nullstelle++;}
     else if(move9check(RubicsCube)==24){Cubedrehung(RubicsCube);Schritt6Motiv(RubicsCube);
	 Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);printf("bitte Motiv des 6.Schrittes durchführen(Seite 2 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=64;Nullstelle++;}
	 else if(move9check(RubicsCube)==34){Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);Schritt6Motiv(RubicsCube);Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);
	 printf("bitte Motiv des 6.Schrittes durchführen(Seite 3 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=65;Nullstelle++;};};}
	 else{x++;untenLinksdrehung(RubicsCube);printf("1.Seite: 3.Zeile nach links drehen\n");Array2[Nullstelle]=66;Nullstelle++;};
	 if(move9check(RubicsCube)==1){x=4;};}

	  //5th mainloop:
	 
	x=0;
	if(move10check(RubicsCube)==1)
	{Schritt7Motiv1(RubicsCube);
	printf("bitte Motiv 1 durchfuehren(Seite 1 bleibt gleich)\n");Array2[Nullstelle]=71;Nullstelle++;}

   for(a=0;a<=5;a++)
  {for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {BackupCube[a][b][c]=RubicsCube[a][b][c];};};}

	 
	 Schritt7Motiv1(RubicsCube);
	 if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	 else{printf("bitte Motiv 1 durchfuehren(Seite 1 bleibt gleich)\n");Array2[Nullstelle]=72;Nullstelle++;x=1;}

	 if(x==0)
	 {Cubedrehung(RubicsCube);
	  Schritt7Motiv1(RubicsCube);
	  Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);
	  if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	  else{printf("bitte Motiv 1 durchfuehren(Seite  2 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=75;Nullstelle++;x=1;};}

	  if(x==0)
	 {Cubedrehung(RubicsCube);
	  Cubedrehung(RubicsCube);
	  Schritt7Motiv1(RubicsCube);
	  Cubedrehung(RubicsCube);Cubedrehung(RubicsCube);
	  if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	  else{printf("bitte Motiv 1 durchfuehren(Seite 3 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=74;Nullstelle++;x=1;};}
	 
	  if(x==0)
	  {Cubedrehung(RubicsCube);
	   Cubedrehung(RubicsCube);
	   Cubedrehung(RubicsCube);
	  Schritt7Motiv1(RubicsCube);
	  Cubedrehung(RubicsCube);
	  if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	  else{printf("bitte Motiv 1 durchfuehren(Seite 4 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=73;Nullstelle++;x=1;};}

	// -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --Motiv 2 
	  if(x==0){Schritt7Motiv2(RubicsCube);
	 if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	 else{printf("bitte Motiv 2 durchfuehren(Seite 1 bleibt gleich)\n");Array2[Nullstelle]=76;Nullstelle++;x=1;};}

	 if(x==0)
	 {Cubedrehung(RubicsCube);
	  Schritt7Motiv2(RubicsCube);
	  Cubedrehung(RubicsCube);
	  Cubedrehung(RubicsCube);
	  Cubedrehung(RubicsCube);
	  if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	  else{printf("bitte Motiv 2 durchfuehren(Seite 2 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=79;Nullstelle++;x=1;};}

	  if(x==0)
	 {Cubedrehung(RubicsCube);
	  Cubedrehung(RubicsCube);
	  Schritt7Motiv2(RubicsCube);
	  Cubedrehung(RubicsCube);
	  Cubedrehung(RubicsCube);
	  if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	  else{printf("bitte Motiv 2 durchfuehren(Seite 3 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=78;Nullstelle++;x=1;};}
 
	  if(x==0)
	  {Cubedrehung(RubicsCube);
	   Cubedrehung(RubicsCube);
	   Cubedrehung(RubicsCube);
	   Schritt7Motiv2(RubicsCube);
	   Cubedrehung(RubicsCube);
	  if(Loesungsweg(RubicsCube,Farbe)==0){Wiederherstellen(RubicsCube,BackupCube);}
	  else{printf("bitte Motiv 2 durchfuehren(Seite 4 wird als Seite 1 gezählt)\n");Array2[Nullstelle]=77;Nullstelle++;x=1;};};


 Arraymanipulation(Array3,Array2);
 //________________________________________________________________________________________________________________________________________
std::string BMPFileName,number;
std::string file_name;
int i,DasEnde;
DasEnde=0;

//check in Array3 ob es 4 gleiche drehungen hintereinander gibt
for(i=0;i<=496;i++)
{if( (Array3[i]==Array3[i+1]) && (Array3[i]==Array3[i+2]) && (Array3[i]==Array3[i+3]) && /*nicht das ende*/ (Array3[i]!=0) )
{Array3[i]=10;//
 Array3[i+1]=10;
 Array3[i+2]=10;
 Array3[i+3]=10;};};

 //check in Array3 ob es 2 gegendrehungen hintereinander gibt
 for(i=0;i<=498;i++)
 {if( (Array3[i]==-Array3[i+1]) && /*nicht das ende*/ (Array3[i]!=0) )
 {Array3[i]=10;Array3[i+1]=10;};};
 DrehungsNummer=0;

for(i=0;i<=499;i++)
{     if(Array3[i]==-1){file_name=("b-1.bmp");DrehungsNummer++;}//hier den input namen schreiben
 else if(Array3[i]==-2){file_name=("b-2.bmp");DrehungsNummer++;}
 else if(Array3[i]==-3){file_name=("b-3.bmp");DrehungsNummer++;}
 else if(Array3[i]==-4){file_name=("b-4.bmp");DrehungsNummer++;}
 else if(Array3[i]==-5){file_name=("b-5.bmp");DrehungsNummer++;}
 else if(Array3[i]==-6){file_name=("b-6.bmp");DrehungsNummer++;}
 else if(Array3[i]==-7){file_name=("b-7.bmp");DrehungsNummer++;}

 else if(Array3[i]==1){file_name=("b1.bmp");DrehungsNummer++;}
 else if(Array3[i]==2){file_name=("b2.bmp");DrehungsNummer++;}
 else if(Array3[i]==3){file_name=("b3.bmp");DrehungsNummer++;}
 else if(Array3[i]==4){file_name=("b4.bmp");DrehungsNummer++;}
 else if(Array3[i]==5){file_name=("b5.bmp");DrehungsNummer++;}
 else if(Array3[i]==6){file_name=("b6.bmp");DrehungsNummer++;}
 else if(Array3[i]==7){file_name=("b7.bmp");DrehungsNummer++;}
 else if(Array3[i]==0){file_name=("ende.bmp");DrehungsNummer++;DasEnde=1;}


 if(Array3[i]!=10) // 10 ist wenn welche schritte sich aufheben also wird es nicht agezeigt
 {		bitmap_image image(file_name);//funktion, die das bmp bild mit gegebenen Namen importiert
		BMPFileName="C:\\temp\\Drehung";//hier kommt der prefix von der outputdatei, z.B "test" fur eine outputdatei "test25.bmp"
		number=Int2Str(DrehungsNummer);//nummer, die an dem prefix der outputdatei angeheftet wird, z.B. "25" fur eine outputdatei "test25.bmp"

		BMPFileName=BMPFileName+number+".bmp";//hier wird der prefix mit der index nummer und die endung .bmp zusammengebracht zu, z.B. "test25.bmp"
		image.save_image(BMPFileName);};//funktion, die das eingelesene bild mit dem vorhin gegebenen Namen in ein neues bild mit dem neuen namen speichert

 if(DasEnde==1){i=500;};};
 printf("\nNun ist Ihr Wuerfel geloest!"); 

 system("Display.bat");//öffnet das bild des ersten schrittes

 printf("\nGeben sie eine beliebige Zahl ein um das Fenster zu schliessen:");
 scanf("%d",&programmschluss);}

int realcubecheck(int B[6][3][3])
{if((B[0][1][1]==1)&&(B[1][1][1]==2)&&(B[2][1][1]==3)&&(B[3][1][1]==4)&&(B[4][1][1]==5)&&(B[5][1][1]==6))
{return 1;}
else {return 0;};}

int realcubecheck2(int B[6][3][3])
{int u,v,w;
 int a,b,c,d,e,f;
 a=0;b=0;c=0;d=0;e=0;f=0;

   for(u=0;u<=5;u++)
  {for(v=0;v<=2;v++)
  {for(w=0;w<=2;w++)
  {     if(B[u][v][w]==1){a++;}
   else if(B[u][v][w]==2){b++;}
   else if(B[u][v][w]==3){c++;}
   else if(B[u][v][w]==4){d++;}
   else if(B[u][v][w]==5){e++;}
   else if(B[u][v][w]==6){f++;};};};};

    if((a==9)&&(b==9)&&(c==9)&&(d==9)&&(e==9)&&(f==9))
    {return 1;}
    else
	{return 0;};}

int Loesungsweg(int C[6][3][3],int D[6][3][3])
{int a,b,c;
  
   for(a=0;a<=5;a++)
  {for(b=0;b<=2;b++)
  {for(c=0;c<=2;c++)
  {if(C[a][b][c]!=D[a][b][c])
  {return 0;};};};};
   return 1;}

int move1check(int C[6][3][3],int D[6][3][3])
{int a,b,c,x;
 x=0;

 //bei dieser Funktion wird der erste Schritt nachgeprüft

 a=4;c=1;//Hier werden die Farben bei den Kästchen Seite5-Reihe1&3-Spalte2 nachgeprüft
 for(b=0;b<=2;b=b+2){if(C[a][b][c]==D[a][b][c])
 {x++;};}//da es sich hier um 2 Kästchen handelt, muss dann bei richtigem Würfel die Variable x den Wert 2 haben

 b=1;//Hier werden die Farben bei den Kästchen Seite5-Reihe2-Spalte1&2&3 nachgeprüft
 for(c=0;c<=2;c++){if(C[a][b][c]==D[a][b][c])
 {x++;};}//da es sich hier um 3 Kästchen handelt, muss dann bei richtigem Würfel die Variable x den Wert 3 haben
 
 c=1;//Hier werden die Farben bei den Kästchen Seite1bis4-Reihe1&2-Spalte1 nachgeprüft
 for(a=0;a<=3;a++){for(b=0;b<=1;b++){if(C[a][b][c]==D[a][b][c])
 {x++;};};}//da es sich hier um 8 Kästchen handelt, muss dann bei richtigem Würfel die Variable x den Wert 8 haben
 	
 //da 13 Kästchen richtig sein sollten damit Schritt 1 stimmt, muss x am Ende den Wert 13 haben
  {if(x!=13){return 0;}//wenn dies nicht der Fall sein sollte, ist der Würfel noch nicht zum richtigen Ergebnis gekommen
   else     {return 1;};};}

int move2check(int C[6][3][3],int D[6][3][3])
{int a,b,c,x,y;

 y=0;
 if(move1check(C,D)==1){y=1;};

 a=0;b=0;c=0;x=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=4;b=2;c=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=3;b=0;c=2;
 if(C[a][b][c]==D[a][b][c]){x++;}

 //Hier werden die Farben bei den Kästchen Seite1-Reihe1-Spalte1, Seite4-Reihe1-Spalte3 und Seite5-Reihe3-Spalte1 nachgeprüft
 //da 3 Kästchen richtig sein sollten damit Schritt 2 stimmt, muss x am Ende den Wert 3 haben und y den Wert 1,da die Bedingungen
 // der vorherigen Funktion mit einbezogen werden
  {if((x==3)&&(y==1)){return 1;}
   else {return 0;};};}//wenn dies nicht der Fall sein sollte, ist der Würfel noch nicht zum richtigen Ergebnis gekommen

int move3check(int C[6][3][3],int D[6][3][3])
{int a,b,c,x,y;

 y=0;
 if(move1check(C,D)==1){y++;};
 if(move2check(C,D)==1){y++;};

 a=0;b=0;c=2;x=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=4;b=2;c=2;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=1;b=0;c=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 //Hier werden die Farben bei den Kästchen Seite1-Reihe1-Spalte3, Seite2-Reihe1-Spalte1 und Seite5-Reihe3-Spalte3 nachgeprüft
 //da 3 Kästchen richtig sein sollten damit Schritt 3 stimmt, muss x am Ende den Wert 3 haben und y den Wert 2,da die Bedingungen
 // der vorherigen Funktion mit einbezogen werden
  {if((x==3)&&(y==2)){return 1;}
   else {return 0;};};}//wenn dies nicht der Fall sein sollte, ist der Würfel noch nicht zum richtigen Ergebnis gekommen

int move4check(int C[6][3][3],int D[6][3][3])
{int a,b,c,x,y;

 y=0;
 if(move1check(C,D)==1){y++;};
 if(move2check(C,D)==1){y++;};
 if(move3check(C,D)==1){y++;};
 
 a=1;b=0;c=2;x=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=2;b=0;c=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=4;b=0;c=2;
 if(C[a][b][c]==D[a][b][c]){x++;}

 //Hier werden die Farben bei den Kästchen Seite2-Reihe1-Spalte3, Seite3-Reihe1-Spalte1 und Seite5-Reihe1-Spalte3 nachgeprüft
 //da 3 Kästchen richtig sein sollten damit Schritt 4 stimmt, muss x am Ende den Wert 3 haben und y den Wert 3,da die Bedingungen
 // der vorherigen Funktion mit einbezogen werden
  {if((x==3)&&(y==3)){return 1;}
   else {return 0;};};}//wenn dies nicht der Fall sein sollte, ist der Würfel noch nicht zum richtigen Ergebnis gekommen

int move5check(int C[6][3][3],int D[6][3][3])
{int a,b,c,x,y;

 y=0;
 if(move1check(C,D)==1){y++;};
 if(move2check(C,D)==1){y++;};
 if(move3check(C,D)==1){y++;};
 if(move4check(C,D)==1){y++;};

 a=3;b=0;c=0;x=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=2;b=0;c=2;
 if(C[a][b][c]==D[a][b][c]){x++;}

 a=4;b=0;c=0;
 if(C[a][b][c]==D[a][b][c]){x++;}

 //Hier werden die Farben bei den Kästchen Seite3-Reihe1-Spalte3, Seite4-Reihe1-Spalte1 und Seite5-Reihe1-Spalte1 nachgeprüft
 //da 3 Kästchen richtig sein sollten damit Schritt 5 stimmt, muss x am Ende den Wert 3 haben und y den Wert 4,da die Bedingungen
 // der vorherigen Funktion mit einbezogen werden
  {if((x==3)&&(y==4)){return 1;}
   else {return 0;};};}//wenn dies nicht der Fall sein sollte, ist der Würfel noch nicht zum richtigen Ergebnis gekommen

int move6acheck(int C[6][3][3])
{int a,b,c,x;

x=0;
a=0;b=1;c=0;
if(C[a][b][c]==1){x++;};

a=3;b=1;c=2;
if(C[a][b][c]==4){x++;};
if(x==2){return 1;}
else {return 0;};}
//move6acheck ist für das rechte steinchen der seite 1
int move6bcheck(int C[6][3][3])
{int a,b,c,x;

x=0;
a=0;b=1;c=2;
if(C[a][b][c]==1){x++;};

a=1;b=1;c=0;
if(C[a][b][c]==2){x++;};
if(x==2){return 1;}
else {return 0;};}
//move6bcheck ist für das linke steinchen der seite 1
int move6ccheck(int C[6][3][3])
{int a,b,c,x;

x=0;
a=1;b=1;c=2;
if(C[a][b][c]==2){x++;};

a=2;b=1;c=0;
if(C[a][b][c]==3){x++;};
if(x==2){return 1;}
else {return 0;};}
//move6ccheck ist für das rechte steinchen der seite 3
int move6dcheck(int C[6][3][3])
{int a,b,c,x;

x=0;
a=2;b=1;c=2;
if(C[a][b][c]==3){x++;};

a=3;b=1;c=0;
if(C[a][b][c]==4){x++;};
if(x==2){return 1;}
else {return 0;};}
//move6dcheck ist für das linke steinchen der seite 3


int move6check(int C[6][3][3])
{int n,o,p,q,r,s,t,u;
n=0;o=0;p=0;q=0;r=0;s=0;t=0;u=0;

if(C[0][2][1]==1){n++;};//Seite1-Farbe mit Seite2-Farbe(unten)
if(C[5][0][1]==2){n++;};

if(C[0][2][1]==1){o++;};//Seite1-Farbe mit Seite4-Farbe(unten)
if(C[5][0][1]==4){o++;};

if(C[0][2][1]==2){p++;};//Seite2-Farbe mit Seite3-Farbe(unten)
if(C[5][0][1]==3){p++;};

if(C[0][2][1]==2){q++;};//Seite2-Farbe mit Seite1-Farbe(unten)
if(C[5][0][1]==1){q++;};

if(C[0][2][1]==3){r++;};//Seite3-Farbe mit Seite4-Farbe(unten)
if(C[5][0][1]==4){r++;};

if(C[0][2][1]==3){s++;};//Seite3-Farbe mit Seite2-Farbe(unten)
if(C[5][0][1]==2){s++;};

if(C[0][2][1]==4){t++;};//Seite4-Farbe mit Seite1-Farbe(unten)
if(C[5][0][1]==1){t++;};

if(C[0][2][1]==4){u++;};//Seite4-Farbe mit Seite3-Farbe(unten)
if(C[5][0][1]==3){u++;};

     if(n==2){return 1;}
else if(o==2){return 2;}
else if(p==2){return 3;}
else if(q==2){return 4;}
else if(r==2){return 5;}
else if(s==2){return 6;}
else if(t==2){return 7;}
else if(u==2){return 8;}
else if((n!=2)&&(o!=2)&&(p!=2)&&(q!=2)&&(r!=2)&&(s!=2)&&(t!=2)&&(u!=2)){return 0;};}

int move7check(int A[6][3][3])
{int x;
 x=0;
 
 if(A[5][0][1]==6){x++;};
 if(A[5][1][0]==6){x++;};
 if(A[5][1][2]==6){x++;};
 if(A[5][2][1]==6){x++;};

 if(x==4){return 1;}
 else{return 0;};}

int rueckmove7check(int A[6][3][3])
{int x;
 x=0;
 
 if(A[5][0][1]!=6){x++;};
 if(A[5][1][0]!=6){x++;};
 if(A[5][1][2]!=6){x++;};
 if(A[5][2][1]!=6){x++;};

 if(x==4){return 1;}
 else{return 0;};}

int move8check(int A[6][3][3])
{int x;
 x=0;
 
 if(A[5][0][0]==6){x++;};
 if(A[5][0][2]==6){x++;};
 if(A[5][2][0]==6){x++;};
 if(A[5][2][2]==6){x++;};

 if(x==1){return 1;}
 else if((x==2)||(x==3)){return 2;}
 else if(x==4){return 4;}
 else{return 0;};}

int move9check(int C[6][3][3])
{int a,b,c,d;
a=0;b=0;c=0;d=0;

if(C[1][2][2]==2){a++;};//Kästchen A
if(C[5][2][2]==6){a++;};
if(C[2][2][0]==3){a++;};

if(C[2][2][2]==3){b++;};//Kästchen B
if(C[3][2][0]==4){b++;};
if(C[5][2][0]==6){b++;};

if(C[0][2][2]==1){c++;};//Kästchen C
if(C[1][2][0]==2){c++;};
if(C[5][0][2]==6){c++;};

if(C[0][2][0]==1){d++;};//Kästchen D
if(C[5][0][0]==6){d++;};
if(C[3][2][2]==4){d++;};

      if((a==3)&&(b==3)&&(c!=3)&&(d!=3)){return 12;}//AB
 else if((a==3)&&(b!=3)&&(c==3)&&(d!=3)){return 13;}//AC
 else if((a==3)&&(b!=3)&&(c!=3)&&(d==3)){return 14;}//AD
 else if((a!=3)&&(b==3)&&(c==3)&&(d!=3)){return 23;}//BC
 else if((a!=3)&&(b==3)&&(c!=3)&&(d==3)){return 24;}//BD
 else if((a!=3)&&(b!=0)&&(c==3)&&(d==3)){return 34;}//CD
 else if((a==3)&&(b==3)&&(c==3)&&(d==3)){return 1;}//ABCD
 else{return 0;};}


int move10check(int A[6][3][3])
{int x;
 x=0;
 
 if(A[0][2][1]!=1){x++;};
 if(A[1][2][1]!=2){x++;};
 if(A[2][2][1]!=3){x++;};
 if(A[3][2][1]!=4){x++;};

 if(x==4){return 1;}
 else{return 0;};}


void Wiederherstellen(int E[6][3][3],int F[6][3][3])
{int a,b,c;

     for(a=0;a<=5;a++)
    {for(b=0;b<=2;b++)
    {for(c=0;c<=2;c++)
	{E[a][b][c]=F[a][b][c];};};};}
     
void ZurücksetzungReferenz(int b,int AB[500],int A[6][3][3],int B[6][3][3])
{       if(AB[b-1]==-2){nachobenRechteSpaltedrehung(A);}
   else if(AB[b-1]==-3){nachobenLinkeSpealtedrehung(A);}
   else if(AB[b-1]==-4){untenLinksdrehung(A);}
   else if(AB[b-1]==-5){VordergrundRechtsdrehung(A);}
   else if(AB[b-1]==-6){HintergrundRechtsdrehung(A);}
   else if(AB[b-1]==1){r_obenLinksdrehung(A);} 
	   
   else if(AB[b-1]==2){r_nachobenRechteSpaltedrehung(A);}    
   else if(AB[b-1]==3){r_nachobenLinkeSpealtedrehung(A);}
   else if(AB[b-1]==4){r_untenLinksdrehung(A);}
   else if(AB[b-1]==5){r_VordergrundRechtsdrehung(A);}
   else if(AB[b-1]==6){Wiederherstellen(A,B);};}

void obenLinksdrehung(int A[6][3][3])
{int u,v,w,x,y;

  y=A[0][0][0];
  A[0][0][0]=A[1][0][0];
  A[1][0][0]=A[2][0][0];
  A[2][0][0]=A[3][0][0];
  A[3][0][0]=y;

  u=A[0][0][1];
  A[0][0][1]=A[1][0][1];
  A[1][0][1]=A[2][0][1];
  A[2][0][1]=A[3][0][1];
  A[3][0][1]=u;

  w=A[0][0][2];
  A[0][0][2]=A[1][0][2];
  A[1][0][2]=A[2][0][2];
  A[2][0][2]=A[3][0][2];
  A[3][0][2]=w;

  x=A[4][0][0];
  A[4][0][0]=A[4][2][0];
  A[4][2][0]=A[4][2][2];
  A[4][2][2]=A[4][0][2];
  A[4][0][2]=x;

  v=A[4][0][1];
  A[4][0][1]=A[4][1][0];
  A[4][1][0]=A[4][2][1];
  A[4][2][1]=A[4][1][2];
  A[4][1][2]=v;}

void nachobenRechteSpaltedrehung(int A[6][3][3])
{int u,v,w,x,y;

  y=A[0][0][2];
  A[0][0][2]=A[5][0][2];
  A[5][0][2]=A[2][2][0];
  A[2][2][0]=A[4][0][2];
  A[4][0][2]=y;

  u=A[0][1][2];
  A[0][1][2]=A[5][1][2];
  A[5][1][2]=A[2][1][0];
  A[2][1][0]=A[4][1][2];
  A[4][1][2]=u;

  w=A[0][2][2];
  A[0][2][2]=A[5][2][2];
  A[5][2][2]=A[2][0][0];
  A[2][0][0]=A[4][2][2];
  A[4][2][2]=w;

  x=A[1][0][0];
  A[1][0][0]=A[1][2][0];
  A[1][2][0]=A[1][2][2];
  A[1][2][2]=A[1][0][2];
  A[1][0][2]=x;

  v=A[1][0][1];
  A[1][0][1]=A[1][1][0];
  A[1][1][0]=A[1][2][1];
  A[1][2][1]=A[1][1][2];
  A[1][1][2]=v;}

void nachobenLinkeSpealtedrehung(int A[6][3][3])
{int u,v,w,x,y;

  y=A[0][0][0];
  A[0][0][0]=A[5][0][0];
  A[5][0][0]=A[2][2][2];
  A[2][2][2]=A[4][0][0];
  A[4][0][0]=y;

  u=A[0][1][0];
  A[0][1][0]=A[5][1][0];
  A[5][1][0]=A[2][1][2];
  A[2][1][2]=A[4][1][0];
  A[4][1][0]=u;
  
  w=A[0][2][0];
  A[0][2][0]=A[5][2][0];
  A[5][2][0]=A[2][0][2];
  A[2][0][2]=A[4][2][0];
  A[4][2][0]=w;

  x=A[3][0][0];
  A[3][0][0]=A[3][0][2];
  A[3][0][2]=A[3][2][2];
  A[3][2][2]=A[3][2][0];
  A[3][2][0]=x;

  v=A[3][0][1];
  A[3][0][1]=A[3][1][2];
  A[3][1][2]=A[3][2][1];
  A[3][2][1]=A[3][1][0];
  A[3][1][0]=v;}

void untenLinksdrehung(int A[6][3][3])
{int u,v,w,x,y;

  y=A[0][2][0];
  A[0][2][0]=A[1][2][0];
  A[1][2][0]=A[2][2][0];
  A[2][2][0]=A[3][2][0];
  A[3][2][0]=y;

  u=A[0][2][1];
  A[0][2][1]=A[1][2][1];
  A[1][2][1]=A[2][2][1];
  A[2][2][1]=A[3][2][1];
  A[3][2][1]=u;

  w=A[0][2][2];
  A[0][2][2]=A[1][2][2];
  A[1][2][2]=A[2][2][2];
  A[2][2][2]=A[3][2][2];
  A[3][2][2]=w;

  x=A[5][0][0];
  A[5][0][0]=A[5][0][2];
  A[5][0][2]=A[5][2][2];
  A[5][2][2]=A[5][2][0];
  A[5][2][0]=x;

  v=A[5][0][1];
  A[5][0][1]=A[5][1][2];
  A[5][1][2]=A[5][2][1];
  A[5][2][1]=A[5][1][0];
  A[5][1][0]=v;}

void VordergrundRechtsdrehung(int A[6][3][3])
{int u,v,w,x,y;

  y=A[4][2][0];
  A[4][2][0]=A[3][2][2];
  A[3][2][2]=A[5][0][2];
  A[5][0][2]=A[1][0][0];
  A[1][0][0]=y;

  u=A[4][2][1];
  A[4][2][1]=A[3][1][2];
  A[3][1][2]=A[5][0][1];
  A[5][0][1]=A[1][1][0];
  A[1][1][0]=u;

  w=A[4][2][2];
  A[4][2][2]=A[3][0][2];
  A[3][0][2]=A[5][0][0];
  A[5][0][0]=A[1][2][0];
  A[1][2][0]=w;

  x=A[0][0][0];
  A[0][0][0]=A[0][2][0];
  A[0][2][0]=A[0][2][2];
  A[0][2][2]=A[0][0][2];
  A[0][0][2]=x;

  v=A[0][0][1];
  A[0][0][1]=A[0][1][0];
  A[0][1][0]=A[0][2][1];
  A[0][2][1]=A[0][1][2];
  A[0][1][2]=v;}

void HintergrundRechtsdrehung(int A[6][3][3])
{int u,v,w,x,y;

  y=A[4][0][0];
  A[4][0][0]=A[3][2][0];
  A[3][2][0]=A[5][2][2];
  A[5][2][2]=A[1][0][2];
  A[1][0][2]=y;

  u=A[4][0][1];
  A[4][0][1]=A[3][1][0];
  A[3][1][0]=A[5][2][1];
  A[5][2][1]=A[1][1][2];
  A[1][1][2]=u;

  w=A[4][0][2];
  A[4][0][2]=A[3][0][0];
  A[3][0][0]=A[5][2][0];
  A[5][2][0]=A[1][2][2];
  A[1][2][2]=w;

  x=A[2][0][0];
  A[2][0][0]=A[2][0][2];
  A[2][0][2]=A[2][2][2];
  A[2][2][2]=A[2][2][0];
  A[2][2][0]=x;

  v=A[2][0][1];
  A[2][0][1]=A[2][1][2];
  A[2][1][2]=A[2][2][1];
  A[2][2][1]=A[2][1][0];
  A[2][1][0]=v;}

void Mittedrehung(int A[6][3][3])//nach links
{int u,v,w;

  v=A[0][1][0];
  A[0][1][0]=A[1][1][0];
  A[1][1][0]=A[2][1][0];
  A[2][1][0]=A[3][1][0];
  A[3][1][0]=v;

  u=A[0][1][1];
  A[0][1][1]=A[1][1][1];
  A[1][1][1]=A[2][1][1];
  A[2][1][1]=A[3][1][1];
  A[3][1][1]=u;

  w=A[0][1][2];
  A[0][1][2]=A[1][1][2];
  A[1][1][2]=A[2][1][2];
  A[2][1][2]=A[3][1][2];
  A[3][1][2]=w;}

void MittlereSpaltedrehung(int A[6][3][3])//nach unten
{int u,v,w;

  v=A[0][0][1];
  A[0][0][1]=A[4][0][1];
  A[4][0][1]=A[2][2][1];
  A[2][2][1]=A[5][0][1];
  A[5][0][1]=v;

  u=A[0][1][1];
  A[0][1][1]=A[4][1][1];
  A[4][1][1]=A[2][1][1];
  A[2][1][1]=A[5][1][1];
  A[5][1][1]=u;

  w=A[0][2][1];
  A[0][2][1]=A[4][2][1];
  A[4][2][1]=A[2][0][1];
  A[2][0][1]=A[5][2][1];
  A[5][2][1]=w;}
//-----------------------------------------------------------------------------Ab jetzt Gegendrehungen
void r_obenLinksdrehung(int A[6][3][3])
{   obenLinksdrehung(A);
    obenLinksdrehung(A);
	obenLinksdrehung(A);}

void r_nachobenRechteSpaltedrehung(int A[6][3][3])
{   nachobenRechteSpaltedrehung(A);
    nachobenRechteSpaltedrehung(A);
	nachobenRechteSpaltedrehung(A);}

void r_nachobenLinkeSpealtedrehung(int A[6][3][3])
{   nachobenLinkeSpealtedrehung(A);
    nachobenLinkeSpealtedrehung(A);
	nachobenLinkeSpealtedrehung(A);}

void r_untenLinksdrehung(int A[6][3][3])
{   untenLinksdrehung(A);
    untenLinksdrehung(A);
	untenLinksdrehung(A);}

void r_VordergrundRechtsdrehung(int A[6][3][3])
{    VordergrundRechtsdrehung(A);
     VordergrundRechtsdrehung(A);
	 VordergrundRechtsdrehung(A);}
void r_HintergrundRechtsdrehung(int A[6][3][3])
{    HintergrundRechtsdrehung(A);
     HintergrundRechtsdrehung(A);	
	 HintergrundRechtsdrehung(A);}

//--------------------------------------------------------------------------------------Motive zum Lösen des 3.Schrittes
void motiv1(int A[6][3][3])//zum Lösen des 3.Schrittes
{untenLinksdrehung(A);
 r_nachobenRechteSpaltedrehung(A);
 r_untenLinksdrehung(A);
 nachobenRechteSpaltedrehung(A);
 r_untenLinksdrehung(A);
 VordergrundRechtsdrehung(A);
 untenLinksdrehung(A);
 r_VordergrundRechtsdrehung(A);}

void motiv2(int A[6][3][3])//zum Lösen des 3.Schrittes
{r_untenLinksdrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 untenLinksdrehung(A);
 nachobenLinkeSpealtedrehung(A);
 untenLinksdrehung(A);
 r_VordergrundRechtsdrehung(A);
 r_untenLinksdrehung(A);
 VordergrundRechtsdrehung(A);}

void Rueckmotiv1(int A[6][3][3])//zum Lösen des 3.Schrittes
{VordergrundRechtsdrehung(A);
 r_untenLinksdrehung(A);
 r_VordergrundRechtsdrehung(A);
 untenLinksdrehung(A);
 r_nachobenRechteSpaltedrehung(A);
 untenLinksdrehung(A);
 nachobenRechteSpaltedrehung(A);
 r_untenLinksdrehung(A);}

void Rueckmotiv2(int A[6][3][3])//zum Lösen des 3.Schrittes
{r_VordergrundRechtsdrehung(A);
 untenLinksdrehung(A);
 VordergrundRechtsdrehung(A);
 r_untenLinksdrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 r_untenLinksdrehung(A);
 nachobenLinkeSpealtedrehung(A);
 untenLinksdrehung(A);}

//--------------------------------------------------------------------------------------Motive zum Lösen des 4.Schrittes
void Schritt4Motiv1(int A[6][3][3])
{VordergrundRechtsdrehung(A);
 r_untenLinksdrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 untenLinksdrehung(A);
 nachobenLinkeSpealtedrehung(A);
 r_VordergrundRechtsdrehung(A);}

void Schritt4Motiv2(int A[6][3][3])
{VordergrundRechtsdrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 r_untenLinksdrehung(A);
 nachobenLinkeSpealtedrehung(A);
 untenLinksdrehung(A);
 r_VordergrundRechtsdrehung(A);}

//--------------------------------------------------------------------------------------Motiv zum Lösen des 5.Schrittes
void Schritt5Motiv(int A[6][3][3])
{r_nachobenLinkeSpealtedrehung(A);
 r_untenLinksdrehung(A);
 nachobenLinkeSpealtedrehung(A);
 r_untenLinksdrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 r_untenLinksdrehung(A);
 r_untenLinksdrehung(A);
 nachobenLinkeSpealtedrehung(A);}

//--------------------------------------------------------------------------------------Motiv zum Lösen des 6.Schrittes
void Schritt6Motiv(int A[6][3][3])
{nachobenLinkeSpealtedrehung(A);
 VordergrundRechtsdrehung(A);
 nachobenLinkeSpealtedrehung(A);
 r_HintergrundRechtsdrehung(A);
 r_HintergrundRechtsdrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 r_VordergrundRechtsdrehung(A);
 nachobenLinkeSpealtedrehung(A);
 r_HintergrundRechtsdrehung(A);
 r_HintergrundRechtsdrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 untenLinksdrehung(A);
}

//--------------------------------------------------------------------------------------Motiv zum Lösen des 7.Schrittes
void Schritt7Motiv1(int A[6][3][3])
{VordergrundRechtsdrehung(A);
 VordergrundRechtsdrehung(A);
 r_untenLinksdrehung(A);
 nachobenRechteSpaltedrehung(A);
 nachobenLinkeSpealtedrehung(A);
 VordergrundRechtsdrehung(A);
 VordergrundRechtsdrehung(A);
 r_nachobenRechteSpaltedrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 r_untenLinksdrehung(A);
 VordergrundRechtsdrehung(A);
 VordergrundRechtsdrehung(A);}

void Schritt7Motiv2(int A[6][3][3])
{VordergrundRechtsdrehung(A);
 VordergrundRechtsdrehung(A);
 untenLinksdrehung(A);
 nachobenRechteSpaltedrehung(A);
 nachobenLinkeSpealtedrehung(A);
 VordergrundRechtsdrehung(A);
 VordergrundRechtsdrehung(A);
 r_nachobenRechteSpaltedrehung(A);
 r_nachobenLinkeSpealtedrehung(A);
 untenLinksdrehung(A);
 VordergrundRechtsdrehung(A);
 VordergrundRechtsdrehung(A);}

void Cubedrehung(int A[6][3][3])
{Mittedrehung(A);//nach links
untenLinksdrehung(A);
obenLinksdrehung(A);}

void Arraymanipulation(int A[500],int B[500])
{//Schritt 3:
 int a;
 int Nullstelle;
 Nullstelle=0;
 for(a=1;a<=500;a++){

      if((B[a-1]==-1)||(B[a-1]==-2)||(B[a-1]==-3)||(B[a-1]==-4)||(B[a-1]==-5)||(B[a-1]==-6)||(B[a-1]==1)||(B[a-1]==2)||(B[a-1]==3)||(B[a-1]==4)||(B[a-1]==5)||(B[a-1]==6)){A[Nullstelle]=B[a-1];Nullstelle++;}
 
 else if(B[a-1]==21){Nullstelle=Motive(1,Nullstelle,A);}

 else if(B[a-1]==22){Nullstelle=Motive(2,Nullstelle,A);}
 //- - - - - - - - - - - - - - - - - - - - - 
 else if(B[a-1]==23){A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=7;Nullstelle++;Nullstelle=Motive(1,Nullstelle,A);
								A[Nullstelle]=-7;Nullstelle++;}

 else if(B[a-1]==24){A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=7;Nullstelle++;Nullstelle=Motive(2,Nullstelle,A);
								A[Nullstelle]=-7;Nullstelle++;}
  //- - - - - - - - - - - - - - - - - - - - - 
 else if(B[a-1]==25){A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=-4;Nullstelle++;
                              A[Nullstelle]=7;Nullstelle++;A[Nullstelle]=7;Nullstelle++;
         Nullstelle=Motive(1,Nullstelle,A);
                              A[Nullstelle]=-7;Nullstelle++;A[Nullstelle]=-7;Nullstelle++;}

 else if(B[a-1]==26){A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=-4;Nullstelle++;
                              A[Nullstelle]=7;Nullstelle++;A[Nullstelle]=7;Nullstelle++;
         Nullstelle=Motive(2,Nullstelle,A);
                              A[Nullstelle]=-7;Nullstelle++;A[Nullstelle]=-7;Nullstelle++;}
 //- - - - - - - - - - - - - - - - - - - - - 
 else if(B[a-1]==27){A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=-4;Nullstelle++;
                              A[Nullstelle]=-7;Nullstelle++;
         Nullstelle=Motive(1,Nullstelle,A);
                              A[Nullstelle]=7;Nullstelle++;}

 else if(B[a-1]==28){A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=-4;Nullstelle++;A[Nullstelle]=-4;Nullstelle++;
                              A[Nullstelle]=-7;Nullstelle++;
         Nullstelle=Motive(2,Nullstelle,A);
                              A[Nullstelle]=7;Nullstelle++;}

//---------------------------------------------------------------------------------------------Rückmotive
 else if(B[a-1]==29){Nullstelle=Motive(3,Nullstelle,A);}

 else if(B[a-1]==210){Nullstelle=Motive(4,Nullstelle,A);}
 //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

 else if(B[a-1]==211){A[Nullstelle]=7;Nullstelle++;A[Nullstelle]=7;Nullstelle++;
                               Nullstelle=Motive(3,Nullstelle,A);
                               A[Nullstelle]=-7;Nullstelle++;A[Nullstelle]=-7;Nullstelle++;}

 else if(B[a-1]==212){A[Nullstelle]=7;Nullstelle++;A[Nullstelle]=7;Nullstelle++;
                            Nullstelle=Motive(4,Nullstelle,A);
							A[Nullstelle]=-7;Nullstelle++;A[Nullstelle]=-7;Nullstelle++;}

 //---------------------------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------------------------
 //Schritt 4:
 else if(B[a-1]==31){Nullstelle=Motive(5,Nullstelle,A);}

 else if(B[a-1]==32){Nullstelle=Motive(5,Nullstelle,A);}

 else if(B[a-1]==33){A[Nullstelle]=4;Nullstelle++;Nullstelle=Motive(5,Nullstelle,A);}

 else if(B[a-1]==34){A[Nullstelle]=4;Nullstelle++;A[Nullstelle]=4;Nullstelle++;Nullstelle=Motive(5,Nullstelle,A);}

 else if(B[a-1]==35){A[Nullstelle]=-4;Nullstelle++;Nullstelle=Motive(5,Nullstelle,A);}

 else if(B[a-1]==36){Nullstelle=Motive(6,Nullstelle,A);}

 else if(B[a-1]==37){A[Nullstelle]=4;Nullstelle++;Nullstelle=Motive(6,Nullstelle,A);}

 //---------------------------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------------------------
 //Schritt 5:

 else if((B[a-1]==51)||(B[a-1]==55)||(B[a-1]==59)){Nullstelle=Motive(7,Nullstelle,A);}

 else if((B[a-1]==52)||(B[a-1]==56)||(B[a-1]==510)){A[Nullstelle]=4;Nullstelle++;Nullstelle=Motive(7,Nullstelle,A);}

 else if((B[a-1]==53)||(B[a-1]==57)||(B[a-1]==511)){A[Nullstelle]=4;Nullstelle++;A[Nullstelle]=4;Nullstelle++;Nullstelle=Motive(7,Nullstelle,A);}

 else if((B[a-1]==54)||(B[a-1]==58)||(B[a-1]==512)){A[Nullstelle]=-4;Nullstelle++;Nullstelle=Motive(7,Nullstelle,A);}

 //---------------------------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------------------------
 //Schritt 6:
 else if((B[a-1]==61)||(B[a-1]==62)){Nullstelle=Motive(8,Nullstelle,A);}

 else if(B[a-1]==63){A[Nullstelle]=-7;Nullstelle++;Nullstelle=Motive(8,Nullstelle,A);A[Nullstelle]=7;Nullstelle++;}

 else if(B[a-1]==64){A[Nullstelle]=7;Nullstelle++;Nullstelle=Motive(8,Nullstelle,A);A[Nullstelle]=-7;Nullstelle++;}

 else if(B[a-1]==65){A[Nullstelle]=7;Nullstelle++;A[Nullstelle]=7;Nullstelle++;
                                                       Nullstelle=Motive(8,Nullstelle,A);
                A[Nullstelle]=-7;Nullstelle++;A[Nullstelle]=-7;Nullstelle++;}

 else if(B[a-1]==66){A[Nullstelle]=4;Nullstelle++;}

 //---------------------------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------------------------
 //Schritt 7:
 else if((B[a-1]==71)||(B[a-1]==72)){Nullstelle=Motive(9,Nullstelle,A);}

 else if(B[a-1]==73){A[Nullstelle]=-7;Nullstelle++;Nullstelle=Motive(9,Nullstelle,A);A[Nullstelle]=7;Nullstelle++;}

 else if(B[a-1]==74){A[Nullstelle]=7;Nullstelle++;A[Nullstelle]=7;Nullstelle++;
                              Nullstelle=Motive(9,Nullstelle,A);
							  A[Nullstelle]=-7;Nullstelle++;A[Nullstelle]=-7;Nullstelle++;}

 else if(B[a-1]==75){A[Nullstelle]=7;Nullstelle++;Nullstelle=Motive(9,Nullstelle,A);A[Nullstelle]=-7;Nullstelle++;}

 //- - - - - - - - - - - - - - - - - - - - - - - 
 else if(B[a-1]==76){Nullstelle=Motive(10,Nullstelle,A);}

 else if(B[a-1]==77){A[Nullstelle]=-7;Nullstelle++;Nullstelle=Motive(10,Nullstelle,A);A[Nullstelle]=7;Nullstelle++;}

 else if(B[a-1]==78){A[Nullstelle]=7;Nullstelle++;A[Nullstelle]=7;Nullstelle++;
                              Nullstelle=Motive(10,Nullstelle,A);
							  A[Nullstelle]=-7;Nullstelle++;A[Nullstelle]=-7;Nullstelle++;}

 else if(B[a-1]==79){A[Nullstelle]=7;Nullstelle++;Nullstelle=Motive(10,Nullstelle,A);A[Nullstelle]=-7;Nullstelle++;}
 };}

int Motive(int a,int Nullstelle,int A[500])
{int M1S3[8],M2S3[8];
 int RM1S3[8],RM2S3[8];
 int M1S4[6],M2S4[6];
 int MS5[8];
 int MS6[13];
 int M1S7[12],M2S7[12];
 int x;
 
 M1S3[0]=4;M1S3[1]=-2;M1S3[2]=-4;M1S3[3]=2;M1S3[4]=-4;M1S3[5]=5;M1S3[6]=4;M1S3[7]=-5;
 M2S3[0]=-4;M2S3[1]=-3;M2S3[2]=4;M2S3[3]=3;M2S3[4]=4;M2S3[5]=-5;M2S3[6]=-4;M2S3[7]=5;

 RM1S3[0]=5;RM1S3[1]=-4;RM1S3[2]=-5;RM1S3[3]=4;RM1S3[4]=-2;RM1S3[5]=4;RM1S3[6]=2;RM1S3[7]=-4;

 RM2S3[0]=-5;RM2S3[1]=4;RM2S3[2]=5;RM2S3[3]=-4;RM2S3[4]=-3;RM2S3[5]=-4;RM2S3[6]=3;RM2S3[7]=4;

 M1S4[0]=5;M1S4[1]=-4;M1S4[2]=-3;M1S4[3]=4;M1S4[4]=3;M1S4[5]=-5;
 M2S4[0]=5;M2S4[1]=-3;M2S4[2]=-4;M2S4[3]=3;M2S4[4]=4;M2S4[5]=-5;

 MS5[0]=-3;MS5[1]=-4;MS5[2]=3;MS5[3]=-4;MS5[4]=-3;MS5[5]=-4;MS5[6]=-4;MS5[7]=3;

 MS6[0]=3;MS6[1]=5;MS6[2]=3;MS6[3]=-6;MS6[4]=-6;MS6[5]=-3;MS6[6]=-5;MS6[7]=3;MS6[8]=-6;MS6[9]=-6;MS6[10]=-3;MS6[11]=-3;MS6[12]=4;

 M1S7[0]=5; M1S7[1]=5; M1S7[2]=-4; M1S7[3]=2; M1S7[4]=3; M1S7[5]=5; M1S7[6]=5; M1S7[7]=-2; M1S7[8]=-3; M1S7[9]=-4; M1S7[10]=5; M1S7[11]=5;

 M2S7[0]=5; M2S7[1]=5; M2S7[2]=4; M2S7[3]=2; M2S7[4]=3; M2S7[5]=5; M2S7[6]=5; M2S7[7]=-2; M2S7[8]=-3; M2S7[9]=4; M2S7[10]=5; M2S7[11]=5;   

      if(a==1){for(x=0;x<=7;x++){A[Nullstelle]=M1S3[x];Nullstelle++;};}
 else if(a==2){for(x=0;x<=7;x++){A[Nullstelle]=M2S3[x];Nullstelle++;};}

 else if(a==3){for(x=0;x<=7;x++){A[Nullstelle]=RM1S3[x];Nullstelle++;};}
 else if(a==4){for(x=0;x<=7;x++){A[Nullstelle]=RM2S3[x];Nullstelle++;};}

 else if(a==5){for(x=0;x<=5;x++){A[Nullstelle]=M1S4[x];Nullstelle++;};}
 else if(a==6){for(x=0;x<=5;x++){A[Nullstelle]=M2S4[x];Nullstelle++;};}

 else if(a==7){for(x=0;x<=7;x++){A[Nullstelle]=MS5[x];Nullstelle++;};}

 else if(a==8){for(x=0;x<=12;x++){A[Nullstelle]=MS6[x];Nullstelle++;};}

 else if(a==9){for(x=0;x<=11;x++){A[Nullstelle]=M1S7[x];Nullstelle++;};}
 else if(a==10){for(x=0;x<=11;x++){A[Nullstelle]=M2S7[x];Nullstelle++;};};
 return Nullstelle;}

std::string Int2Str(int number)
{
	std::stringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}










