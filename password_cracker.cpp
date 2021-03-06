#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#define FILE_ERROR 5
using namespace std;

const int len_unique = 126-32+1+1;


struct Node {
    int num;
    char val;
    bool leaf;
    Node** children;
};


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

//prints the mapping
void printmap( map<char, map<char, int> > mapping) {
    for(map<char, map<char, int> >::iterator it = mapping.begin(); it != mapping.end(); it++) {
        char key = it->first;
        map<char, int> val = it->second;
        cout<<"key "<<key<<endl;
        for (map<char, int>::iterator it2 = val.begin(); it2 != val.end(); it2++) {
            char ikey = it2->first;
            int ival = it2->second;
            cout<<"\t"<<"value "<<ikey<< " " <<(int)(ikey)<< "\t"<< ival<<endl;
        }
    }
}

//void printarr(Type[]
int main () {
    //from space to tilde
    char uniques[len_unique];
    cout <<"len is "<<len_unique<<endl;


    ifstream myfile ("passwords.txt");
    map<char, map<char,int> > mapping;

    //I used to do this loop while appending elements to the mapping
    //this caused the array of unique elements to be uninitialized completely
    //while using said array to insert into the mapping
    //
    //goes through all ASCII characters 32-126, and then appends \n to the end 
    for(int x = 0; x < len_unique-1; x++) {
        uniques[x] = (char)(32+x);
    }
    uniques[len_unique-1] = '\n';


    //for each character in uniques other than \n, create a mapping to all 
    //characters in uniques including \n
    //this should create len_unique-1 keys, each with a map for a value
    //the internal map will have len_unique keys
    for(int x = 0; x < len_unique-1; x++) {
        char key = uniques[x];
        //cout <<key<<endl;
        map<char, int> val;
        for (int y = 0; y < len_unique; y++) {
            //cout<<"\t"<<uniques[y]<<endl;
            if( uniques[y] == '\0') { cout << "found a null val " << y << endl; }
            val.emplace(uniques[y], 1);
        }
        mapping.emplace(key, val);
    }
//NOTE: we don't need to have a mapping for \n to things because if we get \n, we should stop
    
/*
    //prints ASCII 32-126 and \n
    for(int x = 0; x < len_unique; x++) {
        cout <<uniques[x]<<endl;
    }
    */
    cout << "starting reading" << endl;
    string line;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            char current='\n';
            char last='\0';
            //iterate through all characters except starting one
            line.pop_back();
            for (int x = 1; x < (int)line.length(); x++) 
            {
                current = line[x];
                last = line[x-1];
                map<char, int> innermapping = mapping.find(last)->second;
                //bool cur = mapping.count(last);
                //bool las = innermapping.count(current);
                //cout<< cur <<'\t';
                //cout<< las <<endl;

                //find the previous element, find the current element, and increment count
                mapping.find(last)->second.find(current)->second++;
            }
            //if last != \0, we can assume that there was a length to the string
            //and that current should have a value that is equal to the end of the string
            //so we map it to \n to indicate the end of a word
            if (last != '\0')
            {
                //cout<< "current "<<(int)(current)<<endl;
                mapping.find(current)->second.find('\n')->second++;
            }
            //cout << line << '\n';
        }
    }
    else {
        cout << "Unable to open file"; 
        return FILE_ERROR;
    }

    cout << "done reading" << endl;
    printmap(mapping);

    int depth = 3;
    for( int x = 0; x < depth; x++) {
        cout<<x;
    }
    /*
    cout <<"enter pass: ";
    string linein;
    getline(cin, linein);
    */
    return 0;
}
