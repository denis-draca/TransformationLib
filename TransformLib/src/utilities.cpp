#include <utilities.h>

void tr::util::displayMatrix(tr::Matrix &Mat)
{
    double **numbers = Mat.getMatrix();

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            printf(" %f ", numbers[x][y]);
//            std::cout << " " << numbers[x][y] << " ";
        }
        printf("\n");
    }
}

tr::Matrix tr::util::translationMatrix(const double x, const double y, const double z)
{
    tr::Matrix mat;

    mat.setXYZ(x,y,z);

    return mat;
}

tr::Matrix tr::util::rotationMatrix(const double r, const double p, const double y)
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

    return resultant;
}
