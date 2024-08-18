#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
/*
std::string :
La dichiarazione firstName definisce una variabile di tipo std::string 
(istanzio un oggetto della classe std::string.) 
che può essere utilizzata per memorizzare e manipolare sequenze di caratteri.

Quando dichiari std::string firstName;, la variabile firstName è inizializzata 
automaticamente con una stringa vuota (""). 
Questo è possibile grazie al costruttore predefinito di std::string, che crea 
una stringa senza contenuto.

La dichiarazione e l'allocazione della variabile firstName comportano la 
creazione di uno spazio in memoria sufficiente per memorizzare la stringa. 
std::string gestisce automaticamente l'allocazione e la deallocazione della 
memoria interna necessaria per memorizzare i dati della stringa.

Private:
La parola chiave private è un modificatore di accesso che specifica che i membri
della classe sono accessibili solo dalla stessa classe e non da funzioni esterne
o da altre classi derivate.

public:
La parola chiave public è un modificatore di accesso che specifica che i membri
della classe sono accessibili da funzioni esterne e da altre classi derivate.



COSTRUTTORE:
In C++, un costruttore è una funzione speciale all'interno di una classe che 
viene chiamata automaticamente quando un oggetto di quella classe viene creato. 
Il compito principale del costruttore è inizializzare l'oggetto, ovvero assegnare 
valori iniziali agli attributi della classe e fare altre operazioni necessarie 
per preparare l'oggetto all'uso.

Caratteristiche di un Costruttore:
Stesso Nome della Classe:
Il costruttore ha lo stesso nome della classe in cui è definito. Ad esempio, 
se la classe si chiama Persona, anche il costruttore si chiamerà Persona.

Nessun Tipo di Ritorno:
Un costruttore non ha un tipo di ritorno, nemmeno void. Non restituisce alcun valore.

Viene Chiamato Automaticamente:
Il costruttore viene eseguito automaticamente ogni volta che si crea un'istanza 
(oggetto) della classe. Non è necessario chiamarlo manualmente.

Può Essere Sovraccaricato:
È possibile definire più costruttori in una classe, ciascuno con parametri diversi. 
Questa tecnica è chiamata sovraccarico del costruttore.

Costruttore Predefinito:
Se non viene definito nessun costruttore esplicitamente, il compilatore fornirà 
un costruttore predefinito che non fa nulla e non prende parametri. 
Tuttavia, se definisci un costruttore personalizzato, il costruttore predefinito 
non verrà generato automaticamente.

*/
class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkSecret;
	
	public:
		//constructor
		Contact();
};

#endif