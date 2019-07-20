#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstring>
#include <cmath>

namespace tr {
    class Matrix;
}

class tr::Matrix
{
public:
    Matrix();
    Matrix(const double x, const double y, const double z);

    void setXYZ(const double x, const double y, const double z);
    void setRPY(const double r, const double p, const double y);

    void setCols(double **colContainer);
    void setRows(double rowContainer[4][4]);

    double at(int col, int row);

    //getters
    double getX(){return m_location[0];}
    double getY(){return m_location[1];}
    double getZ(){return m_location[2];}

    double **getMatrix(){return m_container;}

    void getRow(size_t row, double *container);//will populate a provided container, for memory safety
    void getCol(size_t col, double *container);

    //overloaded operators

    Matrix operator*(Matrix &Mat);

private:
    double m_location[4];
    double m_eX[4];
    double m_eY[4];
    double m_eZ[4];

    double *m_container[4];

private://methods
    void init();
    double rowColMult(double *row, double *col);

};

#endif // MATRIX_H
