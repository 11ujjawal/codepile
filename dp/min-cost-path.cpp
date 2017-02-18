#include <iostream>
#include <vector>
#include <algorithm>

unsigned getMinCostPath(const std::vector<std::vector<unsigned> >& pathCost, std::size_t row, std::size_t col);

int main(void) {
    std::vector<std::vector<unsigned> > pathCost{ {1, 2, 3}, {4, 8, 2}, {1, 5, 3} };

    std::cout << "Min Path cost is: " << getMinCostPath(pathCost, 3, 3) << std::endl;

    return 0;
}

unsigned getMinCostPath(const std::vector<std::vector<unsigned> >& pathCost, std::size_t row, std::size_t col) {
    std::vector<std::vector<unsigned> > minPathCost(row, std::vector<unsigned>(col, 0));

    minPathCost[0][0] = pathCost[0][0];

    for(std::size_t rIndex = 1; rIndex != row; ++rIndex)
        minPathCost[rIndex][0] = minPathCost[rIndex - 1][0] + pathCost[rIndex][0];

    for(std::size_t cIndex = 1; cIndex != col; ++cIndex)
        minPathCost[0][cIndex] = minPathCost[0][cIndex - 1] + pathCost[0][cIndex];

    for(std::size_t rIndex = 1; rIndex != row; ++rIndex)
        for(std::size_t cIndex = 1; cIndex != col; ++cIndex)
            minPathCost[rIndex][cIndex] = pathCost[rIndex][cIndex] + std::min(std::min(minPathCost[rIndex - 1][cIndex], minPathCost[rIndex][cIndex - 1]), minPathCost[rIndex - 1][cIndex - 1]);

    return minPathCost[row - 1][col - 1];
}
