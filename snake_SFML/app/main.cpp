#include "./../include/utils.hpp"
using namespace sf;

// struct snake snake_struct;
struct fruit fruit_struct;
struct snake_lls *sn_head = create_snake_lls();

int dir = 3;

RenderWindow window(VideoMode(WIDTH,HEIGTH), "Snake Game!");
int main()
{
    Texture _background, _snake, _fruit;
    _background.loadFromFile("images/white.png");
    _snake.loadFromFile("images/red.png");
    _fruit.loadFromFile("images/green.png");

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
    // tentativa de renderizar a cobrinha
            // struct snake_node *snode = sn_head->head;
            // do
            // {   snake.setPosition(snode->x,snode->y);
            //     window.draw(snake);
            //     snode = snode->next;
            // } while (snode->next != NULL);
            
            
        window.display(); 
   }
   
    return 0;
}