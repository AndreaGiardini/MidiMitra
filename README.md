MidiMitra
=========

This projects aims to create a MIDI-Shotgun (Mitra, in italian).
When the button is pressed Arduino sends MIDI (http://en.wikipedia.org/wiki/MIDI) notes to the soundcard/syth/whatever-you-connect:
if the distance from the ultrasonic sensor changes also the note changes, with the potentiometer you can alter the output frequency.

There is also a led... but just for fun :)

You should build your own serial-to-midi adapter in this way:

<img src="http://arduino.cc/en/uploads/Tutorial/MIDI_bb.png">

The result is something really really insane, noisy, funny and disturbing

Photo (yes, i need to do a Fritzing schema):

<img src="./Files/Photo.jpg">

Demo:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=W0uRJnQ7T_U
" target="_blank"><img src="http://img.youtube.com/vi/W0uRJnQ7T_U/0.jpg" 
alt="Youtube video" width="240" height="180" border="10" /></a>

TODO:
[ ] - Add Fritzing schema

Based on:
http://minucci.net/blog/653
