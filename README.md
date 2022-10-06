# filller

Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops.

Used a pretty simple method to check the board, and two while statement to loop through row and col.

In the case where no custom board is made, could consider remove memory allocation.
I decided to go for it as a way to practice, in my opinion program would be better without.

##HOW TO:
First make to create executable
```
make
```

To launch the game (against player hcao on map00)
```
./resources/filler_vm -p1 ./ccariou.filler -p2 ./resources/players/hcao.filler -v -f ./resources/maps/map00
```
![](./image1.png size=250x250) 
![](./image2.png size=250x250)

Script available to simulate multiple game (result in SCORE)
To play 5 games on all map against all opponents :
```
./game.sh all 5
```
