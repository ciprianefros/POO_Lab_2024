#include "pch.h"

using namespace std;

TEST(TestSortare, TestSortareCrescatoare) // verifica daca sortarea este facuta crescator
{
    int v[5] = { 1, 3, 7, 1, 9 };
    unsigned int nrElem = 5;
    sortElemente<int>(v, nrElem);

    for (int i = 0; i < nrElem; i++)
        cout << v[i] << " ";
    cout << endl;

    for (unsigned int i = 0; i < nrElem - 1; i++)
    {
        ASSERT_GE(v[i], v[i + 1]);
    }
}

TEST(TestSortare, TestSortareDescrescatoare) // verifica daca sortarea este facuta descrescator
{
    int v[5] = { 1, 3, 7, 1, 9 };
    unsigned int nrElem = 5;
    sortElemente<int>(v, nrElem);

    for (int i = 0; i < nrElem; i++)
        cout << v[i] << " ";
    cout << endl;

    for (unsigned int i = 0; i < nrElem - 1; i++)
    {
        ASSERT_LE(v[i], v[i + 1]);
    }
}

TEST(TestSortare, TestPrimulElementeste9) //Verifica vreo conditie speciala daca primul element este 9
{
    int v[5] = { 1, 3, 7, 1, 9 };
    unsigned int nrElem = 5;
    sortElemente<int>(v, nrElem);

    for (int i = 0; i < nrElem; i++)
        cout << v[i] << " ";
    cout << endl;

    if (v[0] == 9)
    {
        ASSERT_EQ(v[1], 1);  
        ASSERT_EQ(v[nrElem - 1], 7);  
    }
    else
    {
        for (unsigned int i = 0; i < nrElem - 1; i++)
        {
            ASSERT_GE(v[i], v[i + 1]);
        }
    }
}
TEST(TestSortare, TestSortareChar) //Verifica daca se sorteaza corect array-urile de char
{
    char v[5] = { 'a', 'x', 'b', 'y', '2'};
    char expected[5] = { '2', 'a', 'b', 'x', 'y' };
    unsigned int nrElem = 5;
    sortElemente<char>(v, nrElem);

    for (int i = 0; i < nrElem; i++)
        cout << v[i] << " ";
    cout << endl;

    
    for (unsigned int i = 0; i < nrElem - 1; i++)
    {
        ASSERT_EQ(v[i], expected[i]);
    }
    
}

TEST(TestSortare, TestPrimulElementeste10) //Verifica vreo conditie speciala daca primul element este 10
{
    int v[5] = { 1, 3, 7, 1, 10 };
    unsigned int nrElem = 5;
    sortElemente<int>(v, nrElem);

    for (int i = 0; i < nrElem; i++)
        cout << v[i] << " ";
    cout << endl;

    if (v[0] == 10)
    {
        for (unsigned int i = 0; i < nrElem - 1; i++)
        {
            ASSERT_LE(v[i], v[i + 1]);
        }
    }
}