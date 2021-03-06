#include <fstream>
#include <iostream>

#include "main/Main.hpp"
#include "resources/Texture.hpp"
#include "resources/TgaHeader.hpp"
#include "resources/TgaLoader.hpp"

//Namespace this code belongs to:
using namespace Resources;

Texture* TgaLoader::loadFromFile(const std::string& fileName)
{
    Texture*      texture = new Texture(fileName);
    std::ifstream file;

    file.open(fileName, std::ifstream::in);

    if(!file.good() || !file.is_open())
    {
        Main::die("Failed to open texture: " + fileName + ".");
    }

    //Read the file header:
    TgaHeader fileHeader = TgaHeader();

    fileHeader.load(&file);

    texture->width  = fileHeader.width;
    texture->height = fileHeader.height;

    switch(fileHeader.pixelSize)
    {
        case 24: //RGB 3 channels of 8 bits.
        {
            unsigned char red;
            unsigned char green;
            unsigned char blue;

            unsigned int size = texture->width * texture->height * 4;
            texture->pixels = new float[size];

            float converter = 1.0f / 255.0f;

            for(unsigned int index = 0; index < size;)
            {
                file.read((char*)&blue,  1);
                file.read((char*)&green, 1);
                file.read((char*)&red,   1);

                texture->pixels[index++] = red   * converter;
                texture->pixels[index++] = green * converter;
                texture->pixels[index++] = blue  * converter;
                texture->pixels[index++] = 1.0f;
            }

            break;
        }
        
        case 32: //RGBA 4 channels of 8 bits.
        {
            unsigned char red;
            unsigned char green;
            unsigned char blue;
            unsigned char alpha;

            unsigned int size = texture->width * texture->height * 4;
            texture->pixels = new float[size];

            float converter = 1.0f / 255.0f;

            for(unsigned int index = 0; index < size;)
            {
                file.read((char*)&blue , 1);
                file.read((char*)&green, 1);
                file.read((char*)&red  , 1);
                file.read((char*)&alpha, 1);

                texture->pixels[index++] = red   * converter;
                texture->pixels[index++] = green * converter;
                texture->pixels[index++] = blue  * converter;
                texture->pixels[index++] = alpha * converter;
            }

            break;
        }

        default:
            std::cout << "Texture " << fileName << " pixel is size is: " << fileHeader.pixelSize << " which the loader doesn't support." << std::endl;
            Main::die("Unable to load texture: " + fileName +  ".");
            break;
    }

    return texture;
}