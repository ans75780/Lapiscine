cat /etc/passwd | sed '/^#/d' | sed 's/:.*$//'  | awk 'NR % 2 == 0' | rev | sort -r | awk "NR>=$FT_LINE1&&NR<=$FT_LINE2" | tr '\n' ',' | sed 's/,$/./' | sed 's/,/, /g' | tr -d '\n'
