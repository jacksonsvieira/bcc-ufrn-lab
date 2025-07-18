#include "map.h"

#include <fstream>
#include <iomanip>
#include <random>
#include <stdexcept>
#include <cstring>     

#include <limits>


HeightMap::HeightMap(int N)
{
    if (N > 0) allocate(N);
}

HeightMap::~HeightMap()
{
    delete[] h_;
}

void HeightMap::allocate(int N)
{
    size_ = (1 << N) + 1;             
    h_    = new float[size_ * size_];
    std::memset(h_, 0, sizeof(float) * size_ * size_); 
}

void HeightMap::generate(float roughness)
{
    if (size_ == 0 || !h_)
        throw std::logic_error("HeightMap not initialised");

    initialiseCorners();

    int   step  = size_ - 1;
    float scale = step;

    while (step > 1) {
        diamondStep(step, scale);      
        squareStep (step, scale);      
        step  /= 2;
        scale *= roughness;
    }

    float mn =  std::numeric_limits<float>::infinity();
    float mx = -std::numeric_limits<float>::infinity();

    for (int i = 0; i < size_*size_; ++i) {
        mn = std::min(mn, h_[i]);
        mx = std::max(mx, h_[i]);
    }

    for (int i = 0; i < size_*size_; ++i) {
        h_[i] = (h_[i] - mn) / (mx - mn);
    }
}

bool HeightMap::saveToFile(const std::string& filename) const
{
    if (!h_) return false;
    std::ofstream out(filename);
    if (!out) return false;

    out << size_ << ' ' << size_ << '\n'
        << std::fixed << std::setprecision(6);

    for (int r = 0; r < size_; ++r) {
        for (int c = 0; c < size_; ++c)
            out << h_[r * size_ + c] << ' ';
        out << '\n';
    }
    return true;
}

bool HeightMap::loadFromFile(const std::string& filename)
{
    std::ifstream in(filename);
    if (!in) return false;

    int r, c;
    in >> r >> c;
    if (r != c) return false;

    delete[] h_;                      
    size_ = r;
    h_    = new float[size_ * size_];

    for (int i = 0; i < size_ * size_; ++i)
        in >> h_[i];

    return true;
}

float HeightMap::getAltitude(int row, int col) const
{
    if (row < 0 || col < 0 || row >= size_ || col >= size_)
        throw std::out_of_range("Coordinates outside map");
    return h_[row * size_ + col];
}

void HeightMap::initialiseCorners()
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    h_[0]                      = dist(eng);                // (0,0)
    h_[size_ - 1]              = dist(eng);                // (0,size_-1)
    h_[(size_ - 1) * size_]    = dist(eng);                // (size_-1,0)
    h_[size_ * size_ - 1]      = dist(eng);                // (size_-1,size_-1)
}

void HeightMap::diamondStep(int step, float scale)
{
    const int half = step / 2;

    for (int y = half; y < size_; y += step) {
        for (int x = half; x < size_; x += step) {
            float avg = ( h_[(y - half) * size_ + (x - half)] +
                          h_[(y - half) * size_ + (x + half)] +
                          h_[(y + half) * size_ + (x - half)] +
                          h_[(y + half) * size_ + (x + half)] ) * 0.25f;

            h_[y * size_ + x] = avg + randDisplacement(scale);
        }
    }
}

void HeightMap::squareStep(int step, float scale)
{
    const int half = step / 2;

    for (int y = 0; y < size_; y += half) {
        int xStart = ((y / half) % 2) ? 0 : half; 
        for (int x = xStart; x < size_; x += step) {
            h_[y * size_ + x] = safeAverage(y, x, half) + randDisplacement(scale);
        }
    }
}

float HeightMap::safeAverage(int r, int c, int step) const
{
    float sum = 0.0f;
    int   cnt = 0;

    auto add = [&](int rr, int cc) {
        if (rr >= 0 && rr < size_ && cc >= 0 && cc < size_) {
            sum += h_[rr * size_ + cc];
            ++cnt;
        }
    };

    add(r - step, c);
    add(r + step, c);
    add(r, c - step);
    add(r, c + step);

    return cnt ? sum / cnt : 0.0f;
}

// TODO: This is function is too overengenering should be refactored to a more simple version.
float HeightMap::randDisplacement(float scale) const
{
    static thread_local std::mt19937 eng(std::random_device{}());
    std::uniform_real_distribution<float> dist(-scale, scale);
    return dist(eng);
}


Image HeightMap::toImage(Palette palette, bool shadow) {
    auto aImage = Image(size_, size_);

    for (int i = 0; i < (size_ * size_); i++)
    {
        int x = i % size_;
        int y = i / size_;

        int idx       = y * size_ + x;
        Color pixelColor     = palette.getColor(h_[idx]);

        if(shadow){
            if (x > 0 && y > 0) {
                int idxNW = (y - 1) * size_ + (x - 1);
                if (h_[idxNW] > h_[idx]) {
                    pixelColor.r = static_cast<uint8_t>(pixelColor.r * 0.5f);
                    pixelColor.g = static_cast<uint8_t>(pixelColor.g * 0.5f);
                    pixelColor.b = static_cast<uint8_t>(pixelColor.b * 0.5f);
                }
            }
        }

        aImage.setColor(y, x, pixelColor);
    }
    

    return aImage;
}