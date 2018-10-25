//
// Created by Sudeep Narala on 10/24/18.
//

#include "UtPod.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

UtPod::UtPod()
{
    this->memSize = MAX_MEMORY;
    this->taken = 0;
    songs=NULL;
}

UtPod::UtPod(int size)
{
    this->memSize = size;
    this->taken = 0;
    if((size<0) || (size > MAX_MEMORY))
    {
        this->memSize = MAX_MEMORY;
    }
    songs=NULL;
}

int UtPod::addSong(Song const &s)
{
    if((s.getSize() + taken) > MAX_MEMORY)
        return NO_MEMORY;
    SongNode* new_song = new SongNode;
    new_song->s = s;
    new_song->next = songs;
    songs = new_song;
    this->memSize -= s.getSize();
    return SUCCESS;
}

// PROBLEMS DELETING IF AT FRONT
int UtPod::removeSong(Song const &s)
{
    if(songs->s == s)
    {
        memSize += songs->s.getSize();
        songs = songs->next;
        return SUCCESS;
    }
    SongNode* head = songs;
    SongNode* tail = NULL;
    while(head!=NULL)
    {
        tail = head;
        head = head->next;
        if(head->s == s)
        {
            memSize += head->s.getSize();
            tail->next = head->next;
            return SUCCESS;
        }
    }
    return NOT_FOUND;
}
void UtPod::showSongList()
{
    SongNode* ptr = songs;
    while(ptr!=NULL)
    {
        Song ss = ptr->s;
        cout << ss.getArtist() << "   " << ss.getTitle() << "    " << ss.getSize() << "\n";
        ptr = ptr->next;
    }
}
int UtPod::getRemainingMemory()
{
    return memSize;
}

void UtPod::shuffle() {
    int length = 0;
    SongNode* ptr = songs;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    srand(time(NULL));

    for(int j=0; j<3*length; j++)
    {
        SongNode* curr = songs;
        SongNode* swapnode = songs;
        for(int i=0; i<j%length; i++)
        {
            curr = curr->next;
        }
        int toSwap = rand()%length;      // CHANGE SEED
        for(int k=0; k<toSwap; k++)
        {
            swapnode = swapnode->next;
        }
        Song ss = curr->s;
        curr->s = swapnode->s;
        swapnode->s = ss;
    }
}

void UtPod::sortSongList()
{
    int length = 0;
    SongNode* ptr = songs;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    for(int i=0; i<length; i++) {
        SongNode* curr = songs;
        for(int k=0; k<i; k++) {
            curr = curr->next;
        }
        SongNode* cmp = curr->next;
        for (int j = i + 1; j < length; j++) {
            if(curr->s>cmp->s)
            {
                Song temp = curr->s;
                curr->s = cmp->s;
                cmp->s = temp;
            }
            cmp = cmp->next;
        }
    }
}

