/* ************************************************************************** */
/*                                                                            */
/*   hanoi.h                           $$$$$$$$\ $$\   $$\ $$$$$$\  $$$$$$\   */
/*                                     $$  _____|$$ |  $$ |\_$$  _|$$  __$$ | */
/*                                     $$ |      \$$\ $$  |  $$ |  $$ /  $$ | */
/*                                     $$$$$\     \$$$$  /   $$ |  $$$$$$$$ | */
/*     By: Erwan Plessis               $$  __|    $$  $$<    $$ |  $$  __$$ | */
/*                                     $$ |      $$  /\$$\   $$ |  $$ |  $$ | */
/*                                     $$$$$$$$\ $$ /  $$ |$$$$$$\ $$ |  $$ | */
/*                                     \________|\__|  \__|\______|\__|  \__| */
/*                                                                            */
/* ************************************************************************** */
#ifndef	__HANOI_H__
# define __HANOI_H__

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define couleur(param) printf("\033[%sm",param)

void 		ft_put_header();
int 		ft_level_selec();
void		ft_putchar(char c);
int 		ft_char_atoi(char *str);
void 		ft_put_disks(char *disk);
int 		ft_string_atoi(char *str);
char 		ft_strlowcase(char *string);
int			ft_check_level(char *level);
void 		ft_put_level_selected(int level);
int 		ft_check_t3(char *T3, int level);
int 		ft_check_mov_entry(char *mouvement);
void 		ft_put_rules(char *T1, char *T2, char *T3, int level);
void 		ft_stack_init(char *T1, char *T2, char *T3, int level);
void 		ft_loop_game_play(char *T1, char *T2, char *T3, int level);
void 		ft_put_hanoi_tower(char *T1, char *T2, char *T3, int level);
int 		ft_mouv_disk(char *T1, char *T2, char *T3, char mouvement[3], int level, int *cpt, FILE *file);

#endif