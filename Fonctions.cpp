//
//  Fonctions.cpp
//  
//
//  Created by kilianp07 on 13/10/2020.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "curl/curl.h"
#include "Header.h"
#include "x2struct-master/x2struct.hpp"
#define TOKEN "place your token here"
using namespace std;

string constructionRequete(string message, int chat_id){
    string requete;
    //Encodage du message pour préparation de la requete
    message = msgEncode(message);
   
    //Assemblage de la requete composé du token du chat_id et du message
    requete ="https://api.telegram.org/bot";
    requete += TOKEN;
    requete +="/sendMessage?chat_id=";
    requete +=to_string(chat_id);
    requete += "&text=";
    requete +=message;
    return requete;
}

// Source : stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string
size_t CurlWrite_CallbackFunc_StdString(void *contents, size_t size, size_t nmemb, std::string *s)
{
    size_t newLength = size*nmemb;
    try
    {
        s->append((char*)contents, newLength);
    }
    catch(std::bad_alloc &e)
    {
        //handle memory problem
        return 0;
    }
    return newLength;
}

//Déclaration des structures pour stocker le callback
struct From {
  int id;
  bool is_bot;
  string first_name;
  string username;
  XTOSTRUCT( O(id, is_bot,first_name,username));
};

struct Chat{
  int id;
  string first_name;
  string last_name;
  string username;
  string type;
  XTOSTRUCT( O(id, first_name,last_name,username,type));
};

struct Result {
  int message_id;
  From from;
  Chat chat;
  int  date;
  string text;
  XTOSTRUCT(O(message_id, from, chat, date, text));
};

struct retour {
  bool ok;
  Result result;
  XTOSTRUCT(O(ok, result));
};

void executerRequete(string requete){
   
    //Initialisation de curl
    CURL *curl = curl_easy_init();
    //Si curl a bien demarré
    if(curl) {
        string strJson;
        retour Sretour;
        CURLcode res;
        
        
        //Mise en place des options
        curl_easy_setopt(curl, CURLOPT_URL,requete.c_str());
        
        //Récuperation du callback
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString);
        //Recupération du callback dans le string strJson
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strJson);
        
        //Execution de la requete
        res = curl_easy_perform(curl);
       
        //Conversion du string en structures
        x2struct::X::loadjson(strJson, Sretour, false);
        
        //Si le message à été recu
        if(Sretour.ok == true){
            cout<<Sretour.result.chat.first_name<<" ("<<Sretour.result.chat.username<<") a recu le message."<<endl;
        }
        else {
            cout<<"Erreur lors de l'envoi du message "<<endl;
        }
        curl_easy_cleanup(curl);
    }
    else{
        //Sinon afficher un message d'erreur
        cout<<"Erreur de demarrage curl"<<endl;
    }
}

string msgEncode(string message){
    //Démarrage de curl
    CURL *curl = curl_easy_init();
    
    //Si curl a bien demarré
    if(curl) {
        //Encodage du message
      char *output = curl_easy_escape(curl, message.c_str(), 0);
        //Stockage dans la varariable string message
        message = output;
    }
    return message;
}
