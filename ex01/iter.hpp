/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marudlof <marudlof@42.angouleme.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 15:11:39 by marudlof          #+#    #+#             */
/*   Updated: 2026/10/07 15:56:44 by marudlof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void	iter(T* array, const size_t length, F function)
{
	if (array == NULL)
		return ;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif
