/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-21 09:35:47 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-08-21 09:35:47 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>

class Utils
{
	public:
		static bool isDigitsOnly(const std::string &str);
		static void printHeader(void);
		static std::string formatFields(std::string);
};

#endif