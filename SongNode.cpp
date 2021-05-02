#include <iostream>
#include "SongNode.h"


SongNode::SongNode()
{
    Year = 0;
    PlayTime = 0;
    LeftChild = nullptr;
    RightChild = nullptr;
}

SongNode::SongNode(string title, string artist, string album, int year, int time) : Title(title), Artist(artist), Album(album), Year(year), PlayTime(time)
{}

string SongNode::getTitle() const
{
    return Title;
}
void SongNode::setTitle(const string title)
{
    Title = title;
}

string SongNode::getArtist() const
{
    return Artist;
}
void SongNode::setArtist(const string artist)
{
    Artist = artist;
}

string SongNode::getAlbum() const
{
    return Album;
}
void SongNode::setAlbum(const string album)
{
    Album = album;
}

int SongNode::getYear() const
{
    return Year;
}
void SongNode::setYear(const int year)
{
    Year = year;
}

int SongNode::getPlayTime() const
{
    return PlayTime;
}
void SongNode::setPlayTime(const int time)
{
    PlayTime = time;
}

int SongNode::getKey()
{
    return getPlayTime();
}

void SongNode::setLeftChild(SongNode *lc)
{
    LeftChild = lc;
}

void SongNode::setRightChild(SongNode* rc)
{
    RightChild = rc;
}

SongNode* SongNode::getLeftChild()
{
    return LeftChild;
}

SongNode* SongNode::getRightChild()
{
    return RightChild;
}

void SongNode::printSong() const
{
    cout << "Song: " << Title << ", " << Artist << ", " << Album << ", " << Year << ", " << PlayTime << endl;
}
