#ifndef MUSICLIBRARY_H
#define MUSICLIBRARY_H

#include <string>
#include "SongNode.h"

using namespace std;

class MusicLibrary
{
private:
	int numSongs;
	SongNode* rootNode;
    SongNode *addSong(SongNode *root, SongNode *song);
    void removeSong(SongNode *rs);
    SongNode *getSong(SongNode *gs, string, int);

public:
	MusicLibrary();
	~MusicLibrary();

	void printRepresentation();
	bool addSong(string title, string artist, string album, int year, int time);
    int getNumSongs() const;
    void readSongsFromFile(string filename);
    SongNode *getSong(int pt);
    void removeSong(int pt);
	void cleanupSongs(int playtime);
	static int getNumSongsInFile(string filename);
};

#endif // MUSICLIBRARY_H
