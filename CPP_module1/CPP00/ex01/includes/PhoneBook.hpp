/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:14:28 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/05 15:37:39 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int size;
	int oldest_index;
public:
	PhoneBook();
};

void	print_contact_list(PhoneBook *phone_book, int size);
void exit_program();

#endif
