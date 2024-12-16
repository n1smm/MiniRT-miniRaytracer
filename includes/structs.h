/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuvan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:58:29 by tjuvan            #+#    #+#             */
/*   Updated: 2024/12/15 13:42:51 by tjuvan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTS_H
# define STRUCTS_H

# ifndef MACROS
#  define EPSILON 0.0001
#  define PI 3.1415926535
#  define POINT t_vect
#  define SQUARE 20
#  define ANGLE_SIZE 0.1
#  define MAX_OBJECTS 128
#  define MAX_LIGHTS 128
#  define MAX_PICS 128
# endif

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define DARK_GRAY 0x404040
# define LIGHT_GRAY 0xC0C0C0
# define ORANGE 0xFFA500
# define PINK 0xFFC0CB
# define PURPLE 0x800080
# define BROWN 0xA52A2A
# define LIME 0xBFFF00
# define OLIVE 0x808000
# define MAROON 0x800000
# define NAVY 0x000080
# define TEAL 0x008080
# define AQUA 0x00FFFF

# include <stdbool.h>

typedef struct s_vect
{
	float		x;
	float		y;
	float		z;
}				t_vect;
typedef struct s_ray
{
	POINT		pos;

	t_vect		dir;
}				t_ray;

// typedef struct s_pos
// {
// 	float		x;
// 	float		y;
// 	float		z;
// }				t_pos;

typedef struct s_picture
{
	void		*pic;
	char		*path;
	char		*data;
	int			bpp;
	int			endian;
	int			line_len;
	int			w;
	int			h;
	int			index;
}				t_picture;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_calc
{
	int			tex_theta;
	int			tex_height;
	int			tex_phi;
	int			tex_x;
	int			tex_y;
	float		theta;
	float		phi;
	float		square_theta;
	float		square_phi;
	float		scale_theta;
	float		square_height;
	float		u;
	float		v;
	float		height;

}				t_calc;

typedef struct s_quad
{
	float		a;
	float		b;
	float		c;
	t_vect		acomp;
	float		acomp2;
	float		bcomp;
	float		bcomp2;
	float		ccomp;
	float		ccomp2;
	float		cos_square;
	float		sin_square;
	t_vect		comp;
	t_vect		pdelt;
	t_vect		b1;
	t_vect		c1;
}				t_quad;

typedef struct s_caps
{
	float		visibility;
	float		visibility2;
	float		chosen_t;
	POINT		p;
	POINT		pcenter;
	t_vect		pdelt;
	t_vect		normal;
	float		t;
	float		t2;
}				t_caps;

typedef struct s_pltex
{
	float		u;
	float		v;
	float		dot1;
	float		dot2;
	float		dot3;
	int			tex_x;
	int			tex_y;
	bool		orientation;
	int			color_offset;
	int			color;
	t_rgb		color_v;
}				t_pltex;

typedef struct s_hitinfo
{
	POINT		p;
	t_vect		normal;
	float		t;
	bool		is_outside;
	t_rgb		rgb;
	t_calc		calc;
}				t_hitinfo;

typedef struct s_intersections
{
	POINT		t0;
	POINT		t1;
	int			refl_angle;
	int			nb_collision;
}				t_intersections;

typedef struct s_ambient
{
	float		ratio;
	t_rgb		rgb;
}				t_ambient;

typedef struct s_camera
{
	POINT		pos;
	t_vect		dir;
	t_vect		forward;
	t_vect		right;
	t_vect		up;

	float		fov;
}				t_camera;

typedef struct s_light
{
	POINT		pos;
	float		bright;
	float		nb_rays;
	float		len_ray;
	t_rgb		rgb;
}				t_light;

typedef struct s_sphere
{
	POINT		pos;
	float		diameter;
	float		radius;
	t_rgb		rgb;
	int			nb_params;
	bool		checker;
	bool		bonus;
	t_picture	tex;
	t_picture	tex_normal;
	float		brilliance;
}				t_sphere;

typedef struct s_cylinder
{
	POINT		pos;
	POINT		p1;
	POINT		p2;
	t_vect		dir;
	float		diameter;
	float		radius;
	float		height;
	t_rgb		rgb;
	int			nb_params;
	bool		checker;
	bool		bonus;
	t_picture	tex;
	t_picture	tex_normal;
	float		brilliance;
}				t_cylinder;

typedef struct s_cone
{
	POINT		pos;
	POINT		p1;
	POINT		p2;
	t_vect		dir;
	float		diameter;
	float		radius;
	float		height;
	float		theta_r;
	float		theta_d;
	t_rgb		rgb;
	bool		checker;
	bool		bonus;
	int			nb_params;
	t_picture	tex;
	t_picture	tex_normal;
	float		brilliance;
}				t_cone;

typedef struct s_plane
{
	POINT		pos;
	t_vect		posn;
	t_vect		vect;
	t_rgb		rgb;
	t_rgb		rgb_norm;
	int			nb_params;
	bool		checker;
	bool		bonus;
	t_picture	tex;
	t_picture	tex_norm;
	float		brilliance;
}				t_plane;

typedef struct s_img
{
	void		*img_ptr;
	char		*pix_ptr;
	int			bpp;
	int			endian;
	int			line_len;
	float		width;
	float		height;
}				t_img;

typedef enum s_type_obj
{
	NOTHING,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	HYPERBOLOID,
	END
}				t_type_obj;

typedef struct s_objs
{
	void		*object;
	t_type_obj	type_obj;
}				t_objs;

typedef struct s_data
{
	bool		invalid;
	bool		not_number;
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		img;
	t_picture	pics[MAX_PICS - 1];
	int			pic_idx;
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_objs		*obj;
	t_hitinfo	hit;
	t_light		lights[MAX_LIGHTS - 1];
	t_quad		quad;
	int			nb_lights;
	int			nb_pics;
	int			nb_objs;
	int			nb_main;
	int			nb_amb;
	int			nb_camera;
	float		img_ratio;
	int			index_objs;
	t_vect		light_dir;
	float		dist_to_light;
	float		a;
	float		b;
	float		c;
	float		t1;
	float		t2;
	float		vis1;
	float		vis2;
	POINT		pcenter;
	float		chosen_t;
}				t_data;

#endif
