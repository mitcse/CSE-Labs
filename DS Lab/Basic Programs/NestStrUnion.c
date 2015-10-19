// NestStrUnion.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

typedef struct Date {
	int dd, mm, yyyy, hh, mm;
} DATE_t;

typedef struct Episode {
	char *name;
	char *summary;
	DATE_t *airDate;
} EPISODE_t;

typedef union Person {
	char *name;
	char *quote;
} PERSON_t;

typedef struct TVShow {
	char *name;
	EPISODE_t *episodes;
	DATE_t *premieredDate;
	PERSON_t *showCreator;
};

int main (int argc, const char *argv[]) {
	TVShow *show;
	show.name = "Angel";
	show.episodes = [{"City Of", "1x01", {5, 10, 1999, 10, 30}},
					 {"Not Fade Away", "5x22", {19, 05, 2004, 10, 30}}];
	show.showCreator = {"Joss Whedon", "*insert Joss Whedon quote*"};
	return 0;
}