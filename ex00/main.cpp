/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:04:12 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 15:56:04 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

class Fixed
{
	private:
		int	_value;

	public:
		Fixed(void) : _value(0) {}
		Fixed(int value) : _value(value) {}
		Fixed(const Fixed& other) : _value(other._value) {}
		Fixed&	operator=(const Fixed& other)
		{
			if (this != &other)
				this->_value = other._value;
			return (*this);
		}
		~Fixed(void) {}

		int	getValue(void) const { return (this->_value); }

		bool	operator<(const Fixed& other) const
		{
			return (this->_value < other._value);
		}
		bool	operator>(const Fixed& other) const
		{
			return (this->_value > other._value);
		}
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << "Fixed(" << fixed.getValue() << ")";
	return (out);
}

static void	testSubject(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
}

static void	testEqual(void)
{
	int	a = 42;
	int	b = 42;

	std::cout << "min returns the second one: "
		<< (&::min(a, b) == &b ? "yes" : "no") << std::endl;
	std::cout << "max returns the second one: "
		<< (&::max(a, b) == &b ? "yes" : "no") << std::endl;
}

static void	testOtherTypes(void)
{
	char	e = 'x';
	char	f = 'a';

	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

	double	g = 4.2;
	double	h = -1.5;

	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
	std::cout << "max(g, h) = " << ::max(g, h) << std::endl;

	Fixed	i(21);
	Fixed	j(84);

	::swap(i, j);
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
	std::cout << "max(i, j) = " << ::max(i, j) << std::endl;
}

int	main(void)
{
	testSubject();
	std::cout << std::endl;
	testEqual();
	std::cout << std::endl;
	testOtherTypes();
	return (0);
}
