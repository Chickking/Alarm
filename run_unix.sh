#!/bin/sh
cd "$(dirname "$0")"
file="./alarm"
if [[ ! -x "$file" ]]; then
	g++ -o alarm alarm.cpp;
	chmod a+x ./alarm;
fi
./alarm