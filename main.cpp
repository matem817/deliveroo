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
1=menu dati personali dell'utente
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    //variabili di sistema (gestiscono il programma)
    bool esci=false, chiediSel=false, messagiDEBUG=true;
    int posizioniValide[]={-1,0, 1},  lungPosizioniValide=3;//<----------- inserite qui i nuovi id -Cris
    int posizioneUtente=0;
    int sceltaMenuImpostazioni; //variabile utilizzata per lo switch del menu delle impostazioni dell'utente

    //variabili di dati utente(immagazzinano info sull'utente)
    char nome[15];


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
                cout<<"Digita 1 per accedere al menu delle impostazioni"<<endl;
                cout<<"Digita -1 per uscire dal programma"<<endl;
                break;

            case 1: //menu dati personali utente
                cout<<endl<<"In questo menu puoi inserire i tuoi dati personali."<<endl;
                cout<<"Scegli cosa fare tra le opzioni qua sotto: "<<endl;
                cout<<"1 - Inserisci il nome da visualizzare quando esegui degli ordini."<<endl;
                cout<<"2 - Inserisci un metodo di pagamento predefinito"<<endl;
                cout<<"0 - Torna al menu principale. ";
                cout<<endl<<"=> ";
                cin>>sceltaMenuImpostazioni;

                switch(sceltaMenuImpostazioni){
                    case 1:
                        cout<<"Inserisci il tuo nome (premi invio ad ogni lettera, inserisci 0 quando hai concluso): ";
                        for(int i=0; i<15; i++){
                            cin>>nome[i];
                            if(nome[i]=='0') break;
                        }
                        
                        if(messagiDEBUG){
                            cout<<endl;
                            for(int i=0; i<15; i++){
                                if(nome[i]=='0') break;
                                cout<<nome[i];
                            }
                            cout<<endl;
                        }
                        break;
                    
                    case 0:
                        posizioneUtente=0;
                        break;
                }

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