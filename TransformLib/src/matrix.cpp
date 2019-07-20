#include "matrix.h"

tr::Matrix::Matrix()
{
    init();
}

tr::Matrix::Matrix(const double x, const double y, const double z)
{
    init();
    setXYZ(x,y,z);
}

void tr::Matrix::setXYZ(const double x, const double y, const double z)
{
    m_location[0] = x;
    m_location[1] = y;
    m_location[2] = z;
}

void tr::Matrix::setRPY(const double r, const double p, const double y)
{
    tr::Matrix roll, pitch, yaw;

    double rollIdentifier[4][4] = {  {1 , 0,             0,               0},
                                     {0 , std::cos(r),   -std::sin(r),    0},
                                     {0 , std::sin(r),   std::cos(r),     0},
                                     {0 , 0,             0,               1}
                                 };

    double pitchIdentifier[4][4] = { {std::cos(p) , 0,   std::sin(p),   0},
                                     {0 ,           1,   0,             0},
                                     {-std::sin(p), 0,   std::cos(p),   0},
                                     {0 ,           0,   0,             1}
                                 };

    double yawIdentifier[4][4] = {   {std::cos(y) , -std::sin(y),   0,  0},
                                     {std::sin(y) , std::cos(y),    0,  0},
                                     {0,            0,              1,  0},
                                     {0 ,           0,              0,  1}
                                 };

    roll.setRows(rollIdentifier);
    pitch.setRows(pitchIdentifier);
    yaw.setRows(yawIdentifier);

    tr::Matrix resultant;

    resultant = roll * pitch * yaw;

    resultant.getCol(0, m_eX);
    resultant.getCol(1, m_eY);
    resultant.getCol(2, m_eZ);
}

void tr::Matrix::setCols(double **colContainer)
{
    for (int col = 0; col < 4; col++) {
        for(int row = 0; row < 4; row++){
            m_container[col][row] = colContainer[col][row];
        }
//        std::memcpy(m_container[col], colContainer[col], 4);
    }
}

void tr::Matrix::setRows(double rowContainer[4][4])
{

    for (int col = 0; col < 4; col++) {
        for(int row = 0; row < 4; row++){
            m_container[col][row] = rowContainer[row][col];
        }
//        std::memcpy(m_container[col], colContainer[col], 4);
    }
}

tr::Matrix tr::Matrix::operator*(tr::Matrix &Mat)
{
    double rowContainer[4];
    double colContainer[4];

    double c1[4];
    double c2[4];
    double c3[4];
    double c4[4];

    double *container[4] = {c1,c2,c3,c4};

    for (size_t row = 0; row < 4; row++) {

        this->getRow(row, rowContainer);

        for (size_t col = 0; col < 4; col++) {
            Mat.getCol(col, colContainer);

            double result = rowColMult(rowContainer, colContainer);

            if(std::abs(result) < 0.0001){result = 0.0;}

            container[col][row] = result;
        }
    }

    tr::Matrix newMat;

    newMat.setCols(container);
    return  newMat;
}

void tr::Matrix::init()
{
    for (int i = 0; i < 4; i++) {
        m_location[i]   = 0;
        m_eX[i]         = 0;
        m_eY[i]         = 0;
        m_eZ[i]         = 0;
    }

    m_eX[0]         = 1;
    m_eY[1]         = 1;
    m_eZ[2]         = 1;
    m_location[3]   = 1;

    m_container[0]  = m_eX;
    m_container[1]  = m_eY;
    m_container[2]  = m_eZ;
    m_container[3]  = m_location;
}

double tr::Matrix::rowColMult(double *row, double *col)
{
    double sum = 0;

    for (int i = 0; i < 4; i++) {
        sum += row[i] * col[i];
    }

    return sum;
}

double tr::Matrix::at(int col, int row)
{
    return m_container[col][row];
}

void tr::Matrix::getRow(size_t row, double *container)
{
    if(row >= 4){
        throw std::out_of_range("Transformation is a 4x4 matrix");
    }

    for (int col = 0; col < 4; col++) {
        container[col] = m_container[col][row];
    }
}

void tr::Matrix::getCol(size_t col, double *container)
{
    if(col >= 4){
        throw std::out_of_range("Transformation is a 4x4 matrix");
    }

    for (int row = 0; row < 4; row++) {
        container[row] = m_container[col][row];
    }
}
