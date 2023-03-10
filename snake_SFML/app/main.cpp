#include "./../include/utils.hpp"
using namespace sf;

struct fruit fruit_struct;
struct snake_lls *sn_head = create_snake_lls();
int dir = 3;

RenderWindow window(VideoMode(WIDTH,HEIGTH), "Snake Game!");
int main()
{
    Texture _background, _snake, _fruit;
    _background.loadFromFile("images/bg.png");
    _snake.loadFromFile("images/snk.png");
    _fruit.loadFromFile("images/fr.png");

    Sprite background(_background);
    Sprite snake(_snake);
    Sprite fruit(_fruit);   
    
   create_bodysnake(sn_head, sn_head->head);
   rand_fruit(&fruit_struct);

   Clock clock;
   float timer = 0;

   while (window.isOpen())
   {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
    
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;
        if (timer > VELOCIDADE)
        {
            timer = 0;
            mov_snake(sn_head, sn_head->head, &fruit_struct, &dir);
        }
 
        window.clear();
            for (int i = 0; i < M; i++)
            {   
                for (int j = 0; j < N; j++)
                {
                    background.setPosition(i * SIZE_SPRITE,j * SIZE_SPRITE);
                    window.draw(background);        
                }    
            }

            fruit.setPosition(fruit_struct.x,fruit_struct.y);
            window.draw(fruit);

            struct snake_node *snode_aux = sn_head->head;
            do
            {   snake.setPosition(snode_aux->x,snode_aux->y);
                window.draw(snake);
                snode_aux = snode_aux->next;
            } while (snode_aux != NULL);
            
        window.display(); 
   }  
    return 0;
}