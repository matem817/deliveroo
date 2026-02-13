/*
RICORDATE:
!!!!!!!!!NON PUBBLICARE GLI ESEGUIBILI :D!!!!!!!!!!!
~Cris
TODO:
	AGGIUNGERE ALTRI RISTORANTI CON I LORO PRODOTTI
	AGGIUNGERE LA SEZIONE VISUALIZZA CARRELLO NEL MENU RISTORANTI
		con rimozione item dal carrello
		visualizzazione prezzi per il singolo item
		scelta metodo di pagamento (il primo è il predefinito [COME CAZZO FAREMO BHO])
			se in contanti specificare al rider quanti soldi si daranno
	SUICIDARSI/kurt kobain pov
	AGGIUNGERE nella visualizzazione del carrello le varie scelte
		1) concludere l'ordine e pagare
		2) tornare al menu dei ristoranti
		3) tornare al menu principale
		
	AGGIUNGERE UN SISTEMA PER PULIRE LO SCHERMO DOPO OGNI MENU(stampare una IMMANE quantità di endl)
	
COMPITI ATTUALI:
	CRISTIAN: Abbellimento menù dei singoli ristoranti con aggiunta di annesse funzioni.
	MATTIA: menu carrello
	ANDREA:
COMMENTI:
	bho
	che codice di merda :D
	per dio testate il codice prima di fare commit
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
	int scelta; //variabile da usare per tutti i menù di scelta (Il suo valore non dovrà mai essere chiamato prima di cin>>scelta;)
	char sceltaSN='n';

	//menu Ristoranti
    	int codiceRistorante=0;
		int piattoScelto;

	//Dati Ristoranti (vedi Docs.txt #1)
		int dimPartizione=38;
		char piattiMC[]={
			'1',')','M','c','M','e','n','u',' ','G','r','a','n',' ','C','r','i','s','p','y',' ','M','c','B','a','c','o','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'2',')','2',' ','M','c','M','e','n','u',' ','L','a','r','g','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'3',')','M','c','M','e','n','u',' ','C','B','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'4',')','M','c','M','e','n','u',' ','1','9','5','5',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'5',')','M','c','M','e','n','u',' ','D','o','u','b','l','e',' ','C','h','i','k','e','n',' ','B','B','Q',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'6',')','M','c','M','e','n','u',' ','M','c','R','o','y','a','l',' ','D','e','l','u','x','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		};
		char piattiSK[]={
        	'1',')','K','e','b','a','b',' ','C','o','m','p','l','e','t','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        	'2',')','P','i','a','d','i','n','a',' ','K','e','b','a','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        	'3',')','P','a','n','i','n','o',' ','F','a','l','a','f','e','l',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'4',')','V','a','s','c','h','e','t','t','a',' ','K','e','b','a','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'5',')','P','a','t','a','t','i','n','e',' ','F','r','i','t','t','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'6',')','B','i','b','i','t','a',' ','a',' ','s','c','e','l','t','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };
        int quantitaPiatto;
	
    //variabili di dati utente(immagazzinano info sull'utente)
    	//menu nome
			char nome[30];
    	//menu metodoPagamento
			int metodoPagamentoPreferito=0; //0: Contanti, 1: Carta di credito, 2: Paypal, 3: mangi gratis
			int sceltaMenuPagamento;
			int cartaCredito[16], cvv;
			char nomeCarta[15], cognomeCarta[15];
			char utentePaypal[30];
		//ordini
			int carrello[15], ultimaPosOccupataCarrello=0;

	//menu carrello
		int totale, importo, resto=totale-importo;

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
            <<"Digita 1 per vedere i ristoranti vicino a te"            <<endl
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
			/*	
				###################################################################
									MENU RISTORANTI
				###################################################################
			*/
            case 1:
                menuRistoranti:
				cout<<"################################################################################"<<endl
					<<"#                                                                              #"<<endl
					<<"#  IN PRIMO PIANO                                                              #"<<endl
					<<"#                                                                              #"<<endl
					<<"# ++++++++++++++++++  ++++++++++++++++++  ++++++++++++++++++                   #"<<endl
					<<"# +   ___   _  __  +  +  ___ _         +  +  ___ _  __ ____+                   #"<<endl
					<<"# +  / __| | |/ /  +  + / __| |        +  + | _ \\ |/ /|_  /+                   #"<<endl
					<<"# +  \\__ \\ | ' <   +  + \\__ \\ |__      +  + |  _/ ' <  / / +                   #"<<endl
					<<"# +  |___/ |_|\\_\\  +  + |___/____|     +  + |_| |_|\\_\\/___|+                   #"<<endl
					<<"# ++++++++++++++++++  ++++++++++++++++++  ++++++++++++++++++                   #"<<endl
					<<"# 1) Super kebab      2) Sushi Line       3) Pokè zen                          #"<<endl
					<<"#                                                                              #"<<endl
					<<"# ++++++++++++++++++  ++++++++++++++++++  ++++++++++++++++++                   #"<<endl
					<<"# +  __  __  ___   +  +   _      _     +  +   ___ ___  ____+                   #"<<endl
					<<"# + |  \\/  |/ __|  +  +  | |    /_\\    +  +  / __| _ \\|_  /+                   #"<<endl
					<<"# + | |\\/| | (__   +  +  | |__ / _ \\   +  + | (_ |   / / / +                   #"<<endl
					<<"# + |_|  |_|\\___|  +  +  |____/_/ \\_\\  +  +  \\___|_|_\\/___|+                   #"<<endl
					<<"# ++++++++++++++++++  ++++++++++++++++++  ++++++++++++++++++                   #"<<endl
					<<"# 4) McDonalds        5) La piadineria    6) Da Graziella                      #"<<endl
					<<"#                                                                              #"<<endl
					<<"#  0) Menu iniziale           |(7) <= PAG 0 => (8)|   9) Visualizza carrello   #"<<endl
					<<"################################################################################"<<endl;
				chiediInputRistorante:
				cout<<"=>";
				cin>>codiceRistorante;
				if(codiceRistorante<0||codiceRistorante>9) {
					cout<<"Selezione non valida riprovare\n";
					goto chiediInputRistorante;
				}
				switch(codiceRistorante){
					case 0:
						goto menuPrincipale;
					case 1:
                        superKebab:
                        cout<<"################################################################################"<<endl
                            <<"#  ____  _   _ ____  _____ ____      _  _______ ____    _    ____              #"<<endl
                            <<"# / ___|| | | |  _ \\| ____|  _ \\    | |/ / ____| __ )  / \\  | __ )             #"<<endl
                            <<"# \\___ \\| | | | |_) |  _| | |_) |   | ' <|  _| |  _ \\ / _ \\ |  _ \\             #"<<endl
                            <<"#  ___) | |_| |  __/| |___|  _ <    | . \\| |___| |_) / ___ \\| |_) |            #"<<endl
                            <<"# |____/ \\___/|_|   |_____|_| \\_\\   |_|\\_\\_____|____/_/   \\_\\____/             #"<<endl
                            <<"#                                                                              #"<<endl
                            <<"# Consegna tra 15-30 minuti                                                    #"<<endl;

                        for(int i=0; i<6;i++){
                            cout<<"#------------------------------------------------------------------------------#"<<endl;
                            cout<<"#";
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiSK[x];
                            cout<<"| ";
                            i++;
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiSK[x];
                            cout<<"#"<<endl;
                        }
                        cout<<"#------------------------------------------------------------------------------#"<<endl;
						for(int i=0; i<4; i++){
							cout<<"#                                                                              #"<<endl;
						}
                        cout<<"# 0) Torna al menu Ristoranti                                                  #"<<endl
                            <<"################################################################################"<<endl
                            <<"Selezionare la pietanza da aggiungere al carrello"<<endl
                            <<"=>";
                        cin>>piattoScelto;

                        if(piattoScelto==0) goto menuRistoranti;

                        while(piattoScelto<0||piattoScelto>6){
                            cout<<"Selezione non valida riprovare"<<endl<<"=>";
                            cin>>piattoScelto;
                        }

						cout<<"E stato scelto "<<endl;
						for(int x=(piattoScelto-1)*dimPartizione; x<dimPartizione*(piattoScelto); x++) cout<<piattiSK[x];
						cout<<endl;

                        cout<<"Quante unita' di questo piatto vuoi ordinare? ";
                        cin>>quantitaPiatto;

                        for(int k=0; k<quantitaPiatto; k++){
                            if(ultimaPosOccupataCarrello<15){
                                carrello[ultimaPosOccupataCarrello++]=10+piattoScelto; 
                            } else {
                                break; 
                            }
                        }

                        if(ultimaPosOccupataCarrello<15){
							cout<<"Vuoi ordinare qualcosaltro da SuperKebab?(S/n): ";
							cin>>sceltaSN;
							switch(sceltaSN){
								case 'n':
								case 'N':
									goto menuRistoranti;
									break;
								default:
									goto superKebab;
							}

							goto mcDonalds;
							break;
						}else{
							cout<<"Il tuo carrello è pieno!!!"<<endl
								<<"Sarai reindirizzato al menù ristoranti dove portrai concludere l'ordine"<<endl;
							goto menuRistoranti;	
						}
                    
                     
					case 3:
						cout<<"Hai selezionato come ristorante Sushi Zen, cosa vuoi ordinare dal suo menù?"<<endl;
						break;
					case 4:
						mcDonalds:
						cout<<"################################################################################"<<endl
							<<"# __  __         ____                    _     _                               #"<<endl
							<<"#|  \\/  | ___   |  _ \\  ___  _ __   __ _| | __| |___                           #"<<endl
							<<"#| |\\/| |/ __|  | | | |/ _ \\| '_ \\ / _` | |/ _` / __|                          #"<<endl
							<<"#| |  | | (__   | |_| | (_) | | | | (_| | | (_| \\__ \\                          #"<<endl
							<<"#|_|  |_|\\___|  |____/ \\___/|_| |_|\\__,_|_|\\__,_|___/                          #"<<endl
							<<"#                                                                              #"<<endl
							<<"#Consegna tra 10-25 minuti                                                     #"<<endl;

						for(int i=0; i<6;i++){
							cout<<"#------------------------------------------------------------------------------#"<<endl;
							cout<<"#";
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiMC[x];
							cout<<"| ";
							i++;
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiMC[x];
							cout<<"#"<<endl;
						}
						cout<<"#------------------------------------------------------------------------------#"<<endl;
						for(int i=0; i<4; i++){
							cout<<"#                                                                              #"<<endl;
						}
						cout<<"#                                                                              #"<<endl
							<<"# 0) Menu Principale                                                           #"<<endl
							<<"################################################################################"<<endl
							<<"Selezionare la pietanza da aggiungere al carrello"<<endl
							<<"=>";
						cin>>piattoScelto;
						while(piattoScelto<0||piattoScelto>6){
							cout<<"Selezione non valida riprovare"<<endl
								<<"=>";
							cin>>piattoScelto;
						}
						//decremento perche le partizioni partono da 0 non da 1 :D 
						cout<<"E stato scelto "<<endl;
						for(int x=(piattoScelto-1)*dimPartizione; x<dimPartizione*(piattoScelto); x++) cout<<piattiMC[x];
						cout<<endl;

						cout<<"Quante unita' di questo piatto vuoi ordinare? ";
                        cin>>quantitaPiatto;

                        for(int k=0; k<quantitaPiatto; k++){
                            if(ultimaPosOccupataCarrello<15){
                                carrello[ultimaPosOccupataCarrello++]=40+piattoScelto; 
                            } else {
                                break; 
                            }
                        }
						
						cout<<endl<<"Aggiunto al carrello."<<endl;

						if(ultimaPosOccupataCarrello<15){
							cout<<"Vuoi ordinare qualcosaltro da McDonalds?(S/n): ";
							cin>>sceltaSN;
							switch(sceltaSN){
								case 'n':
								case 'N':
									goto menuRistoranti;
									break;
								default:
									goto mcDonalds;
							}

							goto mcDonalds;
							break;
						}else{
							cout<<"Il tuo carrello è pieno!!!"<<endl
								<<"Sarai reindirizzato al menù ristoranti dove portrai concludere l'ordine"<<endl;
							goto menuRistoranti;	
						}
					case 9: // SEZIONE CARRELLO 
						cout<<"--- CARRELLO ATTUALE ---"<<endl;
						cout<<"PRODOTTO\t\t\t\tRISTORANTE"<<endl;
						if(ultimaPosOccupataCarrello==0) cout<<"Vuoto!"<<endl;
						for(int i=0; i<ultimaPosOccupataCarrello; i++){
							int id=carrello[i];
							if(id>10 && id<20){ // Piatti Super Kebab (11-16)
								int p=id-11;
								cout<<"- ";
								for(int x=p*dimPartizione+2; x<dimPartizione*(p+1); x++) cout<<piattiSK[x];
								cout<<"\tSuper Kebab"<<endl;
							}
							if(id>40 && id<50){ // Piatti McDonalds (41-46)
								int p=id-41;
								cout<<"- ";
								for(int x=p*dimPartizione+2; x<dimPartizione*(p+1); x++) cout<<piattiMC[x];
								cout<<"\tMcDonalds"<<endl;
							}
						}

						cout<<"Scegli una tra le seguenti opzioni: "<<endl
							<<"1 - Ordina e paga"<<endl
							<<"2 - Torna al menu dei ristoranti"<<endl
							<<"3 - Torna al menu principale"<<endl
							<<"=> ";
						cin>>scelta;

						switch(scelta){
							case 1:
								cout<<"Pagherai tramite: ";
								switch(metodoPagamentoPreferito){
									case 0:
										cout<<"contanti. Inserisci l'importo che consegnerai al rider per il calcolo del resto: ";
										cin>>importo;
										if(importo==0) break;
										cout<<"Riceverai "<<resto<<" euro di resto";
										break;
									case 1:
										cout<<"carta. "<<endl<<"Verifica se le informazioni sono corrette: "<<endl;
								}
						}
				
					goto menuRistoranti;
					
                }
            	break;
					
			
			/*	
				###################################################################
									MENU DATI PERSONALI UTENTE
				###################################################################
			*/
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
                        cout<<"Inserisci il tuo nome (inserisci 0 e premi invio quando hai concluso): ";
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
