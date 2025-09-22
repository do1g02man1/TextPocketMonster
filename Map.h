#pragma once

enum class Tile 
{ 
    Wall, 
    Path, 
    Grass, 
    NPC, 
    Player 
};

class Map {
private:
    static const int WIDTH = 40;
    static const int HEIGHT = 20;
    Tile grid[HEIGHT][WIDTH];

public:
    Map(int width = WIDTH, int height = HEIGHT);
    void Generate();
    Tile GetTile(int x, int y) const;
    void SetTile(int x, int y, Tile tile);
    //void Render(const PrintScreen& screen) const;
};

