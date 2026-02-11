/*
RICORDATE:
!!!!!!!!!NON PUBBLICARE GLI ESEGUIBILI :D!!!!!!!!!!!
Se create un nuovo menù ricordatevi di aggiungere il suo id in posizioni valide 
e un case dentro lo swirch E, di incrementare lungPosizioniValide
~Cris
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
    //variabili di sistema (gestiscono il programma)
    bool esci=false, chiediSel=false, messagiDEBUG=true;
    int posizioniValide[]={-1,0},  lungPosizioniValide=2;//<----------- inserite qui i nuovi id -Cris
    int posizioneUtente=0;

    //variabili di dati utente(immagazzinano info sull'utente)

    //APP
    while(!esci){
        while(chiediSel){
            chiediSel=true;
            cout<<"=>";
            cin>>posizioneUtente;
            for(int i=0; i<lungPosizioniValide; i++){
                if(posizioneUtente==posizioniValide[i]) {
                    chiediSel=false;
                    break;
                }
            }
            if(chiediSel) cout<<"Selezione non valida riprovare\n";
        }
        chiediSel=true;

        switch (posizioneUtente){
            case -1:
                esci=true;
                cout<<"Grazie per aver usato deliveroo!!!\n";
                if(messagiDEBUG) cout<<"DEBUG:uscita del programma\n";
                break;

                
            case 0://menu principale
                cout<<"#####################################################"<<endl;
                cout<<"||@@@@  @@@@@ @     @ @   @ @@@@@ @@@@   @@@   @@@ ||"<<endl;
                cout<<"||@   @ @     @     @ @   @ @     @   @ @   @ @   @||"<<endl;
                cout<<"||@   @ @@@@@ @     @ @   @ @@@@@ @@@@  @   @ @   @||"<<endl;
                cout<<"||@   @ @     @     @  @ @  @     @ @   @   @ @   @||"<<endl;
                cout<<"||@@@@  @@@@@ @@@@@ @   @   @@@@@ @  @   @@@   @@@ ||"<<endl;
                cout<<"#####################################################"<<endl;
                cout<<"Benvenuti su deliveroo"<<endl;
                cout<<"Digita 0 per vedere questa schermata"<<endl;
                cout<<"Digita -1 per uscire dal programma"<<endl;
                break;

    
            default:
                cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                cout<<"OPZIONE NON VALIDA, NON DOVRESTI RIUSCIRCI AD ARRIVARE QUI"<<endl;
                cout<<"C'E QUALCOSA CHE NON VA NELLO SWITCH O NEL VETTORE"<<endl;
                cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                esci=true;

        }
        if(messagiDEBUG) cout<<"DEBUG:Eseguito un ciclo\n";
        
    }
}