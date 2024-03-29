#include "Settings.h"

#include <iostream>

Settings::Settings(int argc, char **argv) {
    //Check if the argument count is 6 or 1
    if (argc == 6) {
        //For all the user passed arguments...
        for (int i = 1; i < argc; ++i) {
            //Check if the first character is '-', then depending on the second character set the fields
            if (argv[i][0] == '-') {
                switch (argv[i][1]) {
                    case 'i':
                        Settings::inputPath = argv[++i];
                        break;

                    case 'o':
                        Settings::outputPath = argv[++i];
                        break;

                    case 'd':
                        Settings::operatingMode = Downscale4X;
                        break;

                    case 'g':
                        Settings::operatingMode = Greyscale;
                        break;

                    case 'u':
                        Settings::operatingMode = Upscale4X;
                        break;

                    case 'f':
                        Settings::operatingMode = Flip;
                        break;

                    case 'a':
                        Settings::operatingMode = AvgColor;
                        break;

                    default:
                        throw std::invalid_argument("Argument does not exist");
                }
            } else {
                throw std::invalid_argument("Invalid syntax");
            }
        }
        //The 1 user argument case
    } else if (argc == 2) {
        //Must be the help arg, otherwise things will break. More error handling
        if (strcmp(argv[1], "-h")) {
            Settings::operatingMode = Help;
        } else {
            throw std::invalid_argument("Invalid syntax, run -h on its own for help");
        }
    } else {
        throw std::length_error("Wrong number of arguments");
    }
}

void Settings::displayHelp() {
    std::cout << "ImageBirb help page\n\n"
              << "ImageBirb is a simple program that manipulates 24-bit BMP images.\n"
              << "In order to work, the program needs the following arguments:\n"
              << "-i [path to the input image]\n"
              << "-o [path to the output image]\n"
              << "-[operating mode symbol]\n"
              << "The operating modes are as follows:\n"
              << "\"-d\" downscales the image 4 times, halving the vertical and horizontal resolution.\n"
              << "\"-u\" upscales the image 4 times, doubling the vertical and horizontal resolution.\n"
              << "\"-g\" converts the image to greyscale.\n"
              << "\"-f\" flips the image horizontally.\n"
              << "\"-a\" fills an image of the same dimensions with the input image's average color value.\n"
              << "To display this help message, run the program with only the \"-h\" argument.\n";
}