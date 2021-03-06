#include "board.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

std::vector<std::string> words {
"bang",
"beam",
"bear",
"cafe",
"came",
"cold",
"come",
"cool",
"date",
"diet",
"door",
"doth",
"echo",
"exes",
"exit",
"face",
"fame",
"feed",
"fire",
"five",
"four",
"free",
"frog",
"from",
"game",
"goes",
"good",
"grit",
"have",
"heal",
"hear",
"here",
"hide",
"hole",
"home",
"hope",
"huge",
"keep",
"kill",
"lace",
"lame",
"leek",
"life",
"live",
"maps",
"mass",
"mate",
"maze",
"move",
"near",
"need",
"nine",
"once",
"quit",
"ques",
"race",
"read",
"reed",
"reef",
"rice",
"roof",
"sins",
"stay",
"tame",
"teen",
"tens",
"tide",
"tied",
"tree",
"twin",
"zero",
"zips",
};

Board::Board(int tiles) {
    assert(words.size() > tiles/2);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto dre = std::default_random_engine(seed);
    std::shuffle(words.begin(), words.end(), dre);

    for(int i=0; i<tiles/2; ++i) {
        _tiles.push_back(words[i]); 
        _tiles.push_back(words[i]); 
    }
    std::shuffle(_tiles.begin(), _tiles.end(), dre);
}
std::string Board::attempt(int tile1, int tile2) {
    if(_tiles.at(tile1).matched() || _tiles.at(tile2).matched()) return "Both must be unmatched!";
    std::string m = " and ";
    if( _tiles[tile1].match(_tiles[tile2])) m = " MATCHES ";
    return _tiles[tile1].word() + m + _tiles[tile2].word();
}
bool Board::solved() {
    for(Tile t : _tiles) if(!t.matched()) return false;
    return true;
}
std::ostream& operator<<(std::ostream& ost, const Board& board) {
    ost << std::right << "     ";
    for(int i=0; i<std::min(10, (int)board._tiles.size()); ++i) ost << std::setw(board._tiles[0].width()) << i << ' ';
    int tens = 0;
    for(Tile t : board._tiles) {
        if(tens++ % 10) ost << ' ';
        else ost << "\n" << std::setw(4) << tens-1 << ' ';
        ost << std::setw(t.width()) << t;
    }
    return ost;
}
