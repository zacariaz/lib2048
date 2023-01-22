#ifndef LIB2048_H
#define LIB2048_H

typedef unsigned long long Board;
typedef enum { LEFT, UP, RIGHT, DOWN } Direction;

Board new_game( void );
Board move( Board, Direction );
int score( Board );
int moves( Board );
int greatest( Board );


#endif//LIB2048_h