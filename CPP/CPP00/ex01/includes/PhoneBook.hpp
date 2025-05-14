/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:14:28 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 15:25:27 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include "Utils.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		size_t size;
		size_t oldest_index;
	public:
		PhoneBook();
		void	create_contact(const Contact &contact);
		void	create_contact_form(Contact *contact);
		void	print_contact_list();
		void	search_contact();
};

#endif
