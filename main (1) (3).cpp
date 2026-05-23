// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;

struct utente{
    double X;
    double Y;
};

struct Ebike{
    
    bool disponibile;
    double X;
    double Y;
    double distanza;
    int ID;
    double autonomia;
};

int scelta;
int n=0;
int m = 0;
double lunghezza;

utente user = {0, 0};
Ebike bici[5];
Ebike bici_scelta;



double valore_bici(int n){
    
    if(n>4){
        return 0;
    }else if(n<0){
        cout<<"ERRORE"<<endl;
        return 0;
    }else{
        bici[n].disponibile = rand() % 2 + 0;
        bici[n].X = rand() % 100 + 1;
        bici[n].Y = rand() % 100 + 1;
        bici[n].distanza = sqrt(pow(bici[n].X-user.X,2)+pow(bici[n].Y-user.Y,2));
        bici[n].ID = n+1;
        bici[n].autonomia = rand() % 40 + 0;
        return valore_bici(n+1);
    }
}

bool confronta(Ebike bici1, Ebike bici2){
    return bici1.distanza < bici2.distanza;
}

void scelta_bici(){
   for(int i=0; i<=4; i++){
        if(scelta==bici[i].ID){
            bici_scelta=bici[i];
            cout<<"hai scelto la bici n. "<<i<<endl;
        }else if(scelta>5){
            cout<<"ID non valido"<<endl;
        }
    }  
}

int calcolo_tempo(double lunghezza){
    double tempo=((lunghezza/20.0)*60);///+rand() % 15 + 1;
    return tempo;
}

void menù(){
    
    cout<<"#####################################"<<endl;
    cout<<"|   Bici   |   ID   |   autonomia   |"<<endl;
    cout<<"|----------|--------|---------------|"<<endl;
    if((bici[0].autonomia>9)&&(bici[0].disponibile==true)){
        cout<<"|     1    |   "<<bici[0].ID<<"    |      "<<bici[0].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;

    }else if((bici[0].autonomia<=9)&&(bici[0].disponibile==true)){
        cout<<"|     1    |   "<<bici[0].ID<<"    |       "<<bici[0].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;
    }
    if((bici[1].autonomia>9)&&(bici[1].disponibile==true)){
        cout<<"|     2    |   "<<bici[1].ID<<"    |      "<<bici[1].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;

    }else if((bici[1].autonomia<=9)&&(bici[1].disponibile==true)){
        cout<<"|     2    |   "<<bici[1].ID<<"    |       "<<bici[1].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;
    }
    if((bici[2].autonomia>9)&&(bici[2].disponibile==true)){
        cout<<"|     3    |   "<<bici[2].ID<<"    |      "<<bici[2].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;


    }else if((bici[2].autonomia<=9)&&(bici[2].disponibile==true)){
        cout<<"|     3    |   "<<bici[2].ID<<"    |       "<<bici[2].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;
    }
    if((bici[3].autonomia>9)&&(bici[3].disponibile==true)){
        cout<<"|     4    |   "<<bici[3].ID<<"    |      "<<bici[3].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;
        
    }else if((bici[3].autonomia<=9)&&(bici[3].disponibile==true)){
        cout<<"|     4    |   "<<bici[3].ID<<"    |       "<<bici[3].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;
    }
    if((bici[4].autonomia>9)&&(bici[4].disponibile==true)){
        cout<<"|     5    |   "<<bici[4].ID<<"    |      "<<bici[4].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;
    }else if((bici[4].autonomia<=9)&&(bici[4].disponibile==true)){
        cout<<"|     5    |   "<<bici[4].ID<<"    |       "<<bici[4].autonomia<<"       |"<<endl;
        cout<<"|----------|--------|---------------|"<<endl;

    }
}


int main(){
    std::srand(std::time({}));
    valore_bici(n);
    std::sort(bici, bici+5, confronta); 
    
    for(int i=0; i<=4; i++){
        if(bici[i].autonomia==0){
            bici[i].disponibile=false;
        }
    }
   /// while()
    menù();
    for(int i=0; i<=4; i++){
        if(bici[i].disponibile==true){
            cout<<"bici n: "<<bici[i].ID<<" è a "<<bici[i].distanza<<"m ed è in cordinate X: "<<bici[i].X<<" ed Y: "<<bici[i].Y<<endl;
             cout<<""<<endl;
        }
       
    }
    cout<<""<<endl;
    cin>>scelta;
    
    cout<<""<<endl;
    scelta_bici();
    
    cout<<"quanti km devi percorrere?"<<endl;
    cin>>lunghezza;
    
    for(int i; i<1 ; i++){
        if(bici_scelta.autonomia<lunghezza){
            cout<<"autonomia insufficente"<<endl;
        }else{
            cout<<"bici prenotata"<<endl;
        }
    }
    double tempo = calcolo_tempo(lunghezza);
    
    bici_scelta.autonomia=bici_scelta.autonomia-lunghezza;
    
    double prezzo$=tempo*0.20;
    
    cout<<"tempo noleggio: "<<tempo<<" per "<<lunghezza<<" km ed un prezzo di "<<prezzo$<<endl;

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}