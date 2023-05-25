#!/bin/bash
s=261.6
e=277.2
d=293.7
r=311.1
f=329.6
g=349.2
y=370.0
h=392.0
u=415.3
j=440.0
i=466.2
k=493.9
l=523.2

while
read -s -n1 note
do
[ "${note}" = "q" ] && break;
[[ "sedrfgyhujikl" =~ ${note}{1} ]] && beep -f "${!note}"
done