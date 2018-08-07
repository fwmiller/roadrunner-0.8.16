# The Roadrunner Operating System

This repository contains the source code for the Roadrunner Operating System.
I wrote this OS primarily as part of my Ph.D. dissertation which I completed
at the University of Maryland in 1998.  The development started while I was
at NASA/JSC in about 1989 and proceeded for about 14 years before I stopped
working on it.

The OS was originally written for the Intel i386 processor.  It uses a single
32-bit flat address space with paged memory protection but but does not use
virtual addresses, i.e. all addresses are physical.  I wrote a paper on the
memory protection that can still be found at:
https://www.usenix.org/conference/2002-usenix-annual-technical-conference/simple-memory-protection-embedded-operating

The last release number of 0.8.16, thus the repo title.  In the intervening
years since I worked on this system, everything has gone to 64-bits and some
of the tools needed to build the system have changed to the point where the
system will not boot anymore with a simple compile.

I have recently decided to resurrect the OS and bring it forward to the
x86_64 architecture, probably without the page level protections to begin
with.  Please see the project:  https://github.com/fwmiller/roadrunner for
the current project.
