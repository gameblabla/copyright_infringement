==============================================
Copyright Infringement : The Regressive Right
==============================================

Bukake is challenging you to the greatest challenge
mankind has ever faced : Gay sex.

It's now your job to penetrate Siciel and win his heart
through repeated attempts at rape & penetration.

Will you be able to fool him ?
Or is he going to dump you and tell everyone about it ?

FIND OUT IN COPYRIGHT INFRINGEMENT : THE REGRESSIVE RIGHT !!!

*Don't look at the source code for spoiler or else you'll infringe on the license !!!
THANKS

=============
HOW TO BUILD
=============

Note that i develop and test the game on Linux.
The source code to makemegacart was also patched so it can be compiled on POSIX platforms.

This game is a MegaCART game and SDCC needs to be patched to work with makemegacart.
Thanks Tursi for the tool !

The patch is in megacart/sdcc_350_diffs and it still works with SDCC 3.6.0.
Move it to SDCC's source code root directory and apply it like so :
patch -p1 < sdcc_3.5.0_tursi.patch

Then you can compile SDCC the usual way.
./configure --prefix=/usr
make
sudo make install (or sudo checkinstall)

Once SDCC is patched, you also need to compile makemegacart.
This is quite simple, just run gcc makemegacart.cpp or use my makefile. (run "make")

After you have installed your patched SDCC and built makemegacart,
you can now build the game like so with a simple make.
