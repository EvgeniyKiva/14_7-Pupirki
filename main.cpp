#include <iostream>

void new_matrix(bool Matrix[12][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            Matrix[i][j] = true;
        }
    }
}
void show(bool Matrix[12][12]) {
    bool res = false;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (Matrix[i][j]) {
                std::cout << '0' << " ";
            }
            else {
                std::cout << 'X' << " ";
            }
        }
        std::cout << std::endl;
    }
}
int popMatrix(int x1, int y1, int x2, int y2, bool Matrix[12][12], int count) {
    int i = 0, j = 0;
    bool res = true;
    for (i = y1; i <= y2; ++i) {
        for (j = x1; j <= x2; ++j) {
            if (Matrix[i][j]) {
                Matrix[i][j] = false;
                std::cout << "Pop!" << " ";
                count--;
            }

        }
    }
    std::cout << std::endl;
    return count;
}
int main() {
    bool matrix[12][12] = {};
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int count = 144;
    new_matrix(matrix);
    while (count > 0) {
        show(matrix);
        std::cout << "Enter coordinates (x1 y1 x2 y2) - ";
        std::cin >> x1 >> y1 >> x2 >> y2;
        while (x1<0 || y1 <0 || x2>11 || y2>11 || x1>=x2 || y1>=y2){
            std::cout << "Coordinates wrong! Try again!" << std::endl;
            std::cout << "Enter coordinates (x1 y1 x2 y2) - ";
            std::cin >> x1 >> y1 >> x2 >> y2;
        }
        count = popMatrix(x1, y1, x2, y2, matrix, count);
    }

    return 0;
}
