/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub1d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:02:43 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 18:52:28 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB1D_H
# define CUB1D_H

# include	"get/get_next_line.h"
# include	<mlx.h>
# include	<math.h>
# include <limits.h>

# define PI 3.14159
# define MIN 0.001
# define SIZE 16
# define STEPS 6
# define SIZEMINI 8
# define SIZE_IMG 64
# define WIDTH 1600
# define HEIGHT 800
# define NUMS_RAYS 1600
# define RED 0xFF0000
# define FOV 1.047197

typedef struct s_playerr
{
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
}t_playerr;

typedef enum s_side
{
	zero,
	north,
	south,
	east,
	west
}	t_player;

typedef struct s_var
{
	double	disttoplan;
	double	projplan;
	double	disttowall;
	int		start;
	int		end;
}t_var;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	yi;
	int	xi;
	int	y;
	int	x;
	int	diff;
}				t_line;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bts_pxt;
	int		endn;
	int		len;
	int		width;
	int		height;
}t_image;

typedef struct s_xtr
{
	t_image	*n_orth;
	t_image	*w_est;
	t_image	*s_outh;
	t_image	*e_ast;
}t_xtr;

typedef struct s_map
{
	int		player;
	char	**map;
	int		ort;
	int		i;
	double	ip;
	int		j;
	double	jp;
}t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
}t_mlx;

typedef struct s_content
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
	int		ff;
	int		cc;
	char	*north_p;
	char	*south_p;
	char	*west_p;
	char	*east_p;
	int		*fn;
	int		*cn;
}	t_content;

typedef struct s_rays
{
	double	xsp;
	double	ysp;
	double	rayangle;
	double	xi;
	double	yi;
	double	horzy;
	double	horzx;
	double	vrzay;
	double	vrzax;
	double	prop;
	int		view_down;
	int		view_up;
	int		view_right;
	int		view_left;
	double	next_x;
	double	next_y;
	int		foundh;
	int		foundv;
	double	hdis;
	double	vdis;
	double	dis;
	int		wall;
	int		offx;
	int		offy;
}t_rays;

typedef struct s_weapon
{
	void	*ptr;
	char	*addr;
	unsigned int *data;
	int		bts_pxt;
	int		endn;
	int		len;
	int		width;
	int		height;
}t_weapon;

typedef struct s_big
{
	int			i;
	int			j;
	int			fd;
	char		*line;
	char		*file;
	t_map		map;
	t_content	content;
	t_xtr		texture;
	t_image		image;
	t_mlx		mlx;
	t_playerr	player;
	t_weapon	weapon;
}	t_big;

int		*ft_aatoi(char *str, int i, int j);
void	ft_error(char *str);
int		ft_isalnum(int c);
void	check_map_file(t_big *p);
char	**ft_split(char const *s, char c);
void	read_map(t_big *p, int i, int j);
void	ft_mooove2(int keycode, t_big *p, int s);
int		ft_mooove(int keycode, t_big *p);
void	check_mfile3(t_big *p, int i, char **side);
void	check_mfile4(t_big *p, int i, int **side);
void	check_mfile2(t_big *p);
void	get_map2(t_big *p);
void	get_map(t_big *p);
void	getl(t_big *p);
void	get_contents(t_big *p);
void	check_map(t_big *p);
int		check_zerov2(char c);
void	ckeck_zero(t_big *p);
void	check_texture(t_big *p);
void	get_player2(t_big *p, int ort);
void	get_player1(t_big *p);
void	get_player(t_big *p);
int		mouse(int keycode, t_big *p);
void	get_player2(t_big *p, int ort);
void	get_player1(t_big *p);
void	get_player(t_big *p);
void	get_dataa2(t_big *p);
void	get_dataa(t_big *p);
void	content_init(t_big *p);
void	check_path(char *str, const char *s);
t_image	*get_texture_image(t_big *p, char *str);
int		ft_instr(const char *s, int c);
void	mini_map(t_big *p);
void	get_xy(t_big *p);
void	image_init(t_big *p);
void	get_colors(t_big *p);
int		get_rgb(int red, int green, int blue);
int		mouse_turn(int keycode, int i, int j, t_big *p);
void	get_correct(t_big *p);
void	exito(t_big *p);
/*********************raycasting*************************/
void	draw_line(t_big *data, t_point a, t_point b);
void	cast_rays(t_big *p);
double	dis(double x1, double y1, double x2, double y2);
void	check_angle(t_rays	*ray);
void	get_2d_view(t_rays *ray);
void	get_3d_map(t_big *data, t_rays *ray);
int		hit_wall(t_big *data, double x, double y);
void	init_3d_variable(t_var *var, t_rays *ray, t_big *data);
void	init_horizontal(t_big *data, t_rays *ray);
void	init_vertical(t_big *data, t_rays *ray);
void	my_mlx_pixel_put(t_big *data, int x, int y, int color);
void	get_dis_rays(t_big *data, t_rays *ray);
void	get_deriction(t_big *data, t_rays *ray, int i, int j);
#endif