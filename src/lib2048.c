#include "lib2048.h"
#define TILE_SCORE( n ) ( (n)?((n)-1)<<(n):0 )
#define TILE_MOVES( n ) ( (n)?1<<((n)-1):0 )

Board new_game( void )
{
    Board board = 0ull;
    return board;
}
Board move( Board board, Direction direction )
{
    return board;
}
int score( Board board )
{
    int score = 0;
    do {
        score += TILE_SCORE( board&0xf );
    } while( board >>= 4 );
    return score;
}
int moves( Board board )
{
    int moves = 0;
    do {
        moves += TILE_MOVES( board&0xf );
    } while( board >>= 4 );
    return moves-2;
}
int greatest( Board board )
{
    int greatest = 0;
    do {
        if( ( board&0xf ) > greatest ) greatest = ( board&0xf );
    } while( board >>= 4 );
    return greatest;
}