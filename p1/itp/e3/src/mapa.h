#pragma once
#include <string>
#include <vector>

class HeightMap {
public:
    explicit HeightMap(int N = 0);
    ~HeightMap() = default;

    void  generate(float roughness = 0.5f);
    float getAltitude(int row, int col) const;
    int   rows() const { return size_; }
    int   cols() const { return size_; }

    bool  saveToFile(const std::string& filename) const;
    bool  loadFromFile(const std::string& filename);

private:
    void  initialiseCorners();                  
    void  diamondStep(int step, float scale);  
    void  squareStep(int step, float scale);    
    float safeAverage(int r, int c, int step) const;
    float randDisplacement(float scale) const;

    int size_{0};                               
    std::vector<std::vector<float>> h_;
};
