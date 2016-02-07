/* ************************************************************************** */
/*                                                                            */
/*   hanoi.c                           $$$$$$$$\ $$\   $$\ $$$$$$\  $$$$$$\   */
/*                                     $$  _____|$$ |  $$ |\_$$  _|$$  __$$ | */
/*                                     $$ |      \$$\ $$  |  $$ |  $$ /  $$ | */
/*                                     $$$$$\     \$$$$  /   $$ |  $$$$$$$$ | */
/*   By: Erwan PLESSIS                 $$  __|    $$  $$<    $$ |  $$  __$$ | */
/*                                     $$ |      $$  /\$$\   $$ |  $$ |  $$ | */
/*                                     $$$$$$$$\ $$ /  $$ |$$$$$$\ $$ |  $$ | */
/*                                     \________|\__|  \__|\______|\__|  \__| */
/*                                                                            */
/* ************************************************************************** */
#include "hanoi.h"

void	ft_putchar(char c)
{
	write(1, &c,1);
}

///////////////////////////////////////////////////////////////////////////
//                      CONVERT UPERCASE INTO LOWERCASE                  //
///////////////////////////////////////////////////////////////////////////

char 	ft_strlowcase(char *string)
{
	int i;

	i = 0;
	while(string[i] != '\0')
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
		{
			string[i] = string[i]+32;
		}
		i++;
	}
	return(*string);
}	

///////////////////////////////////////////////////////////////////////////
//                      ASCII TO INTEGER FOR A STRING                    //
///////////////////////////////////////////////////////////////////////////

int 		ft_string_atoi(char *str)
{
	int 	i;
	int		result;
	int 	negative;

	result = 0;
	i = 0;
	negative = 0;
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while (*str)
	{
		result = *str - '0' + result * 10;
		str++;
	}
	if (negative)
	{
		result = 0 - result;
	}
	return (result);
}

///////////////////////////////////////////////////////////////////////////
//                      ASCII TO INTEGER FOR A CHAR                      //
///////////////////////////////////////////////////////////////////////////

int 		ft_char_atoi(char *str)
{
	int		result;

	result = 0;
	result = *str - '0' + result * 10;
	return (result);
}

///////////////////////////////////////////////////////////////////////////
//               CHECK IF THE LEVEL ENTERED IS > 3 and < 10              //
///////////////////////////////////////////////////////////////////////////


int			ft_check_level(char *level)
{
	int 	numeric_level;

	numeric_level = ft_string_atoi(level);
	if (numeric_level < 3 || numeric_level > 10)
		return (-1);
	return (numeric_level);
}

///////////////////////////////////////////////////////////////////////////
//               CHECK IF THE MOVEMENT ENTERED IS CORRECT                //
///////////////////////////////////////////////////////////////////////////

int 		ft_check_mov_entry(char *mouvement)
{
	if (mouvement[0] < '1' || mouvement[0] > '3')
		return (0);
	if (mouvement[1] < '1' || mouvement[1] > '3')
		return (0);
	if (mouvement[2] != '\0' )
		return (0);
	return (1);
}

///////////////////////////////////////////////////////////////////////////
//                        PUT HEADER AT BEGINNING                        //
///////////////////////////////////////////////////////////////////////////

void 		ft_put_header()
{
	couleur("34");
	printf("\n");
	printf("$$$$$$$$$\\                                                 $$\\                 $$\\   $$\\                             $$\\ $$\\ \n");
	printf("\\__$$  __|                                                 $$ |                $$ |  $$ |                            \\__|\\__|\n");
	printf("   $$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\   $$$$$$$\\        $$$$$$$ | $$$$$$\\        $$ |  $$ | $$$$$$\\  $$$$$$$\\   $$$$$$\\  $$\\ \n");
	printf("   $$ |$$  __$$\\ $$ |  $$ |$$  __$$\\ $$  _____|      $$  __$$ |$$  __$$\\       $$$$$$$$ | \\____$$\\ $$  __$$\\ $$  __$$\\ $$ |\n");
	printf("   $$ |$$ /  $$ |$$ |  $$ |$$ |  \\__|\\$$$$$$\\        $$ /  $$ |$$$$$$$$ |      $$  __$$ | $$$$$$$ |$$ |  $$ |$$ /  $$ |$$ |\n");
	printf("   $$ |$$ |  $$ |$$ |  $$ |$$ |       \\____$$\\       $$ |  $$ |$$   ____|      $$ |  $$ |$$  __$$ |$$ |  $$ |$$ |  $$ |$$ |\n");
	printf("   $$ |\\$$$$$$  |\\$$$$$$  |$$ |      $$$$$$$  |      \\$$$$$$$ |\\$$$$$$$\\       $$ |  $$ |\\$$$$$$$ |$$ |  $$ |\\$$$$$$  |$$ |\n");
	printf("   \\__| \\______/  \\______/ \\__|      \\_______/        \\_______| \\_______|      \\__|  \\__| \\_______|\\__|  \\__| \\______/ \\__|\n");
	printf("                                                                             © 2015 Exia - Julien REGINSTER, Mathias ARREDONDO, Erwan PLESSIS\n");
	couleur("0");
	printf("\n");
}

///////////////////////////////////////////////////////////////////////////
//                    PUT LEVEL SELECTED BY GAMER                        //
///////////////////////////////////////////////////////////////////////////

void 		ft_put_level_selected(int level)
{
	couleur("35");
	printf("\n ----------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|                                                                  NIVEAU %d                                                                   |\n", level);
	printf(" ----------------------------------------------------------------------------------------------------------------------------------------------\n");
	couleur("0");
	printf("\n");
}

///////////////////////////////////////////////////////////////////////////
//                        ARRAYS INITIALIZATION                          //
///////////////////////////////////////////////////////////////////////////

void 		ft_stack_init(char *T1, char *T2, char *T3, int level)
{
	int 	i;

	i = 0;
	while (level != 0)
	{
		T1[i] = level + '0';
		i++;
		level--;
	}
	T1[i] = '\0';
	T2[0] = '\0';
	T3[0] = '\0';
}

///////////////////////////////////////////////////////////////////////////
//                       CHECK VALUE ENTERED                             //
///////////////////////////////////////////////////////////////////////////

int 		ft_level_selec()
{
	int		level;
	char	str_level[10000];

	printf("Choisi un niveau de difficulté entre 3 et 10 ?\n");
	scanf("%s", str_level);
	while(getchar() != '\n');
	while (ft_check_level(str_level) == -1)
	{
		couleur("31");
		printf("\nArrête de faire le singe et choisis un niveau entre 3 et 10 pour jouer !\n");
		couleur("0");
		scanf("%s", str_level);
		while(getchar() != '\n');
	}
	level = ft_string_atoi(str_level);
	return (level);
}

///////////////////////////////////////////////////////////////////////////
//                             PUT HANOI TOWER                           //
///////////////////////////////////////////////////////////////////////////

void 		ft_put_disks(char *disk)
{
	char empty[50] = "                       |                       ";
	char one[50]   = "                      1|1                      ";
	char two[50]   = "                     22|22                     ";
	char three[50] = "                    333|333                    ";
	char four[50]  = "                   4444|4444                   ";
	char five[50]  = "                  55555|55555                  ";
	char six[50]   = "                 666666|666666                 ";
	char seven[50] = "                7777777|7777777                ";
	char eight[50] = "               88888888|88888888               ";
	char nine[50]  = "              999999999|999999999              ";
	char ten[50]   = "             0000000000|0000000000             ";

	if (*disk == 0)
		printf("%s", empty);
	if (*disk == '1')
		printf("%s", one);
	if (*disk == '2')
	{
		couleur("01;34");
		printf("%s", two);
		couleur("0");
	}
	if (*disk == '3')
	{
		couleur("01;35");
		printf("%s", three);
		couleur("0");
	}
	if (*disk == '4')
	{
		couleur("34");
		printf("%s", four);
		couleur("0");
	}
	if (*disk == '5')
	{
		couleur("36");	
		printf("%s", five);
		couleur("0");
	}
	if (*disk == '6')
	{
		couleur("35");
		printf("%s", six);
		couleur("0");
	}
	if (*disk == '7')
	{
		couleur("32");
		printf("%s", seven);
		couleur("0");
	}
	if (*disk == '8')
	{
		couleur("33");
		printf("%s", eight);
		couleur("0");
	}
	if (*disk == '9')
	{
		couleur("31");
		printf("%s", nine);
		couleur("0");
	}
	if (*disk == ':')
	{
		couleur("01;30");
		printf("%s", ten);
		couleur("0");
	}
}

void 		ft_put_hanoi_tower(char *T1, char *T2, char *T3, int level)
{
	int 	i;
	int 	tab;

	i = 0;
	while(i != level)
		i++;
	level++;
	tab = level;
	while(level != 1)
	{
		ft_put_disks(&T1[i - 1]);
		ft_put_disks(&T2[i - 1]);
		ft_put_disks(&T3[i - 1]);
		printf(" \n");
		level--;
		tab = level;
		i--;
	}
}

///////////////////////////////////////////////////////////////////////////
//                        CHECK T3 FULL AND SORTED                       //
///////////////////////////////////////////////////////////////////////////

int 		ft_check_t3(char *T3, int level)
{
	int 	i;
	int 	cpt;

	i = 0;
	cpt = 0;
	while (T3[i] != '\0')
	{
		i++;
	}
	if (i != level)
		return (1);
	else
	{
		i = 0;
		while (T3[i] != '\0')
		{
			if (T3[i] < T3[i + 1])
				cpt++;
			i++;
		}
		if (cpt == (level - 1))
			return (0);
	}
	return (0);
}

int 		ft_mouv_disk(char *T1, char *T2, char *T3, char mouvement[3], int level, int *cpt, FILE *file)
{
	int 	i;
	int 	j;
	int 	tmp;
	int 	dest;
	int 	source;
	int 	t1_is_empty;
	int 	t2_is_empty;
	int 	t3_is_empty;
	char 	t1[123] = "                      T.1                                            T.2                                            T.3   ";

	i = 0;
	j = 0;
	tmp = 0;
	t1_is_empty = 0;
	t2_is_empty = 0;
	t3_is_empty = 0;
	dest = ft_char_atoi(&mouvement[1]);
	source = ft_char_atoi(&mouvement[0]);

	///////////////////////////////////////////////////////////////////////////
	//                           CHECK SOURCE IS EMPTY                       //
	///////////////////////////////////////////////////////////////////////////

	if (source == 1)
	{
		while(T1[i] != '\0')
			i++;
		if (i == 0)
		{
			couleur("31");
			printf("T1 est vides\n");
			couleur("0");
			return (1);
		}
	}
	else if (source == 2)
	{
		while(T2[i] != '\0')
			i++;
		if (i == 0)
		{
			couleur("31");
			printf("T2 est vide\n");
			couleur("0");
			return (1);
		}
	}
	else if (source == 3)
	{
		while(T3[i] != '\0')
			i++;
		if (i == 0)
		{
			couleur("31");
			printf("T3 est vide\n");
			couleur("0");
			return (1);
		}
	}

	///////////////////////////////////////////////////////////////////////////
	//                          CHECK DEST IS EMPTY                          //
	///////////////////////////////////////////////////////////////////////////

	i = 0;
	if (dest == 1)
	{
		while(T1[i] != '\0')
			i++;
		if (i == 0)
			t1_is_empty = 1;
	}
	else if (dest == 2)
	{
		while(T2[i] != '\0')
			i++;
		if (i == 0)
			t2_is_empty = 1;
	}
	else if (dest == 3)
	{
		while(T3[i] != '\0')
			i++;
		if (i == 0)
			t3_is_empty = 1;
	}

	///////////////////////////////////////////////////////////////////////////
	//                          CHECK DEST IS FULL                           //
	///////////////////////////////////////////////////////////////////////////

	i = 0;
	if (dest == 1)
	{
		while(T1[i] != '\0')
			i++;
		if (i == level)
		{
			couleur("31");
			printf("T1 est déja pleine\n");
			couleur("0");
			return (1);
		}
	}
	if (dest == 2)
	{
		while(T2[i] != '\0')
			i++;
		if (i == level)
		{
			couleur("31");
			printf("T2 est déja pleine\n");
			couleur("0");
			return (1);
		}
	}
	else if (dest == 3)
	{
		while(T3[i] != '\0')
			i++;
		if (i == level)
			return (1);
	}

	///////////////////////////////////////////////////////////////////////////
	//                               MOVING PART                             //
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	//                         COPY FROM SOURCE DISK                         //
	///////////////////////////////////////////////////////////////////////////

	i = 0;
	if (source == 1)
	{
		while(T1[i + 1] != '\0')
			i++;
		tmp = T1[i];
	}
	else if (source == 2)
	{
		while(T2[i + 1] != '\0')
			i++;
		tmp = T2[i];
	}
	else if (source == 3)
	{
		while(T3[i + 1] != '\0')
			i++;
		tmp = T3[i];
	}

	///////////////////////////////////////////////////////////////////////////
	//                             ADD TO DEST DISK                          //
	///////////////////////////////////////////////////////////////////////////

	i = 0;
	if (dest == 1)
	{
		while(T1[i] != '\0')
			i++;
		if (i == 0)
		{
			T1[i] = tmp;
			T1[i + 1] = '\0';
		}
		else
			if (T1[i - 1] > tmp)
			{
				T1[i] = tmp;
				T1[i + 1] = '\0';
			}
			else
			{
				couleur("31");
				printf("On ne peut placer un disque que sur un autre disque "
						"plus grand que lui ou sur un emplacement vide\n");
				couleur("0");
				return (1);
			}
	}
	else if (dest == 2)
	{
		while(T2[i] != '\0')
			i++;
		if (i == 0) 
		{
			T2[i] = tmp;
			T2[i + 1] = '\0';
		}
		else
			if (T2[i - 1] > tmp)
			{
				T2[i] = tmp;
				T2[i + 1] = '\0';
			}
			else
			{
				couleur("31");
				printf("On ne peut placer un disque que sur un autre disque "
						"plus grand que lui ou sur un emplacement vide\n");
				couleur("0");
				return (1);
			}
	}
	else if (dest == 3)
	{
		while(T3[i] != '\0')
			i++;
		if (i == 0)
		{
			T3[i] = tmp;
			T3[i + 1] = '\0';
		}
		else
			if (T3[i - 1] > tmp)
			{
				T3[i] = tmp;
				T3[i + 1] = '\0';
			}
			else
			{
				couleur("31");
				printf("On ne peut placer un disque que sur un autre disque "
						"plus grand que lui ou sur un emplacement vide\n");
				couleur("0");
				return (1);
			}
	}

	///////////////////////////////////////////////////////////////////////////
	//               IF MOVE SUCCEEDED REMOVE FROM DEST DISK                 //
	///////////////////////////////////////////////////////////////////////////

	i = 0;
	if (source == 1)
	{
		while(T1[i + 1] != '\0')
			i++;
		T1[i] = '\0';
	}
	else if (source == 2)
	{
		while(T2[i + 1] != '\0')
			i++;
		T2[i] = '\0';
	}
	else if (source == 3)
	{
		while(T3[i + 1] != '\0')
			i++;
		T3[i] = '\0';
	}

	///////////////////////////////////////////////////////////////////////////
	//              PUT HANOI TOWER ONLY IF MOUVEMENT SUCEEDED               //
	///////////////////////////////////////////////////////////////////////////

	ft_put_hanoi_tower(T1, T2, T3, level);
	printf("\n%s", t1);

	///////////////////////////////////////////////////////////////////////////
	//                    INT POINTOR IS USED AS COUNTER                     //
	//        EVERY TIME MOVEMENT SUCCEEDED COUNTER IS INCREMENTED           //
	///////////////////////////////////////////////////////////////////////////

	(*cpt)++;

	///////////////////////////////////////////////////////////////////////////
	//                            LOGGING                                    //
	///////////////////////////////////////////////////////////////////////////

	fprintf(file, "Déplacement du disque %c de T%d vers T%d\n", tmp , source, dest);
	return (0);
}

void ft_put_rules(char *T1, char *T2, char *T3, int level)
{
	char ok[1000];
	couleur ("34");
	printf("\n");
	printf("                                                            )\\         O_._._._A_._._._O         /(\n");
	printf("                                                             \\`--.___,'=================`.___,--'/\n");
	printf("                                                              \\`--._.__                 __._,--'/\n");
	printf("                                                                \\  ,. l`~~~~~~~~~~~~~~~'l ,.  /\n");
	printf("                                                    __            \\||(_)!_!_!_.-._!_!_!(_)||/            __\n");
	printf("                                                    \\`-.__        ||_|____!!_|;|_!!____|_||        __,-'//\n");
	printf("                                                     \\    `==---='-----------'='-----------`=---=='    //\n");
	printf("                                                     | `--.                                         ,--' |\n");
	printf("                                                      \\  ,.`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~',.  /\n");
	printf("                                                        \\||  ____,-------._,-------._,-------.____  ||/\n");
	printf("                                                         ||\\|___!`======='!`======='!`======='!___|/||\n");
	printf("                                                         || |---||--------||-| | |-!!--------||---| ||\n");
	printf("                                               __O_____O_ll_lO_____O_____O|| |'|'| ||O_____O_____Ol_ll_O_____O__\n");
	printf("                                               o H o o H o o H o o H o o |-----------| o o H o o H o o H o o H o\n");
	printf("                                              ___H_____H_____H_____H____O =========== O____H_____H_____H_____H___\n");
	printf("                                                                       /|=============|\\\n");
	printf("                                             ()______()______()______() '==== +-+ ====' ()______()______()______()\n");
	printf("                                             ||{_}{_}||{_}{_}||{_}{_}/| ===== |_| ===== |\\{_}{_}||{_}{_}||{_}{_}||\n");
	printf("                                             ||      ||      ||     / |==== s(   )s ====| \\     ||      ||      ||\n");
	printf("                                             ======================()  =================  ()======================\n");
	printf("                                             ----------------------/| ------------------- |\\----------------------\n");
	printf("                                                                  / |---------------------| \\\n");
	printf("                                             -'--'--'           ()  '---------------------'  ()\n");
	printf("                                                                /| ------------------------- |\\    --'--'--'\n");
	printf("                                                    --'--'     / |---------------------------| \\    '--'\n");
	printf("                                                             ()  |___________________________|  ()           '--'-\n");
	printf("                                               --'-          /| _______________________________  |\\\n");
	printf("                                              --'           / |__________________________________| \\\n\n\n");
	couleur ("35");
	printf("	Selon une légende très ancienne, il existe un temple où les moines sont chargés de veiller des disques sacrés. Les disques, qui sont tous\n");
	printf("de taille différente, forment une tour. Comme ils sont précieux et très fragiles, un disque ne peut être placé sur un disque plus petit.\n\n");
	printf("	Hélas, le jour vient où quelques travaux dans le temple sont nécessaires et les disques doivent être déplacés. Ils sont très lourds et ne \n");
	printf("peuvent donc être transportés qu'un par un. De plus, il n'y a qu'un seul endroit assez sacré pour les stocker. Les moines commencent donc à dépla-\n");
	printf("cer les disques de la tour d'origine vers la nouvelle place et l'endroit intermédiaire, gardant toujours chacune des trois piles en ordre (le dis-\n");
	printf("que le plus large en bas, le moins large en haut).\n\n");
	printf("Alors qu'ils travaillent, les moines gardent en tête la terrible prophétie: 'Le temple s'écroulera avant que les disques soient mis en place !' \n\n");
	printf("Qu'en penses-tu?\n\n");
	printf("A toi de jouer !\n\n");
	printf("	Le but du jeu est de bouger tous les disques de la pile du centre vers un nouvel endroit en se servant de la position intermédiaire et en \n");
	printf("respectant les règles suivantes :\n\n");
	printf("    - On ne peut déplacer qu'un disque à la fois.\n");
	printf("    - On ne peut déplacer un disque qui se trouve sous un autre.\n");
	printf("    - Un disque ne peut être déposé sur un disque plus petit.\n\n");
	couleur ("0");
	printf("Entre un caractère pour continuer\n");
	scanf("%s", ok);
	while(getchar() != '\n');
	system("reset");
	ft_put_hanoi_tower(T1, T2, T3, level);
}

void 		ft_loop_game_play(char *T1, char *T2, char *T3, int level)
{
	int 	cpt;
	int 	*ptr;
	char 	mov[1000];
	FILE 	*file = NULL;
	time_t 	start, stop;
	double 	difftime(time_t time1, time_t time2);
	char 	t1[120] = "                      T.1                                            T.2                                            T.3";

	cpt = 0;
	ptr = &cpt;
	time(&start);
	file = fopen("hanoi.log", "a+");
	fprintf(file, "**** NOUVELLE PARTIE NIVEAU: %d ***\n\n", level);
	ft_put_hanoi_tower(T1, T2, T3, level);
	printf("\n%s\n\n", t1);
	printf("[quitter] pour quitter - [aide] pour afficher les règles\n");
	while(ft_check_t3(T3, level))
	{
		printf("\nMouvement ?\n");
		scanf("%s", mov);
		if (strncmp(mov,"quitter", 6) == 0)
		{
			time(&stop);
			fclose(file);
			return;
		}
		while(getchar() != '\n');
		ft_putchar('\n');
		ft_strlowcase(mov);
		if (ft_check_mov_entry(mov))
			ft_mouv_disk(T1, T2, T3, mov, level, ptr, file);
		else
		{
			couleur("31");
			printf("Mouvement impossible, tu fais le singe encore ?\n");
			couleur("0");
		}
		if (strncmp(mov,"aide", 5) == 0)
		{
			system("reset");
			ft_put_rules(T1, T2, T3, level);
		}
	}
	time(&stop);
	fprintf(file, "\nSIMULATION TERMINEE:\n");
	printf("\n\nSIMULATION TERMINEE:\n\n");
	fprintf(file, "\nNombre de mouvements: %d\n", cpt);
	printf("Nombre de mouvements: %d\n\n", cpt);
	printf("Temps: %f secondes \n\n", difftime(stop, start));
	fclose(file);
	return;
}

int			main()
{
	char 	*T1;
	char 	*T2;
	char 	*T3;
	int 	level;
	char 	stack1[10];
	char 	stack2[10];
	char 	stack3[10];

	T1 = &stack1[0];
	T2 = &stack2[0];
	T3 = &stack3[0];
	ft_put_header();
	level = ft_level_selec();
	ft_put_level_selected(level);
	ft_stack_init(T1, T2, T3, level);
	ft_loop_game_play(T1, T2, T3, level);
	return (0);
}
