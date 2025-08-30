#ifndef PARSER_H
# define PARSER_H

/* Structs */
typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bits_per_pxl;
	int		endian;
	int		l_len;
}				t_img;

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
	int		x;
	int		y;
}				t_map;

typedef struct s_line
{
	char			*current;
	struct s_line	*next;
}				t_line;

typedef struct s_cub	t_cub;

/* Functions */
// src/loader/
// src/loader/load_images.c
void	load_texture(t_cub *cub, t_img *texture_img, char *path);

// src/parser/
// src/parser/config_parser.c
void	parse_texture(char *line, t_cub *cub);
void	parse_color(char *line, t_cub *cub);
int		all_configs_set(t_cub *cub);
// src/parser/main_parser.c
int		main_parser(char *filename, t_cub *cub);
// src/parser/map_list_parser.c
t_line	*new_node(char *line);
t_line	*add_node_back(t_line **list_head, t_line *new_node);
void	free_list(t_line *head);
int		count_lines(t_line	*map_list);
// src/parser/map_parser.c
void	parse_map_grid(char *line, t_cub *cub, int fd);
// src/parser/map_validator_utils.c
int		flood_fill(char **map_copy, t_cub *cub, int y, int x);
int		get_map_width(char **map);
char	**duplicate_map(char **map);
int		has_only_valid_characters(char **map);
void	player_coordinates(char **map, t_cub *cub);
// src/parser/map_validator.c
int		is_map_closed(t_cub *cub);

// src/validator/
// src/validator/valid_format.c
int		valid_format(char *str);

#endif