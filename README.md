
Creating a Application that can find and download music from online and burn to a disk
===================================================

Background
----------
The main goal of this software to satisfy the client and their needs so in order to do this successfully I need explain the situation my client is in. My current client is a primary school teacher who would like to use certain music during performances by the students. An example of a song that would be needed by my client would a nursery rhyme like "if your happy and you know in clap your hands". The current system in place in virtually non existent by getting a couple of songs from online and CD. It should be noted that the current method of playing this music is through a CD player and the program needs to be adapted to this.

The problem
-----------
Given this information the problem that I need to solve with this application is to be able to get music from online and burn it to a disk for my client to use. With this I can start to outline some objectives I want this program to achieve. 

 + To be able to download music and store it
 + Create playlists of these songs that my client can burn onto different disks
 + Being able to burn these disks within the application
 + Must be able to work on various computer without requisites installed

For the first item on the list I need to consider where I get the music from and whether it has copy right protection on it. My original thought on this was to use YouTube as this by far has the most variety of music on it and it would be familiar to people who use my application. The big problem with this was copyright but after a little research I managed to find that by editing the URL of the search you can search only for copyright free videos which makes YouTube my preferred choice.

Next on the list I need to think how I would store this download music into playlists. The most simple solution to this would be to use folders where the folder name would be the name of the playlist and all of the contents the song within the playlist. The problem with this is that it would end up being slow and could take up considerable space as one song could be in multiple playlists meaning that it would have to be copied or use symlinks. Considering these factors it would be much more efficient to use a database where all of the songs would be in a single download folder where the database could organise them into different playlists. This also means memory consumption would be at a minimum as I could use ids to reference items in other table so there is little repeated data.

Following the previous item we have to make sure that this application will work on computers without being dependent on other programs. This is critical for my client. The reasoning behind this is that this application may be run upon a work computer where installing additional programs is not feasible. Furthermore being able to transfer this program using a USB and have it work on other computers is a desirable feature.

Finally for the last item on the list I need to consider what libraries would be need to perform the action and how they would work on different platforms which leads nicely onto the next topic.

What language and APIs will I be using?
---------------------------------------
For the application to be able to run across multiple platforms I decided to use an language that would be able to compile. This meant instead of choosing a language like python which is interpreter and needs python pre-installed; instead I have decided to use C++ as a language. This would allow me to create executable easily which would be easier to  port to other systems helping achieve one of the original objectives. The next thing that I should consider is what libraries or APIs I will be using and the conclusion that I arrived at was Qt. The reasoning behind this is that Qt is an expansive library that contains many of the elements that I need to make this project work such as network and database capabilities and I have had past experience with the library making me more familiar with the class that I could make use of.

> Written with [StackEdit](https://stackedit.io/).
