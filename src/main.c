#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void print_board( Board board )
{
    puts( "+---------------+" );
    printf( "| %6X %4X %X |\n", score(board), moves(board), greatest(board) );
    for( int y = 0; y < 64; y += 16)
    {
        puts( "+---+---+---+---+" );
        for( int x = 0; x < 16; x += 4 )
        {
            printf( "|%2llX ", ( board>>( y+x ) )&0xf );
        }
        puts( "|" );
    }
    puts( "+---+---+---+---+\n" );
}

int main( void )
{
    Board b = new_game();
    b = 0x11;
    print_board( b );
    exit(EXIT_SUCCESS);
}
//score: 6
//moves: 4
//tile:: 1