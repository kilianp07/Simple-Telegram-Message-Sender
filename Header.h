//
//  Header.h
//  
//
//  Created by kilianp07 on 13/10/2020.
//

#ifndef Header_h
#define Header_h
using namespace std;

//Fonction permettant de construire la requete
//Parametres d'entree : chat_id et message
//Sortie : requete prete a executer
string constructionRequete(string message, int chat_id);

//Fonction permettant d'executer la requete
//Parametre d'entree : requete
//Pas de sortie
void executerRequete(string requete);

//Fonction permettant d'encoder le message pour que les caracteres spéciaux existent
//Parametre d'entrée : String message
//Sortie : message encodé
string msgEncode(string message);
#endif /* Header_h */
