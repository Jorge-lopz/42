#!/bin/bash

# Use the patch command to apply the changes on the diff file to 'a'  and save them on 'b'
patch a sw.diff -o b

# Extra, show the contents of the newly created 'b' file
cat b
