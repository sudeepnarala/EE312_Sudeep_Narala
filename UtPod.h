//
// Created by Sudeep Narala on 10/24/18.
//

#ifndef LAB5_UTPOD_H
#define LAB5_UTPOD_H

#include "song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;
    int taken;

public:
    UtPod();
    UtPod(int size);

    int addSong(Song const &s);
    int removeSong(Song const &s);
    void shuffle();
    void showSongList();
    void sortSongList();

    int getTotalMemory() {
        return memSize;
    }

    int getRemainingMemory();

//    ~UtPod();     //Why had to delete?

};



#endif