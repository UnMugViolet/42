/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:37:12 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/07/23 16:44:47 by unmugviolet      ###   ########.fr       */
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

	std::cout << "Name: " << deserializedData->first_name << std::endl;
	std::cout << "Last Name: " << deserializedData->last_name << std::endl;
	std::cout << "Age: " << deserializedData->age << std::endl;
}
