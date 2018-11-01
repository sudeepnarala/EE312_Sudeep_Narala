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
    songs=NULL;
}

UtPod::UtPod(int size)
{
    this->memSize = size;
    if((size<0) || (size > MAX_MEMORY))
    {
        this->memSize = MAX_MEMORY;
    }
    songs=NULL;
}

int UtPod::addSong(Song const &s)
{
    if(this->getRemainingMemory() < s.getSize())
        return NO_MEMORY;
    SongNode* new_song = new SongNode;
    new_song->s = s;
    new_song->next = songs;
    songs = new_song;
    return SUCCESS;
}

int UtPod::removeSong(Song const &s)
{
    if(songs->s == s)
    {
        SongNode* tempptr = songs;
        songs = songs->next;
        delete tempptr;
        return SUCCESS;
    }
    SongNode* head = songs;
    SongNode* tail = NULL;
    while(head!=NULL)
    {
        tail = head;
        head = head->next;
        if(head!=NULL)
        {
            if(head->s == s)
            {
                tail->next = head->next;
                delete head;
                return SUCCESS;
            }
        }
    }
    return NOT_FOUND;
}
void UtPod::showSongList()
{

    SongNode* ptr = songs;
    int num1 = 0;   // Used to get a better print
    int num2 = 0;
    while(ptr!=NULL)
    {
        Song ss = ptr->s;
        if(ss.getArtist().length()>num1)
        {
            num1 = ss.getArtist().length();
        }
        if(ss.getTitle().length()>num2)
        {
            num2 = ss.getTitle().length();
        }
        ptr = ptr->next;
    }

    ptr = songs;
    num1 += 5;
    num2 += 5;
    while(ptr!=NULL)
    {
        Song ss = ptr->s;
        string spaces="";
        string spaces2 = "";
        for(int i=0; i<num1-ss.getArtist().length(); i++)
            spaces += " ";

        for(int i=0; i<num2-ss.getTitle().length(); i++)
            spaces2 += " ";

        cout << ss.getArtist() << spaces << ss.getTitle() << spaces2 << ss.getSize() << " MB"<< "\n";
        ptr = ptr->next;
    }
}
int UtPod::getRemainingMemory()
{
    int left = memSize;
    SongNode* ptr = songs;
    while(ptr!=NULL)
    {
        Song ss = ptr->s;
        left -= ss.getSize();
        ptr = ptr->next;
    }
    return left;
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

void UtPod::clearMemory()
{
    SongNode* curr=songs;
    while(curr!=NULL)
    {
        SongNode* temp = curr->next;
        delete curr;
        curr=temp;
    }
    songs=NULL;
    return;
}

UtPod::~UtPod()
{
    clearMemory();
}
