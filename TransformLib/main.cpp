#include <iostream>
#include <matrix.h>
#include <utilities.h>
#include <iostream>


int main()
{
    tr::Matrix Mat(5,9,3);

    tr::util::displayMatrix(Mat);

    printf("\n");

    tr::Matrix rot = tr::util::rotationMatrix(0,0.704,0);
    tr::Matrix tra = tr::util::translationMatrix(1,0,0);

    Mat = Mat * rot;

    Mat = Mat * tra;

    tr::util::displayMatrix(Mat);
//    tr::Matrix transl = tr::util::translationMatrix(1,0,0);
//    tr::Matrix newMat = Mat * transl;

//    tr::util::displayMatrix(newMat);

    std::cout << "Hello World!" << std::endl;
    return 0;
}
