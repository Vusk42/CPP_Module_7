/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:17:12 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/09 17:58:57 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

class Awesome
{
	private:
		int	_n;

	public:
		Awesome(void) : _n(0) {}
		Awesome(int n) : _n(n) {}
		Awesome(const Awesome& other) : _n(other._n) {}
		Awesome&	operator=(const Awesome& other)
		{
			if (this != &other)
				this->_n = other._n;
			return (*this);
		}
		~Awesome(void) {}

		int	getN(void) const { return (this->_n); }
		void	setN(int n) { this->_n = n; }
};

std::ostream&	operator<<(std::ostream& out, const Awesome& awesome)
{
	out << "Awesome(" << awesome.getN() << ")";
	return (out);
}

template <typename T>
void	print(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void	twice(T& element)
{
	element = element + element;
}

void	shoutout(const Awesome& awesome)
{
	std::cout << awesome << "! ";
}

void	increase(Awesome& awesome)
{
	awesome.setN(awesome.getN() + 1);
}

static void	testInt(void)
{
	int	numbers[] = {0, 1, 2, 3, 4};

	std::cout << "int array:          ";
	::iter(numbers, 5, ::print<int>);
	std::cout << std::endl;

	::iter(numbers, 5, ::twice<int>);
	std::cout << "after twice:        ";
	::iter(numbers, 5, ::print<int>);
	std::cout << std::endl;
}

static void	testConstArray(void)
{
	const std::string	words[] = {"templates", "are", "fun"};

	std::cout << "const string array: ";
	::iter(words, 3, ::print<std::string>);
	std::cout << std::endl;
}

static void	testClass(void)
{
	Awesome	tab[] = {Awesome(1), Awesome(2), Awesome(3)};

	std::cout << "class array:        ";
	::iter(tab, 3, ::shoutout);
	std::cout << std::endl;

	::iter(tab, 3, ::increase);
	std::cout << "after increase:         ";
	::iter(tab, 3, ::print<Awesome>);
	std::cout << std::endl;
}

static void	testEdgeCases(void)
{
	double	empty[1] = {0.0};

	std::cout << "empty length:       ";
	::iter(empty, 0, ::print<double>);
	std::cout << "(nothing printed)" << std::endl;

	std::cout << "null array:         ";
	::iter(static_cast<double*>(NULL), 42, ::print<double>);
	std::cout << "(nothing printed)" << std::endl;
}

int	main(void)
{
	testInt();
	testConstArray();
	testClass();
	testEdgeCases();
	return (0);
}
