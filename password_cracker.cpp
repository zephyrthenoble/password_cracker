#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool contains(vector<char>& vec, char& c) {
    for(int x = 0; x < vec.size(); x++)
    {
        if (c == vec[x])
        {
            return true;
        }
    }
    return false;
}

int main () {
    string line;
    ifstream myfile ("passwords.txt");
    vector<char> uniques;
    map<char, map<char,int>> mapping;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            for (int x = 0; x < line.length(); x++) 
            {
                char c = line[x];
                if (contains(uniques, c))
                {
                    ;
                }
                else
                {
                    cout<<"not in "<<c<<'\n';
                    uniques.push_back(c);
                }
            }
            cout<<'\n';
            //cout << line << '\n';
        }
        myfile.close();
    }

    map<char,int> refmap;
    for(int x = 0; x < uniques.size(); x++)
    {

        refmap.insert(pair(uniques[x], 0))
    }


    else {
        cout << "Unable to open file"; 
        return 1;
    }

    return 0;
}
