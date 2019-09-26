#include <stdlib.h>
#include "array.h"
#include "block.h"
#include "dicto.h"
#include "singletone.h"
#include "wutils.h"
#include "ft_printf.h"

static void	config_payload(t_dicto_payload *conf, t_dicto_element *els)
{
	conf->length = 6;
	els[0] = (t_dicto_element){
		.key = "id",
		.length = 2,
		.max_length = 1,
		.is_valid = NULL
	};
	els[1] = (t_dicto_element){
		.key = "type",
		.length = 4,
		.max_length = 4,
		.is_valid = NULL
	};
	els[2] = (t_dicto_element){
		.key = "north",
		.length = 5,
		.max_length = 1,
		.is_valid = NULL
	};
	els[3] = (t_dicto_element){
		.key = "south",
		.length = 5,
		.max_length = 1,
		.is_valid = NULL
	};
	els[4] = (t_dicto_element){
		.key = "east",
		.length = 4,
		.max_length = 1,
		.is_valid = NULL
	};
	els[5] = (t_dicto_element){
		.key = "west",
		.length = 4,
		.max_length = 1,
		.is_valid = NULL
	};
	conf->els = els;
}

int			block_parse_pairs(t_block *b, void *pairs_p)
{
	t_block			***block_metadata;
	t_texture		***tex_metadata;
	unsigned char	*s;
	unsigned int	id;

	block_metadata = singletone_block();
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "id");
	if (s == NULL || s[0] == '\0' || s[1] != '\0')
		return (-2);
	id = (unsigned int)*s;
	(*block_metadata)[id] = b;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "type");
	if (ft_strlen((const char *)s) != 4)
		return (-3);
	if (ft_strncmp((const char *)s, "void", 4) == 0)
		b->type = T_BL_VOID;
	else if (ft_strncmp((const char *)s, "wall", 4) == 0)
		b->type = T_BL_WALL;
	else
		return (-4);
	tex_metadata = singletone_texture();
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "north");
	if (s[0] == '\0' || s[1] != '\0')
		return (-5);
	b->tex_north = *s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "south");
	if (s[0] == '\0' || s[1] != '\0')
		return (-5);
	b->tex_south = *s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "east");
	if (s[0] == '\0' || s[1] != '\0')
		return (-5);
	b->tex_east = *s;
	s = (unsigned char *)pair_get((t_pairs *)pairs_p, "west");
	if (s[0] == '\0' || s[1] != '\0')
		return (-5);
	b->tex_west = *s;
	// TODO is this the wanted behaviour ?
	if ((*tex_metadata)[b->tex_east] == NULL
		|| (*tex_metadata)[b->tex_north] == NULL
		|| (*tex_metadata)[b->tex_south] == NULL
		|| (*tex_metadata)[b->tex_west] == NULL)
		return (-6);
	return (0);
}

int			block_parse(const char **input)
{
	t_dicto_payload	config;
	t_dicto_element	els[6];
	t_pairs			*pairs;
	t_block			*block;
	int				ret;

	config_payload(&config, els);
	pairs = dicto(input, (const t_dicto_payload *)&config);
	if (pairs == NULL)
	{
		ft_dprintf(2, "error on dicto\n");
		return (-1);
	}
	ret = -1;
	if ((block = (t_block *)block_new()) != NULL)
	{
		// TODO need to free id of this block if failure
		if ((ret = block_parse_pairs(block, pairs)) != 0)
		{
			block_del(block);
			block = NULL;
		}
	}
	array_delete((t_array *)pairs, &pair_delete);
	return (ret);
}
