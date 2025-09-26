#pragma once

class Map {
public:
    Map() = default;
    void Generate();
    int GetWidth() const { return Width; }
    int GetHeight() const { return Height; }

    char GetTile(int x, int y) const { return Tile[y][x]; }
    void SetTile(int x, int y, char InTile)
    {
        if (x >= 0 && x < Width && y >= 0 && y < Height)
        {
            Tile[y][x] = InTile;
        }
    }
    
private:
    static const int Width = 20;
    static const int Height = 20;
    char Tile[Height][Width] = {
    "###################",
    "#...........MMMM.$#",
    "#..MMM........MM..#",
    "#..MMM............#",
    "#~~~~~............#",
    "#~~~~~...........O#",
    "###################"
    };
};

