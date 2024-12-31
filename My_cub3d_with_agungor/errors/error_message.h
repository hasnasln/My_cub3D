/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:50:08 by agungor           #+#    #+#             */
/*   Updated: 2024/09/01 16:27:52 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define COLOUR_STR "\033[38;2;000;000;000m"
# define CUB_ERROR "  !! Your file does not have a .cub extension !!  "
# define NOT_OPEN "  !! The file with the relevant \
extension could not be opened !! "
# define ARGUMAN_ERROR "  !! Invalid Argument Number.\
	Please Enter [./cub3D map/path] !! "
# define ENCIRCLING_WALLS_ERROR "  !! The map must be\
 completely covered with walls !!  "
# define MALLOC_ERROR "  !! Memory allocation failed. \
Please contact your system administrator !!  "
# define MLX_INIT_ERROR "  !! Unable to initialize MinilibX graphics library. \
mlx_init function returned the NULL. Exiting program.  !!  "
# define MLX_WINDOW_ERROR "  !! Unable to create window. mlx_new_window \
function returned the NULL. Exiting program !!  "
# define XPM_SO_ERROR "  !! Failed to load the south wall image. \
Please check your file with .xpm extension. !!  "
# define XPM_NO_ERROR "  !! Failed to load the north wall image. \
Plase check your file with .xpm extension. !!  "
# define XPM_EA_ERROR "  !! Failed to load the east wall image. \
Plase check your file with .xpm extension. !!  "
# define XPM_WE_ERROR "  !! Failed to load west wall image. \
Plase check your file with .xpm extension. !!  "
# define MLX_SO_ERROR "  !! Failed to load the south wall image. Please check your file with .xpm extension.\
 mlx_xpm_file_to_image function returned the NULL. Exiting program. !!  "
# define MLX_NO_ERROR "  !! Failed to load the north wall image. Plase check your file with .xpm extension.\
 mlx_xpm_file_to_image function returned the NULL. Exiting program. !!  "
# define MLX_WE_ERROR "  !! Failed to load west wall image. Plase check your file with .xpm extension.\
 mlx_xpm_file_to_image function returned the NULL. Exiting program. !!  "
# define MLX_EA_ERROR "  !! Failed to load the east wall image. \
Plase check your file with .xpm extension.\
 mlx_xpm_file_to_image function returned the NULL. Exiting program. !!  "
# define MLX_ADDR_ERROR "  !! Failed to retrieve image data. \
mlx_get_data_addr function returned NULL. !!  "
# define MLX_MAIN_IMG_ERROR "  !! Failed to retrieve image data. \
mlx_new_image function returned NULL. !!  "
# define INVALIED_ELEMENT "  !! There is an invalid element in the map !!  "

typedef struct s_colour
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_colour;

int					error_center(int error_num);
void				string_check(char *s, int loop_count, int sleep_time,
						t_colour rgb);

#endif
