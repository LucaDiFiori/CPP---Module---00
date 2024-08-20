/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-20 10:34:52 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-20 10:34:52 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/PhoneBook.class.hpp"



int main()
{
	PhoneBook phoneBook;

	phoneBook.add();
	int i = 0;
	while (i < 8)
	{
		std::cout << "Contact " << i << std::endl;
		phoneBook.getContact(i);
		i++;
	}

};