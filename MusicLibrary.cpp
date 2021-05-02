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
    return getSong(this->rootNode, pt);
}

SongNode *MusicLibrary::getSong(SongNode *gs, int playTime)
{
    if (gs == nullptr)
    {
        std::cout << "Song with key pt not found." << std::endl;
        return nullptr;
    }
    if (gs->getPlayTime() == playTime)
    {
        return gs;
    }
    if (gs->getPlayTime() > playTime)
    {
        return this->getSong(gs->getRightChild(), playTime);
    }
    else
    {
        return this->getSong(gs->getLeftChild(), playTime);
    }
}

void MusicLibrary::removeSong(int pt)
{
    // Get Song to delete
    this->rootNode = this->findSongToRemove(this->rootNode, pt);
}

SongNode* MusicLibrary::findSongToRemove(SongNode *root, int pt)
{
    if (root == nullptr)
    {
        std::cout << "Song with key pt not found for deletion." << std::endl;
        return nullptr;
    }
    else if (pt > root->getPlayTime())
    {
        root->setRightChild(this->findSongToRemove(root->getRightChild(), pt));
    }
    else if (pt < root->getPlayTime())
    {
        root->setLeftChild(this->findSongToRemove(root->getLeftChild(), pt));
    }
    else
    {
        this->numSongs--;
        if (root->getLeftChild() == nullptr and root->getRightChild() == nullptr)
        {
            free(root);
            return nullptr;
        }
        else if(root->getLeftChild() == nullptr and root->getRightChild() != nullptr)
        {
            SongNode* temp =  root->getRightChild();
            free(root);
            return temp;
        }
        else if (root->getRightChild() == nullptr and root->getLeftChild() != nullptr)
        {
            SongNode *temp = root->getLeftChild();
            free(root);
            return temp;
        }
        else
        {
            SongNode *temp = root->getRightChild();
            SongNode *prev = temp;

            while(prev->getLeftChild() != nullptr)
            {
                temp = prev;
                prev = prev->getLeftChild();
            }

            if (prev == temp)
            {
                free(temp);
                return root;
            }
            else
            {
                prev->setLeftChild(root->getRightChild());
                temp->setLeftChild(nullptr);
                root->setRightChild(prev);
            }
        }
        return root;
    }
}

bool MusicLibrary::addSong(string title, string artist, string album, int year, int time)
{
    SongNode *newSong = new SongNode(title, artist, album, year, time);

    this->numSongs++;
    this->rootNode = this->addSong(this->rootNode, newSong);

    return true;
}

SongNode *MusicLibrary::addSong(SongNode *root, SongNode *song)
{
    if (root == nullptr)
    {
        return song;
    }
    else if (song->getPlayTime() > root->getPlayTime())
    {
        root->setRightChild(this->addSong(root->getRightChild(), song));
    }
    else
    {
        root->setLeftChild(this->addSong(root->getLeftChild(), song));
    }

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

