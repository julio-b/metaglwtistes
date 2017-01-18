#compile
## flex -o Met5_i.yy.c  Metaglwtistes5\(FLEX\).l && gcc -o met5_i -lfl Met5_i.yy.c
## flex -o Met5_ii.yy.c  Metaglwtistes5_2\(FLEX\).l && gcc -o met5_ii -lfl Met5_ii.yy.c
#run
## ./met5_i
## ./met5_ii
#test
1. echo "Δίνεται τετράγωνο ΒΕΔΑ Δίνεται τετράγωνο ΒΒΕΔΔΔΑ Δίνεται τρίγωνο ΕΓΑ " | ./met5_i
2. echo "Δίνεται τετράγωνο ΒΕΔΑ Δίνεται τετράγωνο ΒΒΕΔΔΔΑ Δίνεται τετράγωνο ΒΒΕΕΓΕΔΑ " | ./met5_ii
