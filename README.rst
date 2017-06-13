bitmaskqt5
==========

Experiments on a c++ browser for Bitmask UI.

Dependencies
------------
Needs qt5 already installed in the system::

  apt install qt5-qmake qt5-default libqt5webkit5-dev

``bitmaskd`` is also assumed to be running.

Build
-----
Build the browser::

  qmake
  make

To-Do
--------------
* [ ] trim size: unlink not-needed libraries.
* [ ] automate dependency gathering.
* [ ] expose bridges to JS to open link, shudown app.
* [ ] allow to open new browser window to open Pixelated.

Open Questions
--------------
* Can we get this in a smaller size?
* Is it really possible to compile statically against webkit?
https://stackoverflow.com/questions/4330980/is-that-possible-to-build-static-qt-library-with-webkit-enabled-and-how
