#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    unordered_map<int, char> umap;
    umap[1] = 'a';
    umap[2] = 'b';
    umap[3] = 'c';
    umap[4] = 'd';
    // Access
    cout << umap[1] << '\n';
    cout << umap[2] << '\n';

    // auto result = umap.find(2);
    // cout << result;

    cout << "At function: " << umap.at(1) << '\n';
    cout << "Bucket :" << umap.bucket(2) << '\n';
    cout << "Bucket Size :" << umap.bucket_size(1) << '\n';

    unordered_map<int, char>::iterator it;

    for (it = umap.begin(); it != umap.end(); it++)
    {
        cout << "(" << it->first << ", " << it->second << ")";
        cout << endl;
    }

    if (umap.find(4) == umap.begin())
        cout << "Found" << endl;

    cout << "Counts :" << umap.count(1) << '\n';

    string s = "I love you , you love me , we love anime";
    stringstream ss(s);
    // ss >> s;
    unordered_map<string, int> wordFreq;
    string word;
    while (ss >> word)
    {
        wordFreq[word]++;
    }
    unordered_map<string, int>::iterator p;

    for (p = wordFreq.begin(); p != wordFreq.end(); p++)
    {
        cout << "(" << p->first << ", " << p->second << ")";
        cout << endl;
    }

    return 0;
}