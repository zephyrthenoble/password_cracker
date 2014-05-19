#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool contains(vector<char>& vec, char& c) {
    for(uint x = 0; x < vec.size(); x++)
    {
        if (c == vec[x])
        {
            return true;
        }
    }
    return false;
}

int main () {
    //from space to tilde
    int len_unique = 126-32+1;
    char uniques[len_unique+1];
    cout <<"len is "<<len_unique<<endl;


    ifstream myfile ("passwords.txt");
    map<char, map<char,int> > mapping;


    for(int x = 0; x < len_unique; x++) {
        char key = (char)(32+x);
        uniques[x] = key;
        cout <<key<<endl;
        map<char, int> val;
        for (int y = 0; y < len_unique; y++) {
            cout<<"\t"<<uniques[y]<<endl;
            val.emplace(uniques[y], 1);
        }
        val.emplace('\n', 1);
        mapping.emplace(key, val);
    }
    uniques[len_unique] = '\n';
    len_unique++;

    //prints ASCII 32-126 and \n
    for(int x = 0; x < len_unique; x++) {
        cout <<uniques[x]<<endl;
    }
/*
    string line;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            char current='\n';
            char last='\0';
            //iterate through all characters except starting one
            for (int x = 1; x < (int)line.length(); x++) 
            {
                current = line[x];
                last = line[x-1];

                //find the previous element, find the current element, and increment count
                mapping.find(last)->second.find(current)->second++;
            }
            //if last != \0, we can assume that there was a length to the string
            //and that current should have a value that is equal to the end of the string
            //so we map it to \n to indicate the end of a word
            if (last != '\0')
            {
                cout<< "current "<<(int)(current)<<endl;
                mapping.find(current)->second.find('\n')->second++;
            }
            //cout << line << '\n';
        }
    }
    else {
        cout << "Unable to open file"; 
        return 1;
    }
    for(int x = 0; x < len_unique; x++) {
        char key = uniques[x];
        cout<<key<<endl;
        for (int y = 0; y < len_unique; y++) {
            char val = uniques[y];
            int num = mapping[key][val];
            cout<<'\t'<<val<<'\t'<<num<<endl;
        }     
    } 
    */
    return 0;
}
