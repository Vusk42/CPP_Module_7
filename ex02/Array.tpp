/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:13:06 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/09 17:59:16 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _elements(new T[0]()), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array& other) : _elements(new T[other._size]()),
	_size(other._size)
{
	for (unsigned int i = 0; i < this->_size; i++)
		this->_elements[i] = other._elements[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T*	elements = new T[other._size]();

		for (unsigned int i = 0; i < other._size; i++)
			elements[i] = other._elements[i];
		delete [] this->_elements;
		this->_elements = elements;
		this->_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->_elements;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return (this->_elements[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return (this->_elements[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what(void) const throw()
{
	return ("index is out of bounds");
}

#endif
