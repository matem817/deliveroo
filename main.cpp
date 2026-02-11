/*
TODO:

COMMENTI:
bho

POSIZIONI:
-1=esci da programa
0=menu principale
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    bool esci=false, chiediSel=true, messagiDEBUG=true;
    int posizioneUtente=0, posizioniValide[]={0}, lungPosizioniValide=1;
    while(!esci){
        switch posizioneUtente{
            case -1:
                esci=true;
                if(messagiDEBUG) cout<<"uscita del programma\n";
                break;
            case 0://menu principale
                break;
        }
        while(chiediSel){
            cout<<"=>";
            cin>>pos;
            bool valido=false;
            for(int i=0; i<lungPosizioniValide; i++){
                if(pos==posizioniValide[i]) {
                    valido=true;
                    break;
                }
            }
        }
    }
}