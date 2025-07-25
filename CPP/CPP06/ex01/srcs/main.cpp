/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:37:12 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/25 17:15:57 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.first_name = "John";
	data.last_name = "Doe";
	data.age = 30;

	
	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);
	
	std::cout << BOLD << UNDERLINE << "Initial Pointer value:" << NEUTRAL << " " << &data << std::endl;
	std::cout << BOLD << UNDERLINE << "Deserialized Pointer value:" << NEUTRAL << " " << deserializedData << std::endl << std::endl;

	std::cout << GREEN << BOLD << "Name: " << NEUTRAL << deserializedData->first_name << std::endl;
	std::cout << GREEN << BOLD << "Last Name: " NEUTRAL << deserializedData->last_name << std::endl;
	std::cout << GREEN << BOLD << "Age: " << NEUTRAL << deserializedData->age << std::endl;

}
