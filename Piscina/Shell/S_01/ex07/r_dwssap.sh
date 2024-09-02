#!/bin/bash
cat /etc/passwd | grep -v "#" | sed -n "${FT_LINE1},${FT_LINE2}p" | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./'
