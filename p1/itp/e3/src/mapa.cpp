#include "mapa.h"
#include <fstream>
#include <iomanip>
#include <random>
#include <stdexcept>

HeightMap::HeightMap(int N)
{
    if (N > 0) {
        size_ = (1 << N) + 1;            
        h_.assign(size_, std::vector<float>(size_, 0.0f));
    }
}

void HeightMap::generate(float roughness)
{
    if (size_ == 0)
        return;
        // throw std::logic_error("HeightMap not initialised");

    initialiseCorners();

    int   step  = size_ - 1;             
    float scale = step;                  

    while (step > 1) {
        diamondStep(step, scale);       
        squareStep(step, scale);         
        step  /= 2;
        scale *= roughness;              
    }
}

bool HeightMap::saveToFile(const std::string& filename) const
{
    std::ofstream out(filename);
    if (!out) return false;

    out << size_ << ' ' << size_ << '\n';
    out << std::setprecision(6) << std::fixed;

    for (const auto& row : h_) {
        for (float v : row) out << v << ' ';
        out << '\n';
    }
    return true;
}

bool HeightMap::loadFromFile(const std::string& filename)
{
    std::ifstream in(filename);
    if (!in.is_open()) return false;

    int r, c;
    in >> r >> c;
    if (r != c) return false;            

    size_ = r;
    h_.assign(size_, std::vector<float>(size_));

    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            in >> h_[i][j];

    return true;
}

float HeightMap::getAltitude(int row, int col) const
{
    if (row < 0 || col < 0 || row >= size_ || col >= size_)
        throw std::out_of_range("Coordinates outside map");
    return h_[row][col];
}

void HeightMap::initialiseCorners()
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    h_[0][0]                = dist(eng);
    h_[0][size_ - 1]        = dist(eng);
    h_[size_ - 1][0]        = dist(eng);
    h_[size_ - 1][size_ -1] = dist(eng);
}

void HeightMap::diamondStep(int step, float scale)
{
    const int half = step / 2;

    for (int y = half; y < size_; y += step) {
        for (int x = half; x < size_; x += step) {
            float avg = (h_[y - half][x - half] +
                         h_[y - half][x + half] +
                         h_[y + half][x - half] +
                         h_[y + half][x + half]) * 0.25f;
            h_[y][x] = avg + randDisplacement(scale);
        }
    }
}

void HeightMap::squareStep(int step, float scale)
{
    const int half = step / 2;

    for (int y = 0; y < size_; y += half) {
        int xStart = ((y / half) % 2) ? 0 : half;
        for (int x = xStart; x < size_; x += step) {
            h_[y][x] = safeAverage(y, x, half) + randDisplacement(scale);
        }
    }
}

float HeightMap::safeAverage(int r, int c, int step) const
{
    float sum = 0.0f;
    int   cnt = 0;

    auto addIfValid = [&](int rr, int cc) {
        if (rr >= 0 && rr < size_ && cc >= 0 && cc < size_) {
            sum += h_[rr][cc];
            ++cnt;
        }
    };

    addIfValid(r - step, c);
    addIfValid(r + step, c);
    addIfValid(r, c - step);
    addIfValid(r, c + step);

    return (cnt ? sum / cnt : 0.0f);
}

float HeightMap::randDisplacement(float scale) const
{
    static thread_local std::mt19937 eng(std::random_device{}());
    std::uniform_real_distribution<float> dist(-scale, scale);
    return dist(eng);
}