#ifndef UTILITIES_H
#define UTILITIES_H

#include "matrix.h"
#include "printf.h"

namespace tr {
namespace util {
    void displayMatrix(Matrix &Mat); //drawing function is very slow. the matrix is stored as a series of coloumns. But to draw i need to access rows.

    tr::Matrix translationMatrix(const double x, const double y, const double z);
    tr::Matrix rotationMatrix(const double r, const double p, const double y);
}
}

#endif // UTILITIES_H
