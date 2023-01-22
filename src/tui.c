#include "tui.h"
#include <stdio.h>
#include <stdlib.h>

Board board;

void print_board( Board board )
{
    puts( "+---------------+" );
    puts( "| Game of 8<<8! |" );
    for( int y = 0; y < 64; y += 16)
    {
        puts( "+---+---+---+---+" );
        for( int x = 0; x < 16; x += 4 )
        {
            printf( "|%2llX ", ( board>>( y+x ) )&0xf );
        }
        puts( "|" );
    }
    puts( "+---+---+---+---+" );
    printf( "| %6X %4X %X |\n", score(board), moves(board), greatest(board) );
    puts( "+---------------+\n" );
}
void save( void )
{
    FILE *fp = fopen( "save.bin", "w+b" );
    fwrite( &board, sizeof( board ), 1, fp );
    fclose( fp );
    puts("it works!");
}
void load( void )
{
    FILE *fp = fopen( "save.bin", "rb" );
    if( !fp )
    {
        board = new_game();
        return;
    }
    fread( &board, sizeof( board ), 1, fp );
    fclose( fp );
}

void init( void )
{
    atexit( save );
    load();
    print_board( board );
    // todo: game loop
    exit(EXIT_SUCCESS);
}