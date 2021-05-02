#ifndef SONGNODE_H
#define SONGNODE_H

#include <string>
using namespace std;

class SongNode {
private:
    string Title;
    string Artist;
    string Album;
    int Year;
    int PlayTime;
    SongNode* LeftChild;
    SongNode* RightChild;

public:
    SongNode();
    SongNode(string title, string artist, string album, int year, int time);

    string getTitle() const;
    void setTitle(const string title);

    string getArtist() const;
    void setArtist(const string artist);

    string getAlbum() const;
    void setAlbum(const string album);

    int getYear() const;
    void setYear(const int year);

    int getPlayTime() const;
    void setPlayTime(const int time);

    int getKey();
    void setLeftChild(SongNode *lc);
    void setRightChild(SongNode *rc);
    SongNode* getLeftChild();
    SongNode* getRightChild();

    void printSong() const;
};
#endif // SONGNODE_H
