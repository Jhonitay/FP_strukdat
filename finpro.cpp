/*
	Final Project Sruktur Data 
	Kelompok 1 (Semester2)
	- Komang Nitay Prasaddas	21.11.4376
	- Angga Airul Rohman		21.11.4384
	- Khoirudin Yoga Pratama	21.11.4389
	- Farhan purnama Putra		21.11.4397
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

struct soal{
	string Easy[5];
	string Medium[7];
	string Hard[9];
};
struct Node{
    int data;
    Node *next;
};
struct data{
	int score[3];
	string Nama;
};

Node *headEall = NULL;
Node *currentEall = NULL;
Node *headMall = NULL;
Node *currentMall = NULL;
Node *headHall = NULL;
Node *currentHall = NULL;

data Easy[5];
data Med[5];
data Hard[5];

void Play(soal *soal);
void Game(soal *soal,int X);
void TopPlayer();
void Input();
void RuleGame();

void inputEasy(int all);
void printEasy();
void insertE_at(int point);
void SaveData();

void inputMed(int all);
void printMed();
void insertM_at(int point);

void inputHard(int all);
void printHard();
void insertH_at(int point);

string newPlayer;
int newScore[3];
int Search;
string SearchNama;

void gotoxy(int x, int y){
	COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void blue(){
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hstdout,11);
}

void red(){
    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hstdout,12);
}

void loading(){
    system("CLS");
    char a=219;
    gotoxy(36,8); cout<<"LOADING, PLEASE WAIT"<<endl;
    gotoxy(30,10);
    for(int i=0; i<30; i++){
        for(int j=0; j<=19999999; j++);
            red(); cout<<a; blue();
    }
}

//===========================================================================================================
int main(){
	int all;
	soal soal[3];
	
	ifstream  Mudah; Mudah.open("Easy.txt"); ifstream Name; Name.open("Name.txt");
	ifstream Menengah; Menengah.open("Medium.txt");	ifstream Score; Score.open("Score.txt");
	ifstream Sulit; Sulit.open("Hard.txt");
	
	for (int i=0;i<3;i++){
		for (int E=0;E<5;E++){
			Mudah>>soal[i].Easy[E];}
		for (int E=0;E<7;E++){
			Menengah>>soal[i].Medium[E];}
		for (int E=0;E<9;E++){
			Sulit>>soal[i].Hard[E];}
	}
		for (int i=0;i<5;i++){
			getline(Name,Easy[i].Nama);
			Score>>Easy[i].score[0];
			Score>>Easy[i].score[1];
			Score>>Easy[i].score[2];
			all=Easy[i].score[0] + Easy[i].score[1] + Easy[i].score[2];
			inputEasy(all);
		
			getline(Name,Med[i].Nama);
			Score>>Med[i].score[0];
			Score>>Med[i].score[1];
			Score>>Med[i].score[2];
			all=Med[i].score[0] + Med[i].score[1] + Med[i].score[2];
			inputMed(all);
		
			getline(Name,Hard[i].Nama);
			Score>>Hard[i].score[0];
			Score>>Hard[i].score[1];
			Score>>Hard[i].score[2];
			all=Hard[i].score[0] + Hard[i].score[1] + Hard[i].score[2];
			inputHard(all);
		}

	//===========================================================================================================
	Ulangi:
	int get=0;
	int pilih=1;
	Search=0;
    blue();
    loading();
	while (get!=13){
    system("CLS");
	gotoxy(0,1);
	cout<<"  ====================="<<endl;
	cout<<"  |       GAME        |"<<endl;
	cout<<"  |   TUMPUK TUMPUK   |"<<endl;
	cout<<"  ====================="<<endl;
	cout<<endl;
		if (pilih==0){pilih=5;}
		if (pilih==6){pilih=1;}
	gotoxy(0,5);blue();cout<<"        PLAY GAME ";if(pilih==1){gotoxy(5,5);red();cout<<"=> PLAY GAME <=";}cout<<endl;
	gotoxy(0,6);blue();cout<<"        TOP SCORE ";if(pilih==2){gotoxy(5,6);red();cout<<"=> TOP SCORE <=";}cout<<endl;
	gotoxy(0,7);blue();cout<<"        RULE GAME ";if(pilih==3){gotoxy(5,7);red();cout<<"=> RULE GAME <=";}cout<<endl;
	gotoxy(0,8);blue();cout<<"        INFO GAME ";if(pilih==4){gotoxy(5,8);red();cout<<"=> INFO GAME <=";}cout<<endl;
	gotoxy(0,9);blue();cout<<"        EXIT GAME ";if(pilih==5){gotoxy(5,9);red();cout<<"=> EXIT GAME <=";}cout<<endl;
    blue();
	for (int i=1; i<23; i++){
		if (i!=1){
		gotoxy(i,10);cout<<"=";
		}
		if (i>4 && i<10){
			gotoxy(21,i);cout<<" |";
			gotoxy(1,i);cout<<" |";
		}
	}
	get=getche();
	get=getche();
	if (get==72){pilih--;}
	else if(get==80){pilih++;}
	}
	if (pilih==1){Play(soal);goto Ulangi;}
	else if (pilih==2){TopPlayer();goto Ulangi;}
	else if (pilih==3){RuleGame();goto Ulangi;}
	else if (pilih==4){system("REFERENSI.png");goto Ulangi;}
	else if (pilih==5){}
	else{goto Ulangi;}
	cout<<endl;
}

void Input(char *input,int jumlah){
	int T=0;
	for (int i=0;i<jumlah;i++){
		if (*input+i==('0'||'1'||'2'||'3'||'4'||'5'||'6'||'7'||'8'||'9')){
			T++;
		}
	}
		if (T==jumlah){
			Search=(int)(*input);
		}else{Search=0;}
	}

void Play(soal *soal){
	char Nick[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	int i,MaxNick=9;
	system("CLS");
	cout<<endl<<endl;
	cout<<"     MASUKKAN NICKNAME "<<endl;
	cout<<"      Max 10 Karakter";
	for (int i=1; i<25; i++){
		gotoxy(i+1,1); cout<<"=";
		gotoxy(i+1,4); cout<<"=";
		gotoxy(i+1,8); cout<<"=";
		if (i!=0 && i!=1 && i<8 && i!=4 ){
			gotoxy(25,i); cout<<"|";
			gotoxy(2,i); cout<<"|";
		}
	}
	gotoxy(9,6);
	cin>>Nick;
	//cin.getline(Nick,sizeof (Nick));
	 i= strlen(Nick);
	while(i<=MaxNick){
		Nick[MaxNick]=' ';//input spasi pada array Nick yang jumlah penggunaan hurufnya kurang dari 10
		MaxNick--;
	}
	//for (i=strlen(Nick);i<10;i++){
		//Nick[MaxNick]=" ";
	//}

	newPlayer=Nick;
	newPlayer=newPlayer.erase(10,10);
	int pilih=1;
	int get;
	while (get!=13){    
	system("CLS");
	cout<<endl;
	cout<<"  ============================"<<endl;
	cout<<"  | > "<<newPlayer<<"             |"<<endl;
	cout<<"  ============================"<<endl;
		if (pilih==0){pilih=4;}
		if (pilih==5){pilih=1;}
	gotoxy(0,4);blue();cout<<"  | SILAHKAN PILIH MODE GAME |"<<endl;
	gotoxy(0,5);blue();cout<<"  ============================"<<endl;
	gotoxy(0,6);blue();cout<<"              EASY ";if(pilih==1){gotoxy(11,6);red();cout<<"=> EASY <=";}cout<<endl;
	gotoxy(0,7);blue();cout<<"             MEDIUM ";if(pilih==2){gotoxy(10,7);red();cout<<"=> MEDIUM <=";}cout<<endl;
	gotoxy(0,8);blue();cout<<"              HARD ";if(pilih==3){gotoxy(11,8);red();cout<<"=> HARD <=";}cout<<endl;
	gotoxy(0,9);blue();cout<<"             CANCEL ";if(pilih==4){gotoxy(10,9);red();cout<<"=> CANCEL <=";}cout<<endl;
    blue();
	gotoxy(0,10);cout<<"  ============================"<<endl;
	for (int i=0; i<10; i++){
		if (i>5 && i<10){
			gotoxy(28,i);cout<<" |";
			gotoxy(1,i);cout<<" |";
		}
	}

	get=getche();
	get=getche();
	if (get==72){pilih--;}
	else if(get==80){pilih++;}
	}
	if (pilih==1){// variabel X untuk pembeda antara tingkat kesulitan
		int X=5; Game(soal,X);
	}else if (pilih==2){
		int X=7; Game(soal,X);
	}else if (pilih==3){
		int X=9; Game(soal,X);
	}else if (pilih==4){
	}else{};
}

void Game(soal *soal,int X){
	string A[X];
	string B[X];
	string C[X];
	string Jawab[9]={"9","8","7","6","5","4","3","2","1"};
	string Jawaban[X];
	string Wadah[3]={"A","B","C"};
	int i=0,a=X,b=0,c=0,Z=0,point;
	char Dari,Ke;
	string Temp;
	for(int F=0;F<3;F++){
		for (int j=0;j<X;j++){
			if (X==5){ A[j]=soal[F].Easy[j];
				Jawaban[j]=Jawab[j+4];
				B[j]="|";
				C[j]="|";
			}else if (X==7){ A[j]=soal[F].Medium[j];
				Jawaban[j]=Jawab[j+2];
				B[j]="|";
				C[j]="|";
			}else if (X==9){ A[j]=soal[F].Hard[j];
				Jawaban[j]=Jawab[j];
				B[j]="|";
				C[j]="|";
			}
		}
		newScore[F]=301;
	while (Z!=X){
		newScore[F]--;//mengurangi jumlah point setiap satu langkah(perulangan)
		system("CLS");
		cout<<endl<<endl;
		cout<<"    Urutkan Secara Ascending Susunan Angka yang ada pada Pilar A!\n";
		for (int i=2; i<67; i++){
			gotoxy(i,1); cout<<"=";
			gotoxy(i,3); cout<<"=";
			if (i==2){
				gotoxy(2,i); cout<<"|";
				gotoxy(66,i); cout<<"|";
			}
		}

		cout<<endl<<endl<<endl;
		cout<<"\t\t================================="<<endl;
        if(X==5){cout<<"\t\t| LEVEL "<<F+1<<"     EASY     SKOR:"<< newScore[F]<<" |"<<endl;}
        if(X==7){cout<<"\t\t| LEVEL "<<F+1<<"    MEDIUM    SKOR:"<< newScore[F]<<" |"<<endl;}
        if(X==9){cout<<"\t\t| LEVEL "<<F+1<<"     HARD     SKOR:"<< newScore[F]<<" |"<<endl;}
		cout<<"\t\t================================="<<endl;
		cout<<"\t\t|                               |"<<endl;
		cout<<"\t\t|                               |"<<endl;
		for (int i=X-1;i>=0;i--){
			cout<<"\t\t|        "<<A[i]<<"      "<<B[i]<<"      "<<C[i]<<"        |"<<endl;
		}
		cout<<"\t\t|       =================       |";
		cout<<endl;
		cout<<"\t\t|        "<<Wadah[0]<<"      "<<Wadah[1]<<"      "<<Wadah[2]<<"        |"<<endl;
		cout<<"\t\t|                               |"<<endl;
		cout<<"\t\t|                               |"<<endl;
		cout<<"\t\t================================="<<endl;

        gotoxy(52,11); cout<<"Pindah dari\t:";red();cout<<" "; cin>>Dari;
        gotoxy(52,13); blue(); cout<<"Pindah ke\t:";red();cout<<" "; cin>>Ke;
        blue();

		if((Dari=='a'||Dari=='A')&&(Ke=='b'||Ke=='B')&&(b<X)&&(a>0)){
			Temp=A[a-1]; A[a-1]=B[b]; B[b]=Temp;
			a--; b++;
		}else if((Dari=='a'||Dari=='A')&&(Ke=='c'||Ke=='C')&&(c<X)&&(a>0)){
			Temp=A[a-1]; A[a-1]=C[c]; C[c]=Temp;
			a--; c++;
		}else if((Dari=='b'||Dari=='B')&&(Ke=='A'||Ke=='a')&&(a<X)&&(b>0)){
			Temp=B[b-1]; B[b-1]=A[a]; A[a]=Temp;
			b--; a++;
		}else if((Dari=='B'||Dari=='b')&&(Ke=='c'||Ke=='C')&&(c<X)&&(b>0)){
			Temp=B[b-1]; B[b-1]=C[c]; C[c]=Temp;
			b--; c++;
		}else if((Dari=='c'||Dari=='C')&&(Ke=='b'||Ke=='B')&&(b<X)&&(c>0)){
			Temp=C[c-1]; C[c-1]=B[b]; B[b]=Temp;
			c--; b++;
		}else if((Dari=='c'||Dari=='C')&&(Ke=='A'||Ke=='a')&&(a<X)&&(c>0)){
			Temp=C[c-1]; C[c-1]=A[a]; A[a]=Temp;
			c--; a++;
		}else if (Dari=='z'){Z=X;}
		else {newScore[F]++;}//menambahkan point karena kesalahan penulisan perintah tidak mengurangi point;
		Z=0;
		for(int L=0;L<X;L++){
			if (A[L]==Jawaban[L]){Z++;}
		}
	}

	system("CLS");
	cout<<endl<<endl;
	for (int K=X-1;K>=0;K--){
			cout<<"          "<<A[K]<<"      "<<B[K]<<"      "<<C[K]<<endl;
		}
			cout<<"         ================="<<endl;
			cout<<"          "<<Wadah[0]<<"      "<<Wadah[1]<<"      "<<Wadah[2]<<endl<<endl<<endl;
	for (int i=0; i<36; i++){
		gotoxy(i,0); cout<<"="<<endl<<endl;
		gotoxy(i,5+X); cout<<"=";
			if (i<5+X && i!=0){
				gotoxy(0,i); cout<<"|";
				gotoxy(35,i); cout<<"|";
			}
	}
    cout<<endl;
    gotoxy(38,4); cout<<"HORE! SUDAH SELESAI!"<<endl;
	gotoxy(38,5); cout<<"SKOR ANDA = "<<newScore[F]<<endl;
	gotoxy(38,6); red(); cout<<"Tekan enter untuk NEXT";
    blue();
    Dari=getch();
	Z=0;
	}
	point=newScore[0]+newScore[1]+newScore[2];
	//percabangan ke sorting;
	Dari=getch();
	if 		 (X==5) {insertE_at(point); //easy sorting 
	}else if (X==7) {insertM_at(point); //medium
	}else if (X==9) {insertH_at(point);//hard
	}
}

void SaveData(){
		ofstream name; name.open("Name.txt");
		ofstream score; score.open("Score.txt");
		for (int i=0;i<5;i++){
			name<<Easy[i].Nama;     name<<"\n";
			score<<Easy[i].score[0];score<<" ";
			score<<Easy[i].score[1];score<<" ";
			score<<Easy[i].score[2];score<<" ";
			score<<"\n";
		
			name<<Med[i].Nama;      name<<"\n";
			score<<Med[i].score[0];score<<" ";
			score<<Med[i].score[1];score<<" ";
			score<<Med[i].score[2];score<<" ";
			score<<"\n";
			
			name<<Hard[i].Nama;     name<<"\n";
			score<<Hard[i].score[0];score<<" ";
			score<<Hard[i].score[1];score<<" ";
			score<<Hard[i].score[2];score<<" ";
			score<<"\n";
		}
}

void TopPlayer (){
	char nick[10];
	int maxNick=9,i;
	ulangi:
	Search=0;
	char next;
	char pilih1;
	system("CLS");printEasy();cout<<"          >> Next";next=getch();
	system("CLS");printMed();cout<<"          >> Next";next=getch();
	system("CLS");printHard();
	cout << "\n  [1] Search Detail Player"<<endl<<"  [2] Kembali ke Menu"<<endl;
	cout << "\n     Masukan Pilihan[1/2]" << endl;
	red(); cout << "    > ";blue();
	cin>>pilih1;
	if (pilih1=='2'){}
	else if (pilih1=='1'){
		red(); cout<<"\n  [!] Input Nama Yang\n      Anda Cari : "; blue();
		cin>>nick;
		//cin.getline (nick, sizeof (nick));
		i= strlen(nick);
	while(i<=maxNick){
		nick[maxNick]=' ';//input spasi pada array Nick yang jumlah penggunaan hurufnya kurang dari 10
		maxNick--;
	}
	system("cls");
	cout << "\n            +--------------------+ " << endl;
	cout << "            | H A S I L  C A R I | " << endl;
	cout << "            +--------------------+ " << endl;
	cout << endl << " -> Nick : " << nick << endl <<endl;
	SearchNama=nick;
	SearchNama=SearchNama.erase(10,10);
		cout << " +==========================================+"<<endl;
		cout << " | Mode     NAMA       SKOR   Lv1  Lv2  Lv3 |"<<endl;
		cout << " +------------------------------------------+"<<endl;
		Search=1;
		printEasy();
		printMed();
		printHard();
				cout << " +==========================================+"<<endl;
	red(); cout<<" \n\n\t [!] ENTER UNTUK KE MENU";pilih1=getche(); blue();
		}else{
		goto ulangi;
	}
}

void RuleGame(){
	system("CLS");
	cout<<endl;
    cout<<"  ================================="<<endl;
	cout<<"  |                               |"<<endl;
	cout<<"  |                               |"<<endl;
	cout<<"  |        4      |      |        |"<<endl;
	cout<<"  |        5      |      |        |"<<endl;
	cout<<"  |        3      |      |        |   Pindah dari :";
	cout<<"\n  |        1      |      |        |   Pindah ke   :";
	cout<<"\n  |        2      |      |        |"<<endl;
	cout<<"  |       =================       |"<<endl;
	cout<<"  |        A      B      C        |"<<endl;
	cout<<"  |                               |"<<endl;
	cout<<"  |                               |"<<endl;
	cout<<"  ================================="<<endl;

	gotoxy(54,6); cout<<"<= Masukkan huruf A";
	gotoxy(52,6);
	getch();
    gotoxy(52,6); cout<<"A";
	getch();

	gotoxy(54,7); cout<<"<= Masukkan huruf B";
	gotoxy(52,7);
	getch();
	gotoxy(52,7); cout<<"B";
	getch();

	gotoxy(11,4); cout<<"|";
	gotoxy(18,8); cout<<"4 <=";
	getch();
}

//===================================== Sorting Linked List ==================================================
bool EasyEmpty(){return (headEall == NULL);}
void inputEasy(int all){
	Node *newEall = NULL;// deklarasi pointer newNode;
	newEall = new Node;// mengalokasikan memory untuk pointer newNode
	newEall->data = all;// isikan data ke node yang baru
    if (EasyEmpty()){                   
		headEall = newEall;    // node baru otomatis menjadi head node	
    }else {
		currentEall->next = newEall;// hubungkan pointer next node aktif (current node) ke node yg baru	
    }
		currentEall = newEall;// set node baru sebagai node aktif		  
	currentEall->next = NULL;
	delete currentEall->next;
}

//===========================================================================================================
void insertE_at(int point){
	Node *newEall = NULL;
	newEall = new Node;// mengalokasikan memory untuk pointer newNode
	int Patok=0;
	
	newEall->data = point;// isikan data ke node yang baru
	Node *bantuE = headEall;
	Node *hapusEall = currentEall;
	if (newEall->data >= bantuE->data)//jika data baru nilainya lebih besar dari data ke-1
	{	newEall->next = bantuE;
		headEall=newEall;
		
		while (bantuE->next != currentEall){
			bantuE = bantuE->next;
		}
		currentEall = bantuE;
		currentEall->next = NULL;
	}else if (newEall->data < currentEall->data)//jika data baru nilainya lebih kecil dari data ke-5
	{	newEall=NULL;
		delete newEall;
		Patok=5;
		
	}else                                   	//jika data baru besar nilainya di antara 2 data
	{	Patok=1;
	while (newEall->data < bantuE->next->data){
			bantuE = bantuE->next;
			Patok++;
		}
		newEall->next = bantuE->next;
		bantuE->next = newEall;
		
		while (bantuE->next != currentEall){
			bantuE = bantuE->next;
		}
		currentEall = bantuE;
		currentEall->next = NULL;
	}
	if (Patok>=0&&Patok<5){
		for (int i=4;i>Patok;i--){
		Easy[i].Nama=Easy[i-1].Nama;
		Easy[i].score[0]=Easy[i-1].score[0];
		Easy[i].score[1]=Easy[i-1].score[1];
		Easy[i].score[2]=Easy[i-1].score[2];
	}
		Easy[Patok].Nama=newPlayer;
		Easy[Patok].score[0]=newScore[0];
		Easy[Patok].score[1]=newScore[1];
		Easy[Patok].score[2]=newScore[2];
	}	
		gotoxy(0,12);
		printEasy();
		SaveData();
		red();cout<<"MENU>>";blue();
		int jeda=getche();
}

void printEasy()
{
    // deklarasi pointer awal node untuk menampung head node
    Node *awalEall = headEall;
    int i = 0;
	if (Search <=0){
	cout << "\n    > T O P  S C O R E < " << endl;
	cout<<" +------------------------+"<<endl;
	cout<<" |        [ EASY ]        |"<<endl;
	cout<<" +------------------------+"<<endl;
	cout<<" |     NAMA      |  SKOR  |"<<endl;
	cout<<" +------------------------+"<<endl;
		  while (awalEall != NULL){
        cout << " | " << i+1 << ". " << Easy[i].Nama <<" |   "<< awalEall->data <<"  |"<<endl;
        awalEall = awalEall->next;	
        i++;          
    }
	cout<<" +------------------------+"<<endl;
	}
    else{
		while (awalEall != NULL)
		{		
		if (Easy[i].Nama==SearchNama){ 
		cout <<" | Easy   " << Easy[i].Nama<<"  ["<< awalEall->data <<"]   "<<Easy[i].score[0]<<"  "<<Easy[i].score[1]<<"  "<<Easy[i].score[2]<<" |";
		cout<<endl;         
		}
		awalEall = awalEall->next;
		i++;
		} 
	}
}

//===========================================================================================================
//===========================================================================================================
//===========================================================================================================
//=====================================medium================================================================
bool MedEmpty(){return (headMall == NULL);}
void inputMed(int all){
	Node *newMall = NULL;// deklarasi pointer newNode;
	newMall = new Node;// mengalokasikan memory untuk pointer newNode
	newMall->data = all;// isikan data ke node yang baru
    if (MedEmpty()){                   
		headMall = newMall;    // node baru otomatis menjadi head node	
    }else {
		currentMall->next = newMall;// hubungkan pointer next node aktif (current node) ke node yg baru	
    }
		currentMall = newMall;// set node baru sebagai node aktif		  
	currentMall->next = NULL;
	delete currentMall->next;
}//==========================================================================================================

void insertM_at(int point){
	Node *newMall = NULL;
	newMall = new Node;// mengalokasikan memory untuk pointer newNode
	int Patok=0;
	
	newMall->data = point;// isikan data ke node yang baru
	Node *bantu = headMall;
	Node *hapusMall = currentMall;
	if (newMall->data >= bantu->data)//jika data baru nilainya lebih besar dari data ke-1
	{	newMall->next = bantu;
		headMall=newMall;
		
		while (bantu->next != currentMall){
			bantu = bantu->next;
		}
		currentMall = bantu;
		currentMall->next = NULL;
	
	}else if (newMall->data < currentMall->data)//jika data baru nilainya lebih kecil dari data ke-5
	{	newMall=NULL;
		delete newMall;
		Patok=5;
	}else   //jika data baru besar nilainya di antara 2 data
	{
		Patok=1;
		while (newMall->data < bantu->next->data){
			bantu = bantu->next;
			Patok++;
		}
		newMall->next = bantu->next;
		bantu->next = newMall;
		
		while (bantu->next != currentMall){
			bantu = bantu->next;
		}
		currentMall = bantu;
		currentMall->next = NULL;
		
		
	}
	if (Patok>=0&&Patok<5){
		for (int i=4;i>Patok;i--){
		Med[i].Nama=Med[i-1].Nama;
		Med[i].score[0]=Med[i-1].score[0];
		Med[i].score[1]=Med[i-1].score[1];
		Med[i].score[2]=Med[i-1].score[2];
	}
		Med[Patok].Nama=newPlayer;
		Med[Patok].score[0]=newScore[0];
		Med[Patok].score[1]=newScore[1];
		Med[Patok].score[2]=newScore[2];
	}
		gotoxy(0,14);
		printMed();
		SaveData();
		red();cout<<"MENU>>";blue();
		int jeda=getche();
}

void printMed()
{
    // deklarasi pointer awal node untuk menampung head node
    Node *awalMall = headMall;
    int i = 0;
	if (Search <=0){
	cout << "\n    > T O P  S C O R E < " << endl;
	cout<<" +------------------------+"<<endl;
	cout<<" |       [ MEDIUM ]       |"<<endl;
	cout<<" +------------------------+"<<endl;
	cout<<" |     NAMA      |  SKOR  |"<<endl;
	cout<<" +------------------------+"<<endl;
		  while (awalMall != NULL){
        cout << " | " << i+1 << ". " << Med[i].Nama <<" |   "<< awalMall->data <<"  |"<<endl;
        awalMall = awalMall->next;
       i++;           
    }
	cout<<" +------------------------+"<<endl;
	
	}
    else{
		  while (awalMall != NULL){	
		if (Med[i].Nama==SearchNama){ 
		cout <<" | Med    " << Med[i].Nama <<"  ["<< awalMall->data <<"]   "<< Med[i].score[0]<<"  "<<Med[i].score[1]<<"  "<<Med[i].score[2]<<" |";
		cout<<endl;
                
	}
	awalMall = awalMall->next;
	i++;
    }
	}
}//====================================================================================
bool HardEmpty(){return (headHall == NULL);}
void inputHard(int all){
	Node *newHall = NULL;// deklarasi pointer newNode;
	newHall = new Node;// mengalokasikan memory untuk pointer newNode
	newHall->data = all;// isikan data ke node yang baru
    if (HardEmpty()){                   
		headHall = newHall;    // node baru otomatis menjadi head node	
    }else {
		currentHall->next = newHall;// hubungkan pointer next node aktif (current node) ke node yg baru	
    }
		currentHall = newHall;// set node baru sebagai node aktif		  
	currentHall->next = NULL;
	delete currentHall->next;
}
void printHard(){
    // deklarasi pointer awal node untuk menampung head node
    Node *awalHall = headHall;
    int i = 0;
	if (Search <=0){
	cout << "\n    > T O P  S C O R E < " << endl;
	cout<<" +------------------------+"<<endl;
	cout<<" |        [ HARD ]        |"<<endl;
	cout<<" +------------------------+"<<endl;
	cout<<" |     NAMA      |  SKOR  |"<<endl;
	cout<<" +------------------------+"<<endl;
		  while (awalHall != NULL){
        cout << " | " << i+1 << ". " << Hard[i].Nama <<" |   "<< awalHall->data <<"  |"<<endl;
        awalHall = awalHall->next;         
        i++;          
    }
	cout<<" +------------------------+"<<endl;
	}
    else{
		  while (awalHall != NULL)
    {
		if (Hard[i].Nama==SearchNama){ 
		cout <<" | Hard   " << Hard[i].Nama <<"  ["<< awalHall->data <<"]   "<< Hard[i].score[0]<<"  "<<Hard[i].score[1]<<"  "<<Hard[i].score[2]<<" |";
		cout<<endl;         
	}
	awalHall = awalHall->next;
	i++;
    } 
}
}

void insertH_at(int point){
	Node *newHall = NULL;
	newHall = new Node;// mengalokasikan memory untuk pointer newNode
	int Patok=0;
	
	newHall->data = point;// isikan data ke node yang baru
	Node *bantuH = headHall;
	Node *hapusHall = currentHall;
	if (newHall->data >= bantuH->data)//jika data baru nilainya lebih besar dari data ke-1
	{	newHall->next = bantuH;
		headHall=newHall;
		
		while (bantuH->next != currentHall){
			bantuH = bantuH->next;
		}
		currentHall = bantuH;
		currentHall->next = NULL;
	
	}else if (newHall->data < currentHall->data)//jika data baru nilainya lebih kecil dari data ke-5
	{	newHall=NULL;
		delete newHall;
		Patok=5;
	}else                                     //jika data baru besar nilainya di antara 2 data
	{	Patok=1;
		while (newHall->data < bantuH->next->data){
			bantuH = bantuH->next;
			Patok++;
		}
		newHall->next = bantuH->next;
		bantuH->next = newHall;
		
		while (bantuH->next != currentHall){
			bantuH = bantuH->next;
		}
		currentHall = bantuH;
		currentHall->next = NULL;
	}
	if (Patok>=0&&Patok<5){
		for (int i=4;i>Patok;i--){
		Hard[i].Nama=Hard[i-1].Nama;
		Hard[i].score[0]=Hard[i-1].score[0];
		Hard[i].score[1]=Hard[i-1].score[1];
		Hard[i].score[2]=Hard[i-1].score[2];
	}
		Hard[Patok].Nama=newPlayer;
		Hard[Patok].score[0]=newScore[0];
		Hard[Patok].score[1]=newScore[1];
		Hard[Patok].score[2]=newScore[2];
	}
		gotoxy(0,16);
		printHard();
		SaveData();
		red(); cout<<"MENU>>"; blue();
		int jeda=getche();
}