/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:17:41 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/29 15:57:26 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <unistd.h>

#define MAX_VAL 750

static void	testSubject(void)
{
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];

	srand(time(NULL) ^ ::getpid());
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int	value = rand();

		numbers[i] = value;
		mirror[i] = value;
	}
		std::cout << "a\n" << std::endl;
	//SCOPE
	{
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			delete [] mirror;
			return ;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	delete [] mirror;
	return ;
}

template <typename T>
static void	display(const Array<T>& array, const std::string& name)
{
	std::cout << name << " (size " << array.size() << "): [";
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << (i ? ", " : "") << array[i];
	std::cout << "]" << std::endl;
}

static void	testEmpty(void)
{
	Array<int>	empty;

	display(empty, "empty");
	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "empty[0] threw: " << e.what() << std::endl;
	}
}

static void	testDefaultValues(void)
{
	Array<int>			numbers(3);
	Array<std::string>	words(3);

	display(numbers, "int array");
	std::cout << "string array (size " << words.size() << "): ["
		<< "\"" << words[0] << "\", \"" << words[1] << "\", \""
		<< words[2] << "\"]" << std::endl;
}

static void	testDeepCopy(void)
{
	Array<int>	original(3);

	for (unsigned int i = 0; i < original.size(); i++)
		original[i] = i + 1;

	Array<int>	copy(original);
	Array<int>	assigned;

	assigned = original;

	copy[0] = 42;
	assigned[1] = 84;
	display(original, "original");
	display(copy, "copy    ");
	display(assigned, "assigned");

	Array<int>&	alias = original;

	original = alias;
	display(original, "self    ");
}

static void	testConstAccess(void)
{
	Array<int>	source(2);

	source[0] = 21;
	source[1] = 42;

	const Array<int>	frozen(source);

	std::cout << "frozen[1] = " << frozen[1] << std::endl;
	try
	{
		std::cout << frozen[2] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "frozen[2] threw: " << e.what() << std::endl;
	}
}

int	main(void)
{
	testSubject();
	std::cout << std::endl;
	testEmpty();
	std::cout << std::endl;
	testDefaultValues();
	std::cout << std::endl;
	testDeepCopy();
	std::cout << std::endl;
	testConstAccess();
	return (0);
}
