#include <iostream>
#include <string>
#include <cstdlib>

#include "SongNode.h"
#include "MusicLibrary.h"

using namespace std;

int main(int argc, char** argv)
{
    string filename;
    cout << "Enter filename with list of Songs :" << endl;
    cin >> filename;

    MusicLibrary *mylibrary = new MusicLibrary();
    mylibrary->readSongsFromFile(filename);
    mylibrary->printRepresentation();
    delete mylibrary;

    return 0;
}