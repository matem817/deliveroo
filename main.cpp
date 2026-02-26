/*
RICORDATE:
!!!!!!!!!NON PUBBLICARE GLI ESEGUIBILI :D!!!!!!!!!!!
~Cris
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
    bool esci=false, messaggiDEBUG=false;
    int posizioneUtente=0;
    int sceltaMenuImpostazioni=0; //variabile utilizzata per lo switch del menu delle impostazioni dell'utente
	int scelta=0; //variabile da usare per tutti i menù di scelta (Il suo valore non dovrà mai essere chiamato prima di cin>>scelta;)
	char sceltaSN='n';

	//menu Ristoranti
    	int codiceRistorante=0;
		int piattoScelto=0;

	//Dati Ristoranti (vedi Docs #1)
		int dimPartizione=38;
        int quantitaPiatto=0;

		char piattiSL[]={
			'1',')','P','o','k','e','\'',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'2',')','1','5','5','.',' ','B','a','r','c','a',' ','m','i','s','t','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'3',')','5','3','.',' ','B','i','a','n','c','o',' ','r','o','l','l',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'4',')','1','5','8','.',' ','S','a','s','h','i','m','i',' ','s','a','l','m','o','n','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'5',')','6','0','.',' ','E','b','i','t','e','n',' ','r','o','l','l',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'6',')','2','1','0','.',' ','S','p','i','e','d','i','n','i',' ','d','i',' ','g','a','m','b','e','r','i',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		};
		float prezziarioSL[]={12.00, 22.00, 8.00, 9.00, 8.00, 7.00};
		
		char piattiSK[]={
        	'1',')','K','e','b','a','b',' ','C','o','m','p','l','e','t','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        	'2',')','P','i','a','d','i','n','a',' ','K','e','b','a','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        	'3',')','P','a','n','i','n','o',' ','F','a','l','a','f','e','l',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'4',')','V','a','s','c','h','e','t','t','a',' ','K','e','b','a','b',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'5',')','P','a','t','a','t','i','n','e',' ','F','r','i','t','t','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
      	  	'6',')','B','i','b','i','t','a',' ','a',' ','s','c','e','l','t','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };
		float prezziarioSK[]={12.00, 11.00, 7.00, 10.00, 6.00, 2.00};

		char piattiMC[]={
			'1',')','M','c','M','e','n','u',' ','G','r','a','n',' ','C','r','i','s','p','y',' ','M','c','B','a','c','o','n',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'2',')','2',' ','M','c','M','e','n','u',' ','L','a','r','g','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'3',')','M','c','M','e','n','u',' ','C','B','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'4',')','M','c','M','e','n','u',' ','1','9','5','5',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'5',')','M','c','M','e','n','u',' ','D','o','u','b','l','e',' ','C','h','i','k','e','n',' ','B','B','Q',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
			'6',')','M','c','M','e','n','u',' ','M','c','R','o','y','a','l',' ','D','e','l','u','x','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		};
		float prezziarioMC[]={12.20,15.90,13.60,14.15,7.30,13.20};

        char piattiPZ[]={
            '1',')','P','o','k','e',' ','S','a','l','m','o','n','e',' ','S','p','i','c','y',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '2',')','P','o','k','e',' ','T','u','n','a',' ','E','x','o','t','i','c',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '3',')','P','o','k','e',' ','V','e','g','e','t','a','r','i','a','n','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '4',')','M','o','c','h','i',' ','M','i','s','t','i',' ','(','3','p','z',')',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '5',')','Z','u','p','p','a',' ','d','i',' ','M','i','s','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '6',')','A','c','q','u','a',' ','N','a','t','u','r','a','l','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };
		float prezziarioPZ[]={10.50, 11.00, 9.00, 5.50, 4.00, 2.50};
        char piattiLP[]={
            '1',')','P','i','a','d','i','n','a',' ','C','r','u','d','o',' ','e',' ','S','q','u','a','c','q','u','e','r','o','n','e',' ',' ',' ',' ',' ',' ',' ',' ',
            '2',')','P','i','a','d','i','n','a',' ','C','o','t','t','o',' ','e',' ','F','o','n','t','i','n','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '3',')','P','i','a','d','i','n','a',' ','P','o','l','l','o',' ','G','r','i','g','l','i','a','t','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '4',')','P','i','a','d','i','n','a',' ','V','e','g','e','t','a','l','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '5',')','R','o','t','o','l','o',' ','N','u','t','e','l','l','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '6',')','B','i','b','i','t','a',' ','i','n',' ','L','a','t','t','i','n','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };
		float prezziarioLP[]={8.50, 8.00, 7.50, 6.50, 5.00, 2.00};
		char piattiDG[]={
            '1',')','C','a','r','b','o','n','a','r','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '2',')','A','m','a','t','r','i','c','i','a','n','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '3',')','C','a','c','i','o',' ','e',' ','P','e','p','e',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '4',')','G','r','i','c','i','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '5',')','P','o','l','p','e','t','t','e',' ','a','l',' ','S','u','g','o',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
            '6',')','T','i','r','a','m','i','s','u','\'',' ','f','a','t','t','o',' ','i','n',' ','c','a','s','a',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
        };
        float prezziarioDG[]={12.00, 11.00, 10.00, 11.00, 13.00, 6.00};

		
	
    //variabili di dati utente(immagazzinano info sull'utente)
    	//menu nome
			char nome[30];
			bool nomeInserito=false;
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
			float costoFinaleItemCarrello[15];
			int piatto; //utilizzato per mostrare le personalizzazioni dei piatti
	//menu carrello
		float totale=0, importo=0, resto=0; //si capisce no? dai
		char indirizzoConsegna[150];

	//initializzazioni vettori
	for(int i=0; i<15;i++){
		carrello[i]=0;
		costoItemCarrello[i]=0;
		costoFinaleItemCarrello[i]=0;
	}
	for(int i=0; i<15*3;i++){
		opzioniPiatti[i]=0;
	}


    //APP
    while(!esci){
		for(int i=0; i<50; i++) cout<<endl;
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
		for(int i=0; i<50; i++) cout<<endl;
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
				for(int i=0; i<50; i++) cout<<endl;
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
					<<"#  0) Menu iniziale                                   8) Visualizza carrello   #"<<endl
					<<"################################################################################"<<endl;
				chiediInputRistorante:
				cout<<"=>";
				cin>>codiceRistorante;
				if(codiceRistorante<0||codiceRistorante>8) {
					cout<<"Selezione non valida riprovare\n";
					goto chiediInputRistorante;
				}
				for(int i=0; i<50; i++) cout<<endl;
				switch(codiceRistorante){
					case 0:
						goto menuPrincipale;
					case 1://SuperKebab
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
											<<"3-Piccolo"<<endl;
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
											<<"3-Nessuno"<<endl;
										cout<<"=>";
										cin>>scelta;
										while(scelta<1 or scelta>3){
											cout<<"Opzione invalida, riprovare."<<endl
											<<"=>";
											cin>>scelta;
										}
										opzioniPiatti[ultimaPosOccupataCarrello*3+1]=scelta;

										cout<<"Scegliere una bibita:"<<endl
											<<"1-Acqua"<<endl
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
											<<"3-Piccolo"<<endl;
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
											<<"3-Nessuna"<<endl;
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
											<<"1-Acqua"<<endl
											<<"2-CocaCola"<<endl
											<<"3-Sprite"<<endl;
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
								<<"Sarai reindirizzato al carrello dove portrai concludere l'ordine"<<endl;
							cout<<"Premi un numero e poi enter per continuare..."<<endl;
							cin>>scelta;
							goto menuCarrello;
						}
                    
                    case 2://SushiLine
						sushiLine:
                        cout<<"################################################################################"<<endl
							<<"# ____            _     _    _     _                                           #"<<endl
							<<"#/ ___| _   _ ___| |__ (_)  | |   (_)_ __   ___                                #"<<endl
							<<"#\\___ \\| | | / __| '_ \\| |  | |   | | '_ \\ / _ \\                               #"<<endl
							<<"# ___) | |_| \\__ \\ | | | |  | |___| | | | |  __/                               #"<<endl
							<<"#|____/ \\__,_|___/_| |_|_|  |_____|_|_| |_|\\___|                               #"<<endl
							<<"#                                                                              #"<<endl
							<<"#Consegna tra 10-25 minuti                                                     #"<<endl;

                        for(int i=0; i<6;i++){
                            cout<<"#------------------------------------------------------------------------------#"<<endl;
                            cout<<"#";
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiSL[x];
                            cout<<"| ";
                            i++;
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiSL[x];
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
						for(int x=(piattoScelto-1)*dimPartizione; x<dimPartizione*(piattoScelto); x++) cout<<piattiSL[x];
						cout<<endl;

						cout<<"Quante unita' di questo piatto vuoi ordinare? ";
                        cin>>quantitaPiatto;

                        for(int k=0; k<quantitaPiatto; k++){
                            if(ultimaPosOccupataCarrello<15){
								ultimaPosOccupataCarrello++;
                                carrello[ultimaPosOccupataCarrello]=20+piattoScelto;
								costoItemCarrello[ultimaPosOccupataCarrello]=prezziarioSL[piattoScelto-1];
								if(piattoScelto==1){
									cout<<"Scegliere la base del poke':"<<endl
										<<"1 - Riso Bianco"<<endl
										<<"2 - Riso Integrale"<<endl;
									cout<<"=>";
									cin>>scelta;
									while(scelta!=1 and scelta!=2){
										cout<<"Opzione invalida, riprovare."<<endl
										<<"=>";
										cin>>scelta;
									}
									opzioniPiatti[ultimaPosOccupataCarrello*3]=scelta;

									cout<<"Scegli le proteine:"<<endl
										<<"1 - Salmone"<<endl
										<<"2 - Tonno\t\t+0.50"<<endl
										<<"3 - Tofu Marinato"<<endl;
										cout<<"=>";
									cin>>scelta;
									while(scelta<1 or scelta>3){
										cout<<"Opzione invalida, riprovare."<<endl
										<<"=>";
										cin>>scelta;
									}
									opzioniPiatti[ultimaPosOccupataCarrello*3+1]=scelta;

									cout<<"Scegli un topping:"<<endl
										<<"1 - Avocado\t\t+1.00"<<endl
										<<"2 - Cetriolo"<<endl
										<<"3 - Carote Juliane"<<endl;
										cout<<"=>";
									cin>>scelta;
									while(scelta<1 or scelta>3){
										cout<<"Opzione invalida, riprovare."<<endl
										<<"=>";
										cin>>scelta;
									}
									opzioniPiatti[ultimaPosOccupataCarrello*3+2]=scelta;

								}
                            } else {
                                break; 
                            }
                        }
						
						cout<<endl<<"Aggiunto al carrello."<<endl;

						if(ultimaPosOccupataCarrello<15){
							cout<<"Vuoi ordinare qualcosaltro da Sushi Line?(S/n): ";
							cin>>sceltaSN;
							switch(sceltaSN){
								case 'n':
								case 'N':
									goto menuRistoranti;
									break;
								default:
									goto sushiLine;
							}
							break;
						}else{
							cout<<"Il tuo carrello è pieno!!!"<<endl
								<<"Sarai reindirizzato al carrello dove portrai concludere l'ordine"<<endl;
							cout<<"Premi un numero e poi enter per continuare..."<<endl;
							cin>>scelta;
							goto menuCarrello;	
						}
						break;
					case 3: //PokeZen
						pokeZen:
                        cout<<"################################################################################"<<endl
							<<"# ____       _    __    _____                                                  #"<<endl
							<<"#|  _ \\ ___ | | __\\_\\  |__  /___ _ __                                          #"<<endl
							<<"#| |_) / _ \\| |/ / _ \\   / // _ \\ '_ \\                                         #"<<endl
							<<"#|  __/ (_) |   <  __/  / /|  __/ | | |                                        #"<<endl
							<<"#|_|   \\___/|_|\\_\\___| /____\\___|_| |_|                                        #"<<endl
							<<"#                                                                              #"<<endl
							<<"#Consegna tra 10-25 minuti                                                     #"<<endl;
                        for(int i=0; i<6;i++){
							cout << "#------------------------------------------------------------------------------#" << endl;
                            cout<<"#";
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiPZ[x];
                            cout<<"| "; i++;
                            for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiPZ[x];
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
						for(int x=(piattoScelto-1)*dimPartizione; x<dimPartizione*(piattoScelto); x++) cout<<piattiPZ[x];
						cout<<endl;

						cout<<"Quante unita' di questo piatto vuoi ordinare? ";
                        cin>>quantitaPiatto;

						for(int k=0; k<quantitaPiatto; k++){
                            if(ultimaPosOccupataCarrello<15){
								ultimaPosOccupataCarrello++;
                                carrello[ultimaPosOccupataCarrello]=30+piattoScelto;
								costoItemCarrello[ultimaPosOccupataCarrello]=prezziarioPZ[piattoScelto-1];
                            } else {
                                break; 
                            }
                        }
						if(ultimaPosOccupataCarrello<15){
							cout<<"Vuoi ordinare qualcosaltro da Poke zen?(S/n): ";
							cin>>sceltaSN;
							switch(sceltaSN){
								case 'n':
								case 'N':
									goto menuRistoranti;
									break;
								default:
									goto pokeZen;
							}
							break;
						}else{
							cout<<"Il tuo carrello è pieno!!!"<<endl
								<<"Sarai reindirizzato al carrello dove portrai concludere l'ordine"<<endl;
							cout<<"Premi un numero e poi enter per continuare..."<<endl;
							cin>>scelta;
							goto menuCarrello;	
						}

					case 4: //mcDonalds
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
								ultimaPosOccupataCarrello++;
                                carrello[ultimaPosOccupataCarrello]=40+piattoScelto;
								costoItemCarrello[ultimaPosOccupataCarrello]=prezziarioMC[piattoScelto-1];
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
							break;
						}else{
							cout<<"Il tuo carrello è pieno!!!"<<endl
								<<"Sarai reindirizzato al carrello dove portrai concludere l'ordine"<<endl;
							cout<<"Premi un numero e poi enter per continuare..."<<endl;
							cin>>scelta;
							goto menuCarrello;
						}
					
						break;
					case 5: // --- LA PIADINERIA ---
						laPiadineria:
						cout<<"################################################################################"<<endl
							<<"# _             ____  _           _ _                 _                        #"<<endl
							<<"#| |    __ _   |  _ \\(_) __ _  __| (_)_ __   ___ _ __(_) __ _                  #"<<endl
							<<"#| |   / _` |  | |_) | |/ _` |/ _` | | '_ \\ / _ \\ '__| |/ _` |                 #"<<endl
							<<"#| |__| (_| |  |  __/| | (_| | (_| | | | | |  __/ |  | | (_| |                 #"<<endl
							<<"#|_____\\__,_|  |_|   |_|\\__,_|\\__,_|_|_| |_|\\___|_|  |_|\\__,_|                 #"<<endl
							<<"#                                                                              #"<<endl
							<<"#Consegna tra 10-25 minuti                                                     #"<<endl;
						for(int i=0; i<6;i++){
							cout<<"#------------------------------------------------------------------------------#"<<endl;
							cout<<"#";
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiLP[x];
							cout<<"| "; i++;
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout<<piattiLP[x];
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
						if(piattoScelto==0) goto menuRistoranti;

						cout<<"E stato scelto "<<endl;
						for(int x=(piattoScelto-1)*dimPartizione; x<dimPartizione*(piattoScelto); x++) cout<<piattiLP[x];
						cout<<endl;

						cout<<"Quante unita' di questo piatto vuoi ordinare? ";
                        cin>>quantitaPiatto;

                        for(int k=0; k<quantitaPiatto; k++){
                            if(ultimaPosOccupataCarrello<15){
								ultimaPosOccupataCarrello++;
                                carrello[ultimaPosOccupataCarrello]=50+piattoScelto;
								costoItemCarrello[ultimaPosOccupataCarrello]=prezziarioLP[piattoScelto-1];
                            } else {
                                break; 
                            }
                        }
						cout<<endl<<"Aggiunto al carrello."<<endl;

						if(ultimaPosOccupataCarrello<15){
							cout<<"Vuoi ordinare qualcosaltro da La Piadineria?(S/n): ";
							cin>>sceltaSN;
							switch(sceltaSN){
								case 'n':
								case 'N':
									goto menuRistoranti;
									break;
								default:
									goto laPiadineria;
							}
						}else{
							cout<<"Il tuo carrello è pieno!!!"<<endl
								<<"Sarai reindirizzato al carrello dove portrai concludere l'ordine"<<endl;
							cout<<"Premi un numero e poi enter per continuare..."<<endl;
							cin>>scelta;
							goto menuCarrello;
						}
							/*
							Non andartene docile in quella buona notte,
							I vecchi dovrebbero bruciare e delirare quando cade il giorno;
							Infuria, infuria, contro il morire della luce.

							Benché i saggi sappiano che la tenebra è inevitabile,
							visto che dalle loro azioni non scaturì alcun fulmine,
							Non se ne vanno docili in quella buona notte,

							Gli onesti, con l’ultima onda, gridando quanto fulgide
							le loro deboli gesta danzerebbero in una verde baia,
							S’infuriano, s’infuriano contro il morire della luce.

							Gli impulsivi che il sole presero al volo e cantarono,
							imparando troppo tardi d’averne afflitto il percorso,
							Non se ne vanno docili in quella buona notte.

							Gli austeri, in punto di morte, accorgendosi con vista cieca
							che gli occhi spenti potevano gioire e brillare come meteore,
							S’infuriano, s’infuriano contro il morire della luce.

							E tu, padre mio, là sulla triste altura, ti prego,
							Condannami o benedicimi, ora, con le tue lacrime furiose.
							Non andartene docile in quella buona notte.
							Infuriati, infuriati contro il morire della luce.
							*/
					case 6://Da graziella
						daGraziella:
						cout << "################################################################################" << endl
								<< "#  ____    _        ____ ____      _    _____ ___ _____ _     _        _       #" << endl
								<< "# |  _ \\  / \\      / ___|  _ \\    / \\   |__  |_ _| ____| |   | |      / \\      #" << endl
								<< "# | | | |/ _ \\    | |  _| |_) |  / _ \\    / / | ||  _| | |   | |     / _ \\     #" << endl
								<< "# | |_| / ___ \\   | |_| |  _ <  / ___ \\  / /_ | || |___| |___| |___ / ___ \\    #" << endl
								<< "# |____/_/   \\_\\   \\____|_| \\_\\/_/   \\_\\/____|___|_____|_____|_____/_/   \\_\\   #" << endl
								<< "#                                                                              #" << endl
								<< "# Consegna tra 20-40 minuti                                                    #" << endl;

						for(int i=0; i<6; i++){
							cout << "#------------------------------------------------------------------------------#" << endl;
							cout << "#";
							// Stampa il primo piatto della coppia
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout << piattiDG[x];
							cout << "| ";
							i++; // Passa al secondo piatto della coppia
							// Stampa il secondo piatto
							for(int x=i*dimPartizione; x<dimPartizione*(i+1); x++) cout << piattiDG[x];
							cout << "#" << endl;
						}
						
						cout << "#------------------------------------------------------------------------------#" << endl;
						for(int i=0; i<4; i++){
							cout<<"#                                                                              #"<<endl;
						}
						cout << "# 0) Torna al menu Ristoranti                                                  #" << endl
								<< "################################################################################" << endl
								<< "Selezionare la pietanza da aggiungere al carrello" << endl
								<< "=>";
						cin >> piattoScelto;

						if(piattoScelto == 0) goto menuRistoranti;

						while(piattoScelto < 0 || piattoScelto > 6){
							cout << "Selezione non valida riprovare" << endl << "=>";
							cin >> piattoScelto;
						}

						cout << "Hai scelto: ";
						for(int x=(piattoScelto-1)*dimPartizione; x<dimPartizione*(piattoScelto); x++) cout << piattiDG[x];
						cout << endl;

						cout << "Quante unita' vuoi ordinare? ";
						cin >> quantitaPiatto;

						for(int k=0; k<quantitaPiatto; k++){
							if(ultimaPosOccupataCarrello < 14){
								ultimaPosOccupataCarrello++;
								carrello[ultimaPosOccupataCarrello] = 60 + piattoScelto; // Codice 60 per Da Graziella
								costoItemCarrello[ultimaPosOccupataCarrello] = prezziarioDG[piattoScelto-1];
							}
						}

						cout << "\nAggiunto al carrello!" << endl;
						if(ultimaPosOccupataCarrello<15){
							cout<<"Vuoi ordinare qualcosaltro da Graziella?(S/n): ";
							cin>>sceltaSN;
							switch(sceltaSN){
								case 'n':
								case 'N':
									goto menuRistoranti;
									break;
								default:
									goto daGraziella;
							}
						}else{
							cout<<"Il tuo carrello è pieno!!!"<<endl
								<<"Sarai reindirizzato al carrello dove portrai concludere l'ordine"<<endl;
							cout<<"Premi un numero e poi enter per continuare..."<<endl;
							cin>>scelta;
							goto menuCarrello;
						}
					case 7://Easter Egg
						cout<<"################################################################################"<<endl<<"#    _                                        _     _            _   _         #"<<endl<<"#   | |    ___   _ __ ___   ___ __ _  ___ ___| |__ (_)_ __   ___| |_| |_ ___   #"<<endl<<"#   | |   / _ \\ | '_ ` _ \\ / __/ _` |/ __/ __| '_ \\| | '_ \\ / _ \\ __| __/ _ \\  #"<<endl<<"#   | |__|  __/ | | | | | | (_| (_| | (_| (__| | | | | | | |  __/ |_| ||  __/  #"<<endl<<"#   |_____\\___| |_| |_| |_|\\___\\__,_|\\___\\___|_| |_|_|_| |_|\\___|\\__|\\__\\___|  #"<<endl<<"#                                                                              #"<<endl<<"#   |---|------------|                                                         #"<<endl<<"#   |   ||----------||                                                         #"
						<<endl<<"#   |   ||[][][][][]||          Chiuso,                                        #"<<endl<<"#   |   ||[][][][][]||          ci scusiamo per il disagio ma                  #"<<endl<<"#   |   ||[][][][][]||          la preside sta girando nei corridoi !!!        #"<<endl<<"#   |   ||[][][][][]||                                                         #"<<endl<<"#   |   ||[][][][][]||               0) ritorna al menu ristoranti             #"<<endl<<"#   |   ||[][][][][]||                                                         #"<<endl<<"#   |   ||[][][][][]||                                                         #"<<endl<<"#   |   ||[][][][][]||                                                         #"<<endl<<"#   |   ||----------||                                                         #"<<endl<<"#   |   ||          ||                                                         #"<<endl<<"#   |   ||----------||                                                         #"<<endl<<"#   |---|------------|                                                         #"<<endl<<"################################################################################"<<endl;
						cout<<"=>";
						cin>>piattoScelto;
						goto menuRistoranti;
						break;

					/*
						---------------------------------------------------------
						@@@@@@@@@@@@@@@@@@@@ SEZIONE CARRELLO @@@@@@@@@@@@@@@@@@@
						---------------------------------------------------------
					*/
					case 8: // SEZIONE CARRELLO 
						menuCarrello:
						cout<<"--- CARRELLO ATTUALE ---"<<endl;
						cout<<"PRODOTTO\t\t\t\tPREZZO"<<endl;
						if(ultimaPosOccupataCarrello==-1) cout<<"Vuoto!"<<endl;
						for(int i=0; i<ultimaPosOccupataCarrello+1; i++){
							int id=carrello[i];
							switch(id){
								case 11 ... 16: // Piatti Super Kebab (11-16)
									piatto=id-11;
									cout<<i+1<<")";
									for(int x=piatto*dimPartizione+2; x<dimPartizione*(piatto+1); x++) cout<<piattiSK[x];
									cout<<"\t"<<costoItemCarrello[i];
									if(int(prezziarioSK[piatto])==prezziarioSK[piatto]) cout<<".00"<<endl;
									else cout<<"0"<<endl;
									sovrapprezzoItem=0;
									switch(piatto+1){
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
													cout<<"Piccolo"<<endl;
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
													cout<<"Nessuno"<<endl;
													break;
											}
											cout<<"\tBibita:\t\t";
											switch(opzioniPiatti[i*3+2]){
												case 1:
													cout<<"Acqua"<<endl;
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
													cout<<"Piccolo"<<endl;
													break;
											}
											cout<<"\tSalsa: ";
											switch(opzioniPiatti[i*3+1]){
												case 1:
													cout<<"Maionese\t\t+0.10"<<endl;
													sovrapprezzoItem+=0.1;
													break;
												case 2:
													cout<<"Ketchup\t\t+0.10"<<endl;
													sovrapprezzoItem+=0.1;
													break;
												case 3:
													cout<<"Nessuna"<<endl;
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
													cout<<"Sprite"<<endl;
													break;
											}
											break;
									}
									break;
								case 21 ... 26:
									piatto=id-21;
									cout<<i+1<<")";
									for(int x=piatto*dimPartizione+2; x<dimPartizione*(piatto+1); x++) cout<<piattiSL[x];
									cout<<"\t"<<costoItemCarrello[i];
									if(int(prezziarioSL[piatto])==prezziarioSL[piatto]) cout<<".00"<<endl;
									else cout<<"0"<<endl;
									sovrapprezzoItem=0;
									if(piatto==0){
										cout<<"\tBase: ";
										switch(opzioniPiatti[i*3]){
											case 1:
												cout<<"Riso bianco."<<endl;
												break;
											case 2:
												cout<<"Riso integrale"<<endl;
												break;
										}
										cout<<"\tProteine: ";
										switch(opzioniPiatti[i*3+1]){
											case 1:
												cout<<"Salmone";
												break;
											case 2:
												cout<<"Tonno\t\t\t+0.50";
												sovrapprezzoItem+=0.50;
												break;
											case 3:
												cout<<"Tofu Marinato";
												break;
										}
										cout<<endl;
										cout<<"\tTopping: ";
										switch(opzioniPiatti[i*3+2]){
											case 1:
												cout<<"Avocado\t\t+1.00";
												sovrapprezzoItem+=1;
												break;
											case 2:
												cout<<"Cetriolo";
												break;
											case 3:
												cout<<"Carote";
												break;
										}
										cout<<endl;
									}
									break;
								case 31 ... 36:
									piatto=id-31;
									cout<<i+1<<")";
									for(int x=piatto*dimPartizione+2; x<dimPartizione*(piatto+1); x++) cout<<piattiPZ[x];
									cout<<endl;
									break;
								case 41 ... 46: // Piatti McDonalds (41-46)
									piatto=id-41;
									cout<<i+1<<")";
									for(int x=piatto*dimPartizione+2; x<dimPartizione*(piatto+1); x++) cout<<piattiMC[x];
									cout<<endl;
									break;
								case 51 ... 56:
									piatto=id-51;
									cout<<i+1<<")";
									for(int x=piatto*dimPartizione+2; x<dimPartizione*(piatto+1); x++) cout<<piattiLP[x];
									cout<<endl;
									break;
								case 61 ... 66:
									piatto=id-61;
									cout<<i+1<<")";
									for(int x=piatto*dimPartizione+2; x<dimPartizione*(piatto+1); x++) cout<<piattiDG[x];
									cout<<endl;
									break;
								
							}
							costoFinaleItemCarrello[i]=costoItemCarrello[i]+sovrapprezzoItem;
							sovrapprezzoItem=0;
							cout<<"\t\t\t\tTOTALE\t"<<costoFinaleItemCarrello[i];
							if((costoFinaleItemCarrello[i]-int(costoFinaleItemCarrello[i]))==0) cout<<".00"<<endl;
							else cout<<"0"<<endl;
							cout<<endl;
						}
						totale=0;
						for(int i=0; i<15; i++){
							if(costoFinaleItemCarrello[i]==0) break;
							totale=totale+costoFinaleItemCarrello[i];
						}
						cout<<"\tTOTALE CARRELLO: "<<totale;
						if((totale-int(totale))==0) cout<<".00"<<endl;
						else cout<<"0"<<endl;
						cout<<endl;
						cout<<"Scegli una tra le seguenti opzioni: "<<endl
							<<"1 - Ordina e paga"<<endl
							<<"2 - Rimuovi un elemento dal carrello"<<endl
							<<"3 - Torna al menu dei ristoranti"<<endl
							<<"0 - Torna al menu principale"<<endl
							<<"=> ";
						cin>>scelta;
						while(scelta>3 || scelta<0){
							cout<<"Opzione non valida, riprovare"<<endl
								<<"=> ";
							cin>>scelta;
						}
						for(int i=0; i<50; i++) cout<<endl;
						switch(scelta){
							case 1: //ordina e paga
								cout<<"Dovrai pagare un totale di ";
								cout<<totale<<" euro"<<endl
									<<"Pagherai tramite: ";
								switch(metodoPagamentoPreferito){
									case 0:
										cout<<"contanti."<<endl
											<<"Inserisci l'importo che consegnerai al rider per il calcolo del resto: ";
										cin>>importo;
										while(importo<=0){
											cout<<"L'importo non puo' essere minore o uguale a 0! Reinserire l'importo: ";
											cin>>importo;
										}
										while(importo<totale){
											cout<<"L'importo non puo' essere minore del totale! Reinserire l'importo: ";
											cin>>importo;
										}

										resto=importo-totale;
										cout<<"Riceverai "<<resto<<" euro di resto"<<endl;
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
											cout<<endl
												<<"	Numero carta: ";
												for(int j=0; j<3;j++){
													for(int i=0; i<4;i++) cout<<"*";
													cout<<"-";
												}
												for(int i=12; i<16; i++){									
													cout<<cartaCredito[i];
												}
										cout<<endl;
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
								cout<<"Se vuoi cambiare metodo di pagamento digita 1, per continuare digita 0"<<endl;
								cout<<"=>";
								cin>>scelta;
								if(scelta==1) goto menuPagamentoPreferito;
								for(int i=0; i<50; i++) cout<<endl;
								cout<<"Inserisci l'inidirizzo di consegna (inserisci 0 per concludere): ";
								for(int i=0; i<150; i++){
									cin>>indirizzoConsegna[i];
									if(indirizzoConsegna[i]=='0') break;
								}
								inserimentoNomeOrdine:
								for(int i=0; i<50; i++) cout<<endl;
								if(!nomeInserito){
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
									cout<<endl;
								}else{
									cout<<"Il nome inserito è:";
									for(int i=0; i<30; i++){
										if(nome[i]=='0') break;
										cout<<nome[i];
									}
									cout<<endl;
									cout<<"Confermi?(s/N)"<<endl
										<<"=>";
									cin>>sceltaSN;
									switch(sceltaSN){
										case 'S':
										case 's':
											break;
										default:
											nomeInserito=false;
											goto inserimentoNomeOrdine;
									}
									
								}
								for(int i=0; i<50; i++) cout<<endl;
								cout<<endl<<"Confermi l'ordine? Verifica le informazioni inserite prima di confermare. (S/N)"<<endl
									<<"Metodo di pagamento: ";
									switch(metodoPagamentoPreferito){
										case 0:
											cout<<"contanti"<<endl
												<<"Consegnerai "<<importo<<" euro al rider e riceverai "<<resto<<" euro di resto";
											break;
										case 1:
											cout<<"carta di credito."<<endl
												<<"Verifica sopra se le informazioni della carta sono corrette.";
											break;
										case 2:
											cout<<"PayPal."<<endl
												<<"Verifica sopra se le informazioni dell'account PayPal sono corrette.";
											break;
										case 3:
											cout<<"Gold Card."<<endl
												<<"Nuovo totale: "<<totale<<" euro";
											break;
									}
								cout<<endl<<"Indirizzo di consegna: ";
								for(int i=0; i<150; i++){
									if(indirizzoConsegna[i]=='0') break;
									cout<<indirizzoConsegna[i];
								}
								
								cout<<endl<<"=> ";
								cin>>sceltaSN;
								switch(sceltaSN){
									case 's':
									case 'S':
										for(int i=0; i<15;i++){
											carrello[i]=0;
											costoItemCarrello[i]=0;
										}
										for(int i=0; i<15*3;i++){
											opzioniPiatti[i]=0;
										}
										cout<<"Il tuo ordine e' in arrivo! Grazie per aver utilizzato Deliveroo!"<<endl<<endl;;
										break;
									case 'n':
									case 'N':
										goto menuCarrello;
								}
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
									\ \ ____________,'  ( JIACOMO
									; '                ;
									\                 /___,-.
									`,    ,_____|  ;'_____,'
									,-" \  :      | :
						     	   ( .-" \ `.__   | |
									\__)  `.__,'  |__)  
								MICIO DI BUONA FORTUNA PER QUESTO POVERO CODICE

			*/
			/*	
				###################################################################
									MENU DATI PERSONALI UTENTE
				###################################################################
			*/
            case 2: //menu dati personali utente
                menuDatiPersonali:
				for(int i=0; i<50; i++) cout<<endl;
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
				for(int i=0; i<50; i++) cout<<endl;
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
						nomeInserito=true;
						goto menuDatiPersonali;
                        break;
                    case 2://metodo di pagamento preferito
                    	menuPagamentoPreferito:
						for(int i=0; i<50; i++) cout<<endl;
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
                                    for(int j=0; j<3;j++){
                                        for(int i=0; i<4;i++) cout<<"*";
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
						for(int i=0; i<50; i++) cout<<endl;
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
								for(int i=0; i<50; i++) cout<<endl;
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
											}else if(cartaCredito[i]<0){
												cout<<"Non possono esserci cifre negative nel numero della carta di credito. Reinserisci l'ultimo numero: "<<endl;
												i--;
											}
										}
										cout<<"Inserisci il CVV: ";
										cin>>cvv;
										if(cvv<0) cout<<"Serio?? Codice di sicurezza negativo? broooooooooooo"<<endl;
										while(cvv<0){
											cout<<"=>";
											cin>>cvv;
										}
				                        for(int i=0; i<50; i++) cout<<endl;
										cout<<"Inserisci il nome sulla carta (premi invio ad ogni lettera, inserisci 0 quando hai concluso): ";
				                        for(int i=0; i<15; i++){
				                            cin>>nomeCarta[i];
				                            if(nomeCarta[i]=='0') break;
				                        }
										for(int i=0; i<50; i++) cout<<endl;
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
										cout<<"Ci prometti che sei tu? OuO"<<endl;
										cout<<"Va bene :3!";
										for(int i=0; i<50000; i++){
											for(int y=0; y<30000; y++);
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
        
    	//qui giaceva una parentesi graffa che ruppe il codice per 12h. R.I.P.
	}
}
/*
Apena inizi a programmare, solo tu e Dio sapete come il codice funziona,
dopo una settimana solo Dio lo sa. 
*/
