//
// Created by Sudeep Narala on 10/24/18.
//

#include "song.h"

using namespace std;

Song::Song()
{
    this->title = "";
    this->artist = "";
    this->size = 0;
}

Song::Song(string title, string artist, int size)
{
    this->title =title;
    this->artist = artist;
    this->size = size;
}

bool Song::operator >(Song const &rhs)
{
    if(artist > rhs.artist) // Can do this with strings?
    {
        return true;
    }
    else if (artist==rhs.artist)
    {
        if(title > rhs.title)
        {
            return true;
        }
        else if(title==rhs.title)
        {
            if(size > rhs.size)
            {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator <(Song const &rhs)
{
    if(artist < rhs.artist) // Can do this with strings?
    {
        return true;
    }
    else if (artist==rhs.artist)
    {
        if(title < rhs.title)
        {
            return true;
        }
        else if(title==rhs.title)
        {
            if(size < rhs.size)
            {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator ==(Song const &rhs)
{
    return ( (artist==rhs.artist) && (title==rhs.title) && (size==rhs.size));
}