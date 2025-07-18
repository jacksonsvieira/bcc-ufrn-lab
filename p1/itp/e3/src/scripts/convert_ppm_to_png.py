import os
from PIL import Image

def convert_ppm_to_png(ppm_file, png_file):
    """
    Convert a PPM file to PNG format.
    
    :param ppm_file: Path to the input PPM file.
    :param png_file: Path to save the output PNG file.
    """
    try:
        with Image.open(ppm_file) as img:
            img.save(png_file, 'PNG')
        print(f"Converted {ppm_file} to {png_file}")
    except Exception as e:
        print(f"Error converting {ppm_file} to {png_file}: {e}")

if __name__ == "__main__":
    import sys

    if len(sys.argv) != 3:
        print("Usage: python convert_ppm_to_png.py <input_ppm> <output_png>")
        sys.exit(1)

    input_ppm = sys.argv[1]
    output_png = sys.argv[2]
    
    if os.path.exists(input_ppm):
        convert_ppm_to_png(input_ppm, output_png)
    else:
        print(f"Input file {input_ppm} does not exist.")