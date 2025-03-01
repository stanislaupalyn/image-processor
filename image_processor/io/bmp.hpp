#pragma once

#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "core/rgb_color.hpp"

/**
 * @class BMP
 * @brief A class for handling BMP image files.
 *
 * This class provides methods to read, write, and manipulate BMP images.
 */
class BMP {
public:
    static constexpr uint16_t BMP_SIGNATURE = 0x4D42;   // NOLINT
    static constexpr uint16_t BMP_BITS_PER_PIXEL = 24;  // NOLINT

    struct BMPHeader {
        uint16_t signature;
        uint32_t size;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset;
    } __attribute__((packed));

    struct DIBHeader {
        uint32_t header_size;
        int32_t width;
        int32_t height;
        uint16_t color_planes_num;
        uint16_t bits_per_pixel;
        uint32_t compression;
        uint32_t image_size;
        int32_t hor_res;
        int32_t ver_res;
        uint32_t colors_num;
        uint32_t important_colors_num;
    } __attribute__((packed));

    BMP() : bmp_header_(), dib_header_() {
    }

    ~BMP() {
    }

    /**
     * @brief Reads a BMP file from disk.
     * @param filename The path to the BMP file.
     * @throws std::runtime_error if the file cannot be read.
     */
    void ReadFromFile(const std::string& filename);

    /**
     * @brief Writes the BMP image to a file.
     * @param filename The path to save the BMP file.
     * @throws std::runtime_error if the file cannot be written.
     */
    void WriteToFile(const std::string& filename) const;

    BMPHeader& GetBMPHeader() {
        return bmp_header_;
    }
    const BMPHeader& GetBMPHeader() const {
        return bmp_header_;
    }
    DIBHeader& GetDIBHeader() {
        return dib_header_;
    }
    const DIBHeader& GetDIBHeader() const {
        return dib_header_;
    }

    std::vector<RGB24>& GetData() {
        return data_;
    }
    const std::vector<RGB24>& GetData() const {
        return data_;
    }

protected:
    static std::fstream OpenToRead(const std::string& filename);
    static std::fstream OpenToWrite(const std::string& filename);
    void ReadBmp(std::fstream& file);
    void WriteBmp(std::fstream& file) const;
    void ReadBmpHeader(std::fstream& file);
    void ReadDibHeader(std::fstream& file);
    void ReadData(std::fstream& file);
    void WriteBmpHeader(std::fstream& file) const;
    void WriteDibHeader(std::fstream& file) const;
    void WriteData(std::fstream& file) const;

protected:
    BMPHeader bmp_header_;
    DIBHeader dib_header_;
    std::vector<RGB24> data_;
};