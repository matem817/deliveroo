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

	AGGIUNGERE MODIFICHE PIATTI PER MCDONALDS
		
	AGGIUNGERE UN SISTEMA PER PULIRE LO SCHERMO DOPO OGNI MENU(stampare una IMMANE quantità di endl)
	
COMPITI ATTUALI:
	CRISTIAN: Personalizzazione piatti
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

		float prezziarioMC[]={12.20,15.90,13.60,14.15,7.30,13.20};
		char piattiSK[]={
        	'1',')','K','e','b','a','b',' ','C','o','m','p','l','e','t','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        	'2',')','P','i','a','d','i','n','a',' ','K','e','b','a','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        	'3',')','P','a','n','i','n','o',' ','F','a','l','a','f','e','l',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'4',')','V','a','s','c','h','e','t','t','a',' ','K','e','b','a','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'5',')','P','a','t','a','t','i','n','e',' ','F','r','i','t','t','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'6',')','B','i','b','i','t','a',' ','a',' ','s','c','e','l','t','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };
		float prezziarioSK[]={12.00, 11.00, 7.00, 10.00, 6.00, 2.00};

		
        int quantitaPiatto;

		char piattiMC[]={
			'1',')','M','c','M','e','n','u',' ','G','r','a','n',' ','C','r','i','s','p','y',' ','M','c','B','a','c','o','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'2',')','2',' ','M','c','M','e','n','u',' ','L','a','r','g','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'3',')','M','c','M','e','n','u',' ','C','B','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'4',')','M','c','M','e','n','u',' ','1','9','5','5',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'5',')','M','c','M','e','n','u',' ','D','o','u','b','l','e',' ','C','h','i','k','e','n',' ','B','B','Q',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'6',')','M','c','M','e','n','u',' ','M','c','R','o','y','a','l',' ','D','e','l','u','x','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		};

        char piattiPZ[]={
            '1',')','P','o','k','e',' ','S','a','l','m','o','n','e',' ','S','p','i','c','y',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '2',')','P','o','k','e',' ','T','u','n','a',' ','E','x','o','t','i','c',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '3',')','P','o','k','e',' ','V','e','g','e','t','a','r','i','a','n','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '4',')','M','o','c','h','i',' ','M','i','s','t','i',' ','(','3','p','z',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '5',')','Z','u','p','p','a',' ','d','i',' ','M','i','s','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '6',')','A','c','q','u','a',' ','N','a','t','u','r','a','l','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };

        char piattiLP[]={
            '1',')','P','i','a','d','i','n','a',' ','C','r','u','d','o',' ','e',' ','S','q','u','a','c','q','u','e','r','o','n','e',' ',' ',' ',' ',' ',' ',' ',' ',
            '2',')','P','i','a','d','i','n','a',' ','C','o','t','t','o',' ','e',' ','F','o','n','t','i','n','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '3',')','P','i','a','d','i','n','a',' ','P','o','l','l','o',' ','G','r','i','g','l','i','a','t','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '4',')','P','i','a','d','i','n','a',' ','V','e','g','e','t','a','l','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '5',')','R','o','t','o','l','o',' ','N','u','t','e','l','l','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '6',')','B','i','b','i','t','a',' ','i','n',' ','L','a','t','t','i','n','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };
		
	
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
			int carrello[15], ultimaPosOccupataCarrello=-1;
			int opzioniPiatti[15*3];
			float costoItemCarrello[15];//costo di ogni item del carrello
			float sovrapprezzoItem=0;//Da utilizzare per il sovraprezzo delle modifiche

	//menu carrello
		int totale, importo, resto; //si capisce no? dai
		char indirizzoConsegna[150];

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

						//personalizzazione piatto
                        for(int k=0; k<quantitaPiatto; k++){ 
                            if(ultimaPosOccupataCarrello<15){
								ultimaPosOccupataCarrello++;
								carrello[ultimaPosOccupataCarrello]=10+piattoScelto;
								costoItemCarrello[ultimaPosOccupataCarrello]=prezziarioSK[piattoScelto-1];

								cout<<"Personalizzare il proprio menù"<<endl;
								switch (piattoScelto){
									case 1 ... 4:
										cout<<"Scegliere la dimensione:"<<endl
											<<"1-Grande\t\t+3,00"<<endl
											<<"2-Medio\t\t\t+2,90"<<endl
											<<"3-Piccolo\t\t+0,00"<<endl;
										cout<<"=>";
										cin>>scelta;
										while(scelta<1 or scelta>3){
											cout<<"Opzione invalida, riprovare."<<endl
											<<"=>";
											cin>>scelta;
										}
										opzioniPiatti[ultimaPosOccupataCarrello*3]=scelta;

										cout<<"Scegliere un contorno:"<<endl
											<<"1-Patatine\t\t+3,00"<<endl
											<<"2-Patate Piccanti\t+3,50"<<endl
											<<"3-Nessuno\t\t+0,00"<<endl;
										cout<<"=>";
										cin>>scelta;
										while(scelta<1 or scelta>3){
											cout<<"Opzione invalida, riprovare."<<endl
											<<"=>";
											cin>>scelta;
										}
										opzioniPiatti[ultimaPosOccupataCarrello*3+1]=scelta;

										cout<<"Scegliere una bibita:"<<endl
											<<"1-Acqua\t\t\t+0,00"<<endl
											<<"2-CocaCola\t\t+2,00"<<endl
											<<"3-Sprite\t\t+1,70"<<endl;
										cout<<"=>";
										cin>>scelta;
										while(scelta<1 or scelta>3){
											cout<<"Opzione invalida, riprovare."<<endl
											<<"=>";
											cin>>scelta;
										}
										opzioniPiatti[ultimaPosOccupataCarrello*3+2]=scelta;
										break;
									case 5:
										cout<<"Scegliere la dimensione:"<<endl
											<<"1-Grande\t\t+1,50"<<endl
											<<"2-Medio\t\t\t+0,50"<<endl
											<<"3-Piccolo\t\t+0,00"<<endl;
										cout<<"=>";
										cin>>scelta;
										while(scelta<1 or scelta>3){
											cout<<"Opzione invalida, riprovare."<<endl
											<<"=>";
											cin>>scelta;
										}
										opzioniPiatti[ultimaPosOccupataCarrello*3]=scelta;

										cout<<"Scegliere una salsa da aggiungere:"<<endl
											<<"1-Maionese\t\t+0,10"<<endl
											<<"2-Ketchup\t\t+0,10"<<endl
											<<"3-Nessuna\t\t+0,00"<<endl;
										cout<<"=>";
										cin>>scelta;
										while(scelta<1 or scelta>3){
											cout<<"Opzione invalida, riprovare."<<endl
											<<"=>";
											cin>>scelta;
										}
										opzioniPiatti[ultimaPosOccupataCarrello*3+1]=scelta;
										opzioniPiatti[ultimaPosOccupataCarrello*3+2]=0;
										break;
									case 6:
									cout<<"Scegliere la bibita:"<<endl
											<<"1-Acqua\t\t\t+0,00"<<endl
											<<"2-CocaCola\t\t+0,00"<<endl
											<<"3-Sprite\t\t+0,00"<<endl;
										cout<<"=>";
										cin>>scelta;
										while(scelta<1 or scelta>3){
											cout<<"Opzione invalida, riprovare."<<endl
											<<"=>";
											cin>>scelta;
										}
										opzioniPiatti[ultimaPosOccupataCarrello*3]=scelta;
										opzioniPiatti[ultimaPosOccupataCarrello*3+1]=scelta=0;
										opzioniPiatti[ultimaPosOccupataCarrello*3+2]=scelta=0;
										
										break;
									default:
										cout<<"##########ERRORE############"<<endl;
										cout<<"Errore nel menu personalizzaione piatto"<<endl;
										break;
								}
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
						pokeZen:
                        cout<<"--- MENU POKE ZEN ---"<<endl;
                        for(int i=0; i<6;i++){
                            cout<<"#";
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiPZ[x];
                            cout<<"| "; i++;
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiPZ[x];
                            cout<<"#"<<endl;
                        }
                        cout<<"Piatto (0 esce) =>"; cin>>piattoScelto;
                        if(piattoScelto==0) goto menuRistoranti;
                        cout<<"Quantita' =>"; cin>>quantitaPiatto;
                        for(int k=0; k<quantitaPiatto; k++){
                            if(ultimaPosOccupataCarrello<15) carrello[ultimaPosOccupataCarrello++]=30+piattoScelto;
                        }
                        cout<<"Continui qui? (s/n): "; cin>>sceltaSN;
                        if(sceltaSN=='s'||sceltaSN=='S') goto pokeZen; else goto menuRistoranti;
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
					
					break;
					case 5: // --- LA PIADINERIA ---
						laPiadineria:
						cout<<"--- MENU LA PIADINERIA ---"<<endl;
						for(int i=0; i<6;i++){
							cout<<"#";
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiLP[x];
							cout<<"| "; i++;
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiLP[x];
							cout<<"#"<<endl;
						}
						cout<<"Piatto (0 esce) =>"; cin>>piattoScelto;
						if(piattoScelto==0) goto menuRistoranti;
						cout<<"Quantita' =>"; cin>>quantitaPiatto;
						for(int k=0; k<quantitaPiatto; k++){
							if(ultimaPosOccupataCarrello<15) carrello[ultimaPosOccupataCarrello++]=50+piattoScelto;
						}
						cout<<"Continui qui? (s/n): "; cin>>sceltaSN;
						if(sceltaSN=='s'||sceltaSN=='S') goto laPiadineria; else goto menuRistoranti;
						break;
					
					/*
						---------------------------------------------------------
						@@@@@@@@@@@@@@@@@@@@ SEZIONE CARRELLO @@@@@@@@@@@@@@@@@@@
						---------------------------------------------------------
					*/
					case 9: // SEZIONE CARRELLO 
						menuCarrello:
						cout<<"--- CARRELLO ATTUALE ---"<<endl;
						cout<<"PRODOTTO\t\t\t\tPREZZO"<<endl;
						if(ultimaPosOccupataCarrello==-1) cout<<"Vuoto!"<<endl;
						for(int i=0; i<ultimaPosOccupataCarrello+1; i++){
							int id=carrello[i];
							if(id>10 && id<20){ // Piatti Super Kebab (11-16)
								int p=id-11;
								cout<<i+1<<")";
								for(int x=p*dimPartizione+2; x<dimPartizione*(p+1); x++) cout<<piattiSK[x];
								cout<<"\t"<<costoItemCarrello[i];
								if(int(prezziarioSK[p])==prezziarioSK[p]) cout<<".00"<<endl;
								else cout<<"0"<<endl;
								sovrapprezzoItem=0;
								switch(p+1){
									case 1 ... 4:
										cout<<"\tDimensione:\t";
										switch(opzioniPiatti[i*3]){
											case 1:
												cout<<"Grande\t\t+3.00"<<endl;
												sovrapprezzoItem+=3;
												break;
											case 2:
												cout<<"Medio\t\t+2.90"<<endl;
												sovrapprezzoItem+=2.9;												
												break;
											case 3:
												cout<<"Piccolo\t\t+0.00"<<endl;
												break;
										}
										cout<<"\tContorno:\t";
										switch(opzioniPiatti[i*3+1]){
											case 1:
												cout<<"Patatine\t+3.00"<<endl;
												sovrapprezzoItem+=3;
												break;
											case 2:
												cout<<"Patate Piccanti\t+3.50"<<endl;
												sovrapprezzoItem+=3.50;
												break;
											case 3:
												cout<<"Nessuno\t\t+0.00"<<endl;
												break;
										}
										cout<<"\tBibita:\t\t";
										switch(opzioniPiatti[i*3+1]){
											case 1:
												cout<<"Acqua\t\t+0.00"<<endl;
												break;
											case 2:
												cout<<"CocaCola\t+2.00"<<endl;
												sovrapprezzoItem+=2;
												break;
											case 3:
												cout<<"Sprite\t\t+1.70"<<endl;
												sovrapprezzoItem+=1.70;
												break;
										}
										break;
									case 5:
										cout<<"\tDimensione: ";
										switch(opzioniPiatti[i*3]){
											case 1:
												cout<<"Grande\t\t+1.50"<<endl;
												sovrapprezzoItem+=1.5;
												break;
											case 2:
												cout<<"Medio\t\t\t+0.50"<<endl;
												sovrapprezzoItem+=0.5;
												break;
											case 3:
												cout<<"Piccolo\t\t+0.00"<<endl;
												break;
										}
										cout<<"\tSalsa: ";
										switch(opzioniPiatti[i*3+1]){
											case 1:
												cout<<"Maionese\t\t\t+0.10"<<endl;
												sovrapprezzoItem+=0.1;
												break;
											case 2:
												cout<<"Ketchup\t\t\t+0.10"<<endl;
												sovrapprezzoItem+=0.1;
												break;
											case 3:
												cout<<"Nessuna\t\t\t+0.00"<<endl;
												break;
										}
										break;
									case 6:
										cout<<"\tBibita: ";
										switch(opzioniPiatti[i*3]){
											case 1:
												cout<<"Acqua"<<endl;
												break;
											case 2:
												cout<<"CocaCola"<<endl;
												break;
											case 3:
												cout<<"Piccolo"<<endl;
												break;
										}
										break;
								}
								costoItemCarrello[i]+=sovrapprezzoItem;
								sovrapprezzoItem=0;
								cout<<"\t\t\t\tTOTALE\t"<<costoItemCarrello[i];
								if((costoItemCarrello[i]-int(costoItemCarrello[i]))==0) cout<<".00"<<endl;
								else cout<<"0"<<endl;
								cout<<endl;
							}
							if(id>40 && id<50){ // Piatti McDonalds (41-46)
								int p=id-41;
								cout<<"- ";
								for(int x=p*dimPartizione+2; x<dimPartizione*(p+1); x++) cout<<piattiMC[x];
								cout<<"\tMcDonalds"<<endl;
							}
						}
						cout<<endl;
						cout<<"Scegli una tra le seguenti opzioni: "<<endl
							<<"1 - Ordina e paga"<<endl
							<<"2 - Rimuovi un elemento dal carrello"<<endl
							<<"3 - Torna al menu dei ristoranti"<<endl
							<<"0 - Torna al menu principale"<<endl
							<<"=> ";
						cin>>scelta;

						switch(scelta){
							case 1: //ordina e paga
								cout<<"Dovrai pagare un totale di "<<totale<<" euro"<<endl
									<<"Pagherai tramite: ";
								switch(metodoPagamentoPreferito){
									case 0:
										cout<<"contanti."<<endl
											<<"Inserisci l'importo che consegnerai al rider per il calcolo del resto: ";
										cin>>importo;
										if(importo==0) break;
										cout<<"Riceverai "<<resto<<" euro di resto";
										break;
									case 1:
										cout<<"carta. "<<endl<<"Verifica se le informazioni sono corrette: "<<endl
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
											cout<<endl;
												for(int i=0; i<16; i++){									
													cout<<cartaCredito[i];
													if(i==4 or i==8 or i==12) cout<<"-";
												}
										break;
									case 2:
										cout<<"PayPal. Verifica se le informazioni sono corrette. "<<endl
											<<"Nome utente: ";
											for (int i=0; i<30; i++){
												if(utentePaypal[i] == '0') break;
												cout<<utentePaypal[i];										
											}
										break;
									case 3:
										cout<<"Gold Card. Non pagherai niente!";
										totale=0;
										break;
								}

								cout<<"Inserisci l'inidirizzo di consegna (inserisci 0 per concludere): ";
								for(int i=0; i<150; i++){
									cin>>indirizzoConsegna[i];
									if(indirizzoConsegna[i]=='0') break;
								}
								
								cout<<"Riepilogo ordine: "<<endl //DA COMPLETARE
									<<"BLA BLA BLA"<<endl;

								cout<<"Confermi? Ovvio che si. "<<endl<<endl; //OVVIAMENTE DA MODIFICARE - AGGIUNGERE SCELTA, SE NON SI CONFERMA SI RIBUTTA AL MENU DEL CARRELLO
								goto menuPrincipale; //ANCHE QUESTO E' TEMPORANEO - DOBBIAMO ACCORDARCI SE FAR CHIUDERE IL PROGRAMMA O SE RIPULIRE SEMPLICEMENTE TUTTO
								break;
							case 2://Pop elementi dal carrello (povera cassiera)
								cout<<"Quale ordine vuoi rimuovere(inserisci il suo numero, 0 per tornare indietro)?"<<endl;
								cout<<"=>";
								cin>>scelta;
								while(scelta<0 or scelta>ultimaPosOccupataCarrello+1){
									cout<<"Opzione non valida, riprova."<<endl
										<<"=>";
									cin>>scelta;
								}
								if(scelta==0) goto menuCarrello;

								scelta--;//decremento perche gli index vanno da 0 e non da 1
								for(int i=scelta; i<15; i++){//rimozione elemento da carrello
        							carrello[i]=carrello[i+1];
    							}
								for(int x=0; x<3; x++){//rimozione elemento da opzioni piatti (3 elementi)
									for(int i=scelta*3; i<15; i++){
        								opzioniPiatti[i]=opzioniPiatti[i+1];
    								}
								}
								for(int i=scelta; i<15; i++){ //rimozione elementi da costoItemCarrello
        							costoItemCarrello[i]=costoItemCarrello[i+1];
    							}

								ultimaPosOccupataCarrello--;//abbiamo liberato una posizione :D
								goto menuCarrello;
								break;
							case 3:
								goto menuRistoranti;
								break;
							case 0:
								goto menuPrincipale;
                		}
					}
					
				break;//chiude menu ristoranti
					
			/*
												 |\ /\
								 __              |,\(_\_
								( (              |\,`   `-^.
								 \ \             :    `-'   )
								  \ \             \        ;
								   \ \             `-.   ,'
									\ \ ____________,'  (
									; '                ;
									\                 /___,-.
									`,    ,_____|  ;'_____,'
									,-" \  :      | :
						     	   ( .-" \ `.__   | |
									\__)  `.__,'  |__)  
								GATTO DI BUONA FORTUNA PER QUESTO POVERO CODICE

			*/
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
