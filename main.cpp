//
//  main.cpp
//  UJCBot
//
//  Created by kilianp07 on 13/10/2020.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"
#include "curl/curl.h"
using namespace std;
int main(int argc, const char * argv[]) {
    string chemin = "liste.txt";
    //Etablissement d'un flux à partir de l'adresse fournie
    ifstream fichier(chemin);
    
    //Si un flux est établi
    if(fichier){
        cout<<endl<<"Quel est le message a envoyer ?"<<endl;
        string message;
        //Récuperation du message tapé
        getline(cin,message);
        cout<<endl;
        string requete;
        int chat_id[255];
        int i=1;
        int nbLigne=0;
        string ligne;
        
        //Tant qu'il y a du texte
        while(getline(fichier, ligne)){
            //Conversion en int de la ligne lue
            chat_id[i]=atoi( ligne.c_str() );
            i++;
            //Comptage du nombre de lignes
            nbLigne++;
        }
        i =1;
        
        //Tant que toutes les lignes n'ont pas été traitées
        while (i<=nbLigne){
            //Construire la requete avec le message et le chat_id de chaque personne
            requete = constructionRequete(message, chat_id[i]);
            //Exécuter la requete
            executerRequete(requete);
            cout<<endl<<endl;
            i++;
        }
    }
    //S'il est impossible d'ouvrir la liste
    else
    {
        cout << "ERREUR: Impossible d'ouvrir la liste." << endl;
    }
    system("pause");
    return EXIT_SUCCESS;
}

