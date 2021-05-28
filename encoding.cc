#include <algorithm>
#include <iostream>

static int encoding(int a, int b)
{
    return std::min(a, b) + std::max(a, b)*(std::max(a,b) + 1)/2;
}

int main()
{
    for (int i = 0; i <= 20; i++)
    {
            for (int j = 0; j < i + 1; j++)
            {
                printf("f(%d,%d) = %d\n", i, j, encoding(i, j));

                if(i != j)
                    printf("f(%d,%d) = %d\n", j, i, encoding(j, i));
            }
    }

    std::cout << "f(1515646, 26489849) = " << encoding(1515646, 26489849) << std::endl;
    return 1;
}