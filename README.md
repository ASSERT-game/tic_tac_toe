# tic_tac_toe

Game of Tic Tac Toe, implemented in C with the help of SDL graphics library. Project was used to get an
understanding of the [min-maxing algorithm](https://en.wikipedia.org/wiki/Minimax). After running ```make```
you can run the executable ```tic_tac_toe``` to play with someone else, or ```tic_tac_toe AI``` to play against the AI, you can also just do ```make vs_ai```.

<br>
<img align="top" height="250" src="https://github.com/ASSERT-game/tic_tac_toe/tree/master/resources/gameplay.gif" />
<br>

Was going to port the algorithm to Chess but due to large search place of Chess, the min-max algorithm would need serious modifications. The current version could be ported to chess but would result in either slow AI responses or a very shallow move depth.
