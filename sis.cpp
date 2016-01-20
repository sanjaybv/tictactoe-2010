#include<fstream.h>
#include<process.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>

const int n=1;          // Specify no of levels with n,but give one level more.
			// for example, if you want 20 levels, give n=21.
int win,kr;
int r[n+1],a[n+1];      // Array r stores the numbers generated in the game
			// and array a stores the values entered by
			// user to check if they are correct or wrong.
void begin();           // Func. for displaying the intro page
void instr();           // Func. to display Instructions screen
void game();            // Main game func. where numbers are generated
			// and sent for operations. User-entered values
			// are checked here and the game progress
			// is maintained.
void wrong(int j);      // Function for displaying that the values entered			// are wrong.
void correct(int j);    // Func. to display that the user-entered values
			// are correct and to indicate the number of
			// levels left. An exit provision is also given.
			// Parameter j (always indicative of the no of levels)
			// is passed to find out the level
			// and display the no of levels left.
void print();           // Func. to print the bubbles that are lighted up
void fill(int i);       // Func. that fills bubbles with yellow colour
			// to highlight the generated numbers. The no
			// of bubbles filled is always equal to the
			// number of levels+2. Random numbers are
			// generated and stored in array r for
			// further checking.
void hs(int l);

struct highscore
{
 char name[50];
 int score;
};

void main()
{
 int gdriver=DETECT,gmode,errorcode;
 initgraph(&gdriver,&gmode,"");

 errorcode=graphresult();
 if (errorcode != grOk)
 {
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
 }
 begin();
 closegraph();
}

void print()
{
 setcolor(0);
 settextstyle(1,0,2);
 setfillstyle(1,15);
 fillellipse(75,100,50,50);
 outtextxy(70,90,"1");
 fillellipse(175,180,50,50);
 outtextxy(170,170,"2");
 fillellipse(275,100,50,50);
 outtextxy(270,90,"3");
 fillellipse(375,180,50,50);
 outtextxy(370,170,"4");
 fillellipse(475,100,50,50);
 outtextxy(470,90,"5");
 fillellipse(575,180,50,50);
 outtextxy(570,170,"6");
}

void fill(int i)
{
 print();
 setcolor(14);
 setfillstyle(1,14);
 settextstyle(1,0,2);
 r[i]=random(6)+1;
 setcolor(0);
 delay(500);
 switch(r[i])
 {
  case 1:
   fillellipse(75,100,50,50);
   outtextxy(70,90,"1");
   break;

  case 2:
   fillellipse(175,180,50,50);
   outtextxy(170,170,"2");
   break;

  case 3:
   fillellipse(275,100,50,50);
   outtextxy(270,90,"3");
   break;

  case 4:
   fillellipse(375,180,50,50);
   outtextxy(370,170,"4");
   break;

  case 5:
   fillellipse(475,100,50,50);
   outtextxy(470,90,"5");
   break;

  case 6:
   fillellipse(575,180,50,50);
   outtextxy(570,170,"6");
   break;
 }
 delay(700);
 print();
}

void wrong(int j)
{
 cleardevice();
 setcolor(4);
 settextstyle(9,0,1);
 outtextxy(20,240,"Incorrect. You Lose! Play from the start!");
 getch();
 hs(j);
}

void correct(int j)
{
 cleardevice();
 int no; char s[5],nm[5],ch;
 setcolor(2);
 settextstyle(9,0,1);
 outtextxy(40,240,"Absolutely! You progress on to level");
 itoa(j,s,10);
 randomize();
 setcolor(random(15)+1);
 settextstyle(1,0,6);
 outtextxy(320,300,s);
 setcolor(15);
 settextstyle(1,0,2);
 outtextxy(10,400,"Press Any Key to Continue. You have");
 no=n-j;
 itoa(no,nm,10);
 outtextxy(410,400,nm);
 outtextxy(450,400,"more levels to go.");
 outtextxy(10,440,"Press X to exit");
 ch=getch();
 if(ch=='X' || ch=='x')
  begin();
 cleardevice();
}

void begin()
{
 char a;
 cleardevice();
 setbkcolor(0);
 settextstyle(10,0,6);
 setcolor(5);
 outtextxy(80,0,"SIMON SAYS");
 setcolor(15);
 fillellipse(250,200,20,15);
 fillellipse(350,200,20,15);
 setcolor(0);
 setfillstyle(0,0);
 fillellipse(250,200,10,10);
 fillellipse(350,200,10,10);
 setcolor(15);
 settextstyle(1,0,4);
 outtextxy(300,250,"!");
 for(int i=180;i<=360;i++)
 {
  arc(300,300,180,i,40);
  delay(20);
 }
 setcolor(12);
 outtextxy(0,350,"A.Start Game");
 outtextxy(0,390,"B.Instructions");
 outtextxy(0,430,"C.Exit");
 a=getch();
 if(a=='A' || a=='a')
  game();
 else if(a=='B' || a=='b')
  instr();
 else if(a=='C' || 'c')
  exit(0);
}

void game()
{
 cleardevice();
 settextstyle(1,0,7);
 setcolor(1);
 outtextxy(250,240,"0th Level");
 delay(1000);
 cleardevice();
 randomize();
 delay(1500);
 for(int j=0;j<=n;j++)
 {
  for(int i=0;i<=j+1;i++)
  {
   fill(i);
   delay(400);
  }
  cleardevice();
  setcolor(15);
  settextstyle(1,0,2);
  outtextxy(0,0,"Enter the exact combination of numbers one by one.");
  for(int k=0;k<=j+1;k++)
  {
   a[k]=getch()-48;
  }
  for(k=0;k<=j+1;k++)
   if(a[k]!=r[k])
   {
    wrong(j);
   }
  if(j==n-1)
  {
   for(win=0;win<15;win++)        //Win Flash
   {
    setbkcolor(0);
    setcolor(win);
    settextstyle(6,0,2);
    cleardevice();
    for(kr=0;kr<20;kr++)
     outtextxy(random(600),random(450),"*");
    if(kbhit())
     goto lb1;
    setcolor(6);
    settextstyle(6,0,6);
    outtextxy(25,25,"You Win!!!");
    if(win==14)
     win=0;
    delay(100);
   }
   lb1:
   getch();
   hs(n-1);
   break;
  }
  correct(j+1);
 }
}


void instr()
{
 char a;
 cleardevice();
 settextstyle(1,0,4);
 setcolor(15);
 outtextxy(230,0,"Instructions");
 settextstyle(1,0,2);
 outtextxy(0,70,"Six Bubbles appear on the screen.");
 outtextxy(0,120,"Each Bubble has an indicated number.");
 outtextxy(0,170,"In each level, the bubbles flash combinations of numbers.");
 outtextxy(0,220,"You will have to remember the combination and");
 outtextxy(0,250,"enter it correctly to progress to the next level");
 outtextxy(0,300,"There are 20 levels in the game starting from the 0th level.");
 outtextxy(0,350,"Try to even reach the last level in this game to win!");
 settextstyle(2,0,6);
 setcolor(10);
 outtextxy(0,420,"Press any key to start the game or Press X to exit");
 a=getch();
 if(a=='x' || a=='X')
  exit(0);
 else
 {
  cleardevice();
  game();
 }
}

void hs(int l)
{
 setbkcolor(0);
 char s;
 int i,j,tempscore,tempno;
 char empty[]={"empty"};
 fstream fi("i55.txt",ios::in);
 highscore h[11];
 j=0;
 cleardevice();
 setcolor(12);
 settextstyle(2,0,6);
 outtextxy(40,200,"Do you want your name to be displayed in the high scores?");
 outtextxy(250,230,"Press Y or N");
 s=getch();
 if(s=='n' || s=='N')
  begin();
 if(s=='y' || s=='Y')
 {
  char a[80];
  restorecrtmode();
  while (fi)
  {                               // read file and increment j
   fi.getline(h[j].name,50);
   fi.getline(a,80);
   h[j].score=atoi(a);
   j++;                           // if there is something, j becomes 1
  }
  if (j==0)
  {
   for (i=0;i<10;i++)             // if no first entry is located,
   {                              // let name and score of first 10 entries
    strcpy(h[i].name,empty);      // be empty and zero resp.
    h[i].score=0;
   }
  }
  fi.close();                // close file for reading
  cout<<"Please enter your name\n";
  cin.getline(h[10].name,50);
  h[10].score=l;             // get name and score for 10th entry
  tempscore=0;
  for (i=0;i<10;i++)
  {
   tempscore=0;
   for (j=i;j<11;j++)        // when i=10,j=10
   {
    if (h[j].score>=tempscore) //tempscore becomes 10th score
    {                          // tempno=10
     tempscore=h[j].score;
     tempno=j;
    }
   }
   char name[50];              // sorting high names and high scores
   int p;
   p=h[i].score;
   h[i].score=h[tempno].score;
   h[tempno].score=p;
   strcpy(name,h[i].name);
   strcpy(h[i].name,h[tempno].name);
   strcpy(h[tempno].name,name);
  }
  fstream fn("i55.txt",ios::out);
  for (i=0;i<10;i++)
  {
   fn<<h[i].name<<endl<<h[i].score<<endl;
   cout<<h[i].name<<"\t\t\t\t"<<h[i].score<<"\n";
  }
  fn.close();
 }
 cout<<"Thank you for using 'Simon Says'!";
 cout<<"\nPlease go to the Achievers List to see your name listed.";
 getch();
 setgraphmode(getgraphmode());
 begin();
}
