#include <algorithm>
#include <iostream>
#include <vector>

/* 
    On suppose ici que les paires vendues sont données sous forme d'argument à la fonction.
    En pratique, cela se fait en interagissant avec la DB
*/

int encoding(int a, int b)
{
    return std::min(a, b) + std::max(a, b) * (std::max(a,b) + 1) / 2;
}

bool is_pair_valid(const int pair, const std::vector<int> &sold_pairs)
{
    return std::find(sold_pairs.begin(), sold_pairs.end(), pair) == sold_pairs.end();
}

/*
    Losque le client sélectionne ses 5 chaussures, on retranscrit cela en un tableau "shoes" de 5 id
*/

std::vector<int> to_pairs(const std::vector<int> &shoes, std::vector<int> &sold_pairs)
{
    std::vector<int> pairs;
    for (auto &shoes1 : shoes)
    {
        for (auto &shoes2 : shoes)
        {
            if (shoes1 == shoes2)
                continue;

            int pair = encoding(shoes1, shoes2);
            if (is_pair_valid(pair, sold_pairs))
            {
                pairs.push_back(pair);
                sold_pairs.push_back(pair); //EN PRATIQUE : Ubdate the DB
            }
        }
    }

    return pairs;
}


int main()
{
    std::vector<int> shoes{14, 18, 68, 2, 5};
    std::vector<int> sold_pairs = {encoding(68, 2)};

    std::cout << "Sold pairs: " << encoding(68, 2) << '\n';
    auto pairs = to_pairs(shoes, sold_pairs);

    std::cout << "[ ";
    for (auto &pair : pairs)
        std::cout << pair << " ";

    std::cout << "]" << std::endl;
    return 1;
}