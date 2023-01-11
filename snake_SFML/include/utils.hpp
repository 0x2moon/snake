#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

#define M 30
#define N 30
#define WIDTH   480
#define HEIGTH  480
#define SIZE_SPRITE 16
#define VELOCIDADE 0.09

struct fruit{
    int x, y;
};

struct snake_lls{
    int tam;  
    struct snake_node *head;
    struct snake_node *end;
};

struct snake_node{
    int x, y;
    struct snake_node *prev;
    struct snake_node *next;
};

void rand_fruit(struct fruit*);

void __dir_snake(int *);
void __lim_snake(struct snake_node*);
void __coli_fruit(struct fruit *,struct snake_lls *,struct snake_node *);

struct snake_lls *create_snake_lls();
struct snake_node *create_snake_node();
void create_bodysnake(struct snake_lls *, struct snake_node *);
void mov_snake(struct snake_lls*, struct snake_node*, struct fruit *, int *);
#endif