#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <windows.h>
#include <iostream>
#include <ctime>

void arr_fill(const int size, int *arr, sf::RectangleShape *entity, const double width){
    double offset = 0;
    for(int i = 0; i < size; i++){
        arr[i] = rand()%600;
        //entity[i].setSize(sf::Vector2f(width, arr[i]));
        entity[i].setSize(sf::Vector2f(width, -arr[i]));
        //entity[i].move(sf::Vector2f(offset, 0));
        entity[i].move(sf::Vector2f(offset, 600));
        entity[i].setFillColor(sf::Color::White);
        entity[i].setOutlineColor(sf::Color(255));
        entity[i].setOutlineThickness(-1);
        offset += width;
    }
}

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int main(){
    srand(time(NULL));

    const int size = 100;
    int array[size]{};

    sf::RectangleShape entity[size];
    const double width = 800/size;

    arr_fill(size, array, entity, width);
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "test");
   // window.setVerticalSyncEnabled(true);
    while (window.isOpen())
    {
        sf::Event event;
        for (int i = 0; i < size - 1; i++)
        {
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            } 

            window.clear(sf::Color::Black);
            if (array[i] > array[i + 1])
            {
                swap(&array[i], &array[i + 1]);
                entity[i].setSize(sf::Vector2f(width, -array[i]));
                entity[i + 1].setSize(sf::Vector2f(width, -array[i + 1]));
                entity[i+1].setFillColor(sf::Color::Red);
            } 

            
            for (int k = 0; k < size; k++)
            {
                window.draw(entity[k]);
            }
            //Sleep(10);
            window.display();
            entity[i+1].setFillColor(sf::Color::White);
        }
    

    }

    return 0;
}
