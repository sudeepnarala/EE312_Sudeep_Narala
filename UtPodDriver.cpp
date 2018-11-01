/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"
#include "song.cpp"
#include "UtPod.cpp"
#include <stdio.h>


using namespace std;

int main(int argc, char *argv[])
{
    Song s1("Song 1", "Beatles", 40);
    Song s2("Song 2", "Panic! At the Disco", 15);
    Song s3("Song 3", "Led Zeppelin",  42);
    Song s4("Song 4", "Radiohead",  4);
    Song s5("Song 5", "Pear Jam", 32);
    Song s6("Song 6", "Metallica", 54);
    Song s7("Song 7", "Fall Out Boy", 21);
    Song s8("Song 8", "Fall Out Boy", 21);
    Song s9("Song 8", "Fall Out Boy", 42);
    cout << "Creating a UtPod with maximum memory size (512).\n";
    UtPod t;

    cout << "Adding one song to the UtPod:\n";
    int result = t.addSong(s1);
    cout << "Result of add should be: " << 0 << ", and it is: " << result << "\n";
    cout << "Here is the song list:\n";
    t.showSongList();
    cout << "Now adding a bunch of songs to the UtPod in an arbitrary order, all adds should be successful and there "
            "should be 9 total songs.\n";
    t.addSong(s4);
    t.addSong(s3);
    t.addSong(s8);
    t.addSong(s7);
    t.addSong(s5);
    t.addSong(s9);
    t.addSong(s6);
    t.addSong(s2);
    cout << "Here is how the song list looks:\n";
    t.showSongList();
    cout << "Let's sort the songs.\n";
    t.sortSongList();
    cout << "And here is the list after the sort:\n\n";
    t.showSongList();
    cout << "\n";
    cout << "Now, let's try shuffling the songs around.\n";
    t.shuffle();
    cout << "The shuffle yields the following result:\n\n";
    t.showSongList();
    cout << "\n";
    cout << "Let's try shuffling another time. This is how it looks:\n\n";
    t.shuffle();
    t.showSongList();
    cout << "\n";
    cout << "Deleting UtPod.\n";
    t.~UtPod();

    int new_size = 128;
    cout << "Creating a new UtPod with a size of " << new_size <<".\n";
    UtPod t2(new_size);
    cout << "Adding 4 songs, all adds should be successful. The song list looks like:\n\n";
    t2.addSong(s5);
    t2.addSong(s4);
    t2.addSong(s6);
    t2.addSong(s7);
    t2.showSongList();
    cout << "\n";
    char temp[100];
    sprintf(temp, "%d-%d-%d-%d-%d = %d", t2.getTotalMemory(), s5.getSize(), s4.getSize(), s6.getSize(), s7.getSize(), t2.getTotalMemory()-s5.getSize()-s4.getSize()-s6.getSize()-s7.getSize());
    cout << "Memory left = total memory - memory used = " <<temp<<"\n";
    cout << "Asking UtPod how much memory it has left: " << t2.getRemainingMemory() << "\n";
    cout << "New song we are trying to add, " << s3.getTitle() << ", has memory of " << s3.getSize() << " so the UtPod should reject it.\n";
    result = t2.addSong(s3);
    cout << "Result of add should be " << -1 << ", and it is: " << result << "\n";
    cout << "If add was done correctly, song list should not have changed from last time. Here it is:\n\n";
    t2.showSongList();
    cout << "\n";
    cout << "Now, let's try removing a song. Removing the Fall Out Boy song (1st one).\n";
    result = t2.removeSong(s7);
    cout << "Since the song we are removing exists in our UtPod, the removal request should be: "
    << 0 << ", and our UtPod returns a result of: " << result << "\n";
    cout << "Here is what the song list looks like now:\n\n";
    t2.showSongList();
    cout << "\n";
    cout << "Let's also try removing a song from the middle of the song list. Let's remove the Radiohead song. "
            "The song list now looks like:\n\n";
    t2.removeSong(s4);
    t2.showSongList();
    cout << "\n";
    cout << "Now, we are going to try to remove a song which is not in this UtPod as of right now "
            "(Song 1 by the Beatles).\n";
    result = t2.removeSong(s1);
    cout << "The result of the removal attempt should be: " << -2 << ", and we get: " << result << "\n";
    cout << "The UtPod should not have changed. Here it is:\n\n";
    t2.showSongList();
    cout << "\n";
    cout << "Let's erase the memory of the UtPod.\n";
    t2.clearMemory();
    cout << "Now the song list looks like (should be empty):\n\n";
    t2.showSongList();
    cout << "\n";
    cout << "Deleting UtPod.\n";
    t2.~UtPod();

    // Checked for memory leaks using valgrind and saw that I freed all of the allocated memory



}

