using namespace std;
void rodytiTaisykles();
void naujasZaidejas(zaidejas *&pradzia, zaidejas *&galas,zaidejas *&naujas);
void prisijungimas();





void showMenu(){
    zaidejas *galas, *pradzia,*naujas;

int p;
system("cls");
system("color a9");
        gotoxy(3,3);
        cout<<"BOMBU ZAIDIMAS";
        gotoxy(3,4);
        cout<<"================";
        gotoxy(3,5);
cout<<"(1) NAUJAS ZAIDEJAS"<<endl;
gotoxy(3,6);
cout<<"(2) PRADETI"<<endl;
gotoxy(3,7);
cout<<"(3) TAISYKLES"<<endl;
gotoxy(3,8);
cout<<"(4) REITINGAS"<<endl;
gotoxy(3,9);
cout<<"(5) ISEITI"<<endl;
cin>>p;

switch(p){
case 1:
    naujasZaidejas(pradzia, galas,naujas);
    break;

case 2: prisijungimas();
break;

case 3: rodytiTaisykles();
break;

case 4:

case 5: break;




}
}



