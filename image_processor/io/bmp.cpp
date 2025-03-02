#include "bmp.hpp"

#include <cassert>
#include <fstream>
#include <stdexcept>

std::fstream BMP::OpenToRead(const std::string& filename) {
    assert(!filename.empty());

    std::fstream file;
    file.open(filename, std::fstream::in | std::fstream::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file.");
    }
    return file;
}

std::fstream BMP::OpenToWrite(const std::string& filename) {
    assert(!filename.empty());

    std::fstream file;
    file.open(filename, std::fstream::out | std::fstream::binary);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file.");
    }
    return file;
}

void BMP::ReadBmp(std::fstream& file) {
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file.");
    }

    file.seekg(0);

    ReadBmpHeader(file);
    ReadDibHeader(file);
    ReadData(file);
}

void BMP::ReadBmpHeader(std::fstream& file) {
    if (!file) {
        throw std::runtime_error("Error while reading file.");
    }
    file.read(reinterpret_cast<char*>(&bmp_header_), sizeof(BMPHeader));
    if (!file) {
        throw std::runtime_error("Error while reading file.");
    }

    if (bmp_header_.signature != BMP_SIGNATURE) {
        throw std::invalid_argument("BMP File is invalid.");
    }
}

void BMP::ReadDibHeader(std::fstream& file) {
    if (!file) {
        throw std::runtime_error("Error while reading file.");
    }
    file.read(reinterpret_cast<char*>(&dib_header_), sizeof(DIBHeader));
    if (!file) {
        throw std::runtime_error("Error while reading file.");
    }

    if (dib_header_.bits_per_pixel != BMP_BITS_PER_PIXEL) {
        throw std::runtime_error("BMP File is invalid.");
    }
}

void BMP::ReadData(std::fstream& file) {
    if (!file) {
        throw std::runtime_error("Cannot open file.");
    }

    file.seekg(bmp_header_.offset);
    data_.resize(dib_header_.height * dib_header_.width);

    std::vector<uint8_t> padding;
    if ((dib_header_.width * 3) % 4) {
        int32_t need = 4 - (dib_header_.width * 3) % 4;
        padding.resize(need);
    }

    for (size_t row = 0; row < dib_header_.height; ++row) {
        if (!file) {
            throw std::runtime_error("Error while reading file.");
        }
        file.read(reinterpret_cast<char*>(data_.data() + row * dib_header_.width), dib_header_.width * 3);
        if (!file) {
            throw std::runtime_error("Error while reading file.");
        }
        file.read(reinterpret_cast<char*>(padding.data()), static_cast<int32_t>(padding.size()));
        if (!file) {
            throw std::runtime_error("Error while reading file.");
        }
    }
}

void BMP::WriteBmp(std::fstream& file) const {
    if (!file.is_open()) {
        throw std::runtime_error("File is not open.");
    }

    file.seekg(0);

    WriteBmpHeader(file);
    WriteDibHeader(file);
    WriteData(file);
}

void BMP::WriteBmpHeader(std::fstream& file) const {
    if (!file) {
        throw std::runtime_error("Error while writing file.");
    }
    file.write(reinterpret_cast<const char*>(&bmp_header_), sizeof(BMPHeader));
    if (!file) {
        throw std::runtime_error("Error while writing file.");
    }
}

void BMP::WriteDibHeader(std::fstream& file) const {
    if (!file) {
        throw std::runtime_error("Error while writing file.");
    }
    file.write(reinterpret_cast<const char*>(&dib_header_), sizeof(DIBHeader));
    if (!file) {
        throw std::runtime_error("Error while writing file.");
    }
}

void BMP::WriteData(std::fstream& file) const {
    if (!file) {
        throw std::runtime_error("Error while writing file.");
    }

    file.seekg(bmp_header_.offset);

    std::vector<uint8_t> padding;
    if ((dib_header_.width * 3) % 4) {
        int32_t need = 4 - (dib_header_.width * 3) % 4;
        padding.resize(need);
    }

    for (size_t row = 0; row < dib_header_.height; ++row) {
        if (!file) {
            throw std::runtime_error("Error while writing file.");
        }
        file.write(reinterpret_cast<const char*>(data_.data() + row * dib_header_.width), dib_header_.width * 3);
        if (!file) {
            throw std::runtime_error("Error while writing file.");
        }
        file.write(reinterpret_cast<const char*>(padding.data()), static_cast<int32_t>(padding.size()));
        if (!file) {
            throw std::runtime_error("Error while writing file.");
        }
    }
}

void BMP::ReadFromFile(const std::string& filename) {
    std::fstream file = OpenToRead(filename);
    ReadBmp(file);
    file.close();
}

void BMP::WriteToFile(const std::string& filename) const {
    std::fstream file = OpenToWrite(filename);
    WriteBmp(file);
    file.close();
}