/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-21 09:37:28 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-21 09:37:28 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Utils.class.hpp"

bool Utils::isDigitsOnly(const std::string &str)
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

void Utils::printHeader(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

//quetsa funzione prende una stringa (campo del contatto) e la formatta nei 10
// spazi richiesti
std::string Utils::formatFields(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	else if (str.size() < 10)
	{
		str.insert(0, 10 - str.size(), ' ');
	}
	return ("|" + str);
}