// #pragma once
#include <string>

/*
 * HeightMap  – Step‑3 terrain generator (diamond–square)
 * • Uses a single 1‑D C array (float*) for speed & low‑level practice.
 * • row‑major index:  idx = r * size_ + c
 */
class HeightMap {
public:
    explicit HeightMap(int N = 0);          // N == log2(size_-1)
    ~HeightMap();                           // releases the C array

    // High‑level API
    void  generate(float roughness = 0.5f);
    float getAltitude(int row, int col) const;
    int   rows() const { return size_; }
    int   cols() const { return size_; }

    bool  saveToFile(const std::string& filename) const;
    bool  loadFromFile(const std::string& filename);

private:
    // Internals
    void  allocate(int N);                      // alloc + zero‑fill
    void  initialiseCorners();
    void  diamondStep(int step, float scale);   // phase ①
    void  squareStep (int step, float scale);   // phase ②
    float safeAverage(int r, int c, int step) const;
    float randDisplacement(float scale) const;

    int    size_{0};        // side length (rows == cols)
    float* h_{nullptr};     // altitude buffer, size_ × size_
};