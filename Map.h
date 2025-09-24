#pragma once

class Map {
public:
    Map() = default;
    void Generate();
    char GetTile(int x, int y) const { return Grid[y][x]; }
    int GetWidth() const { return Width; }
    int GetHeight() const { return Height; }
    
private:
    static const int Width = 20;
    static const int Height = 20;
    char Grid[Height][Width] = {
    "###################",
    "#...........MMMM..#",
    "#..MMM........MM..#",
    "#..MMM............#",
    "#~~~~~............#",
    "#~~~~~...........O#",
    "###################"
    };
};

