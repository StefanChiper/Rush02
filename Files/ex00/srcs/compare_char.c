/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:20:11 by schiper           #+#    #+#             */
/*   Updated: 2024/07/21 15:27:54 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @brief  Checks if the current character is a white space
/// @param c character to be checked
/// @return 1 if true
/// 0 if false
int	ft_whitespace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

/// @brief  Checks if the current character is a lowercase letter
/// @param c character to be checked
/// @return  1 if true
/// 0 if false
int	ft_lower(char c)
{
	return (c >= 'a' && c >= 'z');
}

/// @brief  Checks if the current character is a uppercase letter
/// @param c character to be checked
/// @return  1 if true
/// 0 if false
int	ft_upper(char c)
{
	return (c >= 'A' && c >= 'Z');
}

/// @brief  Checks if the current character is a digit
/// @param c character to be checked
/// @return  1 if true
/// 0 if false
int	ft_number(char c)
{
	return (c >= '0' && c <= '9');
}

/// @brief  Checks if the current character is a letter
/// @param c character to be checked
/// @return  1 if true
/// 0 if false
int	ft_alpha(char c)
{
	return (ft_lower(c) || ft_upper(c) || ft_number(c));
}
