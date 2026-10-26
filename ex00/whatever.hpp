/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:15:10 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 15:56:16 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

#endif
