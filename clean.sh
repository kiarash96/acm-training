#!/bin/bash

find . ! -name clean.sh -perm /111 -type f -exec rm "{}" \;
find . -name *.in -type f -exec rm "{}" \;
find . -name *.out -type f -exec rm "{}" \;

