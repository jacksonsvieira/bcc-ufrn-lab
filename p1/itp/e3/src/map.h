#include <string>

#include "image.h"

class HeightMap {
public:
    /**
     * Constructs a HeightMap with the given size (2^N+1).
     * @param N The exponent for the map size
     */
    explicit HeightMap(int N = 0);         
    /**
     * Destroys the HeightMap and frees memory.
     */
    ~HeightMap();                           

    /**
     * Generates the height map using the Diamond-Square algorithm.
     * @param roughness The roughness parameter for terrain generation
     */
    void  generate(float roughness = 0.5f);
    /**
     * Returns the altitude at the given row and column.
     * @param row The row index
     * @param col The column index
     * @return The altitude at (row, col)
     */
    float getAltitude(int row, int col) const;
    /**
     * Returns the number of rows in the map.
     * @return The number of rows
     */
    int   rows() const { return size_; }
    /**
     * Returns the number of columns in the map.
     * @return The number of columns
     */
    int   cols() const { return size_; }
    /**
     * Converts the height map to an Image using the given palette and optional shadow.
     * @param palette The color palette to use
     * @param shadow Whether to apply shadow effect
     * @return The generated Image
     */
    Image toImage(Palette pallete, bool shadow = false);
    /**
     * Saves the height map to a file.
     * @param filename The file to save to
     * @return true if successful, false otherwise
     */
    bool  saveToFile(const std::string& filename) const;
    /**
     * Loads the height map from a file.
     * @param filename The file to load from
     * @return true if successful, false otherwise
     */
    bool  loadFromFile(const std::string& filename);

private:
    /**
     * Allocates memory for the height map.
     * @param N The exponent for the map size
     */
    void  allocate(int N);                     
    /**
     * Initializes the corners of the height map with random values.
     */
    void  initialiseCorners();
    /**
     * Performs the diamond step of the algorithm.
     * @param step The current step size
     * @param scale The scale of the random displacement
     */
    void  diamondStep(int step, float scale);   
    /**
     * Performs the square step of the algorithm.
     * @param step The current step size
     * @param scale The scale of the random displacement
     */
    void  squareStep (int step, float scale);  
    /**
     * Computes the average of valid neighbors for the square step.
     * @param r The row index
     * @param c The column index
     * @param step The current step size
     * @return The average value
     */
    float safeAverage(int r, int c, int step) const;
    /**
     * Returns a random displacement value.
     * @param scale The scale of the displacement
     * @return The random displacement
     */
    float randDisplacement(float scale) const;

    /**
     * The size of the height map (number of rows/columns).
     */
    int    size_{0};       
    /**
     * Pointer to the height values array representing the height map in 2D array in a 1D array.
     */
    float* h_ = nullptr;     
};