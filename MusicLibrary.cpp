#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <algorithm>
#include <cstdlib>
#include "MusicLibrary.h"

MusicLibrary::MusicLibrary()
{
    numSongs = 0;
    rootNode = nullptr;
}

MusicLibrary::~MusicLibrary()
{
    //destructor
}

int MusicLibrary::getNumSongs() const
{
    return numSongs;
}

//DO NOT MODIFY THIS FUNCTION
void printlr(SongNode *sn, string lrfull, string lr)
{
    if (nullptr != sn)
    {
        cout << "[" << lrfull << lr << "] ";
        sn->printSong();
        printlr(sn->getLeftChild(), lrfull + lr, "l");
        printlr(sn->getRightChild(), lrfull + lr, "r");
    }
}

//DO NOT MODIFY THIS FUNCTION
void MusicLibrary::printRepresentation()
{
    cout << endl;
    string rep = "x";
    printlr(rootNode, rep, "");
    cout << endl;
}

SongNode *MusicLibrary::getSong(int pt)
{
    std::string errorString = "Song with key pt not found.";
    return getSong(this->rootNode, errorString, pt);
}

SongNode *MusicLibrary::getSong(SongNode *gs, string str, int playTime)
{
    if (gs == nullptr)
    {
        std::cout << str << std::endl;
        return nullptr;
    }
    if (gs->getPlayTime() == playTime)
    {
        return gs;
    }
    if (gs->getPlayTime() > playTime)
    {
        return this->getSong(gs->getRightChild(), str, playTime);
    }
    else
    {
        return this->getSong(gs->getLeftChild(), str, playTime);
    }
}

void MusicLibrary::removeSong(int pt)
{
    //implement function
    /*
	IMPORTANT
	When removing node with two children, find replacement from the
	right subtree
	*/
}

void MusicLibrary::removeSong(SongNode *rs)
{
    removeSong(rs->getPlayTime());
}

bool MusicLibrary::addSong(string title, string artist, string album, int year, int time)
{
    SongNode *newSong = new SongNode(title, artist, album, year, time);

    this->rootNode = this->addSong(this->rootNode, newSong);

    return true;
}

SongNode *MusicLibrary::addSong(SongNode *root, SongNode *song)
{
    if (root == nullptr)
    {
        return song;
    }
    // if (song->getPlayTime() > root->getPlayTime())
    // {
    //     root->getRightChild() = this->addSong(root->getRightChild(), song);
    // }
    // else
    // {
    //     root->getLeftChild() = this->addSong(root->getLeftChild(), song);
    // }

    return root;
}

void MusicLibrary::readSongsFromFile(string filename)
{

    ifstream input;
    input.open(filename);

    if (input.is_open())
    {
        string line;
        while (getline(input, line))
        {
            string title, artist, album;
            string s_year, s_time;
            int year;
            int time;
            istringstream inSS(line);

            getline(inSS, title, ',');
            getline(inSS, artist, ',');
            getline(inSS, album, ',');
            getline(inSS, s_year, ',');
            getline(inSS, s_time);

            // Trim whitespaces
            artist.erase(artist.begin(), std::find_if(artist.begin(), artist.end(),
                                                      [](char ch) { return !isspace(ch); }));
            album.erase(album.begin(), std::find_if(album.begin(), album.end(),
                                                    [](char ch) { return !isspace(ch); }));

            year = stoi(s_year);
            time = stoi(s_time);
            addSong(title, artist, album, year, time);
        };
        input.close();
    }
    else
    {
        cout << "Could not open file " << filename << std::endl;
        exit(-1);
    }
}

int MusicLibrary::getNumSongsInFile(string filename)
{
    ifstream input;
    int lines;
    string line;

    input.open(filename);
    if (input.is_open())
    {
        for (lines = 0; getline(input, line); lines++)
            ;
        input.close();
    }
    else
    {
        cout << "Could not open file " << filename << std::endl;
        exit(-1);
    }
    input.close();

    return lines;
}

void MusicLibrary::cleanupSongs(int playtime)
{
    //implement function
    /*
	IMPORTANT
	Remove only nodes which have STRICTLY less than (<) playtime
	*/
}
