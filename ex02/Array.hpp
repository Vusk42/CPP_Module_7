/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:03:12 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 16:11:20 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		T*				_elements;
		unsigned int	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array(void);

		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;

		unsigned int	size(void) const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

# include "Array.tpp"

#endif
