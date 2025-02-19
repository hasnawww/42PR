/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errordef.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:49:23 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/02/19 15:11:50 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORDEF_H
#define ERRORDEF_H

#define MALLOC_ERROR	"not knowing how to malloc in common core is crazy"
#define MAP_BORDER		"The map has to be surrounded by '1'"
#define MAP_FORM		"The map has to be rectangular"
#define MISSING_SYMBOL	"The map has to have at least 1 C, 1 P and 1 E"
#define BAD_SYMBOL		"The map has an incorrect symbol"
#define FLOOD_FILL	"The player has to access all the collectibles and exit"
// #define FLOOD_FILL_E	"The player cannot access the exit"
#define FILE_EXTENSION	"The file has to be a '.ber'"

#endif