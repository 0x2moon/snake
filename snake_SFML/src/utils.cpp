#include "./../include/utils.hpp"
#include <iostream>

struct snake_lls *create_snake_lls(){
   
    struct snake_lls *new_s = (struct snake_lls *) malloc (sizeof(struct snake_lls));
    new_s->head = NULL;
    new_s->end  = NULL;
    new_s->tam  = 0;
    return new_s; 
}

struct snake_node *create_snake_node(){
   
    struct snake_node *newnode = (struct snake_node *) malloc (sizeof(struct snake_node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->x = 0;
    newnode->y = 0;
    return newnode;
}

void create_bodysnake(struct snake_lls *tsn, struct snake_node *snode){
    
    if(tsn->head == NULL){
       tsn->head = create_snake_node();
       tsn->end  = tsn->head;
       tsn->tam  = 1;
       return;
    }

    if(snode->next == NULL){
        snode->next    = create_snake_node();
        snode->next->x = snode->x - 1;
        snode->next->y = snode->y - 1;
        snode->next->prev = snode;
        tsn->end = snode->next;
        tsn->tam++;
        return;
    }
    create_bodysnake(tsn,snode->next);
}

void __dir_snake(int *dir){
  
    // 0 = up | 1 = down | 2 = left | 3 = rigth
    if (Keyboard::isKeyPressed(Keyboard::Up)){
        if( *dir != 1){
            *dir = 0;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)){
        if( *dir != 0){
            *dir = 1;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Left)){
        if( *dir != 3){
            *dir = 2;
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)){
        if( *dir != 2){
            *dir = 3;
        }
    }
}

void __lim_snake(struct snake_node *snake_h){
    
    if(snake_h->x >  (WIDTH - SIZE_SPRITE)) {
       snake_h->x =  0;
    }  
    if(snake_h->x <  0) {
       snake_h->x =  WIDTH;
    }  
    if(snake_h->y >  (HEIGTH - SIZE_SPRITE)) {
       snake_h->y =  0;
    }  
    if(snake_h->y <  0) {
       snake_h->y =  HEIGTH;
    }  
}

void mov_snake(struct snake_lls *snh, struct snake_node *snode, struct fruit *fruit, int *dir){
 // 0 = up | 1 = down | 2 = left | 3 = rigth  
    __lim_snake(snode);
    __dir_snake(dir);
    __coli_fruit(fruit,snh,snode);
    
    struct snake_node *snode_aux = snh->end;
    while(snode_aux->prev != NULL)
    {   
        snode_aux->x = snode_aux->prev->x;
        snode_aux->y = snode_aux->prev->y;
        snode_aux = snode_aux->prev;
    }

    if (*dir == 2)
    {   
        snh->head->x -= SIZE_SPRITE;
    }
    
    if (*dir == 3)
    {
         snh->head->x += SIZE_SPRITE;
    }

    if (*dir == 0)
    { 
        snh->head->y -= SIZE_SPRITE;
    }
    
    if (*dir == 1)
    {
        snh->head->y += SIZE_SPRITE;
    }
}

void rand_fruit(struct fruit* fruit){
    srand(time(NULL));
    fruit->x = rand() % M;
    fruit->y = rand() % N;
    
    fruit->x = fruit->x * SIZE_SPRITE;
    fruit->y = fruit->y * SIZE_SPRITE;
}

void __coli_fruit(struct fruit *fruit, struct snake_lls *snake,struct snake_node *snake_h){
    if((fruit->x == snake_h->x && fruit->y == snake_h->y)){
        create_bodysnake(snake,snake_h);
        rand_fruit(fruit);
    }
}