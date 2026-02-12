/*
RICORDATE:
!!!!!!!!!NON PUBBLICARE GLI ESEGUIBILI :D!!!!!!!!!!!
Se create un nuovo menù ricordatevi di aggiungere il suo id in posizioni valide 
e un case dentro lo swirch E, di incrementare lungPosizioniValide
~Cris
TODO:
	fixare TUTTI I MENU dove manca il cout

COMMENTI:
bho
che codice di merda :D

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
    bool esci=false, chiediSel=false, messaggiDEBUG=true;
    int posizioniValide[]={-1,0, 1},  lungPosizioniValide=3;//<----------- inserite qui i nuovi id -Cris
    int posizioneUtente=0;
    int sceltaMenuImpostazioni; //variabile utilizzata per lo switch del menu delle impostazioni dell'utente

    //variabili di dati utente(immagazzinano info sull'utente)
    	//menu nome
			char nome[15];
    	//menu metodoPagamento
			int metodoPagamentoPreferito=0; //0: Contanti, 1: Carta di credito, 2: Paypal, 3: mangi gratis
			int sceltaMenuPagamento;
			int cartaCredito[16], cvv;
			char nomeCarta[15], cognomeCarta[15];
			char utentePaypal[30];
    


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
                if(messaggiDEBUG) cout<<"DEBUG:uscita del programma\n";
                break;

                
            case 0://menu principale
                menuPrincipale:
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
                menuDatiPersonali:
				cout<<endl<<"In questo menu puoi inserire i tuoi dati personali."<<endl
                	<<"Scegli cosa fare tra le opzioni qua sotto: "<<endl
                	<<"1 - Inserisci il nome da visualizzare quando esegui degli ordini."<<endl
                	<<"2 - Inserisci un metodo di pagamento predefinito"<<endl
                	<<"0 - Torna al menu principale. "<<endl
                	<<"=> ";
                cin>>sceltaMenuImpostazioni;

                switch(sceltaMenuImpostazioni){
                    case 1://Inserimento nome utente
                        cout<<"Inserisci il tuo nome (premi invio ad ogni lettera, inserisci 0 quando hai concluso): ";
                        for(int i=0; i<15; i++){
                            cin>>nome[i];
                            if(nome[i]=='0') break;
                        }
                        
                        if(messaggiDEBUG){
                            cout<<endl;
                            for(int i=0; i<15; i++){
                                if(nome[i]=='0') break;
                                cout<<nome[i];
                            }
                            cout<<endl;
                        }
                        break;
                    case 2://metodo di pagamento preferito
                    	menuPagamentoPreferito:
						cout<<"Metodo di pagamento attuale: ";
                    	switch(metodoPagamentoPreferito){
                    		case 0:
                    			cout<<"contanti."<<endl;
                    			break;
                    		case 1:
                    			cout<<"carta di credito."<<endl
                    				<<"	Nome e Cognome sulla carta: ";
                    				for(int i=0; i<15; i++){
                    					if(nomeCarta[i]=='0') break;
										cout<<nomeCarta[i];
									}
								cout<<" ";
									for(int i=0; i<15; i++){
										if(cognomeCarta[i]=='0') break;
										cout<<cognomeCarta[i];
									}
								cout<<endl
									<<"	Ultime 4 cifre della carta: ";
									for(int i=12; i<16; i++){									
										cout<<cartaCredito[i];
									}
								cout<<endl;
								break;
							case 2:
								cout<<"Paypal."
									<<endl<<"	Nome utente: ";
									for (int i=0; i<30; i++){
										if(utentePaypal[i] == '0') break;
										cout<<utentePaypal[i];										
									}
								break;
							case 3:
								cout<<"gold card (mangi gratis).";
								break;
							default:
								if(messaggiDEBUG) cout<<"DEBUG: Errore nella variabile metodoPagamentoPreferito."<<endl;
						}
						cout<<endl
							<<"Scegli cosa vuoi fare: "<<endl
							<<"1 - Imposta metodo di pagamento preferito."<<endl
							<<"0 - Torna al menu delle impostazioni."<<endl
							<<"=> ";
						cin>>sceltaMenuPagamento;
						
						switch(sceltaMenuPagamento){
							case 1:
								do{
									cout<<"Metodi di pagamento accettati: "<<endl
										<<"0 - Contanti"<<endl
										<<"1 - Carta di Credito"<<endl
										<<"2 - Paypal"<<endl
										// 3 - Gold Card (mangi gratis)
										<<endl<<"=> ";
									cin>>metodoPagamentoPreferito;
								}while(metodoPagamentoPreferito>3 or metodoPagamentoPreferito<0);
								
								switch(metodoPagamentoPreferito){
									selezioneMetodoPagamento:
									case 0: //contanti
										cout<<"Hai selezionato il pagamento con contanti."<<endl;
										goto menuPagamentoPreferito;
									case 1: //carta di credito
										cout<<"Hai selezionato il pagamento tramite carta di credito."<<endl
											<<"Inserisci il numero di carta (numero per numero, premi invio per ogni numero): "<<endl;
										for (int i=0; i<16; i++){
											cin>>cartaCredito[i];
											if(cartaCredito[i]>9){
												cout<<"Non possono esserci doppie cifre nel numero della carta di credito. Reinserisci l'ultimo numero: "<<endl;
												i--;
											}
										}
										cout<<"Inserisci il CVV: ";
										cin>>cvv;
				                        
										cout<<"Inserisci il nome sulla carta (premi invio ad ogni lettera, inserisci 0 quando hai concluso): ";
				                        for(int i=0; i<15; i++){
				                            cin>>nomeCarta[i];
				                            if(nomeCarta[i]=='0') break;
				                        }
				                        cout<<"Inserisci il cognome sulla carta (premi invio ad ogni lettera, inserisci 0 quando hai concluso): ";
				                        for(int i=0; i<15; i++){
				                            cin>>cognomeCarta[i];
				                            if(cognomeCarta[i]=='0') break;
				                        }
										goto menuPagamentoPreferito;
									case 2: //paypal
										cout<<"Hai selezionato il pagamento tramite PayPal"<<endl
											<<"Inserisci il tuo nome utente: (premi invio ad ogni lettera, inserisci 0 quando hai concluso)";
										for (int i=0; i<30; i++){
											cin>>utentePaypal[i];
											if(utentePaypal[i] == '0') break;
										}
										goto menuPagamentoPreferito;
									case 3: //gold card
										cout<<"Hai inserito il metodo di pagamento tramite Gold Card. Mangi gratis!"<<endl;
										goto menuPagamentoPreferito;			
								}
							case 0:
								goto menuDatiPersonali;
						}
						
						
						
                    case 0:
                        goto menuPrincipale;
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
        if(messaggiDEBUG) cout<<"DEBUG:Eseguito un ciclo\n";
        
    }
}
