#!/bin/bash

for letter in {a..z};
do
    convert $letter.xpm -scale 64x64 $letter.xpm
done