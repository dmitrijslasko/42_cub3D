/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:29:34 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/06 17:18:36 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define TXT_GREEN		"\033[32m"
# define TXT_RESET		"\033[0m"

// colors
# define BLACK		0x000000
# define WHITE		0xffffff
# define GREY		0x444444
# define DARKGREY	0x0f0f0f

# define RED		0x990000
# define GREEN		0x00FF00
# define BLUE		0x0000FF

# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define PINK		0xFFC0CB
# define BROWN		0xA52A2A
# define GOLD		0xFFD700
# define SILVER		0xC0C0C0
# define LIME		0x32CD32
# define NAVY		0x000020
# define TEAL		0x008080
# define MAROON		0x200000

// color schemes
# define SCHEME_1_LO	TEAL
# define SCHEME_1_HI	YELLOW
# define SCHEME_1_BG	NAVY

# define SCHEME_2_LO	RED
# define SCHEME_2_HI	BLUE
# define SCHEME_2_BG	DARKGREY

#endif
