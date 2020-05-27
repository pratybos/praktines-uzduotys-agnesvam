
using namespace std;

struct zaidejas{
string vardas;
int gyvybiuSk;
int taskusSk;
int nugaletiSk;
struct zaidejas *next;
};


void showMenu();


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



void rodytiTaisykles(){
string name;
int g=3;
system("cls");
system("color a9");
ifstream dataFile("taisykles.txt");
    while (!dataFile.fail() && !dataFile.eof() )
    {
          dataFile >> name ;
           gotoxy(3,g);
          cout << name << endl;
          g++;
    }
cout<<endl;
int atgal;
cout<< "< Atgal (enter)";
atgal=getch();
            if(atgal){
            showMenu();}
        }


void naujasZaidejas(zaidejas *&pradzia, zaidejas *&galas,zaidejas *&naujas){
 system("cls");
 system("color a9");
 gotoxy(3,3);

 //zaidejas *naujas;
 naujas= new zaidejas();

 cout<<"IVESKITE NAUJO ZAIDEJO VARDA"<<endl;
  gotoxy(3,4);
cin>>naujas->vardas;
naujas->gyvybiuSk=5;
naujas->taskusSk=100;
naujas->nugaletiSk=0;
naujas->next=NULL;

if(pradzia==NULL){
    pradzia=naujas;
    galas=naujas;
    naujas=NULL;
}
  else{
    galas->next=naujas;
    galas=naujas;


  }


//irasome i registruotu zaideju sarasa
ofstream d;
d.open("registruotiZaidejai.txt", ios::app);
d<<naujas->vardas<<" ";
d<<naujas->gyvybiuSk<<" ";
d<<naujas->taskusSk<<" ";
d<<naujas->nugaletiSk;
d<<endl;
d.close();



system("cls");
 system("color a9");
 gotoxy(3,3);
cout<<"JUSU NAUJAS ZAIDEJAS SUKURTAS!";
Sleep(1500);
showMenu();


}

void prisijungimas(){/*
system("cls");
system("color a9");
string id;
gotoxy(3,3);
cout<<"Iveskite savo vartotojo vardas: "<<endl;
cin>>id;
cout<<endl;
int registruotuSk=(sizeof(struct zaidejas)/16);
//paziurim ar toks egzistuoja zaidejas
for(int i=0; i<=registruotuSk;i++){
    if(id==zaidejas[i].vardas){
        cout<<"sveiki prisijunge";


    }

*/

}








void updateBoards();
void printBoards();
void showReitingas();
void parduotuve();
void zaidejoInfo();
void endGame();
void reset();
