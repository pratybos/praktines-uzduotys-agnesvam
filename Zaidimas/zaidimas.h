
using namespace std;
void reitingas(int zaidejoNR);
void showMenu();
void pagrindinis(int zaidejoNR);
void game(int zaidejoNR);
void game2(int zaidejoNR);
void reitTaskai(int zaidejoNR);
void reitNugaleti(int zaidejoNR);



struct zaidejas{
string vardas;
int gyvybiuSk;
int taskusSk;
int nugaletiSk;
};
zaidejas zaidejai[100];

int zaidejoNR;
int size;

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
system("color b5");
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

void naujasZaidejas(){
 system("cls");
 system("color b5");
 gotoxy(3,3);
zaidejas *naujas;
naujas=new zaidejas;


 cout<<"IVESKITE NAUJO ZAIDEJO VARDA: ";
  gotoxy(3,4);
  //pradiniai duomenys
cin>>naujas->vardas;
naujas->gyvybiuSk=5;
naujas->taskusSk=100;
naujas->nugaletiSk=0;


//irasome i registruotu zaideju sarasa
ofstream d;
d.open("registruotiZaidejai.txt", ios::app);
d<<naujas->vardas<<" ";
d<<naujas->gyvybiuSk<<" ";
d<<naujas->taskusSk<<" ";
d<<naujas->nugaletiSk<<endl;
d.close();

system("cls");
 system("color b5");
 gotoxy(3,3);
cout<<"JUSU NAUJAS ZAIDEJAS SUKURTAS!";
Sleep(1500);
showMenu();

delete naujas;
}



bool getKeyPressed( char &key )
{
	if( _kbhit() )
	{
		key = _getch();
		return true;
	}

	return false;
}


 void lygioPas(int zaidejoNR){
 system("cls");

 gotoxy(3,3);
 cout<<"PASIRINKITE LYGI: ";
 gotoxy(3,4);
cout<<"=======================================";
gotoxy(3,5);
cout<<"(1) LENGVAS LYGIS (50 tasku) ";
gotoxy(3,6);
cout<<"(2) SUNKUS LYGIS (100 tasku)";
gotoxy(3,7);
cout<<"(3) ATGAL "<<endl;

char key = ' ';
	bool running = true;

	do
	{
		if( getKeyPressed( key ) )
		{
			switch( key )
			{
				case '1':
					game(zaidejoNR);
					break;

				case '2':
game2(zaidejoNR);
					break;

				case '3':
					pagrindinis(zaidejoNR);
					running = false;
					break;

				default:
					std::cout << key << " Neteisingas pasirinkimas";
					lygioPas(zaidejoNR);
					break;
			}
		}
	}while( running );
}




void atnaujinimas(int zaidejoNR){

int n=zaidejoNR-1;

ofstream is;
is.open("registruotiZaidejai.txt");

int linenr=0;
for(int i=0;i<size-1;i++){

    if(i==n){continue;}

    is<<zaidejai[i].vardas<<" "<<zaidejai[i].gyvybiuSk<<" "<<zaidejai[i].taskusSk<<" "<<zaidejai[i].nugaletiSk<<endl;
}
//pridedam atnaujinta
is<<zaidejai[zaidejoNR-1].vardas<<" "<<zaidejai[zaidejoNR-1].gyvybiuSk<<" "<<zaidejai[zaidejoNR-1].taskusSk<<" "<<zaidejai[zaidejoNR-1].nugaletiSk<<endl;
is.close();

}



class Bombos
{
private:
	const static int rows = 10;
	const static int columns = 10;
	int coOrd;
	int maxB;
	int matrix[rows][columns];
public:
	Bombos()
	{
		coOrd = 0;
		maxB = 10;
	}

	void isvalyti() // isvalyti kamb.
	{
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < columns; x++)
			{
				matrix[y][x] = 0;
			}
		}
	}


	void rodytKamb()
	{
		cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
		cout << "-----------------------" << endl;
		for (int x = 0; x < rows; x++)
		{
			cout << coOrd << "| ";
			coOrd++;
			for (int y = 0; y < rows; y++)
			{
				cout << matrix[x][y] << " ";
			}
			cout << endl;
		}
	}

	int liko() // paziureti kiek liko bombu
	{
		int c = 0;
		for (int x = 0; x < rows; x++)
		{
			for (int y = 0; y < columns; y++)
			{
				if (matrix[x][y] == 1)
				{
					c++;
				}
			}
		}
		return c;
	}

	void padetB()//padedam bombas
	{
		int bomba = 0;
		while (bomba < maxB)
		{
			int xPos = rand() % 10; // pozicija nuo 0 iki 9 matricoje
			int yPos = rand() % 10;

			if (matrix[xPos][yPos] != 1)
			{
				bomba++;
				matrix[xPos][yPos] = 1;
			}

		}

	}
	bool ataka(int _x, int _y) // true arba false pagal tai ar pataike
	{
		if (matrix[_x][_y] == 1) // paziuri ar toje vietoje yra bomba
		{
			matrix[_x][_y] = 2; // jeigu pataike tai i ta vieta paraso 2 ir daugiau negalima taikyt i sia vieta
			return true;
		}
		return false;
	}
};



class Kambariai // kambariai matomi zaidejo
{
private:
	const static int rows = 10; // kambario matrica
	const static int columns = 10;
	char grid[rows][columns]; // "uzslepti" kambari su bombomis kai zaidiama todel char
public:

	void sudarytKamb() // sudaromi zaidimokambariai
	{
		for (int x = 0; x < rows; x++)
		{
			for (int y = 0; y < columns; y++)
			{
				grid[x][y] = '-'; //"uzslepiam"
			}
		}
	}

	void updateKamb(bool i, int x, int y) // atnaujinam kambarius
	{
		int xPos = x;
		int yPos = y;

		if (i == true)
		{
			grid[xPos][yPos] = 'Y';//jei pataike tai toje vietoje kambaryje pasirodo 'Y'
		}
		else
		{
			grid[xPos][yPos] = 'N'; // jei taike ir nepataike tai 'N'
		}
	}

	void PrintKamb() // isveda kamb.
	{
		int amt = 0;
		cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // stulpeliu koordinates
		for (int x = 0; x < rows; x++) {
			cout << amt << " ";
			amt++;
			for (int y = 0; y < columns; y++) {
				cout << grid[x][y] << " ";
			}
			cout << endl;
		}
	}
};



void game(int zaidejoNR){
    system("cls");
    //jei zaidejas turi uztektinai gyvybiu ir tasku zaisti
    if(zaidejai[zaidejoNR-1].taskusSk>=50 && zaidejai[zaidejoNR-1].gyvybiuSk>0){
 char rerun;

	do
	{ system("cls");
		srand((unsigned)time(NULL)); // kiekviena karta skirtingi

		Bombos zaidejas; // deklaruojami du zaidejai
		Bombos kompiuteris;

		Kambariai zaidejoBoard; // deklaruojami abieju zaideju kambariai
		Kambariai kompiuterioBoard;

		zaidejas.isvalyti();
		zaidejas.padetB();

		kompiuteris.isvalyti();
		kompiuteris.padetB();

		zaidejoBoard.sudarytKamb();
		kompiuterioBoard.sudarytKamb();

		cout << "Tavo kambarys: " << endl;
		zaidejoBoard.PrintKamb();
		cout << "Kompiuterio kambarys" << endl;


		kompiuterioBoard.PrintKamb();

		int position1, position2;
		char which; // variable paziuret ar zaidejas nori testi zaidima
		int found = 0; // bus talpinamas rastu bomu skaicius
		int toGo = 10; // talpinamas likusiu bombu skaicius

		int kFound = 0; // ^ tas pats kompiuterio zaidejui
		int kToGet = 10;

		bool isTrue;
		bool isTrueCpu;

		while (found < 10 || kFound < 10) // loop tol kol nera rastos visos bombus vieno is zaideju
		{
			int cpuX = rand() % 10; // kompiuterio ataka- random pozicija
			int cpuY = rand() % 10;

			if (kompiuteris.ataka(cpuX, cpuY))
			{
				isTrueCpu = true;
				kFound++;
				kToGet--;
				cout << "Kompiuteris rado bomba stai cia: " << "(" << cpuX << ", " << cpuY << ")" << endl;
			}
			else //jei kompiuteris nepataike
			{
				isTrueCpu = false;
				cout << "Kompiuteris nerado bombos si karta" << endl;
			}

			//------------------------------------------------------------------------------------------------------------

			position1 = 11;
			position2 = 11;

			while (position1 > 9 || position2 > 9)
			{
				if (kFound == 10 || found == 10) //jei laimejo kompiuteris nutraukiam loop
				{
					break;
				}
				cout << "Iveskite eilutes numeri: ";

				cin >> position1 ;

				cout<<"Iveskite stulpelio numeri: ";
				cin>>position2;

				while (cin.fail()) // jei zaidejas netinkamai ivede atakos koordinates
				{
					cin.clear();
					cin.ignore();
					cout << "netinkama pozicija, bandyk dar: "; cin >> position1 >> position2;
				}
			}

			if (zaidejas.ataka(position1, position2)) // jei pataike
			{
				isTrue = true;
				found++;
				toGo--;
				cout << "Tu radai: " << found << " bombu, dar liko rasti: " << toGo << " bombu" << endl;
			}
			else // nepataike:
			{
				isTrue = false;
				cout << "Sioje pozicijoje nera bombos" << endl;
			}

			cout << "Liko: " << zaidejas.liko() << " bombu" << endl;
			cout << "Norite pasiduoti (t/n)?: "; cin >> which;

			system("CLS");

			zaidejoBoard.updateKamb(isTrue, position1, position2);
			kompiuterioBoard.updateKamb(isTrueCpu, cpuX, cpuY);
system("cls"); //po kiekvieno ejimo naujas puslapis
			cout << "Tavo kambarys: " << endl;
			zaidejoBoard.PrintKamb(); // atnaujinti kambariai
			cout << "Kompiuterio kambarys" << endl;
			kompiuterioBoard.PrintKamb();


/////////////////////////////////////////////////////////////////////////////////
////////////////////////////KAI ZAIDIMAS BAIGTAS ATNAUJINTI TXT FAILE DUOMENIS
			if (which == 't') // jei nori baigti zaidima
			{   zaidejai[zaidejoNR-1].gyvybiuSk-=1;
			zaidejai[zaidejoNR-1].taskusSk-=50;
atnaujinimas(zaidejoNR);
				pagrindinis(zaidejoNR);
				break;
			}
			else if (found == 10)
			{
			    cout<<endl;
			    cout<<"LAIMEJOTE!";
			    zaidejai[zaidejoNR-1].nugaletiSk+=1;
			    zaidejai[zaidejoNR-1].taskusSk+=100;
			    atnaujinimas(zaidejoNR);
			    pagrindinis(zaidejoNR);
				break;
			}
			else if(kFound==10){
                cout<<endl;
                cout<<"PRALAIMEJOTE!!";
                zaidejai[zaidejoNR-1].gyvybiuSk-=1;
                zaidejai[zaidejoNR-1].taskusSk-=50;
                atnaujinimas(zaidejoNR);
                pagrindinis(zaidejoNR);
                break;
			}

		}



		cout << "Zaidimas baigtas!" << endl;
		cout << "Tavo kambarys: " << endl;
		cout << "2- reiskia rastas bombas" << endl;
		zaidejas.rodytKamb();
		cout << "----------------------------------------------------" << endl;
		cout << "Kompiuterio kambarys: " << endl;
		kompiuteris.rodytKamb();

		cout << "Norite zaisti dar karta? (r)"; cin >> rerun;
	} while (rerun == 'r' || rerun == 'R');

    }


else{
    system("cls");
    gotoxy(3,3);
    system("color b5");
    cout<<"NETURITE UZTEKTINAI GYVYBIU ARBA TASKU!!!!";
    Sleep(1500);
    pagrindinis(zaidejoNR);

}

}




class Bombos2
{
private:
	const static int rows = 10;
	const static int columns = 10;
	int coOrd;
	int maxB;
	int matrix[rows][columns];
public:
	Bombos2()
	{
		coOrd = 0;
		maxB = 15;
	}

	void isvalyti() // isvalyti kamb.
	{
		for (int y = 0; y < rows; y++)
		{
			for (int x = 0; x < columns; x++)
			{
				matrix[y][x] = 0;
			}
		}
	}


	void rodytKamb()
	{
		cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
		cout << "-----------------------" << endl;
		for (int x = 0; x < rows; x++)
		{
			cout << coOrd << "| ";
			coOrd++;
			for (int y = 0; y < rows; y++)
			{
				cout << matrix[x][y] << " ";
			}
			cout << endl;
		}
	}

	int liko() // paziureti kiek liko bombu
	{
		int c = 0;
		for (int x = 0; x < rows; x++)
		{
			for (int y = 0; y < columns; y++)
			{
				if (matrix[x][y] == 1)
				{
					c++;
				}
			}
		}
		return c;
	}

	void padetB()//padedam bombas
	{
		int bomba = 0;
		while (bomba < maxB)
		{
			int xPos = rand() % 10; // pozicija nuo 0 iki 9 matricoje
			int yPos = rand() % 10;

			if (matrix[xPos][yPos] != 1)
			{
				bomba++;
				matrix[xPos][yPos] = 1;
			}

		}

	}
	bool ataka(int _x, int _y) // true arba false pagal tai ar pataike
	{
		if (matrix[_x][_y] == 1) // paziuri ar toje vietoje yra bomba
		{
			matrix[_x][_y] = 2; // jeigu pataike tai i ta vieta paraso 2 ir daugiau negalima taikyt i sia vieta
			return true;
		}
		return false;
	}
};



class Kambariai2 // kambariai matomi zaidejo
{
private:
	const static int rows = 10; // kambario matrica
	const static int columns = 10;
	char grid[rows][columns]; // "uzslepti" kambari su bombomis kai zaidiama todel char
public:

	void sudarytKamb() // sudaromi zaidimokambariai
	{
		for (int x = 0; x < rows; x++)
		{
			for (int y = 0; y < columns; y++)
			{
				grid[x][y] = '-'; //"uzslepiam"
			}
		}
	}

	void updateKamb(bool i, int x, int y) // atnaujinam kambarius
	{
		int xPos = x;
		int yPos = y;

		if (i == true)
		{
			grid[xPos][yPos] = 'Y';//jei pataike tai toje vietoje kambaryje pasirodo 'Y'
		}
		else
		{
			grid[xPos][yPos] = 'N'; // jei taike ir nepataike tai 'N'
		}
	}

	void PrintKamb() // isveda kamb.
	{
		int amt = 0;
		cout << "  0 1 2 3 4 5 6 7 8 9" << endl; // stulpeliu koordinates
		for (int x = 0; x < rows; x++) {
			cout << amt << " ";
			amt++;
			for (int y = 0; y < columns; y++) {
				cout << grid[x][y] << " ";
			}
			cout << endl;
		}
	}
};



void game2(int zaidejoNR){
    system("cls");
    //jei zaidejas turi uztektinai gyvybiu ir tasku zaisti
    if(zaidejai[zaidejoNR-1].taskusSk>=100 && zaidejai[zaidejoNR-1].gyvybiuSk>0){
 char rerun;

	do
	{ system("cls");
		srand((unsigned)time(NULL)); // kiekviena karta skirtingi

		Bombos2 zaidejas; // deklaruojami du zaidejai
		Bombos2 kompiuteris;

		Kambariai2 zaidejoBoard; // deklaruojami abieju zaideju kambariai
		Kambariai2 kompiuterioBoard;

		zaidejas.isvalyti();
		zaidejas.padetB();

		kompiuteris.isvalyti();
		kompiuteris.padetB();

		zaidejoBoard.sudarytKamb();
		kompiuterioBoard.sudarytKamb();

		cout << "Tavo kambarys: " << endl;
		zaidejoBoard.PrintKamb();
		cout << "Kompiuterio kambarys" << endl;


		kompiuterioBoard.PrintKamb();

		int position1, position2;
		char which; // variable paziuret ar zaidejas nori testi zaidima
		int found = 0; // bus talpinamas rastu bomu skaicius
		int toGo = 15; // talpinamas likusiu bombu skaicius

		int kFound = 0; // ^ tas pats kompiuterio zaidejui
		int kToGet = 15;

		bool isTrue;
		bool isTrueCpu;

		while (found < 15 || kFound < 15) // loop tol kol nera rastos visos bombus vieno is zaideju
		{
			int cpuX = rand() % 10; // kompiuterio ataka- random pozicija
			int cpuY = rand() % 10;

			if (kompiuteris.ataka(cpuX, cpuY))
			{
				isTrueCpu = true;
				kFound++;
				kToGet--;
				cout << "Kompiuteris rado bomba stai cia: " << "(" << cpuX << ", " << cpuY << ")" << endl;
			}
			else //jei kompiuteris nepataike
			{
				isTrueCpu = false;
				cout << "Kompiuteris nerado bombos si karta" << endl;
			}

			//------------------------------------------------------------------------------------------------------------

			position1 = 11;
			position2 = 11;

			while (position1 > 9 || position2 > 9)
			{
				if (kFound == 15 || found == 15) //jei laimejo kompiuteris nutraukiam loop
				{
					break;
				}
				cout << "Iveskite eilutes numeri: ";

				cin >> position1 ;

				cout<<"Iveskite stulpelio numeri: ";
				cin>>position2;

				while (cin.fail()) // jei zaidejas netinkamai ivede atakos koordinates
				{
					cin.clear();
					cin.ignore();
					cout << "netinkama pozicija, bandyk dar: "; cin >> position1 >> position2;
				}
			}

			if (zaidejas.ataka(position1, position2)) // jei pataike
			{
				isTrue = true;
				found++;
				toGo--;
				cout << "Tu radai: " << found << " bombu, dar liko rasti: " << toGo << " bombu" << endl;
			}
			else // nepataike:
			{
				isTrue = false;
				cout << "Sioje pozicijoje nera bombos" << endl;
			}

			cout << "Liko: " << zaidejas.liko() << " bombu" << endl;
			cout << "Norite pasiduoti (t/n)?: "; cin >> which;

			system("CLS");

			zaidejoBoard.updateKamb(isTrue, position1, position2);
			kompiuterioBoard.updateKamb(isTrueCpu, cpuX, cpuY);
system("cls"); //po kiekvieno ejimo naujas puslapis
			cout << "Tavo kambarys: " << endl;
			zaidejoBoard.PrintKamb(); // atnaujinti kambariai
			cout << "Kompiuterio kambarys" << endl;
			kompiuterioBoard.PrintKamb();


/////////////////////////////////////////////////////////////////////////////////
////////////////////////////KAI ZAIDIMAS BAIGTAS ATNAUJINTI TXT FAILE DUOMENIS
			if (which == 't') // jei nori baigti zaidima
			{   zaidejai[zaidejoNR-1].gyvybiuSk-=1;
			zaidejai[zaidejoNR-1].taskusSk-=100;
atnaujinimas(zaidejoNR);
				pagrindinis(zaidejoNR);
				break;
			}
			else if (found == 15)
			{
			    cout<<endl;
			    cout<<"LAIMEJOTE!";
			    zaidejai[zaidejoNR-1].nugaletiSk+=1;
			    zaidejai[zaidejoNR-1].taskusSk+=200;
			    atnaujinimas(zaidejoNR);
			    pagrindinis(zaidejoNR);
				break;
			}
			else if(kFound==10){
                cout<<endl;
                cout<<"PRALAIMEJOTE!!";
                zaidejai[zaidejoNR-1].gyvybiuSk-=1;
                zaidejai[zaidejoNR-1].taskusSk-=100;
                atnaujinimas(zaidejoNR);
                pagrindinis(zaidejoNR);
                break;
			}

		}



		cout << "Zaidimas baigtas!" << endl;
		cout << "Tavo kambarys: " << endl;
		cout << "2- reiskia rastas bombas" << endl;
		zaidejas.rodytKamb();
		cout << "----------------------------------------------------" << endl;
		cout << "Kompiuterio kambarys: " << endl;
		kompiuteris.rodytKamb();

		cout << "Norite zaisti dar karta? (r)"; cin >> rerun;
	} while (rerun == 'r' || rerun == 'R');

    }


else{
    system("cls");
    gotoxy(3,3);
    system("color b5");
    cout<<"NETURITE UZTEKTINAI GYVYBIU ARBA TASKU!!!!";
    Sleep(1500);
    pagrindinis(zaidejoNR);

}

}





void parduotuve(int zaidejoNR){
system("cls");
gotoxy(5,3);
cout<<"PARDUOTUVE";
gotoxy(3,4);
cout<<"==========================";
gotoxy(3,5);
cout<<"Uz taskus galite nusipirkti gyvybes"<<endl;
cout<<"Siuo metu turite ["<<zaidejai[zaidejoNR-1].gyvybiuSk<<"] gyvybes ir ["<<zaidejai[zaidejoNR-1].taskusSk<<"] taskus"<<endl;

int p;
gotoxy(3,8);
cout <<"(1) PIRKTI 1 GYVYBE [UZ 50 TASKU]";
gotoxy(3,9);
cout <<"(2) PIRKTI 2 GYVYBES [UZ 80 TASKU]";
gotoxy(3,10);
cout <<"(3) PIRKTI 5 GYVYBES [UZ 200 TASKU]";
gotoxy(3,11);
cout <<"(4) ISEITI IS PARDUOTUVES"<<endl;

cout<<"Irasykite pasirinkima: ";
cin>>p;



}

void pagrindinis(int zaidejoNR){
system("cls");
cout<<"jusu id: "<<zaidejoNR;
gotoxy(3,3);
int p;
cout<<"SVEIKI SUGRIZE, "<<zaidejai[zaidejoNR-1].vardas;
gotoxy(3,4);
cout<<"(1) JUSU ZAIDEJO INFORMACIJA";
gotoxy(3,5);
cout<<"(2) ZAISTI";
gotoxy(3,6);
cout<<"(3) EITI I PARDUOTUVE";
gotoxy(3,7);
cout<<"(4) ZAIDEJU REITINGAS";
gotoxy(3,8);
cout<<"(5) ISEITI";
cout<<endl;
cin>>p;
switch(p){
case 1:{ //////info apie zaideja//////
    //zaidejoNR-=1;
    system("cls");
cout<<"jusu vardas:"<<zaidejai[zaidejoNR-1].vardas<<endl;
cout<<"jusu turimos gyvybes: "<<zaidejai[zaidejoNR-1].gyvybiuSk<<endl;
cout<<"jusu turimi taskai: "<<zaidejai[zaidejoNR-1].taskusSk<<endl;
cout<<"jusu nugaletu zaidimu skaicius: "<<zaidejai[zaidejoNR-1].nugaletiSk<<endl;
int atgal;
cout<< "< Atgal (enter)";
atgal=getch();
            if(atgal){
            pagrindinis(zaidejoNR);}
    break;
}
/////////////////////////////
case 2:{ lygioPas(zaidejoNR);
    //game(zaidejoNR);
    break;}

case 3:{ parduotuve(zaidejoNR);
    break;}
case 4:{ reitingas(zaidejoNR);
    break;}
case 5:{ showMenu();
    break;}



}
}


void prisijungimas(){
system("cls");
system("color b5");
string id;
gotoxy(3,3);
cout<<"Iveskite savo zaidejo varda: "<<endl;
cin>>id;
cout<<endl;
//patalpinam is txt i struct registruotus ir ieskome
size=0;

ifstream in;
in.open("registruotiZaidejai.txt");
while(!in.eof()){
    in>>zaidejai[size].vardas;
    in>>zaidejai[size].gyvybiuSk;
    in>>zaidejai[size].taskusSk;
    in>>zaidejai[size].nugaletiSk;
    size++;
}
in.close();

//struktura su zaideju info
/*
for(int j=0;j<i-1;j++){
    cout<<zaidejai[j].vardas<<" "<<zaidejai[j].gyvybiuSk<<" "<<zaidejai[j].taskusSk<<" "<<zaidejai[j].nugaletiSk<<endl;}
*/
int zaidejoNR=0;//ziureti kelinto strukturoje yra zaidejas
bool rastas=false;
for(int j=0;j<size-1;j++){
 zaidejoNR++;
    if(zaidejai[j].vardas==id){
       // cout<<"sveiki sugrize";
rastas=true;
        break;
    }

} //cout<<zaidejoNR;


if(rastas==true){
//jei pavyksta prisijungti tai einame i pagr psl.
pagrindinis(zaidejoNR);
}

else{ showMenu();}

}



void showMenu(){

int p;
system("cls");
system("color b5");
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
cout<<"(4) ISEITI"<<endl;
cin>>p;

switch(p){
case 1:
    naujasZaidejas();
    break;

case 2: prisijungimas();
break;

case 3: rodytiTaisykles();
break;

case 4: break;



}
}


void reitingas(int zaidejoNR){

system("cls");

gotoxy(3,3);
cout<<"Pagal ka norite ziureti reitinga?";
gotoxy(3,4);
cout<<"================================= ";
gotoxy(3,5);
cout<<"(1)REITINGAS PAGAL TASKU SKAICIU";
gotoxy(3,6);
cout<<"(2)REITINGAS PAGAL NUGALETU ZAIDIMU SKAICIU ";
gotoxy(3,7);
cout<<"(3)Iseiti";

char key = ' ';
	bool running = true;

	do
	{
		if( getKeyPressed( key ) )
		{
			switch( key )
			{
				case '1':
					reitTaskai(zaidejoNR);
					break;

				case '2':
reitNugaleti(zaidejoNR);
					break;

				case '3':
					pagrindinis(zaidejoNR );
					running = false;
					break;

				default:
					std::cout << key << " Neteisingas pasirinkimas";
					reitingas(zaidejoNR);
					break;
			}
		}
	}while( running );





}


void reitTaskai(int zaidejoNR){
/*system("cls");
gotoxy(3,3);
cout<<"REITINGAS PAGAL TASKU SKAICIU..."<<endl;


//SORTING....
cout<<endl;
*/

bool swapped;
do{
    swapped=false;
    for(int count=0;count<size-1;count++){
        if(zaidejai[count].taskusSk<zaidejai[count+1].taskusSk){
            swap(zaidejai[count],zaidejai[count+1]);
            swapped=true;
        }

    }


}while(swapped);


//sorted dedam i faila
ofstream d;
d.open("reitingasTaskai.txt");

for(int i=0;i<=size-2;i++){
        d<<i+1<<". ";
    d<<zaidejai[i].taskusSk<<" "<<zaidejai[i].vardas<<endl;
}

d.close();

//i html
string name;
ifstream x;
string head = "<!DOCTYPE html>\n<html>\n<head> <style> table, th, td { border: 1px solid black; }  </style> </head><body style=background-color:#37FDC3;>\n<table width=500>";
    string tail = "</table></body>\n</html>";
    string bodystart = "<tr bgcolor=C9C9F9><td>\n";
    string bodyclose = "</td></tr>";

    ofstream y;
    //x.open("reitingasTaskai.txt",std::ios::app);
    y.open("reitingas.html");




    y<<head;
    y<<"<h2> REITINGAS PAGAL TASKUS </H2>";
    y<<"<tr> <th bgcolor=C9C9F9>Nr.</th> <th bgcolor=C9C9F9>Taskai</th> <th bgcolor=C9C9F9>Vardas</th>  </tr>";

    for(int i=0;i<size-2;i++){
        y<<bodystart;
                y<< i+1;
        y<< "</td>";
       y<< "<td>";
        y<< zaidejai[i].taskusSk;
          y<<"</td>";
        y<<"<td>";
       y<< zaidejai[i].vardas;
         y<<bodyclose;
    }
    y<<tail;


    //atidarome narsykleje
    ShellExecute(NULL, "open", "file:///C:/Users/ABC/Documents/GitHub/praktines-uzduotys-agnesvam/Zaidimas/reitingas.html",
                NULL, NULL, SW_SHOWNORMAL);




}









void reitNugaleti(int zaidejoNR){

bool swapped;
do{
    swapped=false;
    for(int count=0;count<size-1;count++){
        if(zaidejai[count].nugaletiSk<zaidejai[count+1].nugaletiSk){
            swap(zaidejai[count],zaidejai[count+1]);
            swapped=true;
        }

    }


}while(swapped);


//sorted dedam i faila
ofstream d;
d.open("reitingasTaskai.txt");

for(int i=0;i<=size-2;i++){
        d<<i+1<<". ";
    d<<zaidejai[i].nugaletiSk<<" "<<zaidejai[i].vardas<<endl;
}

d.close();

//i html
string name;
ifstream x;
string head = "<!DOCTYPE html>\n<html>\n<head> <style> table, th, td { border: 1px solid black; }  </style> </head><body style=background-color:#37FDC3;>\n<table width=500>";
    string tail = "</table></body>\n</html>";
    string bodystart = "<tr bgcolor=C9C9F9><td>\n";
    string bodyclose = "</td></tr>";

    ofstream y;
    //x.open("reitingasTaskai.txt",std::ios::app);
    y.open("reitingas.html");




    y<<head;
    y<<"<h2> REITINGAS PAGAL NUGALETU ZAIDIMU SKAICIU </H2>";
    y<<"<tr> <th bgcolor=C9C9F9>Nr.</th> <th bgcolor=C9C9F9>Taskai</th> <th bgcolor=C9C9F9>Vardas</th>  </tr>";

    for(int i=0;i<size-2;i++){
        y<<bodystart;
                y<< i+1;
        y<< "</td>";
       y<< "<td>";
        y<< zaidejai[i].nugaletiSk;
          y<<"</td>";
        y<<"<td>";
       y<< zaidejai[i].vardas;
         y<<bodyclose;
    }
    y<<tail;


    //atidarome narsykleje
    ShellExecute(NULL, "open", "file:///C:/Users/ABC/Documents/GitHub/praktines-uzduotys-agnesvam/Zaidimas/reitingas.html",
                NULL, NULL, SW_SHOWNORMAL);






}



