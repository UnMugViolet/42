/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:18:09 by pjaguin           #+#    #+#             */
/*   Updated: 2025/05/06 16:00:23 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class PhoneBook;

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		size_t		nbr_inputs;
		std::string fields[5];
	public:
		Contact();
		size_t 				get_inputs_number();
		const std::string 	*get_input_fields();
		void 				set_field(std::string field, std::string value);
		void 				print_contact_single(std::string formatted_fields[]);
		void				create_contact_form(Contact *contact);
		void				print_header(int index);
		void 				contact_seeder(PhoneBook &phone_book);
		// Function to create a contact form with seeded input
		void 				create_contact_form_seeded(const std::string &seeded_input);
};

void	add_contact(PhoneBook &phone_book);

#endif 
