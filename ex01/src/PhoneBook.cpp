/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-20 10:27:34 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-20 10:27:34 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.class.hpp"

// Definizione della funzione isDigitsOnly
static bool isDigitsOnly(const std::string &str) 
{
	size_t i;

	i = 0;
	while (i < str.size()) 
	{
    	if (!std::isdigit(str[i])) 
		{
        	return false;
    	}
    	++i;
	}
	return (true);
}

//start method
void PhoneBook::start(void)
{
	std::cout << RED "WELCOME TO THE PHONEBOOK!" << std::endl;
	std::cout << GREEN "-> add up to 8 contacts." << std::endl;
	std::cout << GREEN "-> search for a contact by typing 'SEARCH'." << std::endl;
	std::cout << GREEN "-> add a contact by typing 'ADD'." << std::endl;
	std::cout << GREEN "-> exit the PhoneBook by typing 'EXIT'." << std::endl;
};

//constructor - destructor
PhoneBook::PhoneBook()
{
	this->_nbContacts = 0;
	PhoneBook::start();
};

PhoneBook::~PhoneBook()
{
	std::cout << RED "Goodbye!" << std::endl;
};


//add utils - mettere controlli tipe se uno inserisce stringa vuota o cose del genere, SE IL NUMERO DI TELEFONO è COMPOSTO SOLO DA NUMERI

// NOTE: std::ws: This is a manipulator that tells the input stream to discard 
//       any leading whitespace (such as spaces, tabs, or newlines) before 
//       processing the next input. It's important to note that std::ws only 
//       skips leading whitespace characters; it doesn't affect any other 
//       characters in the input.
void PhoneBook::addName(int index)
{
	std::string name;

	std::cout << BLUE "Enter the name: " << std::endl;
	std::getline(std::cin >> std::ws, name);
	this->_contacts[index].setFirstName(name);
}

void PhoneBook::addLastName(int index)
{
	std::string lastName;

	std::cout << BLUE "Enter the last name: " << std::endl;
	std::getline(std::cin >> std::ws, lastName);
	this->_contacts[index].setLastName(lastName);
}

void PhoneBook::addNickName(int index)
{
	std::string nickName;

	std::cout << BLUE "Enter the nickname: " << std::endl;
	std::getline(std::cin >> std::ws, nickName);
	this->_contacts[index].setNickName(nickName);
}

void PhoneBook::addPhoneNumber(int index)
{
	std::string phoneNumber;

    std::cout << BLUE "Enter the phone number: " << std::endl;
    std::getline(std::cin >> std::ws, phoneNumber);

    while (true) 
	{
        std::cout << BLUE "Enter the phone number: " << std::endl;
        std::getline(std::cin >> std::ws, phoneNumber);

        // Controlla se phoneNumber contiene solo numeri
        if (isDigitsOnly(phoneNumber)) 
		{
            this->_contacts[index].setPhoneNumber(phoneNumber);
            break; // Esce dal ciclo se il numero è valido
        } 
		else
            std::cout << RED "Error: Phone number must contain only digits. Please try again." << std::endl;
    }
}


void PhoneBook::addDarkSecret(int index)
{
	std::string darkSecret;

	std::cout << BLUE "Enter the darkest secret: " << std::endl;
	std::getline(std::cin >> std::ws, darkSecret);
	this->_contacts[index].setDarkSecret(darkSecret);
}



//Add method
void PhoneBook::add(void)
{
	if (this->_nbContacts > 7)
	{
		std::cout << RED "The PhoneBook is full!" << std::endl;
		std::cout << RED "This contact will be added to the top of the list." << std::endl;
		PhoneBook::addName(0);
		PhoneBook::addLastName(0);
		PhoneBook::addNickName(0);
		PhoneBook::addPhoneNumber(0);
		PhoneBook::addDarkSecret(0);
		this->_nbContacts--;
	}
	else
	{
		PhoneBook::addName(this->_nbContacts);
		PhoneBook::addLastName(this->_nbContacts);
		PhoneBook::addNickName(this->_nbContacts);
		PhoneBook::addPhoneNumber(this->_nbContacts);
		PhoneBook::addDarkSecret(this->_nbContacts);
		this->_nbContacts++;
	}



};









void PhoneBook::getContact(int index) const
{
	std::cout << "name : " << this->_contacts[index].getFisrtName() << std::endl;
	std::cout << "last name : " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "nickname : " << this->_contacts[index].getNickName() << std::endl;
	std::cout << "phone number : " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "dark secret :" << this->_contacts[index].getDarkSecret() << std::endl;
	std::cout << std::endl;
};