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

int scelta_bici(){
   for(int i=0; i<=4; i++){
        if(scelta==bici[i].ID){
            bici_scelta=bici[i];
            cout<<"hai scelto la bici n. "<<i<<endl;
            return 0;
        }else if((scelta>5)||(bici[i].disponibile==false)){
            cout<<"bici non disponibile"<<endl;
            return -1;
        }
        
    }  
}

int calcolo_tempo(double lunghezza){
    double tempo=((lunghezza/20.0)*60);///+rand() % 15 + 1;
    return tempo;
}

void menù(){
    cout<<"####################################################################"<<endl;
    cout<<"|   bici   |   ID   |   autonomia   |   distanza   |   X   |   Y   |"<<endl;
    cout<<"|----------|--------|---------------|--------------|-------|-------|"<<endl;
    cout<<"|     1    |   "<<bici[0].ID<<"    |       "<<bici[0].autonomia<<"      |   "<<bici[0].distanza<<"    |   "<<bici[0].X<<"  |   "<<bici[0].Y<<"  |"<<endl;
    cout<<"|----------|--------|---------------|--------------|-------|-------|"<<endl;
    cout<<"|     2    |   "<<bici[1].ID<<"    |       "<<bici[1].autonomia<<"      |    "<<bici[1].distanza<<"   |  "<<bici[1].X<<"   |    "<<bici[1].Y<<"   |"<<endl;
    cout<<"|----------|--------|---------------|--------------|-------|-------|"<<endl;
    cout<<"|     3    |   "<<bici[2].ID<<"    |       "<<bici[2].autonomia<<"      |   "<<bici[2].distanza<<"      |   "<<bici[2].X<<"   |   "<<bici[2].Y<<"   |"<<endl;
    cout<<"|----------|--------|---------------|--------------|-------|-------|"<<endl;
    cout<<"|     4    |   "<<bici[3].ID<<"    |       "<<bici[3].autonomia<<"   |   "<<bici[3].distanza<<"   |   "<<bici[3].X<<"   |   "<<bici[3].Y<<"   |"<<endl;
    cout<<"|----------|--------|---------------|--------------|-------|-------|"<<endl;
    cout<<"|     5    |   "<<bici[4].ID<<"    |      "<<bici[4].autonomia<<"       |   "<<bici[4].distanza<<"    |   "<<bici[4].X<<"   |   "<<bici[4].Y<<"   |"<<endl;
    cout<<"|----------|--------|---------------|--------------|-------|-------|"<<endl;
    cout<<"####################################################################"<<endl;
    
    

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

while(true){
    menù();
    cout<<"scegli una mobike"<<endl;
    cout<<""<<endl;
    cin>>scelta;
    
    cout<<""<<endl;
    if(scelta_bici()==-1){
        continue;
    }
    
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
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}