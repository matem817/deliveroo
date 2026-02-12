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
    bool esci=false, messaggiDEBUG=true;
    int posizioneUtente=0;
    int sceltaMenuImpostazioni; //variabile utilizzata per lo switch del menu delle impostazioni dell'utente
    int codiceRistorante=0;

    //variabili di dati utente(immagazzinano info sull'utente)
    	//menu nome
			char nome[30];
    	//menu metodoPagamento
			int metodoPagamentoPreferito=0; //0: Contanti, 1: Carta di credito, 2: Paypal, 3: mangi gratis
			int sceltaMenuPagamento;
			int cartaCredito[16], cvv;
			char nomeCarta[15], cognomeCarta[15];
			char utentePaypal[30];
    


    //APP
    while(!esci){
		
		menuPrincipale:
		cout<<"#####################################################"   <<endl
		    <<"||@@@@  @@@@@ @     @ @   @ @@@@@ @@@@   @@@   @@@ ||"   <<endl
		    <<"||@   @ @     @     @ @   @ @     @   @ @   @ @   @||"   <<endl
		    <<"||@   @ @@@@@ @     @ @   @ @@@@@ @@@@  @   @ @   @||"   <<endl
		    <<"||@   @ @     @     @  @ @  @     @ @   @   @ @   @||"   <<endl
		    <<"||@@@@  @@@@@ @@@@@ @   @   @@@@@ @  @   @@@   @@@ ||"   <<endl
		    <<"#####################################################"   <<endl
		    <<"Benvenuti su deliveroo"                                  <<endl
            <<"Digita 1 per accedere alla mappa ristoranti"             <<endl
		    <<"Digita 2 per accedere al menu delle impostazioni"        <<endl
		    <<"Digita 0 per uscire dal programma"                       <<endl;

		chiediInput:
			cout<<"=>";
			cin>>posizioneUtente;
			if(posizioneUtente<0||posizioneUtente>2) {
				cout<<"Selezione non valida riprovare\n";
				goto chiediInput;
			}

        switch (posizioneUtente){
			case 0:
                esci=true;
                cout<<"Grazie per aver usato deliveroo!!!\n";
                if(messaggiDEBUG) cout<<"DEBUG:uscita del programma\n";
                break;
            case 1:
                //mappaRistoranti:
                cout<<"|  |Via Torvalds                |  |    #@#  CODICE\t-\tNEGOZI"<<endl
                    <<"|  |*    *            **********|  |    #@#  ----------------------------------------"<<endl
                    <<"|  |* 06 *            *        *|  |    #@#  1\t\t-\tMcDonalds"<<endl
                    <<"|  |******            *     05 *|  |    #@#  ----------------------------------------"<<endl
                    <<"|  |******            *        *|  |    #@#  2\t\t-\tSuper Kebab"<<endl
                    <<"|  |*    *            **********|  |    #@#  ----------------------------------------"<<endl
                    <<"|  |*    *                 *****|  |    #@#  3\t\t-\tSushi Zen"<<endl
                    <<"|  |******                 *   *|  |    #@#  ----------------------------------------"<<endl
                    <<"|  |******                 * 04*|  |    #@#  "<<endl
                    <<"|  |* 07 *                 *   *|  |    #@#  ----------------------------------------"<<endl
                    <<"|  |*    *                 *****|  |    #@#  "<<endl
                    <<"|  |******  ********** *********|  |    #@#  ----------------------------------------"<<endl
                    <<"|  |******  *        * *     03*|  |    #@#  "<<endl
                    <<"|  |*    *  *        * *********|  |    #@#  ----------------------------------------"<<endl
                    <<"|  |*    *  *        *          |  |    #@#  "<<endl
                    <<"|  |******  *        *  ********|  |    #@#  "<<endl
                    <<"|  |******* *        *  *      *|  |    #@#  "<<endl
                    <<"|  |*     * *   01   *  *   02 *|  |    #@#  "<<endl
                    <<"|  |*     * *        *  *      *|  |    #@#  "<<endl
                    <<"|  |******* **********  ********|  |    #@#  "<<endl
                    <<"|  |____________________________/  |    #@#  "<<endl
                    <<"|  |______________________________/     #@#  "<<endl
                    <<"|  |Via Bjarne *****************        #@#  "<<endl;
                cout<<"Selezionare il ristorante da cui ordinare.(inserire 0 per tornara al menu' principale)"<<endl;
                    chiediInputRistorante:
			        cout<<"=>";
			        cin>>codiceRistorante;
                    if(codiceRistorante<0||codiceRistorante>7) {
                        cout<<"Selezione non valida riprovare\n";
                        goto chiediInputRistorante;
                    }
                    switch(codiceRistorante){
                        case 0:
                            goto menuPrincipale;
                        case 1:
                            cout<<"Hai selezionato come ristorante McDonald, cosa vuoi ordinare dal suo menù?"<<endl;
                            break;
                        case 2:
                            cout<<"Hai selezionato come ristorante Super Kebab, cosa vuoi ordinare dal suo menù?"<<endl;
                            break;
                        case 3:
                            cout<<"Hai selezionato come ristorante Sushi Zen, cosa vuoi ordinare dal suo menù?"<<endl;
                            break;
                    }
                break;
            case 2: //menu dati personali utente
                menuDatiPersonali:
				cout<<endl<<"In questo menu puoi inserire i tuoi dati personali."<<endl
                	<<"Scegli cosa fare tra le opzioni qua sotto: "<<endl
                	<<"1 - Inserisci il nome da visualizzare quando esegui degli ordini."<<endl
                	<<"2 - Metodo di pagamento predefinito"<<endl
                	<<"0 - Torna al menu principale. "<<endl;
                
                inputMenuImpostazioni:
			    cout<<"=>";
			    cin>>sceltaMenuImpostazioni;
                if(sceltaMenuImpostazioni<0||sceltaMenuImpostazioni>2) {
                    cout<<"Selezione non valida riprovare\n";
                    goto inputMenuImpostazioni;
                }

                switch(sceltaMenuImpostazioni){ //MENU IMPOSTAZIONI
                    case 1://Inserimento nome utente
                        cout<<"Inserisci il tuo nome (premi invio ad ogni lettera, inserisci 0 quando hai concluso): ";
                        for(int i=0; i<30; i++){
                            cin>>nome[i];
                            if(nome[i]=='0') break;
                        }
						cout<<endl
							<<"Il nome inserito è:";
						for(int i=0; i<30; i++){
							if(nome[i]=='0') break;
							cout<<nome[i];
						}
						cout<<"."<<endl;
						goto menuDatiPersonali;
                        break;
                    case 2://metodo di pagamento preferito
                    	menuPagamentoPreferito:
                        cout<<endl
						    <<"Metodo di pagamento attuale: ";
                    	switch(metodoPagamentoPreferito){ //output metodo di pagamento preferito
                    		case 0:
                    			cout<<"contanti.";
                    			break;
                    		case 1://PRINT INFO CARTA DI CREDITO
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
									<<"	Carta di credito: ";
                                    for(int j=0; j<4;j++){
                                        for(int i=0; i<5;i++) cout<<"*";
                                        cout<<"-";
                                    }
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
								cout<<endl;
								if(messaggiDEBUG) cout<<"DEBUG: Errore nella variabile metodoPagamentoPreferito."<<endl;
						}
                        cout<<endl
                            <<"Scegli cosa vuoi fare: "<<endl
							<<"1 - Imposta metodo di pagamento preferito."<<endl
							<<"0 - Torna al menu delle impostazioni."<<endl;
						inputMenuMetodoPagamento:
                        cout<<"=>";
                        cin>>sceltaMenuPagamento;
                        if(sceltaMenuPagamento!=0 && sceltaMenuPagamento!=1) {
                            cout<<"Selezione non valida riprovare\n";
                            goto inputMenuMetodoPagamento;
                        }
						
						switch(sceltaMenuPagamento){//Menu metodi di pagamento
							case 1:
								do{
									cout<<endl
                                        <<"Metodi di pagamento accettati: "<<endl
										<<"0 - Contanti"<<endl
										<<"1 - Carta di Credito"<<endl
										<<"2 - Paypal"<<endl
										// 3 - Gold Card (mangi gratis)
										<<"=> ";
									cin>>metodoPagamentoPreferito;
								}while(metodoPagamentoPreferito>3 or metodoPagamentoPreferito<0);
								
								switch(metodoPagamentoPreferito){
									case 0: //contanti
										cout<<"Hai selezionato il pagamento con contanti."<<endl;
										break;
										
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
										break;
									case 2: //paypal
										cout<<"Hai selezionato il pagamento tramite PayPal"<<endl
											<<"Inserisci il tuo nome utente: (premi invio ad ogni lettera, inserisci 0 quando hai concluso)";
										for (int i=0; i<30; i++){
											cin>>utentePaypal[i];
											if(utentePaypal[i] == '0') break;
										}
										break;
									case 3: //gold card
										cout<<"Hai inserito il metodo di pagamento tramite Gold Card. Mangi gratis!"<<endl
											<<"(Il governo non vuole che tu sappia questo trucco #adv)"<<endl;
										break;		
								}
								goto menuPagamentoPreferito;
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
                cout<<"OPZIONE NON VALIDA, NON DOVRESTI RIUSCIRE AD ARRIVARE QUI"<<endl;
                cout<<"C'E QUALCOSA CHE NON VA NELLO SWITCH O NELLA VALIDAZIONE INPUT"<<endl;
                cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                esci=true;

        }
        if(messaggiDEBUG) cout<<"DEBUG:Eseguito un ciclo\n";
        
    }
}
