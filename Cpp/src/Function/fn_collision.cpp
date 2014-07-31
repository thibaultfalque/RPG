#include "fn_collision.hpp"


bool pointInRect(AABB rect,sf::Vector2f point){
    return (point.x > rect.x
            && point.x < rect.x2
            && point.y > rect.y
            && point.y < rect.y2);
}

bool pointInRect(sf::Vector2f _pos,sf::Vector2f _size,sf::Vector2f point){
        AABB rect = {_pos.x,_pos.y,_pos.x+_size.x,_pos.y+_size.y};
        return pointInRect(rect,point);
}

bool AABBinAABB(AABB box1,AABB box2)
{
   if((box2.x >= box1.x2)      // trop à droite
	|| (box2.x2 <= box1.x) // trop à gauche
	|| (box2.y >= box1.y2) // trop en bas
	|| (box2.y2 <= box1.y))  // trop en haut
          return false;
   else
          return true;
}
