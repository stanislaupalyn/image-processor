# Image Processor

A command-line application for applying various filters to BMP images.

## About

This project is a slightly refactored version of my basic C++ course project at HSE. The application allows users to
apply multiple image filters in sequence through a simple CLI interface.

## Supported Image Format

The application supports only the [BMP](http://en.wikipedia.org/wiki/BMP_file_format) format for both input and output
images.

## Usage

### Command-Line Arguments Format

The general format for running the program is:

```
{program_name} {input_file_path} {output_file_path}
[-{filter_name_1} [filter_argument_1] [filter_argument_2] ...]
[-{filter_name_2} [filter_argument_1] [filter_argument_2] ...] ...
```

- `{program_name}` – Name of the executable.
- `{input_file_path}` – Path to the input BMP file.
- `{output_file_path}` – Path to save the processed BMP file.
- `-{filter_name}` – Filter name preceded by `-`.
- `[filter_argument]` – Optional parameters specific to certain filters.

If the program runs without arguments, it prints a help reference.

### Example

```
./image_processor input.bmp /tmp/output.bmp -crop 800 600 -gs -blur 0.5
```

In this example:

1. The image is loaded from `input.bmp`.
2. It is cropped to 800x600 pixels, starting from the top-left corner.
3. It is converted to grayscale.
4. A Gaussian blur with sigma 0.5 is applied.
5. The processed image is saved to `/tmp/output.bmp`.
6. If no filters are specified, the image is saved unchanged.

Filters are applied in the order they are specified in the command-line arguments.

## Available Filters

### Crop (`-crop width height`)

Crops the image to the specified `width` and `height`, using the top-left corner as the origin.

- If the specified dimensions exceed the image size, the available portion is retained.

### Grayscale (`-gs`)

Converts the image to grayscale using the standard grayscale formula.

### Negative (`-neg`)

Inverts the colors of the image to produce a negative effect.

### Sharpening (`-sharp`)

Enhances image sharpness using a convolution matrix.

### Edge Detection (`-edge threshold`)

Applies an edge detection filter.

- `threshold` must be in the range `[0, 1]`.

### Gaussian Blur (`-blur sigma`)

Applies a [Gaussian blur](https://en.wikipedia.org/wiki/Gaussian_blur) to the image.

- `sigma` controls the blur intensity.

### Fisheye (`-fisheye alpha center_x center_y`)

Applies a fisheye distortion effect centered at `(center_x, center_y)`.

- `alpha` determines the distortion strength and must satisfy: `0 ≤ alpha < min(center_x, center_y)`.

---

### Notes

- Ensure the input image is in BMP format.
- Filters requiring parameters must be provided with valid values.
- Filters are applied sequentially in the order they are specified.

Happy image processing!

