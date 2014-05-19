#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
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
    int len_unique = 126-32+1;
    char uniques[len_unique];
    cout <<"len is "<<len_unique<<endl;


    ifstream myfile ("passwords.txt");
    map<char, map<char,int> > mapping;


    for(int x = 0; x < len_unique; x++) {
        char key = uniques[x];
        map<char, int> val;
        for (int y = 0; y < len_unique; y++) {
            val.emplace(uniques[y], 1);
        }
        mapping.emplace(key, val);
    }

    return 0;
    string line;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            for (int x = 1; x < line.length(); x++) 
            {
                char c = line[x];
            }
            cout<<'\n';
            //cout << line << '\n';
        }
    }
    else {
        cout << "Unable to open file"; 
        return 1;
    }

    return 0;
}
