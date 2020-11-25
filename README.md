# Simple-Telegram-Message-Sender

That's just a simple Telegram message sender.

## Requirements
This project needs libcurl.
 
## Preparation

First create a file list named "liste.txt" and place inside all the chat_id of your users.

Next, in "Fonctions.cpp" replace the token by your own.

```cpp
#define TOKEN "Place your token here"
```

## Usage

Make sure your "liste.txt" is in the same directory as your executable,
otherwise you will get the following error

```cpp
>>ERREUR: Impossible d'ouvrir la liste.
```

Start the program then it will ask you the message you want to send.

```cpp
>>Quel est le message a envoyer ?
```

Then you will get the result of your request(s).
```cpp
>>last_name1 (username1) a reçu le message.
>>last_name2 (username2) a reçu le message.
```
## Changelog
v1.1 : Json callback interpretation.

## Credits
[Curl](https://curl.se/libcurl/)

[X2struct](https://github.com/xyz347/x2struct)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
