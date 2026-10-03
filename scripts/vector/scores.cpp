#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores{72, 85, 91};
    scores.push_back(88);
    scores[1] = 90;
    int total = 0;
    for (int score : scores)
    {
        total += score;
    }

    for (int score : scores)
    {
        std::cout << score << " ";
    }
    std::cout << "\nTotal: " << total << "\n";
    std::cout << "\nCount: " << scores.size() << "\n";
    return 0;
}
